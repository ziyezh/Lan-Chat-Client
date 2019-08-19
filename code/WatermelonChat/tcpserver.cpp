#include "tcpserver.h"
#include "ui_tcpserver.h"
#include <QMessageBox>
#include <QTcpServer>
#include <QFileDialog>
#include<QApplication>
#include <QMouseEvent>
TcpServer::TcpServer(QWidget *parent) :
    QWidget(parent),
    ui(new Ui::TcpServer)
{
    ui->setupUi(this);
    this->setWindowFlags(Qt::FramelessWindowHint | Qt::WindowSystemMenuHint | Qt::WindowMinimizeButtonHint);
    this->setFixedSize(550,300);//设置窗口大小
    ui->progressBar->setVisible(false);
    ui->serverStatusLabel->setAlignment(Qt::AlignCenter);
    tcpPort = 19999;//端口
    tcpServer = new QTcpServer(this);//为指针分配空间，指定父对象
    connect(tcpServer,&QTcpServer::newConnection,this,&TcpServer::sendMessage);

    initServer();//用来初始化上传
}

TcpServer::~TcpServer()
{
    delete ui;
    delete clientConnection;
}

void TcpServer::on_serverOpenBtn_clicked()
{
    fileName = QFileDialog::getOpenFileName(this);//打开文件窗口
    if(!fileName.isEmpty())//文件名不空
    {
        theFileName = fileName.right(fileName.size() - fileName.lastIndexOf('/')-1);
        ui->serverStatusLabel->setText(tr("要传送的文件为：%1 ").arg(theFileName));
        ui->serverSendBtn->setEnabled(true);
    }
}

void TcpServer::on_serverSendBtn_clicked()
{
    ui->progressBar->setVisible(true);
    if(!tcpServer->listen(QHostAddress::Any,tcpPort))//开始监听
    {
        qDebug() << tcpServer->errorString();//错误报告
        close();
        return;
    }

    ui->serverStatusLabel->setText(tr("等待对方接收... ..."));
    emit sendFileName(theFileName);//触发信号
}

//这个函数的意思就是如果发生了语言变化，就重新翻译这个Ui
//void TcpServer::changeEvent(QEvent *e)
//{
//    QDialog::changeEvent(e);
//    switch (e->type()) {
//    case QEvent::LanguageChange:
//        ui->retranslateUi(this);
//        break;
//    default:
//        break;
//    }
//}

void TcpServer::sendMessage()  //开始发送数据
{
    ui->serverSendBtn->setEnabled(false);//设置该按钮为不可点击
    clientConnection = tcpServer->nextPendingConnection();//获取已经建立的连接的子套接字
    connect(clientConnection,SIGNAL(bytesWritten(qint64)),SLOT(updateClientProgress(qint64)));

    ui->serverStatusLabel->setText(tr("开始传送文件 %1 ！").arg(theFileName));//设置进度条上方label的文字 thefilename在槽函数也定义了

    localFile = new QFile(fileName);// filename是头文件定义的一个Qstring类对象 在槽函数定义了 localfile表示文件内容本身

    //没打开的话就报错
    if(!localFile->open((QFile::ReadOnly))){//以只读方式打开
        QMessageBox::warning(this,tr("应用程序"),tr("无法读取文件 %1:\n%2").arg(fileName).arg(localFile->errorString()));
        return;
    }

    TotalBytes = localFile->size();

    //第一个参数是缓存一次发送的数据 第二个参数：文件打开方式：只写模式，设置输出流属性
    QDataStream sendOut(&outBlock,QIODevice::WriteOnly);
    sendOut.setVersion(QDataStream::Qt_5_5);
    time.start();  //开始计时
    //最短的文件名，比如是a.txt，把路径删掉
    QString currentFile = fileName.right(fileName.size() - fileName.lastIndexOf('/')-1);

    //qint64(0)表示将0转换成qint64类型,与(qint64)0等价
    //网上解释：如果是，则此处为依次写入总大小信息空间，文件名大小信息空间，文件名
    //首部 = 总大小 + 文件名长度 + 文件名
    sendOut<<qint64(0)<<qint64(0)<<currentFile;
    //总大小加上首部的大小
    TotalBytes += outBlock.size();

    //防止TCP黏包
    //需要通过定时器延时 20 ms
    timer.start(20);

    //sendOut.device()为返回io设备的当前设置，seek(0)表示设置当前pos为0
    //返回到outBlock的开始，执行覆盖操作
    sendOut.device()->seek(0);

    //发送总大小空间和文件名大小空间   这里乘以2什么意思？
    sendOut<<TotalBytes<<qint64((outBlock.size()-sizeof(qint64)*2));

    //还需要传输的数据量
    bytesToWrite = TotalBytes - clientConnection->write(outBlock);
    qDebug()<<currentFile<<TotalBytes;

    //将outblock变为0 清空发送缓冲区
    outBlock.resize(0);

}

