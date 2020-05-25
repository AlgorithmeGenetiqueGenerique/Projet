#include "graphwidget.h"
#include "edge.h"
#include "node.h"
#include <math.h>

#include <QKeyEvent>

GraphWidget::GraphWidget(int nbSommets,QWidget *parent)
    : QGraphicsView(parent), timerId(0)
{
    QGraphicsScene *scene = new QGraphicsScene(this);
    scene->setSceneRect(-200, -200, 400, 400);
    setScene(scene);
    scale(qreal(2), qreal(2));
    setFixedSize(1560, 850);
    setWindowTitle(tr("voyageur de commerce"));
    nombre_sommets = nbSommets;
    initialisationGraph();
    if (nombre_sommets == 4){
        dessinGraphe4Sommets();
        scene->addItem(node1);
        scene->addItem(node2);
        scene->addItem(node3);
        scene->addItem(node4);
        scene->addItem(edge12);
         scene->addItem(edge23);
         scene->addItem(edge13);
          scene->addItem(edge14);
          scene->addItem(edge24);
           scene->addItem(edge34);
    }
    //________________________________________________________
    if (nombre_sommets == 5){
        dessinGraphe5Sommets();
        scene->addItem(node1);
        scene->addItem(node2);
        scene->addItem(node3);
        scene->addItem(node4);
           scene->addItem(node5);
    scene->addItem(edge12);
     scene->addItem(edge23);
     scene->addItem(edge13);
      scene->addItem(edge14);
      scene->addItem(edge15);
      scene->addItem(edge24);
       scene->addItem(edge25);
       scene->addItem(edge34);
         scene->addItem(edge35);
         scene->addItem(edge45);
    }
    //________________________________________________________
    if (nombre_sommets == 6){
        dessinGraphe6Sommets();
        scene->addItem(node1);
        scene->addItem(node2);
        scene->addItem(node3);
        scene->addItem(node4);
        scene->addItem(node5);
        scene->addItem(node6);
    scene->addItem(edge12);
     scene->addItem(edge23);
     scene->addItem(edge13);
      scene->addItem(edge14);
      scene->addItem(edge15);
      scene->addItem(edge16);
      scene->addItem(edge24);
       scene->addItem(edge25);
        scene->addItem(edge26);
       scene->addItem(edge34);
         scene->addItem(edge35);
          scene->addItem(edge36);
         scene->addItem(edge45);
          scene->addItem(edge46);
          scene->addItem(edge56);
    }
    if (nombre_sommets == 7){
        dessinGraphe7Sommets();
        scene->addItem(node1);
        scene->addItem(node2);
        scene->addItem(node3);
        scene->addItem(node4);
           scene->addItem(node5);
            scene->addItem(node6);
             scene->addItem(node7);
 scene->addItem(edge12);
  scene->addItem(edge23);
  scene->addItem(edge13);
   scene->addItem(edge14);
   scene->addItem(edge15);
   scene->addItem(edge16);
    scene->addItem(edge17);
   scene->addItem(edge24);
    scene->addItem(edge25);
     scene->addItem(edge26);
      scene->addItem(edge27);
    scene->addItem(edge34);
      scene->addItem(edge35);
       scene->addItem(edge36);
         scene->addItem(edge37);
      scene->addItem(edge45);
       scene->addItem(edge46);
           scene->addItem(edge47);
       scene->addItem(edge56);
        scene->addItem(edge57);
         scene->addItem(edge67);
    }

}
void GraphWidget::setSommets(int sommets){
    nombre_sommets = sommets;
}

void GraphWidget::initialisation4sommets(int edge12_, int edge13_, int edge14_, int edge23_, int edge24_, int edge34_){
        
        graph[0][0] = 0;
        graph[0][1] = edge12_;
        graph[0][2] = edge13_;
        graph[0][3] = edge14_;
        graph[1][0] = graph[0][1];
        graph[1][1] = 0;
        graph[1][2] = edge23_;
        graph[1][3] = edge24_;
        graph[2][0] = graph[0][2];
        graph[2][1] = graph[1][2];
        graph[2][2] = 0;
        graph[2][3] = edge34_;
        graph[3][0] = graph[0][3];
        graph[3][1] = graph[1][3];
        graph[3][2] = graph[2][3];
        graph[3][3] = 0;
        QString str1 = "";
        str1 = QString::number(graph[0][1]);
        label12->setText(str1);
        QString str2 = "";
        str2 = QString::number(graph[0][2]);
        label13->setText(str2);
        QString str3 = "";
        str3 = QString::number(graph[0][3]);
        label14->setText(str3);
        QString str4 = "";
        str4 = QString::number(graph[1][2]);
        label23->setText(str4);
        QString str5 = "";
        str5 = QString::number(graph[1][3]);
        label24->setText(str5);
        QString str6 = "";
        str6 = QString::number(graph[2][3]);
        label34->setText(str6);
        label12->show();
        label13->show();
        label14->show();
        label23->show();
        label24->show();
        label34->show();
}

