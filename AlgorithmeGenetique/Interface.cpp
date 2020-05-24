
#include <QtWidgets>

#include "Interface.h"

Interface::Interface(QWidget *parent)
    : QWidget(parent)
{
    // création des boutons

    voyageur = new QPushButton(tr("Voyageur de Commerce"));
    modelisation = new QPushButton(("Modelisation du problème"));

    huits_dame = new QPushButton(tr("Problème des Huit Dames"));

    quitter = new QPushButton(tr("Quitter"));


    // positionné les bouton
    QGridLayout *mainLayout = new QGridLayout;
    mainLayout->addWidget(voyageur, 1, 0);
    mainLayout->addWidget(modelisation, 0, 1);
    mainLayout->addWidget(huits_dame, 1, 2);
    mainLayout->addWidget(quitter, 2, 1);
    setLayout(mainLayout);


}


