#include "OP/modelisationprblm.h"
#include "ui_modelisationprblm.h"
#include <QDebug>
#include <QAbstractButton>
#include <QGraphicsProxyWidget>
#include <QPushButton>
#include <QtCore>
#include "../mainwindow1.h"
#include <QMessageBox>
#include <QDesktopServices>

ModelisationPrblm::ModelisationPrblm(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::ModelisationPrblm)
{
    srand(unsigned(time(NULL)));
    ui->setupUi(this);
    ui->doubleSpinBox_3->setEnabled(false);
    ui->doubleSpinBox_4->setEnabled(false);
    timer=new QTimer();
    nombre_genes = ui->spinBox;
    taille_population=ui->spinBox_2;
    nombre_iterations=ui->spinBox_3;
    nombre_individu_selectionnes=ui->spinBox_4;
    entier=ui->radioButton;
    entier->setText("entier");
    flottant=ui->radioButton_2;
    flottant->setText("flottant");
    binaire=ui->radioButton_3;
    binaire->setText("binaire");
    maximisation=ui->radioButton_4;
    maximisation->setText("maximisation");
    minimisation=ui->radioButton_5;
    minimisation->setText("minimisation");
    taux_croisement=ui->doubleSpinBox;
    taux_mutation=ui->doubleSpinBox_2;
    choix_selection=ui->comboBox;
    chaine_evaluation=ui->lineEdit;
    min_intervalle=nullptr;
    max_intervalle=nullptr;
    generation_satisfaisante=ui->lineEdit_4;
    sauvegarder=ui->pushButton_2;
    charger=ui->pushButton;
    demarrer_simulation=ui->pushButton_3;
    acceuil=ui->pushButton_6;
    aide=ui->pushButton_5;
    quitter=ui->pushButton_4;
    pause=ui->pushButton_9;
    reprendre=ui->pushButton_8;
    reconfigurer=ui->pushButton_7;
    nom_fichier_sauvegarde=ui->lineEdit_5;
    nom_fichier_latex=ui->lineEdit_6;
    nom_fichier_chargement=ui->lineEdit_5;
    configurer=ui->pushButton_7;

    //---------------------------------------------------------
    label_nombre_genes=ui->label_nombreG;
    label_nombre_genes->setText("nombre_genes");
    label_taille_population=ui->label_tailleP;
    label_taille_population->setText("taille_population");
    label_nombre_iterations=ui->label_nombreI;
    label_nombre_iterations->setText("nombre_iterations");
    label_nombre_individu_selectionnes=ui->label_nombreIS;
    label_nombre_individu_selectionnes->setText("nombre_individu_selectionnes");
    label_type_genes=ui->label_typeG;
    label_type_genes->setText("nombre_genes");

    label_choix_selection=ui->label_typeS ;
    label_taux_croisement=ui->label_tauxC;
    label_taux_mutation=ui->label_tauxM ;
    label_chaine_evaluation=ui->label_chaineE;
    label_generation_satisfaisante=ui->label_generationS;
    ntb=new notepad(this);
    thrd=new myThread(this);
    calculat=new Calculator(nullptr);
    calculat->close();
    QObject::connect(thrd,SIGNAL(txtEdt(int)),this,SLOT(onTxtEdt(int)));

}

ModelisationPrblm::~ModelisationPrblm()
{
    delete ui;
}

