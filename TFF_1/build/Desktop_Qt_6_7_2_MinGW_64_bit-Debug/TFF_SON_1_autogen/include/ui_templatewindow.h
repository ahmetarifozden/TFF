/********************************************************************************
** Form generated from reading UI file 'templatewindow.ui'
**
** Created by: Qt User Interface Compiler version 6.7.2
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_TEMPLATEWINDOW_H
#define UI_TEMPLATEWINDOW_H

#include <QtCore/QVariant>
#include <QtWidgets/QApplication>
#include <QtWidgets/QPushButton>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_TemplateWindow
{
public:
    QWidget *formWidget;
    QPushButton *addButton;
    QPushButton *saveButton;

    void setupUi(QWidget *TemplateWindow)
    {
        if (TemplateWindow->objectName().isEmpty())
            TemplateWindow->setObjectName("TemplateWindow");
        TemplateWindow->resize(495, 412);
        formWidget = new QWidget(TemplateWindow);
        formWidget->setObjectName("formWidget");
        formWidget->setGeometry(QRect(10, 10, 351, 351));
        addButton = new QPushButton(TemplateWindow);
        addButton->setObjectName("addButton");
        addButton->setGeometry(QRect(370, 30, 101, 41));
        saveButton = new QPushButton(TemplateWindow);
        saveButton->setObjectName("saveButton");
        saveButton->setGeometry(QRect(370, 80, 101, 41));

        retranslateUi(TemplateWindow);

        QMetaObject::connectSlotsByName(TemplateWindow);
    } // setupUi

    void retranslateUi(QWidget *TemplateWindow)
    {
        TemplateWindow->setWindowTitle(QCoreApplication::translate("TemplateWindow", "Form", nullptr));
        addButton->setText(QCoreApplication::translate("TemplateWindow", "Add", nullptr));
        saveButton->setText(QCoreApplication::translate("TemplateWindow", "Save", nullptr));
    } // retranslateUi

};

namespace Ui {
    class TemplateWindow: public Ui_TemplateWindow {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_TEMPLATEWINDOW_H