void TcpServer::updateClientProgress(qint64 numBytes)//更新进度条
{
    bytesWritten += (int)numBytes;
    if(bytesToWrite > 0)
    {//没发送完的时候

        //初始化loadsize为64kb，即每次最多发送64kb
        outBlock = localFile->read(qMin(bytesToWrite,loadSize));
        bytesToWrite -= (int)clientConnection->write(outBlock);
        outBlock.resize(0);//清空发送缓冲区
    }
    else
    {
        localFile->close();
    }
    ui->progressBar->setMaximum(TotalBytes);
    ui->progressBar->setValue(bytesWritten);

   float useTime = time.elapsed();//从time.start开始到当前所用的时间记录在useTime中
   double speed = (bytesWritten / useTime);
   ui->serverStatusLabel->setText(tr("已发送 %1MB (%2MB/s) \n共%3MB 已用时:%4秒\n估计剩余时间：%5秒")
                                  .arg(bytesWritten / (1024*1024))//已发送
                                  .arg(speed*1000/(1024*1024),0,'f',2)//速度
                                  .arg(TotalBytes / (1024 * 1024))//总大小
                                  .arg(useTime/1000,0,'f',0)//用时
                                  .arg(TotalBytes/speed/1000 - useTime/1000,0,'f',0));//剩余时间

   //num.sprintf("%.1f KB/s", (bytesWritten*1000) / (1024.0*time.elapsed()));
    if(bytesWritten == TotalBytes)//发送成功
        ui->serverStatusLabel->setText(tr("传送文件 %1 成功").arg(theFileName));


}

void TcpServer::refused()//被对方拒绝
{
    tcpServer->close();
    ui->serverStatusLabel->setText(tr("对方拒收文件"));
    ui->serverSendBtn->setEnabled(false);
    ui->serverOpenBtn->setEnabled(false);

}

void TcpServer::initServer()//初始化
{
    loadSize = 4*1024;
    TotalBytes = 0;
    bytesWritten = 0;
    bytesToWrite = 0;
    clientConnection = new QTcpSocket(this);
    ui->serverStatusLabel->setText(tr("请选择要传送的文件"));
    ui->progressBar->setValue(0);
    ui->serverOpenBtn->setEnabled(true);//可以点
    ui->serverSendBtn->setEnabled(false);//不可以点

}


void TcpServer::on_serverCloseBtn_clicked()
{
    if(tcpServer->isListening())
    {
        tcpServer->close();
        clientConnection->abort();//退出
    }
    this->close();
}

void TcpServer::mousePressEvent(QMouseEvent *e)
{
    last = e->globalPos();
}
void TcpServer::mouseMoveEvent(QMouseEvent *e)
{
    int dx = e->globalX() - last.x();
    int dy = e->globalY() - last.y();
    last = e->globalPos();
    move(x()+dx, y()+dy);
}
void TcpServer::mouseReleaseEvent(QMouseEvent *e)
{
    int dx = e->globalX() - last.x();
    int dy = e->globalY() - last.y();
    move(x()+dx, y()+dy);
}