void ModelisationPrblm::on_pushButton_3_clicked()//Lancer la simulation
{
    nombre_individu_selectionnes->setStyleSheet("background-color: white;");
    chaine_evaluation->setStyleSheet("background-color: white;");
    taux_croisement->setStyleSheet("background-color: white;");
    ui->lineEdit_4->setStyleSheet("background-color: white;");
    ui->doubleSpinBox_3->setStyleSheet("background-color: white;");
    ui->doubleSpinBox_4->setStyleSheet("background-color: white;");
    ui->spinBox_5->setStyleSheet("background-color: white;");
    ui->spinBox_6->setStyleSheet("background-color: white;");
    ui->pushButton_4->setEnabled(false);
    thrd->Stop=false;
    thrd->count=0;
    ui->stackedWidget->setCurrentIndex(1);
    reprendre->setEnabled(false);
    reconfigurer->setEnabled(false);

    int type;
    int maxMin;
    if(ui->radioButton->isChecked())
    {
        type=1;
        thrd->test=2;
    }

    else if(ui->radioButton_2->isChecked())
    {
        type=2;
        thrd->test=0;
    }

    else
    {
        type=3;
        thrd->test=2;
    }

    if(ui->radioButton_4->isChecked())
        maxMin=1;
    else
        maxMin=2;

    thrd->iteration=nombre_iterations->value()-1;
    compteur_generation = 0;
    chaine_evaluation_ = chaine_evaluation->text().toUtf8().constData();
    generation_satisfaisante_ = generation_satisfaisante->text().toDouble();
    generation_satisfaisante_=generation_satisfaisante->text().toDouble();
    QString chaineEval="";
    if(ui->checkBox->isChecked())
        chaineEval=calculat->getEvaluation();
    else
        chaineEval=ui->lineEdit->text();
    if(type==2)
        ee = new EntreesSorties( chaineEval.toStdString(), taille_population->value(), nombre_iterations->value(), nombre_individu_selectionnes->value(), ui->comboBox->currentIndex()+1,nombre_genes->value(),taux_croisement->value(),taux_mutation->value(),ui->lineEdit_4->text().toDouble(), type, ui->doubleSpinBox_3->value(), ui->doubleSpinBox_4->value(),maxMin);
    else if (type == 1 || type ==3)
        ee = new EntreesSorties( chaineEval.toStdString(), taille_population->value(), nombre_iterations->value(), nombre_individu_selectionnes->value(), ui->comboBox->currentIndex()+1,nombre_genes->value(),taux_croisement->value(),taux_mutation->value(),ui->lineEdit_4->text().toInt(), type, ui->spinBox_5->value(),ui->spinBox_6->value(),maxMin);
    op = new operationsGenetiques(&individus,ee->getMaximisationMinimisation(), ee->getNmbr_indiv_a_selec());
    sb = ui->textBrowser->verticalScrollBar();
    score_totale=0;
    evaluation evaluation_test = evaluation(ee->getChaineEvaluation());
    if(type==1 || type==3){
        if ((ee->getMinIntervalle() == ee->getMaxIntervalle()) ) {
           ui->stackedWidget->setCurrentIndex(0);
               ui->spinBox_5->setStyleSheet("background-color: red;");
               ui->spinBox_6->setStyleSheet("background-color: red;");
           QMessageBox::warning(this, "Erreur", "min intervalle égale à max intervalle ");
        }
        else {
            int p_o = 0;
            int p_f = 0;
            bool incoherance = false;
            for (int i =0; i < ee->getChaineEvaluation().size(); i++){
                    if (ee->getChaineEvaluation().at(i)== '(' ) p_o++;
                    if (ee->getChaineEvaluation().at(i)== ')' ){
                        p_f++;
                    }
                    if (p_f > p_o) {
                        ui->stackedWidget->setCurrentIndex(0);
                        QMessageBox::warning(this, "Erreur", " de lancer la simulation:\nErreur dans Les parenthèses");
                        chaine_evaluation->setStyleSheet("background-color: red;");
                        incoherance = true;
                    }
            }

        if (incoherance == false){
        evaluation_test.evaluer(new individu(ee->getMinIntervalle(),ee->getMaxIntervalle(), ee->getNombreGenes(),ee->getTypeGenes()));
        if(ee->getTaillePopulation() < ee->getNmbr_indiv_a_selec())
    {
        nombre_individu_selectionnes->setValue((ee->getTaillePopulation()/2));
        nombre_individu_selectionnes->setStyleSheet("background-color: red;");
        ui->stackedWidget->setCurrentIndex(0);
        QMessageBox::warning(this, "Erreur", "Impossible de lancer la simulation:\nNombre individu"
                                              "a selectioner inf a la population");
    }
        else if (ee->getTauxCroisement()*ee->getNmbr_indiv_a_selec()<2) {
           ui->stackedWidget->setCurrentIndex(0);
           taux_croisement->setStyleSheet("background-color: red;");
           QMessageBox::warning(this, "Erreur", "Taux de croisement insuffisant");
        }
        else if ((ee->getMinIntervalle() > ee->getMaxIntervalle()) ) {
           ui->stackedWidget->setCurrentIndex(0);
               ui->spinBox_5->setStyleSheet("background-color: red;");
               ui->spinBox_6->setStyleSheet("background-color: red;");
           QMessageBox::warning(this, "Erreur", "min intervalle superieur à max intervalle ");
        }
        else if(evaluation_test.getErreur())
        {
            ui->stackedWidget->setCurrentIndex(0);
            if (evaluation_test.getErreur() == 1){
            QMessageBox::warning(this, "Erreur", "Impossible de lancer la simulation:\nSymbole indisponiblepour le nombre de genes choisi");
            chaine_evaluation->setStyleSheet("background-color: red;");
            }
            else if (evaluation_test.getErreur() == 2){
                QMessageBox::warning(this, "Erreur", "Impossible de lancer la simulation:\nPrenthèse fermante manquante");
             chaine_evaluation->setStyleSheet("background-color: red;");}
                else if (evaluation_test.getErreur() == 3){
                QMessageBox::warning(this, "Erreur", "Impossible de lancer la simulation:\nFonction non valable pour type binaire");
                chaine_evaluation->setStyleSheet("background-color: red;");}
            else if (evaluation_test.getErreur() == 4){
                QMessageBox::warning(this, "Erreur", "Impossible de lancer la simulation:\nFonction non valable pour type entier");
                chaine_evaluation->setStyleSheet("background-color: red;");}
            else if (evaluation_test.getErreur() == 5){
                QMessageBox::warning(this, "Erreur", "Impossible de lancer la simulation:\nFonction non valable pour type flottant");
                chaine_evaluation->setStyleSheet("background-color: red;");}
            else if (evaluation_test.getErreur() == 8){
                QMessageBox::warning(this, "Erreur", " de lancer la simulation:\nErreur dans l'équation saisie");
                chaine_evaluation->setStyleSheet("background-color: red;");
          }
        }
        else
            thrd->start();
        }
       }
    }else if (type==2){
        if ((ee->getMinIntervalleFlottant() == ee->getMaxIntervalleFlottant()) ) {
           ui->stackedWidget->setCurrentIndex(0);
               ui->doubleSpinBox_3->setStyleSheet("background-color: red;");
               ui->doubleSpinBox_4->setStyleSheet("background-color: red;");
           QMessageBox::warning(this, "Erreur", "min intervalle égale à max intervalle ");
        }
        else {
        evaluation_test.evaluer(new individu(ee->getMinIntervalleFlottant(),ee->getMaxIntervalleFlottant(), ee->getNombreGenes(),ee->getTypeGenes()));
        if(ee->getTaillePopulation() < ee->getNmbr_indiv_a_selec())
    {
        nombre_individu_selectionnes->setValue((ee->getTaillePopulation()/2));
        nombre_individu_selectionnes->setStyleSheet("background-color: red;");
        ui->stackedWidget->setCurrentIndex(0);
        QMessageBox::warning(this, "Erreur", "Impossible de lancer la simulation:\nNombre individu"
                                              "a selectioner inf a la population");
    }
        else if (ee->getTauxCroisement()*ee->getNmbr_indiv_a_selec()<2) {
           ui->stackedWidget->setCurrentIndex(0);
           taux_croisement->setStyleSheet("background-color: red;");
           QMessageBox::warning(this, "Erreur", "Taux de croisement insuffisant");
        }
        else if ((ee->getMinIntervalleFlottant() > ee->getMaxIntervalleFlottant()) ) {
           ui->stackedWidget->setCurrentIndex(0);
               ui->doubleSpinBox_3->setStyleSheet("background-color: red;");
               ui->doubleSpinBox_4->setStyleSheet("background-color: red;");
           QMessageBox::warning(this, "Erreur", "min intervalle superieur à max intervalle ");
        }
        else if(evaluation_test.getErreur())
        {
            ui->stackedWidget->setCurrentIndex(0);
            if (evaluation_test.getErreur() == 1){
            QMessageBox::warning(this, "Erreur", "Impossible de lancer la simulation:\nSymbole indisponiblepour le nombre de genes choisi");
            chaine_evaluation->setStyleSheet("background-color: red;");
            }
            else if (evaluation_test.getErreur() == 2){
                QMessageBox::warning(this, "Erreur", "Impossible de lancer la simulation:\nPrenthèse fermante manquante");
             chaine_evaluation->setStyleSheet("background-color: red;");}
                else if (evaluation_test.getErreur() == 3){
                QMessageBox::warning(this, "Erreur", "Impossible de lancer la simulation:\nFonction non valable pour type binaire");
                chaine_evaluation->setStyleSheet("background-color: red;");}
            else if (evaluation_test.getErreur() == 4){
                QMessageBox::warning(this, "Erreur", "Impossible de lancer la simulation:\nFonction non valable pour type entier");
                chaine_evaluation->setStyleSheet("background-color: red;");}
            else if (evaluation_test.getErreur() == 5){
                QMessageBox::warning(this, "Erreur", "Impossible de lancer la simulation:\nFonction non valable pour type flottant");
                chaine_evaluation->setStyleSheet("background-color: red;");}
            else if (evaluation_test.getErreur() == 8){
                QMessageBox::warning(this, "Erreur", " de lancer la simulation:\nErreur dans l'éuation saisie");
                chaine_evaluation->setStyleSheet("background-color: red;");
          }
          }
        else
            thrd->start();
    }
    }
}

