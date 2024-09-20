#include "mainwindow.h"
#include "ui_mainwindow.h"
#include "templatewindow.h"
#include "settingswindow.h"
#include <QDir>
#include <QFile>
#include <QJsonDocument>
#include <QJsonObject>
#include <QJsonArray>
#include <QFormLayout>
#include <QLabel>
#include <QLineEdit>
#include <QMessageBox>
#include <QFileDialog>
#include <QNetworkAccessManager>
#include <QNetworkRequest>
#include <QNetworkReply>
#include <QUrl>
#include "loggerwindow.h"
#include <QDebug>


LoggerWindow *MainWindow::loggerWindow = nullptr;  // Static üye değişkeni tanımı

MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::MainWindow)
{
    ui->setupUi(this);

    //QNetworkAccessManager *networkManager = new QNetworkAccessManager(this);
    networkManager = new QNetworkAccessManager(this);

    // JSON dosyalarını combobox'a ekleme işlemi
    QString folderPath = QCoreApplication::applicationDirPath() + "/sablonlar";
    updateComboBox(folderPath);


    connect(ui->comboBox, &QComboBox::currentIndexChanged, this, [this, folderPath]() {
        if(ui->comboBox->currentText()==""){
            return;
        }

        QString filePath = folderPath + "/" + ui->comboBox->currentText();
        QFile file(filePath);

        if (!file.open(QIODevice::ReadOnly)) {
            QMessageBox::warning(this, tr("Hata"), tr("Dosya açılamadı: %1").arg(filePath));
            return;
        }

        QByteArray jsonData = file.readAll();
        file.close();

        QJsonDocument jsonDoc = QJsonDocument::fromJson(jsonData);
        if (jsonDoc.isNull()) {
            QMessageBox::warning(this, tr("Hata"), tr("Geçersiz JSON dosyası: %1").arg(filePath));
            return;
        }

        QJsonObject jsonObjt = jsonDoc.object();
        displayJsonFields(jsonObjt);

    });

    // TemplateWindow ve SettingsWindow'u tab widget'e ekleme
    TemplateWindow *templateWindow = new TemplateWindow();
    SettingsWindow *settingsWindow = new SettingsWindow();
    // LoggerWindow'u oluşturun ve bir sekme olarak ekleyin
    loggerWindow = new LoggerWindow();
    ui->tabWidget->addTab(templateWindow, tr("Template"));
    ui->tabWidget->addTab(settingsWindow, tr("Settings"));
    ui->tabWidget->addTab(loggerWindow, tr("Logger"));

    setupMessageHandler();


    connect(ui->sendButton, &QPushButton::clicked, this, &MainWindow::onSendButtonClicked);
    connect(templateWindow, &TemplateWindow::templateSaved, this, [this, folderPath]() {
        updateComboBox(folderPath);
    });
}

MainWindow::~MainWindow()
{
    delete ui;
}

void MainWindow::updateComboBox(const QString &folderPath)
{
    QString filePath = folderPath + "/" + ui->comboBox->currentText();

    ui->comboBox->clear();
    QDir dir(folderPath);
    QStringList jsonFiles = dir.entryList(QStringList() << "*.json", QDir::Files);

    foreach (const QString &jsonFile, jsonFiles) {
        ui->comboBox->addItem(jsonFile);
    }

    qDebug() << "Açılmaya çalışılan dosya yolu: " << filePath;
}
/*
void MainWindow::displayJsonFields(const QJsonObject &jsonObj)
{
    // Eski alanları temizle
    QLayout *oldLayout = ui->fieldsWidget->layout();
    if (oldLayout) {
        QLayoutItem *item;
        while ((item = oldLayout->takeAt(0)) != nullptr) {
            delete item->widget();  // Eski widget'ı serbest bırak
            delete item;           // Eski layout öğesini serbest bırak
        }
        delete oldLayout;         // Eski layout'u serbest bırak
    }

    // Yeni alanları ekle
    QFormLayout *formLayout = new QFormLayout();
    QJsonArray fieldsArray = jsonObj["fields"].toArray();

    foreach (const QJsonValue &value, fieldsArray) {
        QJsonObject fieldObject = value.toObject();
        QString fieldName = fieldObject["name"].toString();
        QString fieldType = fieldObject["type"].toString();

        QLabel *label = new QLabel(fieldName);
        QLineEdit *lineEdit = new QLineEdit();
        inputFields[fieldName] = lineEdit;  // QLineEdit'i map'e ekle

        formLayout->addRow(label, lineEdit);
    }

    ui->fieldsWidget->setLayout(formLayout);
}
*/


void MainWindow::displayJsonFields(const QJsonObject &jsonObjt)
{
    // Eski alanları temizle
    QLayout *oldLayout = ui->fieldsWidget->layout();
    if (oldLayout) {
        QLayoutItem *item;
        while ((item = oldLayout->takeAt(0)) != nullptr) {
            delete item->widget();
            delete item;
        }
        delete oldLayout;
    }

    // Yeni alanları ekle
    QFormLayout *formLayout = new QFormLayout();
    QJsonArray fieldsArray = jsonObjt["fields"].toArray();

    foreach (const QJsonValue &value, fieldsArray) {
        QJsonObject fieldObject = value.toObject();
        QString fieldName = fieldObject["name"].toString();
        QString fieldType = fieldObject["type"].toString();

        QLabel *label = new QLabel(fieldName);
        QLineEdit *lineEdit = new QLineEdit();

        if (lineEdit == nullptr) {
            qDebug() << "QLineEdit oluşturulamadı!";
            continue;
        }

        inputFields[fieldName] = lineEdit;  // QLineEdit'i map'e ekle

        formLayout->addRow(label, lineEdit);
    }

    ui->fieldsWidget->setLayout(formLayout);
}


