#include <QtWidgets>
#include "Interface.h"
#include "mainwindow1.h"
#include "OP/modelisationprblm.h"
#include "Queen/InterfaceQueen.h"
#include "VoyageurDeCommerce/interfaceVoyageur.h"

extern InterfaceQueen *game;

MainWindow1::MainWindow1()
{


    accueil = new Interface;


    setCentralWidget(accueil);
    accueil->setMinimumSize(800,600);
    accueil->setMaximumSize(800,600);

      QPixmap bkgnd("algo.jpg");

      QPalette palette;
      palette.setBrush(QPalette::Background, bkgnd);
      this->setPalette(palette);
    /*this->setStyleSheet("{background-image: url (/home/hameni/Bureau/algo.jpg)};");*/

    exitAct = new QAction(tr("E&xit"), this);
    exitAct->setShortcuts(QKeySequence::Quit);
    connect(exitAct, SIGNAL(triggered()), this, SLOT(close()));
    connect(accueil->quitter, SIGNAL(clicked()), this, SLOT(close()));
    connect(accueil->huits_dame, SIGNAL(clicked()), this, SLOT(huits_dames()));
    connect(accueil->modelisation, SIGNAL(clicked()), this, SLOT(modeli()));
    connect(accueil->voyageur, SIGNAL(clicked()), this, SLOT(voyageur()));

;
}
void MainWindow1::huits_dames()
{
    hide();

    game->show();


}
void MainWindow1::modeli()
{
  hide();
  ModelisationPrblm *p = new ModelisationPrblm();
  p->show();

}
void MainWindow1::voyageur(){
  
  hide();
  srand(unsigned(time(NULL)));
  qsrand(QTime(0,0,0).secsTo(QTime::currentTime()));
  voyageurDeCommerceInterface *vc = new voyageurDeCommerceInterface(this);
  vc->show();
}