void ModelisationPrblm::on_pushButton_2_clicked()//----
{
    ui->stackedWidget->setCurrentIndex(2);
}

void ModelisationPrblm::on_pushButton_6_clicked()//Acceuil
{   
    thrd->Stop = true;
    ui->stackedWidget->setCurrentIndex(0);
    MainWindow1 *mainWindow = new MainWindow1();
    mainWindow->show();
    this->close();
}

void ModelisationPrblm::onTxtEdt(int j)//Thread
{
    if (arret) thrd->Stop=true;
    if(arret)
        ui->pushButton_4->setEnabled(true);
        int erreur=0;
        if(!j){
            for (int i = 0; i< ee->getTaillePopulation(); i++){

                if ((ee->getTypeGenes() == 1) || (ee->getTypeGenes() == 3))
                individus.push_back(individu(ee->getMinIntervalle(),ee->getMaxIntervalle(), ee->getNombreGenes(),ee->getTypeGenes()));
                else if (ee->getTypeGenes() == 2)
                individus.push_back(individu(ee->getMinIntervalleFlottant(),ee->getMaxIntervalleFlottant(), ee->getNombreGenes(),ee->getTypeGenes()));
                evaluation e = evaluation (ee->getChaineEvaluation());
                e.evaluer(&individus[i]);
                if (ee->getTypeGenes() == 1)
                    score_totale += individus[i].getNoteEvaluation();
                else if (ee->getTypeGenes() == 2)
                    score_totale_d += individus[i].getNoteEvaluationFlottant();
                else if (ee->getTypeGenes() == 3)
                    score_totale += individus[0].convertionVersDecimale(individus[i].getNoteEvaluation());
                if(e.getErreur()>erreur)
                 erreur=e.getErreur();
            }
            evaluation e = evaluation (ee->getChaineEvaluation());
            if (ee->getTypeGenes() == 1){
                meilleur_premier = individus[0].getNoteEvaluation();
                score_totale = score_totale/individus.size();
                arret = e.testArret(score_totale,ee->getGenerationSatisfaisante(), ee->getMaximisationMinimisation());
                meillleur_individu.push_back(individus.at(0).getNoteEvaluation());
                score_total.push_back(score_totale);
                if(erreur==6)
                {
                    ui->textBrowser->insertPlainText("Une Division sur zero à u lieu");
                    ui->textBrowser->insertPlainText("\n");
                }
                else if(erreur==7)
                {
                    ui->textBrowser->insertPlainText("Modulo zero à u lieu");
                    ui->textBrowser->insertPlainText("\n");
                }

            }
            else if (ee->getTypeGenes() == 2){
                meilleur_premier_d = individus[0].getNoteEvaluationFlottant();
                score_totale_d = score_totale_d/individus.size();
                arret = e.testArret(score_totale_d,ee->getGenerationSatisfaisanteFlottant(), ee->getMaximisationMinimisation());
                meillleur_individu_d.push_back(individus.at(0).getNoteEvaluationFlottant());
                score_total_d.push_back(score_totale_d);
                if(erreur==6)
                {
                    ui->textBrowser->insertPlainText("Une division sur zero à u lieu");
                    ui->textBrowser->insertPlainText("\n");
                }
                else if(erreur==7)
                {
                    ui->textBrowser->insertPlainText("Modulo zero à u lieu");
                    ui->textBrowser->insertPlainText("\n");
                }

            }
            else if (ee->getTypeGenes() == 3){

                meilleur_premier = individus[0].getNoteEvaluation();
                score_totale = individus[0].conversionVersBinaire(score_totale/individus.size());
                arret = e.testArret(score_totale,ee->getGenerationSatisfaisante(), ee->getMaximisationMinimisation());
                meillleur_individu.push_back(individus.at(0).getNoteEvaluation());
                score_total.push_back(score_totale);
                if(erreur==6)
                {
                    ui->textBrowser->insertPlainText("Une division sur zéro à u lieu");
                    ui->textBrowser->insertPlainText("\n");
                }
                else if(erreur==7)
                {
                    ui->textBrowser->insertPlainText("Modulo zero à u lieu");
                    ui->textBrowser->insertPlainText("\n");
                }

            }
        }
        if (arret) thrd->Stop=true;
    //-------------------------Sélection---------------
    if (ee->getChoixSelection() == 1)
            op->selectionParRang();
    else if (ee->getChoixSelection() == 2)// modifier reel-------
            op->selectionParTournoi();
    else if (ee->getChoixSelection() == 3)//modifier reel--------
            op->selectionParRoulette();
    //-------------------------Croisement---------------

    if ((ee->getTypeGenes() == 1) || (ee->getTypeGenes() == 3))
        score_totale = 0;
    else if (ee->getTypeGenes() == 2)
        score_totale_d = 0;
        op->croisement(ee->getTauxCroisement(), ee->getTauxMutation(), ee->getTaillePopulation(), ee->getChaineEvaluation());
        for (int i = 0; i< individus.size(); i++)
        {
            evaluation e = evaluation (ee->getChaineEvaluation());
            e.evaluer(&individus[i]);
            if(e.getErreur()>erreur)
                erreur=e.getErreur();
            if (ee->getTypeGenes() == 1)
            {
              score_totale += individus[i].getNoteEvaluation();
            }
            else if (ee->getTypeGenes() == 2)
            {
                score_totale_d += individus[i].getNoteEvaluationFlottant();
            }
            else if (ee->getTypeGenes() == 3)
                score_totale += individus[0].convertionVersDecimale(individus[i].getNoteEvaluation());
        }
        evaluation e2 = evaluation (ee->getChaineEvaluation());
        if (ee->getTypeGenes() == 1)
        {
            arret = e2.testArret(score_totale/individus.size(),ee->getGenerationSatisfaisante(), ee->getMaximisationMinimisation());
            score_total.push_back(score_totale/individus.size());
            meillleur_individu.push_back(individus.at(0).getNoteEvaluation());
            ui->textBrowser->insertPlainText("generation : "+QString::number(compteur_generation)+" Score :"+QString::number(score_total[compteur_generation]));
            ui->textBrowser->insertPlainText("\n");
            if(erreur==6)
            {
                ui->textBrowser->insertPlainText("Une division sur zéro à u lieu");
                ui->textBrowser->insertPlainText("\n");
            }
            else if(erreur==7)
            {
                ui->textBrowser->insertPlainText("Modulo zéro à u lieu");
                ui->textBrowser->insertPlainText("\n");
            }

        }
        else if (ee->getTypeGenes() == 2)
        {
            arret = e2.testArret(score_totale_d/individus.size(),ee->getGenerationSatisfaisanteFlottant(), ee->getMaximisationMinimisation());
            score_total_d.push_back(score_totale_d/individus.size());
            meillleur_individu_d.push_back(individus.at(0).getNoteEvaluationFlottant());
            ui->textBrowser->insertPlainText("generation : "+QString::number(compteur_generation)+" Score :"+QString::number(score_total_d[compteur_generation]));
            ui->textBrowser->insertPlainText("\n");
            if(erreur==6)
            {
                ui->textBrowser->insertPlainText("Une division sur zéro à u lieu");
                ui->textBrowser->insertPlainText("\n");
            }
            else if(erreur==7)
            {
                ui->textBrowser->insertPlainText("Modulo zéro à u lieu");
                ui->textBrowser->insertPlainText("\n");
            }
        }
        else if (ee->getTypeGenes() == 3)
        {
            arret = e2.testArret(individus[0].conversionVersBinaire(score_totale/individus.size()),ee->getGenerationSatisfaisante(), ee->getMaximisationMinimisation());
            score_total.push_back(individus[0].conversionVersBinaire(score_totale/individus.size()));
            meillleur_individu.push_back(individus.at(0).getNoteEvaluation());
            ui->textBrowser->insertPlainText("generation : "+QString::number(compteur_generation)+" Score :"+QString::number(score_total[compteur_generation]));
            ui->textBrowser->insertPlainText("\n");
            if(erreur==6)
            {
                ui->textBrowser->insertPlainText("Une division sur zéro à u lieu");
                ui->textBrowser->insertPlainText("\n");
            }
            else if(erreur==7)
            {
                ui->textBrowser->insertPlainText("Modulo zéro à u lieu");
                ui->textBrowser->insertPlainText("\n");
            }
        }
            compteur_generation++;

    sb->setValue(sb->maximum());
    thrd->count=j;
    if (arret) thrd->Stop=true;
    if(thrd->count<=ee->getNombreiterations() && arret)
    {
        ui->textBrowser->insertPlainText("generation : "+QString::number(compteur_generation)+" Score :"+QString::number(score_total[compteur_generation]));
        ui->textBrowser->insertPlainText("\n");
    }
}

