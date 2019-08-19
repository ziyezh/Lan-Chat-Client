#ifndef TCPCLIENT_H
#define TCPCLIENT_H

#include <QWidget>
#include <QTcpSocket>
#include <QHostAddress>
#include <QFile>
#include <QTime>
#include <QEvent>
#include <QPoint>
namespace Ui {
class TcpClient;
}

class TcpClient : public QWidget
{
    Q_OBJECT

public:
    explicit TcpClient(QWidget *parent = 0);
    ~TcpClient();
    void setHostAddress(QHostAddress address);
    void updateServerProgress(qint64 numBytes);
    void setFileName(QString fileName){localFile = new QFile(fileName);}

protected:
//    void changeEvent(QEvent *);
    void mousePressEvent(QMouseEvent *e);
    void mouseMoveEvent(QMouseEvent *e);
    void mouseReleaseEvent(QMouseEvent *e);

private:
    Ui::TcpClient *ui;
    QTcpSocket *tcpClient;
    QHostAddress hostAddress;
    qint16 tcpPort;
    qint16 blockSize;

    //传输文件总字节数
    qint64 totalBytes;
    //已传输的字节
    qint64 bytesReceived;
    //待传输的字节
    qint64 bytesToReceive;
    //文件名的大小
    qint64 fileNameSize;
    //文件名
    QString fileName;
    //一个QFile类型的指针
    QFile *localFile;
    //一个数组来存储划分成块的文件
    QByteArray inBlock;

    QTime time;
    QPoint last;
public slots:
    void readMessage();
    void newConnect();
private slots:
    void on_tcpClientCancleBtn_clicked();
    void on_tcpClientCloseBtn_clicked();
    //void displayError(QAbstractSocket::SocketError);
};

#endif // TCPCLIENT_H