void GraphWidget::afficherSolution()
{
    /* switch (event->key()) {
    case Qt::Key_Up:

        break;
    case Qt::Key_Down:
    { */
            int score_totale = 0;
            double score_totale_d = 0;
            int meilleur_premier;
            bool arret = false;
            vector<int> score_total;
            vector<double> score_total_d;
            vector<int> meillleur_individu;
            vector<double> meillleur_individu_d;
            vector<individu> individus; // Notre population
            int compteur_generation = 0;
            //-------------------------------------les affichages--------------------------------------
            string chaine_evaluation;
            if (nombre_sommets == 4) chaine_evaluation = "a+b+c+d";
            if (nombre_sommets == 5) chaine_evaluation = "a+b+c+d+w";
            if (nombre_sommets == 6) chaine_evaluation = "a+b+c+d+w+x";
            if (nombre_sommets == 7) chaine_evaluation = "a+b+c+d+w+x+y";
            EntreesSorties ee = EntreesSorties(chaine_evaluation, 2048, 1, 1500, 1, nombre_sommets, 0.05, 0.1, 0, 1, 0, nombre_sommets, 2);
             // 1.récuperer la taille de la matrice (nombre de sommets) :
int g1,g2,g3,g4,g5,g6,g7,poid =10000000;
            //-------------------------initialisations et évaluation---------------
            operationsGenetiques op = operationsGenetiques(&individus, ee.getMaximisationMinimisation(), ee.getNmbr_indiv_a_selec());
            for (int j = 0; j< ee.getNombreiterations(); j++){
                if(!j){
                    for (int i = 0; i< ee.getTaillePopulation(); i++){
                        if ((ee.getTypeGenes() == 1) || (ee.getTypeGenes() == 3)){
                            individu individu_x;
                            if (nombre_sommets == 4){
                            do{
                        individu_x = individu(0,4,4,1);
                        }while ((individu_x.ADN.genes_int[0] == individu_x.ADN.genes_int[1])||(individu_x.ADN.genes_int[0] == individu_x.ADN.genes_int[2])||(individu_x.ADN.genes_int[0] == individu_x.ADN.genes_int[3])||(individu_x.ADN.genes_int[1] == individu_x.ADN.genes_int[2])||(individu_x.ADN.genes_int[1] == individu_x.ADN.genes_int[3])||(individu_x.ADN.genes_int[2] == individu_x.ADN.genes_int[3]));
                        }
                           else if (nombre_sommets == 5){
                                do{
                                 individu_x = individu(0,5,5,1);
                                }while ((individu_x.ADN.genes_int[0] == individu_x.ADN.genes_int[1])||(individu_x.ADN.genes_int[0] == individu_x.ADN.genes_int[2])||(individu_x.ADN.genes_int[0] == individu_x.ADN.genes_int[3])||(individu_x.ADN.genes_int[0] == individu_x.ADN.genes_int[4])||(individu_x.ADN.genes_int[1] == individu_x.ADN.genes_int[2])||(individu_x.ADN.genes_int[1] == individu_x.ADN.genes_int[3])||(individu_x.ADN.genes_int[1] == individu_x.ADN.genes_int[4])||(individu_x.ADN.genes_int[2] == individu_x.ADN.genes_int[3])||(individu_x.ADN.genes_int[2] == individu_x.ADN.genes_int[4])||(individu_x.ADN.genes_int[3] == individu_x.ADN.genes_int[4]));
                            }
                          else  if (nombre_sommets == 6){
                                do{
                                 individu_x = individu(0,6,6,1);
                                }while ((individu_x.ADN.genes_int[0] == individu_x.ADN.genes_int[1])||(individu_x.ADN.genes_int[0] == individu_x.ADN.genes_int[2])||(individu_x.ADN.genes_int[0] == individu_x.ADN.genes_int[3])||(individu_x.ADN.genes_int[0] == individu_x.ADN.genes_int[4])||(individu_x.ADN.genes_int[0] == individu_x.ADN.genes_int[5])||(individu_x.ADN.genes_int[1] == individu_x.ADN.genes_int[2])||(individu_x.ADN.genes_int[1] == individu_x.ADN.genes_int[3])||(individu_x.ADN.genes_int[1] == individu_x.ADN.genes_int[4])||(individu_x.ADN.genes_int[1] == individu_x.ADN.genes_int[5])||(individu_x.ADN.genes_int[2] == individu_x.ADN.genes_int[3])||(individu_x.ADN.genes_int[2] == individu_x.ADN.genes_int[4])||(individu_x.ADN.genes_int[2] == individu_x.ADN.genes_int[5])||(individu_x.ADN.genes_int[3] == individu_x.ADN.genes_int[4])||(individu_x.ADN.genes_int[3] == individu_x.ADN.genes_int[5])||(individu_x.ADN.genes_int[4] == individu_x.ADN.genes_int[5]));
                            }
                            else  if (nombre_sommets == 7){
                                  do{
                                   individu_x = individu(0,7,7,1);
                                  }while ((individu_x.ADN.genes_int[0] == individu_x.ADN.genes_int[1])||(individu_x.ADN.genes_int[0] == individu_x.ADN.genes_int[2])||(individu_x.ADN.genes_int[0] == individu_x.ADN.genes_int[3])||(individu_x.ADN.genes_int[0] == individu_x.ADN.genes_int[4])||(individu_x.ADN.genes_int[0] == individu_x.ADN.genes_int[5])||(individu_x.ADN.genes_int[0] == individu_x.ADN.genes_int[6])||(individu_x.ADN.genes_int[1] == individu_x.ADN.genes_int[2])||(individu_x.ADN.genes_int[1] == individu_x.ADN.genes_int[3])||(individu_x.ADN.genes_int[1] == individu_x.ADN.genes_int[4])||(individu_x.ADN.genes_int[1] == individu_x.ADN.genes_int[5])||(individu_x.ADN.genes_int[1] == individu_x.ADN.genes_int[6])||(individu_x.ADN.genes_int[2] == individu_x.ADN.genes_int[3])||(individu_x.ADN.genes_int[2] == individu_x.ADN.genes_int[4])||(individu_x.ADN.genes_int[2] == individu_x.ADN.genes_int[5])||(individu_x.ADN.genes_int[2] == individu_x.ADN.genes_int[6])||(individu_x.ADN.genes_int[3] == individu_x.ADN.genes_int[4])||(individu_x.ADN.genes_int[3] == individu_x.ADN.genes_int[5])||(individu_x.ADN.genes_int[3] == individu_x.ADN.genes_int[6])||(individu_x.ADN.genes_int[4] == individu_x.ADN.genes_int[5])||(individu_x.ADN.genes_int[4] == individu_x.ADN.genes_int[6])||(individu_x.ADN.genes_int[5] == individu_x.ADN.genes_int[6]));
                              }
                        individus.push_back(individu_x);
                        }
                        int x,y,z,w,x5,x6,x7;
                        if (nombre_sommets == 4){
                    if (individus[i].ADN.genes_int[0] == 0){
                            x = graph[0][individus[i].ADN.genes_int[1]];
                        }
                        else if (individus[i].ADN.genes_int[0] == 1){
                        x = graph[1][individus[i].ADN.genes_int[1]];

                        }
                        else if (individus[i].ADN.genes_int[0]  == 2){
                            x = graph[2][individus[i].ADN.genes_int[1]];
                        }
                        else if (individus[i].ADN.genes_int[0]  == 3){
                            x = graph[3][individus[i].ADN.genes_int[1]];
                        }
                        //----------------------------------
                        if (individus[i].ADN.genes_int[1] == 0){
                            y = graph[0][individus[i].ADN.genes_int[2]];
                        }
                        else if (individus[i].ADN.genes_int[1] == 1){
                        y = graph[1][individus[i].ADN.genes_int[2]];

                        }
                        else if (individus[i].ADN.genes_int[1] == 2){
                            y = graph[2][individus[i].ADN.genes_int[2]];
                        }
                        else if (individus[i].ADN.genes_int[1] == 3){
                            y = graph[3][individus[i].ADN.genes_int[2]];
                        }
                        //----------------------------------
                        if (individus[i].ADN.genes_int[2] == 0){
                            z = graph[0][individus[i].ADN.genes_int[3]];
                        }
                        else if (individus[i].ADN.genes_int[2] == 1){
                            z = graph[1][individus[i].ADN.genes_int[3]];
                        }
                        else if (individus[i].ADN.genes_int[2] == 2){
                            z = graph[2][individus[i].ADN.genes_int[3]];                        }
                        else if (individus[i].ADN.genes_int[2] == 3){
                            z = graph[3][individus[i].ADN.genes_int[3]];
                        }
                        //----------------------------------
                        if (individus[i].ADN.genes_int[3] == 0){
                            w = graph[0][individus[i].ADN.genes_int[0]];
                        }
                        else if (individus[i].ADN.genes_int[3] == 1){
                        w = graph[1][individus[i].ADN.genes_int[0]];

                        }
                        else if (individus[i].ADN.genes_int[3] == 2){
                            w = graph[2][individus[i].ADN.genes_int[0]];
                        }
                        else if (individus[i].ADN.genes_int[3] == 3){
                            w = graph[3][individus[i].ADN.genes_int[0]];
                        }
                        }
                        //_______________---------------------------------------------____
                        else if (nombre_sommets == 5){
                            if (individus[i].ADN.genes_int[0] == 0){
                                    x = graph[0][individus[i].ADN.genes_int[1]];
                                }
                                else if (individus[i].ADN.genes_int[0] == 1){
                                x = graph[1][individus[i].ADN.genes_int[1]];

                                }
                                else if (individus[i].ADN.genes_int[0]  == 2){
                                    x = graph[2][individus[i].ADN.genes_int[1]];
                                }
                                else if (individus[i].ADN.genes_int[0]  == 3){
                                    x = graph[3][individus[i].ADN.genes_int[1]];
                                }
                            else if (individus[i].ADN.genes_int[0]  == 4){
                                x = graph[4][individus[i].ADN.genes_int[1]];
                            }
                                //----------------------------------
                                if (individus[i].ADN.genes_int[1] == 0){
                                    y = graph[0][individus[i].ADN.genes_int[2]];
                                }
                                else if (individus[i].ADN.genes_int[1] == 1){
                                y = graph[1][individus[i].ADN.genes_int[2]];

                                }
                                else if (individus[i].ADN.genes_int[1] == 2){
                                    y = graph[2][individus[i].ADN.genes_int[2]];
                                }
                                else if (individus[i].ADN.genes_int[1] == 3){
                                    y = graph[3][individus[i].ADN.genes_int[2]];
                                }
                                else if (individus[i].ADN.genes_int[1] == 4){
                                    y = graph[4][individus[i].ADN.genes_int[2]];
                                }
                                //----------------------------------
                                if (individus[i].ADN.genes_int[2] == 0){
                                    z = graph[0][individus[i].ADN.genes_int[3]];
                                }
                                else if (individus[i].ADN.genes_int[2] == 1){
                                    z = graph[1][individus[i].ADN.genes_int[3]];
                                }
                                else if (individus[i].ADN.genes_int[2] == 2){
                                    z = graph[2][individus[i].ADN.genes_int[3]];                        }
                                else if (individus[i].ADN.genes_int[2] == 3){
                                    z = graph[3][individus[i].ADN.genes_int[3]];
                                }
                                else if (individus[i].ADN.genes_int[2] == 4){
                                    z = graph[4][individus[i].ADN.genes_int[3]];
                                }
                                //----------------------------------
                                if (individus[i].ADN.genes_int[3] == 0){
                                    w = graph[0][individus[i].ADN.genes_int[4]];
                                }
                                else if (individus[i].ADN.genes_int[3] == 1){
                                w = graph[1][individus[i].ADN.genes_int[4]];

                                }
                                else if (individus[i].ADN.genes_int[3] == 2){
                                    w = graph[2][individus[i].ADN.genes_int[4]];
                                }
                                else if (individus[i].ADN.genes_int[3] == 3){
                                    w = graph[3][individus[i].ADN.genes_int[4]];
                                }
                                else if (individus[i].ADN.genes_int[3] == 4){
                                    w = graph[4][individus[i].ADN.genes_int[4]];
                                }
                                //----------------------------------
                                if (individus[i].ADN.genes_int[4] == 0){
                                    x5 = graph[0][individus[i].ADN.genes_int[0]];
                                }
                                else if (individus[i].ADN.genes_int[4] == 1){
                                x5 = graph[1][individus[i].ADN.genes_int[0]];

                                }
                                else if (individus[i].ADN.genes_int[4] == 2){
                                    x5 = graph[2][individus[i].ADN.genes_int[0]];
                                }
                                else if (individus[i].ADN.genes_int[4] == 3){
                                    x5 = graph[3][individus[i].ADN.genes_int[0]];
                                }
                                else if (individus[i].ADN.genes_int[4] == 4){
                                    x5 = graph[4][individus[i].ADN.genes_int[0]];
                                }
                        }
                       //-----------_____________-------------------
                        else if (nombre_sommets == 6){
                            if (individus[i].ADN.genes_int[0] == 0){
                                    x = graph[0][individus[i].ADN.genes_int[1]];
                                }
                                else if (individus[i].ADN.genes_int[0] == 1){
                                x = graph[1][individus[i].ADN.genes_int[1]];

                                }
                                else if (individus[i].ADN.genes_int[0]  == 2){
                                    x = graph[2][individus[i].ADN.genes_int[1]];
                                }
                                else if (individus[i].ADN.genes_int[0]  == 3){
                                    x = graph[3][individus[i].ADN.genes_int[1]];
                                }
                            else if (individus[i].ADN.genes_int[0]  == 4){
                                x = graph[4][individus[i].ADN.genes_int[1]];
                            }
                            else if (individus[i].ADN.genes_int[0]  == 5){
                                x = graph[5][individus[i].ADN.genes_int[1]];
                            }
                                //----------------------------------
                                if (individus[i].ADN.genes_int[1] == 0){
                                    y = graph[0][individus[i].ADN.genes_int[2]];
                                }
                                else if (individus[i].ADN.genes_int[1] == 1){
                                y = graph[1][individus[i].ADN.genes_int[2]];

                                }
                                else if (individus[i].ADN.genes_int[1] == 2){
                                    y = graph[2][individus[i].ADN.genes_int[2]];
                                }
                                else if (individus[i].ADN.genes_int[1] == 3){
                                    y = graph[3][individus[i].ADN.genes_int[2]];
                                }
                                else if (individus[i].ADN.genes_int[1] == 4){
                                    y = graph[4][individus[i].ADN.genes_int[2]];
                                }
                                else if (individus[i].ADN.genes_int[1] == 5){
                                    y = graph[5][individus[i].ADN.genes_int[2]];
                                }
                                //----------------------------------
                                if (individus[i].ADN.genes_int[2] == 0){
                                    z = graph[0][individus[i].ADN.genes_int[3]];
                                }
                                else if (individus[i].ADN.genes_int[2] == 1){
                                    z = graph[1][individus[i].ADN.genes_int[3]];
                                }
                                else if (individus[i].ADN.genes_int[2] == 2){
                                    z = graph[2][individus[i].ADN.genes_int[3]];                        }
                                else if (individus[i].ADN.genes_int[2] == 3){
                                    z = graph[3][individus[i].ADN.genes_int[3]];
                                }
                                else if (individus[i].ADN.genes_int[2] == 4){
                                    z = graph[4][individus[i].ADN.genes_int[3]];
                                }
                                else if (individus[i].ADN.genes_int[2] == 5){
                                    z = graph[5][individus[i].ADN.genes_int[3]];
                                }
                                //----------------------------------
                                if (individus[i].ADN.genes_int[3] == 0){
                                    w = graph[0][individus[i].ADN.genes_int[4]];
                                }
                                else if (individus[i].ADN.genes_int[3] == 1){
                                w = graph[1][individus[i].ADN.genes_int[4]];

                                }
                                else if (individus[i].ADN.genes_int[3] == 2){
                                    w = graph[2][individus[i].ADN.genes_int[4]];
                                }
                                else if (individus[i].ADN.genes_int[3] == 3){
                                    w = graph[3][individus[i].ADN.genes_int[4]];
                                }
                                else if (individus[i].ADN.genes_int[3] == 4){
                                    w = graph[4][individus[i].ADN.genes_int[4]];
                                }
                                else if (individus[i].ADN.genes_int[3] == 5){
                                    w = graph[5][individus[i].ADN.genes_int[4]];
                                }
                                //----------------------------------
                                if (individus[i].ADN.genes_int[4] == 0){
                                    x5 = graph[0][individus[i].ADN.genes_int[5]];
                                }
                                else if (individus[i].ADN.genes_int[4] == 1){
                                x5 = graph[1][individus[i].ADN.genes_int[5]];

                                }
                                else if (individus[i].ADN.genes_int[4] == 2){
                                    x5 = graph[2][individus[i].ADN.genes_int[5]];
                                }
                                else if (individus[i].ADN.genes_int[4] == 3){
                                    x5 = graph[3][individus[i].ADN.genes_int[5]];
                                }
                                else if (individus[i].ADN.genes_int[4] == 4){
                                    x5 = graph[4][individus[i].ADN.genes_int[5]];
                                }
                                else if (individus[i].ADN.genes_int[4] == 5){
                                    x5 = graph[5][individus[i].ADN.genes_int[5]];
                                }
                                //----------------------------------
                                if (individus[i].ADN.genes_int[5] == 0){
                                    x6 = graph[0][individus[i].ADN.genes_int[0]];
                                }
                                else if (individus[i].ADN.genes_int[5] == 1){
                                x6 = graph[1][individus[i].ADN.genes_int[0]];

                                }
                                else if (individus[i].ADN.genes_int[5] == 2){
                                    x6 = graph[2][individus[i].ADN.genes_int[0]];
                                }
                                else if (individus[i].ADN.genes_int[5] == 3){
                                    x6 = graph[3][individus[i].ADN.genes_int[0]];
                                }
                                else if (individus[i].ADN.genes_int[5] == 4){
                                    x6 = graph[4][individus[i].ADN.genes_int[0]];
                                }
                                else if (individus[i].ADN.genes_int[5] == 5){
                                    x6 = graph[5][individus[i].ADN.genes_int[0]];
                                }
                        }
                        //-----------_____________-------------------
                         else if (nombre_sommets == 7){
                             if (individus[i].ADN.genes_int[0] == 0){
                                     x = graph[0][individus[i].ADN.genes_int[1]];
                                 }
                                 else if (individus[i].ADN.genes_int[0] == 1){
                                 x = graph[1][individus[i].ADN.genes_int[1]];

                                 }
                                 else if (individus[i].ADN.genes_int[0]  == 2){
                                     x = graph[2][individus[i].ADN.genes_int[1]];
                                 }
                                 else if (individus[i].ADN.genes_int[0]  == 3){
                                     x = graph[3][individus[i].ADN.genes_int[1]];
                                 }
                             else if (individus[i].ADN.genes_int[0]  == 4){
                                 x = graph[4][individus[i].ADN.genes_int[1]];
                             }
                             else if (individus[i].ADN.genes_int[0]  == 5){
                                 x = graph[5][individus[i].ADN.genes_int[1]];
                             }
                             else if (individus[i].ADN.genes_int[0]  == 6){
                                 x = graph[6][individus[i].ADN.genes_int[1]];
                             }
                                 //----------------------------------
                                 if (individus[i].ADN.genes_int[1] == 0){
                                     y = graph[0][individus[i].ADN.genes_int[2]];
                                 }
                                 else if (individus[i].ADN.genes_int[1] == 1){
                                 y = graph[1][individus[i].ADN.genes_int[2]];

                                 }
                                 else if (individus[i].ADN.genes_int[1] == 2){
                                     y = graph[2][individus[i].ADN.genes_int[2]];
                                 }
                                 else if (individus[i].ADN.genes_int[1] == 3){
                                     y = graph[3][individus[i].ADN.genes_int[2]];
                                 }
                                 else if (individus[i].ADN.genes_int[1] == 4){
                                     y = graph[4][individus[i].ADN.genes_int[2]];
                                 }
                                 else if (individus[i].ADN.genes_int[1] == 5){
                                     y = graph[5][individus[i].ADN.genes_int[2]];
                                 }
                                 else if (individus[i].ADN.genes_int[1] == 6){
                                     y = graph[6][individus[i].ADN.genes_int[2]];
                                 }
                                 //----------------------------------
                                 if (individus[i].ADN.genes_int[2] == 0){
                                     z = graph[0][individus[i].ADN.genes_int[3]];
                                 }
                                 else if (individus[i].ADN.genes_int[2] == 1){
                                     z = graph[1][individus[i].ADN.genes_int[3]];
                                 }
                                 else if (individus[i].ADN.genes_int[2] == 2){
                                     z = graph[2][individus[i].ADN.genes_int[3]];                        }
                                 else if (individus[i].ADN.genes_int[2] == 3){
                                     z = graph[3][individus[i].ADN.genes_int[3]];
                                 }
                                 else if (individus[i].ADN.genes_int[2] == 4){
                                     z = graph[4][individus[i].ADN.genes_int[3]];
                                 }
                                 else if (individus[i].ADN.genes_int[2] == 5){
                                     z = graph[5][individus[i].ADN.genes_int[3]];
                                 }
                                 else if (individus[i].ADN.genes_int[2] == 6){
                                     z = graph[6][individus[i].ADN.genes_int[3]];
                                 }
                                 //----------------------------------
                                 if (individus[i].ADN.genes_int[3] == 0){
                                     w = graph[0][individus[i].ADN.genes_int[4]];
                                 }
                                 else if (individus[i].ADN.genes_int[3] == 1){
                                 w = graph[1][individus[i].ADN.genes_int[4]];

                                 }
                                 else if (individus[i].ADN.genes_int[3] == 2){
                                     w = graph[2][individus[i].ADN.genes_int[4]];
                                 }
                                 else if (individus[i].ADN.genes_int[3] == 3){
                                     w = graph[3][individus[i].ADN.genes_int[4]];
                                 }
                                 else if (individus[i].ADN.genes_int[3] == 4){
                                     w = graph[4][individus[i].ADN.genes_int[4]];
                                 }
                                 else if (individus[i].ADN.genes_int[3] == 5){
                                     w = graph[5][individus[i].ADN.genes_int[4]];
                                 }
                                 else if (individus[i].ADN.genes_int[3] == 6){
                                     w = graph[6][individus[i].ADN.genes_int[4]];
                                 }
                                 //----------------------------------
                                 if (individus[i].ADN.genes_int[4] == 0){
                                     x5 = graph[0][individus[i].ADN.genes_int[5]];
                                 }
                                 else if (individus[i].ADN.genes_int[4] == 1){
                                 x5 = graph[1][individus[i].ADN.genes_int[5]];

                                 }
                                 else if (individus[i].ADN.genes_int[4] == 2){
                                     x5 = graph[2][individus[i].ADN.genes_int[5]];
                                 }
                                 else if (individus[i].ADN.genes_int[4] == 3){
                                     x5 = graph[3][individus[i].ADN.genes_int[5]];
                                 }
                                 else if (individus[i].ADN.genes_int[4] == 4){
                                     x5 = graph[4][individus[i].ADN.genes_int[5]];
                                 }
                                 else if (individus[i].ADN.genes_int[4] == 5){
                                     x5 = graph[5][individus[i].ADN.genes_int[5]];
                                 }
                                 else if (individus[i].ADN.genes_int[4] == 6){
                                     x5 = graph[6][individus[i].ADN.genes_int[5]];
                                 }
                                 //----------------------------------
                                 if (individus[i].ADN.genes_int[5] == 0){
                                     x6 = graph[0][individus[i].ADN.genes_int[6]];
                                 }
                                 else if (individus[i].ADN.genes_int[5] == 1){
                                 x6 = graph[1][individus[i].ADN.genes_int[6]];

                                 }
                                 else if (individus[i].ADN.genes_int[5] == 2){
                                     x6 = graph[2][individus[i].ADN.genes_int[6]];
                                 }
                                 else if (individus[i].ADN.genes_int[5] == 3){
                                     x6 = graph[3][individus[i].ADN.genes_int[6]];
                                 }
                                 else if (individus[i].ADN.genes_int[5] == 4){
                                     x6 = graph[4][individus[i].ADN.genes_int[6]];
                                 }
                                 else if (individus[i].ADN.genes_int[5] == 5){
                                     x6 = graph[5][individus[i].ADN.genes_int[6]];
                                 }
                                 else if (individus[i].ADN.genes_int[5] == 6){
                                     x6 = graph[6][individus[i].ADN.genes_int[6]];
                                 }
                                 //----------------------------------
                                 if (individus[i].ADN.genes_int[6] == 0){
                                     x7 = graph[0][individus[i].ADN.genes_int[0]];
                                 }
                                 else if (individus[i].ADN.genes_int[6] == 1){
                                 x7 = graph[1][individus[i].ADN.genes_int[0]];

                                 }
                                 else if (individus[i].ADN.genes_int[6] == 2){
                                     x7 = graph[2][individus[i].ADN.genes_int[0]];
                                 }
                                 else if (individus[i].ADN.genes_int[6] == 3){
                                     x7 = graph[3][individus[i].ADN.genes_int[0]];
                                 }
                                 else if (individus[i].ADN.genes_int[6] == 4){
                                     x7 = graph[4][individus[i].ADN.genes_int[0]];
                                 }
                                 else if (individus[i].ADN.genes_int[6] == 5){
                                     x7 = graph[5][individus[i].ADN.genes_int[0]];
                                 }
                                 else if (individus[i].ADN.genes_int[6] == 6){
                                     x7 = graph[6][individus[i].ADN.genes_int[0]];
                                 }
                         }                        
            
                        //------_____________---------------------__
                        if (nombre_sommets == 4) if((poid)>(x+y+z+w)){
                             g1 = individus[i].ADN.genes_int[0];
                             g2 = individus[i].ADN.genes_int[1];
                             g3 = individus[i].ADN.genes_int[2];
                             g4 = individus[i].ADN.genes_int[3];
                             poid = x+y+z+w;
                         }
                        if (nombre_sommets == 5) if((poid)>(x+y+z+w+x5)){
                             g1 = individus[i].ADN.genes_int[0];
                             g2 = individus[i].ADN.genes_int[1];
                             g3 = individus[i].ADN.genes_int[2];
                             g4 = individus[i].ADN.genes_int[3];
                             g5 = individus[i].ADN.genes_int[4];
                             poid = x+y+z+w+x5;
                         }
                        if (nombre_sommets == 6) if((poid)>(x+y+z+w+x5+x6)){
                             g1 = individus[i].ADN.genes_int[0];
                             g2 = individus[i].ADN.genes_int[1];
                             g3 = individus[i].ADN.genes_int[2];
                             g4 = individus[i].ADN.genes_int[3];
                             g5 = individus[i].ADN.genes_int[4];
                             g6 = individus[i].ADN.genes_int[5];
                             poid = x+y+z+w+x5+x6;
                         }

                        if (nombre_sommets == 7) if((poid)>(x+y+z+w+x5+x6+x7)){
                             g1 = individus[i].ADN.genes_int[0];
                             g2 = individus[i].ADN.genes_int[1];
                             g3 = individus[i].ADN.genes_int[2];
                             g4 = individus[i].ADN.genes_int[3];
                             g5 = individus[i].ADN.genes_int[4];
                             g6 = individus[i].ADN.genes_int[5];
                             g7 = individus[i].ADN.genes_int[6];
                             poid = x+y+z+w+x5+x6+x7;
                         }
                        individus[i].ADN.genes_int[0] = x;
                        individus[i].ADN.genes_int[1] = y;
                        individus[i].ADN.genes_int[2] = z;
                        individus[i].ADN.genes_int[3] = w;
                        if (nombre_sommets == 5) individus[i].ADN.genes_int[4] = x5;
                        if (nombre_sommets == 6) {
                            individus[i].ADN.genes_int[4] = x5;
                            individus[i].ADN.genes_int[5] = x6;
                        }
                        if (nombre_sommets == 7) {
                            individus[i].ADN.genes_int[4] = x5;
                            individus[i].ADN.genes_int[5] = x6;
                            individus[i].ADN.genes_int[6] = x7;
                        }
                        evaluation e = evaluation (ee.getChaineEvaluation());
                        e.evaluer(&individus[i]);
                        if (ee.getTypeGenes() == 1)
                            score_totale += individus[i].getNoteEvaluation();
                        else if (ee.getTypeGenes() == 2)
                            score_totale_d += individus[i].getNoteEvaluationFlottant();
                        else if (ee.getTypeGenes() == 3)
                            score_totale += individus[0].convertionVersDecimale(individus[i].getNoteEvaluation());

                    }

                    op.triFusion(0, individus.size()-1);
                    evaluation e = evaluation (ee.getChaineEvaluation());
                    if (ee.getTypeGenes() == 1){
                        meilleur_premier = individus[0].getNoteEvaluation();
                        score_totale = score_totale/individus.size();
                        arret = e.testArret(meilleur_premier,ee.getGenerationSatisfaisante(), ee.getMaximisationMinimisation());
                        meillleur_individu.push_back(individus.at(0).getNoteEvaluation());
                        score_total.push_back(score_totale);
                    }
                }
                if (arret) break;
            //-------------------------Sélection---------------
            if (ee.getChoixSelection() == 1)
                op.selectionParRang();
            else if (ee.getChoixSelection() == 2)// modifier reel-------
                {
                    op.selectionParTournoi();
                }
            else if (ee.getChoixSelection() == 3)//modifier reel--------
                {
                    op.selectionParRoulette();
                }
            //-------------------------Croisement---------------

            if ((ee.getTypeGenes() == 1) || (ee.getTypeGenes() == 3))
            score_totale = 0;
            else if (ee.getTypeGenes() == 2)
            score_totale_d = 0;
            op.croisement(ee.getTauxCroisement(), ee.getTauxMutation(), ee.getTaillePopulation(), ee.getChaineEvaluation());
                for (int i = ee.getNmbr_indiv_a_selec(); i< individus.size(); i++){
                        //----------------------
                        if (nombre_sommets == 4){
                            while ((individus[i].ADN.genes_int[0] == individus[i].ADN.genes_int[1])||(individus[i].ADN.genes_int[0] == individus[i].ADN.genes_int[2])||(individus[i].ADN.genes_int[0] == individus[i].ADN.genes_int[3])||(individus[i].ADN.genes_int[1] == individus[i].ADN.genes_int[2])||(individus[i].ADN.genes_int[1] == individus[i].ADN.genes_int[3])||(individus[i].ADN.genes_int[2] == individus[i].ADN.genes_int[3])){
                                individus[i] = individu(ee.getMinIntervalle(),ee.getMaxIntervalle(), ee.getNombreGenes(),ee.getTypeGenes());
                            }
                        } else if (nombre_sommets ==5){
                        while ((individus[i].ADN.genes_int[0] == individus[i].ADN.genes_int[1])||(individus[i].ADN.genes_int[0] == individus[i].ADN.genes_int[2])||(individus[i].ADN.genes_int[0] == individus[i].ADN.genes_int[3])||(individus[i].ADN.genes_int[0] == individus[i].ADN.genes_int[4])||(individus[i].ADN.genes_int[1] == individus[i].ADN.genes_int[2])||(individus[i].ADN.genes_int[1] == individus[i].ADN.genes_int[3])||(individus[i].ADN.genes_int[1] == individus[i].ADN.genes_int[4])||(individus[i].ADN.genes_int[2] == individus[i].ADN.genes_int[3])||(individus[i].ADN.genes_int[2] == individus[i].ADN.genes_int[4])||(individus[i].ADN.genes_int[3] == individus[i].ADN.genes_int[4])){
                                individus[i] = individu(0,5,5,1);
                        }
                        }
                        else if (nombre_sommets ==6){
                        while ((individus[i].ADN.genes_int[0] == individus[i].ADN.genes_int[1])||(individus[i].ADN.genes_int[0] == individus[i].ADN.genes_int[2])||(individus[i].ADN.genes_int[0] == individus[i].ADN.genes_int[3])||(individus[i].ADN.genes_int[0] == individus[i].ADN.genes_int[4])||(individus[i].ADN.genes_int[0] == individus[i].ADN.genes_int[5])||(individus[i].ADN.genes_int[1] == individus[i].ADN.genes_int[2])||(individus[i].ADN.genes_int[1] == individus[i].ADN.genes_int[3])||(individus[i].ADN.genes_int[1] == individus[i].ADN.genes_int[4])||(individus[i].ADN.genes_int[1] == individus[i].ADN.genes_int[5])||(individus[i].ADN.genes_int[2] == individus[i].ADN.genes_int[3])||(individus[i].ADN.genes_int[2] == individus[i].ADN.genes_int[4])||(individus[i].ADN.genes_int[2] == individus[i].ADN.genes_int[5])||(individus[i].ADN.genes_int[3] == individus[i].ADN.genes_int[4])||(individus[i].ADN.genes_int[3] == individus[i].ADN.genes_int[5])||(individus[i].ADN.genes_int[4] == individus[i].ADN.genes_int[5])){
                              individus[i] = individu(0,6,6,1);
                              }
                           }
                        else if (nombre_sommets ==7){
                        while ((individus[i].ADN.genes_int[0] == individus[i].ADN.genes_int[1])||(individus[i].ADN.genes_int[0] == individus[i].ADN.genes_int[2])||(individus[i].ADN.genes_int[0] == individus[i].ADN.genes_int[3])||(individus[i].ADN.genes_int[0] == individus[i].ADN.genes_int[4])||(individus[i].ADN.genes_int[0] == individus[i].ADN.genes_int[5])||(individus[i].ADN.genes_int[0] == individus[i].ADN.genes_int[6])||(individus[i].ADN.genes_int[1] == individus[i].ADN.genes_int[2])||(individus[i].ADN.genes_int[1] == individus[i].ADN.genes_int[3])||(individus[i].ADN.genes_int[1] == individus[i].ADN.genes_int[4])||(individus[i].ADN.genes_int[1] == individus[i].ADN.genes_int[5])||(individus[i].ADN.genes_int[1] == individus[i].ADN.genes_int[6])||(individus[i].ADN.genes_int[2] == individus[i].ADN.genes_int[3])||(individus[i].ADN.genes_int[2] == individus[i].ADN.genes_int[4])||(individus[i].ADN.genes_int[2] == individus[i].ADN.genes_int[5])||(individus[i].ADN.genes_int[2] == individus[i].ADN.genes_int[6])||(individus[i].ADN.genes_int[3] == individus[i].ADN.genes_int[4])||(individus[i].ADN.genes_int[3] == individus[i].ADN.genes_int[5])||(individus[i].ADN.genes_int[3] == individus[i].ADN.genes_int[6])||(individus[i].ADN.genes_int[4] == individus[i].ADN.genes_int[5])||(individus[i].ADN.genes_int[4] == individus[i].ADN.genes_int[6])||(individus[i].ADN.genes_int[5] == individus[i].ADN.genes_int[6])){
                              individus[i] = individu(0,7,7,1);
                              }
                        }
                    int x,y,z,w,x5,x6,x7;
                    if (nombre_sommets == 4){
                    if (individus[i].ADN.genes_int[0] == 0){
                            x = graph[0][individus[i].ADN.genes_int[1]];
                        }
                        else if (individus[i].ADN.genes_int[0] == 1){
                        x = graph[1][individus[i].ADN.genes_int[1]];

                        }
                        else if (individus[i].ADN.genes_int[0]  == 2){
                            x = graph[2][individus[i].ADN.genes_int[1]];
                        }
                        else if (individus[i].ADN.genes_int[0]  == 3){
                            x = graph[3][individus[i].ADN.genes_int[1]];
                        }
                        //----------------------------------
                        if (individus[i].ADN.genes_int[1] == 0){
                            y = graph[0][individus[i].ADN.genes_int[2]];
                        }
                        else if (individus[i].ADN.genes_int[1] == 1){
                        y = graph[1][individus[i].ADN.genes_int[2]];

                        }
                        else if (individus[i].ADN.genes_int[1] == 2){
                            y = graph[2][individus[i].ADN.genes_int[2]];
                        }
                        else if (individus[i].ADN.genes_int[1] == 3){
                            y = graph[3][individus[i].ADN.genes_int[2]];
                        }
                        //----------------------------------
                        if (individus[i].ADN.genes_int[2] == 0){
                            z = graph[individus[i].ADN.genes_int[2]][individus[i].ADN.genes_int[3]] - graph[individus[i].ADN.genes_int[0]][individus[i].ADN.genes_int[0]];
                        }
                        else if (individus[i].ADN.genes_int[2] == 1){
                        z = graph[individus[i].ADN.genes_int[2]][individus[i].ADN.genes_int[3]] - graph[individus[i].ADN.genes_int[1]][individus[i].ADN.genes_int[1]];

                        }
                        else if (individus[i].ADN.genes_int[2] == 2){
                            z = graph[individus[i].ADN.genes_int[2]][individus[i].ADN.genes_int[3]] - graph[individus[i].ADN.genes_int[2]][individus[i].ADN.genes_int[2]];
                        }
                        else if (individus[i].ADN.genes_int[2] == 3){
                            z = graph[individus[i].ADN.genes_int[2]][individus[i].ADN.genes_int[3]] - graph[individus[i].ADN.genes_int[3]][individus[i].ADN.genes_int[3]];
                        }
                        //----------------------------------
                        if (individus[i].ADN.genes_int[3] == 0){
                            w = graph[individus[i].ADN.genes_int[3]][individus[i].ADN.genes_int[0]] - graph[individus[i].ADN.genes_int[0]][individus[i].ADN.genes_int[0]];
                        }
                        else if (individus[i].ADN.genes_int[3] == 1){
                        w = graph[individus[i].ADN.genes_int[3]][individus[i].ADN.genes_int[0]] - graph[individus[i].ADN.genes_int[1]][individus[i].ADN.genes_int[1]];

                        }
                        else if (individus[i].ADN.genes_int[3] == 2){
                            w = graph[individus[i].ADN.genes_int[3]][individus[i].ADN.genes_int[0]] - graph[individus[i].ADN.genes_int[2]][individus[i].ADN.genes_int[2]];
                        }
                        else if (individus[i].ADN.genes_int[3] == 3){
                            w = graph[individus[i].ADN.genes_int[3]][individus[i].ADN.genes_int[0]] - graph[individus[i].ADN.genes_int[3]][individus[i].ADN.genes_int[3]];
                        }
                        //---------------------------------
                        }
                        //_____________----------________
                        if (nombre_sommets == 5){
                            if (individus[i].ADN.genes_int[0] == 0){
                                    x = graph[0][individus[i].ADN.genes_int[1]];
                                }
                                else if (individus[i].ADN.genes_int[0] == 1){
                                x = graph[1][individus[i].ADN.genes_int[1]];

                                }
                                else if (individus[i].ADN.genes_int[0]  == 2){
                                    x = graph[2][individus[i].ADN.genes_int[1]];
                                }
                                else if (individus[i].ADN.genes_int[0]  == 3){
                                    x = graph[3][individus[i].ADN.genes_int[1]];
                                }
                            else if (individus[i].ADN.genes_int[0]  == 4){
                                x = graph[4][individus[i].ADN.genes_int[1]];
                            }
                                //----------------------------------
                                if (individus[i].ADN.genes_int[1] == 0){
                                    y = graph[0][individus[i].ADN.genes_int[2]];
                                }
                                else if (individus[i].ADN.genes_int[1] == 1){
                                y = graph[1][individus[i].ADN.genes_int[2]];

                                }
                                else if (individus[i].ADN.genes_int[1] == 2){
                                    y = graph[2][individus[i].ADN.genes_int[2]];
                                }
                                else if (individus[i].ADN.genes_int[1] == 3){
                                    y = graph[3][individus[i].ADN.genes_int[2]];
                                }
                                else if (individus[i].ADN.genes_int[1] == 4){
                                    y = graph[4][individus[i].ADN.genes_int[2]];
                                }
                                //----------------------------------
                                if (individus[i].ADN.genes_int[2] == 0){
                                    z = graph[0][individus[i].ADN.genes_int[3]];
                                }
                                else if (individus[i].ADN.genes_int[2] == 1){
                                    z = graph[1][individus[i].ADN.genes_int[3]];
                                }
                                else if (individus[i].ADN.genes_int[2] == 2){
                                    z = graph[2][individus[i].ADN.genes_int[3]];                        }
                                else if (individus[i].ADN.genes_int[2] == 3){
                                    z = graph[3][individus[i].ADN.genes_int[3]];
                                }
                                else if (individus[i].ADN.genes_int[2] == 4){
                                    z = graph[4][individus[i].ADN.genes_int[3]];
                                }
                                //----------------------------------
                                if (individus[i].ADN.genes_int[3] == 0){
                                    w = graph[0][individus[i].ADN.genes_int[4]];
                                }
                                else if (individus[i].ADN.genes_int[3] == 1){
                                w = graph[1][individus[i].ADN.genes_int[4]];

                                }
                                else if (individus[i].ADN.genes_int[3] == 2){
                                    w = graph[2][individus[i].ADN.genes_int[4]];
                                }
                                else if (individus[i].ADN.genes_int[3] == 3){
                                    w = graph[3][individus[i].ADN.genes_int[4]];
                                }
                                else if (individus[i].ADN.genes_int[3] == 4){
                                    w = graph[4][individus[i].ADN.genes_int[4]];
                                }
                                //----------------------------------
                                if (individus[i].ADN.genes_int[4] == 0){
                                    x5 = graph[0][individus[i].ADN.genes_int[0]];
                                }
                                else if (individus[i].ADN.genes_int[4] == 1){
                                x5 = graph[1][individus[i].ADN.genes_int[0]];

                                }
                                else if (individus[i].ADN.genes_int[4] == 2){
                                    x5 = graph[2][individus[i].ADN.genes_int[0]];
                                }
                                else if (individus[i].ADN.genes_int[4] == 3){
                                    x5 = graph[3][individus[i].ADN.genes_int[0]];
                                }
                                else if (individus[i].ADN.genes_int[4] == 4){
                                    x5 = graph[4][individus[i].ADN.genes_int[0]];
                                }
                        }
                        //-----------_____________-------------------
                         else if (nombre_sommets == 6){
                             if (individus[i].ADN.genes_int[0] == 0){
                                     x = graph[0][individus[i].ADN.genes_int[1]];
                                 }
                                 else if (individus[i].ADN.genes_int[0] == 1){
                                 x = graph[1][individus[i].ADN.genes_int[1]];

                                 }
                                 else if (individus[i].ADN.genes_int[0]  == 2){
                                     x = graph[2][individus[i].ADN.genes_int[1]];
                                 }
                                 else if (individus[i].ADN.genes_int[0]  == 3){
                                     x = graph[3][individus[i].ADN.genes_int[1]];
                                 }
                             else if (individus[i].ADN.genes_int[0]  == 4){
                                 x = graph[4][individus[i].ADN.genes_int[1]];
                             }
                             else if (individus[i].ADN.genes_int[0]  == 5){
                                 x = graph[5][individus[i].ADN.genes_int[1]];
                             }
                                 //----------------------------------
                                 if (individus[i].ADN.genes_int[1] == 0){
                                     y = graph[0][individus[i].ADN.genes_int[2]];
                                 }
                                 else if (individus[i].ADN.genes_int[1] == 1){
                                 y = graph[1][individus[i].ADN.genes_int[2]];

                                 }
                                 else if (individus[i].ADN.genes_int[1] == 2){
                                     y = graph[2][individus[i].ADN.genes_int[2]];
                                 }
                                 else if (individus[i].ADN.genes_int[1] == 3){
                                     y = graph[3][individus[i].ADN.genes_int[2]];
                                 }
                                 else if (individus[i].ADN.genes_int[1] == 4){
                                     y = graph[4][individus[i].ADN.genes_int[2]];
                                 }
                                 else if (individus[i].ADN.genes_int[1] == 5){
                                     y = graph[5][individus[i].ADN.genes_int[2]];
                                 }
                                 //----------------------------------
                                 if (individus[i].ADN.genes_int[2] == 0){
                                     z = graph[0][individus[i].ADN.genes_int[3]];
                                 }
                                 else if (individus[i].ADN.genes_int[2] == 1){
                                     z = graph[1][individus[i].ADN.genes_int[3]];
                                 }
                                 else if (individus[i].ADN.genes_int[2] == 2){
                                     z = graph[2][individus[i].ADN.genes_int[3]];                        }
                                 else if (individus[i].ADN.genes_int[2] == 3){
                                     z = graph[3][individus[i].ADN.genes_int[3]];
                                 }
                                 else if (individus[i].ADN.genes_int[2] == 4){
                                     z = graph[4][individus[i].ADN.genes_int[3]];
                                 }
                                 else if (individus[i].ADN.genes_int[2] == 5){
                                     z = graph[5][individus[i].ADN.genes_int[3]];
                                 }
                                 //----------------------------------
                                 if (individus[i].ADN.genes_int[3] == 0){
                                     w = graph[0][individus[i].ADN.genes_int[4]];
                                 }
                                 else if (individus[i].ADN.genes_int[3] == 1){
                                 w = graph[1][individus[i].ADN.genes_int[4]];

                                 }
                                 else if (individus[i].ADN.genes_int[3] == 2){
                                     w = graph[2][individus[i].ADN.genes_int[4]];
                                 }
                                 else if (individus[i].ADN.genes_int[3] == 3){
                                     w = graph[3][individus[i].ADN.genes_int[4]];
                                 }
                                 else if (individus[i].ADN.genes_int[3] == 4){
                                     w = graph[4][individus[i].ADN.genes_int[4]];
                                 }
                                 else if (individus[i].ADN.genes_int[3] == 5){
                                     w = graph[5][individus[i].ADN.genes_int[4]];
                                 }
                                 //----------------------------------
                                 if (individus[i].ADN.genes_int[4] == 0){
                                     x5 = graph[0][individus[i].ADN.genes_int[5]];
                                 }
                                 else if (individus[i].ADN.genes_int[4] == 1){
                                 x5 = graph[1][individus[i].ADN.genes_int[5]];

                                 }
                                 else if (individus[i].ADN.genes_int[4] == 2){
                                     x5 = graph[2][individus[i].ADN.genes_int[5]];
                                 }
                                 else if (individus[i].ADN.genes_int[4] == 3){
                                     x5 = graph[3][individus[i].ADN.genes_int[5]];
                                 }
                                 else if (individus[i].ADN.genes_int[4] == 4){
                                     x5 = graph[4][individus[i].ADN.genes_int[5]];
                                 }
                                 else if (individus[i].ADN.genes_int[4] == 5){
                                     x5 = graph[5][individus[i].ADN.genes_int[5]];
                                 }
                                 //----------------------------------
                                 if (individus[i].ADN.genes_int[5] == 0){
                                     x6 = graph[0][individus[i].ADN.genes_int[0]];
                                 }
                                 else if (individus[i].ADN.genes_int[5] == 1){
                                 x6 = graph[1][individus[i].ADN.genes_int[0]];

                                 }
                                 else if (individus[i].ADN.genes_int[5] == 2){
                                     x6 = graph[2][individus[i].ADN.genes_int[0]];
                                 }
                                 else if (individus[i].ADN.genes_int[5] == 3){
                                     x6 = graph[3][individus[i].ADN.genes_int[0]];
                                 }
                                 else if (individus[i].ADN.genes_int[5] == 4){
                                     x6 = graph[4][individus[i].ADN.genes_int[0]];
                                 }
                                 else if (individus[i].ADN.genes_int[5] == 5){
                                     x6 = graph[5][individus[i].ADN.genes_int[0]];
                                 }
                         }
                        //-----------_____________-------------------
                         else if (nombre_sommets == 7){
                             if (individus[i].ADN.genes_int[0] == 0){
                                     x = graph[0][individus[i].ADN.genes_int[1]];
                                 }
                                 else if (individus[i].ADN.genes_int[0] == 1){
                                 x = graph[1][individus[i].ADN.genes_int[1]];

                                 }
                                 else if (individus[i].ADN.genes_int[0]  == 2){
                                     x = graph[2][individus[i].ADN.genes_int[1]];
                                 }
                                 else if (individus[i].ADN.genes_int[0]  == 3){
                                     x = graph[3][individus[i].ADN.genes_int[1]];
                                 }
                             else if (individus[i].ADN.genes_int[0]  == 4){
                                 x = graph[4][individus[i].ADN.genes_int[1]];
                             }
                             else if (individus[i].ADN.genes_int[0]  == 5){
                                 x = graph[5][individus[i].ADN.genes_int[1]];
                             }
                             else if (individus[i].ADN.genes_int[0]  == 6){
                                 x = graph[6][individus[i].ADN.genes_int[1]];
                             }
                                 //----------------------------------
                                 if (individus[i].ADN.genes_int[1] == 0){
                                     y = graph[0][individus[i].ADN.genes_int[2]];
                                 }
                                 else if (individus[i].ADN.genes_int[1] == 1){
                                 y = graph[1][individus[i].ADN.genes_int[2]];

                                 }
                                 else if (individus[i].ADN.genes_int[1] == 2){
                                     y = graph[2][individus[i].ADN.genes_int[2]];
                                 }
                                 else if (individus[i].ADN.genes_int[1] == 3){
                                     y = graph[3][individus[i].ADN.genes_int[2]];
                                 }
                                 else if (individus[i].ADN.genes_int[1] == 4){
                                     y = graph[4][individus[i].ADN.genes_int[2]];
                                 }
                                 else if (individus[i].ADN.genes_int[1] == 5){
                                     y = graph[5][individus[i].ADN.genes_int[2]];
                                 }
                                 else if (individus[i].ADN.genes_int[1] == 6){
                                     y = graph[6][individus[i].ADN.genes_int[2]];
                                 }
                                 //----------------------------------
                                 if (individus[i].ADN.genes_int[2] == 0){
                                     z = graph[0][individus[i].ADN.genes_int[3]];
                                 }
                                 else if (individus[i].ADN.genes_int[2] == 1){
                                     z = graph[1][individus[i].ADN.genes_int[3]];
                                 }
                                 else if (individus[i].ADN.genes_int[2] == 2){
                                     z = graph[2][individus[i].ADN.genes_int[3]];                        }
                                 else if (individus[i].ADN.genes_int[2] == 3){
                                     z = graph[3][individus[i].ADN.genes_int[3]];
                                 }
                                 else if (individus[i].ADN.genes_int[2] == 4){
                                     z = graph[4][individus[i].ADN.genes_int[3]];
                                 }
                                 else if (individus[i].ADN.genes_int[2] == 5){
                                     z = graph[5][individus[i].ADN.genes_int[3]];
                                 }
                                 else if (individus[i].ADN.genes_int[2] == 6){
                                     z = graph[6][individus[i].ADN.genes_int[3]];
                                 }
                                 //----------------------------------
                                 if (individus[i].ADN.genes_int[3] == 0){
                                     w = graph[0][individus[i].ADN.genes_int[4]];
                                 }
                                 else if (individus[i].ADN.genes_int[3] == 1){
                                 w = graph[1][individus[i].ADN.genes_int[4]];

                                 }
                                 else if (individus[i].ADN.genes_int[3] == 2){
                                     w = graph[2][individus[i].ADN.genes_int[4]];
                                 }
                                 else if (individus[i].ADN.genes_int[3] == 3){
                                     w = graph[3][individus[i].ADN.genes_int[4]];
                                 }
                                 else if (individus[i].ADN.genes_int[3] == 4){
                                     w = graph[4][individus[i].ADN.genes_int[4]];
                                 }
                                 else if (individus[i].ADN.genes_int[3] == 5){
                                     w = graph[5][individus[i].ADN.genes_int[4]];
                                 }
                                 else if (individus[i].ADN.genes_int[3] == 6){
                                     w = graph[6][individus[i].ADN.genes_int[4]];
                                 }
                                 //----------------------------------
                                 if (individus[i].ADN.genes_int[4] == 0){
                                     x5 = graph[0][individus[i].ADN.genes_int[5]];
                                 }
                                 else if (individus[i].ADN.genes_int[4] == 1){
                                 x5 = graph[1][individus[i].ADN.genes_int[5]];

                                 }
                                 else if (individus[i].ADN.genes_int[4] == 2){
                                     x5 = graph[2][individus[i].ADN.genes_int[5]];
                                 }
                                 else if (individus[i].ADN.genes_int[4] == 3){
                                     x5 = graph[3][individus[i].ADN.genes_int[5]];
                                 }
                                 else if (individus[i].ADN.genes_int[4] == 4){
                                     x5 = graph[4][individus[i].ADN.genes_int[5]];
                                 }
                                 else if (individus[i].ADN.genes_int[4] == 5){
                                     x5 = graph[5][individus[i].ADN.genes_int[5]];
                                 }
                                 else if (individus[i].ADN.genes_int[4] == 6){
                                     x5 = graph[6][individus[i].ADN.genes_int[5]];
                                 }
                                 //----------------------------------
                                 if (individus[i].ADN.genes_int[5] == 0){
                                     x6 = graph[0][individus[i].ADN.genes_int[6]];
                                 }
                                 else if (individus[i].ADN.genes_int[5] == 1){
                                 x6 = graph[1][individus[i].ADN.genes_int[6]];

                                 }
                                 else if (individus[i].ADN.genes_int[5] == 2){
                                     x6 = graph[2][individus[i].ADN.genes_int[6]];
                                 }
                                 else if (individus[i].ADN.genes_int[5] == 3){
                                     x6 = graph[3][individus[i].ADN.genes_int[6]];
                                 }
                                 else if (individus[i].ADN.genes_int[5] == 4){
                                     x6 = graph[4][individus[i].ADN.genes_int[6]];
                                 }
                                 else if (individus[i].ADN.genes_int[5] == 5){
                                     x6 = graph[5][individus[i].ADN.genes_int[6]];
                                 }
                                 else if (individus[i].ADN.genes_int[5] == 6){
                                     x6 = graph[6][individus[i].ADN.genes_int[6]];
                                 }
                                 //----------------------------------
                                 if (individus[i].ADN.genes_int[6] == 0){
                                     x7 = graph[0][individus[i].ADN.genes_int[0]];
                                 }
                                 else if (individus[i].ADN.genes_int[6] == 1){
                                 x7 = graph[1][individus[i].ADN.genes_int[0]];

                                 }
                                 else if (individus[i].ADN.genes_int[6] == 2){
                                     x7 = graph[2][individus[i].ADN.genes_int[0]];
                                 }
                                 else if (individus[i].ADN.genes_int[6] == 3){
                                     x7 = graph[3][individus[i].ADN.genes_int[0]];
                                 }
                                 else if (individus[i].ADN.genes_int[6] == 4){
                                     x7 = graph[4][individus[i].ADN.genes_int[0]];
                                 }
                                 else if (individus[i].ADN.genes_int[6] == 5){
                                     x7 = graph[5][individus[i].ADN.genes_int[0]];
                                 }
                                 else if (individus[i].ADN.genes_int[6] == 6){
                                     x7 = graph[6][individus[i].ADN.genes_int[0]];
                                 }
                        }
                        
                         
                        if (nombre_sommets == 4) if((poid)>(x+y+z+w)){
                             g1 = individus[i].ADN.genes_int[0];
                             g2 = individus[i].ADN.genes_int[1];
                             g3 = individus[i].ADN.genes_int[2];
                             g4 = individus[i].ADN.genes_int[3];
                             poid = x+y+z+w;
                         }
                        if (nombre_sommets == 5) if((poid)>(x+y+z+w+x5)){
                            g1 = individus[i].ADN.genes_int[0];
                            g2 = individus[i].ADN.genes_int[1];
                            g3 = individus[i].ADN.genes_int[2];
                            g4 = individus[i].ADN.genes_int[3];
                            g5 = individus[i].ADN.genes_int[4];
                            poid = x+y+z+w+x5;
                        }
                        if (nombre_sommets == 6) if((poid)>(x+y+z+w+x5+x6)){
                             g1 = individus[i].ADN.genes_int[0];
                             g2 = individus[i].ADN.genes_int[1];
                             g3 = individus[i].ADN.genes_int[2];
                             g4 = individus[i].ADN.genes_int[3];
                             g5 = individus[i].ADN.genes_int[4];
                             g6 = individus[i].ADN.genes_int[5];
                             poid = x+y+z+w+x5+x6;
                         }
                        if (nombre_sommets == 7) if((poid)>(x+y+z+w+x5+x6+x7)){
                             g1 = individus[i].ADN.genes_int[0];
                             g2 = individus[i].ADN.genes_int[1];
                             g3 = individus[i].ADN.genes_int[2];
                             g4 = individus[i].ADN.genes_int[3];
                             g5 = individus[i].ADN.genes_int[4];
                             g6 = individus[i].ADN.genes_int[5];
                             g7 = individus[i].ADN.genes_int[6];
                             poid = x+y+z+w+x5+x6+x7;
                         }
                        individus[i].ADN.genes_int[0] = x;
                        individus[i].ADN.genes_int[1] = y;
                        individus[i].ADN.genes_int[2] = z;
                        individus[i].ADN.genes_int[3] = w;
                        if (nombre_sommets == 5) individus[i].ADN.genes_int[4] = x5;
                        if (nombre_sommets == 6) {
                            individus[i].ADN.genes_int[4] = x5;
                            individus[i].ADN.genes_int[5] = x6;
                        }
                        if (nombre_sommets == 7) {
                            individus[i].ADN.genes_int[4] = x5;
                            individus[i].ADN.genes_int[5] = x6;
                            individus[i].ADN.genes_int[6] = x7;
                        }
                    evaluation e = evaluation (ee.getChaineEvaluation());
                    e.evaluer(&individus[i]);
                    if (ee.getTypeGenes() == 1){
                        score_totale += individus[i].getNoteEvaluation();
                    }
                }	op.triFusion(0, individus.size()-1);
                evaluation e2 = evaluation (ee.getChaineEvaluation());
                if (ee.getTypeGenes() == 1){
                    arret = e2.testArret(individus.at(0).getNoteEvaluation(),ee.getGenerationSatisfaisante(), ee.getMaximisationMinimisation());
                    score_total.push_back(score_totale/individus.size());
                        meillleur_individu.push_back(individus.at(0).getNoteEvaluation());
                }
                    compteur_generation++;
                    if (arret) break;



            }
            if ((ee.getTypeGenes() == 1) || (ee.getTypeGenes() == 3)){

                ee.setNoteMoyenne(score_total);
                ee.setMeilleurIndividu(meillleur_individu);
                ee.genererLatex(&individus, "Statistiques.txt");
            }

            if (nombre_sommets ==4)
                afficherSolution4Sommets(g1,g2,g3,g4);
            if (nombre_sommets == 5)
                afficherSolution5Sommets(g1,g2,g3,g4,g5);
            if (nombre_sommets == 6)
                afficherSolution6Sommets(g1,g2,g3,g4,g5,g6);
            if (nombre_sommets == 7)
                afficherSolution7Sommets(g1,g2,g3,g4,g5,g6,g7);
}


