#include "mainwindow.h"
#include "ui_mainwindow.h"
#include <QFile>
#include <QTextStream>
#include <QMessageBox>

MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::MainWindow)
{
    ui->setupUi(this);

    // "Kaydet" butonuna tıklama olayını bağlama
    connect(ui->pushButtonKaydet, &QPushButton::clicked, this, &MainWindow::on_pushButtonKaydet_clicked);
}

MainWindow::~MainWindow()
{
    delete ui;
}

void MainWindow::on_pushButtonKaydet_clicked()
{
    // Kullanıcıdan veri alma
    QString ad = ui->lineEdit->text();
    int yas = ui->spinBox->value();

    // Verileri kaydetmek için dosya oluşturma
    QFile file("veriler.txt");

    // Dosyayı yazma modunda açma
    if(file.open(QIODevice::WriteOnly | QIODevice::Text))
    {
        QTextStream out(&file);

        // Verileri dosyaya yazma
        out << "Ad: " << ad << "\n";
        out << "Yaş: " << yas << "\n";

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
