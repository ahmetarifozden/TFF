#ifndef TEMPLATEWINDOW_H
#define TEMPLATEWINDOW_H

#include <QWidget>
#include <QVBoxLayout>

namespace Ui {
class TemplateWindow;
}

class TemplateWindow : public QWidget
{
    Q_OBJECT

public:
    explicit TemplateWindow(QWidget *parent = nullptr);
    ~TemplateWindow();

signals:
    void templateSaved(); // Sinyal tanımı

private slots:
    void handleAddField();
    void handleSave();  // JSON kaydetme işlevi için eklenen slot
    void setupUi();
    void addField(QVBoxLayout *layout);



private:
    Ui::TemplateWindow *ui;
   // void closeEvent(QCloseEvent *bar);
};

#endif // TEMPLATEWINDOW_H
