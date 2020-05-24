#ifndef GRAPHWIDGET_H
#define GRAPHWIDGET_H
#include<QLabel>
#include <QGraphicsView>
#include <string>
#include <QVariant>
#include <QDesktopWidget>
#include <iostream>
#include "edge.h"
#include <time.h>
#include "./../OP/operationsgenetiques.h"
#include "./../OP/entreessorties.h"

using namespace std;
class Node;

class GraphWidget : public QGraphicsView
{
    Q_OBJECT

public:
    GraphWidget(int nbSommets,QWidget *parent = 0);
    void initialisationGraph();
    void dessinGraphe4Sommets();
    void dessinGraphe5Sommets();
    void dessinGraphe6Sommets();
    void dessinGraphe7Sommets();
    void afficherSolution4Sommets(int g1, int g2, int g3, int g4);
    void afficherSolution5Sommets(int g1, int g2, int g3, int g4, int g5);
    void afficherSolution6Sommets(int g1, int g2, int g3, int g4, int g5, int g6);
    void afficherSolution7Sommets(int g1, int g2, int g3, int g4, int g5, int g6, int g7);
    int** graph;
    void setSommets(int sommets);
    void afficherSolution();

public slots:
    void initialisation4sommets(int edge12_, int edge13_, int edge14_, int edge23_, int edge24_, int edge34_);

protected:

    void scaleView(qreal scaleFactor);

private:
    int timerId;
    Node* node1;
     Node* node2;
      Node* node3;
       Node* node4;
        Node* node5;
         Node* node6;
          Node* node7;
           Node* node8;
           int nombre_sommets;
           Edge* edge12;
           Edge* edge13;
            Edge* edge14;
            Edge* edge15;
            Edge* edge16;
            Edge* edge17;
            Edge* edge18;
             Edge* edge23;
              Edge* edge24;
               Edge* edge25;
                Edge* edge26;
                Edge* edge27;
                 Edge* edge28;
              Edge* edge34;
               Edge* edge35;
                Edge* edge36;
                    Edge* edge37;
                    Edge* edge38;
               Edge* edge45;
               Edge* edge46;
                  Edge* edge47;
                  Edge* edge48;
               Edge* edge56;
                Edge* edge57;
                 Edge* edge58;
                 Edge* edge67;
                  Edge* edge68;
                   Edge* edge78;
                   QLabel *label12;
                   QLabel *label23;
                   QLabel *label13;
                   QLabel *label14;
                   QLabel *label24;
                   QLabel *label34;
                    QLabel *label15;
                    QLabel *label25;
                    QLabel *label35;
                    QLabel *label45;
                    QLabel *label16;
                    QLabel *label26;
                    QLabel *label36;
                     QLabel *label46;
                     QLabel *label56;
                     QLabel *label17;
                     QLabel *label27;
                     QLabel *label37;
                     QLabel *label47;
                     QLabel *label57;
                     QLabel *label67;
};

#endif // GRAPHWIDGET_H
