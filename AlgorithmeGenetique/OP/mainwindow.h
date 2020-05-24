#ifndef MAINWINDOW_H
#define MAINWINDOW_H
#include <QMainWindow>
#include <QSpinBox>

namespace Ui {
class MainWindow;
}

class MainWindow : public QMainWindow
{
    Q_OBJECT

public:
    explicit MainWindow(QWidget *parent = nullptr);
    ~MainWindow();

private slots:
    void on_toolButton_Sauvgarder_clicked(bool checked);

private:
    Ui::MainWindow *ui;
    QSpinBox *nombre_genes;
};

#endif // MAINWINDOW_H
