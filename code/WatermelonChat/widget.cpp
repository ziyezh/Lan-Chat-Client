#include "widget.h"
#include "ui_widget.h"
#include "main_game_window.h"
#include <QEvent>
#include <QKeyEvent>
#include <QDateTime>
#include <QHostInfo>
#include <QScrollBar>
#include <QNetworkInterface>
#include <QProcess>
#include <QMessageBox>
#include <QFileDialog>
#include <QHostAddress>
#include <QColorDialog>
#include <QDebug>
#include <QPropertyAnimation>
#include <QAction>
#include <QDesktopWidget>
#include <QUrl>
#include<QImageReader>
#include<QImage>
#include<QVariant>
#include <QDesktopServices>
#include <QMenu>

Widget::Widget(QString name):
    ui(new Ui::Widget)
{
    ui->setupUi(this);
    userName = name;
    //设置外观
    setAppearance();
    QMenu *ChangeBackGroundMenu=new QMenu(this);
    ChangeBackGroundMenu->addAction(action1);
    ChangeBackGroundMenu->addAction(action2);
    ChangeBackGroundMenu->addAction(action3);
    ui->changeButton->setMenu(ChangeBackGroundMenu);
    connect(action1,&QAction::triggered,this,&Widget::action1_slot);
    connect(action2,&QAction::triggered,this,&Widget::action2_slot);
    connect(action3,&QAction::triggered,this,&Widget::action3_slot);
    //自动调用eventFliter函数,来实现按下回车键发送信息
    ui->textEditWrite->installEventFilter(this);

    udpSocket = new QUdpSocket(this);
    port = 19999;
    privatechat1 = NULL;
    newvoice = NULL;
    //连接本机的port端口，采用ShareAddress模式(即允许其它的服务连接到相同的地址和端口，特别是用在多客户端监听同一个服务器端口等时特别有效)，和ReuseAddressHint模式(重新连接服务器)
    udpSocket->bind(QHostAddress(getIP()),port);//,QAbstractSocket::ShareAddress|QAbstractSocket::ReuseAddressHint
    //readyRead()信号是每当有新的数据来临时就被触发

    connect(udpSocket, &QUdpSocket::readyRead, this, &Widget::processPendingDatagrams);

    //打开软件时就向外发射本地信息，让其他在线用户得到通知
    sendMessage(NewParticipant);

    //发送文件服务器端
    server = new TcpServer(this);
    server->close();
    connect(server,&TcpServer::sendFileName,this,&Widget::sentFileName);
    connect(ui->textEditWrite,&QTextEdit::currentCharFormatChanged,this,&Widget::currentFormatChanged);
}

Widget::~Widget()
{
    delete ui;
}

void Widget::currentFormatChanged(const QTextCharFormat &format)
{//当编辑器的字体格式改变时，我们让部件状态也随之改变
    ui->fontComboBox->setCurrentFont(format.font());
    ui->fontSizeComboBox->setCurrentIndex(ui->fontSizeComboBox->findText(QString::number(format.fontPointSize())));
    ui->textbold->setChecked(format.font().bold());
    ui->textitalic->setChecked(format.font().italic());
    ui->textUnderline->setChecked(format.font().underline());
    color = format.foreground().color();
}

