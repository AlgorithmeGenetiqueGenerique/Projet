#include "modelisation.h"
#include "ui_modelisation.h"

Modelisation::Modelisation(QWidget *parent) :
    QWidget(parent),
    ui(new Ui::Modelisation)
{
    ui->setupUi(this);
}

Modelisation::~Modelisation()
{
    delete ui;
}


void Modelisation::on_pushButton_3_clicked()
{
    ui->stackedWidget->setCurrentIndex(2);
}

void Modelisation::on_pushButton_5_clicked()
{
    ui->stackedWidget->setCurrentIndex(0);
}

void Modelisation::on_pushButton_4_clicked()
{
    ui->stackedWidget->setCurrentIndex(1);
    ui->lineEdit->setText("0");
    ui->lineEdit_2->setText("0");
    ui->lineEdit_3->setText("0");
}

void Modelisation::on_pushButton_10_clicked()
{
    ui->stackedWidget->setCurrentIndex(0);
}

void Modelisation::on_pushButton_9_clicked()
{
    ui->stackedWidget->setCurrentIndex(3);
}

void Modelisation::on_pushButton_11_clicked()
{
    ui->stackedWidget->setCurrentIndex(0);
}

void Modelisation::on_pushButton_8_clicked()
{
    ui->stackedWidget->setCurrentIndex(4);
}