void GraphWidget::initialisationGraph(){
    //2.créer la matrice :--------------------------------
   if (nombre_sommets == 4){
       graph = (int**) malloc(4*sizeof(int*));
       for (int i=0; i<4; i++){
           graph[i] = (int*) malloc(4*sizeof(int));
       }
   }
   else if (nombre_sommets == 5){
       graph = (int**) malloc(5*sizeof(int*));
       for (int i=0; i<5; i++){
           graph[i] = (int*) malloc(5*sizeof(int));
       }
   }
   else if (nombre_sommets == 6){
       graph = (int**) malloc(6*sizeof(int*));
       for (int i=0; i<6; i++){
           graph[i] = (int*) malloc(6*sizeof(int));
       }
   }
   else if (nombre_sommets == 7){
       graph = (int**) malloc(7*sizeof(int*));
       for (int i=0; i<7; i++){
           graph[i] = (int*) malloc(7*sizeof(int));
       }
   }
   else if (nombre_sommets == 8){
       graph = (int**) malloc(8*sizeof(int*));
       for (int i=0; i<8; i++){
           graph[i] = (int*) malloc(8*sizeof(int));
       }
   }
   //3. recuperer les poids et initialiser la matrice :
   if (nombre_sommets == 4){
       graph[0][0] = 0;
       graph[0][1] = rand()%100;
       graph[0][2] = rand()%100;
       graph[0][3] = rand()%100;
       graph[1][0] = graph[0][1];
       graph[1][1] = 0;
       graph[1][2] = rand()%100;
       graph[1][3] = rand()%100;
       graph[2][0] = graph[0][2];
       graph[2][1] = graph[1][2];
       graph[2][2] = 0;
       graph[2][3] = rand()%100;
       graph[3][0] = graph[0][3];
       graph[3][1] = graph[1][3];
       graph[3][2] = graph[2][3];
       graph[3][3] = 0;
   }
   else if (nombre_sommets ==5){
       graph[0][0] = 0;
       graph[0][1] = rand()%100;
       graph[0][2] = rand()%100;
       graph[0][3] = rand()%100;
       graph[0][4] = rand()%100;
       graph[1][0] = graph[0][1];
       graph[1][1] = 0;
       graph[1][2] = rand()%100;
       graph[1][3] = rand()%100;
       graph[1][4] = rand()%100;
       graph[2][0] = graph[0][2];
       graph[2][1] = graph[1][2];
       graph[2][2] = 0;
       graph[2][3] = rand()%100;
       graph[2][4] = rand()%100;
       graph[3][0] = graph[0][3];
       graph[3][1] = graph[1][3];
       graph[3][2] = graph[2][3];
       graph[3][3] = 0;
       graph[3][4] = rand()%100;
       graph[4][0] = graph[0][4];
       graph[4][1] = graph[1][4];
       graph[4][2] = graph[2][4];
       graph[4][3] = graph[3][4];
       graph[4][4] = 0;
   }
   else if (nombre_sommets ==6){
       graph[0][0] = 0;
       graph[0][1] = rand()%100;
       graph[0][2] = rand()%100;
       graph[0][3] = rand()%100;
       graph[0][4] = rand()%100;
       graph[0][5] = rand()%100;
       graph[1][0] = graph[0][1];
       graph[1][1] = 0;
       graph[1][2] = rand()%100;
       graph[1][3] = rand()%100;
       graph[1][4] = rand()%100;
       graph[1][5] = rand()%100;
       graph[2][0] = graph[0][2];
       graph[2][1] = graph[1][2];
       graph[2][2] = 0;
       graph[2][3] = rand()%100;
       graph[2][4] = rand()%100;
       graph[2][5] = rand()%100;
       graph[3][0] = graph[0][3];
       graph[3][1] = graph[1][3];
       graph[3][2] = graph[2][3];
       graph[3][3] = 0;
       graph[3][4] = rand()%100;
       graph[3][5] = rand()%100;
       graph[4][0] = graph[0][4];
       graph[4][1] = graph[1][4];
       graph[4][2] = graph[2][4];
       graph[4][3] = graph[3][4];
       graph[4][4] = 0;
       graph[4][5] = rand()%100;
       graph[5][0] = graph[0][5];
       graph[5][1] = graph[1][5];
       graph[5][2] = graph[2][5];
       graph[5][3] = graph[3][5];
       graph[5][4] = graph[4][5];
       graph[5][5] = 0;
   }
   else if (nombre_sommets ==7){
       graph[0][0] = 0;
       graph[0][1] = rand()%100;
       graph[0][2] = rand()%100;
       graph[0][3] = rand()%100;
       graph[0][4] = rand()%100;
       graph[0][5] = rand()%100;
       graph[0][6] = rand()%100;
       graph[1][0] = graph[0][1];
       graph[1][1] = 0;
       graph[1][2] = rand()%100;
       graph[1][3] = rand()%100;
       graph[1][4] = rand()%100;
       graph[1][5] = rand()%100;
       graph[1][6] = rand()%100;
       graph[2][0] = graph[0][2];
       graph[2][1] = graph[1][2];
       graph[2][2] = 0;
       graph[2][3] = rand()%100;
       graph[2][4] = rand()%100;
       graph[2][5] = rand()%100;
       graph[2][6] = rand()%100;
       graph[3][0] = graph[0][3];
       graph[3][1] = graph[1][3];
       graph[3][2] = graph[2][3];
       graph[3][3] = 0;
       graph[3][4] = rand()%100;
       graph[3][5] = rand()%100;
       graph[3][6] = rand()%100;
       graph[4][0] = graph[0][4];
       graph[4][1] = graph[1][4];
       graph[4][2] = graph[2][4];
       graph[4][3] = graph[3][4];
       graph[4][4] = 0;
       graph[4][5] = rand()%100;
       graph[4][6] = rand()%100;
       graph[5][0] = graph[0][5];
       graph[5][1] = graph[1][5];
       graph[5][2] = graph[2][5];
       graph[5][3] = graph[3][5];
       graph[5][4] = graph[4][5];
       graph[5][5] = 0;
       graph[5][6] = rand()%100;
       graph[6][0] = graph[0][6];
       graph[6][1] = graph[1][6];
       graph[6][2] = graph[2][6];
       graph[6][3] = graph[3][6];
       graph[6][4] = graph[4][6];
       graph[6][5] = graph[5][6];
       graph[6][6] = 0;
   }
}

