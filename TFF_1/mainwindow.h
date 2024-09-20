#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>
#include <QTextEdit>  // QTextEdit ekleyin
#include <QLineEdit>
#include "loggerwindow.h"  // Yeni eklenen satır
#include <QJsonObject>
#include <QNetworkAccessManager>

QT_BEGIN_NAMESPACE
namespace Ui { class MainWindow; }
QT_END_NAMESPACE

class MainWindow : public QMainWindow
{
    Q_OBJECT

    QNetworkAccessManager *networkManager;


public:
    explicit MainWindow(QWidget *parent = nullptr);
    ~MainWindow();
    void MyClear();
    static LoggerWindow *loggerWindow; // Static işaretçi
    void clearAll();



private slots:
    //void openTemplateWindow();
    //void openSettingsWindow();
    void onSendButtonClicked();
    void updateComboBox(const QString &folderPath);



private:
    Ui::MainWindow *ui;
    QJsonObject jsonObj; // JSON objesi üye değişkeni olarak tanımlandı
    void loadJsonFilesToTabs(const QString &folderPath);
    void addJsonToTab(const QString &tabName, const QJsonObject &jsonObj);
    QTextEdit *textEdit;  // Burada textEdit'i sınıf üyesi olarak tanımlayın
    void displayJsonFields(const QJsonObject &jsonObj);
    void sendJsonData(const QJsonObject &jsonObj);
    QMap<QString, QLineEdit*> inputFields;  // Dinamik olarak oluşturulan QLineEdit'leri saklamak için
    static void customMessageHandler(QtMsgType type, const QMessageLogContext &context, const QString &msg);
    void setupMessageHandler();
};

extern MainWindow *mainwindow;

#endif // MAINWINDOW_H
