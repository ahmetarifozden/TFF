#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>
#include <QNetworkAccessManager>
#include <QNetworkReply>
#include <QNetworkRequest>
#include <QFile>
#include <QFileDialog>
#include <QJsonDocument>
#include <QJsonObject>
#include <QJsonArray>
#include <QImage>
#include <QImageWriter>
#include <QBuffer>

QT_BEGIN_NAMESPACE
namespace Ui { class MainWindow; }
QT_END_NAMESPACE

class MainWindow : public QMainWindow
{
    Q_OBJECT

public:
    MainWindow(QWidget *parent = nullptr);
    ~MainWindow();

private slots:
    void on_pushButtonSelectImage_clicked();
    void on_pushButtonSubmit_clicked();
    void on_networkReplyFinished(QNetworkReply* reply);

private:
    Ui::MainWindow *ui;
    QNetworkAccessManager *networkManager;
    QString selectedImagePath;

    void sendDataToApi();
};

#endif // MAINWINDOW_H