void GraphWidget::dessinGraphe4Sommets(){
    node1 = new Node(this, "1");
    node2 = new Node(this, "2");
   node3 = new Node(this, "3");
    node4 = new Node(this, "4");
   edge12 = new Edge(node1, node2, graph[0][1]);
    edge23 = new Edge(node2, node3, graph[1][2]);
    edge13 = new Edge(node1, node3, graph[0][2]);
     edge14 = new Edge(node1, node4, graph[0][3]);
      edge24 = new Edge(node2, node4, graph[1][3]);
       edge34 = new Edge(node3, node4, graph[2][3]);
    node1->setPos(-52, -124);
    node2->setPos(-239.5, 60.5);
    node3->setPos(142, 60.5);
    node4->setPos(-52, -14);
    label12 = new QLabel(this);
    label12->setStyleSheet("QLabel {color : black; }");
    int nombre = edge12->getPoid();
    QString str = "";
    str = QString::number(nombre);
    label12->setText(str);
    label12->move(480,320);
    label12->show();
    //--------------------------------

    label23 = new QLabel(this);
    label23->setStyleSheet("QLabel {color : black; }");
    int nombre1 = edge23->getPoid();
    QString str1 = "";
    str1 = QString::number(nombre1);
    label23->setText(str1);
    label23->move(670,560);
    label23->show();
    //--------------------------------

    label13 = new QLabel(this);
    label13->setStyleSheet("QLabel {color : black; }");
    int nombre2 = edge13->getPoid();
    QString str2 = "";
    str2 = QString::number(nombre2);
    label13->setText(str2);
    label13->move(860,320);
    label13->show();

    //--------------------------------

    label14 = new QLabel(this);
    label14->setStyleSheet("QLabel {color : black; }");
    int nombre3 = edge14->getPoid();
    QString str3 = "";
    str3 = QString::number(nombre3);
    label14->setText(str3);
    label14->move(650,280);
    label14->show();
    //--------------------------------

    label24 = new QLabel(this);
    label24->setStyleSheet("QLabel {color : black; }");
    int nombre4 = edge24->getPoid();
    QString str4 = "";
    str4 = QString::number(nombre4);
    label24->setText(str4);
    label24->move(500,430);
    label24->show();
    //--------------------------------

    label34 = new QLabel(this);
    label34->setStyleSheet("QLabel {color : black; }");
    int nombre5 = edge34->getPoid();
    QString str5 = "";
    str5 = QString::number(nombre5);
    label34->setText(str5);
    label34->move(830,430);
    label34->show();
}

