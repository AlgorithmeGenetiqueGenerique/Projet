#include "InterfaceQueen.h"
#include "bouton.h"
#include "./../mainwindow1.h"

#include <QDebug>

#include <QTextEdit>
#include <QCheckBox>
#include <QLineEdit>
#include <QTextBrowser>
#include <QDesktopServices>
#include <QObject>
#include <QtCore>

using namespace std;
InterfaceQueen::InterfaceQueen():QGraphicsView()
{

    //Making the Scene
    Scene_du_jeu = new QGraphicsScene();
    Scene_du_jeu->setSceneRect(530,200,500,500);
    Scene = new QGraphicsScene();                qDebug()<<"-------->";

    Scene->setSceneRect(200,200,500,500);
    //Making the view
    setFixedSize(1200,850);
   setHorizontalScrollBarPolicy(Qt::ScrollBarAlwaysOff);
    setVerticalScrollBarPolicy(Qt::ScrollBarAlwaysOff);
   setScene(Scene_du_jeu);

   op = operationsGenetiques(&individus, ee.getMaximisationMinimisation(), ee.getNmbr_indiv_a_selec());
    //setScene(Scene);
    QBrush brush;
    brush.setStyle(Qt::SolidPattern);
    brush.setColor(Qt::lightGray);
    setBackgroundBrush(brush);
   //display Check
    check = new QGraphicsTextItem();
    check->setPos(width()/2-100,860);

    enCours = 0;


}




void InterfaceQueen::removeFromScene(QGraphicsItem *item)
{
    Scene_du_jeu->removeItem(item);

}
void InterfaceQueen::DessinerEchiquier()
{
    Echiquiers = new Echiquier();

    QBrush brush;
    brush.setStyle(Qt::SolidPattern);
    brush.setColor(Qt::lightGray);
    QBrush brush1;
    brush1.setStyle(Qt::SolidPattern);
    brush1.setColor(Qt::lightGray);
    Echiquiers->Dessiner_box(width()/2-410,55);
    int** echiquier1;
            echiquier1 = (int**) malloc(sizeof(*echiquier1) * 8);
            for (int i=0;i<8;i++){
                echiquier1[i] = (int*)malloc(sizeof(**echiquier1)*8);
            }
            for(int i=0;i<8;i++)
            {
               for(int j=0;j<8;j++)
               {
                   echiquier1[i][j]=0;
               }
           }
            echiquier1[4][1]=1;echiquier1[4][3]=1;echiquier1[4][5]=1;echiquier1[4][7]=1;echiquier1[4][0]=1;
            echiquier1[4][4]=1;echiquier1[4][2]=1;
            echiquier1[4][6]=1;
            Echiquiers->AjouterPiece(echiquier1);




}
void InterfaceQueen::AjouterSurScene(QGraphicsItem *item)
{
    Scene_du_jeu->addItem(item);
}

void InterfaceQueen::start()
{
    if(thrd->Stop==true)
    {
        enCours=1;
 thrd->count=0;
        QGraphicsTextItem *Piece = new QGraphicsTextItem();
        thrd->test=2;
        Piece->setPos(1200,10);
        Piece->setZValue(1);
        Piece->setDefaultTextColor(Qt::black);
        Piece->setFont(QFont("",14));
        AjouterSurScene(Piece);


        srand(unsigned(time(NULL)));  vector<int> score_total;

        thrd->Stop=false;

        compteur_generation=0;
        sb = text->verticalScrollBar();
        thrd->iteration=2500;
        sb =text->verticalScrollBar();text->insertPlainText("Debut de la simulation");
        thrd->start();
        text->insertPlainText("\n");
        enCours=0;
    }
    
}