void ModelisationPrblm::on_pushButton_9_clicked()//pause
{
    thrd->Stop=true;
    reprendre->setEnabled(true);
    reconfigurer->setEnabled(true);
    ui->pushButton_4->setEnabled(true);
}

void ModelisationPrblm::on_pushButton_8_clicked()//reprondre
{
    thrd->Stop=false;
    thrd->start();
    reprendre->setEnabled(false);
    reconfigurer->setEnabled(false);
    ui->pushButton_4->setEnabled(false);
}

void ModelisationPrblm::on_pushButton_7_clicked()//reconfigutrer
{
    ui->stackedWidget->setCurrentIndex(0);
    individus.clear();
    score_total.clear();
    score_totale = 0;
    score_total_d.clear();
    score_totale_d = 0;
    meillleur_individu_d.clear();
    meillleur_individu.clear();
    arret = false;
}


//♣♣♣

void ModelisationPrblm::on_checkBox_stateChanged(int arg1)
{
    if(ui->checkBox->isChecked())
        ui->lineEdit->setEnabled(false);

    else
        ui->lineEdit->setEnabled(true);



}

void ModelisationPrblm::on_pushButton_10_clicked()//Clavier
{
    int type;
    int maxMin;
    if(ui->radioButton->isChecked())
        type=1;
    else if(ui->radioButton_2->isChecked())
        type=2;
    else
        type=3;
    if(ui->radioButton_4->isChecked())
        maxMin=1;
    else
        maxMin=2;
    thrd->iteration=nombre_iterations->value();
    compteur_generation = 0;
    chaine_evaluation_ = chaine_evaluation->text().toUtf8().constData();
    generation_satisfaisante_ = generation_satisfaisante->text().toDouble();
    generation_satisfaisante_=generation_satisfaisante->text().toDouble();
    QString chaineEval="";
    if(ui->checkBox->isChecked())
        chaineEval=calculat->getEvaluation();
    else
        chaineEval=ui->lineEdit->text();
    if(type==2)
        ee = new EntreesSorties( chaineEval.toStdString(), taille_population->value(), nombre_iterations->value(), nombre_individu_selectionnes->value(), 1+ui->comboBox->currentIndex(),nombre_genes->value(),taux_croisement->value(),taux_mutation->value(),ui->lineEdit_4->text().toDouble(), type, ui->doubleSpinBox_3->value(), ui->doubleSpinBox_4->value(),maxMin);
    else if (type == 1 || type ==3)
        ee = new EntreesSorties( chaineEval.toStdString(), taille_population->value(), nombre_iterations->value(), nombre_individu_selectionnes->value(), 1+ui->comboBox->currentIndex(),nombre_genes->value(),taux_croisement->value(),taux_mutation->value(),ui->lineEdit_4->text().toInt(), type, ui->spinBox_5->value(),ui->spinBox_6->value(),maxMin);
    ee->sauvegarde(ui->lineEdit_5->text().toStdString());
    ui->stackedWidget->setCurrentIndex(0);
}


