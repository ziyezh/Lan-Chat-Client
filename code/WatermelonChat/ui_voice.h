/********************************************************************************
** Form generated from reading UI file 'voice.ui'
**
** Created by: Qt User Interface Compiler version 5.6.1
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_VOICE_H
#define UI_VOICE_H

#include <QtCore/QVariant>
#include <QtWidgets/QAction>
#include <QtWidgets/QApplication>
#include <QtWidgets/QButtonGroup>
#include <QtWidgets/QHeaderView>
#include <QtWidgets/QMainWindow>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_VoiceWindow
{
public:
    QWidget *centralwidget;

    void setupUi(QMainWindow *VoiceWindow)
    {
        if (VoiceWindow->objectName().isEmpty())
            VoiceWindow->setObjectName(QStringLiteral("VoiceWindow"));
        VoiceWindow->resize(200, 200);
        centralwidget = new QWidget(VoiceWindow);
        centralwidget->setObjectName(QStringLiteral("centralwidget"));
        VoiceWindow->setCentralWidget(centralwidget);

        retranslateUi(VoiceWindow);

        QMetaObject::connectSlotsByName(VoiceWindow);
    } // setupUi

    void retranslateUi(QMainWindow *VoiceWindow)
    {
        VoiceWindow->setWindowTitle(QApplication::translate("VoiceWindow", "MainWindow", 0));
    } // retranslateUi

};

namespace Ui {
    class VoiceWindow: public Ui_VoiceWindow {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_VOICE_H
