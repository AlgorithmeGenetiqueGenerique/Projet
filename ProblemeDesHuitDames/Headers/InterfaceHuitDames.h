#include <QGraphicsView>
#include <QGraphicsScene>
#include <echiquier.h>
#include<QPushButton>
#include <QSpinBox>
#include <QVBoxLayout>
#include <QGroupBox>
#include <QRadioButton>
#include <QLabel>
#include "ProblemeDesHuitDames"
#include "EntreesSorties.h"
#include "OperationsGenetiques.h"
#include "Piece.h"
class InterfaceHuitDames:public QGraphicsView
{
    Q_OBJECT
public:

    InterfaceHuitDames(QWidget *parent = 0);
    ~InterfaceHuitDame()

    void DessinerEchiquier();

    void AjouterSurScene(QGraphicsItem *item);
    void AffichageEchiquier();
    void RetirerPiece();
    BoxEchiquier *matrice[8][8];
    QGraphicsTextItem *verifier;
    QList <Piece *> pieceActuelle;

public slots:

    void connectLancement();
    void connectAcceuil();
    void connectReConfiguration();
    void connectAide();
    void connectQuitter();

private:
    QGraphicsScene *Scene_du_jeu;
    Echiquier *Echiquier;
    QList <QGraphicsItem *> listG;
    QSpinBox taille_population;
    QVBoxLayout *layout_taille_population;
    QLabel *label_taille_population;
    QVBoxLayout *layout_nombre_genes;
    QSpinBox *nombre_iterations;
    QVBoxLayout *layout_nombre_iterations;
    QLabel *label_nombre_iterations;
    QVBoxLayout *layout_maximisation_minimisation;
    QVBoxLayout *layout_maximisation_minimisation_principale;
    QGroupBox* maximisation_minimisation;
    QRadioButton* minimisation;
    vector<individu> individus;
    QPushButton *reconfigurer;
    QPushButton *lancement;
    QHBoxLayout *layout_reconfigurer;
    QHBoxLayout *layout_lancement;
    QPushButton *acceuil;
    QHBoxLayout *layout_acceuil;
    QLabel *label_acceuil;
    QPushButton *aide;
    QHBoxLayout *layout_aide;
    QLabel *label_aide;
    QLabel *label_reconfigurer;
    QLabel *label_lancement;
    QPushButton *quitter;
    QHBoxLayout *layout_quitter;
    QLabel *label_quitter;
};
