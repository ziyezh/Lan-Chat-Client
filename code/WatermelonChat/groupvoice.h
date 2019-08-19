#ifndef GROUPVOICE_H
#define GROUPVOICE_H

#include <QMainWindow>
#include <QtNetwork/QUdpSocket>
#include <QAudio>
#include <QAudioFormat>
#include <QAudioInput>
#include <QAudioOutput>
#include <QIODevice>

namespace Ui {
class GroupVoice;
}

class GroupVoice : public QMainWindow
{
    Q_OBJECT

public:
    explicit GroupVoice(QWidget *parent = 0);
    ~GroupVoice();

private:
    Ui::GroupVoice *ui;
    QUdpSocket *udpSocket;//用于音频信号的发送
    QString ip;
    QAudioInput *input;
    QAudioOutput *output;
    QIODevice *inputDevice;
    QIODevice *outputDevice;
    static int i;
    QString getIP();

    struct video
    {
        char audiodata[1024];
        int lens;
    };

private slots:
    void onReadyRead();
    void ReadyReadSlot();

};

#endif // GROUPVOICE_H
