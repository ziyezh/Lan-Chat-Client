#ifndef WIDGET_H
#define WIDGET_H

#include "tcpclient.h"
#include "tcpserver.h"
#include "chat.h"
#include "groupvoice.h"
#include <QWidget>
#include <QTcpServer>
#include <QTcpSocket>
#include <QUdpSocket>
#include <QTextCharFormat>
#include <QMouseEvent>

//enum MessageType
//{
//    Message,
//    NewParticipant,
//    ParticipantLeft,
//    FileName,
//    Refuse
//};

namespace Ui {
class Widget;
}

class Widget : public QWidget
{
    Q_OBJECT

public:
    Widget(QString name);
    ~Widget();
    QString getUserName();
    QString getMessage();

    chat* privatechat1;
    chat *privatechat;
    QMap<QString,chat*> chatMap;
    QMap<QString,chat*> chatMap1;

protected:
    //处理新用户加入
    void newParticipant(QString userName,QString localHostName,QString ipAddress);
    //根据不同消息类型启用不同处理流程
    //void changeEvent(QEvent *e);
    //处理用户离开
    void participantLeft(QString userName,QString localHostName,QString time);
    //处理用户关闭窗口，发送用户离开信息
    //void closeEvent(QCloseEvent *);
    //处理接收文件
    void hasPendingFile(QString userName, QString serverAddress, QString fileName);
    //事件过滤器，实现按下回车键发送信息功能
    bool eventFilter(QObject *target, QEvent *event);
    void sendMessage(MessageType type, QString serverAddress = "");

    //实现去除窗口标题栏后移动窗口
    void mousePressEvent(QMouseEvent *e);
    void mouseMoveEvent(QMouseEvent *e);
    void mouseReleaseEvent(QMouseEvent *e);
    void closeEvent(QCloseEvent *e);
private:
    Ui::Widget *ui;
    QUdpSocket *udpSocket;
    qint16 port;
    qint32 bb = 0;
    QString fileName;
    TcpServer *server;
    GroupVoice *newvoice;
    QString userName;
    //获得IP
    QString getIP();
    //颜色
    QColor color;
    //保存聊天记录
    bool saveFile(const QString& fileName);
    QPoint last;
    void setAppearance();
    void showxchat(QString myname, QString name, QString ip);

    QPalette pal;
    QAction *action1;
    QAction *action2;
    QAction *action3;
private slots:

    void processPendingDatagrams();
    void sentFileName(QString);
    void currentFormatChanged(const QTextCharFormat &format);

    void on_SendButton_clicked();
    void on_textcolor_clicked();
    void on_textUnderline_clicked(bool checked);
    void on_textbold_clicked(bool checked);
    void on_textitalic_clicked(bool checked);
    void on_clear_clicked();
    void on_fontComboBox_currentFontChanged(const QFont &f);
    void on_fontSizeComboBox_currentIndexChanged(const QString &arg1);
    void on_hideButton_clicked();
    void on_closeButton_clicked();
    void on_sendfile_clicked();
    void on_save_clicked();
    void on_gameButton_clicked();
    void on_textButton_clicked(bool checked);
    void on_tableWidget_doubleClicked(const QModelIndex &index);
    void on_imageButton_clicked();
    void on_voiceButton_clicked(bool checked);
    void on_webButton_clicked();

    void action1_slot();
    void action2_slot();
    void action3_slot();
};

#endif // WIDGET_H
