#include "mainwindow.h"
#include "ui_mainwindow.h"
#include <QImage>
#include <QPixmap>
#include <QRandomGenerator>
#include <QJsonObject>
#include <QJsonDocument>
#include <QJsonArray>
#include <QNetworkRequest>
#include <QNetworkReply>
#include <QBuffer>
#include <QDebug>
#include <QDir>
#include <QFileInfoList>
#include <QImageWriter>

MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::MainWindow)
    , networkManager(new QNetworkAccessManager(this))
{
    ui->setupUi(this);

    // Connect button click event to slot
    //connect(ui->generateButton, &QPushButton::clicked, this, &MainWindow::on_generateButton_clicked);
    connect(networkManager, &QNetworkAccessManager::finished, this, &MainWindow::onUploadFinished);    
}

MainWindow::~MainWindow()
{
    delete ui;
}

void MainWindow::on_generateButton_clicked()
{
    int personCount = ui->personCountSpinBox->value();  // Kullanıcının girdiği kişi sayısı
    generateRandomData(personCount);
}

void MainWindow::generateRandomData(int personCount)
{
    QJsonArray personArray;

    for (int i = 0; i < personCount; ++i) {
        QString name = QString("Name%1").arg(QRandomGenerator::global()->bounded(1000));
        QString surname = QString("Surname%1").arg(QRandomGenerator::global()->bounded(1000));
        QString tc = QString::number(QRandomGenerator::global()->bounded(10000000000ull));
        QString musabaka = QString("musabaka%1").arg(QRandomGenerator::global()->bounded(1000));
        QString kapino = QString("kapino%1").arg(QRandomGenerator::global()->bounded(1000));
        QString tribuno = QString("tribuno%1").arg(QRandomGenerator::global()->bounded(1000));

        QString imagePath = getRandomImagePath("C:/Users/Arif/Documents/Ders2/resimler"); // Resimlerin bulunduğu dizin
        QImage image(imagePath);

        if (image.isNull()) {
            qWarning() << "Failed to load image from path:" << imagePath;
            continue;
        }

        QByteArray imageData;
        QBuffer buffer(&imageData);
        buffer.open(QIODevice::WriteOnly);
        QImageWriter writer(&buffer, "PNG");
        writer.write(image);

        QJsonObject personObject;
        personObject["name"] = name;
        personObject["surname"] = surname;
        personObject["tc"] = tc;
        personObject["image"] = QString(imageData.toBase64());
        personObject["musabaka"] = musabaka;
        personObject["kapino"] = kapino;
        personObject["tribuno"] = tribuno;

        personArray.append(personObject);
    }

    QString apiUrl = ui->apiUrlLineEdit->text();  // Kullanıcının girdiği API URL'si
    uploadData(personArray, apiUrl);
}

void MainWindow::uploadData(const QJsonArray &personArray, const QString &apiUrl)
{
    QJsonObject jsonObject;
    jsonObject["people"] = personArray;

    QJsonDocument jsonDoc(jsonObject);
    QByteArray jsonData = jsonDoc.toJson();

    QUrl url(apiUrl);
    QNetworkRequest request(url);
    request.setHeader(QNetworkRequest::ContentTypeHeader, "application/json");

    networkManager->post(request, jsonData);
}

void MainWindow::onUploadFinished(QNetworkReply *reply)
{
    if (reply->error() == QNetworkReply::NoError) {
        qDebug() << "Upload successful!";
        QString response = reply->readAll();
        qDebug() << "Response:" << response;
    } else {
        qDebug() << "Upload failed:" << reply->errorString();
    }
    reply->deleteLater();
}

QString MainWindow::getRandomImagePath(const QString &directoryPath)
{
    QDir directory(directoryPath);
    QStringList filters;
    filters << "*.jpg" << "*.png" << "*.bmp"; // Desteklenen resim formatları
    QFileInfoList files = directory.entryInfoList(filters, QDir::Files);

    if (files.isEmpty()) {
        qWarning() << "No images found in directory:" << directoryPath;
        return QString();
    }

    int randomIndex = QRandomGenerator::global()->bounded(files.size());
    return files[randomIndex].absoluteFilePath();
}



//bloop
/*
MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::MainWindow)
{
    ui->setupUi(this);

    // Connect button click event to slot
    connect(ui->generateButton, &QPushButton::clicked, this, &MainWindow::on_generateButton_clicked);
}

MainWindow::~MainWindow()
{
    delete ui;
}

void MainWindow::on_generateButton_clicked()
{
    loadRandomImage();
}

void MainWindow::loadRandomImage()
{
    QDir directory("C:/Users/Arif/Documents/Ders2/resimler");  // Resimlerin bulunduğu dizin
    QStringList imageFiles = directory.entryList(QStringList() << "*.png" << "*.jpg" << "*.jpeg", QDir::Files);

    if (imageFiles.isEmpty()) {
        qDebug() << "No images found in the directory.";
        return;
    }

    int randomIndex = QRandomGenerator::global()->bounded(imageFiles.size());
    QString selectedFile = directory.filePath(imageFiles[randomIndex]);

    QPixmap pixmap(selectedFile);
    ui->photoLabel->setPixmap(pixmap);
    ui->photoLabel->setScaledContents(true); // QLabel içinde resmi ölçeklendir
}
*/
/*
void MainWindow::on_generateButton_clicked()
{
    bool ok;
    int personCount = ui->personCountInput->text().toInt(&ok);
    if (!ok || personCount <= 0) {
        ui->outputTextEdit->setText("Geçerli bir kişi sayısı girin.");
        return;
    }

    QStringList names = {"Ali", "Ayşe", "Mehmet", "Fatma", "Ahmet", "Elif", "Murat", "Zeynep"};
    QStringList surnames = {"Yılmaz", "Kaya", "Demir", "Çelik", "Şahin", "Öztürk", "Aydın", "Koç"};
    QString result;

    for (int i = 0; i < personCount; ++i) {
        QString name = names.at(QRandomGenerator::global()->bounded(names.size()));
        QString surname = surnames.at(QRandomGenerator::global()->bounded(surnames.size()));
        QString tc = generateRandomTC();

        result.append(QString("Kişi %1:\nAd: %2\nSoyad: %3\nTC: %4\n\n").arg(i + 1).arg(name).arg(surname).arg(tc));
    }

    ui->outputTextEdit->setText(result);
}

QString MainWindow::generateRandomTC()
{
    QString tc;
    for (int i = 0; i < 11; ++i) {
        tc.append(QString::number(QRandomGenerator::global()->bounded(10)));
    }
    return tc;
    QString yas;
    for(int i=0;i<2;++i){
        yas.append(QString::number(QRandomGenerator::global()->bounded(10)));
    }
}
*/