//接收数据
void Widget::processPendingDatagrams()
{
    while(udpSocket->hasPendingDatagrams())
    {
        QByteArray datagram;
        datagram.resize(udpSocket->pendingDatagramSize());
        udpSocket->readDatagram(datagram.data(), datagram.size());
        QDataStream in(&datagram, QIODevice::ReadOnly);
        int messageType;
        in>>messageType;
        QString userName, localHostName, ipAddress, message;
        QString time = QDateTime::currentDateTime().toString("yyyy-MM-dd hh:mm:ss");
        switch(messageType)
        {
        case Message:
        {
            in>>userName>>localHostName>>ipAddress>>message;
            if(QHostInfo::localHostName() != localHostName)
            {
                ui->textEditRead->setTextColor(QColor(65, 165, 155));
                ui->textEditRead->setCurrentFont(QFont("宋体",10));
                ui->textEditRead->append(userName + "   "+ time );
                ui->textEditRead->append(message);
                if(windowState() == Qt::WindowMinimized)
                {
                    QApplication::alert(this);
                }
            }
            else
            {
                ui->textEditRead->setTextColor(QColor(142, 168, 118));
                ui->textEditRead->setCurrentFont(QFont("宋体",10));
                ui->textEditRead->append(userName + "   "+ time );
                ui->textEditRead->append(message);
            }
            break;
        }
        case NewParticipant:
        {
            in>>userName>>localHostName>>ipAddress;
            newParticipant(userName,localHostName,ipAddress);
            break;
        }
        case ParticipantLeft:
        {
            in >>userName >>localHostName;
            participantLeft(userName,localHostName,time);
            break;
        }
        case FileName:
        {
            in >>userName >>localHostName >> ipAddress;
            if(getIP()!=ipAddress)
            {
                QString fileName;
                in >> fileName;
                hasPendingFile(userName,ipAddress,fileName);
            }
            break;
        }
        case Refuse:
        {
            in >> userName >> localHostName;
            QString serverAddress;
            in >> serverAddress;
            QString ipAddress = getIP();

            if(ipAddress == serverAddress)
            {
                server->refused();
            }
            break;
        }
        case Xchat:
        {
            in >>userName >>localHostName >>ipAddress;
            showxchat(getUserName(), userName,ipAddress);//显示与主机名聊天中
            break;
        }
        default:
            break;
        }
    }

}
//处理新用户的加入，在右边的tableWidget显示在线的用户名、主机名、ip
void Widget::newParticipant(QString userName,QString localHostName,QString ipAddress)
{
    //判断是否主机名重名
    if(ui->tableWidget->findItems(localHostName, Qt::MatchExactly).isEmpty())
    {
        //创建三个QTableWidgetItem类型指针
        QTableWidgetItem *user = new QTableWidgetItem(userName);
        QTableWidgetItem *host = new QTableWidgetItem(localHostName);
        QTableWidgetItem *ip = new QTableWidgetItem(ipAddress);
        //设置列数为3
        ui->tableWidget->setColumnCount(3);
        //自动调整列宽
        ui->tableWidget->horizontalHeader()->setStretchLastSection(true);
        //增加行
        ui->tableWidget->insertRow(0);
        //增加行内第一个数据用户名
        ui->tableWidget->setItem(0,0,user);
        ui->tableWidget->item(0,0)->setTextAlignment(Qt::AlignCenter);
        //增加行内第二个数据主机名
        ui->tableWidget->setItem(0,1,host);
        //增加行内第三个数据ip
        ui->tableWidget->setItem(0,2,ip);
        //设置阅读框文字的颜色，字体，字号
        ui->textEditRead->setTextColor(QColor(150, 150, 150, 255));
        ui->textEditRead->setCurrentFont(QFont("宋体",10));
        //提示新用户上线
        ui->textEditRead->append(tr("%1 上线").arg(userName));
        //通过数行数得到人数，显示在线人数
        ui->userNumber->setText(tr("在线人数：%1").arg(ui->tableWidget->rowCount()));
        sendMessage(NewParticipant);

    }
}

//sendMessage即把本机的主机名，用户名+（消息内容后ip地址）广播出去
void Widget::sendMessage(MessageType type, QString serverAddress)
{
    QByteArray data;
    //将数组以只写的方式传入数据流内
    QDataStream out(&data, QIODevice::WriteOnly);
    //获取本机的主机名
    QString localHostName = QHostInfo::localHostName();
    //获取ip地址
    QString address = getIP();
    //将type，getUserName()，localHostName按照先后顺序送到out数据流中，消息类型type在最前面
    out << type << getUserName() << localHostName;

    //根据消息类型选择相应动作
    switch(type)
    {
    //若消息类型为新加入者
    case Xchat:
    {
        break;
    }
    case ParticipantLeft:
    {
        break;
    }
    case NewParticipant:
    {
        out << address;
        break;
    }
    case Message:
    {
        //如果发送为空，无动作，以防发出只有用户名没有内容的消息
        if(ui->textEditWrite->toPlainText() == "")
        {
            return;
        }
        else
        {
            //将ip地址和得到的消息内容输入out数据流
            out <<address <<getMessage();
            //设置阅读框文字超出视图后，滚动条自动移至最底部
            ui->textEditRead->verticalScrollBar()->setValue(ui->textEditRead->verticalScrollBar()->maximum());
        }
        break;
    }
    case FileName:
    {
        out << address<< fileName;
        break;
    }
    case Refuse:
    {
        out << serverAddress;
        break;
    }
    }
    //将data中的数据发送
    udpSocket->writeDatagram(data, data.length(), QHostAddress::Broadcast, port);
}

