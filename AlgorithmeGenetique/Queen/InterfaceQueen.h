#ifndef GAME_H
#define GAME_H
#include <iostream>
#include <time.h>
#include "./../OP/operationsgenetiques.h"
#include <QMainWindow>
#include <QFile>
#include <QFileDialog>
#include <QTextStream>
#include <QMessageBox>
#include <QApplication>
#include "ProblemeDesHuitDames.h"
#include <QGraphicsView>
#include <QGraphicsScene>
#include "Echiquier.h"
#include<QPushButton>
#include <QSpinBox>
#include <QVBoxLayout>
#include <QGroupBox>
#include <QRadioButton>
#include <QTextEdit>
#include <QScrollBar>
#include <QTextBrowser>

#include <QLabel>
#include "Piece.h"
#include "bouton.h"
#include "./../OP/mythread.h"
#include "./../OP/EntreesSorties.h"
#include<QKeyEvent>
class InterfaceQueen:public QGraphicsView
{
    Q_OBJECT
public:
    //Constructors
    InterfaceQueen();
    //public Methods
    void DessinerEchiquier();
    void removeFromScene(QGraphicsItem *item);
 myThread *thrd;
    //Scene Related
    void AjouterSurScene(QGraphicsItem *item);
    BoxEchiquier *collection[8][8];
    QGraphicsTextItem *check;
    QList <Piece *> alivePiece;
     EntreesSorties ee = EntreesSorties("a%10+b%10+c%10+d%10+w%10+x%10+y%10+z%10", 2048, 300, 1500, 1 , 8, 0.1, 0.7, 200, 1, 0, 63, 2);
      operationsGenetiques op=   op = operationsGenetiques(&individus, ee.getMaximisationMinimisation(), ee.getNmbr_indiv_a_selec());;
    void AffichageEchiquier();
   //Thread
    void RetirerPiece();
public slots:
    void start();
    void fin();
    void connectAide();
    void connectAcceuil();
    void onTxtEdt(int j);

private:
     QScrollBar *sb;
    QGraphicsScene *Scene,*Scene_du_jeu;
    QGraphicsTextItem *s;
    Echiquier *Echiquiers;
     QVBoxLayout *layout;

    //QSpinBox *nombre_genes;
    int selection;
    int enCours;
    int compteur_generation ;
    std::vector<individu> individus;
    std::vector<ProblemeDesHuitDames> dames;


    QWidget *a;
    QTextBrowser *text;
    QVBoxLayout *layout_nombre_iterations;
    QLabel *label_nombre_iterations;
    QVBoxLayout *layout_maximisation_minimisation;
    QVBoxLayout *layout_maximisation_minimisation_principale;
    QGroupBox* maximisation_minimisation;
    QRadioButton* minimisation;

    //vector<individu> individus;
    Bouton *acceuil;
    Bouton *aide;
    Bouton *quitter;
    Bouton *playButton;



};

#endif // GAME_H