void ModelisationPrblm::on_pushButton_clicked()
{
    ui->stackedWidget->setCurrentIndex(3);
}

void ModelisationPrblm::on_pushButton_11_clicked()//sauvgarde
{
    qDebug()<<ui->lineEdit_7->text();
    ee=new EntreesSorties(ui->lineEdit_7->text().toStdString());
    //--------------------------------------------------------
    ui->spinBox->setValue(ee->getNombreGenes());
    ui->spinBox_2->setValue(ee->getTaillePopulation());
    ui->spinBox_3->setValue(ee->getNombreiterations());
    ui->spinBox_4->setValue(ee->getNmbr_indiv_a_selec());
    ui->doubleSpinBox_2->setValue(ee->getTauxCroisement());
    ui->doubleSpinBox_2->setValue(ee->getTauxMutation());
    ui->comboBox->setCurrentIndex(ee->getChoixSelection()-1);
    if(ee->getTypeGenes()==1)
        ui->radioButton->setChecked(true);
    else if(ee->getTypeGenes()==2)
        ui->radioButton_2->setChecked(true);
    else
        ui->radioButton_3->setChecked(true);

    if(ee->getMaximisationMinimisation()==1)
        ui->radioButton_4->setChecked(true);
    else
        ui->radioButton_5->setChecked(true);
    ui->lineEdit->setText(QString::fromStdString(ee->getChaineEvaluation()));
    ui->stackedWidget->setCurrentIndex(0);
}
void ModelisationPrblm::on_pushButton_12_clicked()
{

    if ((ee->getTypeGenes() == 1) || (ee->getTypeGenes() == 3)){
            ee->setNoteMoyenne(score_total);
            ee->setMeilleurIndividu(meillleur_individu);
            ee->genererLatex(&individus, ui->lineEdit_6->text().toStdString());
        }
        else if (ee->getTypeGenes() == 2){
            ee->setNoteMoyenneFlottant(score_total_d);
            ee->setMeilleurIndividuFlottant(meillleur_individu_d);
            ee->genererLatex(&individus, ui->lineEdit_6->text().toStdString());
        }
    ui->lineEdit_6->setText("");
}