void Widget::participantLeft(QString userName,QString localHostName,QString time)
{
    int rowNum = ui->tableWidget->findItems(localHostName,Qt::MatchExactly).first()->row();
    ui->tableWidget->removeRow(rowNum);
    ui->textEditRead->setTextColor(QColor(100, 50, 50, 255));
    ui->textEditRead->setCurrentFont(QFont("宋体",10));
    ui->textEditRead->append(tr("\n%1  %2 离开").arg(userName).arg(time));
    ui->userNumber->setText(tr("在线人数：%1").arg(ui->tableWidget->rowCount()));
}


QString Widget::getIP()
{
    QString localName = QHostInfo::localHostName();
    QList<QHostAddress> list = QHostInfo::fromName(localName).addresses();
    foreach (QHostAddress address, list)
    {
        if(address.protocol() == QAbstractSocket::IPv4Protocol) //我们使用IPv4地址
            return address.toString();
    }

    return 0;
}

QString Widget::getUserName()
{
    //    QStringList envVariables;
    //    envVariables << "USERNAME.*" << "USER.*" << "USERDOMAIN.*"
    //                 << "HOSTNAME.*" << "DOMAINNAME.*";
    //    QStringList environment = QProcess::systemEnvironment();
    //    foreach (QString string, envVariables)
    //    {
    //        int index = environment.indexOf(QRegExp(string));
    //        if (index != -1)
    //        {

    //            QStringList stringList = environment.at(index).split('=');
    //            if (stringList.size() == 2)
    //            {
    //                return stringList.at(1);
    //                break;
    //            }
    //        }
    //    }
    //    return false;
    return userName;
}

QString Widget::getMessage()  //获得要发送的信息
{
    QString msg = ui->textEditWrite->toHtml();
    ui->textEditWrite->clear();
    ui->textEditWrite->setFocus();
    return msg;
}

void Widget::sentFileName(QString fileName)
{
    this->fileName = fileName;
    sendMessage(FileName);
}

void Widget::hasPendingFile(QString userName,QString serverAddress,QString fileName)
{
    int btn = QMessageBox::information(this,tr("接受文件"),
                                       tr("来自%1(%2)的文件：%3\n是否接收？")
                                       .arg(userName).arg(serverAddress).arg(fileName),
                                       QMessageBox::Yes,QMessageBox::No);
    if(btn == QMessageBox::Yes)
    {
        QString name = QFileDialog::getSaveFileName(0,tr("保存文件"),fileName);
        if(!name.isEmpty())
        {
            TcpClient *client = new TcpClient(this);
            client->setFileName(name);
            client->setHostAddress(QHostAddress(serverAddress));
            client->show();
            //使窗体出现在中间
            client->move((QApplication::desktop()->width()-server->width())/6,(QApplication::desktop()->height()-server->height())/3);
        }

    }
    else
    {
        sendMessage(Refuse,serverAddress);
    }
}

bool Widget::saveFile(const QString &fileName)//保存文件
{
    QFile file(fileName);
    if(!file.open(QFile::WriteOnly | QFile::Text))

    {
        QMessageBox::warning(this,tr("保存文件"),
                             tr("无法保存文件 %1:\n %2").arg(fileName)
                             .arg(file.errorString()));
        return false;
    }
    QTextStream out(&file);
    out << ui->textEditRead->toPlainText();

    return true;
}

