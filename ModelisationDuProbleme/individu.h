#ifndef INDIVIDU_H
#define INDIVIDU_H

#include <string>
#include <cmath>
#include "gene.h"

class individu
{
    public:
    individu();
    individu(int min_intervalle, int max_intervalle, int nombre_genes, int type_genes);
    individu(double min_intervalle, double max_intervalle, int nombre_genes, int type_genes);
    
    int valeurAleatoire(int min_intervalle, int max_intervalle);
    double valeurAleatoire(double min_intervalle, double max_intervalle);
    
    int conversionVersBinaire(int decimale); 
    int convertionVersDecimale(int binaire);
     
    int getNoteEvaluation();
    double getNoteEvaluationFlottant();
    int getDebutItervalle();
    int getFinItervalle();
    double getDebutIntervalleFlottant();
    double getFinIntervalleFlottant();
    
    void setNoteEvaluation(int note_evaluation);
    void setNoteEvaluationFlottant(double note_evaluation_flottant);
    void setDebutIntervalleFlottant(double debut_intervalle);
    void setFinIntervalleFlottant(double fin_intervalle);
    void setDebutIntervalle(int debut_intervalle);
    void setFinIntervalle(int fin_intervalle);
    
    gene ADN;
   
    private:
    int note_evaluation;
	double note_evaluation_flottant;
	int debut_intervalle;
	int fin_intervalle;
	double debut_intervalle_flottant;
	double fin_intervalle_flottant;
};
#endif // INDIVIDU_H
