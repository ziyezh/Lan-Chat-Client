#include "tcpclient.h"
#include "ui_tcpclient.h"
#include <QDialog>
#include <QMessageBox>
#include <QEvent>
#include <QMouseEvent>
TcpClient::TcpClient(QWidget *parent) :
    QWidget(parent),
    ui(new Ui::TcpClient)
{
    ui->setupUi(this);

    //设置窗口大小为350*200
    this->setFixedSize(550,300);

    //初始化变量的值
    totalBytes = 0;
    bytesReceived = 0;
    bytesToReceive = 0;
    fileNameSize = 0;

    //为tcpClient分配空间，指定父对象
    tcpClient = new QTcpSocket(this);
    //设定端口号为19999
    tcpPort = 19999;
    //关联数据信号
    connect(tcpClient, &QTcpSocket::readyRead,this,&TcpClient::readMessage);
    //如果传输发生错误,提示错误信息，使用lambda表达式
    connect(tcpClient, static_cast<void(QAbstractSocket::*)(QAbstractSocket::SocketError)>
            (&QAbstractSocket::error),
          [=](QAbstractSocket::SocketError socketError)
        { switch(socketError)
            {
                case QAbstractSocket::RemoteHostClosedError : break;
                default : qDebug() << tcpClient->errorString();
            }
        });

}

TcpClient::~TcpClient()
{
    delete ui;
}

void TcpClient::readMessage()
{
    QDataStream in(tcpClient);
    //设置版本号
    in.setVersion(QDataStream::Qt_5_5);

    //自上次调用start（）或restart（）以来所经过的毫秒数
    float useTime = time.elapsed();


    //如果传入的字节小于sizeof(qint64)*2
    if(bytesReceived <= sizeof(qint64)*2)
    {
        //如果等待读取的传入字节数大于sizeof(qint64)*2并且文件名大小为0
        if((tcpClient->bytesAvailable() >= sizeof(qint64)*2) && (fileNameSize == 0))
        {
            //将所有字节传入数据流
            in>>totalBytes>>fileNameSize;
            //已接受的字节加sizeof(qint64)*2长度
            bytesReceived += sizeof(qint64)*2;
        }
        //如果等待读取的传入字节数大于文件名大小，且文件名大小不为0
        if((tcpClient->bytesAvailable() >= fileNameSize) && (fileNameSize != 0))
        {
            //将文件名传入数据流
            in>>fileName;
             //已接受的字节加上文件名长度
            bytesReceived +=fileNameSize;

            //如果没有打开文件，弹出提示消息
            if(!localFile->open(QFile::WriteOnly))
            {
                QMessageBox::warning(this,tr("应用程序"),tr("无法读取文件 %1:\n%2.").arg(fileName).arg(localFile->errorString()));
                return;
            }
        }

        else
        {
            return;
        }
    }

    //如果传入的字节小于总字节数，即未传输完
    if(bytesReceived < totalBytes)
    {
        //将等待传输的字节加入已接受的字节中
        bytesReceived += tcpClient->bytesAvailable();
        //将套接字中的内容转为QByteArray
        inBlock = tcpClient->readAll();
        //将block中内容写入file
        localFile->write(inBlock);
        //清空block
        inBlock.resize(0);
    }


    //设置进度条最大值为所有字节，当前值为已接受字节
    ui->progressBar->setMaximum(totalBytes);
    ui->progressBar->setValue(bytesReceived);
    //输出已接受字节
    qDebug()<<bytesReceived<<"received"<<totalBytes;

    //计算速度
    double speed = bytesReceived / useTime;
    //设置进度条上方提示信息
    ui->clientStatusLabel->setText(tr("已接收 %1MB (%2MB/s)     共%3MB\n已用时:%4秒    估计剩余时间：%5秒")
                                   //已接收
                                   .arg(bytesReceived / (1024*1024))
                                   //第一个参数代表速度，第二个参数0为最小宽度，第三个参数'f'表示取精度时的小数位数，第四个参数表示第三个参数代表的位数是2
                                   .arg(speed*1000/(1024*1024),0,'f',2)
                                   //总大小
                                   .arg(totalBytes / (1024 * 1024))
                                   //用时
                                   .arg(useTime/1000,0,'f',0)
                                   //剩余时间，其他参数见上面注释
                                   .arg(totalBytes/speed/1000 - useTime/1000,0,'f',0));

    //如果传输完毕
    if(bytesReceived == totalBytes)
    {
        //关闭套接字的I/O设备，断开套接字与主机的连接，关闭套接字，并重置名称、地址、端口号和底层套接字描述符
        tcpClient->close();
        //设置进度条上方提示信息
        ui->clientStatusLabel->setText(tr("接收文件 %1 完毕").arg(fileName));
        //接收完文件后，一定要关闭，不然可能出问题
        localFile->close();
    }

}


//切换语言版本
//void TcpClient::changeEvent(QEvent *event)
//{
//    QDialog::changeEvent(event);
//    //根据事件类型判别
//    switch(event->type())
//    {
//        //如果是语言改变事件
//        case QEvent::LanguageChange:
//        //更新UI的语言
//        ui->retranslateUi(this);
//        break;
//    default:
//        break;
//    }
//}

void TcpClient::setHostAddress(QHostAddress address)
{
    //获取服务器地址
    hostAddress = address;
    newConnect();
}

void TcpClient::mousePressEvent(QMouseEvent *e)
{
    last = e->globalPos();
}
void TcpClient::mouseMoveEvent(QMouseEvent *e)
{
    int dx = e->globalX() - last.x();
    int dy = e->globalY() - last.y();
    last = e->globalPos();
    move(x()+dx, y()+dy);
}
void TcpClient::mouseReleaseEvent(QMouseEvent *e)
{
    int dx = e->globalX() - last.x();
    int dy = e->globalY() - last.y();
    move(x()+dx, y()+dy);
}

void TcpClient::newConnect()
{
    //初始化blocksize，即每次发送的大小
    blockSize = 0;
    //中止当前连接并重置套接字
    tcpClient->abort();
    //根据给定端口号连接主机名
    tcpClient->connectToHost(hostAddress, tcpPort);
    //将此时间设置为当前时间,为了方便传输文件时计算时间和速度
    time.start();

}



void TcpClient::on_tcpClientCancleBtn_clicked()
{
    //中止当前连接并重置套接字
    tcpClient->abort();
    ui->progressBar->setValue(0);
}

void TcpClient::on_tcpClientCloseBtn_clicked()
{
    //中止当前连接并重置套接字
    tcpClient->abort();
    //关闭窗口
    this->close();
}
