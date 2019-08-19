#include "client.h"
#include "ui_client.h"
#include <QBitmap>
#include <QPainter>
#include <QFile>

//#define ip "172.20.10.2"
#define port 8000

Client::Client(QWidget *parent) :
    QWidget(parent),
    ui(new Ui::Client)
{
    ui->setupUi(this);
    this->setWindowFlags(Qt::FramelessWindowHint | Qt::WindowSystemMenuHint | Qt::WindowMinimizeButtonHint);
    setAttribute(Qt::WA_TranslucentBackground);
    pix.load(":/chat/image/clientBackground.png");
    this->resize(pix.size());
    ui->passwardLineEdit->setEchoMode(QLineEdit::Password);  //密码方式显示文本
    ui->userLineEdit->setFocusPolicy(Qt::StrongFocus);
    ui->userLineEdit->setFocus();
    init();
    connectServer();
}

Client::~Client()
{
    delete ui;
}

void Client::init()
{
    QFile file("serverIP.txt");
    if (!file.open(QIODevice::ReadOnly | QIODevice::Text))
    {
        qDebug()<<"====================fail=======================";
        ip = "172.20.10.2";
    }
    else
    {
        QTextStream in(&file);
        in >> ip;
    }


    w = NULL;
    tcpSocket=new QTcpSocket(this);
    connect(tcpSocket,SIGNAL(error(QAbstractSocket::SocketError)),
            this,SLOT(displayError(QAbstractSocket::SocketError)));   //发生错误时执行displayError函数
}

void Client::connectServer()
{
    tcpSocket->abort();   //取消已有的连接
    tcpSocket->connectToHost(ip,port);
    connect(tcpSocket,SIGNAL(readyRead()),this,SLOT(readMessages()));
}

void Client::on_sendBtn_clicked()
{
    QString userName=ui->userLineEdit->text();
    QString passward=ui->passwardLineEdit->text();
    if(userName=="" || passward=="")
        QMessageBox::information(this,"警告","输入不能为空",QMessageBox::Ok);
    QString bs="b";
    QString data=bs+"#"+userName+"#"+passward;
    tcpSocket->write(data.toLatin1());
}


void Client::on_signBtn_clicked()
{
    QString userName=ui->userLineEdit->text();
    QString passward=ui->passwardLineEdit->text();
    if(userName=="" || passward=="")
        QMessageBox::information(this,"警告","输入不能为空",QMessageBox::Ok);
    QString as="a";
    QString data=as+"#"+userName+"#"+passward;
    tcpSocket->write(data.toLatin1());
}


void Client::displayError(QAbstractSocket::SocketError)
{
    qDebug()<<tcpSocket->errorString();   //输出出错信息
}


void Client::readMessages()
{
    QString data=tcpSocket->readAll();
    QStringList list=data.split("#");
    if(list[0]=="a" && list[1]=="true")
        QMessageBox::information(this,"信息提示","注册成功!",QMessageBox::Ok);
    else if(list[0]=="a" && list[1]=="false")
        QMessageBox::information(this,"信息提示","注册失败,用户名已经被注册!",QMessageBox::Ok);
    else if(list[0]=="b" && list[1]=="true")
    {
        w = new Widget(ui->userLineEdit->text());
        QPropertyAnimation *animation = new QPropertyAnimation(w,"windowOpacity");
        animation->setDuration(800);
        animation->setStartValue(0);
        animation->setEndValue(1);
        animation->start();
        w->show();
        this->close();
    }
    else if(list[0]=="b" && list[1]=="false")
        QMessageBox::information(this,"信息提示","登录失败,用户名或密码错误!",QMessageBox::Ok);
    else
        return;
}

void Client::mousePressEvent(QMouseEvent *e)
{
    last = e->globalPos();
}
void Client::mouseMoveEvent(QMouseEvent *e)
{
    int dx = e->globalX() - last.x();
    int dy = e->globalY() - last.y();
    last = e->globalPos();
    move(x()+dx, y()+dy);
}
void Client::mouseReleaseEvent(QMouseEvent *e)
{
    int dx = e->globalX() - last.x();
    int dy = e->globalY() - last.y();
    move(x()+dx, y()+dy);
}

void Client::on_hideButton_clicked()
{
    if( windowState() != Qt::WindowMinimized )
    {
        setWindowState( Qt::WindowMinimized );
    }
}

void Client::on_closeButton_clicked()
{
    //慢慢消失的效果
    QPropertyAnimation *animation = new QPropertyAnimation(this,"windowOpacity");
    animation->setDuration(500);
    animation->setStartValue(1);
    animation->setEndValue(0);
    animation->start();
    connect(animation,SIGNAL(finished()),this,SLOT(close()));//效果显示完后关闭
}

void Client::paintEvent(QPaintEvent *e)
{
    QPainter painter(this);
    painter.drawPixmap(0,0,pix);
}
