/********************************************************************************
** Form generated from reading UI file 'widget.ui'
**
** Created by: Qt User Interface Compiler version 5.6.1
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_WIDGET_H
#define UI_WIDGET_H

#include <QtCore/QVariant>
#include <QtWidgets/QAction>
#include <QtWidgets/QApplication>
#include <QtWidgets/QButtonGroup>
#include <QtWidgets/QComboBox>
#include <QtWidgets/QFontComboBox>
#include <QtWidgets/QHeaderView>
#include <QtWidgets/QLabel>
#include <QtWidgets/QLineEdit>
#include <QtWidgets/QPushButton>
#include <QtWidgets/QStackedWidget>
#include <QtWidgets/QTableWidget>
#include <QtWidgets/QTextEdit>
#include <QtWidgets/QToolButton>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_Widget
{
public:
    QTextEdit *textEditRead;
    QTableWidget *tableWidget;
    QLineEdit *userNumber;
    QPushButton *voiceButton;
    QPushButton *textButton;
    QPushButton *sendfile;
    QPushButton *imageButton;
    QPushButton *save;
    QLabel *WatermelonChat;
    QComboBox *fontSizeComboBox;
    QToolButton *textbold;
    QToolButton *textitalic;
    QToolButton *textUnderline;
    QToolButton *textcolor;
    QToolButton *clear;
    QFontComboBox *fontComboBox;
    QPushButton *gameButton;
    QToolButton *closeButton;
    QToolButton *hideButton;
    QPushButton *SendButton;
    QLabel *label;
    QStackedWidget *stackedWidget;
    QWidget *page;
    QPushButton *webButton;
    QPushButton *changeButton;
    QTextEdit *textEditWrite;
    QWidget *page_2;

    void setupUi(QWidget *Widget)
    {
        if (Widget->objectName().isEmpty())
            Widget->setObjectName(QStringLiteral("Widget"));
        Widget->resize(1000, 800);
        Widget->setMinimumSize(QSize(1000, 800));
        Widget->setMaximumSize(QSize(1920, 1080));
        Widget->setBaseSize(QSize(1000, 1000));
        QIcon icon;
        icon.addFile(QStringLiteral(":/chat/image/icon/icon_title.png"), QSize(), QIcon::Normal, QIcon::Off);
        Widget->setWindowIcon(icon);
        Widget->setAutoFillBackground(false);
        Widget->setStyleSheet(QStringLiteral(""));
        textEditRead = new QTextEdit(Widget);
        textEditRead->setObjectName(QStringLiteral("textEditRead"));
        textEditRead->setGeometry(QRect(40, 100, 461, 431));
        textEditRead->setStyleSheet(QLatin1String("background-color: rgb(255, 255, 255, 230);\n"
"border-top-left-radius:20px; \n"
"border-top-right-radius:20px;"));
        textEditRead->setReadOnly(true);
        tableWidget = new QTableWidget(Widget);
        tableWidget->setObjectName(QStringLiteral("tableWidget"));
        tableWidget->setGeometry(QRect(550, 100, 381, 611));
        tableWidget->setStyleSheet(QLatin1String("background-color: rgb(255, 255, 255, 230);\n"
"border-radius: 20px;"));
        tableWidget->setShowGrid(false);
        tableWidget->verticalHeader()->setVisible(false);
        userNumber = new QLineEdit(Widget);
        userNumber->setObjectName(QStringLiteral("userNumber"));
        userNumber->setGeometry(QRect(550, 720, 151, 31));
        userNumber->setStyleSheet(QStringLiteral("border-image: url(:/chat/image/icon/background_peopleleft.png);"));
        voiceButton = new QPushButton(Widget);
        voiceButton->setObjectName(QStringLiteral("voiceButton"));
        voiceButton->setGeometry(QRect(130, 700, 31, 41));
        voiceButton->setStyleSheet(QLatin1String("QPushButton { background-color: rgb(50, 50, 50,0); border-radius: 6px; color: rgb(255, 255, 255); border-image: url(:/chat/image/icon/icon_novoice.png);}\n"
"QPushButton:hover { background-color:rgba(172, 178, 148, 100)}"));
        textButton = new QPushButton(Widget);
        textButton->setObjectName(QStringLiteral("textButton"));
        textButton->setGeometry(QRect(70, 700, 41, 41));
        textButton->setStyleSheet(QLatin1String("QPushButton { background-color: rgb(50, 50, 50,0); border-radius: 6px; color: rgb(255, 255, 255); border-image: url(:/chat/image/icon/icon_.png);}\n"
"QPushButton:hover { background-color:rgba(172, 178, 148, 100)}\n"
""));
        sendfile = new QPushButton(Widget);
        sendfile->setObjectName(QStringLiteral("sendfile"));
        sendfile->setGeometry(QRect(190, 700, 41, 41));
        sendfile->setStyleSheet(QLatin1String("QPushButton { background-color: rgb(50, 50, 50,0); border-radius: 6px; color: rgb(255, 255, 255); border-image: url(:/chat/image/icon/icon_file.png);}\n"
"QPushButton:hover { background-color:rgba(172, 178, 148, 100)}"));
        imageButton = new QPushButton(Widget);
        imageButton->setObjectName(QStringLiteral("imageButton"));
        imageButton->setGeometry(QRect(260, 700, 41, 41));
        imageButton->setStyleSheet(QLatin1String("QPushButton { background-color: rgb(50, 50, 50,0); border-radius: 6px; color: rgb(255, 255, 255); border-image: url(:/chat/image/icon/icon_pic.png);}\n"
"QPushButton:hover { background-color:rgba(172, 178, 148, 100)}"));
        save = new QPushButton(Widget);
        save->setObjectName(QStringLiteral("save"));
        save->setGeometry(QRect(330, 700, 41, 41));
        save->setStyleSheet(QLatin1String("QPushButton { background-color: rgb(50, 50, 50,0); border-radius: 6px; color: rgb(255, 255, 255); border-image: url(:/chat/image/icon/icon_download.png);}\n"
"QPushButton:hover { background-color:rgba(172, 178, 148, 100)}"));
        WatermelonChat = new QLabel(Widget);
        WatermelonChat->setObjectName(QStringLiteral("WatermelonChat"));
        WatermelonChat->setGeometry(QRect(40, 20, 431, 61));
        WatermelonChat->setStyleSheet(QStringLiteral("border-image: url(:/chat/image/title.png);"));
        fontSizeComboBox = new QComboBox(Widget);
        fontSizeComboBox->setObjectName(QStringLiteral("fontSizeComboBox"));
        fontSizeComboBox->setGeometry(QRect(220, 490, 71, 31));
        QFont font;
        font.setPointSize(9);
        fontSizeComboBox->setFont(font);
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
        textbold = new QToolButton(Widget);
        textbold->setObjectName(QStringLiteral("textbold"));
        textbold->setGeometry(QRect(300, 490, 31, 31));
        textbold->setStyleSheet(QLatin1String("QToolButton { background-color: rgb(50, 50, 50,0); border-radius: 3px;border-image: url(:/chat/image/icon/icon_bold.png);}\n"
"QToolButton:hover { background-color:rgba(172, 178, 148, 100)}"));
        textitalic = new QToolButton(Widget);
        textitalic->setObjectName(QStringLiteral("textitalic"));
        textitalic->setGeometry(QRect(340, 490, 31, 31));
        textitalic->setStyleSheet(QLatin1String("QToolButton { background-color: rgb(50, 50, 50,0); border-radius: 3px; color: rgb(255, 255, 255); border-image: url(:/chat/image/icon/icon_italic.png);}\n"
"QToolButton:hover { background-color:rgba(172, 178, 148, 100)}\n"
""));
        textUnderline = new QToolButton(Widget);
        textUnderline->setObjectName(QStringLiteral("textUnderline"));
        textUnderline->setGeometry(QRect(380, 490, 31, 31));
        textUnderline->setStyleSheet(QLatin1String("QToolButton { background-color: rgb(50, 50, 50,0); border-radius: 3px; color: rgb(255, 255, 255); border-image: url(:/chat/image/icon/icon_underline.png);}\n"
"QToolButton:hover { background-color:rgba(172, 178, 148, 100)}"));
        textcolor = new QToolButton(Widget);
        textcolor->setObjectName(QStringLiteral("textcolor"));
        textcolor->setGeometry(QRect(460, 490, 31, 31));
        textcolor->setStyleSheet(QLatin1String("QToolButton { background-color: rgb(50, 50, 50,0); border-radius: 3px; color: rgb(255, 255, 255); border-image: url(:/chat/image/icon/icon_color.png);}\n"
"QToolButton:hover { background-color:rgba(172, 178, 148, 100)}"));
        clear = new QToolButton(Widget);
        clear->setObjectName(QStringLiteral("clear"));
        clear->setGeometry(QRect(420, 490, 31, 31));
        clear->setStyleSheet(QLatin1String("QToolButton { background-color: rgb(50, 50, 50,0); border-radius: 3px; color: rgb(255, 255, 255);border-image: url(:/chat/image/icon/icon_del.png); }\n"
"QToolButton:hover { background-color:rgba(172, 178, 148, 100)}"));
        fontComboBox = new QFontComboBox(Widget);
        fontComboBox->setObjectName(QStringLiteral("fontComboBox"));
        fontComboBox->setGeometry(QRect(50, 490, 161, 31));
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
        gameButton = new QPushButton(Widget);
        gameButton->setObjectName(QStringLiteral("gameButton"));
        gameButton->setGeometry(QRect(720, 720, 41, 31));
        gameButton->setStyleSheet(QStringLiteral("border-image: url(:/chat/image/icon/icon_game.png);"));
        closeButton = new QToolButton(Widget);
        closeButton->setObjectName(QStringLiteral("closeButton"));
        closeButton->setGeometry(QRect(960, 10, 30, 30));
        closeButton->setMinimumSize(QSize(30, 30));
        closeButton->setMaximumSize(QSize(30, 30));
        closeButton->setStyleSheet(QLatin1String("QToolButton { background-color: rgb(50, 50, 50,0); border-radius: 3px; color: rgb(255, 255, 255); }\n"
"QToolButton:hover { background-color: rgb(172, 178, 148);}"));
        QIcon icon1;
        icon1.addFile(QStringLiteral(":/chat/image/icon/icon_close.png"), QSize(), QIcon::Normal, QIcon::Off);
        closeButton->setIcon(icon1);
        hideButton = new QToolButton(Widget);
        hideButton->setObjectName(QStringLiteral("hideButton"));
        hideButton->setGeometry(QRect(920, 10, 30, 30));
        hideButton->setMinimumSize(QSize(30, 30));
        hideButton->setMaximumSize(QSize(30, 30));
        hideButton->setStyleSheet(QLatin1String("QToolButton { background-color: rgb(50, 50, 50,0); border-radius: 3px; color: rgb(255, 255, 255); }\n"
"QToolButton:hover { background-color: rgb(172, 178, 148);}"));
        QIcon icon2;
        icon2.addFile(QStringLiteral(":/chat/image/icon/icon_hide.png"), QSize(), QIcon::Normal, QIcon::Off);
        hideButton->setIcon(icon2);
        SendButton = new QPushButton(Widget);
        SendButton->setObjectName(QStringLiteral("SendButton"));
        SendButton->setGeometry(QRect(390, 710, 81, 31));
        SendButton->setMinimumSize(QSize(60, 25));
        SendButton->setMaximumSize(QSize(103, 41));
        SendButton->setStyleSheet(QLatin1String("QPushButton { background-color: rgb(172, 178, 148,200); border-radius: 3px; color: rgb(255, 255, 255); }\n"
" QPushButton:hover { background-color: rgb(172, 178, 148,255);}\n"
""));
        label = new QLabel(Widget);
        label->setObjectName(QStringLiteral("label"));
        label->setGeometry(QRect(40, 671, 461, 81));
        label->setStyleSheet(QLatin1String("border-bottom-left-radius:20px; \n"
"border-bottom-right-radius:20px; \n"
"background-color: rgb(255, 255, 255, 230);"));
        stackedWidget = new QStackedWidget(Widget);
        stackedWidget->setObjectName(QStringLiteral("stackedWidget"));
        stackedWidget->setGeometry(QRect(0, 0, 1001, 801));
        page = new QWidget();
        page->setObjectName(QStringLiteral("page"));
        webButton = new QPushButton(page);
        webButton->setObjectName(QStringLiteral("webButton"));
        webButton->setGeometry(QRect(40, 760, 271, 31));
        webButton->setMinimumSize(QSize(60, 25));
        webButton->setMaximumSize(QSize(300, 50));
        QFont font1;
        font1.setBold(true);
        font1.setWeight(75);
        webButton->setFont(font1);
        webButton->setStyleSheet(QLatin1String("QPushButton { background-color: rgb(172, 178, 148,100); border-radius: 3px; color: rgb(255, 255, 255); }\n"
" QPushButton:hover { background-color: rgb(172, 178, 148,150);}\n"
""));
        changeButton = new QPushButton(page);
        changeButton->setObjectName(QStringLiteral("changeButton"));
        changeButton->setGeometry(QRect(880, 10, 31, 31));
        changeButton->setStyleSheet(QLatin1String("QPushButton { background-color: rgb(200, 200, 200,0); border-radius: 3px; color: rgb(255, 255, 255); }\n"
"QPushButton:hover { background-color: rgb(172, 178, 148);}"));
        QIcon icon3;
        icon3.addFile(QStringLiteral(":/chat/image/icon/icon_menu.png"), QSize(), QIcon::Normal, QIcon::Off);
        changeButton->setIcon(icon3);
        textEditWrite = new QTextEdit(page);
        textEditWrite->setObjectName(QStringLiteral("textEditWrite"));
        textEditWrite->setGeometry(QRect(40, 530, 461, 141));
        textEditWrite->setStyleSheet(QLatin1String("border-top-left-radius:0px; \n"
"border-top-right-radius:0px;\n"
"background-color: rgb(255, 255, 255,230);\n"
"border-top:2px solid #e1e0e0;"));
        stackedWidget->addWidget(page);
        page_2 = new QWidget();
        page_2->setObjectName(QStringLiteral("page_2"));
        stackedWidget->addWidget(page_2);
        stackedWidget->raise();
        label->raise();
        textEditRead->raise();
        tableWidget->raise();
        userNumber->raise();
        voiceButton->raise();
        textButton->raise();
        sendfile->raise();
        imageButton->raise();
        save->raise();
        WatermelonChat->raise();
        fontSizeComboBox->raise();
        textbold->raise();
        textitalic->raise();
        textUnderline->raise();
        textcolor->raise();
        clear->raise();
        fontComboBox->raise();
        gameButton->raise();
        closeButton->raise();
        hideButton->raise();
        SendButton->raise();

        retranslateUi(Widget);

        stackedWidget->setCurrentIndex(0);


        QMetaObject::connectSlotsByName(Widget);
    } // setupUi

    void retranslateUi(QWidget *Widget)
    {
        Widget->setWindowTitle(QApplication::translate("Widget", "Watermelon Chat", 0));
        userNumber->setText(QApplication::translate("Widget", "\345\234\250\347\272\277\344\272\272\346\225\260\357\274\232", 0));
        voiceButton->setText(QString());
        textButton->setText(QString());
        sendfile->setText(QString());
        imageButton->setText(QString());
        save->setText(QString());
        WatermelonChat->setText(QApplication::translate("Widget", "<html><head/><body><p align=\"center\"><br/></p></body></html>", 0));
        fontSizeComboBox->clear();
        fontSizeComboBox->insertItems(0, QStringList()
         << QApplication::translate("Widget", "9", 0)
         << QApplication::translate("Widget", "10", 0)
         << QApplication::translate("Widget", "11", 0)
         << QApplication::translate("Widget", "12", 0)
         << QApplication::translate("Widget", "13", 0)
         << QApplication::translate("Widget", "14", 0)
         << QApplication::translate("Widget", "15", 0)
         << QApplication::translate("Widget", "16", 0)
         << QApplication::translate("Widget", "17", 0)
         << QApplication::translate("Widget", "18", 0)
         << QApplication::translate("Widget", "19", 0)
         << QApplication::translate("Widget", "20", 0)
        );
        fontSizeComboBox->setCurrentText(QApplication::translate("Widget", "9", 0));
        textbold->setText(QString());
        textitalic->setText(QString());
        textUnderline->setText(QString());
        textcolor->setText(QString());
        clear->setText(QString());
        fontComboBox->setCurrentText(QApplication::translate("Widget", "\345\256\213\344\275\223", 0));
        gameButton->setText(QString());
#ifndef QT_NO_TOOLTIP
        closeButton->setToolTip(QApplication::translate("Widget", "\345\205\263\351\227\255", 0));
#endif // QT_NO_TOOLTIP
        closeButton->setText(QApplication::translate("Widget", "...", 0));
#ifndef QT_NO_TOOLTIP
        hideButton->setToolTip(QApplication::translate("Widget", "\346\234\200\345\260\217\345\214\226", 0));
#endif // QT_NO_TOOLTIP
        hideButton->setText(QApplication::translate("Widget", "...", 0));
        SendButton->setText(QApplication::translate("Widget", "\345\217\221\351\200\201", 0));
        label->setText(QString());
        webButton->setText(QApplication::translate("Widget", "follow\346\210\221\344\273\254\347\232\204GitHub", 0));
        changeButton->setText(QString());
    } // retranslateUi

};

namespace Ui {
    class Widget: public Ui_Widget {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_WIDGET_H
