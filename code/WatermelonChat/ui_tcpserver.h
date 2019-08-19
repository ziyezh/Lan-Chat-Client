/********************************************************************************
** Form generated from reading UI file 'tcpserver.ui'
**
** Created by: Qt User Interface Compiler version 5.6.1
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_TCPSERVER_H
#define UI_TCPSERVER_H

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

class Ui_TcpServer
{
public:
    QProgressBar *progressBar;
    QPushButton *serverOpenBtn;
    QPushButton *serverSendBtn;
    QLabel *label;
    QLabel *label_2;
    QToolButton *serverCloseBtn;
    QTextEdit *serverStatusLabel;

    void setupUi(QWidget *TcpServer)
    {
        if (TcpServer->objectName().isEmpty())
            TcpServer->setObjectName(QStringLiteral("TcpServer"));
        TcpServer->resize(550, 285);
        QIcon icon;
        icon.addFile(QStringLiteral(":/chat/image/icon/icon_file.png"), QSize(), QIcon::Normal, QIcon::Off);
        TcpServer->setWindowIcon(icon);
        TcpServer->setStyleSheet(QStringLiteral(""));
        progressBar = new QProgressBar(TcpServer);
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
        serverOpenBtn = new QPushButton(TcpServer);
        serverOpenBtn->setObjectName(QStringLiteral("serverOpenBtn"));
        serverOpenBtn->setGeometry(QRect(110, 200, 101, 41));
        serverOpenBtn->setStyleSheet(QLatin1String("QPushButton { background-color: rgb(172, 178, 148,200); border-radius: 3px; color: rgb(255, 255, 255); }\n"
" QPushButton:hover { background-color: rgb(172, 178, 148,255);}"));
        serverSendBtn = new QPushButton(TcpServer);
        serverSendBtn->setObjectName(QStringLiteral("serverSendBtn"));
        serverSendBtn->setGeometry(QRect(350, 200, 111, 41));
        serverSendBtn->setStyleSheet(QLatin1String("QPushButton { background-color: rgb(172, 178, 148,200); border-radius: 3px; color: rgb(255, 255, 255); }\n"
" QPushButton:hover { background-color: rgb(172, 178, 148,255);}"));
        label = new QLabel(TcpServer);
        label->setObjectName(QStringLiteral("label"));
        label->setGeometry(QRect(0, 0, 551, 131));
        label->setStyleSheet(QLatin1String("border-top-left-radius:6px; \n"
"border-top-right-radius:6px;\n"
"background-color: rgb(190, 195, 171);\n"
""));
        label_2 = new QLabel(TcpServer);
        label_2->setObjectName(QStringLiteral("label_2"));
        label_2->setGeometry(QRect(0, 130, 551, 161));
        label_2->setStyleSheet(QLatin1String("border-button-left-radius:6px; \n"
"border-button-right-radius:6px;\n"
"background-color: rgb(255, 255, 255);\n"
"\n"
""));
        serverCloseBtn = new QToolButton(TcpServer);
        serverCloseBtn->setObjectName(QStringLiteral("serverCloseBtn"));
        serverCloseBtn->setGeometry(QRect(520, 0, 30, 30));
        serverCloseBtn->setMinimumSize(QSize(30, 30));
        serverCloseBtn->setMaximumSize(QSize(30, 30));
        serverCloseBtn->setStyleSheet(QLatin1String("QToolButton { background-color: rgb(50, 50, 50,0); border-radius: 3px; color: rgb(255, 255, 255); }\n"
"QToolButton:hover { background-color: rgb(172, 178, 148);}"));
        QIcon icon1;
        icon1.addFile(QStringLiteral(":/chat/image/icon/icon_close.png"), QSize(), QIcon::Normal, QIcon::Off);
        serverCloseBtn->setIcon(icon1);
        serverStatusLabel = new QTextEdit(TcpServer);
        serverStatusLabel->setObjectName(QStringLiteral("serverStatusLabel"));
        serverStatusLabel->setGeometry(QRect(150, 20, 341, 101));
        QFont font;
        font.setFamily(QString::fromUtf8("\346\245\267\344\275\223"));
        font.setPointSize(12);
        serverStatusLabel->setFont(font);
        serverStatusLabel->setStyleSheet(QLatin1String("background-color: rgba(255, 255, 255, 0);\n"
"border: none;"));
        serverStatusLabel->setVerticalScrollBarPolicy(Qt::ScrollBarAlwaysOff);
        serverStatusLabel->setHorizontalScrollBarPolicy(Qt::ScrollBarAlwaysOff);
        label_2->raise();
        label->raise();
        progressBar->raise();
        serverOpenBtn->raise();
        serverSendBtn->raise();
        serverCloseBtn->raise();
        serverStatusLabel->raise();

        retranslateUi(TcpServer);

        QMetaObject::connectSlotsByName(TcpServer);
    } // setupUi

    void retranslateUi(QWidget *TcpServer)
    {
        TcpServer->setWindowTitle(QApplication::translate("TcpServer", "\345\217\221\351\200\201\346\226\207\344\273\266", 0));
        serverOpenBtn->setText(QApplication::translate("TcpServer", "\346\211\223\345\274\200", 0));
        serverSendBtn->setText(QApplication::translate("TcpServer", "\345\217\221\351\200\201", 0));
        label->setText(QString());
        label_2->setText(QString());
#ifndef QT_NO_TOOLTIP
        serverCloseBtn->setToolTip(QApplication::translate("TcpServer", "\345\205\263\351\227\255", 0));
#endif // QT_NO_TOOLTIP
        serverCloseBtn->setText(QApplication::translate("TcpServer", "...", 0));
    } // retranslateUi

};

namespace Ui {
    class TcpServer: public Ui_TcpServer {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_TCPSERVER_H