void Widget::setAppearance()
{
    //重新设置窗口大小为1000*800
    this->resize(1000,800);
    //隐藏标题栏
    this->setWindowFlags(Qt::FramelessWindowHint | Qt::WindowSystemMenuHint | Qt::WindowMinimizeButtonHint);

    //设置tablewidget的属性
    ui->tableWidget->setColumnCount(3);
    QStringList header;
    header<<"用户名" << "主机名" << "IP";
    ui->fontComboBox->setVisible(false);
    ui->fontSizeComboBox->setCurrentIndex(1);
    ui->fontSizeComboBox->setVisible(false);
    ui->textbold->setVisible(false);
    ui->textcolor->setVisible(false);
    ui->textitalic->setVisible(false);
    ui->textUnderline->setVisible(false);
    ui->clear->setVisible(false);
    ui->tableWidget->setHorizontalHeaderLabels(header);
    ui->tableWidget->horizontalHeader()->setStretchLastSection(true);
    ui->tableWidget->setColumnWidth(0, 90);
    ui->tableWidget->setColumnWidth(1, 130);
    ui->tableWidget->setContextMenuPolicy(Qt::CustomContextMenu);
    ui->tableWidget->setHorizontalScrollBarPolicy(Qt::ScrollBarAlwaysOff);
    ui->tableWidget->setShowGrid(false);
    ui->tableWidget->setSelectionBehavior(QAbstractItemView::SelectRows);//单击选择一行
    ui->tableWidget->setSelectionMode(QAbstractItemView::SingleSelection);//设置只能选择一行，不能多行选中
    ui->tableWidget->setEditTriggers(QAbstractItemView::NoEditTriggers);//设置每行内容不可更改
    ui->tableWidget->setAlternatingRowColors(true);//设置隔一行变一颜色，即：一灰一白
    ui->textEditRead->verticalScrollBar()->setStyleSheet(
                "QScrollBar:vertical{width:8px;background:rgba(0,0,0,0%);margin:0px,0px,0px,0px;padding-top:9px;padding-bottom:9px;}"//留9px给上下箭头
                "QScrollBar::handle:vertical{width:8px;background:rgba(0,0,0,25%);border-radius:4px;min-height:20;}"//上下设置为椭圆
                "QScrollBar::handle:vertical:hover{width:8px;background:rgba(0,0,0,50%);border-radius:4px;min-height:20;}"//鼠标悬浮颜色变深
                "QScrollBar::add-line:vertical{height:9px;width:8px;border-image:url(:/chat/image/icon/bottom.png);subcontrol-position:bottom;}"//下箭头
                "QScrollBar::sub-line:vertical{height:9px;width:8px;border-image:url(:/chat/image/icon/top.png);subcontrol-position:top;}"//上箭头
                "QScrollBar::add-line:vertical:hover{height:7px;width:6px;border-image:url(:/chat/image/icon/bottom.png);border:1px;subcontrol-position:bottom;}"//鼠标悬浮下箭头
                "QScrollBar::sub-line:vertical:hover{height:7px;width:6px;border-image:url(:/chat/image/icon/top.png);border:1px;subcontrol-position:top;}"//鼠标悬浮上箭头
                "QScrollBar::add-page:vertical,QScrollBar::sub-page:vertical{background:rgba(0,0,0,10%);border-radius:4px;}");//滚动时部分
    ui->textEditWrite->verticalScrollBar()->setStyleSheet(
                "QScrollBar:vertical{width:8px;background:rgba(0,0,0,0%);margin:0px,0px,0px,0px;padding-top:9px;padding-bottom:9px;}"//留9px给上下箭头
                "QScrollBar::handle:vertical{width:8px;background:rgba(0,0,0,25%);border-radius:4px;min-height:20;}"//上下设置为椭圆
                "QScrollBar::handle:vertical:hover{width:8px;background:rgba(0,0,0,50%);border-radius:4px;min-height:20;}"//鼠标悬浮颜色变深
                "QScrollBar::add-line:vertical{height:9px;width:8px;border-image:url(:/chat/image/icon/bottom.png);subcontrol-position:bottom;}"//下箭头
                "QScrollBar::sub-line:vertical{height:9px;width:8px;border-image:url(:/chat/image/icon/top.png);subcontrol-position:top;}"//上箭头
                "QScrollBar::add-line:vertical:hover{height:7px;width:6px;border-image:url(:/chat/image/icon/bottom.png);border:1px;subcontrol-position:bottom;}"//鼠标悬浮下箭头
                "QScrollBar::sub-line:vertical:hover{height:7px;width:6px;border-image:url(:/chat/image/icon/top.png);border:1px;subcontrol-position:top;}"//鼠标悬浮上箭头
                "QScrollBar::add-page:vertical,QScrollBar::sub-page:vertical{background:rgba(0,0,0,10%);border-radius:4px;}");//滚动时部分
    //设置光标在输入框
    ui->textEditWrite->setFocusPolicy(Qt::StrongFocus);
    ui->textEditRead->setFocusPolicy(Qt::NoFocus);
    ui->textEditWrite->setFocus();

    ui->stackedWidget->setStyleSheet("QStackedWidget {border-image: url(:/chat/image/background1.png);}");
    action1=new QAction(this);
    action2=new QAction(this);
    action3=new QAction(this);
    action1->setIcon(QIcon(":/chat/image/icon/icon_menu.png"));
    action1->setText(tr("原始"));
    action2->setIcon(QIcon(":/chat/image/icon/icon_menu.png"));
    action2->setText(tr("飞天小女警"));
    action3->setIcon(QIcon(":/chat/image/icon/icon_menu.png"));
    action3->setText(tr("自定义"));
}

