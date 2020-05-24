#ifndef MODELISATION_H
#define MODELISATION_H

#include <QWidget>

namespace Ui {
class Modelisation;
}

class Modelisation : public QWidget
{
    Q_OBJECT

public:
    explicit Modelisation(QWidget *parent = nullptr);
    ~Modelisation();



private slots:
    void on_pushButton_3_clicked();

    void on_pushButton_5_clicked();

    void on_pushButton_4_clicked();

    void on_pushButton_10_clicked();

    void on_pushButton_9_clicked();

    void on_pushButton_11_clicked();

    void on_pushButton_8_clicked();

private:
    Ui::Modelisation *ui;
};

#endif // MODELISATION_H
