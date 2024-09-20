#include "settingswindow.h"
#include "ui_settingswindow.h"
#include "QMessageBox"

SettingsWindow::SettingsWindow(QWidget *parent)
    : QWidget(parent)
    , ui(new Ui::SettingsWindow)
    , apiServerAddress("")  // API sunucu adresi için bir üye değişkeni tanımla
{
    ui->setupUi(this);

    connect(ui->saveButton, &QPushButton::clicked, this, &SettingsWindow::saveApiServerAddress);
}

SettingsWindow::~SettingsWindow()
{
    delete ui;
}

void SettingsWindow::saveApiServerAddress()
{
    // Kullanıcının girdiği API sunucu adresini al ve kaydet
    apiServerAddress = ui->apiServerLineEdit->text();
    qDebug() << "Sunucu Adresi Kaydedildi:" << apiServerAddress;

    // API adresi kaydedildikten sonra bir mesaj gösterebiliriz
    QMessageBox::information(this, tr("Saved"), tr("API Server address has been saved."));
}

QString SettingsWindow::getApiServerAddress() const
{
    return apiServerAddress;
}
