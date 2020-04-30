#include <vector>	
#include <cmath>		
#include "individu.h"
#include "evaluation.h"
class operationsGenetiques{
	
	public : 
	
	operationsGenetiques(std::vector<individu>* individus, int maximisation_minimisation, int nmbr_indiv_a_selec);
	void selectionParRang();
	void triFusion(int debut, int fin);
	void Fusion(int debut, int milieu, int fin);
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
