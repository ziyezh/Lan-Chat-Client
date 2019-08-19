/********************************************************************************
** Form generated from reading UI file 'maingamewindow.ui'
**
** Created by: Qt User Interface Compiler version 5.6.1
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_MAINGAMEWINDOW_H
#define UI_MAINGAMEWINDOW_H

#include <QtCore/QVariant>
#include <QtWidgets/QAction>
#include <QtWidgets/QApplication>
#include <QtWidgets/QButtonGroup>
#include <QtWidgets/QHeaderView>
#include <QtWidgets/QMainWindow>
#include <QtWidgets/QMenu>
#include <QtWidgets/QMenuBar>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_MainGameWindow
{
public:
    QAction *actionStart;
    QAction *actionBasic;
    QAction *actionMedium;
    QAction *actionHard;
    QAction *actionQuit;
    QWidget *centralWidget;
    QMenuBar *menuBar;
    QMenu *menu;
    QMenu *menuLevel;

    void setupUi(QMainWindow *MainGameWindow)
    {
        if (MainGameWindow->objectName().isEmpty())
            MainGameWindow->setObjectName(QStringLiteral("MainGameWindow"));
        MainGameWindow->resize(400, 300);
        actionStart = new QAction(MainGameWindow);
        actionStart->setObjectName(QStringLiteral("actionStart"));
        actionBasic = new QAction(MainGameWindow);
        actionBasic->setObjectName(QStringLiteral("actionBasic"));
        actionMedium = new QAction(MainGameWindow);
        actionMedium->setObjectName(QStringLiteral("actionMedium"));
        actionHard = new QAction(MainGameWindow);
        actionHard->setObjectName(QStringLiteral("actionHard"));
        actionQuit = new QAction(MainGameWindow);
        actionQuit->setObjectName(QStringLiteral("actionQuit"));
        centralWidget = new QWidget(MainGameWindow);
        centralWidget->setObjectName(QStringLiteral("centralWidget"));
        MainGameWindow->setCentralWidget(centralWidget);
        menuBar = new QMenuBar(MainGameWindow);
        menuBar->setObjectName(QStringLiteral("menuBar"));
        menuBar->setGeometry(QRect(0, 0, 400, 23));
        menu = new QMenu(menuBar);
        menu->setObjectName(QStringLiteral("menu"));
        menuLevel = new QMenu(menu);
        menuLevel->setObjectName(QStringLiteral("menuLevel"));
        MainGameWindow->setMenuBar(menuBar);

        menuBar->addAction(menu->menuAction());
        menu->addAction(actionStart);
        menu->addAction(menuLevel->menuAction());
        menu->addAction(actionQuit);
        menuLevel->addAction(actionBasic);
        menuLevel->addAction(actionMedium);
        menuLevel->addAction(actionHard);

        retranslateUi(MainGameWindow);

        QMetaObject::connectSlotsByName(MainGameWindow);
    } // setupUi

    void retranslateUi(QMainWindow *MainGameWindow)
    {
        MainGameWindow->setWindowTitle(QApplication::translate("MainGameWindow", "MainGameWindow", 0));
        actionStart->setText(QApplication::translate("MainGameWindow", "start", 0));
        actionBasic->setText(QApplication::translate("MainGameWindow", "basic", 0));
        actionMedium->setText(QApplication::translate("MainGameWindow", "medium", 0));
        actionHard->setText(QApplication::translate("MainGameWindow", "hard", 0));
        actionQuit->setText(QApplication::translate("MainGameWindow", "quit", 0));
        menu->setTitle(QApplication::translate("MainGameWindow", "\346\270\270\346\210\217", 0));
        menuLevel->setTitle(QApplication::translate("MainGameWindow", "level", 0));
    } // retranslateUi

};

namespace Ui {
    class MainGameWindow: public Ui_MainGameWindow {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_MAINGAMEWINDOW_H
