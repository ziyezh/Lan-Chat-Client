/********************************************************************************
** Form generated from reading UI file 'client.ui'
**
** Created by: Qt User Interface Compiler version 5.6.1
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_CLIENT_H
#define UI_CLIENT_H

#include <QtCore/QVariant>
#include <QtWidgets/QAction>
#include <QtWidgets/QApplication>
#include <QtWidgets/QButtonGroup>
#include <QtWidgets/QHeaderView>
#include <QtWidgets/QLabel>
#include <QtWidgets/QLineEdit>
#include <QtWidgets/QPushButton>
#include <QtWidgets/QToolButton>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_Client
{
public:
    QLabel *label_2;
    QLineEdit *passwardLineEdit;
    QLabel *label;
    QLineEdit *userLineEdit;
    QToolButton *closeButton;
    QToolButton *hideButton;
    QPushButton *signBtn;
    QPushButton *sendBtn;

    void setupUi(QWidget *Client)
    {
        if (Client->objectName().isEmpty())
            Client->setObjectName(QStringLiteral("Client"));
        Client->resize(985, 685);
        QIcon icon;
        icon.addFile(QStringLiteral(":/chat/image/icon/icon_clientTitle.png"), QSize(), QIcon::Normal, QIcon::Off);
        Client->setWindowIcon(icon);
        label_2 = new QLabel(Client);
        label_2->setObjectName(QStringLiteral("label_2"));
        label_2->setGeometry(QRect(346, 337, 111, 41));
        QFont font;
        font.setFamily(QString::fromUtf8("\346\245\267\344\275\223"));
        font.setPointSize(14);
        font.setBold(true);
        font.setWeight(75);
        label_2->setFont(font);
        passwardLineEdit = new QLineEdit(Client);
        passwardLineEdit->setObjectName(QStringLiteral("passwardLineEdit"));
        passwardLineEdit->setGeometry(QRect(460, 338, 281, 41));
        QFont font1;
        font1.setPointSize(12);
        passwardLineEdit->setFont(font1);
        passwardLineEdit->setStyleSheet(QLatin1String("border: none;\n"
"background-color: rgba(255, 255, 255, 0);"));
        label = new QLabel(Client);
        label->setObjectName(QStringLiteral("label"));
        label->setGeometry(QRect(341, 259, 111, 41));
        label->setFont(font);
        userLineEdit = new QLineEdit(Client);
        userLineEdit->setObjectName(QStringLiteral("userLineEdit"));
        userLineEdit->setGeometry(QRect(460, 258, 291, 41));
        userLineEdit->setFont(font1);
        userLineEdit->setStyleSheet(QLatin1String("border: none;\n"
"background-color: rgba(255, 255, 255, 0);"));
        closeButton = new QToolButton(Client);
        closeButton->setObjectName(QStringLiteral("closeButton"));
        closeButton->setGeometry(QRect(650, 210, 30, 30));
        closeButton->setMinimumSize(QSize(30, 30));
        closeButton->setMaximumSize(QSize(30, 30));
        closeButton->setStyleSheet(QLatin1String("QToolButton { background-color: rgb(150, 150, 150, 80); border-radius: 3px; color: rgb(255, 255, 255); }\n"
"QToolButton:hover { background-color: rgb(172, 178, 148);}"));
        QIcon icon1;
        icon1.addFile(QStringLiteral(":/chat/image/icon/icon_close.png"), QSize(), QIcon::Normal, QIcon::Off);
        closeButton->setIcon(icon1);
        hideButton = new QToolButton(Client);
        hideButton->setObjectName(QStringLiteral("hideButton"));
        hideButton->setGeometry(QRect(610, 210, 30, 30));
        hideButton->setMinimumSize(QSize(30, 30));
        hideButton->setMaximumSize(QSize(30, 30));
        hideButton->setStyleSheet(QLatin1String("QToolButton { background-color: rgb(150, 150, 150, 80); border-radius: 3px; color: rgb(255, 255, 255); }\n"
"QToolButton:hover { background-color: rgb(172, 178, 148);}"));
        QIcon icon2;
        icon2.addFile(QStringLiteral(":/chat/image/icon/icon_hide.png"), QSize(), QIcon::Normal, QIcon::Off);
        hideButton->setIcon(icon2);
        signBtn = new QPushButton(Client);
        signBtn->setObjectName(QStringLiteral("signBtn"));
        signBtn->setGeometry(QRect(410, 420, 91, 41));
        signBtn->setMinimumSize(QSize(60, 25));
        signBtn->setMaximumSize(QSize(103, 41));
        QFont font2;
        font2.setFamily(QString::fromUtf8("\346\245\267\344\275\223"));
        font2.setPointSize(12);
        signBtn->setFont(font2);
        signBtn->setStyleSheet(QLatin1String("QPushButton { background-color: rgb(172, 178, 148,200); border-radius: 3px; color: rgb(255, 255, 255); }\n"
" QPushButton:hover { background-color: rgb(172, 178, 148,255);}\n"
""));
        sendBtn = new QPushButton(Client);
        sendBtn->setObjectName(QStringLiteral("sendBtn"));
        sendBtn->setGeometry(QRect(590, 420, 91, 41));
        sendBtn->setMinimumSize(QSize(60, 25));
        sendBtn->setMaximumSize(QSize(103, 41));
        sendBtn->setFont(font2);
        sendBtn->setStyleSheet(QLatin1String("QPushButton { background-color: rgb(172, 178, 148,200); border-radius: 3px; color: rgb(255, 255, 255); }\n"
" QPushButton:hover { background-color: rgb(172, 178, 148,255);}\n"
""));

        retranslateUi(Client);

        QMetaObject::connectSlotsByName(Client);
    } // setupUi

    void retranslateUi(QWidget *Client)
    {
        Client->setWindowTitle(QApplication::translate("Client", "Form", 0));
        label_2->setText(QApplication::translate("Client", "<html><head/><body><p><span style=\" color:#b6b688;\">\345\257\206 \347\240\201\357\274\232</span></p></body></html>", 0));
        label->setText(QApplication::translate("Client", "<html><head/><body><p><span style=\" color:#b6b688;\">\347\224\250\346\210\267\345\220\215\357\274\232</span></p></body></html>", 0));
#ifndef QT_NO_TOOLTIP
        closeButton->setToolTip(QApplication::translate("Client", "\345\205\263\351\227\255", 0));
#endif // QT_NO_TOOLTIP
        closeButton->setText(QApplication::translate("Client", "...", 0));
#ifndef QT_NO_TOOLTIP
        hideButton->setToolTip(QApplication::translate("Client", "\346\234\200\345\260\217\345\214\226", 0));
#endif // QT_NO_TOOLTIP
        hideButton->setText(QApplication::translate("Client", "...", 0));
        signBtn->setText(QApplication::translate("Client", "\346\263\250\345\206\214", 0));
        sendBtn->setText(QApplication::translate("Client", "\347\231\273\351\231\206", 0));
    } // retranslateUi

};

namespace Ui {
    class Client: public Ui_Client {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_CLIENT_H
