#ifndef SETTINGSWINDOW_H
#define SETTINGSWINDOW_H

#include <QWidget>

namespace Ui {
class SettingsWindow;
}

class SettingsWindow : public QWidget
{
    Q_OBJECT

public:
    explicit SettingsWindow(QWidget *parent = nullptr);
    ~SettingsWindow();
    QString getApiServerAddress() const; // API sunucu adresini döndüren fonksiyon


private slots:
    void saveApiServerAddress(); // API sunucu adresini kaydeden slot

private:
    Ui::SettingsWindow *ui;
    QString apiServerAddress;  // API sunucu adresi için üye değişken

};

#endif // SETTINGSWINDOW_H