void Widget::showxchat(QString myname, QString name, QString ip)
{
    privatechat1 = new chat(myname, name,ip);
}


//实现按回车键发送信息
bool Widget::eventFilter(QObject *target, QEvent *event)
{
    //判断目标是否是输入框
    if(target == ui->textEditWrite)
    {
        //判断事件是否是按下键盘
        if(event->type() == QEvent::KeyPress)
        {
            QKeyEvent *e = static_cast<QKeyEvent *>(event);
            //判断是否按下回车键
            if(e->key() == Qt::Key_Return)
            {
                //调用发送按钮的槽函数
                on_SendButton_clicked();
                return true;
            }
        }
        else
        {
            return QWidget::eventFilter( target, event);
        }
    }
}

void Widget::closeEvent(QCloseEvent *e)
{
    sendMessage(ParticipantLeft);
    QWidget::closeEvent(e);
}

void Widget::on_SendButton_clicked()
{
    sendMessage(Message);
}

void Widget::on_textcolor_clicked()
{
    color = QColorDialog::getColor(color,this);
    if(color.isValid())
    {
        ui->textEditWrite->setTextColor(color);
        ui->textEditWrite->setFocus();
    }
}

void Widget::on_textUnderline_clicked(bool checked)
{
    checked =!(ui->textEditWrite->fontUnderline());
    if(checked)
    {
        ui->textUnderline->setStyleSheet("background-color: rgb(50, 50, 50,50); border-radius: 3px;border-image: url(:/chat/image/icon/icon_underline.png);");
    }
    else
    {
        ui->textUnderline->setStyleSheet("QToolButton { background-color: rgb(50, 50, 50,0); border-radius: 3px;border-image: url(:/chat/image/icon/icon_underline.png);}"
                                         "QToolButton:hover { background-color:rgba(172, 178, 148, 100)}");
    }
    ui->textEditWrite->setFontUnderline(checked);
    ui->textEditWrite->setFocus();
}

void Widget::on_textbold_clicked(bool checked)
{
    checked = ((ui->textEditWrite->fontWeight())!= QFont::Bold);
    if(checked)
    {
        ui->textEditWrite->setFontWeight(QFont::Bold);
        ui->textbold->setStyleSheet("background-color: rgb(50, 50, 50,50); border-radius: 3px;border-image: url(:/chat/image/icon/icon_bold.png);");
    }
    else
    {
        ui->textEditWrite->setFontWeight(QFont::Normal);
        ui->textbold->setStyleSheet("QToolButton { background-color: rgb(50, 50, 50,0); border-radius: 3px;border-image: url(:/chat/image/icon/icon_bold.png);}"
                                    "QToolButton:hover { background-color:rgba(172, 178, 148, 100)}");
    }
    ui->textEditWrite->setFocus();
}

