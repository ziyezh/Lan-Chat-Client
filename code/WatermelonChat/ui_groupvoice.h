/********************************************************************************
** Form generated from reading UI file 'groupvoice.ui'
**
** Created by: Qt User Interface Compiler version 5.6.1
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_GROUPVOICE_H
#define UI_GROUPVOICE_H

#include <QtCore/QVariant>
#include <QtWidgets/QAction>
#include <QtWidgets/QApplication>
#include <QtWidgets/QButtonGroup>
#include <QtWidgets/QHeaderView>
#include <QtWidgets/QMainWindow>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_GroupVoice
{
public:
    QWidget *centralwidget;

    void setupUi(QMainWindow *GroupVoice)
    {
        if (GroupVoice->objectName().isEmpty())
            GroupVoice->setObjectName(QStringLiteral("GroupVoice"));
        GroupVoice->resize(200, 200);
        centralwidget = new QWidget(GroupVoice);
        centralwidget->setObjectName(QStringLiteral("centralwidget"));
        GroupVoice->setCentralWidget(centralwidget);

        retranslateUi(GroupVoice);

        QMetaObject::connectSlotsByName(GroupVoice);
    } // setupUi

    void retranslateUi(QMainWindow *GroupVoice)
    {
        GroupVoice->setWindowTitle(QApplication::translate("GroupVoice", "MainWindow", 0));
    } // retranslateUi

};

namespace Ui {
    class GroupVoice: public Ui_GroupVoice {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_GROUPVOICE_H
