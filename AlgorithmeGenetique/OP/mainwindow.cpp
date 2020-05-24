#include "mainwindow.h"
#include "ui_mainwindow.h"

MainWindow::MainWindow(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::MainWindow)
{
    ui->setupUi(this);
    nombre_genes=new QSpinBox;
    nombre_genes->setMaximum(8);
    nombre_genes->setMinimum(1);
    nombre_genes->setValue(50);
    nombre_genes->show();
    nombre_genes->setParent(this);
}

MainWindow::~MainWindow()
{
    delete ui;
}

