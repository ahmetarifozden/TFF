/********************************************************************************
** Form generated from reading UI file 'mainwindow.ui'
**
** Created by: Qt User Interface Compiler version 6.7.2
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_MAINWINDOW_H
#define UI_MAINWINDOW_H

#include <QtCore/QVariant>
#include <QtWidgets/QApplication>
#include <QtWidgets/QFormLayout>
#include <QtWidgets/QLabel>
#include <QtWidgets/QLineEdit>
#include <QtWidgets/QMainWindow>
#include <QtWidgets/QMenuBar>
#include <QtWidgets/QPushButton>
#include <QtWidgets/QSpinBox>
#include <QtWidgets/QStatusBar>
#include <QtWidgets/QVBoxLayout>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_MainWindow
{
public:
    QWidget *centralwidget;
    QWidget *layoutWidget;
    QVBoxLayout *verticalLayout;
    QFormLayout *formLayout;
    QLabel *label;
    QLineEdit *lineEditTC;
    QLabel *label_2;
    QLineEdit *lineEditName;
    QLabel *label_3;
    QSpinBox *Yas;
    QLabel *label_4;
    QLineEdit *MusabakaAd;
    QLabel *label_5;
    QLineEdit *TribunAd;
    QLabel *label_6;
    QLineEdit *KoltukNo;
    QLabel *label_7;
    QLineEdit *KapiNo;
    QLabel *label_8;
    QLineEdit *lineEditApiUrl;
    QPushButton *pushButtonKaydet;
    QWidget *layoutWidget1;
    QVBoxLayout *verticalLayout_2;
    QLabel *labelImage;
    QPushButton *pushButtonSelectImage;
    QMenuBar *menubar;
    QStatusBar *statusbar;

    void setupUi(QMainWindow *MainWindow)
    {
        if (MainWindow->objectName().isEmpty())
            MainWindow->setObjectName("MainWindow");
        MainWindow->resize(472, 287);
        centralwidget = new QWidget(MainWindow);
        centralwidget->setObjectName("centralwidget");
        layoutWidget = new QWidget(centralwidget);
        layoutWidget->setObjectName("layoutWidget");
        layoutWidget->setGeometry(QRect(30, 20, 168, 211));
        verticalLayout = new QVBoxLayout(layoutWidget);
        verticalLayout->setObjectName("verticalLayout");
        verticalLayout->setContentsMargins(0, 0, 0, 0);
        formLayout = new QFormLayout();
        formLayout->setObjectName("formLayout");
        label = new QLabel(layoutWidget);
        label->setObjectName("label");

        formLayout->setWidget(0, QFormLayout::LabelRole, label);

        lineEditTC = new QLineEdit(layoutWidget);
        lineEditTC->setObjectName("lineEditTC");

        formLayout->setWidget(0, QFormLayout::FieldRole, lineEditTC);

        label_2 = new QLabel(layoutWidget);
        label_2->setObjectName("label_2");

        formLayout->setWidget(1, QFormLayout::LabelRole, label_2);

        lineEditName = new QLineEdit(layoutWidget);
        lineEditName->setObjectName("lineEditName");

        formLayout->setWidget(1, QFormLayout::FieldRole, lineEditName);

        label_3 = new QLabel(layoutWidget);
        label_3->setObjectName("label_3");

        formLayout->setWidget(2, QFormLayout::LabelRole, label_3);

        Yas = new QSpinBox(layoutWidget);
        Yas->setObjectName("Yas");

        formLayout->setWidget(2, QFormLayout::FieldRole, Yas);

        label_4 = new QLabel(layoutWidget);
        label_4->setObjectName("label_4");

        formLayout->setWidget(3, QFormLayout::LabelRole, label_4);

        MusabakaAd = new QLineEdit(layoutWidget);
        MusabakaAd->setObjectName("MusabakaAd");

        formLayout->setWidget(3, QFormLayout::FieldRole, MusabakaAd);

        label_5 = new QLabel(layoutWidget);
        label_5->setObjectName("label_5");

        formLayout->setWidget(4, QFormLayout::LabelRole, label_5);

        TribunAd = new QLineEdit(layoutWidget);
        TribunAd->setObjectName("TribunAd");

        formLayout->setWidget(4, QFormLayout::FieldRole, TribunAd);

        label_6 = new QLabel(layoutWidget);
        label_6->setObjectName("label_6");

        formLayout->setWidget(5, QFormLayout::LabelRole, label_6);

        KoltukNo = new QLineEdit(layoutWidget);
        KoltukNo->setObjectName("KoltukNo");

        formLayout->setWidget(5, QFormLayout::FieldRole, KoltukNo);

        label_7 = new QLabel(layoutWidget);
        label_7->setObjectName("label_7");

        formLayout->setWidget(6, QFormLayout::LabelRole, label_7);

        KapiNo = new QLineEdit(layoutWidget);
        KapiNo->setObjectName("KapiNo");

        formLayout->setWidget(6, QFormLayout::FieldRole, KapiNo);

        label_8 = new QLabel(layoutWidget);
        label_8->setObjectName("label_8");

        formLayout->setWidget(7, QFormLayout::LabelRole, label_8);

        lineEditApiUrl = new QLineEdit(layoutWidget);
        lineEditApiUrl->setObjectName("lineEditApiUrl");

        formLayout->setWidget(7, QFormLayout::FieldRole, lineEditApiUrl);


        verticalLayout->addLayout(formLayout);

        pushButtonKaydet = new QPushButton(layoutWidget);
        pushButtonKaydet->setObjectName("pushButtonKaydet");

        verticalLayout->addWidget(pushButtonKaydet);

        layoutWidget1 = new QWidget(centralwidget);
        layoutWidget1->setObjectName("layoutWidget1");
        layoutWidget1->setGeometry(QRect(220, 30, 151, 171));
        verticalLayout_2 = new QVBoxLayout(layoutWidget1);
        verticalLayout_2->setObjectName("verticalLayout_2");
        verticalLayout_2->setContentsMargins(0, 0, 0, 0);
        labelImage = new QLabel(layoutWidget1);
        labelImage->setObjectName("labelImage");

        verticalLayout_2->addWidget(labelImage);

        pushButtonSelectImage = new QPushButton(layoutWidget1);
        pushButtonSelectImage->setObjectName("pushButtonSelectImage");

        verticalLayout_2->addWidget(pushButtonSelectImage);

        MainWindow->setCentralWidget(centralwidget);
        menubar = new QMenuBar(MainWindow);
        menubar->setObjectName("menubar");
        menubar->setGeometry(QRect(0, 0, 472, 18));
        MainWindow->setMenuBar(menubar);
        statusbar = new QStatusBar(MainWindow);
        statusbar->setObjectName("statusbar");
        MainWindow->setStatusBar(statusbar);

        retranslateUi(MainWindow);

        QMetaObject::connectSlotsByName(MainWindow);
    } // setupUi

    void retranslateUi(QMainWindow *MainWindow)
    {
        MainWindow->setWindowTitle(QCoreApplication::translate("MainWindow", "MainWindow", nullptr));
        label->setText(QCoreApplication::translate("MainWindow", "TC NUMARASI", nullptr));
        label_2->setText(QCoreApplication::translate("MainWindow", "Ad\304\261 Soyad\304\261", nullptr));
        label_3->setText(QCoreApplication::translate("MainWindow", "Ya\305\237", nullptr));
        label_4->setText(QCoreApplication::translate("MainWindow", "M\303\274sabaka ad\304\261", nullptr));
        label_5->setText(QCoreApplication::translate("MainWindow", "Trib\303\274n Ad\304\261", nullptr));
        label_6->setText(QCoreApplication::translate("MainWindow", "Koltuk No", nullptr));
        label_7->setText(QCoreApplication::translate("MainWindow", "Kap\304\261 No", nullptr));
        label_8->setText(QCoreApplication::translate("MainWindow", "API", nullptr));
        pushButtonKaydet->setText(QCoreApplication::translate("MainWindow", "PushButton", nullptr));
        labelImage->setText(QCoreApplication::translate("MainWindow", "                     Foto\304\237raf", nullptr));
        pushButtonSelectImage->setText(QCoreApplication::translate("MainWindow", "Foto\304\237raf Y\303\274kle", nullptr));
    } // retranslateUi

};

namespace Ui {
    class MainWindow: public Ui_MainWindow {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_MAINWINDOW_H
