#include "notebad.h"
#include <QFontDialog>
#include "ui_notepad.h"

notepad::notepad(QWidget *parent) :


    QMainWindow(parent),


    ui(new Ui::notepad)
{
    ui->setupUi(this);

    this->setCentralWidget(ui->textEdit);
}


notepad::~notepad()
{
    delete ui;
}

void notepad::on_actionNew_triggered()
{

    currentFile.clear();


    ui->textEdit->setText(QString());
}


void notepad::on_actionOpen_triggered()
{

    QString fileName = QFileDialog::getOpenFileName(this, "Ouvrir le fichier");


    QFile file(fileName);


    currentFile = fileName;



    if (!file.open(QIODevice::ReadOnly | QFile::Text)) {
        QMessageBox::warning(this, "Erreur", "Impossible d'ouvrir le fichier: " + file.errorString());
        return;
    }


    setWindowTitle(fileName);


    QTextStream in(&file);


    QString text = in.readAll();


    ui->textEdit->setText(text);


    file.close();
}



void notepad::on_actionSave_as_triggered()
{

    QString fileName = QFileDialog::getSaveFileName(this, "Sauvegarder sous");


    QFile file(fileName);


    if (!file.open(QFile::WriteOnly | QFile::Text)) {
        QMessageBox::warning(this, "Erreur", "Impossible de sauvegarder le fichier: " + file.errorString());
        return;
    }


    currentFile = fileName;


    setWindowTitle(fileName);


    QTextStream out(&file);


    QString text = ui->textEdit->toPlainText();


    out << text;


    file.close();
}

void notepad::on_actionSave_triggered()
{
    QString fileName = QFileDialog::getSaveFileName(this, "Sauvegarder");
    QFile file(fileName);
    if (!file.open(QFile::WriteOnly | QFile::Text)) {
        QMessageBox::warning(this, "Erreur", "Impossible de sauvegarder le fichier: " + file.errorString());
        return;
    }
    currentFile = fileName;
    setWindowTitle(fileName);
    QTextStream out(&file);
    QString text = ui->textEdit->toPlainText();
    out << text;
    file.close();
}

void notepad::on_actionPrint_triggered()
{

  /*  QPrinter printer(QPrinter::ScreenResolution);


    printer.setPrinterName("Nom de l'imprimente");


    QPrintDialog pDialog(&printer, this);

    if(pDialog.exec() == QDialog::Rejected){
        QMessageBox::warning(this, "Erreur", "Impossible d'accéder à l'imprimante");
        return;
    }


    ui->textEdit->print(&printer);*/

}

void notepad::on_actionExit_triggered()
{
    this->close();
}


void notepad::on_actionCopy_triggered()
{
    ui->textEdit->copy();
}

void notepad::on_actionCut_triggered()
{
    ui->textEdit->cut();
}

void notepad::on_actionPaste_triggered()
{
    ui->textEdit->paste();
}

void notepad::on_actionUndo_triggered()
{
    ui->textEdit->undo();
}

void notepad::on_actionRedo_triggered()
{
    ui->textEdit->redo();
}


void notepad::on_actionSelectFont_triggered()
{
    bool fontSelected;
    QFont font = QFontDialog::getFont(&fontSelected, this);
    if (fontSelected)
        ui->textEdit->setFont(font);
}


void notepad::on_actionsetFontUnderline_triggered(bool underline)
{
    ui->textEdit->setFontUnderline(underline);
}

void notepad::on_actionsetFontItalic_triggered(bool italic)
{
    ui->textEdit->setFontItalic(italic);
}

void notepad::on_actionBold_triggered(bool bold)
{
    bold ? ui->textEdit->setFontWeight(QFont::Bold) :
           ui->textEdit->setFontWeight(QFont::Normal);
}