void GraphWidget::dessinGraphe5Sommets(){
    node1 = new Node(this, "1");
    node2 = new Node(this, "2");
   node3 = new Node(this, "3");
    node4 = new Node(this, "4");
     node5 = new Node(this, "5");
   edge12 = new Edge(node1, node2, graph[0][1]);
    edge23 = new Edge(node2, node3, graph[1][2]);
    edge13 = new Edge(node1, node3, graph[0][2]);
     edge14 = new Edge(node1, node4, graph[0][3]);
     edge15 = new Edge(node1, node5, graph[0][4]);
      edge24 = new Edge(node2, node4, graph[1][3]);
         edge25 = new Edge(node2, node5, graph[1][4]);
       edge34 = new Edge(node3, node4, graph[2][3]);
       edge35 = new Edge(node3, node5, graph[2][4]);
        edge45 = new Edge(node4, node5, graph[3][4]);
    node1->setPos(-60.5, -189.5);
    node2->setPos(-267, -58.5);
    node3->setPos(137.5,-58.5);
    node4->setPos(-155.5,143);
     node5->setPos(17.5,143);
    label12 = new QLabel(this);
    label12->setStyleSheet("QLabel {color : black; }");
    int nombre = edge12->getPoid();
    QString str = "";
    str = QString::number(nombre);
    label12->setText(str);
    label12->move(425,150);
    label12->show();
    //--------------------------------
    label23 = new QLabel(this);
    label23->setStyleSheet("QLabel {color : black; }");
    int nombre1 = edge23->getPoid();
    QString str1 = "";
    str1 = QString::number(nombre1);
    label23->setText(str1);
    label23->move(648,290);
    label23->show();
    //--------------------------------
    label13 = new QLabel(this);
    label13->setStyleSheet("QLabel {color : black; }");
    int nombre2 = edge13->getPoid();
    QString str2 = "";
    str2 = QString::number(nombre2);
    label13->setText(str2);
    label13->move(860,150);
    label13->show();
    //--------------------------------
    label14 = new QLabel(this);
    label14->setStyleSheet("QLabel {color : black; }");
    int nombre3 = edge14->getPoid();
    QString str3 = "";
    str3 = QString::number(nombre3);
    label14->setText(str3);
    label14->move(535,370);
    label14->show();
    //--------------------------------
    label15 = new QLabel(this);
    label15->setStyleSheet("QLabel {color : black; }");
    int nombre6 = edge15->getPoid();
    QString str6 = "";
    str6 = QString::number(nombre6);
    label15->setText(str6);
    label15->move(750,370);
    label15->show();
    //--------------------------------
    label24 = new QLabel(this);
    label24->setStyleSheet("QLabel {color : black; }");
    int nombre4 = edge24->getPoid();
    QString str4 = "";
    str4 = QString::number(nombre4);
    label24->setText(str4);
    label24->move(325,500);
    label24->show();
    //--------------------------------
    label25 = new QLabel(this);
    label25->setStyleSheet("QLabel {color : black; }");
    int nombre7 = edge25->getPoid();
    QString str7 = "";
    str7 = QString::number(nombre7);
    label25->setText(str7);
    label25->move(537,500);
    label25->show();
    //--------------------------------
    label34 = new QLabel(this);
    label34->setStyleSheet("QLabel {color : black; }");
    int nombre5 = edge34->getPoid();
    QString str5 = "";
    str5 = QString::number(nombre5);
    label34->setText(str5);
    label34->move(740,500);
    label34->show();
    //--------------------------------
    label35 = new QLabel(this);
    label35->setStyleSheet("QLabel {color : black; }");
    int nombre8 = edge35->getPoid();
    QString str8 = "";
    str8 = QString::number(nombre8);
    label35->setText(str8);
    label35->move(950,500);
    label35->show();
    //--------------------------------
    label45 = new QLabel(this);
    label45->setStyleSheet("QLabel {color : black; }");
    int nombre9 = edge45->getPoid();
    QString str9 = "";
    str9 = QString::number(nombre9);
    label45->setText(str9);
    label45->move(648,687);
    label45->show();
}

void GraphWidget::dessinGraphe6Sommets(){
    node1 = new Node(this, "1");
    node2 = new Node(this, "2");
   node3 = new Node(this, "3");
    node4 = new Node(this, "4");
     node5 = new Node(this, "5");
      node6 = new Node(this, "6");
   edge12 = new Edge(node1, node2, graph[0][1]);
    edge23 = new Edge(node2, node3, graph[1][2]);
    edge13 = new Edge(node1, node3, graph[0][2]);
     edge14 = new Edge(node1, node4, graph[0][3]);
     edge15 = new Edge(node1, node5, graph[0][4]);
      edge16 = new Edge(node1, node6, graph[0][5]);
      edge24 = new Edge(node2, node4, graph[1][3]);
         edge25 = new Edge(node2, node5, graph[1][4]);
          edge26 = new Edge(node2, node6, graph[1][5]);
       edge34 = new Edge(node3, node4, graph[2][3]);
       edge35 = new Edge(node3, node5, graph[2][4]);
       edge36 = new Edge(node3, node6, graph[2][5]);
        edge45 = new Edge(node4, node5, graph[3][4]);
        edge46 = new Edge(node4, node6, graph[3][5]);
        edge56 = new Edge(node5, node6, graph[4][5]);
    node1->setPos(-155.5, -189.5);
    node2->setPos(-269.5, -24.5);
    node3->setPos(17.5, -189.5);
    node4->setPos(-155.5,143);
     node5->setPos(17.5,143);
      node6->setPos(130,-24.5);
    label12 = new QLabel(this);
    label12->setStyleSheet("QLabel {color : black; }");
    int nombre = edge12->getPoid();
    QString str = "";
    str = QString::number(nombre);
    label12->setText(str);
    label12->move(345,180);
    label12->show();
    //--------------------------------
    label23 = new QLabel(this);
    label23->setStyleSheet("QLabel {color : black; }");
    int nombre1 = edge23->getPoid();
    QString str1 = "";
    str1 = QString::number(nombre1);
    label23->setText(str1);
    label23->move(500,205);
    label23->show();
    //--------------------------------
    label13 = new QLabel(this);
    label13->setStyleSheet("QLabel {color : black; }");
    int nombre2 = edge13->getPoid();
    QString str2 = "";
    str2 = QString::number(nombre2);
    label13->setText(str2);
    label13->move(630,30);
    label13->show();
    //--------------------------------
    label14 = new QLabel(this);
    label14->setStyleSheet("QLabel {color : black; }");
    int nombre3 = edge14->getPoid();
    QString str3 = "";
    str3 = QString::number(nombre3);
    label14->setText(str3);
    label14->move(452,320);
    label14->show();
    //--------------------------------
    label15 = new QLabel(this);
    label15->setStyleSheet("QLabel {color : black; }");
    int nombre6 = edge15->getPoid();
    QString str6 = "";
    str6 = QString::number(nombre6);
    label15->setText(str6);
    label15->move(600,285);
    label15->show();
    //--------------------------------
    label16 = new QLabel(this);
    label16->setStyleSheet("QLabel {color : black; }");
    int nombre10 = edge16->getPoid();
    QString str10 = "";
    str10 = QString::number(nombre10);
    label16->setText(str10);
    label16->move(768,205);
    label16->show();
    //--------------------------------
    label24 = new QLabel(this);
    label24->setStyleSheet("QLabel {color : black; }");
    int nombre4 = edge24->getPoid();
    QString str4 = "";
    str4 = QString::number(nombre4);
    label24->setText(str4);
    label24->move(330,530);
    label24->show();
    //--------------------------------
    label25 = new QLabel(this);
    label25->setStyleSheet("QLabel {color : black; }");
    int nombre7 = edge25->getPoid();
    QString str7 = "";
    str7 = QString::number(nombre7);
    label25->setText(str7);
    label25->move(505,515);
    label25->show();
    //--------------------------------
    label26 = new QLabel(this);
    label26->setStyleSheet("QLabel {color : black; }");
    int nombre11 = edge26->getPoid();
    QString str11 = "";
    str11 = QString::number(nombre11);
    label26->setText(str11);
    label26->move(610,360);
    label26->show();
    //--------------------------------
    label34 = new QLabel(this);
    label34->setStyleSheet("QLabel {color : black; }");
    int nombre5 = edge34->getPoid();
    QString str5 = "";
    str5 = QString::number(nombre5);
    label34->setText(str5);
    label34->move(600,410);
    label34->show();
    //--------------------------------
    label35 = new QLabel(this);
    label35->setStyleSheet("QLabel {color : black; }");
    int nombre8 = edge35->getPoid();
    QString str8 = "";
    str8 = QString::number(nombre8);
    label35->setText(str8);
    label35->move(818,320);
    label35->show();
    //--------------------------------
    label36 = new QLabel(this);
    label36->setStyleSheet("QLabel {color : black; }");
    int nombre12 = edge36->getPoid();
    QString str12 = "";
    str12 = QString::number(nombre12);
    label36->setText(str12);
    label36->move(920,180);
    label36->show();
    //--------------------------------
    label45 = new QLabel(this);
    label45->setStyleSheet("QLabel {color : black; }");
    int nombre9 = edge45->getPoid();
    QString str9 = "";
    str9 = QString::number(nombre9);
    label45->setText(str9);
    label45->move(648,690);
    label45->show();
    //--------------------------------
    label46 = new QLabel(this);
    label46->setStyleSheet("QLabel {color : black; }");
    int nombre13 = edge46->getPoid();
    QString str13 = "";
    str13 = QString::number(nombre13);
    label46->setText(str13);
    label46->move(765,515);
    label46->show();
    //--------------------------------
    label56 = new QLabel(this);
    label56->setStyleSheet("QLabel {color : black; }");
    int nombre14 = edge56->getPoid();
    QString str14 = "";
    str14 = QString::number(nombre14);
    label56->setText(str14);
    label56->move(940,530);
    label56->show();
}

