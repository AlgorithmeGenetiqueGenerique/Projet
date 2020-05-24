#include "modelisationprblm.h"
#include "ui_modelisationprblm.h"
#include <QDebug>
#include <QAbstractButton>
#include <QGraphicsProxyWidget>
#include <QPushButton>
#include <QtCore>
#include "../mainwindow1.h"
#include <QMessageBox>


ModelisationPrblm::ModelisationPrblm(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::ModelisationPrblm)
{
    srand(unsigned(time(NULL)));
    ui->setupUi(this);
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
    min_intervalle=ui->lineEdit_2;
    max_intervalle=ui->lineEdit_3;
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
    /*nom_fichier_chargement=;
    configurer= ;
    consulter=;
    //---------------------------------------------------------
    layout_nombre_genes= new QVBoxLayout;
    layout_taille_population= new QVBoxLayout;
    layout_nombre_iterations= new QVBoxLayout;
    layout_nombre_individu_selectionnes= new QVBoxLayout;
    layout_type_genes= new QVBoxLayout;
    layout_type_genes_principale= new QVBoxLayout;
    layout_choix_selection= new QVBoxLayout;
    layout_taux_croisement= new QVBoxLayout;
    layout_taux_mutation= new QVBoxLayout;
    layout_maximisation_minimisation= new QVBoxLayout;
    layout_maximisation_minimisation_principale= new QVBoxLayout;
    layout_chaine_evaluation= new QVBoxLayout;
    layout_min_intervalle= new QVBoxLayout;
    layout_max_intervalle= new QVBoxLayout;
    layout_generation_satisfaisante= new QVBoxLayout;
    layout_nom_fichier_sauvegarde= new QVBoxLayout;
    layout_nom_fichier_latex= new QVBoxLayout;
    layout_nom_fichier_chargement= new QVBoxLayout;
    //-----------------------------------------------------------------------
    layout_configurer= new QHBoxLayout;
    layout_sauvegarder= new QHBoxLayout;
    layout_charger= new QHBoxLayout;
    layout_demarrer_simulation= new QHBoxLayout;
    layout_pause= new QHBoxLayout;
    layout_reprendre= new QHBoxLayout;
    layout_reconfigurer= new QHBoxLayout;
    layout_acceuil= new QHBoxLayout;
    layout_aide= new QHBoxLayout;
    layout_quitter= new QHBoxLayout;
    layout_consulter= new QHBoxLayout;
    //----------------------------------------------------------------------
    Layout_conteneur= new QGridLayout;
    //---------------------------------------------------------------------
    */
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
    label_min_intervalle=ui->label_intervalleMI;
    label_max_intervalle=ui->label_intervalleMA;
    label_generation_satisfaisante=ui->label_generationS;
    /*label_nom_fichier_sauvegarde=;
    label_nom_fichier_latex=;
    label_nom_fichier_chargement=;
    label_sauvegarder=;
    label_charger=;
    label_demarrer_simulation=;
    label_pause=;
    label_reprendre=;
    label_reconfigurer=;
    label_acceuil=;
    label_aide=;
    label_quitter=;
    label_consulter=;*/
    ntb=new notepad(this);
    thrd=new myThread(this);
    calculat=new Calculator(nullptr);
    calculat->close();
    QObject::connect(thrd,SIGNAL(txtEdt(int)),this,SLOT(onTxtEdt(int)));



}

void ModelisationPrblm::connectConfiguration(){

}
void ModelisationPrblm::connectReConfiguration(){

}
void ModelisationPrblm::connectSauvegarde(){

}
void ModelisationPrblm::connectChargement(){

}
void ModelisationPrblm::connectLancement(){

}
void ModelisationPrblm::connectPause(){

}
void ModelisationPrblm::connectReprendre(){

}
void ModelisationPrblm::connectAcceuil(){

}
void ModelisationPrblm::connectAide(){

}
void ModelisationPrblm::connectQuitter(){

}
void ModelisationPrblm::connectConsulter(){

}

ModelisationPrblm::~ModelisationPrblm()
{
    delete ui;
}

