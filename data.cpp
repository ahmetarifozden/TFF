#include <QNetworkAccessManager>
#include <QNetworkRequest>
#include <QNetworkReply>
#include <QJsonObject>
#include <QJsonDocument>
#include <QJsonDocument>
#include <QMainWindow>

class MainWindow : public QMainWindow
{
    Q_OBJECT

public:
    MainWindow(QWidget *parent = nullptr);
    ~MainWindow();

private slots:
    void on_pushButtonKaydet_clicked();

private:
    Ui::MainWindow *ui;
    QNetworkAccessManager *manager;  // HTTP istekleri için kullanılacak

    void sendDataToAPI(const QString &ad, int yas);
};

MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::MainWindow)
{
    ui->setupUi(this);
    manager = new QNetworkAccessManager(this);  // HTTP isteklerini yönetmek için manager nesnesi
    connect(ui->pushButtonKaydet, &QPushButton::clicked, this, &MainWindow::on_pushButtonKaydet_clicked);
}


void MainWindow::on_pushButtonKaydet_clicked()
{
    // Kullanıcıdan veri alma
    QString ad = ui->lineEditAd->text();
    int yas = ui->spinBoxYas->value();

    // Verileri API'ye gönderme fonksiyonunu çağır
    sendDataToAPI(ad, yas);
}

void MainWindow::sendDataToAPI(const QString &ad, int yas)
{
    // JSON verisi oluşturma
    QJsonObject json;
    json["ad"] = ad;
    json["yas"] = yas;

    QJsonDocument doc(json);
    QByteArray data = doc.toJson();

    // API'ye POST isteği gönderme
    QNetworkRequest request(QUrl("https://api.example.com/kullanici"));
    request.setHeader(QNetworkRequest::ContentTypeHeader, "application/json");

    QNetworkReply *reply = manager->post(request, data);

    // Yanıtı işlemek için
    connect(reply, &QNetworkReply::finished, [reply, this]() {
        if (reply->error() == QNetworkReply::NoError) {
            // Başarılı bir yanıt alındı
            QByteArray response_data = reply->readAll();
            qDebug() << "API yanıtı:" << response_data;
            QMessageBox::information(this, "Başarılı", "Veriler API'ye başarıyla gönderildi.");
        } else {
            // Hata oluştu
            qDebug() << "API hatası:" << reply->errorString();
            QMessageBox::warning(this, "Hata", "API'ye veri gönderme başarısız oldu.");
        }
        reply->deleteLater();  // Bellek sızıntısını önlemek için
    });
}
