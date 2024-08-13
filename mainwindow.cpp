#include "mainwindow.h"
#include "./ui_mainwindow.h"
#include <QFileDialog>
#include <QPixmap>
#include <QFile>
#include <QTextStream>
#include <QMessageBox>
#include <QImage>
#include <QDebug>
#include <QtWidgets>


MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::MainWindow)

{
    ui->setupUi(this);
    connect(ui->pushButtonSelectImage, &QPushButton::clicked, this, &MainWindow::on_pushButtonSelectImage_clicked);
    connect(ui->TxtKaydet, &QPushButton::clicked, this, &MainWindow::on_pushButtonSaveImage_clicked);
    //connect(ui->FotoKaydet, &QPushButton::clicked, this, &MainWindow::on_pushButtonYukle_clicked);
    //connect(ui->TxtKaydet, &QPushButton::clicked, this, &MainWindow::on_pushButtonKaydet_clicked);

}

MainWindow::~MainWindow()
{
    delete ui;
}

void MainWindow::on_pushButtonSelectImage_clicked()
{
    // Kullanıcının bir fotoğraf seçmesini sağlayan dosya seçici
    QString filePath = QFileDialog::getOpenFileName(this, "Resim Seç", "", "Resimler (*.png *.jpg *.bmp)");

    if (!filePath.isEmpty())
    {
        selectedImagePath = filePath;

        // Resmin önizlemesini QLabel'de gösterme
        QPixmap pixmap(filePath);
        ui->labelImage->setPixmap(pixmap.scaled(ui->labelImage->size(), Qt::KeepAspectRatio));
    }
}

void MainWindow::on_pushButtonSaveImage_clicked()
{
    if (selectedImagePath.isEmpty())
    {
        QMessageBox::warning(this, "Hata", "Önce bir resim seçmelisiniz!");
        return;
    }

    // Kaydetme yolu ve dosya adı
    QString savePath = QFileDialog::getSaveFileName(this, "Resmi Kaydet", "", "Resimler (*.png *.jpg *.bmp)");

    if (savePath.isEmpty())
    {
        QMessageBox::warning(this, "Hata", "Dosya yolu seçilmedi!");
        return;
    }

    // Resmi belirtilen yere kaydetme
    QFile::copy(selectedImagePath, savePath);

    QMessageBox::information(this, "Başarılı", "Resim başarıyla kaydedildi.");
}

/*
void MainWindow::on_pushButtonKaydet_clicked(){

    // Kullanıcıdan veri alma
    QString TcNo = ui->TcNo->text();
    QString ad = ui->AdSoyad->text();
    int yas = ui->Yas->value();
    QString MusabakaAd = ui->MusabakaAd->text();
    QString TribunAd = ui->TribunAd->text();
    QString KoltukNo = ui->KoltukNo->text();
    QString KapiNo = ui->KapiNo->text();

    // Verileri kaydetmek için dosya oluşturma
    QFile file("veriler.txt");

    // Dosyayı yazma modunda açma
    if(file.open(QIODevice::WriteOnly | QIODevice::Text))
    {
        QTextStream out(&file);

        // Verileri dosyaya yazma
        out << "Ad: " << ad << "\n";
        out << "Yaş: " << yas << "\n";
        out << "Müsabaka Adı: " << MusabakaAd << "\n";
        out << "Tribün Adı: " << TribunAd << "\n";
        out << "Koltuk No: " << KoltukNo << "\n";
        out << "Kapı No: " << KapiNo << "\n";


        file.close();

        // Başarı mesajı gösterme
        QMessageBox::information(this, "Başarılı", "Veriler başarıyla kaydedildi.");
    }
    else
    {
        // Hata mesajı gösterme
        QMessageBox::warning(this, "Hata", "Dosya açılamadı!");
    }
}
*/

/*
void MainWindow::on_pushButtonYukle_clicked()
{
    // Dosya seçme penceresi açma
    QString filePath = QFileDialog::getOpenFileName(this, "Fotoğraf Seç", "", "Resim Dosyaları (*.png *.jpg *.bmp)");

    if (!filePath.isEmpty()) {
        // Seçilen fotoğrafı QLabel üzerinde gösterme
        displayImage(filePath);
    }
}

void MainWindow::displayImage(const QString &filePath)
{
    QPixmap pixmap(filePath);
    ui->labelFoto->setPixmap(pixmap.scaled(ui->labelFoto->size(), Qt::KeepAspectRatio));
}
*/