void GraphWidget::dessinGraphe7Sommets(){
    node1 = new Node(this, "1");
    node2 = new Node(this, "2");
   node3 = new Node(this, "3");
    node4 = new Node(this, "4");
     node5 = new Node(this, "5");
      node6 = new Node(this, "6");
       node7 = new Node(this, "7");
   edge12 = new Edge(node1, node2, graph[0][1]);
    edge23 = new Edge(node2, node3, graph[1][2]);
    edge13 = new Edge(node1, node3, graph[0][2]);
     edge14 = new Edge(node1, node4, graph[0][3]);
     edge15 = new Edge(node1, node5, graph[0][4]);
      edge16 = new Edge(node1, node6, graph[0][5]);
       edge17 = new Edge(node1, node7, graph[0][6]);
      edge24 = new Edge(node2, node4, graph[1][3]);
         edge25 = new Edge(node2, node5, graph[1][4]);
          edge26 = new Edge(node2, node6, graph[1][5]);
           edge27 = new Edge(node2, node7, graph[1][6]);
       edge34 = new Edge(node3, node4, graph[2][3]);
       edge35 = new Edge(node3, node5, graph[2][4]);
       edge36 = new Edge(node3, node6, graph[2][5]);
       edge37 = new Edge(node3, node7, graph[2][6]);
        edge45 = new Edge(node4, node5, graph[3][4]);
        edge46 = new Edge(node4, node6, graph[3][5]);
          edge47 = new Edge(node4, node7, graph[3][6]);
        edge56 = new Edge(node5, node6, graph[4][5]);
         edge57 = new Edge(node5, node7, graph[4][6]);
           edge67 = new Edge(node6, node7, graph[5][6]);
    node1->setPos(-181, -198);
    node2->setPos(-355.5,-25.5);
    node3->setPos(36, -198);
    node4->setPos( -313.5,140.5);
     node5->setPos(154,140.5);
      node6->setPos(209,-25.5);
      node7->setPos(-69.5,195);
    label12 = new QLabel(this);
    label12->setStyleSheet("QLabel {color : black; }");
    int nombre = edge12->getPoid();
    QString str = "";
    str = QString::number(nombre);
    label12->setText(str);
    label12->move(230,180);
    label12->show();
    //--------------------------------
    label23 = new QLabel(this);
    label23->setStyleSheet("QLabel {color : black; }");
    int nombre1 = edge23->getPoid();
    QString str1 = "";
    str1 = QString::number(nombre1);
    label23->setText(str1);
    label23->move(500,160);
    label23->show();
    //--------------------------------
    label13 = new QLabel(this);
    label13->setStyleSheet("QLabel {color : black; }");
    int nombre2 = edge13->getPoid();
    QString str2 = "";
    str2 = QString::number(nombre2);
    label13->setText(str2);
    label13->move(630,10);
    label13->show();
    //--------------------------------
    label14 = new QLabel(this);
    label14->setStyleSheet("QLabel {color : black; }");
    int nombre3 = edge14->getPoid();
    QString str3 = "";
    str3 = QString::number(nombre3);
    label14->setText(str3);
    label14->move(280,320);
    label14->show();
    //--------------------------------
    label15 = new QLabel(this);
    label15->setStyleSheet("QLabel {color : black; }");
    int nombre6 = edge15->getPoid();
    QString str6 = "";
    str6 = QString::number(nombre6);
    label15->setText(str6);
    label15->move(685,285);
    label15->show();
    //--------------------------------
    label16 = new QLabel(this);
    label16->setStyleSheet("QLabel {color : black; }");
    int nombre10 = edge16->getPoid();
    QString str10 = "";
    str10 = QString::number(nombre10);
    label16->setText(str10);
    label16->move(768,168);
    label16->show();
    //--------------------------------
    label17 = new QLabel(this);
    label17->setStyleSheet("QLabel {color : black; }");
    int nombre15 = edge17->getPoid();
    QString str15 = "";
    str15 = QString::number(nombre15);
    label17->setText(str15);
    label17->move(475,290);
    label17->show();
    //--------------------------------
    label24 = new QLabel(this);
    label24->setStyleSheet("QLabel {color : black; }");
    int nombre4 = edge24->getPoid();
    QString str4 = "";
    str4 = QString::number(nombre4);
    label24->setText(str4);
    label24->move(90,530);
    label24->show();
    //--------------------------------
    label25 = new QLabel(this);
    label25->setStyleSheet("QLabel {color : black; }");
    int nombre7 = edge25->getPoid();
    QString str7 = "";
    str7 = QString::number(nombre7);
    label25->setText(str7);
    label25->move(505,500);
    label25->show();
    //--------------------------------
    label26 = new QLabel(this);
    label26->setStyleSheet("QLabel {color : black; }");
    int nombre11 = edge26->getPoid();
    QString str11 = "";
    str11 = QString::number(nombre11);
    label26->setText(str11);
    label26->move(630,355);
    label26->show();
    //--------------------------------
    label27 = new QLabel(this);
    label27->setStyleSheet("QLabel {color : black; }");
    int nombre18 = edge27->getPoid();
    QString str18 = "";
    str18 = QString::number(nombre18);
    label27->setText(str18);
    label27->move(355,580);
    label27->show();
    //--------------------------------
    label34 = new QLabel(this);
    label34->setStyleSheet("QLabel {color : black; }");
    int nombre5 = edge34->getPoid();
    QString str5 = "";
    str5 = QString::number(nombre5);
    label34->setText(str5);
    label34->move(425,410);
    label34->show();
    //--------------------------------
    label35 = new QLabel(this);
    label35->setStyleSheet("QLabel {color : black; }");
    int nombre8 = edge35->getPoid();
    QString str8 = "";
    str8 = QString::number(nombre8);
    label35->setText(str8);
    label35->move(960,320);
    label35->show();
    //--------------------------------
    label36 = new QLabel(this);
    label36->setStyleSheet("QLabel {color : black; }");
    int nombre12 = edge36->getPoid();
    QString str12 = "";
    str12 = QString::number(nombre12);
    label36->setText(str12);
    label36->move(1020,180);
    label36->show();
    //--------------------------------
    label37 = new QLabel(this);
    label37->setStyleSheet("QLabel {color : black; }");
    int nombre19 = edge37->getPoid();
    QString str19 = "";
    str19 = QString::number(nombre19);
    label37->setText(str19);
    label37->move(722,430);
    label37->show();
    //--------------------------------
    label45 = new QLabel(this);
    label45->setStyleSheet("QLabel {color : black; }");
    int nombre9 = edge45->getPoid();
    QString str9 = "";
    str9 = QString::number(nombre9);
    label45->setText(str9);
    label45->move(633,690);
    label45->show();
    //--------------------------------
    label46 = new QLabel(this);
    label46->setStyleSheet("QLabel {color : black; }");
    int nombre13 = edge46->getPoid();
    QString str13 = "";
    str13 = QString::number(nombre13);
    label46->setText(str13);
    label46->move(780,485);
    label46->show();
    //--------------------------------
    label47 = new QLabel(this);
    label47->setStyleSheet("QLabel {color : black; }");
    int nombre20 = edge47->getPoid();
    QString str20 = "";
    str20 = QString::number(nombre20);
    label47->setText(str20);
    label47->move(390,742);
    label47->show();
    //--------------------------------
    label56 = new QLabel(this);
    label56->setStyleSheet("QLabel {color : black; }");
    int nombre14 = edge56->getPoid();
    QString str14 = "";
    str14 = QString::number(nombre14);
    label56->setText(str14);
    label56->move(1150,530);
    label56->show();
    //--------------------------------
    label57 = new QLabel(this);
    label57->setStyleSheet("QLabel {color : black; }");
    int nombre21 = edge57->getPoid();
    QString str21 = "";
    str21 = QString::number(nombre21);
    label57->setText(str21);
    label57->move(850,745);
    label57->show();
    //--------------------------------
    label67 = new QLabel(this);
    label67->setStyleSheet("QLabel {color : black; }");
    int nombre22 = edge67->getPoid();
    QString str22 = "";
    str22 = QString::number(nombre22);
    label67->setText(str22);
    label67->move(905,580);
    label67->show();
}

void GraphWidget::afficherSolution4Sommets(int g1, int g2, int g3, int g4){
    edge12->hide();
    label12->hide();
    edge13->hide();
    label13->hide();
    edge14->hide();
    label14->hide();
    edge23->hide();
    label23->hide();
    edge24->hide();
    label24->hide();
    edge34->hide();
    label34->hide();
    if (g1 == 0){
        if (g2 ==1){ edge12->show(); label12->show();}
            else if (g2 ==2){ edge13->show();  label13->show();}
               else if (g2 ==3){ edge14->show();  label14->show();}
    }
    else if (g1 == 1){
        if (g2 ==2){ edge23->show(); label23->show();}
            else if (g2 ==3){ edge24->show(); label24->show();}
                else if (g2 ==0){ edge12->show(); label12->show();}
    }
    else if (g1 == 2){
                if (g2 ==0){ edge13->show(); label13->show();}
                    else if (g2 ==1){ edge23->show(); label23->show();}
                else if (g2 ==3){ edge34->show(); label34->show();}
    }
    else if (g1 == 3){
            if (g2 ==2){ edge34->show(); label34->show();}
                else if (g2 ==1){ edge24->show(); label24->show();}
                    else if (g2 ==0){ edge14->show(); label14->show();}
    }
    if (g2 == 0){
        if (g3 ==1){ edge12->show(); label12->show();}
            else if (g3 ==2){ edge13->show(); label13->show();}
               else if (g3 ==3){ edge14->show(); label14->show();}
    }
    else if (g2 == 1){
        if (g3 ==2){ edge23->show(); label23->show();}
            else if (g3 ==3){ edge24->show(); label24->show();}
                else if (g3 ==0){ edge12->show(); label12->show();}
    }
    else if (g2 == 2){
        if (g3 ==3){ edge34->show(); label34->show();}
                else if (g3 ==0){ edge13->show(); label13->show();}
                    else if (g3 ==1){ edge23->show(); label23->show();}

    }
    else if (g2 == 3){
             if (g3 ==2){ edge34->show(); label34->show();}
                else if (g3 ==1){ edge24->show(); label24->show();}
                    else if (g3 ==0){ edge14->show(); label14->show();}
    }
    if (g3 == 0){
        if (g4 ==1){ edge12->show(); label12->show();}
            else if (g4 ==2){ edge13->show(); label13->show();}
               else if (g4 ==3){ edge14->show(); label14->show();}
    }
    else if (g3 == 1){
        if (g4 ==2){ edge23->show(); label23->show();}
            else if (g4 ==3){ edge24->show(); label24->show();}
                else if (g4 ==0){ edge12->show(); label12->show();}
    }
    else if (g3 == 2){
        if (g4 ==3){ edge34->show(); label34->show();}
                else if (g4 ==0){ edge13->show(); label13->show();}
                    else if (g4 ==1){ edge23->show(); label23->show();}

    }
    else if (g3 == 3){
            if (g4 ==2){ edge34->show(); label34->show();}
                else if (g4 ==1){ edge24->show(); label24->show();}
                    else if (g4 ==0){ edge14->show(); label14->show();}
    }
    if (g4 == 0){
        if (g1 ==1){ edge12->show(); label12->show();}
            else if (g1 ==2){ edge13->show(); label13->show();}
               else if (g1 ==3){ edge14->show(); label14->show();}
    }
    else if (g4 == 1){
        if (g1 ==2){ edge23->show(); label23->show();}
            else if (g1 ==3){ edge24->show(); label24->show();}
                else if (g1 ==0){ edge12->show(); label12->show();}
    }
    else if (g4 == 2){
        if (g1 ==3){ edge34->show(); label34->show();}
                else if (g1 ==0){ edge13->show(); label13->show();}
                    else if (g1 ==1){ edge23->show(); label23->show();}

    }
    else if (g4 == 3){
            if (g1 ==2){ edge34->show(); label34->show();}
                else if (g1 ==1){ edge24->show(); label24->show();}
                    else if (g1 ==0){ edge14->show(); label14->show();}
    }

}

void GraphWidget::afficherSolution5Sommets(int g1, int g2, int g3, int g4, int g5){
    edge12->hide();
    label12->hide();
    edge13->hide();
    label13->hide();
    edge14->hide();
    label14->hide();
    edge23->hide();
    label23->hide();
    edge24->hide();
    label24->hide();
    edge34->hide();
    label34->hide();
    edge15->hide();
    label15->hide();
    edge25->hide();
    label25->hide();
    edge35->hide();
    label35->hide();
    edge45->hide();
    label45->hide();
    if (g1 == 0){
        if (g2 ==1){ edge12->show(); label12->show();}
            else if (g2 ==2){ edge13->show();  label13->show();}
               else if (g2 ==3){ edge14->show();  label14->show();}
                    else if (g2 ==4){ edge15->show();  label15->show();}
    }
    else if (g1 == 1){
        if (g2 ==2){ edge23->show(); label23->show();}
            else if (g2 ==3){ edge24->show(); label24->show();}
                else if (g2 ==0){ edge12->show(); label12->show();}
                    else if (g2 ==4){ edge25->show(); label25->show();}
    }
    else if (g1 == 2){
                if (g2 ==0){ edge13->show(); label13->show();}
                    else if (g2 ==1){ edge23->show(); label23->show();}
                else if (g2 ==3){ edge34->show(); label34->show();}
                else if (g2 ==4){ edge35->show(); label35->show();}
    }
    else if (g1 == 3){
            if (g2 ==2){ edge34->show(); label34->show();}
                else if (g2 ==1){ edge24->show(); label24->show();}
                    else if (g2 ==0){ edge14->show(); label14->show();}
                        else if (g2 ==4){ edge45->show(); label45->show();}
    }
    else if (g1 == 4){
            if (g2 ==2){ edge35->show(); label35->show();}
                else if (g2 ==1){ edge25->show(); label25->show();}
                    else if (g2 ==0){ edge15->show(); label15->show();}
                        else if (g2 ==3){ edge45->show(); label45->show();}
    }

    if (g2 == 0){
        if (g3 ==1){ edge12->show(); label12->show();}
            else if (g3 ==2){ edge13->show(); label13->show();}
               else if (g3 ==3){ edge14->show(); label14->show();}
                   else if (g3 ==4){ edge15->show(); label15->show();}
    }
    else if (g2 == 1){
        if (g3 ==2){ edge23->show(); label23->show();}
            else if (g3 ==3){ edge24->show(); label24->show();}
                else if (g3 ==0){ edge12->show(); label12->show();}
                    else if (g3 ==4){ edge25->show(); label25->show();}
    }
    else if (g2 == 2){
        if (g3 ==3){ edge34->show(); label34->show();}
                else if (g3 ==0){ edge13->show(); label13->show();}
                    else if (g3 ==1){ edge23->show(); label23->show();}
                        else if (g3 ==4){ edge35->show(); label35->show();}

    }
    else if (g2 == 3){
             if (g3 ==2){ edge34->show(); label34->show();}
                else if (g3 ==1){ edge24->show(); label24->show();}
                    else if (g3 ==0){ edge14->show(); label14->show();}
                        else if (g3 ==4){ edge45->show(); label45->show();}
    }
    else if (g2 == 4){
             if (g3 ==2){ edge35->show(); label35->show();}
                else if (g3 ==1){ edge25->show(); label25->show();}
                    else if (g3 ==0){ edge15->show(); label15->show();}
                        else if (g3 ==3){ edge45->show(); label45->show();}
    }

    if (g3 == 0){
        if (g4 ==1){ edge12->show(); label12->show();}
            else if (g4 ==2){ edge13->show(); label13->show();}
               else if (g4 ==3){ edge14->show(); label14->show();}
                else if (g4 ==4){ edge15->show(); label15->show();}
    }
    else if (g3 == 1){
        if (g4 ==2){ edge23->show(); label23->show();}
            else if (g4 ==3){ edge24->show(); label24->show();}
                else if (g4 ==0){ edge12->show(); label12->show();}
                    else if (g4 ==4){ edge25->show(); label25->show();}
    }
    else if (g3 == 2){
        if (g4 ==3){ edge34->show(); label34->show();}
                else if (g4 ==0){ edge13->show(); label13->show();}
                    else if (g4 ==1){ edge23->show(); label23->show();}
                        else if (g4 ==4){ edge35->show(); label35->show();}

    }
    else if (g3 == 3){
            if (g4 ==2){ edge34->show(); label34->show();}
                else if (g4 ==1){ edge24->show(); label24->show();}
                    else if (g4 ==0){ edge14->show(); label14->show();}
                        else if (g4 ==4){ edge45->show(); label45->show();}
    }
    else if (g3 == 4){
            if (g4 ==2){ edge35->show(); label35->show();}
                else if (g4 ==1){ edge25->show(); label25->show();}
                    else if (g4 ==0){ edge15->show(); label15->show();}
                        else if (g4 ==3){ edge45->show(); label45->show();}
    }
    if (g4 == 0){
        if (g5 ==1){ edge12->show(); label12->show();}
            else if (g5 ==2){ edge13->show(); label13->show();}
               else if (g5 ==3){ edge14->show(); label14->show();}
                else if (g5 ==4){ edge15->show(); label15->show();}
    }
    else if (g4 == 1){
        if (g5 ==2){ edge23->show(); label23->show();}
            else if (g5 ==3){ edge24->show(); label24->show();}
                else if (g5 ==0){ edge12->show(); label12->show();}
                    else if (g5 ==4){ edge25->show(); label25->show();}
    }
    else if (g4 == 2){
        if (g5 ==3){ edge34->show(); label34->show();}
                else if (g5 ==0){ edge13->show(); label13->show();}
                    else if (g5 ==1){ edge23->show(); label23->show();}
                         else if (g5 ==4){ edge35->show(); label35->show();}

    }
    else if (g4 == 3){
            if (g5 ==2){ edge34->show(); label34->show();}
                else if (g5 ==1){ edge24->show(); label24->show();}
                    else if (g5 ==0){ edge14->show(); label14->show();}
                        else if (g5 ==4){ edge45->show(); label45->show();}
    }
    else if (g4 == 4){
            if (g5 ==2){ edge35->show(); label35->show();}
                else if (g5 ==1){ edge25->show(); label25->show();}
                    else if (g5 ==0){ edge15->show(); label15->show();}
                        else if (g5 ==3){ edge45->show(); label45->show();}
    }
    if (g5 == 0){
        if (g1 ==1){ edge12->show(); label12->show();}
            else if (g1 ==2){ edge13->show(); label13->show();}
               else if (g1 ==3){ edge14->show(); label14->show();}
                else if (g1 ==4){ edge15->show(); label15->show();}
    }
    else if (g5 == 1){
        if (g1 ==2){ edge23->show(); label23->show();}
            else if (g1 ==3){ edge24->show(); label24->show();}
                else if (g1 ==0){ edge12->show(); label12->show();}
                    else if (g1 ==4){ edge25->show(); label25->show();}
    }
    else if (g5 == 2){
        if (g1 ==3){ edge34->show(); label34->show();}
                else if (g1 ==0){ edge13->show(); label13->show();}
                    else if (g1 ==1){ edge23->show(); label23->show();}
                         else if (g1 ==4){ edge35->show(); label35->show();}

    }
    else if (g5 == 3){
            if (g1 ==2){ edge34->show(); label34->show();}
                else if (g1 ==1){ edge24->show(); label24->show();}
                    else if (g1 ==0){ edge14->show(); label14->show();}
                        else if (g1 ==4){ edge45->show(); label45->show();}
    }
    else if (g5 == 4){
            if (g1 ==2){ edge35->show(); label35->show();}
                else if (g1 ==1){ edge25->show(); label25->show();}
                    else if (g1 ==0){ edge15->show(); label15->show();}
                        else if (g1 ==3){ edge45->show(); label45->show();}
    }

}