void ModelisationPrblm::on_pushButton_13_clicked()
{
    ntb->show();

}

void ModelisationPrblm::on_pushButton_4_clicked()
{
    this->close();
}

void ModelisationPrblm::on_pushButton_14_clicked()
{

   calculat->show();
   ui->checkBox->setChecked(true);
}

void ModelisationPrblm::on_pushButton_5_clicked()
{
    QFile HelpFile("qrc:../Manuel.pdf");;
    HelpFile.copy(qApp->applicationDirPath().append("../Manuel.pdf"));
    QDesktopServices::openUrl(QUrl::fromLocalFile(qApp->applicationDirPath().append("../Manuel.pdf")));
}

void ModelisationPrblm::on_radioButton_clicked()//entier
{
    ui->doubleSpinBox_3->setEnabled(false);
    ui->doubleSpinBox_4->setEnabled(false);
    ui->spinBox_5->setEnabled(true);
    ui->spinBox_6->setEnabled(true);
}

void ModelisationPrblm::on_radioButton_3_clicked()
{

    ui->doubleSpinBox_3->setEnabled(false);
    ui->doubleSpinBox_4->setEnabled(false);
    ui->spinBox_5->setEnabled(true);
    ui->spinBox_6->setEnabled(true);
}

void ModelisationPrblm::on_radioButton_2_clicked()
{
    ui->doubleSpinBox_3->setEnabled(true);
    ui->doubleSpinBox_4->setEnabled(true);
    ui->spinBox_5->setEnabled(false);
    ui->spinBox_6->setEnabled(false);
}