void MainWindow::onSendButtonClicked()
{
    QJsonObject jsonObj;
    // Dinamik olarak oluşturulan alanları JSON'a ekleyin
    qDebug() << "Input alanlarından veriler JSON'a ekleniyor...";



    for (auto it = inputFields.begin(); it != inputFields.end(); ++it) {
        if (it.value() == nullptr) {
            qDebug() << "Found a null pointer in inputFields!";
            continue;  // Geçersiz işaretçiyi atla
        }
        jsonObj[it.key()] = it.value()->text();
    }

    if (jsonObj.isEmpty()) {
        qDebug() << "JSON object is empty!";
        return;
    }

    // JSON verisini gönder
    sendJsonData(jsonObj);

}

void MainWindow::sendJsonData(const QJsonObject &jsonObj)
{
    // API adresini SettingsWindow'dan al
    QWidget *settingsWidget = ui->tabWidget->widget(2);
    SettingsWindow *settingsWindow = qobject_cast<SettingsWindow*>(settingsWidget);
    if (!settingsWindow) {
        QMessageBox::warning(this, tr("Hata"), tr("SettingsWindow bulunamadı."));
        qDebug()<<"Hata, SettinsWindow Bulunamadı";
        return;
    }

    QString apiUrl = settingsWindow->getApiServerAddress();

    if (apiUrl.isEmpty()) {
        QMessageBox::warning(this, tr("Hata"), tr("API sunucu adresi girilmemiş."));
        qDebug()<<"Hata, API sunucu adresi girilmemiş";
        return;
    }

    // QNetworkAccessManager nesnesini oluştur

    // QNetworkRequest nesnesini oluştur
    QNetworkRequest request;
    request.setUrl(QUrl(apiUrl));

    // İçerik türünü belirt
    request.setHeader(QNetworkRequest::ContentTypeHeader, "application/json");

    // JSON veriyi QByteArray'e dönüştür
    QJsonDocument jsonDoc(jsonObj);
    QByteArray jsonData = jsonDoc.toJson();

    // POST isteği gönder
    QNetworkReply *reply = networkManager->post(request, jsonData);

    // Yanıtı dinle
    connect(reply, &QNetworkReply::finished, [this, reply]() {
        if (reply->error() == QNetworkReply::NoError) {
            qDebug() << "Başarılı, Veriler başarıyla gönderildi.";
            QMessageBox::information(this, "Başarılı", "Veriler başarıyla gönderildi.");
        } else {
            QMessageBox::warning(this, "Hata", "Veriler gönderilirken hata oluştu: " + reply->errorString());
            qDebug()<<"Hata,Veriler gönderilirken bir hata oluştu ";
        }
        reply->deleteLater();
    });
    clearAll();

}

void MainWindow::customMessageHandler(QtMsgType type, const QMessageLogContext &context, const QString &msg) {
    QString text;
    switch (type) {
    case QtDebugMsg:
        text = QString(" %1").arg(msg);
        break;
    case QtInfoMsg:
        text = QString(" %1").arg(msg);
        break;
    case QtWarningMsg:
        text = QString(" %1").arg(msg);
        break;
    case QtCriticalMsg:
        text = QString(" %1").arg(msg);
        break;
    case QtFatalMsg:
        text = QString(" %1").arg(msg);
        abort();
    }

    if (loggerWindow) {
        loggerWindow->addLogMessage(text);
    }
}




void MainWindow::setupMessageHandler()
{
    // Lambda ifadesi kullanarak messageHandler'ı ayarlayın
    auto handler = [](QtMsgType type, const QMessageLogContext &context, const QString &msg) {
        MainWindow::customMessageHandler(type, context, msg);
    };
    qInstallMessageHandler(handler);
}


void MainWindow::clearAll()
{
/*
    // 1. inputFields'teki tüm QLineEdit widget'larının içeriğini temizle
    for (auto it = inputFields.begin(); it != inputFields.end(); ++it) {
        if (it.value()) {
            it.value()->clear();  // QLineEdit'i temizle
        }
    }

    // 2. fieldsWidget içindeki layout'u temizle (Şablon yapısını koruyun)
    QLayout *oldLayout = ui->fieldsWidget->layout();
    if (oldLayout) {
        while (oldLayout->count() > 0) {
            QLayoutItem *item = oldLayout->takeAt(0); // İlk öğeyi al
            if (item) {
                delete item->widget(); // Widget'ı sil
                delete item; // LayoutItem'ı sil
            }
        }
        delete oldLayout; // Eski layout'u serbest bırak
    }
*/
    // 3. inputFields map'ini sıfırla
    inputFields.clear();

    // 4. JSON verilerini sıfırla (Bellekteki JSON'u sıfırla)
    jsonObj = QJsonObject();  // JSON objeyi sıfırla
}