void InterfaceQueen::onTxtEdt(int j)//Thread
{
 vector<ProblemeDesHuitDames> dames1;
    if(j!=0)
    {
    Echiquiers->reset();
    }
    if(!j){
        individus.clear();dames.clear();
        for (int i = 0; i< ee.getTaillePopulation(); i++){
            individu individu_x;
            do{
            individu_x =individu(0,63,8,1);
            }while ((individu_x.ADN.genes_int[0] == individu_x.ADN.genes_int[1])||(individu_x.ADN.genes_int[0] == individu_x.ADN.genes_int[2])||(individu_x.ADN.genes_int[0] == individu_x.ADN.genes_int[3])||(individu_x.ADN.genes_int[0] == individu_x.ADN.genes_int[4])||(individu_x.ADN.genes_int[0] == individu_x.ADN.genes_int[5])||(individu_x.ADN.genes_int[0] == individu_x.ADN.genes_int[6])||(individu_x.ADN.genes_int[0] == individu_x.ADN.genes_int[7])||(individu_x.ADN.genes_int[1] == individu_x.ADN.genes_int[2])||(individu_x.ADN.genes_int[1] == individu_x.ADN.genes_int[3])||(individu_x.ADN.genes_int[1] == individu_x.ADN.genes_int[4])||(individu_x.ADN.genes_int[1] == individu_x.ADN.genes_int[3])||(individu_x.ADN.genes_int[1] == individu_x.ADN.genes_int[5])||(individu_x.ADN.genes_int[6] == individu_x.ADN.genes_int[7])||(individu_x.ADN.genes_int[2] == individu_x.ADN.genes_int[3])||(individu_x.ADN.genes_int[2] == individu_x.ADN.genes_int[4])||(individu_x.ADN.genes_int[2] == individu_x.ADN.genes_int[5])||(individu_x.ADN.genes_int[2] == individu_x.ADN.genes_int[6])||(individu_x.ADN.genes_int[2] == individu_x.ADN.genes_int[7])|| (individu_x.ADN.genes_int[3] == individu_x.ADN.genes_int[4])||(individu_x.ADN.genes_int[3] == individu_x.ADN.genes_int[5])||(individu_x.ADN.genes_int[3] == individu_x.ADN.genes_int[6])||(individu_x.ADN.genes_int[3] == individu_x.ADN.genes_int[7])||(individu_x.ADN.genes_int[4] == individu_x.ADN.genes_int[5])||(individu_x.ADN.genes_int[4] == individu_x.ADN.genes_int[6])||(individu_x.ADN.genes_int[4] == individu_x.ADN.genes_int[7])||(individu_x.ADN.genes_int[5] == individu_x.ADN.genes_int[6])||(individu_x.ADN.genes_int[5] == individu_x.ADN.genes_int[7])||(individu_x.ADN.genes_int[6] == individu_x.ADN.genes_int[7]));
            individus.push_back(individu_x);
            dames.push_back(ProblemeDesHuitDames(&individus[i]));
            dames[i].detection_position(0);
            dames[i].verification_solution();
            evaluation e = evaluation (ee.getChaineEvaluation());
            e.evaluer(&individus[i]);


        }
        evaluation e = evaluation (ee.getChaineEvaluation());

    }

    //if (arret) break;
    int alpha=0;
    int beta=individus[0].getNoteEvaluation();

for (int i = 0; i< ee.getTaillePopulation(); i++)
{
    if(beta > individus[i].getNoteEvaluation())
    {
        beta=individus[i].getNoteEvaluation();
        alpha=i;
    }
}
for (int i = 0; i< ee.getTaillePopulation(); i++)
{
    for(int j=0;j<8;j++) {individus[i].ADN.genes_int[j]=individus[i].ADN.genes_int[j]/10;}
    individu individu_x=individus[i];
dames1.push_back(dames[i]);

}
dames1[alpha].generation_echiquier();
int x = individus[alpha].getNoteEvaluation();

 Echiquiers->AjouterPiece(dames1[alpha].getech());
 if(x!=0)
 {
text->insertPlainText("generation : "+QString::number(compteur_generation));
text->insertPlainText("\n");
 }
 if(x==0)
 {

     text->insertPlainText("generation : "+QString::number(compteur_generation));
    text->insertPlainText("\nFin de la simulation \n");
     dames[alpha].generation_echiquier();
     dames[alpha].printSolution();
      Echiquiers->AjouterPiece(dames[alpha].getech());
     thrd->Stop=true;


 }


//-------------------------Sélection---------------
op.selectionParTournoi();
compteur_generation=compteur_generation + 1;
//-------------------------Croisement---------------

op.croisement(ee.getTauxCroisement(), ee.getTauxMutation(), ee.getTaillePopulation(), ee.getChaineEvaluation());
dames.clear();
for (int i = 0; i< ee.getTaillePopulation(); i++)
{
    while((individus[i].ADN.genes_int[0] == individus[i].ADN.genes_int[1])||(individus[i].ADN.genes_int[0] == individus[i].ADN.genes_int[2])||(individus[i].ADN.genes_int[0] == individus[i].ADN.genes_int[3])||(individus[i].ADN.genes_int[0] == individus[i].ADN.genes_int[4])||(individus[i].ADN.genes_int[0] == individus[i].ADN.genes_int[5])||(individus[i].ADN.genes_int[0] == individus[i].ADN.genes_int[6])||(individus[i].ADN.genes_int[0] == individus[i].ADN.genes_int[7])||(individus[i].ADN.genes_int[1] == individus[i].ADN.genes_int[2])||(individus[i].ADN.genes_int[1] == individus[i].ADN.genes_int[3])||(individus[i].ADN.genes_int[1] == individus[i].ADN.genes_int[4])||(individus[i].ADN.genes_int[1] == individus[i].ADN.genes_int[5])||(individus[i].ADN.genes_int[1] == individus[i].ADN.genes_int[6])||(individus[i].ADN.genes_int[1] == individus[i].ADN.genes_int[7])||(individus[i].ADN.genes_int[2] == individus[i].ADN.genes_int[3])||(individus[i].ADN.genes_int[2] == individus[i].ADN.genes_int[4])||(individus[i].ADN.genes_int[2] == individus[i].ADN.genes_int[5])||(individus[i].ADN.genes_int[2] == individus[i].ADN.genes_int[6])||(individus[i].ADN.genes_int[2] == individus[i].ADN.genes_int[7])|| (individus[i].ADN.genes_int[3] == individus[i].ADN.genes_int[4])||(individus[i].ADN.genes_int[3] == individus[i].ADN.genes_int[5])||(individus[i].ADN.genes_int[3] == individus[i].ADN.genes_int[6])||(individus[i].ADN.genes_int[3] == individus[i].ADN.genes_int[7])||(individus[i].ADN.genes_int[4] == individus[i].ADN.genes_int[5])||(individus[i].ADN.genes_int[4] == individus[i].ADN.genes_int[6])||(individus[i].ADN.genes_int[4] == individus[i].ADN.genes_int[7])||(individus[i].ADN.genes_int[5] == individus[i].ADN.genes_int[6])||(individus[i].ADN.genes_int[5] == individus[i].ADN.genes_int[7])||(individus[i].ADN.genes_int[6] == individus[i].ADN.genes_int[7]))
    {
        individus[i]  =individu(0,63,8,1);
    }
    dames.push_back(ProblemeDesHuitDames(&individus[i]));
    dames[i].detection_position(0);
    dames[i].verification_solution();

}



    for (int i = 0; i < ee.getTaillePopulation() ; i++)
    {
        evaluation e = evaluation (ee.getChaineEvaluation());
        e.evaluer(&individus[i]);

    }
    evaluation e2 = evaluation (ee.getChaineEvaluation());

 //--------------------------------------------------------------------------------------------

    sb->setValue(sb->maximum());
    thrd->count=j;
}


