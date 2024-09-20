#include "mainwindow.h"
#include "ui_mainwindow.h"
#include <QMessageBox>

MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::MainWindow)
    , networkManager(new QNetworkAccessManager(this))
{
    ui->setupUi(this);

    //connect(ui->pushButtonSelectImage, &QPushButton::clicked, this, &MainWindow::on_pushButtonSelectImage_clicked);
    connect(ui->pushButtonKaydet, &QPushButton::clicked, this, &MainWindow::on_pushButtonSubmit_clicked);
    connect(networkManager, &QNetworkAccessManager::finished, this, &MainWindow::on_networkReplyFinished);
}

MainWindow::~MainWindow()
{
    delete ui;
}

void MainWindow::on_pushButtonSelectImage_clicked()
{
    QString filePath = QFileDialog::getOpenFileName(this, "Resim Seç", "", "Resimler (*.png *.jpg *.bmp)");
    if (!filePath.isEmpty()) {
        selectedImagePath = filePath;
        QPixmap pixmap(filePath);
        ui->labelImage->setPixmap(pixmap.scaled(ui->labelImage->size(), Qt::KeepAspectRatio));
    }
}

void MainWindow::on_pushButtonSubmit_clicked()
{
    sendDataToApi();
}

void MainWindow::sendDataToApi()
{
    QString apiUrl = ui->lineEditApiUrl->text(); // Kullanıcının API URL'sini aldığı yer

    QString name = ui->lineEditName->text();
    QString tc = ui->lineEditTC->text();
    QString MusabakaAd = ui->MusabakaAd->text();
    QString TribunAd = ui->TribunAd->text();
    QString KoltukNo = ui->KoltukNo->text();
    QString KapiNo = ui->KapiNo->text();

    QJsonObject json;
    json["name:"] = name;
    json["tc:"] = tc;
    json["Müsabaka Adı:"] = MusabakaAd;
    json["Tribün Adı:"] = TribunAd;
    json["Koltuk No:"] = KoltukNo;
    json["Kapı No:"] = KapiNo;


    // Resim verisini ekleyin
    if (!selectedImagePath.isEmpty()) {
        QFile imageFile(selectedImagePath);
        if (imageFile.open(QIODevice::ReadOnly)) {
            QByteArray imageData = imageFile.readAll();
            QString imageBase64 = QString::fromLatin1(imageData.toBase64().data());
            json["image"] = imageBase64;
        }
    }

    QJsonDocument jsonDoc(json);
    QByteArray jsonData = jsonDoc.toJson();

    QUrl url(apiUrl); // API URL'sini kullanarak QUrl oluştur
    QNetworkRequest request(url);
    request.setHeader(QNetworkRequest::ContentTypeHeader, "application/json");

    networkManager->post(request, jsonData);
}

void MainWindow::on_networkReplyFinished(QNetworkReply* reply)
{
    if (reply->error() == QNetworkReply::NoError) {
        QString response = reply->readAll();
        QMessageBox::information(this, "Başarılı", "Veri başarıyla gönderildi: " + response);
    } else {
        QMessageBox::warning(this, "Hata", "Veri gönderimi sırasında bir hata oluştu: " + reply->errorString());
    }
    reply->deleteLater();
}
