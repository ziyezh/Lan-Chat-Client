/********************************************************************************
** Form generated from reading UI file 'chat.ui'
**
** Created by: Qt User Interface Compiler version 5.6.1
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_CHAT_H
#define UI_CHAT_H

#include <QtCore/QVariant>
#include <QtWidgets/QAction>
#include <QtWidgets/QApplication>
#include <QtWidgets/QButtonGroup>
#include <QtWidgets/QComboBox>
#include <QtWidgets/QDialog>
#include <QtWidgets/QFontComboBox>
#include <QtWidgets/QHeaderView>
#include <QtWidgets/QLabel>
#include <QtWidgets/QLineEdit>
#include <QtWidgets/QPushButton>
#include <QtWidgets/QStackedWidget>
#include <QtWidgets/QTextEdit>
#include <QtWidgets/QToolButton>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_chat
{
public:
    QLabel *WatermelonChat;
    QLineEdit *label;
    QComboBox *fontSizeComboBox;
    QToolButton *textUnderline;
    QPushButton *textButton;
    QLabel *label_2;
    QFontComboBox *fontComboBox;
    QPushButton *imageButton;
    QPushButton *SendButton;
    QTextEdit *textEditWrite;
    QTextEdit *textEditRead;
    QPushButton *save;
    QToolButton *textcolor;
    QToolButton *clear;
    QPushButton *voiceButton;
    QToolButton *textitalic;
    QPushButton *sendfile;
    QToolButton *textbold;
    QPushButton *gameButton;
    QToolButton *hideButton;
    QToolButton *closeButton;
    QPushButton *webButton;
    QStackedWidget *stackedWidget;
    QWidget *page;
    QWidget *widget;
    QWidget *page_2;

    void setupUi(QDialog *chat)
    {
        if (chat->objectName().isEmpty())
            chat->setObjectName(QStringLiteral("chat"));
        chat->resize(800, 800);
        QIcon icon;
        icon.addFile(QStringLiteral(":/chat/image/icon/icon_title1.png"), QSize(), QIcon::Normal, QIcon::Off);
        chat->setWindowIcon(icon);
        WatermelonChat = new QLabel(chat);
        WatermelonChat->setObjectName(QStringLiteral("WatermelonChat"));
        WatermelonChat->setGeometry(QRect(20, 10, 431, 61));
        WatermelonChat->setStyleSheet(QStringLiteral("border-image: url(:/chat/image/title.png);"));
        label = new QLineEdit(chat);
        label->setObjectName(QStringLiteral("label"));
        label->setGeometry(QRect(10, 80, 251, 41));
        QFont font;
        font.setFamily(QString::fromUtf8("\344\270\255\345\233\275\345\274\217\346\211\213\345\206\231\351\243\216"));
        font.setPointSize(12);
        font.setBold(false);
        font.setWeight(50);
        label->setFont(font);
        label->setStyleSheet(QStringLiteral("border-image: url(:/chat/image/icon/background_peopleleft.png);"));
        fontSizeComboBox = new QComboBox(chat);
        fontSizeComboBox->setObjectName(QStringLiteral("fontSizeComboBox"));
        fontSizeComboBox->setGeometry(QRect(190, 520, 71, 31));
        QFont font1;
        font1.setPointSize(9);
        fontSizeComboBox->setFont(font1);
        fontSizeComboBox->setStyleSheet(QString::fromUtf8("QComboBox {\n"
"	background-color: rgb(255, 255, 255);\n"
"    border: 1px solid gray;\n"
"    border-radius: 3px;\n"
"    padding: 1px 2px 1px 2px;  /*\351\222\210\345\257\271\344\272\216\347\273\204\345\220\210\346\241\206\344\270\255\347\232\204\346\226\207\346\234\254\345\206\205\345\256\271*/\n"
"    /*min-width: 9em;   \347\273\204\345\220\210\346\241\206\347\232\204\346\234\200\345\260\217\345\256\275\345\272\246*/\n"
"}\n"
"QComboBox::drop-down {\n"
"    subcontrol-origin: padding;\n"
"    subcontrol-position: top right;\n"
"    width: 20px;\n"
"\n"
"    border-left-width: 1px;\n"
"    border-left-color: darkgray;\n"
"    border-left-style: solid; \n"
"    border-top-right-radius: 3px; \n"
"    border-bottom-right-radius: 3px;\n"
"}\n"
"QComboBox::down-arrow {\n"
"image: url(:/chat/image/icon/icon_menu.png);\n"
"}\n"
"QComboBox::drop-down:hover { background-color: rgb(50, 50, 50,255);}"));
        textUnderline = new QToolButton(chat);
        textUnderline->setObjectName(QStringLiteral("textUnderline"));
        textUnderline->setGeometry(QRect(350, 520, 31, 31));
        textUnderline->setStyleSheet(QLatin1String("QToolButton { background-color: rgb(50, 50, 50,0); border-radius: 3px; color: rgb(255, 255, 255); border-image: url(:/chat/image/icon/icon_underline.png);}\n"
"QToolButton:hover { background-color:rgba(172, 178, 148, 100)}"));
        textButton = new QPushButton(chat);
        textButton->setObjectName(QStringLiteral("textButton"));
        textButton->setGeometry(QRect(30, 730, 41, 41));
        textButton->setStyleSheet(QLatin1String("QPushButton { background-color: rgb(50, 50, 50,0); border-radius: 6px; color: rgb(255, 255, 255); border-image: url(:/chat/image/icon/icon_.png);}\n"
"QPushButton:hover { background-color:rgba(172, 178, 148, 100)}\n"
""));
        label_2 = new QLabel(chat);
        label_2->setObjectName(QStringLiteral("label_2"));
        label_2->setGeometry(QRect(10, 701, 461, 80));
        label_2->setStyleSheet(QLatin1String("border-bottom-left-radius:20px; \n"
"border-bottom-right-radius:20px; \n"
"background-color: rgb(255, 255, 255, 230);"));
        fontComboBox = new QFontComboBox(chat);
        fontComboBox->setObjectName(QStringLiteral("fontComboBox"));
        fontComboBox->setGeometry(QRect(20, 520, 161, 31));
        fontComboBox->setStyleSheet(QString::fromUtf8("QComboBox {\n"
"	background-color: rgb(255, 255, 255);\n"
"    border: 1px solid gray;\n"
"    border-radius: 3px;\n"
"    padding: 1px 2px 1px 2px;  /*\351\222\210\345\257\271\344\272\216\347\273\204\345\220\210\346\241\206\344\270\255\347\232\204\346\226\207\346\234\254\345\206\205\345\256\271*/\n"
"    /*min-width: 9em;   \347\273\204\345\220\210\346\241\206\347\232\204\346\234\200\345\260\217\345\256\275\345\272\246*/\n"
"}\n"
"QComboBox::drop-down {\n"
"    subcontrol-origin: padding;\n"
"    subcontrol-position: top right;\n"
"    width: 20px;\n"
"\n"
"    border-left-width: 1px;\n"
"    border-left-color: darkgray;\n"
"    border-left-style: solid; \n"
"    border-top-right-radius: 3px; \n"
"    border-bottom-right-radius: 3px;\n"
"}\n"
"QComboBox::down-arrow {\n"
"	image: url(:/chat/image/icon/icon_menu.png);\n"
"}\n"
"QComboBox::drop-down:hover { background-color: rgb(50, 50, 50,255);}"));
        imageButton = new QPushButton(chat);
        imageButton->setObjectName(QStringLiteral("imageButton"));
        imageButton->setGeometry(QRect(230, 730, 41, 41));
        imageButton->setStyleSheet(QLatin1String("QPushButton { background-color: rgb(50, 50, 50,0); border-radius: 6px; color: rgb(255, 255, 255); border-image: url(:/chat/image/icon/icon_pic.png);}\n"
"QPushButton:hover { background-color:rgba(172, 178, 148, 100)}"));
        SendButton = new QPushButton(chat);
        SendButton->setObjectName(QStringLiteral("SendButton"));
        SendButton->setGeometry(QRect(360, 740, 81, 31));
        SendButton->setMinimumSize(QSize(60, 25));
        SendButton->setMaximumSize(QSize(103, 41));
        SendButton->setStyleSheet(QLatin1String("QPushButton { background-color: rgb(172, 178, 148,200); border-radius: 3px; color: rgb(255, 255, 255); }\n"
" QPushButton:hover { background-color: rgb(172, 178, 148,255);}\n"
""));
        textEditWrite = new QTextEdit(chat);
        textEditWrite->setObjectName(QStringLiteral("textEditWrite"));
        textEditWrite->setGeometry(QRect(10, 560, 461, 141));
        textEditWrite->setStyleSheet(QLatin1String("border-top-left-radius:0px; \n"
"border-top-right-radius:0px;\n"
"background-color: rgb(255, 255, 255,230);\n"
"border-top:2px solid #e1e0e0;"));
        textEditRead = new QTextEdit(chat);
        textEditRead->setObjectName(QStringLiteral("textEditRead"));
        textEditRead->setGeometry(QRect(10, 130, 461, 431));
        textEditRead->setStyleSheet(QLatin1String("background-color: rgb(255, 255, 255, 230);\n"
"border-top-left-radius:20px; \n"
"border-top-right-radius:20px;"));
        textEditRead->setReadOnly(true);
        save = new QPushButton(chat);
        save->setObjectName(QStringLiteral("save"));
        save->setGeometry(QRect(300, 730, 41, 41));
        save->setStyleSheet(QLatin1String("QPushButton { background-color: rgb(50, 50, 50,0); border-radius: 6px; color: rgb(255, 255, 255); border-image: url(:/chat/image/icon/icon_download.png);}\n"
"QPushButton:hover { background-color:rgba(172, 178, 148, 100)}"));
        textcolor = new QToolButton(chat);
        textcolor->setObjectName(QStringLiteral("textcolor"));
        textcolor->setGeometry(QRect(430, 520, 31, 31));
        textcolor->setStyleSheet(QLatin1String("QToolButton { background-color: rgb(50, 50, 50,0); border-radius: 3px; color: rgb(255, 255, 255); border-image: url(:/chat/image/icon/icon_color.png);}\n"
"QToolButton:hover { background-color:rgba(172, 178, 148, 100)}"));
        clear = new QToolButton(chat);
        clear->setObjectName(QStringLiteral("clear"));
        clear->setGeometry(QRect(390, 520, 31, 31));
        clear->setStyleSheet(QLatin1String("QToolButton { background-color: rgb(50, 50, 50,0); border-radius: 3px; color: rgb(255, 255, 255);border-image: url(:/chat/image/icon/icon_del.png); }\n"
"QToolButton:hover { background-color:rgba(172, 178, 148, 100)}"));
        voiceButton = new QPushButton(chat);
        voiceButton->setObjectName(QStringLiteral("voiceButton"));
        voiceButton->setGeometry(QRect(90, 730, 31, 41));
        voiceButton->setStyleSheet(QLatin1String("QPushButton { background-color: rgb(50, 50, 50,0); border-radius: 6px; color: rgb(255, 255, 255); border-image: url(:/chat/image/icon/icon_novoice.png);}\n"
"QPushButton:hover { background-color:rgba(172, 178, 148, 100)}"));
        textitalic = new QToolButton(chat);
        textitalic->setObjectName(QStringLiteral("textitalic"));
        textitalic->setGeometry(QRect(310, 520, 31, 31));
        textitalic->setStyleSheet(QLatin1String("QToolButton { background-color: rgb(50, 50, 50,0); border-radius: 3px; color: rgb(255, 255, 255); border-image: url(:/chat/image/icon/icon_italic.png);}\n"
"QToolButton:hover { background-color:rgba(172, 178, 148, 100)}\n"
""));
        sendfile = new QPushButton(chat);
        sendfile->setObjectName(QStringLiteral("sendfile"));
        sendfile->setGeometry(QRect(150, 730, 41, 41));
        sendfile->setStyleSheet(QLatin1String("QPushButton { background-color: rgb(50, 50, 50,0); border-radius: 6px; color: rgb(255, 255, 255); border-image: url(:/chat/image/icon/icon_file.png);}\n"
"QPushButton:hover { background-color:rgba(172, 178, 148, 100)}"));
        textbold = new QToolButton(chat);
        textbold->setObjectName(QStringLiteral("textbold"));
        textbold->setGeometry(QRect(270, 520, 31, 31));
        textbold->setStyleSheet(QLatin1String("QToolButton { background-color: rgb(50, 50, 50,0); border-radius: 3px; color: rgb(255, 255, 255); border-image: url(:/chat/image/icon/icon_bold.png);}\n"
"QToolButton:hover { background-color:rgba(172, 178, 148, 100)}"));
        gameButton = new QPushButton(chat);
        gameButton->setObjectName(QStringLiteral("gameButton"));
        gameButton->setGeometry(QRect(490, 750, 41, 31));
        gameButton->setStyleSheet(QStringLiteral("border-image: url(:/chat/image/icon/icon_game.png);"));
        hideButton = new QToolButton(chat);
        hideButton->setObjectName(QStringLiteral("hideButton"));
        hideButton->setGeometry(QRect(720, 10, 30, 30));
        hideButton->setMinimumSize(QSize(30, 30));
        hideButton->setMaximumSize(QSize(30, 30));
        hideButton->setStyleSheet(QLatin1String("QToolButton { background-color: rgb(50, 50, 50,0); border-radius: 3px; color: rgb(255, 255, 255); }\n"
"QToolButton:hover { background-color: rgb(172, 178, 148);}"));
        QIcon icon1;
        icon1.addFile(QStringLiteral(":/chat/image/icon/icon_hide.png"), QSize(), QIcon::Normal, QIcon::Off);
        hideButton->setIcon(icon1);
        closeButton = new QToolButton(chat);
        closeButton->setObjectName(QStringLiteral("closeButton"));
        closeButton->setGeometry(QRect(760, 10, 30, 30));
        closeButton->setMinimumSize(QSize(30, 30));
        closeButton->setMaximumSize(QSize(30, 30));
        closeButton->setStyleSheet(QLatin1String("QToolButton { background-color: rgb(50, 50, 50,0); border-radius: 3px; color: rgb(255, 255, 255); }\n"
"QToolButton:hover { background-color: rgb(172, 178, 148);}"));
        QIcon icon2;
        icon2.addFile(QStringLiteral(":/chat/image/icon/icon_close.png"), QSize(), QIcon::Normal, QIcon::Off);
        closeButton->setIcon(icon2);
        webButton = new QPushButton(chat);
        webButton->setObjectName(QStringLiteral("webButton"));
        webButton->setGeometry(QRect(540, 750, 251, 31));
        webButton->setMinimumSize(QSize(60, 25));
        webButton->setMaximumSize(QSize(300, 50));
        QFont font2;
        font2.setBold(true);
        font2.setWeight(75);
        webButton->setFont(font2);
        webButton->setStyleSheet(QLatin1String("QPushButton { background-color: rgb(172, 178, 148,100); border-radius: 3px; color: rgb(255, 255, 255); }\n"
" QPushButton:hover { background-color: rgb(172, 178, 148,150);}\n"
""));
        stackedWidget = new QStackedWidget(chat);
        stackedWidget->setObjectName(QStringLiteral("stackedWidget"));
        stackedWidget->setGeometry(QRect(-1, 0, 801, 801));
        page = new QWidget();
        page->setObjectName(QStringLiteral("page"));
        widget = new QWidget(page);
        widget->setObjectName(QStringLiteral("widget"));
        widget->setGeometry(QRect(480, 50, 311, 651));
        widget->setStyleSheet(QStringLiteral("border-image: url(:/chat/image/chatBackground1.png);"));
        stackedWidget->addWidget(page);
        page_2 = new QWidget();
        page_2->setObjectName(QStringLiteral("page_2"));
        stackedWidget->addWidget(page_2);
        stackedWidget->raise();
        label_2->raise();
        textEditRead->raise();
        WatermelonChat->raise();
        label->raise();
        fontSizeComboBox->raise();
        textUnderline->raise();
        textButton->raise();
        fontComboBox->raise();
        imageButton->raise();
        SendButton->raise();
        textEditWrite->raise();
        save->raise();
        textcolor->raise();
        clear->raise();
        voiceButton->raise();
        textitalic->raise();
        sendfile->raise();
        textbold->raise();
        gameButton->raise();
        hideButton->raise();
        closeButton->raise();
        webButton->raise();

        retranslateUi(chat);

        QMetaObject::connectSlotsByName(chat);
    } // setupUi

    void retranslateUi(QDialog *chat)
    {
        chat->setWindowTitle(QApplication::translate("chat", "Dialog", 0));
        WatermelonChat->setText(QApplication::translate("chat", "<html><head/><body><p align=\"center\"><br/></p></body></html>", 0));
        label->setText(QString());
        fontSizeComboBox->clear();
        fontSizeComboBox->insertItems(0, QStringList()
         << QApplication::translate("chat", "9", 0)
         << QApplication::translate("chat", "10", 0)
         << QApplication::translate("chat", "11", 0)
         << QApplication::translate("chat", "12", 0)
         << QApplication::translate("chat", "13", 0)
         << QApplication::translate("chat", "14", 0)
         << QApplication::translate("chat", "15", 0)
         << QApplication::translate("chat", "16", 0)
         << QApplication::translate("chat", "17", 0)
         << QApplication::translate("chat", "18", 0)
         << QApplication::translate("chat", "19", 0)
         << QApplication::translate("chat", "20", 0)
        );
        fontSizeComboBox->setCurrentText(QApplication::translate("chat", "9", 0));
        textUnderline->setText(QString());
        textButton->setText(QString());
        label_2->setText(QString());
        fontComboBox->setCurrentText(QApplication::translate("chat", "\345\256\213\344\275\223", 0));
        imageButton->setText(QString());
        SendButton->setText(QApplication::translate("chat", "\345\217\221\351\200\201", 0));
        save->setText(QString());
        textcolor->setText(QString());
        clear->setText(QString());
        voiceButton->setText(QString());
        textitalic->setText(QString());
        sendfile->setText(QString());
        textbold->setText(QString());
        gameButton->setText(QString());
#ifndef QT_NO_TOOLTIP
        hideButton->setToolTip(QApplication::translate("chat", "\346\234\200\345\260\217\345\214\226", 0));
#endif // QT_NO_TOOLTIP
        hideButton->setText(QApplication::translate("chat", "...", 0));
#ifndef QT_NO_TOOLTIP
        closeButton->setToolTip(QApplication::translate("chat", "\345\205\263\351\227\255", 0));
#endif // QT_NO_TOOLTIP
        closeButton->setText(QApplication::translate("chat", "...", 0));
        webButton->setText(QApplication::translate("chat", "follow\346\210\221\344\273\254\347\232\204GitHub", 0));
    } // retranslateUi

};

namespace Ui {
    class chat: public Ui_chat {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_CHAT_H
