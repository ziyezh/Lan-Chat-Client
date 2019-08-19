#include "chat.h"
#include "ui_chat.h"
#include "main_game_window.h"
#include "voice.h"
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
#include <QUrl>
#include <QImageReader>
#include <QImage>
#include <QVariant>
#include <QDesktopWidget>
#include <QDesktopServices>
chat::chat(QString myName, QString pasvusername, QString pasvuserip)
    :ui(new Ui::chat)
{
    ui->setupUi(this);
    setAppearance();

    //自动调用eventFliter函数,来实现按下回车键发送信息
    ui->textEditWrite->installEventFilter(this);

    xpasvusername = pasvusername;
    xpasvuserip = pasvuserip;
    myUserName = myName;
    ui->label->setText(tr("  与 %1 聊天中").arg(xpasvusername));
    setWindowTitle(xpasvusername);
    newvoice = NULL;
    xchat = new QUdpSocket(this);
    xport = 45456;
    xchat->bind(QHostAddress(getIP()), xport );
    connect(xchat, &QUdpSocket::readyRead, this, &chat::processPendingDatagrams);

    server = new TcpServer(this);
    server->close();
    connect(server,&TcpServer::sendFileName,this,&chat::sentFileName);
    connect(ui->textEditWrite,&QTextEdit::currentCharFormatChanged,this,&chat::currentFormatChanged);

}

chat::~chat()
{
    delete newvoice;
    delete ui;
}


//通过私聊套接字发送到对方的私聊专用端口上
void chat::sendMessage(MessageType type, QString serverAddress)  //发送信息
{
    QByteArray data;
    QDataStream out(&data,QIODevice::WriteOnly);
    QString localHostName = QHostInfo::localHostName();
    QString address = getIP();
    out << type << getUserName() << localHostName;


    switch(type)
    {
    case NewParticipant:
    {
        break;
    }
    case ParticipantLeft:
    {
        break;
    }
    case Message :
    {
        if(ui->textEditWrite->toPlainText() == "")
        {
            return;
        }
        else
        {
            //将ip地址和得到的消息内容输入out数据流
            out <<address <<getMessage();
            ui->textEditRead->verticalScrollBar()->setValue(ui->textEditRead->verticalScrollBar()->maximum());
            break;
        }
    }
    case FileName:
    {
        QString clientAddress = xpasvuserip;
        out << address << clientAddress << fileName;
        break;
    }
    case Refuse:
    {
        out << serverAddress;
        break;
    }
    case Xchat:
    {
        break;
    }
    }
    if(type != FileName)
    {
        xchat->writeDatagram(data,data.length(),QHostAddress(xpasvuserip), xport);
        xchat->writeDatagram(data,data.length(),QHostAddress(getIP()), xport);
    }
    else
    {
        xchat->writeDatagram(data,data.length(),QHostAddress(xpasvuserip), xport);
    }

}

void chat::processPendingDatagrams()
{
    while(xchat->hasPendingDatagrams())
    {
        QByteArray datagram;
        datagram.resize(xchat->pendingDatagramSize());
        xchat->readDatagram(datagram.data(),datagram.size());
        QDataStream in(&datagram,QIODevice::ReadOnly);
        int messageType;
        in >> messageType;
        QString userName,localHostName,ipAddress,messagestr;
        QString time = QDateTime::currentDateTime().toString("yyyy-MM-dd hh:mm:ss");
        switch(messageType)
        {
        case Xchat:
        {
            break;
        }
        case Message:
        {
            in>>userName>>localHostName>>ipAddress>>messagestr;
            if(QHostInfo::localHostName() != localHostName)
            {
                ui->textEditRead->setTextColor(QColor(65, 165, 155));
                ui->textEditRead->setCurrentFont(QFont("宋体",10));
                ui->textEditRead->append(userName + "   "+ time );
                ui->textEditRead->append(messagestr);
                this->show();
            }
            else
            {
                ui->textEditRead->setTextColor(QColor(142, 168, 118));
                ui->textEditRead->setCurrentFont(QFont("宋体",10));
                ui->textEditRead->append(userName + "   "+ time );
                ui->textEditRead->append(messagestr);
            }
            if(windowState() == Qt::WindowMinimized)
            {
                QApplication::alert(this);
            }
            break;
        }
        case FileName:
        {
            in >>userName >>localHostName >> ipAddress;
            QString clientAddress,fileName;
            in >> clientAddress >> fileName;
            hasPendingFile(userName,ipAddress,clientAddress,fileName);
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
        case ParticipantLeft:
        {
            break;
        }
        }
    }

}

void chat::hasPendingFile(QString userName,QString serverAddress,  //接收文件
                          QString clientAddress,QString fileName)
{
    QString ipAddress = getIP();
    if(ipAddress == clientAddress)
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
        else{
            sendMessage(Refuse,serverAddress);
        }
    }
}


