/********************************************************************************
** Form generated from reading UI file 'settingswindow.ui'
**
** Created by: Qt User Interface Compiler version 6.7.2
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_SETTINGSWINDOW_H
#define UI_SETTINGSWINDOW_H

#include <QtCore/QVariant>
#include <QtWidgets/QApplication>
#include <QtWidgets/QLabel>
#include <QtWidgets/QLineEdit>
#include <QtWidgets/QPushButton>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_SettingsWindow
{
public:
    QLineEdit *apiServerLineEdit;
    QPushButton *saveButton;
    QLabel *label;

    void setupUi(QWidget *SettingsWindow)
    {
        if (SettingsWindow->objectName().isEmpty())
            SettingsWindow->setObjectName("SettingsWindow");
        SettingsWindow->resize(508, 383);
        apiServerLineEdit = new QLineEdit(SettingsWindow);
        apiServerLineEdit->setObjectName("apiServerLineEdit");
        apiServerLineEdit->setGeometry(QRect(160, 60, 231, 20));
        saveButton = new QPushButton(SettingsWindow);
        saveButton->setObjectName("saveButton");
        saveButton->setGeometry(QRect(410, 60, 61, 21));
        label = new QLabel(SettingsWindow);
        label->setObjectName("label");
        label->setGeometry(QRect(40, 60, 121, 16));

        retranslateUi(SettingsWindow);

        QMetaObject::connectSlotsByName(SettingsWindow);
    } // setupUi

    void retranslateUi(QWidget *SettingsWindow)
    {
        SettingsWindow->setWindowTitle(QCoreApplication::translate("SettingsWindow", "Form", nullptr));
        saveButton->setText(QCoreApplication::translate("SettingsWindow", "Save", nullptr));
        label->setText(QCoreApplication::translate("SettingsWindow", "API Server Adress", nullptr));
    } // retranslateUi

};

namespace Ui {
    class SettingsWindow: public Ui_SettingsWindow {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_SETTINGSWINDOW_H