void Widget::on_textitalic_clicked(bool checked)
{

    checked =!(ui->textEditWrite->fontItalic());
    if(checked)
    {
        ui->textitalic->setStyleSheet("background-color: rgb(50, 50, 50,50); border-radius: 3px;border-image: url(:/chat/image/icon/icon_italic.png);");
    }
    else
    {
        ui->textitalic->setStyleSheet("QToolButton { background-color: rgb(50, 50, 50,0); border-radius: 3px;border-image: url(:/chat/image/icon/icon_italic.png);}"
                                      "QToolButton:hover { background-color:rgba(172, 178, 148, 100)}");
    }
    ui->textEditWrite->setFontItalic(checked);
    ui->textEditWrite->setFocus();
}

void Widget::on_clear_clicked()
{
    ui->textEditRead->clear();
}

void Widget::on_fontComboBox_currentFontChanged(const QFont &f)
{
    ui->textEditWrite->setCurrentFont(f);
    ui->textEditWrite->setFocus();
}

void Widget::on_fontSizeComboBox_currentIndexChanged(const QString &size)
{
    ui->textEditWrite->setFontPointSize(size.toDouble());
    ui->textEditWrite->setFocus();
}

void Widget::on_hideButton_clicked()
{
    if( windowState() != Qt::WindowMinimized )
    {
        setWindowState( Qt::WindowMinimized );
    }
}

void Widget::on_closeButton_clicked()
{
    //慢慢消失的效果
    QPropertyAnimation *animation = new QPropertyAnimation(this,"windowOpacity");
    animation->setDuration(1000);
    animation->setStartValue(1);
    animation->setEndValue(0);
    animation->start();
    connect(animation,SIGNAL(finished()),this,SLOT(close()));//效果显示完后关闭
}

void Widget::on_sendfile_clicked()
{
    server->show();
    server->move((QApplication::desktop()->width()-server->width())/6,(QApplication::desktop()->height()-server->height())/3);
    server->initServer();
}

void Widget::on_save_clicked()
{
    QString fileName = QFileDialog::getSaveFileName(this, tr("Save File"),"C:",  tr("文件(*.txt)"));
    if (fileName.isEmpty())
    {
        return;

    }
    QFile *newFile = new QFile;
    newFile ->setFileName(fileName);
    bool ok = newFile->open(QIODevice::WriteOnly);
    if(ok)
    {
        QTextStream out(newFile);
        out<<ui->textEditRead->toPlainText();
        newFile->close();
        delete newFile;
    }
    else
    {
        QMessageBox::information(this, "error", "fail to save the file");

    }

}


void Widget::mousePressEvent(QMouseEvent *e)
{
    last = e->globalPos();
}
void Widget::mouseMoveEvent(QMouseEvent *e)
{
    int dx = e->globalX() - last.x();
    int dy = e->globalY() - last.y();
    last = e->globalPos();
    move(x()+dx, y()+dy);
}
void Widget::mouseReleaseEvent(QMouseEvent *e)
{
    int dx = e->globalX() - last.x();
    int dy = e->globalY() - last.y();
    move(x()+dx, y()+dy);
}

void Widget::on_gameButton_clicked()
{
    MainGameWindow *w = new MainGameWindow(this);
    w->show();
}

void Widget::on_textButton_clicked(bool checked)
{
    checked = (ui->fontComboBox->isVisible());
    if(!checked)
    {
        ui->fontComboBox->setVisible(true);
        ui->fontSizeComboBox->setVisible(true);
        ui->textbold->setVisible(true);
        ui->textcolor->setVisible(true);
        ui->textitalic->setVisible(true);
        ui->textUnderline->setVisible(true);
        ui->clear->setVisible(true);

    }
    else
    {
        ui->fontComboBox->setVisible(false);
        ui->fontSizeComboBox->setVisible(false);
        ui->textbold->setVisible(false);
        ui->textcolor->setVisible(false);
        ui->textitalic->setVisible(false);
        ui->textUnderline->setVisible(false);
        ui->clear->setVisible(false);

    }
}

