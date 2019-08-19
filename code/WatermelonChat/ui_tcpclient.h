/********************************************************************************
** Form generated from reading UI file 'tcpclient.ui'
**
** Created by: Qt User Interface Compiler version 5.6.1
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_TCPCLIENT_H
#define UI_TCPCLIENT_H

#include <QtCore/QVariant>
#include <QtWidgets/QAction>
#include <QtWidgets/QApplication>
#include <QtWidgets/QButtonGroup>
#include <QtWidgets/QHeaderView>
#include <QtWidgets/QLabel>
#include <QtWidgets/QProgressBar>
#include <QtWidgets/QPushButton>
#include <QtWidgets/QTextEdit>
#include <QtWidgets/QToolButton>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_TcpClient
{
public:
    QProgressBar *progressBar;
    QLabel *label;
    QPushButton *tcpClientCancleBtn;
    QLabel *label_2;
    QToolButton *tcpClientCloseBtn;
    QTextEdit *clientStatusLabel;

    void setupUi(QWidget *TcpClient)
    {
        if (TcpClient->objectName().isEmpty())
            TcpClient->setObjectName(QStringLiteral("TcpClient"));
        TcpClient->resize(550, 289);
        progressBar = new QProgressBar(TcpClient);
        progressBar->setObjectName(QStringLiteral("progressBar"));
        progressBar->setGeometry(QRect(80, 150, 431, 31));
        progressBar->setStyleSheet(QLatin1String("QProgressBar{\n"
"        border: none;\n"
"        text-align: center;\n"
"        background: rgb(210, 225, 240);\n"
"border-radius:10px;\n"
"\n"
"\n"
"}\n"
"QProgressBar::chunk {\n"
"        background: rgb(0, 160, 230);\n"
"border-radius:10px;\n"
"\n"
"}"));
        progressBar->setValue(24);
        label = new QLabel(TcpClient);
        label->setObjectName(QStringLiteral("label"));
        label->setGeometry(QRect(0, 0, 551, 131));
        label->setStyleSheet(QLatin1String("border-top-left-radius:6px; \n"
"border-top-right-radius:6px;\n"
"background-color: rgb(190, 195, 171);\n"
""));
        tcpClientCancleBtn = new QPushButton(TcpClient);
        tcpClientCancleBtn->setObjectName(QStringLiteral("tcpClientCancleBtn"));
        tcpClientCancleBtn->setGeometry(QRect(220, 200, 101, 41));
        tcpClientCancleBtn->setStyleSheet(QLatin1String("QPushButton { background-color: rgb(172, 178, 148,200); border-radius: 3px; color: rgb(255, 255, 255); }\n"
" QPushButton:hover { background-color: rgb(172, 178, 148,255);}"));
        label_2 = new QLabel(TcpClient);
        label_2->setObjectName(QStringLiteral("label_2"));
        label_2->setGeometry(QRect(0, 130, 551, 161));
        label_2->setStyleSheet(QLatin1String("border-button-left-radius:6px; \n"
"border-button-right-radius:6px;\n"
"background-color: rgb(255, 255, 255);\n"
"\n"
""));
        tcpClientCloseBtn = new QToolButton(TcpClient);
        tcpClientCloseBtn->setObjectName(QStringLiteral("tcpClientCloseBtn"));
        tcpClientCloseBtn->setGeometry(QRect(520, 0, 30, 30));
        tcpClientCloseBtn->setMinimumSize(QSize(30, 30));
        tcpClientCloseBtn->setMaximumSize(QSize(30, 30));
        tcpClientCloseBtn->setStyleSheet(QLatin1String("QToolButton { background-color: rgb(50, 50, 50,0); border-radius: 3px; color: rgb(255, 255, 255); }\n"
"QToolButton:hover { background-color: rgb(172, 178, 148);}"));
        QIcon icon;
        icon.addFile(QStringLiteral(":/chat/image/icon/icon_close.png"), QSize(), QIcon::Normal, QIcon::Off);
        tcpClientCloseBtn->setIcon(icon);
        clientStatusLabel = new QTextEdit(TcpClient);
        clientStatusLabel->setObjectName(QStringLiteral("clientStatusLabel"));
        clientStatusLabel->setGeometry(QRect(100, 20, 341, 101));
        QFont font;
        font.setFamily(QString::fromUtf8("\346\245\267\344\275\223"));
        font.setPointSize(12);
        clientStatusLabel->setFont(font);
        clientStatusLabel->setStyleSheet(QLatin1String("background-color: rgba(255, 255, 255, 0);\n"
"border: none;"));
        clientStatusLabel->setVerticalScrollBarPolicy(Qt::ScrollBarAlwaysOff);
        clientStatusLabel->setHorizontalScrollBarPolicy(Qt::ScrollBarAlwaysOff);
        label_2->raise();
        tcpClientCancleBtn->raise();
        label->raise();
        tcpClientCloseBtn->raise();
        progressBar->raise();
        clientStatusLabel->raise();

        retranslateUi(TcpClient);

        QMetaObject::connectSlotsByName(TcpClient);
    } // setupUi

    void retranslateUi(QWidget *TcpClient)
    {
        TcpClient->setWindowTitle(QApplication::translate("TcpClient", "\346\216\245\346\224\266\346\226\207\344\273\266", 0));
        label->setText(QString());
        tcpClientCancleBtn->setText(QApplication::translate("TcpClient", "\345\217\226\346\266\210", 0));
        label_2->setText(QString());
#ifndef QT_NO_TOOLTIP
        tcpClientCloseBtn->setToolTip(QApplication::translate("TcpClient", "\345\205\263\351\227\255", 0));
#endif // QT_NO_TOOLTIP
        tcpClientCloseBtn->setText(QApplication::translate("TcpClient", "...", 0));
    } // retranslateUi

};

namespace Ui {
    class TcpClient: public Ui_TcpClient {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_TCPCLIENT_H