void GraphWidget::afficherSolution6Sommets(int g1, int g2, int g3, int g4, int g5, int g6){
    edge12->hide();
    label12->hide();
    edge13->hide();
    label13->hide();
    edge14->hide();
    label14->hide();
    edge23->hide();
    label23->hide();
    edge24->hide();
    label24->hide();
    edge34->hide();
    label34->hide();
    edge15->hide();
    label15->hide();
    edge16->hide();
    label16->hide();
    edge25->hide();
    label25->hide();
    edge26->hide();
    label26->hide();
    edge35->hide();
    label35->hide();
    edge36->hide();
    label36->hide();
    edge45->hide();
    label45->hide();
    edge46->hide();
    label46->hide();
    edge56->hide();
    label56->hide();
    if (g1 == 0){
        if (g2 ==1){ edge12->show(); label12->show();}
            else if (g2 ==2){ edge13->show();  label13->show();}
               else if (g2 ==3){ edge14->show();  label14->show();}
                    else if (g2 ==4){ edge15->show();  label15->show();}
                        else if (g2 ==5){ edge16->show();  label16->show();}
    }
    else if (g1 == 1){
        if (g2 ==2){ edge23->show(); label23->show();}
            else if (g2 ==3){ edge24->show(); label24->show();}
                else if (g2 ==0){ edge12->show(); label12->show();}
                    else if (g2 ==4){ edge25->show(); label25->show();}
                        else if (g2 ==5){ edge26->show(); label26->show();}
    }
    else if (g1 == 2){
                if (g2 ==0){ edge13->show(); label13->show();}
                    else if (g2 ==1){ edge23->show(); label23->show();}
                else if (g2 ==3){ edge34->show(); label34->show();}
                else if (g2 ==4){ edge35->show(); label35->show();}
                    else if (g2 ==5){ edge36->show(); label36->show();}
    }
    else if (g1 == 3){
            if (g2 ==2){ edge34->show(); label34->show();}
                else if (g2 ==1){ edge24->show(); label24->show();}
                    else if (g2 ==0){ edge14->show(); label14->show();}
                        else if (g2 ==4){ edge45->show(); label45->show();}
                    else if (g2 ==5){ edge46->show(); label46->show();}
    }
    else if (g1 == 4){
            if (g2 ==2){ edge35->show(); label35->show();}
                else if (g2 ==1){ edge25->show(); label25->show();}
                    else if (g2 ==0){ edge15->show(); label15->show();}
                        else if (g2 ==3){ edge45->show(); label45->show();}
                        else if (g2 ==5){ edge56->show(); label56->show();}
    }
    else if (g1 == 5){
            if (g2 ==2){ edge36->show(); label36->show();}
                else if (g2 ==1){ edge26->show(); label26->show();}
                    else if (g2 ==0){ edge16->show(); label16->show();}
                        else if (g2 ==3){ edge46->show(); label46->show();}
                        else if (g2 ==4){ edge56->show(); label56->show();}
    }

    if (g2 == 0){
        if (g3 ==1){ edge12->show(); label12->show();}
            else if (g3 ==2){ edge13->show(); label13->show();}
               else if (g3 ==3){ edge14->show(); label14->show();}
                   else if (g3 ==4){ edge15->show(); label15->show();}
                        else if (g3 ==5){ edge16->show(); label16->show();}
    }
    else if (g2 == 1){
        if (g3 ==2){ edge23->show(); label23->show();}
            else if (g3 ==3){ edge24->show(); label24->show();}
                else if (g3 ==0){ edge12->show(); label12->show();}
                    else if (g3 ==4){ edge25->show(); label25->show();}
                        else if (g3 ==5){ edge26->show(); label26->show();}
    }
    else if (g2 == 2){
        if (g3 ==3){ edge34->show(); label34->show();}
                else if (g3 ==0){ edge13->show(); label13->show();}
                    else if (g3 ==1){ edge23->show(); label23->show();}
                        else if (g3 ==4){ edge35->show(); label35->show();}
                            else if (g3 ==5){ edge36->show(); label36->show();}

    }
    else if (g2 == 3){
             if (g3 ==2){ edge34->show(); label34->show();}
                else if (g3 ==1){ edge24->show(); label24->show();}
                    else if (g3 ==0){ edge14->show(); label14->show();}
                        else if (g3 ==4){ edge45->show(); label45->show();}
                            else if (g3 ==5){ edge46->show(); label46->show();}
    }
    else if (g2 == 4){
             if (g3 ==2){ edge35->show(); label35->show();}
                else if (g3 ==1){ edge25->show(); label25->show();}
                    else if (g3 ==0){ edge15->show(); label15->show();}
                        else if (g3 ==3){ edge45->show(); label45->show();}
                            else if (g3 ==5){ edge56->show(); label56->show();}
    }
    else if (g2 == 5){
             if (g3 ==2){ edge36->show(); label36->show();}
                else if (g3 ==1){ edge26->show(); label26->show();}
                    else if (g3 ==0){ edge16->show(); label16->show();}
                        else if (g3 ==3){ edge46->show(); label46->show();}
                            else if (g3 ==4){ edge56->show(); label56->show();}
    }

    if (g3 == 0){
        if (g4 ==1){ edge12->show(); label12->show();}
            else if (g4 ==2){ edge13->show(); label13->show();}
               else if (g4 ==3){ edge14->show(); label14->show();}
                else if (g4 ==4){ edge15->show(); label15->show();}
                    else if (g4 ==5){ edge16->show(); label16->show();}
    }
    else if (g3 == 1){
        if (g4 ==2){ edge23->show(); label23->show();}
            else if (g4 ==3){ edge24->show(); label24->show();}
                else if (g4 ==0){ edge12->show(); label12->show();}
                    else if (g4 ==4){ edge25->show(); label25->show();}
                        else if (g4 ==5){ edge26->show(); label26->show();}
    }
    else if (g3 == 2){
        if (g4 ==3){ edge34->show(); label34->show();}
                else if (g4 ==0){ edge13->show(); label13->show();}
                    else if (g4 ==1){ edge23->show(); label23->show();}
                        else if (g4 ==4){ edge35->show(); label35->show();}
                            else if (g4 ==5){ edge36->show(); label36->show();}

    }
    else if (g3 == 3){
            if (g4 ==2){ edge34->show(); label34->show();}
                else if (g4 ==1){ edge24->show(); label24->show();}
                    else if (g4 ==0){ edge14->show(); label14->show();}
                        else if (g4 ==4){ edge45->show(); label45->show();}
                            else if (g4 ==5){ edge46->show(); label46->show();}
    }
    else if (g3 == 4){
            if (g4 ==2){ edge35->show(); label35->show();}
                else if (g4 ==1){ edge25->show(); label25->show();}
                    else if (g4 ==0){ edge15->show(); label15->show();}
                        else if (g4 ==3){ edge45->show(); label45->show();}
                            else if (g4 ==5){ edge56->show(); label56->show();}
    }
    else if (g3 == 5){
            if (g4 ==2){ edge36->show(); label36->show();}
                else if (g4 ==1){ edge26->show(); label26->show();}
                    else if (g4 ==0){ edge16->show(); label16->show();}
                        else if (g4 ==3){ edge46->show(); label46->show();}
                            else if (g4 ==4){ edge56->show(); label56->show();}
    }
    if (g4 == 0){
        if (g5 ==1){ edge12->show(); label12->show();}
            else if (g5 ==2){ edge13->show(); label13->show();}
               else if (g5 ==3){ edge14->show(); label14->show();}
                else if (g5 ==4){ edge15->show(); label15->show();}
                    else if (g5 ==5){ edge16->show(); label16->show();}
    }
    else if (g4 == 1){
        if (g5 ==2){ edge23->show(); label23->show();}
            else if (g5 ==3){ edge24->show(); label24->show();}
                else if (g5 ==0){ edge12->show(); label12->show();}
                    else if (g5 ==4){ edge25->show(); label25->show();}
                        else if (g5 ==5){ edge26->show(); label26->show();}
    }
    else if (g4 == 2){
        if (g5 ==3){ edge34->show(); label34->show();}
                else if (g5 ==0){ edge13->show(); label13->show();}
                    else if (g5 ==1){ edge23->show(); label23->show();}
                         else if (g5 ==4){ edge35->show(); label35->show();}
                            else if (g5 ==5){ edge36->show(); label36->show();}

    }
    else if (g4 == 3){
            if (g5 ==2){ edge34->show(); label34->show();}
                else if (g5 ==1){ edge24->show(); label24->show();}
                    else if (g5 ==0){ edge14->show(); label14->show();}
                        else if (g5 ==4){ edge45->show(); label45->show();}
                            else if (g5 ==5){ edge46->show(); label46->show();}
    }
    else if (g4 == 4){
            if (g5 ==2){ edge35->show(); label35->show();}
                else if (g5 ==1){ edge25->show(); label25->show();}
                    else if (g5 ==0){ edge15->show(); label15->show();}
                        else if (g5 ==3){ edge45->show(); label45->show();}
                            else if (g5 ==5){ edge56->show(); label56->show();}
    }
    else if (g4 == 5){
            if (g5 ==2){ edge36->show(); label36->show();}
                else if (g5 ==1){ edge26->show(); label26->show();}
                    else if (g5 ==0){ edge16->show(); label16->show();}
                        else if (g5 ==3){ edge46->show(); label46->show();}
                            else if (g5 ==4){ edge56->show(); label56->show();}
    }
    if (g5 == 0){
        if (g6 ==1){ edge12->show(); label12->show();}
            else if (g6 ==2){ edge13->show(); label13->show();}
               else if (g6 ==3){ edge14->show(); label14->show();}
                else if (g6 ==4){ edge15->show(); label15->show();}
                    else if (g6 ==5){ edge16->show(); label16->show();}
    }
    else if (g5 == 1){
        if (g6 ==2){ edge23->show(); label23->show();}
            else if (g6 ==3){ edge24->show(); label24->show();}
                else if (g6 ==0){ edge12->show(); label12->show();}
                    else if (g6 ==4){ edge25->show(); label25->show();}
                        else if (g6 ==5){ edge26->show(); label26->show();}
    }
    else if (g5 == 2){
        if (g6 ==3){ edge34->show(); label34->show();}
                else if (g6 ==0){ edge13->show(); label13->show();}
                    else if (g6 ==1){ edge23->show(); label23->show();}
                         else if (g6 ==4){ edge35->show(); label35->show();}
                            else if (g6 ==5){ edge36->show(); label36->show();}

    }
    else if (g5 == 3){
            if (g6 ==2){ edge34->show(); label34->show();}
                else if (g6 ==1){ edge24->show(); label24->show();}
                    else if (g6 ==0){ edge14->show(); label14->show();}
                        else if (g6 ==4){ edge45->show(); label45->show();}
            else if (g6 ==5){ edge46->show(); label46->show();}
    }
    else if (g5 == 4){
            if (g6 ==2){ edge35->show(); label35->show();}
                else if (g6 ==1){ edge25->show(); label25->show();}
                    else if (g6 ==0){ edge15->show(); label15->show();}
                        else if (g6 ==3){ edge45->show(); label45->show();}
                            else if (g6 ==5){ edge56->show(); label56->show();}
    }
    else if (g5 == 5){
            if (g6 ==2){ edge36->show(); label36->show();}
                else if (g6 ==1){ edge26->show(); label26->show();}
                    else if (g6 ==0){ edge16->show(); label16->show();}
                        else if (g6 ==3){ edge46->show(); label46->show();}
                            else if (g6 ==4){ edge56->show(); label56->show();}
    }
    if (g6 == 0){
        if (g1 ==1){ edge12->show(); label12->show();}
            else if (g1 ==2){ edge13->show(); label13->show();}
               else if (g1 ==3){ edge14->show(); label14->show();}
                else if (g1 ==4){ edge15->show(); label15->show();}
                    else if (g1 ==5){ edge16->show(); label16->show();}
    }
    else if (g6 == 1){
        if (g1 ==2){ edge23->show(); label23->show();}
            else if (g1 ==3){ edge24->show(); label24->show();}
                else if (g1 ==0){ edge12->show(); label12->show();}
                    else if (g1 ==4){ edge25->show(); label25->show();}
                        else if (g1 ==5){ edge26->show(); label26->show();}
    }
    else if (g6 == 2){
        if (g1 ==3){ edge34->show(); label34->show();}
                else if (g1 ==0){ edge13->show(); label13->show();}
                    else if (g1 ==1){ edge23->show(); label23->show();}
                         else if (g1 ==4){ edge35->show(); label35->show();}
                            else if (g1 ==5){ edge36->show(); label36->show();}

    }
    else if (g6 == 3){
            if (g1 ==2){ edge34->show(); label34->show();}
                else if (g1 ==1){ edge24->show(); label24->show();}
                    else if (g1 ==0){ edge14->show(); label14->show();}
                        else if (g1 ==4){ edge45->show(); label45->show();}
            else if (g1 ==5){ edge46->show(); label46->show();}
    }
    else if (g6 == 4){
            if (g1 ==2){ edge35->show(); label35->show();}
                else if (g1 ==1){ edge25->show(); label25->show();}
                    else if (g1 ==0){ edge15->show(); label15->show();}
                        else if (g1 ==3){ edge45->show(); label45->show();}
                            else if (g1 ==5){ edge56->show(); label56->show();}
    }
    else if (g6 == 5){
            if (g1 ==2){ edge36->show(); label36->show();}
                else if (g1 ==1){ edge26->show(); label26->show();}
                    else if (g1 ==0){ edge16->show(); label16->show();}
                        else if (g1 ==3){ edge46->show(); label46->show();}
                            else if (g1 ==4){ edge56->show(); label56->show();}
    }


}