void Widget::on_tableWidget_doubleClicked(const QModelIndex &index)
{
    QString hostName = ui->tableWidget->item(index.row(),1)->text();
    if(ui->tableWidget->item(index.row(),0)->text() == getUserName() &&
            ui->tableWidget->item(index.row(),2)->text() == getIP())
    {
        return;
    }
    else
    {
        if(!chatMap.contains(hostName))
        {
            privatechat = new chat(getUserName(), ui->tableWidget->item(index.row(),0)->text(), //接收用户名
                                   ui->tableWidget->item(index.row(),2)->text()) ;//接收用户IP
            chatMap.insert(hostName, privatechat);
            QByteArray data;
            QDataStream out(&data,QIODevice::WriteOnly);
            QString localHostName = QHostInfo::localHostName();
            QString address = getIP();
            out << Xchat << getUserName() << localHostName << address;
            udpSocket->writeDatagram(data,data.length(),QHostAddress(ui->tableWidget->item(index.row(),2)->text()), port);
            chatMap.value(hostName)->show();
        }
        else
        {
            chatMap.value(hostName)->show();
        }
    }

}

void Widget::on_imageButton_clicked()
{
    QString file= QFileDialog::getOpenFileName(this, tr("Open Image File"),".",
                                               tr("Image files(*.bmp *.jpg *.pbm *.pgm *.png *.ppm *.xbm *.xpm)"));
    QUrl url(QString("file://%1").arg(file));
    QImage image =QImageReader(file).read();
    QImage newImg = image.scaledToWidth(295);
    QTextDocument *textDocument = ui->textEditWrite->document();
    textDocument->addResource(QTextDocument::ImageResource,url,QVariant(newImg));
    QTextCursor cursor = ui->textEditWrite->textCursor();
    QTextImageFormat imageFormat;
    imageFormat.setWidth(newImg.width());
    imageFormat.setHeight(newImg.height());
    imageFormat.setName(file);
    cursor.insertImage(imageFormat);
}

void Widget::on_voiceButton_clicked(bool checked)
{
    checked = !(newvoice == NULL);
    if(checked)
    {
        newvoice->close();
        delete newvoice;
        newvoice = NULL;
        ui->voiceButton->setStyleSheet("QPushButton { background-color: rgb(50, 50, 50,0); border-radius: 6px; color: rgb(255, 255, 255); border-image: url(:/chat/image/icon/icon_novoice.png);}"
                                       "QPushButton:hover { background-color:rgba(172, 178, 148, 100)}");
    }
    else
    {
        ui->voiceButton->setStyleSheet("QPushButton { background-color: rgb(50, 50, 50,0); border-radius: 6px; color: rgb(255, 255, 255); border-image: url(:/chat/image/icon/icon_voice.png);}"
                                       "QPushButton:hover { background-color:rgba(172, 178, 148, 100)}");
        newvoice = new GroupVoice(this);
        newvoice->show();
        newvoice->move((QApplication::desktop()->width()-newvoice->width())/12,(QApplication::desktop()->height()-newvoice->height())/3);
    }
}

void Widget::on_webButton_clicked()
{
    const QUrl regUrl(QLatin1String("https://github.com/EmilyZhangzzy/Watermelon_Chat"));
    QDesktopServices::openUrl(regUrl);
}

void Widget::action1_slot()//设置菜单  添加图片
{

    ui->stackedWidget->setStyleSheet("QStackedWidget {border-image: url(:/chat/image/background1.png);}");

}
void Widget::action2_slot()//设置菜单  添加图片
{

    ui->stackedWidget->setStyleSheet("QStackedWidget {border-image: url(:/chat/image/background2.jpg);}");

}
void Widget::action3_slot()//设置菜单  添加图片
{

    QString FileName=QFileDialog::getOpenFileName(this,tr("背景"),".",tr("Image file(*.bmp *.jpg *.pbm *.pgm *.png *.ppm *.xbm *.xpm)"));
    if(FileName!="")
    {
        ui->stackedWidget->setStyleSheet("QStackedWidget {border-image: url("+FileName+");}");
    }
}
