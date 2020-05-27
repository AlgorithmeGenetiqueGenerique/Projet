#include "interfaceVoyageur.h"

voyageurDeCommerceInterface::voyageurDeCommerceInterface(QWidget *parent){
    
    //Boutons
    demarrer = new QPushButton("&Demarrer la simulation");
    quitter = new QPushButton("Quitter");
    plusCourtChemin = new QPushButton("Afficher le plus &court chemin");
    valeurChoisies = new QPushButton("Utiliser ces valeurs");

    //Creation de la zone centrale et du dock
    QWidget* centre = new QWidget;
    QWidget* dock = new QWidget;

    //Actions
    accueil = new QAction(tr("&Accueil"),this);
    sauvegarder = new QAction(tr("&Sauvegarder"),this);
    charger = new QAction(tr("&Charger"),this);
    aide = new QAction(tr("&Aide"),this);
    

    //Layouts
    dockLayout = new QVBoxLayout();
    central = new QVBoxLayout();
    boutons = new QHBoxLayout();
    dockConfiguration = new QDockWidget(tr("Configuration du graphe"), this);
    dockConfiguration->setAllowedAreas(Qt::LeftDockWidgetArea);
    configurationLayout = new QFormLayout();
    nombre_sommets = new QSpinBox();
    nombre_sommets->setMinimum(4);
    nombre_sommets->setMaximum(7);
    poids_arrete1 = new QSpinBox();
    poids_arrete2 = new QSpinBox();
    poids_arrete3 = new QSpinBox();
    poids_arrete4 = new QSpinBox();
    poids_arrete5 = new QSpinBox();
    poids_arrete6 = new QSpinBox();
    configurationLayout->addRow("Nombre de sommets", nombre_sommets);
    configurationLayout->addRow("Poids arrête 1 <-> 2 : ", poids_arrete1);
    configurationLayout->addRow("Poids arrête 1 <-> 3 : ", poids_arrete2);
    configurationLayout->addRow("Poids arrête 1 <-> 4 : ", poids_arrete3);
    configurationLayout->addRow("Poids arrête 2 <-> 3 : ", poids_arrete4);
    configurationLayout->addRow("Poids arrête 2 <-> 4 : ", poids_arrete5);
    configurationLayout->addRow("Poids arrête 3 <-> 4 : ", poids_arrete6);
    configurationLayout->addWidget(valeurChoisies);
    configurationLayout->setFieldGrowthPolicy(QFormLayout::FieldsStayAtSizeHint);
    
    //Creation du graphe
    graphe = new GraphWidget(nombre_sommets->value(),this);

    //Ajoute le widget au dock
    dockConfiguration->setWidget(dock);
    addDockWidget(Qt::LeftDockWidgetArea, dockConfiguration);

    //Ajoute le layout au widget
    centre->setLayout(central);
    dock->setLayout(dockLayout);

    //Ajoute les layouts aux layouts
    central->addWidget(graphe);
    central->addLayout(boutons);
    dockLayout->addLayout(configurationLayout);

    //Ajoute les widgets aux layouts

    dockLayout->addWidget(valeurChoisies);
    dockLayout->addWidget(demarrer);
    dockLayout->addWidget(plusCourtChemin);
    dockLayout->addWidget(quitter);
    setCentralWidget(centre);

    //Configuration graphique
    dock->setSizePolicy(QSizePolicy::Policy::Preferred,QSizePolicy::Policy::Maximum);
    
    //Signaux
    connect(quitter, SIGNAL(clicked()), qApp, SLOT(quit()));
    connect(demarrer,SIGNAL(clicked()), this, SLOT(creerGraphe()));
    connect(nombre_sommets, SIGNAL(valueChanged(int)), this, SLOT(gestionConfiguration(int)));
    connect(valeurChoisies, SIGNAL(clicked()),this, SLOT(quatreSommets()));
    connect(accueil, SIGNAL(triggered()), this, SLOT(retourAccueil()));
    connect(aide,SIGNAL(triggered()),SLOT(afficherAide()));
    connect(plusCourtChemin,SIGNAL(clicked()),this,SLOT(lancer()));
    //Creation du menu
    creerMenu();
}

void voyageurDeCommerceInterface::creerGraphe(){
    
    delete graphe;
    graphe = new GraphWidget(nombre_sommets->value(),this);
    central->insertWidget(0,graphe);
    
}

void voyageurDeCommerceInterface::gestionConfiguration(int valeur){
    
    if(valeur != 4){
        poids_arrete1->hide();
        (configurationLayout->labelForField(poids_arrete1))->hide(); 
        poids_arrete2->hide();
        (configurationLayout->labelForField(poids_arrete2))->hide();
        poids_arrete3->hide();
        (configurationLayout->labelForField(poids_arrete3))->hide();
        poids_arrete4->hide();
        (configurationLayout->labelForField(poids_arrete4))->hide();
        poids_arrete5->hide();
        (configurationLayout->labelForField(poids_arrete5))->hide();
        poids_arrete6->hide();
        (configurationLayout->labelForField(poids_arrete6))->hide();
        valeurChoisies->hide();
    }
    else
    {
        poids_arrete1->show();
        (configurationLayout->labelForField(poids_arrete1))->show(); 
        poids_arrete2->show(); 
        (configurationLayout->labelForField(poids_arrete2))->show();
        poids_arrete3->show();
        (configurationLayout->labelForField(poids_arrete3))->show();
        poids_arrete4->show();
        (configurationLayout->labelForField(poids_arrete4))->show();
        poids_arrete5->show();
        (configurationLayout->labelForField(poids_arrete5))->show();
        poids_arrete6->show();
        (configurationLayout->labelForField(poids_arrete6))->show();
        valeurChoisies->show();
    }
}

void voyageurDeCommerceInterface::quatreSommets(){

    graphe->initialisation4sommets(poids_arrete1->value(),poids_arrete2->value(),poids_arrete3->value(),poids_arrete4->value(),poids_arrete5->value(),poids_arrete6->value());
}

void voyageurDeCommerceInterface::retourAccueil(){
    
    MainWindow1 *mainWindow = new MainWindow1();
    mainWindow->show();
    this->close();
}
void voyageurDeCommerceInterface::lancer(){
    graphe->afficherSolution();
}
void voyageurDeCommerceInterface::afficherAide(){
    
    QFile HelpFile("qrc:/Manuel.pdf");;
    HelpFile.copy(qApp->applicationDirPath().append("/Manuel.pdf"));
    QDesktopServices::openUrl(QUrl::fromLocalFile(qApp->applicationDirPath().append("/Manuel.pdf")));
}

void voyageurDeCommerceInterface::creerMenu(){

    menu = menuBar()->addMenu(tr("&Accueil"));
    menu->addAction(accueil);

    menu = menuBar()->addMenu(tr("&Sauvegarde"));
    menu->addAction(sauvegarder);
    menu->addAction(charger);

    menu = menuBar()->addMenu(tr("&Aide"));
    menu->addAction(aide);
}
