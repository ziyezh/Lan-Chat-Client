#ifndef CLIENT_H
#define CLIENT_H

#include "widget.h"
#include <QMainWindow>
#include <QtNetwork>
#include <QMessageBox>
#include <QMouseEvent>
#include <QPoint>
#include <QPaintEvent>
namespace Ui {
class Client;
}

class Client : public QWidget
{
    Q_OBJECT

public:
    explicit Client(QWidget *parent = 0);
    ~Client();

protected:
    void init();
    void connectServer();
    void mousePressEvent(QMouseEvent *e);
    void mouseMoveEvent(QMouseEvent *e);
    void mouseReleaseEvent(QMouseEvent *e);
    void paintEvent(QPaintEvent *e);

private slots:
    void on_sendBtn_clicked();

    void displayError(QAbstractSocket::SocketError);

    void on_signBtn_clicked();

    void readMessages();

    void on_hideButton_clicked();

    void on_closeButton_clicked();

private:
    Ui::Client *ui;
    QTcpSocket *tcpSocket;
    Widget *w;
    QPoint last;
    QPixmap pix;
    QString ip;
};

#endif // CLIENT_H