void ModelisationPrblm::on_pushButton_3_clicked()//Lancer la simulation
{
    chaine_evaluation->setStyleSheet("background-color: white;");
    ui->pushButton_4->setEnabled(false);
    thrd->Stop=false;
    thrd->count=0;
    ui->stackedWidget->setCurrentIndex(1);
    reprendre->setEnabled(false);
    reconfigurer->setEnabled(false);

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
    min_intervalle_ = min_intervalle->text().toDouble();
    max_intervalle_ = max_intervalle->text().toDouble();
    generation_satisfaisante_=generation_satisfaisante->text().toDouble();
    QString chaineEval="";
    if(ui->checkBox->isChecked())
        chaineEval=calculat->getEvaluation();
    else
        chaineEval=ui->lineEdit->text();
    if(type==2)
        ee = new EntreesSorties( chaineEval.toStdString(), taille_population->value(), nombre_iterations->value(), nombre_individu_selectionnes->value(), ui->comboBox->currentIndex()+1,nombre_genes->value(),taux_croisement->value(),taux_mutation->value(),ui->lineEdit_4->text().toDouble(), type, min_intervalle->text().toDouble(), max_intervalle->text().toDouble(),maxMin);
    else
        ee = new EntreesSorties( chaineEval.toStdString(), taille_population->value(), nombre_iterations->value(), nombre_individu_selectionnes->value(), ui->comboBox->currentIndex()+1,nombre_genes->value(),taux_croisement->value(),taux_mutation->value(),ui->lineEdit_4->text().toInt(), type, min_intervalle->text().toInt(), max_intervalle->text().toInt(),maxMin);
    op = new operationsGenetiques(&individus,ee->getMaximisationMinimisation(), ee->getNmbr_indiv_a_selec());
    sb = ui->textBrowser->verticalScrollBar();
    score_totale=0;
    evaluation evaluation_test = evaluation(ee->getChaineEvaluation());
    if(type==1 || type==3)
        evaluation_test.evaluer(new individu(ee->getMinIntervalle(),ee->getMaxIntervalle(), ee->getNombreGenes(),ee->getTypeGenes()));
    else
        evaluation_test.evaluer(new individu(ee->getMinIntervalleFlottant(),ee->getMaxIntervalleFlottant(), ee->getNombreGenes(),ee->getTypeGenes()));

    if(evaluation_test.getErreur())
    {
        chaine_evaluation->setStyleSheet("background-color: red;");
        ui->stackedWidget->setCurrentIndex(0);

        QMessageBox::warning(this, "Erreur", "Impossible de lancer la simulation:\nSymbole indisponible"
                                             "pour le nombre de genes choisi");
    }
    else
     thrd->start();

}

void ModelisationPrblm::on_pushButton_2_clicked()//----
{
    ui->stackedWidget->setCurrentIndex(2);
}

void ModelisationPrblm::on_pushButton_6_clicked()//----
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
            }
            evaluation e = evaluation (ee->getChaineEvaluation());
            if (ee->getTypeGenes() == 1){
                meilleur_premier = individus[0].getNoteEvaluation();
                score_totale = score_totale/individus.size();
                arret = e.testArret(score_totale,ee->getGenerationSatisfaisante(), ee->getMaximisationMinimisation());
                meillleur_individu.push_back(individus.at(0).getNoteEvaluation());
                score_total.push_back(score_totale);
            }
            else if (ee->getTypeGenes() == 2){
                meilleur_premier_d = individus[0].getNoteEvaluationFlottant();
                score_totale_d = score_totale_d/individus.size();
                arret = e.testArret(score_totale_d,ee->getGenerationSatisfaisanteFlottant(), ee->getMaximisationMinimisation());
                meillleur_individu_d.push_back(individus.at(0).getNoteEvaluationFlottant());
                score_total_d.push_back(score_totale_d);
            }
            else if (ee->getTypeGenes() == 3){

                meilleur_premier = individus[0].getNoteEvaluation();
                score_totale = individus[0].conversionVersBinaire(score_totale/individus.size());
                arret = e.testArret(score_totale,ee->getGenerationSatisfaisante(), ee->getMaximisationMinimisation());
                meillleur_individu.push_back(individus.at(0).getNoteEvaluation());
                score_total.push_back(score_totale);
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
        }
        else if (ee->getTypeGenes() == 2)
        {
            arret = e2.testArret(score_totale_d/individus.size(),ee->getGenerationSatisfaisanteFlottant(), ee->getMaximisationMinimisation());
            score_total_d.push_back(score_totale_d/individus.size());
            meillleur_individu_d.push_back(individus.at(0).getNoteEvaluationFlottant());
            ui->textBrowser->insertPlainText("generation : "+QString::number(compteur_generation)+" Score :"+QString::number(score_total_d[compteur_generation]));
            ui->textBrowser->insertPlainText("\n");
        }
        else if (ee->getTypeGenes() == 3)
        {
            arret = e2.testArret(individus[0].conversionVersBinaire(score_totale/individus.size()),ee->getGenerationSatisfaisante(), ee->getMaximisationMinimisation());
            score_total.push_back(individus[0].conversionVersBinaire(score_totale/individus.size()));
            meillleur_individu.push_back(individus.at(0).getNoteEvaluation());
            ui->textBrowser->insertPlainText("generation : "+QString::number(compteur_generation)+" Score :"+QString::number(score_total[compteur_generation]));
            ui->textBrowser->insertPlainText("\n");
        }
            compteur_generation++;





 //--------------------------------------------------------------------------------------------
    sb->setValue(sb->maximum());
    thrd->count=j;
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
}


//♣♣♣

void ModelisationPrblm::on_checkBox_stateChanged(int arg1)
{
    if(ui->checkBox->isChecked())
        ui->lineEdit->setEnabled(false);

    else
        ui->lineEdit->setEnabled(true);



}