void InterfaceQueen::connectAide(){
    QFile HelpFile("qrc:/Manuel.pdf");;
    HelpFile.copy(qApp->applicationDirPath().append("/Manuel.pdf"));
    QDesktopServices::openUrl(QUrl::fromLocalFile(qApp->applicationDirPath().append("/Manuel.pdf")));

}
void InterfaceQueen::connectAcceuil(){
if(thrd->Stop==false)
{

}else
{
MainWindow1 *mainWindow = new  MainWindow1();
   mainWindow->show();
   Echiquiers->reset();   thrd->Stop=false;text->deleteLater(); text = new QTextBrowser();
   individus.clear();
   dames.clear();
     thrd->test=0;
   layout->addWidget(text);close();
    }
}
void InterfaceQueen::fin()
{

                int reponse=QMessageBox::question(this,"Confirmer" ,"Etes-vous sûr de vouloir quitter?", QMessageBox::Yes | QMessageBox::No );
                if (reponse == QMessageBox::Yes)
                {
                    close();
                }

}
void InterfaceQueen::AffichageEchiquier()
{


    thrd=new myThread(this);
    thrd->Stop=true;
    thrd->test=2;
     QObject::connect(thrd,SIGNAL(txtEdt(int)),this,SLOT(onTxtEdt(int)));
    //create Button
    DessinerEchiquier();

     int pxPos =875;
    int pyPos = 27;
    playButton = new Bouton("Lancer la simulation");
    playButton->setPos(pxPos,pyPos);
    acceuil = new Bouton("Accueil");
     pxPos =200;
     pyPos = 27;
    acceuil->setPos(pxPos,pyPos);
    quitter= new Bouton("Quitter");
     pxPos =425;
     pyPos = 27;
    quitter->setPos(pxPos,pyPos);
    aide= new Bouton("Aide");
     pxPos =650;
     pyPos = 27;
    aide->setPos(pxPos,pyPos);

    a= new QWidget(); layout = new QVBoxLayout();
    a->setGeometry(1000,90,360,750);
    text = new QTextBrowser();

    layout->addWidget(text);
       a->setLayout(layout);
            Scene_du_jeu->addWidget(a);
               connect(playButton,SIGNAL(clicked()) , this , SLOT(start()));
            connect(quitter,SIGNAL(clicked()) , this , SLOT(fin()));
            connect(aide,SIGNAL(clicked()) , this , SLOT(connectAide()));
            connect(acceuil,SIGNAL(clicked()) , this , SLOT(connectAcceuil()));

    AjouterSurScene(playButton);
    AjouterSurScene(aide);
    AjouterSurScene(quitter);    AjouterSurScene(acceuil);





}


