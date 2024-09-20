#include "loggerwindow.h"
#include <QVBoxLayout> // QVBoxLayout kullanımı için gerekli
#include <QDateTime>
#include <QDir>
LoggerWindow::LoggerWindow(QWidget *parent) : QWidget(parent)
{
    logTextEdit = new QTextEdit(this);
    logTextEdit->setReadOnly(true);

    QVBoxLayout *layout = new QVBoxLayout(this);
    layout->addWidget(logTextEdit);
    setLayout(layout);

    // Log dosyasını başlat
    initializeLogFile();
}

LoggerWindow::~LoggerWindow()
{
    // Log dosyasını kapat
    logFile.close();
}

void LoggerWindow::initializeLogFile()
{
    // Dosya adını tarih ve saate göre oluştur
    QString logDir = "C:/Users/Arif/Documents/TFF_3_new_1/TFF_3/Logger";
    QDir().mkpath(logDir); // Eğer yoksa klasörü oluşturur

    QString timestamp = QDateTime::currentDateTime().toString("yyyy-MM-dd_HH-mm-ss");
    QString logFileName = QString("%1/log_%2.txt").arg(logDir).arg(timestamp);

    logFile.setFileName(logFileName);

    if (logFile.open(QIODevice::Append | QIODevice::Text)) {
        logStream.setDevice(&logFile);
    } else {
        qWarning() << "Log dosyası açılamadı: " << logFileName;
    }
}

void LoggerWindow::addLogMessage(const QString &message)
{
    QString timestamp = QDateTime::currentDateTime().toString("yyyy-MM-dd HH:mm:ss");
    QString fullMessage = QString("[%1] %2").arg(timestamp).arg(message);

    logTextEdit->append(fullMessage);

    // Mesajı dosyaya yaz
    if (logStream.device()) {
        logStream << fullMessage << "\n";
        logStream.flush();  // Dosyaya hemen yazılması için
    }
}

/*
void LoggerWindow::addLogMessage(const QString &message)
{
    //logTextEdit->append(message);
    QString timestamp = QDateTime::currentDateTime().toString("yyyy-MM-dd HH:mm:ss");
    QString fullMessage = QString("[%1] %2").arg(timestamp).arg(message);
    logTextEdit->append(fullMessage);
}
*/