void chat::sentFileName(QString fileName)
{
    this->fileName = fileName;
    sendMessage(FileName);
}

void chat::currentFormatChanged(const QTextCharFormat &format)
{
    //当编辑器的字体格式改变时，我们让部件状态也随之改变
    ui->fontComboBox->setCurrentFont(format.font());
    ui->fontSizeComboBox->setCurrentIndex(ui->fontSizeComboBox->findText(QString::number(format.fontPointSize())));
    ui->textbold->setChecked(format.font().bold());
    ui->textitalic->setChecked(format.font().italic());
    ui->textUnderline->setChecked(format.font().underline());
    color = format.foreground().color();
}

QString chat::getIP()  //获取ip地址
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

QString chat::getUserName()  //获取用户名
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
    return myUserName;
}

QString chat::getMessage()  //获得要发送的信息
{
    QString msg = ui->textEditWrite->toHtml();
    ui->textEditWrite->clear();
    ui->textEditWrite->setFocus();
    return msg;
}

void chat::setAppearance()
{
    //隐藏标题栏，实现点击任务栏图标可以实现最小化
    this->setWindowFlags(Qt::FramelessWindowHint | Qt::WindowSystemMenuHint | Qt::WindowMinimizeButtonHint);
    //ui->stackedWidget->setStyleSheet("QStackedWidget {border-image: url(:/chat/image/chatBackground.jpg);}");
    ui->fontComboBox->setVisible(false);
    ui->fontSizeComboBox->setVisible(false);
    ui->fontSizeComboBox->setCurrentIndex(1);
    ui->textbold->setVisible(false);
    ui->textcolor->setVisible(false);
    ui->textitalic->setVisible(false);
    ui->textUnderline->setVisible(false);
    ui->clear->setVisible(false);
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


}

//实现按回车键发送信息
bool chat::eventFilter(QObject *target, QEvent *event)
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


void chat::on_textButton_clicked(bool checked)
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

void chat::on_sendfile_clicked()
{
    server->show();
    server->move((QApplication::desktop()->width()-server->width())/10,(QApplication::desktop()->height()-server->height())/3);
    server->initServer();
}

void chat::on_imageButton_clicked()
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

void chat::on_save_clicked()
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

void chat::on_SendButton_clicked()
{
    sendMessage(Message);
}

void chat::on_fontComboBox_currentFontChanged(const QFont &f)
{
    ui->textEditWrite->setCurrentFont(f);
    ui->textEditWrite->setFocus();
}

void chat::on_fontSizeComboBox_currentIndexChanged(const QString &size)
{
    ui->textEditWrite->setFontPointSize(size.toDouble());
    ui->textEditWrite->setFocus();
}

void chat::on_textbold_clicked(bool checked)
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

void chat::on_textitalic_clicked(bool checked)
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

void chat::on_textUnderline_clicked(bool checked)
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

void chat::on_clear_clicked()
{
    ui->textEditRead->clear();
}

void chat::on_textcolor_clicked()
{
    color = QColorDialog::getColor(color,this);
    if(color.isValid())
    {
        ui->textEditWrite->setTextColor(color);
        ui->textEditWrite->setFocus();
    }
}

void chat::on_hideButton_clicked()
{
    if( windowState() != Qt::WindowMinimized )
    {
        setWindowState( Qt::WindowMinimized );
    }
}

void chat::on_closeButton_clicked()
{
    delete newvoice;
    this->close();
}

void chat::mousePressEvent(QMouseEvent *e)
{
    last = e->globalPos();
}
void chat::mouseMoveEvent(QMouseEvent *e)
{
    int dx = e->globalX() - last.x();
    int dy = e->globalY() - last.y();
    last = e->globalPos();
    move(x()+dx, y()+dy);
}
void chat::mouseReleaseEvent(QMouseEvent *e)
{
    int dx = e->globalX() - last.x();
    int dy = e->globalY() - last.y();
    move(x()+dx, y()+dy);
}

void chat::on_gameButton_clicked()
{
    MainGameWindow *w = new MainGameWindow(this);
    w->show();
}


void chat::on_voiceButton_clicked(bool checked)
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
        newvoice = new VoiceWindow(xpasvuserip);
        newvoice->setParent(this);
        newvoice->show();
        newvoice->move((QApplication::desktop()->width()-newvoice->width())/12,(QApplication::desktop()->height()-newvoice->height())/3);
    }
}

void chat::on_webButton_clicked()
{
    const QUrl regUrl(QLatin1String("https://github.com/wc-chat1/wc_chat"));
    QDesktopServices::openUrl(regUrl);
}
