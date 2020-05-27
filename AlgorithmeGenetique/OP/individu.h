#ifndef INDIVIDU_H
#define INDIVIDU_H

#include <string>
#include <cmath>
#include <stdlib.h>
#include "gene.h"

class individu
{
    public:
    individu();
    //Constructeur utiliser dans le cas où les gènes sont de type entiers ou booléens
    individu(int min_intervalle, int max_intervalle, int nombre_genes, int type_genes);
    //Constructeur utiliser dans le cas où les gènes sont de type flottants
    individu(double min_intervalle, double max_intervalle, int nombre_genes, int type_genes);
    
    /*génére une valeur entière comprise entre min_intervalle et int max_intervalle
     * dans le cas où les gènes sont de type entiers ou booléens */
    int valeurAleatoire(int min_intervalle, int max_intervalle);
    /*génére une valeur entière comprise entre min_intervalle et int max_intervalle
     * dans le cas où les gènes sont de type flottants */
    double valeurAleatoire(double min_intervalle, double max_intervalle);
    
    //Convertie un nombre décimale en binaire
    int conversionVersBinaire(int decimale);
    //Convertie un nombre binaire en décimale
    int convertionVersDecimale(int binaire);
     
    //Retourne l’attribut note_evaluation dans le cas où les gènes sont de type entiers ou binaires
    int getNoteEvaluation();
    //Retourne l’attribut note_evaluation dans le cas où les gènes sont de type flottants
    double getNoteEvaluationFlottant();
    //Retourne l’attribut debut_intervalle
    int getDebutItervalle();
    //Retourne l’attribut ﬁn_intervalle
    int getFinItervalle();
    //Retourne l’attribut double debut_intervalle_ﬂottant
    double getDebutIntervalleFlottant();
    //Retourne l’attribut double ﬁn_intervalle_ﬂottant
    double getFinIntervalleFlottant();
    
    //Permet de modiﬁer la valeur de l’attribut note_evaluation
    void setNoteEvaluation(int note_evaluation);
    //Permet de modiﬁer la valeur de l’attribut note_evaluation_ﬂottant
    void setNoteEvaluationFlottant(double note_evaluation_flottant);
    //Permet de modiﬁer la valeur de l’attribut int debut_intervalle_ﬂottant
    void setDebutIntervalleFlottant(double debut_intervalle);
    //Permet de modiﬁer la valeur de l’attribut int ﬁn_intervalle_ﬂottant
    void setFinIntervalleFlottant(double fin_intervalle);
    //Permet de modiﬁer la valeur de l’attribut int debut_intervalle
    void setDebutIntervalle(int debut_intervalle);
    //Permet de modiﬁer la valeur de l’attribut int ﬁn_intervalle
    void setFinIntervalle(int fin_intervalle);

    //Contenien tous les gènes de l’individu
    gene ADN;
   
    private:
    //Type d'entiers avec une extension utilisé dans la conversion d'un décimale vers binaire
    #define ull_ unsigned long long int
    //la note représentant la capacité d’adaptation d’un individu dans l'environnement pour type gènes entiers et binaires
    int note_evaluation;
    //la note représentant la capacité d’adaptation d’un individu dans l'environnement pour type gènes flottants
	double note_evaluation_flottant;

    //Outil nécessaires pour concevoire les intervalles utiliser dans la séléction par roulette pour un type de gène entier ou binaire
	int debut_intervalle;
    //Outil nécessaires pour concevoire les intervalles utiliser dans la séléction par roulette pour un type de gène entier ou binaire
	int fin_intervalle;
    //Outil nécessaires pour concevoire les intervalles utiliser dans la séléction par roulette pour un type de gène flottant
	double debut_intervalle_flottant;
    //Outil nécessaires pour concevoire les intervalles utiliser dans la séléction par roulette pour un type de gène flottant
	double fin_intervalle_flottant;
};
#endif // INDIVIDU_H
