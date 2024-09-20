/********************************************************************************
** Form generated from reading UI file 'loggerwindow.ui'
**
** Created by: Qt User Interface Compiler version 6.7.2
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_LOGGERWINDOW_H
#define UI_LOGGERWINDOW_H

#include <QtCore/QVariant>
#include <QtWidgets/QApplication>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_LoggerWindow
{
public:

    void setupUi(QWidget *LoggerWindow)
    {
        if (LoggerWindow->objectName().isEmpty())
            LoggerWindow->setObjectName("LoggerWindow");
        LoggerWindow->resize(400, 300);

        retranslateUi(LoggerWindow);

        QMetaObject::connectSlotsByName(LoggerWindow);
    } // setupUi

    void retranslateUi(QWidget *LoggerWindow)
    {
        LoggerWindow->setWindowTitle(QCoreApplication::translate("LoggerWindow", "Form", nullptr));
    } // retranslateUi

};

namespace Ui {
    class LoggerWindow: public Ui_LoggerWindow {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_LOGGERWINDOW_H
