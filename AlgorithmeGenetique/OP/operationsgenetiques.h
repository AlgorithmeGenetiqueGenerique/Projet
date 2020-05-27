#ifndef OPG_H
#define OPG_H

#include <vector>	
#include <cmath>		
#include "evaluation.h"
#include <iostream>

class operationsGenetiques{
	
	public : 
    //Constructeur de la classe
	operationsGenetiques(std::vector<individu>* individus, int maximisation_minimisation, int nmbr_indiv_a_selec);
    //c'est cette méthode qui est appelée pour faire la sélection par rang
	void selectionParRang();
    //méthode qui fait un tri de type fusion sur notre population
	void triFusion(int debut, int fin);
    //méthode utilisé par la fonction triFusion
	void Fusion(int debut, int milieu, int fin);
    //c'est cette méthode qui est appelée pour faire la sélection par tournoi
	void selectionParTournoi();
    //c'est cette méthode qui est appelée pour faire la sélection par roulette
	void selectionParRoulette();
    /* elle génère un intervalle indiquant l’importance de la note d’évaluation
     * d’un individu par rapport a la note total de la population pour chaque
     * membre de notre population, l’ensemble des intervalles
     * se complètent et constitue la note total*/
	void configurationIntervalles();
    /*utiliser dans conﬁgurationIntervalles calcule la note total de la population
     * dans le cas où les gènes sont de type ﬂottant*/
    double calculeNoteTotalFlottant();
    /*utiliser dans conﬁgurationIntervalles calcule la note total de la population
     * dans le cas où les gènes sont de type entier*/
	int calculeNoteTotal();
    //Méthode appelée pour effectué le croisement
	void croisement(float taux_croisement, float taux_mutation, int taille_population, std::string chaine_evaluation);
    //Méthode appelée pour effectué la mutation
    void mutation(individu* individu_x, float taux_mutation);
	
	int getMaximisationMinimisation();
    int getNmbr_indiv_a_selec();
	
	void setNmbr_indiv_a_selec(int nmbr_indiv_a_selec);
	void setMaximisationMinimisation(int maximisation_minimisation);
	
	private :
    //pointeur sur l'ensemble individus qui héberge notre population
	std::vector<individu>* individus;
	int nmbr_indiv_a_selec; 
	int maximisation_minimisation;
};
#endif
