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
#include <QtWidgets/QLineEdit>
#include <QtWidgets/QMainWindow>
#include <QtWidgets/QPushButton>
#include <QtWidgets/QToolButton>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_TcpServer
{
public:
    QWidget *centralwidget;
    QToolButton *closeButton;
    QToolButton *hideButton;
    QPushButton *startBtn;
    QPushButton *webButton;
    QLineEdit *label;

    void setupUi(QMainWindow *TcpServer)
    {
        if (TcpServer->objectName().isEmpty())
            TcpServer->setObjectName(QStringLiteral("TcpServer"));
        TcpServer->resize(708, 685);
        QIcon icon;
        icon.addFile(QStringLiteral(":/image/serverBackground.png"), QSize(), QIcon::Normal, QIcon::Off);
        TcpServer->setWindowIcon(icon);
        centralwidget = new QWidget(TcpServer);
        centralwidget->setObjectName(QStringLiteral("centralwidget"));
        closeButton = new QToolButton(centralwidget);
        closeButton->setObjectName(QStringLiteral("closeButton"));
        closeButton->setGeometry(QRect(550, 90, 30, 30));
        closeButton->setMinimumSize(QSize(30, 30));
        closeButton->setMaximumSize(QSize(30, 30));
        closeButton->setStyleSheet(QLatin1String("QToolButton { background-color: rgb(150, 150, 150,200); border-radius: 3px; color: rgb(255, 255, 255); }\n"
"QToolButton:hover { background-color: rgb(172, 178, 148);}"));
        QIcon icon1;
        icon1.addFile(QStringLiteral(":/image/icon_close.png"), QSize(), QIcon::Normal, QIcon::Off);
        closeButton->setIcon(icon1);
        hideButton = new QToolButton(centralwidget);
        hideButton->setObjectName(QStringLiteral("hideButton"));
        hideButton->setGeometry(QRect(510, 90, 30, 30));
        hideButton->setMinimumSize(QSize(30, 30));
        hideButton->setMaximumSize(QSize(30, 30));
        hideButton->setStyleSheet(QLatin1String("QToolButton { background-color: rgb(150, 150, 150,200); border-radius: 3px; color: rgb(255, 255, 255); }\n"
"QToolButton:hover { background-color: rgb(172, 178, 148);}"));
        QIcon icon2;
        icon2.addFile(QStringLiteral(":/image/icon_hide.png"), QSize(), QIcon::Normal, QIcon::Off);
        hideButton->setIcon(icon2);
        startBtn = new QPushButton(centralwidget);
        startBtn->setObjectName(QStringLiteral("startBtn"));
        startBtn->setGeometry(QRect(210, 230, 271, 81));
        startBtn->setMinimumSize(QSize(60, 25));
        startBtn->setMaximumSize(QSize(400, 400));
        QFont font;
        font.setFamily(QString::fromUtf8("\345\215\216\346\226\207\350\241\214\346\245\267"));
        font.setPointSize(13);
        startBtn->setFont(font);
        startBtn->setStyleSheet(QLatin1String("QPushButton { background-color: rgb(172, 178, 148,255); border-radius: 3px;}\n"
" QPushButton:hover { background-color: rgb(152, 158, 128,255);}\n"
""));
        webButton = new QPushButton(centralwidget);
        webButton->setObjectName(QStringLiteral("webButton"));
        webButton->setGeometry(QRect(210, 410, 271, 31));
        webButton->setMinimumSize(QSize(60, 25));
        webButton->setMaximumSize(QSize(300, 50));
        QFont font1;
        font1.setBold(true);
        font1.setWeight(75);
        webButton->setFont(font1);
        webButton->setStyleSheet(QLatin1String("QPushButton { background-color: rgb(172, 178, 148,100); border-radius: 3px; color: rgb(255, 255, 255); }\n"
" QPushButton:hover { background-color: rgb(172, 178, 148,150);}\n"
""));
        label = new QLineEdit(centralwidget);
        label->setObjectName(QStringLiteral("label"));
        label->setGeometry(QRect(210, 320, 271, 61));
        QFont font2;
        font2.setFamily(QString::fromUtf8("\344\270\255\345\233\275\345\274\217\346\211\213\345\206\231\351\243\216"));
        font2.setPointSize(12);
        font2.setBold(false);
        font2.setWeight(50);
        label->setFont(font2);
        label->setCursor(QCursor(Qt::ArrowCursor));
        label->setStyleSheet(QStringLiteral("background-color: rgb(172, 178, 148,200); border-radius: 3px;"));
        label->setReadOnly(true);
        TcpServer->setCentralWidget(centralwidget);

        retranslateUi(TcpServer);

        QMetaObject::connectSlotsByName(TcpServer);
    } // setupUi

    void retranslateUi(QMainWindow *TcpServer)
    {
        TcpServer->setWindowTitle(QApplication::translate("TcpServer", "MainWindow", 0));
#ifndef QT_NO_TOOLTIP
        closeButton->setToolTip(QApplication::translate("TcpServer", "\345\205\263\351\227\255", 0));
#endif // QT_NO_TOOLTIP
        closeButton->setText(QApplication::translate("TcpServer", "...", 0));
#ifndef QT_NO_TOOLTIP
        hideButton->setToolTip(QApplication::translate("TcpServer", "\346\234\200\345\260\217\345\214\226", 0));
#endif // QT_NO_TOOLTIP
        hideButton->setText(QApplication::translate("TcpServer", "...", 0));
        startBtn->setText(QApplication::translate("TcpServer", "\345\274\200\345\220\257\346\234\215\345\212\241\345\231\250", 0));
        webButton->setText(QApplication::translate("TcpServer", "follow\346\210\221\344\273\254\347\232\204GitHub", 0));
        label->setText(QApplication::translate("TcpServer", "  IP:", 0));
    } // retranslateUi

};

namespace Ui {
    class TcpServer: public Ui_TcpServer {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_TCPSERVER_H
