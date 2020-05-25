#ifndef H_INTERFACE
#define H_INTERFACE

#include "graphwidget.h"
#include "../mainwindow1.h"
#include <QApplication>
#include <QtWidgets>


class voyageurDeCommerceInterface: public QMainWindow {
    Q_OBJECT
    private:
        QMenu *menu;
        QPushButton *demarrer;
        QPushButton *quitter;
        QPushButton *valeurChoisies;
        QPushButton *plusCourtChemin;
        QDockWidget *dockConfiguration;
        QWidget centre;
        QWidget *dock;
        QVBoxLayout *dockLayout;
        QFormLayout *configurationLayout;
        QVBoxLayout *central;
        QHBoxLayout *boutons;
        QAction *accueil;
        QAction *sauvegarder;
        QAction *charger;
        QAction *configurer;
        QAction *aide;
        QSpinBox *nombre_sommets;
        QSpinBox *poids_arrete1;
        QSpinBox *poids_arrete2;
        QSpinBox *poids_arrete3;
        QSpinBox *poids_arrete4;
        QSpinBox *poids_arrete5;
        QSpinBox *poids_arrete6;
        QSpinBox *taille_graphe;
        GraphWidget *graphe;
        //QHBoxLayout *accueilLayout;
    public:
        voyageurDeCommerceInterface(QWidget *parent);
        void creerMenu();

    public slots:
        void creerGraphe();
        void gestionConfiguration(int valeur);
        void quatreSommets();
        void retourAccueil();
        void afficherAide();
        void lancer();

};

#endif