void GraphWidget::afficherSolution7Sommets(int g1, int g2, int g3, int g4, int g5, int g6, int g7){
    edge12->hide();
    label12->hide();
    edge13->hide();
    label13->hide();
    edge14->hide();
    label14->hide();
    edge23->hide();
    label23->hide();
    edge24->hide();
    label24->hide();
    edge34->hide();
    label34->hide();
    edge15->hide();
    label15->hide();
    edge16->hide();
    label16->hide();
    edge17->hide();
    label17->hide();
    edge25->hide();
    label25->hide();
    edge26->hide();
    label26->hide();
    edge27->hide();
    label27->hide();
    edge35->hide();
    label35->hide();
    edge36->hide();
    label36->hide();
    edge37->hide();
    label37->hide();
    edge45->hide();
    label45->hide();
    edge46->hide();
    label46->hide();
    edge47->hide();
    label47->hide();
    edge56->hide();
    label56->hide();
    edge57->hide();
    label57->hide();
    edge67->hide();
    label67->hide();
    if (g1 == 0){
        if (g2 ==1){ edge12->show(); label12->show();}
            else if (g2 ==2){ edge13->show();  label13->show();}
               else if (g2 ==3){ edge14->show();  label14->show();}
                    else if (g2 ==4){ edge15->show();  label15->show();}
                        else if (g2 ==5){ edge16->show();  label16->show();}
                            else if (g2 ==6){ edge17->show();  label17->show();}
    }
    else if (g1 == 1){
        if (g2 ==2){ edge23->show(); label23->show();}
            else if (g2 ==3){ edge24->show(); label24->show();}
                else if (g2 ==0){ edge12->show(); label12->show();}
                    else if (g2 ==4){ edge25->show(); label25->show();}
                        else if (g2 ==5){ edge26->show(); label26->show();}
                            else if (g2 ==6){ edge27->show(); label27->show();}
    }
    else if (g1 == 2){
                if (g2 ==0){ edge13->show(); label13->show();}
                    else if (g2 ==1){ edge23->show(); label23->show();}
                else if (g2 ==3){ edge34->show(); label34->show();}
                else if (g2 ==4){ edge35->show(); label35->show();}
                    else if (g2 ==5){ edge36->show(); label36->show();}
                    else if (g2 ==6){ edge37->show(); label37->show();}
    }
    else if (g1 == 3){
            if (g2 ==2){ edge34->show(); label34->show();}
                else if (g2 ==1){ edge24->show(); label24->show();}
                    else if (g2 ==0){ edge14->show(); label14->show();}
                        else if (g2 ==4){ edge45->show(); label45->show();}
                    else if (g2 ==5){ edge46->show(); label46->show();}
                else if (g2 ==6){ edge47->show(); label47->show();}
    }
    else if (g1 == 4){
            if (g2 ==2){ edge35->show(); label35->show();}
                else if (g2 ==1){ edge25->show(); label25->show();}
                    else if (g2 ==0){ edge15->show(); label15->show();}
                        else if (g2 ==3){ edge45->show(); label45->show();}
                        else if (g2 ==5){ edge56->show(); label56->show();}
            else if (g2 ==6){ edge57->show(); label57->show();}
    }
    else if (g1 == 5){
            if (g2 ==2){ edge36->show(); label36->show();}
                else if (g2 ==1){ edge26->show(); label26->show();}
                    else if (g2 ==0){ edge16->show(); label16->show();}
                        else if (g2 ==3){ edge46->show(); label46->show();}
                        else if (g2 ==4){ edge56->show(); label56->show();}
                 else if (g2 ==6){ edge67->show(); label67->show();}
    }
    else if (g1 == 6){
            if (g2 ==2){ edge37->show(); label37->show();}
                else if (g2 ==1){ edge27->show(); label27->show();}
                    else if (g2 ==0){ edge17->show(); label17->show();}
                        else if (g2 ==3){ edge47->show(); label47->show();}
                        else if (g2 ==4){ edge57->show(); label57->show();}
                 else if (g2 ==5){ edge67->show(); label67->show();}
    }

    if (g2 == 0){
        if (g3 ==1){ edge12->show(); label12->show();}
            else if (g3 ==2){ edge13->show(); label13->show();}
               else if (g3 ==3){ edge14->show(); label14->show();}
                   else if (g3 ==4){ edge15->show(); label15->show();}
                        else if (g3 ==5){ edge16->show(); label16->show();}
            else if (g3 ==6){ edge17->show(); label17->show();}
    }
    else if (g2 == 1){
        if (g3 ==2){ edge23->show(); label23->show();}
            else if (g3 ==3){ edge24->show(); label24->show();}
                else if (g3 ==0){ edge12->show(); label12->show();}
                    else if (g3 ==4){ edge25->show(); label25->show();}
                        else if (g3 ==5){ edge26->show(); label26->show();}
            else if (g3 ==6){ edge27->show(); label27->show();}
    }
    else if (g2 == 2){
        if (g3 ==3){ edge34->show(); label34->show();}
                else if (g3 ==0){ edge13->show(); label13->show();}
                    else if (g3 ==1){ edge23->show(); label23->show();}
                        else if (g3 ==4){ edge35->show(); label35->show();}
                            else if (g3 ==5){ edge36->show(); label36->show();}
                                else if (g3 ==6){ edge37->show(); label37->show();}

    }
    else if (g2 == 3){
             if (g3 ==2){ edge34->show(); label34->show();}
                else if (g3 ==1){ edge24->show(); label24->show();}
                    else if (g3 ==0){ edge14->show(); label14->show();}
                        else if (g3 ==4){ edge45->show(); label45->show();}
                            else if (g3 ==5){ edge46->show(); label46->show();}
                                else if (g3 ==6){ edge47->show(); label47->show();}
    }
    else if (g2 == 4){
             if (g3 ==2){ edge35->show(); label35->show();}
                else if (g3 ==1){ edge25->show(); label25->show();}
                    else if (g3 ==0){ edge15->show(); label15->show();}
                        else if (g3 ==3){ edge45->show(); label45->show();}
                            else if (g3 ==5){ edge56->show(); label56->show();}
                                else if (g3 ==6){ edge57->show(); label57->show();}
    }
    else if (g2 == 5){
             if (g3 ==2){ edge36->show(); label36->show();}
                else if (g3 ==1){ edge26->show(); label26->show();}
                    else if (g3 ==0){ edge16->show(); label16->show();}
                        else if (g3 ==3){ edge46->show(); label46->show();}
                            else if (g3 ==4){ edge56->show(); label56->show();}
                                else if (g3 ==6){ edge67->show(); label67->show();}
    }
    else if (g2 == 6){
             if (g3 ==2){ edge37->show(); label37->show();}
                else if (g3 ==1){ edge27->show(); label27->show();}
                    else if (g3 ==0){ edge17->show(); label17->show();}
                        else if (g3 ==3){ edge47->show(); label47->show();}
                            else if (g3 ==4){ edge57->show(); label57->show();}
                                else if (g3 ==5){ edge67->show(); label67->show();}
    }

    if (g3 == 0){
        if (g4 ==1){ edge12->show(); label12->show();}
            else if (g4 ==2){ edge13->show(); label13->show();}
               else if (g4 ==3){ edge14->show(); label14->show();}
                else if (g4 ==4){ edge15->show(); label15->show();}
                    else if (g4 ==5){ edge16->show(); label16->show();}
                        else if (g4 ==6){ edge17->show(); label17->show();}
    }
    else if (g3 == 1){
        if (g4 ==2){ edge23->show(); label23->show();}
            else if (g4 ==3){ edge24->show(); label24->show();}
                else if (g4 ==0){ edge12->show(); label12->show();}
                    else if (g4 ==4){ edge25->show(); label25->show();}
                        else if (g4 ==5){ edge26->show(); label26->show();}
                            else if (g4 ==6){ edge27->show(); label27->show();}
    }
    else if (g3 == 2){
        if (g4 ==3){ edge34->show(); label34->show();}
                else if (g4 ==0){ edge13->show(); label13->show();}
                    else if (g4 ==1){ edge23->show(); label23->show();}
                        else if (g4 ==4){ edge35->show(); label35->show();}
                            else if (g4 ==5){ edge36->show(); label36->show();}
                                else if (g4 ==6){ edge37->show(); label37->show();}

    }
    else if (g3 == 3){
            if (g4 ==2){ edge34->show(); label34->show();}
                else if (g4 ==1){ edge24->show(); label24->show();}
                    else if (g4 ==0){ edge14->show(); label14->show();}
                        else if (g4 ==4){ edge45->show(); label45->show();}
                            else if (g4 ==5){ edge46->show(); label46->show();}
                                else if (g4 ==6){ edge47->show(); label47->show();}
    }
    else if (g3 == 4){
            if (g4 ==2){ edge35->show(); label35->show();}
                else if (g4 ==1){ edge25->show(); label25->show();}
                    else if (g4 ==0){ edge15->show(); label15->show();}
                        else if (g4 ==3){ edge45->show(); label45->show();}
                            else if (g4 ==5){ edge56->show(); label56->show();}
                                else if (g4 ==6){ edge57->show(); label57->show();}
    }
    else if (g3 == 5){
            if (g4 ==2){ edge36->show(); label36->show();}
                else if (g4 ==1){ edge26->show(); label26->show();}
                    else if (g4 ==0){ edge16->show(); label16->show();}
                        else if (g4 ==3){ edge46->show(); label46->show();}
                            else if (g4 ==4){ edge56->show(); label56->show();}
                                else if (g4 ==6){ edge67->show(); label67->show();}
    }
    else if (g3 == 6){
            if (g4 ==2){ edge37->show(); label37->show();}
                else if (g4 ==1){ edge27->show(); label27->show();}
                    else if (g4 ==0){ edge17->show(); label17->show();}
                        else if (g4 ==3){ edge47->show(); label47->show();}
                            else if (g4 ==4){ edge57->show(); label57->show();}
                                else if (g4 ==5){ edge67->show(); label67->show();}
    }
    if (g4 == 0){
        if (g5 ==1){ edge12->show(); label12->show();}
            else if (g5 ==2){ edge13->show(); label13->show();}
               else if (g5 ==3){ edge14->show(); label14->show();}
                else if (g5 ==4){ edge15->show(); label15->show();}
                    else if (g5 ==5){ edge16->show(); label16->show();}
                        else if (g5 ==6){ edge17->show(); label17->show();}
    }
    else if (g4 == 1){
        if (g5 ==2){ edge23->show(); label23->show();}
            else if (g5 ==3){ edge24->show(); label24->show();}
                else if (g5 ==0){ edge12->show(); label12->show();}
                    else if (g5 ==4){ edge25->show(); label25->show();}
                        else if (g5 ==5){ edge26->show(); label26->show();}
                            else if (g5 ==6){ edge27->show(); label27->show();}
    }
    else if (g4 == 2){
        if (g5 ==3){ edge34->show(); label34->show();}
                else if (g5 ==0){ edge13->show(); label13->show();}
                    else if (g5 ==1){ edge23->show(); label23->show();}
                         else if (g5 ==4){ edge35->show(); label35->show();}
                            else if (g5 ==5){ edge36->show(); label36->show();}
                                else if (g5 ==6){ edge37->show(); label37->show();}

    }
    else if (g4 == 3){
            if (g5 ==2){ edge34->show(); label34->show();}
                else if (g5 ==1){ edge24->show(); label24->show();}
                    else if (g5 ==0){ edge14->show(); label14->show();}
                        else if (g5 ==4){ edge45->show(); label45->show();}
                            else if (g5 ==5){ edge46->show(); label46->show();}
                                else if (g5 ==6){ edge47->show(); label47->show();}
    }
    else if (g4 == 4){
            if (g5 ==2){ edge35->show(); label35->show();}
                else if (g5 ==1){ edge25->show(); label25->show();}
                    else if (g5 ==0){ edge15->show(); label15->show();}
                        else if (g5 ==3){ edge45->show(); label45->show();}
                            else if (g5 ==5){ edge56->show(); label56->show();}
                            else if (g5 ==6){ edge57->show(); label57->show();}
    }
    else if (g4 == 5){
            if (g5 ==2){ edge36->show(); label36->show();}
                else if (g5 ==1){ edge26->show(); label26->show();}
                    else if (g5 ==0){ edge16->show(); label16->show();}
                        else if (g5 ==3){ edge46->show(); label46->show();}
                            else if (g5 ==4){ edge56->show(); label56->show();}
             else if (g5 ==6){ edge67->show(); label67->show();}
    }
    else if (g4 == 6){
            if (g5 ==2){ edge37->show(); label37->show();}
                else if (g5 ==1){ edge27->show(); label27->show();}
                    else if (g5 ==0){ edge17->show(); label17->show();}
                        else if (g5 ==3){ edge47->show(); label47->show();}
                            else if (g5 ==4){ edge57->show(); label57->show();}
             else if (g5 ==5){ edge67->show(); label67->show();}
    }
    if (g5 == 0){
        if (g6 ==1){ edge12->show(); label12->show();}
            else if (g6 ==2){ edge13->show(); label13->show();}
               else if (g6 ==3){ edge14->show(); label14->show();}
                else if (g6 ==4){ edge15->show(); label15->show();}
                    else if (g6 ==5){ edge16->show(); label16->show();}
                     else if (g6 ==6){ edge17->show(); label17->show();}
    }
    else if (g5 == 1){
        if (g6 ==2){ edge23->show(); label23->show();}
            else if (g6 ==3){ edge24->show(); label24->show();}
                else if (g6 ==0){ edge12->show(); label12->show();}
                    else if (g6 ==4){ edge25->show(); label25->show();}
                        else if (g6 ==5){ edge26->show(); label26->show();}
                            else if (g6 ==6){ edge27->show(); label27->show();}
    }
    else if (g5 == 2){
        if (g6 ==3){ edge34->show(); label34->show();}
                else if (g6 ==0){ edge13->show(); label13->show();}
                    else if (g6 ==1){ edge23->show(); label23->show();}
                         else if (g6 ==4){ edge35->show(); label35->show();}
                            else if (g6 ==5){ edge36->show(); label36->show();}
                                else if (g6 ==6){ edge37->show(); label37->show();}

    }
    else if (g5 == 3){
            if (g6 ==2){ edge34->show(); label34->show();}
                else if (g6 ==1){ edge24->show(); label24->show();}
                    else if (g6 ==0){ edge14->show(); label14->show();}
                        else if (g6 ==4){ edge45->show(); label45->show();}
            else if (g6 ==5){ edge46->show(); label46->show();}
                else if (g6 ==6){ edge47->show(); label47->show();}
    }
    else if (g5 == 4){
            if (g6 ==2){ edge35->show(); label35->show();}
                else if (g6 ==1){ edge25->show(); label25->show();}
                    else if (g6 ==0){ edge15->show(); label15->show();}
                        else if (g6 ==3){ edge45->show(); label45->show();}
                            else if (g6 ==5){ edge56->show(); label56->show();}
                                else if (g6 ==6){ edge57->show(); label57->show();}
    }
    else if (g5 == 5){
            if (g6 ==2){ edge36->show(); label36->show();}
                else if (g6 ==1){ edge26->show(); label26->show();}
                    else if (g6 ==0){ edge16->show(); label16->show();}
                        else if (g6 ==3){ edge46->show(); label46->show();}
                            else if (g6 ==4){ edge56->show(); label56->show();}
            else if (g6 ==6){ edge67->show(); label67->show();}
    }
    else if (g5 == 6){
            if (g6 ==2){ edge37->show(); label37->show();}
                else if (g6 ==1){ edge27->show(); label27->show();}
                    else if (g6 ==0){ edge17->show(); label17->show();}
                        else if (g6 ==3){ edge47->show(); label47->show();}
                            else if (g6 ==4){ edge57->show(); label57->show();}
            else if (g6 ==5){ edge67->show(); label67->show();}
    }
    if (g6 == 0){
        if (g7 ==1){ edge12->show(); label12->show();}
            else if (g7 ==2){ edge13->show(); label13->show();}
               else if (g7 ==3){ edge14->show(); label14->show();}
                else if (g7 ==4){ edge15->show(); label15->show();}
                    else if (g7 ==5){ edge16->show(); label16->show();}
        else if (g7 ==6){ edge17->show(); label17->show();}
    }
    else if (g6 == 1){
        if (g7 ==2){ edge23->show(); label23->show();}
            else if (g7 ==3){ edge24->show(); label24->show();}
                else if (g7 ==0){ edge12->show(); label12->show();}
                    else if (g7 ==4){ edge25->show(); label25->show();}
                        else if (g7 ==5){ edge26->show(); label26->show();}
        else if (g7 ==6){ edge27->show(); label27->show();}
    }
    else if (g6 == 2){
        if (g7 ==3){ edge34->show(); label34->show();}
                else if (g7 ==0){ edge13->show(); label13->show();}
                    else if (g7 ==1){ edge23->show(); label23->show();}
                         else if (g7 ==4){ edge35->show(); label35->show();}
                            else if (g7 ==5){ edge36->show(); label36->show();}
                        else if (g7 ==6){ edge37->show(); label37->show();}

    }
    else if (g6 == 3){
            if (g7 ==2){ edge34->show(); label34->show();}
                else if (g7 ==1){ edge24->show(); label24->show();}
                    else if (g7 ==0){ edge14->show(); label14->show();}
                        else if (g7 ==4){ edge45->show(); label45->show();}
            else if (g7 ==5){ edge46->show(); label46->show();}
            else if (g7 ==6){ edge47->show(); label47->show();}
    }
    else if (g6 == 4){
            if (g7 ==2){ edge35->show(); label35->show();}
                else if (g7 ==1){ edge25->show(); label25->show();}
                    else if (g7 ==0){ edge15->show(); label15->show();}
                        else if (g7 ==3){ edge45->show(); label45->show();}
                            else if (g7 ==5){ edge56->show(); label56->show();}
            else if (g7 ==6){ edge57->show(); label57->show();}
    }
    else if (g6 == 5){
            if (g7 ==2){ edge36->show(); label36->show();}
                else if (g7 ==1){ edge26->show(); label26->show();}
                    else if (g7 ==0){ edge16->show(); label16->show();}
                        else if (g7 ==3){ edge46->show(); label46->show();}
                            else if (g7 ==4){ edge56->show(); label56->show();}
            else if (g7 ==6){ edge67->show(); label67->show();}
    }
    else if (g6 == 6){
            if (g7 ==2){ edge37->show(); label37->show();}
                else if (g7 ==1){ edge27->show(); label27->show();}
                    else if (g7 ==0){ edge17->show(); label17->show();}
                        else if (g7 ==3){ edge47->show(); label47->show();}
                            else if (g7 ==4){ edge57->show(); label57->show();}
            else if (g7 ==5){ edge67->show(); label67->show();}
    }
    if (g7 == 0){
        if (g1 ==1){ edge12->show(); label12->show();}
            else if (g1 ==2){ edge13->show(); label13->show();}
               else if (g1 ==3){ edge14->show(); label14->show();}
                else if (g1 ==4){ edge15->show(); label15->show();}
                    else if (g1 ==5){ edge16->show(); label16->show();}
        else if (g1 ==6){ edge17->show(); label17->show();}
    }
    else if (g7 == 1){
        if (g1 ==2){ edge23->show(); label23->show();}
            else if (g1 ==3){ edge24->show(); label24->show();}
                else if (g1 ==0){ edge12->show(); label12->show();}
                    else if (g1 ==4){ edge25->show(); label25->show();}
                        else if (g1 ==5){ edge26->show(); label26->show();}
        else if (g1 ==6){ edge27->show(); label27->show();}
    }
    else if (g7 == 2){
        if (g1 ==3){ edge34->show(); label34->show();}
                else if (g1 ==0){ edge13->show(); label13->show();}
                    else if (g1 ==1){ edge23->show(); label23->show();}
                         else if (g1 ==4){ edge35->show(); label35->show();}
                            else if (g1 ==5){ edge36->show(); label36->show();}
                        else if (g1 ==6){ edge37->show(); label37->show();}

    }
    else if (g7 == 3){
            if (g1 ==2){ edge34->show(); label34->show();}
                else if (g1 ==1){ edge24->show(); label24->show();}
                    else if (g1 ==0){ edge14->show(); label14->show();}
                        else if (g1 ==4){ edge45->show(); label45->show();}
            else if (g1 ==5){ edge46->show(); label46->show();}
            else if (g1 ==6){ edge47->show(); label47->show();}
    }
    else if (g7 == 4){
            if (g1 ==2){ edge35->show(); label35->show();}
                else if (g1 ==1){ edge25->show(); label25->show();}
                    else if (g1 ==0){ edge15->show(); label15->show();}
                        else if (g1 ==3){ edge45->show(); label45->show();}
                            else if (g1 ==5){ edge56->show(); label56->show();}
            else if (g1 ==6){ edge57->show(); label57->show();}
    }
    else if (g7 == 5){
            if (g1 ==2){ edge36->show(); label36->show();}
                else if (g1 ==1){ edge26->show(); label26->show();}
                    else if (g1 ==0){ edge16->show(); label16->show();}
                        else if (g1 ==3){ edge46->show(); label46->show();}
                            else if (g1 ==4){ edge56->show(); label56->show();}
            else if (g1 ==6){ edge67->show(); label67->show();}
    }
    else if (g7 == 6){
            if (g1 ==2){ edge37->show(); label37->show();}
                else if (g1 ==1){ edge27->show(); label27->show();}
                    else if (g1 ==0){ edge17->show(); label17->show();}
                        else if (g1 ==3){ edge47->show(); label47->show();}
                            else if (g1 ==4){ edge57->show(); label57->show();}
            else if (g1 ==5){ edge67->show(); label67->show();}
    }
}
