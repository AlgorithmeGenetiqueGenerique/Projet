#include "EntreesSorties.h"

EntreesSorties::EntreesSorties(std::string nom_fichier){
	std::ifstream file(nom_fichier);
    std::string ligne;
    std::getline(file, ligne);
    taille_population = stoi(ligne);
    std::getline(file, ligne);
    type_genes = stoi(ligne);
    std::getline(file, ligne);
    nombre_genes = stoi(ligne);
    std::getline(file, chaine_evaluation);
    if (type_genes == 1 || type_genes == 3){
		std::getline(file, ligne);
		min_intervalle= stoi(ligne);
		 std::getline(file, ligne);
		max_intervalle = stoi(ligne);
		    std::getline(file, ligne);
    generation_satisfaisante = stoi(ligne);
	}
    
    else if (type_genes == 2){
		std::getline(file, ligne);
		min_intervalle_flottant= stod(ligne);
		 std::getline(file, ligne);
		max_intervalle_flottant = stod(ligne);
		    std::getline(file, ligne);
    generation_satisfaisante_flottant = stod(ligne);
	}
    std::getline(file, ligne);
    nombre_iterations = stoi(ligne);
    std::getline(file, ligne);
    choix_selection = stoi(ligne);
    std::getline(file, ligne);
    nmbr_indiv_a_selec = stoi(ligne);
    std::getline(file, ligne);
    taux_croisement = stof(ligne);
    std::getline(file, ligne);
    taux_mutation = stof(ligne);
    std::getline(file, ligne);
    maximisation_minimisation = stoi(ligne);
}

EntreesSorties::EntreesSorties(std::string chaine_evaluation, int taille_population, int nombre_iterations, int nmbr_indiv_a_selec, int choix_selection , int nombre_genes, float taux_croisement, float taux_mutation, int generation_satisfaisante, int type_genes, int min_intervalle, int max_intervalle, int maximisation_minimisation){
		this->max_intervalle = max_intervalle;
		this-> min_intervalle = min_intervalle;
		this->type_genes = type_genes;
		this->generation_satisfaisante = generation_satisfaisante;
		this->taux_mutation = taux_mutation;
		this->taux_croisement = taux_croisement;
		this->nombre_genes = nombre_genes;
		this->choix_selection = choix_selection;
		this->nmbr_indiv_a_selec = nmbr_indiv_a_selec;
		this->nombre_iterations = nombre_iterations;
		this->taille_population = taille_population;
		this->chaine_evaluation = chaine_evaluation;
		this->maximisation_minimisation = maximisation_minimisation;
}
EntreesSorties::EntreesSorties(std::string chaine_evaluation, int taille_population, int nombre_iterations, int nmbr_indiv_a_selec, int choix_selection , int nombre_genes, float taux_croisement, float taux_mutation, double generation_satisfaisante, int type_genes, double min_intervalle, double max_intervalle, int maximisation_minimisation){
		this->max_intervalle_flottant = max_intervalle;
		this-> min_intervalle_flottant = min_intervalle;
		this->type_genes = type_genes;
		this->generation_satisfaisante_flottant = generation_satisfaisante;
		this->taux_mutation = taux_mutation;
		this->taux_croisement = taux_croisement;
		this->nombre_genes = nombre_genes;
		this->choix_selection = choix_selection;
		this->nmbr_indiv_a_selec = nmbr_indiv_a_selec;
		this->nombre_iterations = nombre_iterations;
		this->taille_population = taille_population;
		this->chaine_evaluation = chaine_evaluation;
		this->maximisation_minimisation = maximisation_minimisation;
}


