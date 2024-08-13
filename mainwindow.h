#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>
#include <QImage>


QT_BEGIN_NAMESPACE
namespace Ui {class MainWindow;}
QT_END_NAMESPACE

class MainWindow : public QMainWindow
{
    Q_OBJECT

public:
    MainWindow(QWidget *parent = nullptr);
    ~MainWindow();

private slots:
    void on_pushButtonSelectImage_clicked();
    void on_pushButtonSaveImage_clicked();
    // void on_pushButtonYukle_clicked();
    //void on_pushButtonKaydet_clicked();

private:
    Ui::MainWindow *ui;
    QString selectedImagePath;
    //void displayImage(const QString &filePath);
};
#endif // MAINWINDOW_H
