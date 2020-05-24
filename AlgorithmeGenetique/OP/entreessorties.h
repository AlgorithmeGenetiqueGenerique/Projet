#ifndef es_h
#define es_h

#include <iostream>
#include <fstream>
#include <vector>
#include "individu.h"

class EntreesSorties
{
    public:

    EntreesSorties(std::string nom_fichier);

    EntreesSorties(std::string chaine_evaluation, int taille_population, int nombre_iterations, int nmbr_indiv_a_selec, int choix_selection , int nombre_genes, float taux_croisement, float taux_mutation, int generation_satisfaisante, int type_genes, int min_intervalle, int max_intervalle, int maximisation_minimisation);

    EntreesSorties(std::string chaine_evaluation, int taille_population, int nombre_iterations, int nmbr_indiv_a_selec, int choix_selection , int nombre_genes, float taux_croisement, float taux_mutation, double generation_satisfaisante, int type_genes, double min_intervalle, double max_intervalle, int maximisation_minimisation);

    void sauvegarde(std::string nom_fichier);

    void genererLatex(std::vector<individu>* individus, std::string nom_fichier);

    std::string getChaineEvaluation();
    int getTaillePopulation();
    int getNombreiterations();
    int getNmbr_indiv_a_selec();
    int getChoixSelection();
    int getNombreGenes();
    float getTauxCroisement();
    float getTauxMutation();
    int getGenerationSatisfaisante();
    double getGenerationSatisfaisanteFlottant();
    int getTypeGenes();
    int getMinIntervalle();
    int getMaxIntervalle();
    double getMinIntervalleFlottant();
    double getMaxIntervalleFlottant();
    std::vector<int> getNoteMoyenne();
    std::vector<double> getNoteMoyenneFlottant();
    std::vector<int> getMeilleurIndividu();
    std::vector<double> getMeilleurIndividuFlottant();
    int getMaximisationMinimisation();

    void setChaineEvaluation(std::string chaine_evaluation);
    void setTaillePopulation(int taille_population);
    void setNombreiterations(int nombre_iterations);
    void setNmbr_indiv_a_selec(int nmbr_indiv_a_selec);
    void setChoixSelection(int choix_selection);
    void setNombreGenes(int nombre_genes);
    void setTauxCroisement(float taux_croisement);
    void setTauxMutation(float taux_mutation);
    void setGenerationSatisfaisante(int generation_satisfaisante);
    void setGenerationSatisfaisanteFlottant(double generation_satisfaisante);
    void setTypeGenes(int type_genes);
    void setMinIntervalle(int min_intervalle);
    void setMaxIntervalle(int max_intervalle);
    void setMinIntervalleFlottant(double min_intervalle);
    void setMaxIntervalleFlottant(double max_intervalle);
    void setNoteMoyenne(std::vector<int> note_moyenne);
    void setNoteMoyenneFlottant(std::vector<double> note_moyenne);
    void setMeilleurIndividu(std::vector<int> meilleur_individu);
    void setMeilleurIndividuFlottant(std::vector<double> meilleur_individu);
    void setMaximisationMinimisation(int maximisation_minimisation);

    private :
    std::string chaine_evaluation;
    int taille_population;
    int nombre_iterations;
    int nmbr_indiv_a_selec;
    int choix_selection;
int nombre_genes;
    float taux_croisement;
    float taux_mutation;
    int generation_satisfaisante;
    double generation_satisfaisante_flottant;
    int type_genes;
    int min_intervalle;
    int max_intervalle;
    double min_intervalle_flottant;
    double max_intervalle_flottant;
    std::vector<int> note_moyenne;
    std::vector<double> note_moyenne_flottant;
    std::vector<int> meilleur_individu;
    std::vector<double> meilleur_individu_flottant;
    int maximisation_minimisation;
};
#endif
