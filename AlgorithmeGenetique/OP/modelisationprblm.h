#ifndef MODELISATIONPRBLM_H
#define MODELISATIONPRBLM_H
#include <QComboBox>
#include <QSpinBox>
#include <QPushButton>
#include <QVBoxLayout>
#include <QLabel>
#include <QGroupBox>
#include <QRadioButton>
#include <QLineEdit>
#include <QDoubleSpinBox>
#include <QMenu>
#include <QMenuBar>
#include <QAction>
#include <QGridLayout>
#include <time.h>
#include <QMainWindow>
#include <QObject>
#include <QtCore>
#include "mythread.h"
#include "individu.h"
#include "evaluation.h"
#include "gene.h"
#include "EntreesSorties.h"
#include "operationsgenetiques.h"
#include <QScrollBar>
#include "notebad.h"
#include "calculator.h"



namespace Ui {
class ModelisationPrblm;
}

class ModelisationPrblm : public QMainWindow
{
    Q_OBJECT

public:
    explicit ModelisationPrblm(QWidget *parent = nullptr);
    ~ModelisationPrblm();
     myThread *thrd;

public slots:
    void connectConfiguration();
    void connectReConfiguration();
    void connectSauvegarde();
    void connectChargement();
    void connectLancement();
    void connectPause();
    void connectReprendre();
    void connectAcceuil();
    void connectAide();
    void connectQuitter();
    void connectConsulter();
    void onTxtEdt(int a);

private slots:
    void on_pushButton_3_clicked();

    void on_pushButton_2_clicked();

    void on_pushButton_6_clicked();



    void on_pushButton_9_clicked();

    void on_pushButton_8_clicked();

    void on_pushButton_7_clicked();

    void on_checkBox_stateChanged(int arg1);

    void on_pushButton_10_clicked();

    void on_pushButton_clicked();

    void on_pushButton_11_clicked();

    void on_pushButton_12_clicked();

    void on_pushButton_13_clicked();

    void on_pushButton_4_clicked();

    void on_pushButton_14_clicked();

    void on_pushButton_5_clicked();

signals:
    void ppp();

private:
    Ui::ModelisationPrblm *ui;
    QComboBox* choix_selection;//
    QSpinBox *nombre_genes;
    QSpinBox *taille_population;
    QSpinBox *nombre_iterations;
    QSpinBox *nombre_individu_selectionnes;
    QDoubleSpinBox* taux_croisement;
    QDoubleSpinBox* taux_mutation;
    QPushButton *configurer = nullptr;
    QPushButton *sauvegarder;
    QPushButton *charger;
    QPushButton *demarrer_simulation;
    QPushButton *pause;
    QPushButton *reprendre;
    QPushButton *reconfigurer;
    QPushButton *acceuil;
    QPushButton *aide;
    QPushButton *quitter;
    QPushButton *consulter;
    QVBoxLayout *testL;
    QVBoxLayout *layout_nombre_genes;
    QVBoxLayout *layout_taille_population;
    QVBoxLayout *layout_nombre_iterations;
    QVBoxLayout *layout_nombre_individu_selectionnes;
    QVBoxLayout *layout_type_genes;
    QVBoxLayout *layout_type_genes_principale;
    QVBoxLayout *layout_choix_selection;
    QVBoxLayout *layout_maximisation_minimisation;
    QVBoxLayout *layout_maximisation_minimisation_principale;
    QVBoxLayout *layout_chaine_evaluation;
    QVBoxLayout *layout_min_intervalle;
    QVBoxLayout *layout_max_intervalle;
    QVBoxLayout *layout_generation_satisfaisante;
    QVBoxLayout *layout_taux_croisement;
    QVBoxLayout *layout_taux_mutation;
    QVBoxLayout *layout_nom_fichier_sauvegarde;
    QVBoxLayout *layout_nom_fichier_latex;
    QVBoxLayout *layout_nom_fichier_chargement;
    QHBoxLayout *layout_configurer;
    QHBoxLayout *layout_sauvegarder;
    QHBoxLayout *layout_charger;
    QHBoxLayout *layout_demarrer_simulation;
    QHBoxLayout *layout_pause;
    QHBoxLayout *layout_reprendre;
    QHBoxLayout *layout_reconfigurer;
    QHBoxLayout *layout_acceuil;
    QHBoxLayout *layout_aide;
    QHBoxLayout *layout_quitter;
    QHBoxLayout *layout_consulter;
    QGridLayout* Layout_conteneur;
    QLabel *label_type_genes; //***
    QLabel *label_nombre_genes;
    QLabel *label_taille_population;
    QLabel *label_nombre_iterations;
    QLabel *label_nombre_individu_selectionnes;
    QLabel *label_choix_selection;
    QLabel *label_chaine_evaluation;
    QLabel *label_min_intervalle;
    QLabel *label_max_intervalle;
    QLabel *label_generation_satisfaisante;
    QLabel *label_taux_croisement;
    QLabel *label_taux_mutation;
    QLabel *label_nom_fichier_sauvegarde;
    QLabel *label_nom_fichier_latex;
    QLabel *label_nom_fichier_chargement;
    QLabel *label_sauvegarder;
    QLabel *label_charger;
    QLabel *label_demarrer_simulation;
    QLabel *label_pause;
    QLabel *label_reprendre;
    QLabel *label_reconfigurer;
    QLabel *label_acceuil;
    QLabel *label_aide;
    QLabel *label_quitter;
    QLabel *label_consulter;
    QGroupBox* type_genes;
    QGroupBox* maximisation_minimisation;
    QRadioButton* entier;
    QRadioButton* flottant;
    QRadioButton* binaire;
    QRadioButton* maximisation;
    QRadioButton* minimisation;
    QLineEdit* chaine_evaluation;
    QLineEdit* min_intervalle;
    QLineEdit* max_intervalle;
    QLineEdit* generation_satisfaisante;
    QLineEdit* nom_fichier_sauvegarde;
    QLineEdit* nom_fichier_latex;
    QLineEdit* nom_fichier_chargement;
    QTimer *timer;
    //--------------------------
    EntreesSorties *ee;
    operationsGenetiques *op;

    int score_totale = 0;
    double score_totale_d = 0;
    int meilleur_premier;
    double meilleur_premier_d;
    bool arret = false;
    std::vector<int> score_total;
    std::vector<double> score_total_d;
    std::vector<int> meillleur_individu;
    std::vector<double> meillleur_individu_d;
    std::vector<individu> individus;
    int compteur_generation;
    std::string chaine_evaluation_;
    double generation_satisfaisante_;
    double min_intervalle_;
    double max_intervalle_;
    QScrollBar *sb;
    notepad *ntb;
    Calculator *calculat;

};

#endif // MODELISATIONPRBLM_H
