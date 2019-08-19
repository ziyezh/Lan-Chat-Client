#ifndef TCPSERVER_H
#define TCPSERVER_H

#include <QWidget>
#include <QTcpSocket>
#include <QTime>
#include <QTcpServer>
#include <QFile>
#include <QTimer>
#include <QPoint>

namespace Ui {
class TcpServer;
}

class TcpServer : public QWidget
{
    Q_OBJECT

public:
    explicit TcpServer(QWidget *parent = 0);
    ~TcpServer();

    void refused();
    void initServer();


protected:
//    void changeEvent(QEvent *e);

    void mousePressEvent(QMouseEvent *e);
    void mouseMoveEvent(QMouseEvent *e);
    void mouseReleaseEvent(QMouseEvent *e);
private slots:
    void on_serverSendBtn_clicked();
    void on_serverOpenBtn_clicked();
    void sendMessage();
    void updateClientProgress(qint64 numBytes);
    void on_serverCloseBtn_clicked();

signals:
    void sendFileName(QString fileName);

private:
    Ui::TcpServer *ui;
    qint16 tcpPort;
    QTcpServer *tcpServer;
    QString fileName;
    QString theFileName;
    QFile *localFile;

    qint64 TotalBytes;
    qint64 bytesWritten;
    qint64 bytesToWrite;
    qint64 loadSize;//初始化时为64*1024
    QByteArray outBlock;//缓存一次发送的数据，可以看成一串或几串数字
    QTcpSocket *clientConnection;//套接字
    QTime time;
    QTimer timer;
    QPoint last;

};

#endif // TCPSERVER_H
