/*#ifndef LOGGERWINDOW_H
#define LOGGERWINDOW_H

#include <QWidget>

namespace Ui {
class LoggerWindow;
}

class LoggerWindow : public QWidget
{
    Q_OBJECT

public:
    explicit LoggerWindow(QWidget *parent = nullptr);
    ~LoggerWindow();

private:
    Ui::LoggerWindow *ui;
};

#endif // LOGGERWINDOW_H
*/

#ifndef LOGGERWINDOW_H
#define LOGGERWINDOW_H

#include <QWidget>
#include <QTextEdit>
#include <QFile>
#include <QTextStream>

class LoggerWindow : public QWidget
{
    Q_OBJECT

public:
    explicit LoggerWindow(QWidget *parent = nullptr);
    ~LoggerWindow();

    void addLogMessage(const QString &message);

private:
    QTextEdit *logTextEdit;
    QFile logFile;
    QTextStream logStream;

    void initializeLogFile();
};

#endif // LOGGERWINDOW_H