void EntreesSorties::sauvegarde(std::string nom_fichier){
	std::ofstream monFlux(nom_fichier.c_str());
	if (monFlux) {
        monFlux <<taille_population<< std::endl;
                   monFlux <<type_genes<< std::endl;
        monFlux <<nombre_genes<< std::endl;
        monFlux <<chaine_evaluation<< std::endl;
        if (type_genes == 1 || type_genes == 3){
			monFlux <<min_intervalle<< std::endl;
			monFlux <<max_intervalle<< std::endl;
			monFlux <<generation_satisfaisante<< std::endl;
		}
        else {
			monFlux <<min_intervalle_flottant<< std::endl;
			monFlux <<max_intervalle_flottant<< std::endl;
			monFlux <<generation_satisfaisante_flottant<< std::endl;
		}
        
        monFlux <<nombre_iterations<< std::endl;
        monFlux <<choix_selection<< std::endl;
        monFlux <<nmbr_indiv_a_selec<< std::endl;
        monFlux <<taux_croisement<< std::endl;
        monFlux <<taux_mutation<< std::endl;
        monFlux <<maximisation_minimisation<< std::endl;
	}
	else {
		std::cout << "ERREUR: Impossible d'ouvrir le fichier." << std::endl;
	}
}

void EntreesSorties::genererLatex(std::vector<individu>* individus, std::string nom_fichier){
	std::ofstream monFlux(nom_fichier.c_str());
	if (monFlux) {
		monFlux << "\\documentclass[a4paper,10pt]{article}" << std::endl;
				monFlux << "\\usepackage{tikz}" << std::endl;
				monFlux << "\\usepackage{pgfplots}" << std::endl;
				monFlux << "\\usepackage[utf8]{inputenc}" << std::endl;
				monFlux << "\\usepackage[T1]{fontenc}" << std::endl;
				monFlux << "\\usepackage{lmodern}" << std::endl;
				monFlux << "\\usepackage[frenchb]{babel}" << std::endl;
				monFlux << "\\usepackage[latin1]{inputenc}" << std::endl;
				monFlux << "\\usepackage[francais]{babel}" << std::endl;
				monFlux << "\\usepackage{amsmath}" << std::endl;
				monFlux << "\\usepackage{amssymb}" << std::endl;
				monFlux << "\\usepackage{mathrsfs}" << std::endl;
				monFlux << "\\begin{document}" << std::endl;
				monFlux << "\\\\Récapitulatif de la configuration choisie : " << std::endl;
				monFlux << "\\\\Taille de la population :  " <<individus->size()<< std::endl;
				monFlux << "\\\\Type des gène :  ";
				switch((individus)->at(0).ADN.getTypeGenes()){
					case 1 : {monFlux << "Entier";
								break;}
					case 2 : {monFlux << "Double";
								break;}
					case 3 : {monFlux << "Boolèen";
								break;}
				}
				monFlux << "\\\\Nombre de gènes :  "<<nombre_genes<< std::endl;
				monFlux << "\\\\Chaine évaluer :  "<<chaine_evaluation<< std::endl;
				if (((individus)->at(0).ADN.getTypeGenes() == 1) || ((individus)->at(0).ADN.getTypeGenes() == 3)){
					monFlux << "\\\\Intervalle :  ["<<min_intervalle<<" , "<<max_intervalle<<" ]"<< std::endl;
					monFlux << "\\\\La génération satisfaisante :  "<< generation_satisfaisante << std::endl;
				}
				else if ((individus)->at(0).ADN.getTypeGenes() == 2){
					monFlux << "\\\\Intervalle :  ["<<min_intervalle_flottant<<" , "<<max_intervalle_flottant<<" ]"<< std::endl;
					monFlux << "\\\\La génération satisfaisante :  "<< generation_satisfaisante_flottant << std::endl;
				}
				monFlux << "\\\\Nombre d'itérations maximum fixé :  "<< nombre_iterations << std::endl;
				monFlux << "\\\\Type de séléction :  ";
				switch(choix_selection){
					case 1 : {monFlux << "Séléction par rang";
								break;}
					case 2 : {monFlux << "Sélétion par tournoi";
								break;}
					case 3 : {monFlux << "Séléction par roulette";
								break;}
				}
				monFlux << "\\\\Le taux de croisement :  "<<taux_croisement<< std::endl;
				monFlux << "\\\\Le taux de mutation :  "<<taux_mutation<< std::endl;
				monFlux << "\\\\Nombre d'individus à séléctionné :  "<<nmbr_indiv_a_selec<< std::endl;
				if (maximisation_minimisation == 1)
					monFlux << "\\\\Convergence : Maximisation"<<std::endl;
				else if (maximisation_minimisation == 2)
					monFlux << "\\\\Convergence : Minimisation"<<std::endl;
				monFlux << "\\\\\\begin{figure}[h]" << std::endl;
				monFlux << "\\\\\\\\\\begin{tikzpicture}" << individus->size()<< std::endl;
				monFlux << "\\begin{axis}[xlabel=Numéro génération ,ylabel=Moyenne scores,axis x line=bottom ,axis y line=left]" << std::endl;
				monFlux << "\\addplot coordinates {" << std::endl;
				if ((individus)->at(0).ADN.getTypeGenes() == 1)
					for (int i=0; i < note_moyenne.size();i++){
						monFlux << "(" << i << "," << note_moyenne.at(i) <<") ";
					}
				else if ((individus)->at(0).ADN.getTypeGenes() == 2)
					for (int i=0; i < note_moyenne_flottant.size();i++){
						monFlux << "(" << i << "," << note_moyenne_flottant.at(i) <<") ";
					}
				else if ((individus)->at(0).ADN.getTypeGenes() == 3)
					for (int i=0; i < note_moyenne.size();i++){
						monFlux << "(" << i << "," << individus->at(0).convertionVersDecimale(note_moyenne.at(i)) <<") ";
					}
				monFlux << "};" << std::endl;
				monFlux << "\\end{axis}" << std::endl;
				monFlux << "\\end{tikzpicture}" << std::endl;
				monFlux << "\\caption{Graphe représentant l'évolution de la moyenne des scores des individus}" << std::endl;
				monFlux << "\\end{figure}" << std::endl;
				monFlux << "\\begin{figure}[h]" << std::endl;
				monFlux << "\\\\\\\\\\begin{tikzpicture}" << std::endl;
				monFlux << "\\begin{axis}[xlabel=Numéro génération ,ylabel=Meilleur individu,axis x line=bottom ,axis y line=left]" << std::endl;
				monFlux << "\\addplot coordinates {" << std::endl;
				if ((individus)->at(0).ADN.getTypeGenes() == 1)
					for (int i=0; i < meilleur_individu.size();i++){
						monFlux << "(" << i << "," << meilleur_individu.at(i) <<") ";
					}
				else if ((individus)->at(0).ADN.getTypeGenes() == 2)
					for (int i=0; i < meilleur_individu_flottant.size();i++){
						monFlux << "(" << i << "," << meilleur_individu_flottant.at(i) <<") ";
					}
				else if ((individus)->at(0).ADN.getTypeGenes() == 3)
					for (int i=0; i < meilleur_individu.size();i++){
							monFlux << "(" << i << "," << (individus)->at(0).convertionVersDecimale(meilleur_individu.at(i)) <<") ";
					}
				monFlux << "};" << std::endl;
				monFlux << "\\end{axis}" << std::endl;
				monFlux << "\\end{tikzpicture}" << std::endl;
				monFlux << "\\caption{Graphe représentant l'évolution des meilleur individus}" << std::endl;
				monFlux << "\\end{figure}" << std::endl;
				monFlux << "\\end{document}" << std::endl;
		
	}
	else {
		std::cout << "ERREUR: Impossible d'ouvrir le fichier." << std::endl;
	}
}

	std::string EntreesSorties::getChaineEvaluation(){
		return chaine_evaluation;
	}
	int EntreesSorties::getTaillePopulation(){
		return  taille_population;
	}
	int EntreesSorties::getNombreiterations(){
		return nombre_iterations;
	}
	int EntreesSorties::getNmbr_indiv_a_selec(){
		return nmbr_indiv_a_selec;
	}
	int EntreesSorties::getChoixSelection(){
		return choix_selection;
	}
	int EntreesSorties::getNombreGenes(){
		return nombre_genes;
	}
	float EntreesSorties::getTauxCroisement(){
		return taux_croisement;
	}
	float EntreesSorties::getTauxMutation(){
		return taux_mutation;
	}
	int EntreesSorties::getGenerationSatisfaisante(){
		return generation_satisfaisante;
	}
		double EntreesSorties::getGenerationSatisfaisanteFlottant(){
		return generation_satisfaisante_flottant;
	}
	int EntreesSorties::getTypeGenes(){
		return type_genes;
	}
	int EntreesSorties::getMinIntervalle(){
		return min_intervalle;
	}
	int EntreesSorties::getMaxIntervalle(){
		return max_intervalle;
	}
	
	void EntreesSorties::setChaineEvaluation(std::string chaine_evaluation){
		this->chaine_evaluation = chaine_evaluation;
	}
	void EntreesSorties::setTaillePopulation(int taille_population){
		this->taille_population = taille_population;
	}
	void EntreesSorties::setNombreiterations(int nombre_iterations){
		this->nombre_iterations = nombre_iterations;
	}
	void EntreesSorties::setNmbr_indiv_a_selec(int nmbr_indiv_a_selec){
		this->nmbr_indiv_a_selec = nmbr_indiv_a_selec;
	}
	void EntreesSorties::setChoixSelection(int choix_selection){
		this->choix_selection = choix_selection;
	}
	void EntreesSorties::setNombreGenes(int nombre_genes){
		this->nombre_genes = nombre_genes;
	}
	void EntreesSorties::setTauxCroisement(float taux_croisement){
		this->taux_croisement = taux_croisement;
	}
	void EntreesSorties::setTauxMutation(float taux_mutation){
		this->taux_mutation = taux_mutation;
	}
	void EntreesSorties::setGenerationSatisfaisante(int generation_satisfaisante){
		this->generation_satisfaisante = generation_satisfaisante;
	}
		void EntreesSorties::setGenerationSatisfaisanteFlottant(double generation_satisfaisante){
		this->generation_satisfaisante_flottant = generation_satisfaisante;
	}
	void EntreesSorties::setTypeGenes(int type_genes){
		this->type_genes = type_genes;
	}
	void EntreesSorties::setMinIntervalle(int min_intervalle){
		this-> min_intervalle = min_intervalle;
	}
	void EntreesSorties::setMaxIntervalle(int max_intervalle){
		max_intervalle = max_intervalle;
	}
	double EntreesSorties::getMinIntervalleFlottant(){
		return min_intervalle_flottant;
	}
	double EntreesSorties::getMaxIntervalleFlottant(){
		return max_intervalle_flottant;
		
	}
	void EntreesSorties::setMinIntervalleFlottant(double min_intervalle){
		min_intervalle_flottant = min_intervalle;
	}
	void EntreesSorties::setMaxIntervalleFlottant(double max_intervalle){
		max_intervalle_flottant = max_intervalle;
	}
	std::vector<int> EntreesSorties::getNoteMoyenne(){
		return note_moyenne;
	}
	std::vector<double> EntreesSorties::getNoteMoyenneFlottant(){
		return note_moyenne_flottant;
	}
    void EntreesSorties::setNoteMoyenne(std::vector<int> note_total){
		for (int i = 0; i<note_total.size(); i++)
			this->note_moyenne.push_back(note_total[i]);
	}
	void EntreesSorties::setNoteMoyenneFlottant(std::vector<double> note_total_flottant){
		for (int i = 0; i<note_total_flottant.size(); i++)
			this->note_moyenne_flottant.push_back(note_total_flottant[i]);
	}
	std::vector<int> EntreesSorties::getMeilleurIndividu(){
		return meilleur_individu;
	}
	std::vector<double> EntreesSorties::getMeilleurIndividuFlottant(){
		return meilleur_individu_flottant;
	}
	void EntreesSorties::setMeilleurIndividu(std::vector<int> meilleur_individu){
		for (int i = 0; i<meilleur_individu.size(); i++)
			this->meilleur_individu.push_back(meilleur_individu[i]);
	}
	void EntreesSorties::setMeilleurIndividuFlottant(std::vector<double> meilleur_individu_flottant){
		for (int i = 0; i<meilleur_individu_flottant.size(); i++)
			this->meilleur_individu_flottant.push_back(meilleur_individu_flottant[i]);
	}
	int EntreesSorties::getMaximisationMinimisation(){
		return this->maximisation_minimisation;
	}
	void EntreesSorties::setMaximisationMinimisation(int maximisation_minimisation){
		this->maximisation_minimisation = maximisation_minimisation;
	}
