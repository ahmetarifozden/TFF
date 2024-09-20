#include "templatewindow.h"
#include "mainwindow.h"
#include "ui_templatewindow.h"
#include <QComboBox>
#include <QLineEdit>
#include <QGridLayout>
#include <QJsonDocument>
#include <QJsonObject>
#include <QJsonArray>
#include <QFile>
#include <QFileDialog>
#include <QMessageBox>
#include <QInputDialog>
#include <QDir>

TemplateWindow::TemplateWindow(QWidget *parent) :
    QWidget(parent),
    ui(new Ui::TemplateWindow)
{
    ui->setupUi(this);

    // addButton'a tıklandığında handleAddField fonksiyonunu çalıştır
    connect(ui->addButton, &QPushButton::clicked, this, &TemplateWindow::handleAddField);
    // saveButton'a tıklandığında handleSave fonksiyonunu çalıştır
    connect(ui->saveButton, &QPushButton::clicked, this, &TemplateWindow::handleSave);
}

TemplateWindow::~TemplateWindow()
{
    delete ui;
}

void TemplateWindow::handleAddField()
{
    QComboBox *comboBox = new QComboBox();
    comboBox->addItem("String");
    comboBox->addItem("Integer");
    comboBox->addItem("Image");

    QLineEdit *lineEdit = new QLineEdit();

    QPushButton *deleteButton = new QPushButton("Sil");

    QGridLayout *gridLayout = qobject_cast<QGridLayout*>(ui->formWidget->layout());
    if (!gridLayout) {
        gridLayout = new QGridLayout(ui->formWidget);
        ui->formWidget->setLayout(gridLayout);
    }

    int rowCount = gridLayout->rowCount();

    gridLayout->addWidget(comboBox, rowCount, 0);
    gridLayout->addWidget(lineEdit, rowCount, 1);
    gridLayout->addWidget(deleteButton, rowCount, 2);

    // "Sil" butonunun tıklanma olayını ilgili satırı silen bir lambda fonksiyonuna bağlayın
    connect(deleteButton, &QPushButton::clicked, this, [this, comboBox, lineEdit, deleteButton]() {
        QGridLayout *layout = qobject_cast<QGridLayout*>(ui->formWidget->layout());
        if (!layout)
            return;

        // Widget'ları grid layout'tan ve bellekten kaldır
        int row = layout->indexOf(comboBox) / layout->columnCount();
        layout->takeAt(layout->indexOf(comboBox))->widget()->deleteLater();
        layout->takeAt(layout->indexOf(lineEdit))->widget()->deleteLater();
        layout->takeAt(layout->indexOf(deleteButton))->widget()->deleteLater();

        // Satırları yeniden düzenleyin
        for (int i = row; i < layout->rowCount(); ++i) {
            for (int j = 0; j < layout->columnCount(); ++j) {
                QLayoutItem *item = layout->itemAtPosition(i + 1, j);
                if (item) {
                    layout->addWidget(item->widget(), i, j);
                }
            }
        }
    });
}


void TemplateWindow::handleSave()
{
    // Dosya adını kullanıcıdan alın
    QString fileName = QInputDialog::getText(this, tr("Şablon Adı"),
                                             tr("Lütfen bir şablon adı girin:"));

    if (fileName.isEmpty()) {
        QMessageBox::warning(this, tr("Hata"), tr("Dosya adı girilmedi."));
        qDebug() << "Hata, Dosya adı girilmedi.";
        return;
    }

    // Projenin çalışma dizininde "sablonlar" klasörünü kontrol et, yoksa oluştur
    QString folderPath = QDir::currentPath() + "/sablonlar";
    QDir dir;
    if (!dir.exists(folderPath)) {
        if (!dir.mkpath(folderPath)) {
            QMessageBox::warning(this, tr("Hata"), tr("Klasör oluşturulamadı: %1").arg(folderPath));
            qDebug() << "Hata, Klasör oluşturulamadı: " << folderPath;
            return;
        }
    }

    QString filePath = folderPath + "/" + fileName + ".json";
    int count = 1;

    // Aynı isimli bir dosya olup olmadığını kontrol et ve yeni bir isim oluştur
    while (QFile::exists(filePath)) {
        fileName = QString("%1_%2").arg(fileName).arg(count);
        filePath = folderPath + "/" + fileName + ".json";
        count++;
    }

    // JSON verilerini oluştur
    QJsonArray jsonArray;
    QGridLayout *gridLayout = qobject_cast<QGridLayout*>(ui->formWidget->layout());

    if (gridLayout) {
        for (int i = 1; i < gridLayout->rowCount(); ++i) {
            QComboBox *comboBox = qobject_cast<QComboBox*>(gridLayout->itemAtPosition(i, 0)->widget());
            QLineEdit *lineEdit = qobject_cast<QLineEdit*>(gridLayout->itemAtPosition(i, 1)->widget());

            if (comboBox && lineEdit) {
                QJsonObject jsonObject;
                jsonObject["name"] = lineEdit->text();  // Kullanıcının girdiği isim
                jsonObject["type"] = comboBox->currentText();  // Verinin tipi
                jsonArray.append(jsonObject);
            }
        }
    }

    QJsonObject rootObject;
    rootObject["fields"] = jsonArray;
    QJsonDocument jsonDoc(rootObject);

    // JSON verilerini dosyaya yaz
    QFile file(filePath);
    if (file.open(QIODevice::WriteOnly)) {
        file.write(jsonDoc.toJson());
        file.close();
        QMessageBox::information(this, tr("Başarılı"), tr("Şablon başarıyla kaydedildi."));
        qDebug() << fileName << "Şablon başarıyla kaydedildi.";
        emit templateSaved();

        // Bellekte oluşturulan alanları temizle
        QLayout *oldLayout = ui->formWidget->layout();
        if (oldLayout) {
            while (QLayoutItem *item = oldLayout->takeAt(0)) {
                delete item->widget();  // Widget'ı sil
                delete item;           // LayoutItem'ı sil
            }
            delete oldLayout;          // Eski layout'u serbest bırak
        }

        // Yeni bir layout oluştur ve formWidget'e ata
        QGridLayout *newLayout = new QGridLayout(ui->formWidget);
        ui->formWidget->setLayout(newLayout);
    } else {
        QMessageBox::warning(this, tr("Hata"), tr("Dosya kaydedilemedi."));
        qDebug() << "Hata, Dosya kaydedilemedi.";
    }

}
