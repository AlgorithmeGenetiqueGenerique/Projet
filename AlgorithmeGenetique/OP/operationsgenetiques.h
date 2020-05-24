#ifndef OPG_H
#define OPG_H

#include <vector>	
#include <cmath>		
#include "evaluation.h"
#include <iostream>
class operationsGenetiques{
	
	public : 
	
	operationsGenetiques(std::vector<individu>* individus, int maximisation_minimisation, int nmbr_indiv_a_selec);
	void selectionParRang();
	void triFusion(int debut, int fin);
	void Fusion(int debut, int milieu, int fin);
	void selectionParTournoi();
	void selectionParRoulette();
	void configurationIntervalles();
	double calculeNoteTotalFlottant();
	int calculeNoteTotal();
	void croisement(float taux_croisement, float taux_mutation, int taille_population, std::string chaine_evaluation);
	void mutation(individu* individu_x, float taux_mutation);
	
	int getMaximisationMinimisation();
    int getNmbr_indiv_a_selec();
	
	void setNmbr_indiv_a_selec(int nmbr_indiv_a_selec);
	void setMaximisationMinimisation(int maximisation_minimisation);
	
	private :
	std::vector<individu>* individus;
	int nmbr_indiv_a_selec; 
	int maximisation_minimisation;
};
#endif