void ModelisationPrblm::on_pushButton_10_clicked()
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
    min_intervalle_ = min_intervalle->text().toDouble();
    max_intervalle_ = max_intervalle->text().toDouble();
    generation_satisfaisante_=generation_satisfaisante->text().toDouble();
    QString chaineEval="";
    if(ui->checkBox->isChecked())
        chaineEval=calculat->getEvaluation();
    else
        chaineEval=ui->lineEdit->text();
    if(type==2)
        ee = new EntreesSorties( chaineEval.toStdString(), taille_population->value(), nombre_iterations->value(), nombre_individu_selectionnes->value(), ui->comboBox->currentIndex()+1,nombre_genes->value(),taux_croisement->value(),taux_mutation->value(),ui->lineEdit_4->text().toDouble(), type, min_intervalle->text().toDouble(), max_intervalle->text().toDouble(),maxMin);
    else
        ee = new EntreesSorties( chaineEval.toStdString(), taille_population->value(), nombre_iterations->value(), nombre_individu_selectionnes->value(), ui->comboBox->currentIndex()+1,nombre_genes->value(),taux_croisement->value(),taux_mutation->value(),ui->lineEdit_4->text().toInt(), type, min_intervalle->text().toInt(), max_intervalle->text().toInt(),maxMin);
    ee->sauvegarde(ui->lineEdit_5->text().toStdString());
    ui->stackedWidget->setCurrentIndex(0);
}


void ModelisationPrblm::on_pushButton_clicked()
{
    ui->stackedWidget->setCurrentIndex(3);
}

void ModelisationPrblm::on_pushButton_11_clicked()
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
    ui->comboBox->setCurrentIndex(ee->getChoixSelection());
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
    if(ee->getTypeGenes()==2)
    {
        ui->lineEdit_2->setText(QString::number(ee->getMinIntervalleFlottant()));
        ui->lineEdit_3->setText(QString::number(ee->getMaxIntervalleFlottant()));
        ui->lineEdit_2->setText(QString::number(ee->getGenerationSatisfaisanteFlottant()));
    }
    else
    {
        ui->lineEdit_2->setText(QString::number(ee->getMinIntervalle()));
        ui->lineEdit_3->setText(QString::number(ee->getMaxIntervalle()));
        ui->lineEdit_2->setText(QString::number(ee->getGenerationSatisfaisante()));
    }

    ui->stackedWidget->setCurrentIndex(0);
}




/*ui->textBrowser->insertPlainText("Chaine evaluation : "+chaine_evaluation->text());
printf("%s",chaine_evaluation->text().toStdString().c_str());
ui->textBrowser->insertPlainText("\n");
ui->textBrowser->insertPlainText("Taille population : "+QString::number(taille_population->value()));
printf("%d\n",taille_population->value());
ui->textBrowser->insertPlainText("\n");
ui->textBrowser->insertPlainText("Nombre iteration : "+QString::number(nombre_iterations->value()));
printf("%d\n",nombre_iterations->value());
ui->textBrowser->insertPlainText("\n");
ui->textBrowser->insertPlainText("Select nomber : "+QString::number(nombre_individu_selectionnes->value()));
printf("%d\n",nombre_individu_selectionnes->value());
ui->textBrowser->insertPlainText("\n");
ui->textBrowser->insertPlainText("Choix selection : "+QString::number(ui->comboBox->currentIndex()+1));
printf("%d\n",ui->comboBox->currentIndex()+1);
ui->textBrowser->insertPlainText("\n");
ui->textBrowser->insertPlainText("nombre des genes : "+QString::number(nombre_genes->value()));
printf("%d\n",nombre_genes->value());
ui->textBrowser->insertPlainText("\n");
ui->textBrowser->insertPlainText("Taux de croisement : "+QString::number(taux_croisement->value()));
printf("%f\n",taux_croisement->value());
ui->textBrowser->insertPlainText("\n");
ui->textBrowser->insertPlainText("Taux de mutation : "+QString::number(taux_mutation->value()));
printf("%f\n",taux_mutation->value());
ui->textBrowser->insertPlainText("\n");
ui->textBrowser->insertPlainText("Generation sat : "+QString::number(ui->lineEdit_4->text().toDouble()));
printf("%f\n",ui->lineEdit_4->text().toDouble());
ui->textBrowser->insertPlainText("\n");
ui->textBrowser->insertPlainText("Minimisation maximisation : "+QString::number(maxMin));
printf("%d\n",maxMin);
ui->textBrowser->insertPlainText("\n");
ui->textBrowser->insertPlainText("Type de genes: "+QString::number(type));
printf("%d\n",type);
ui->textBrowser->insertPlainText("\n");
ui->textBrowser->insertPlainText("Intervalle Max: "+QString::number(max_intervalle->text().toDouble()));
printf("%f\n",max_intervalle->text().toDouble());
ui->textBrowser->insertPlainText("\n");
ui->textBrowser->insertPlainText("Intervalle Min: "+QString::number(min_intervalle->text().toDouble()));
printf("%f\n",min_intervalle->text().toDouble());
ui->textBrowser->insertPlainText("\n");*/

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
