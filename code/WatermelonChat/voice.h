#ifndef VOICE_H
#define VOICE_H

#include <QMainWindow>
#include <QtNetwork/QUdpSocket>
#include <QAudio>
#include <QAudioFormat>
#include <QAudioInput>
#include <QAudioOutput>
#include <QIODevice>
namespace Ui {
class VoiceWindow;
}

class VoiceWindow : public QMainWindow
{
    Q_OBJECT

public:
    VoiceWindow(QString userip);
    ~VoiceWindow();

private:
    Ui::VoiceWindow *ui;
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

#endif // VOICE_H
