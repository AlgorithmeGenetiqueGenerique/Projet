#include "operations_genetiques.h"
#include <iostream>

operationsGenetiques::operationsGenetiques(std::vector<individu>* individus, int maximisation_minimisation, int nmbr_indiv_a_selec){
	this->individus = individus; 
	this->maximisation_minimisation = maximisation_minimisation;
	this->nmbr_indiv_a_selec = nmbr_indiv_a_selec;
}

void operationsGenetiques::selectionParRang(){
	int taille_population = individus->size();
	triFusion(0, taille_population-1);
	for (int i = nmbr_indiv_a_selec; i< taille_population ; i++)
	individus->erase(individus->begin() + i);
}

void operationsGenetiques::triFusion(int debut, int fin){
    int milieu;
  if (debut < fin) {
    milieu = (debut+fin)/2;
    triFusion(debut,milieu);
    triFusion(milieu+1,fin);
    Fusion(debut,milieu,fin);
  }
}

void operationsGenetiques::Fusion(int debut, int milieu, int fin){
  int P=debut, D=milieu+1;
  std::vector<individu> aux;

  if (this->maximisation_minimisation == 1){
	if ((individus->at(0).ADN.getTypeGenes()) == 1 || (individus->at(0).ADN.getTypeGenes() == 3)){
       while ((P <= milieu) && (D <= fin)){
    
    if ((*individus)[P].getNoteEvaluation() > (*individus)[D].getNoteEvaluation()) {
      aux.push_back((*individus)[P]);
      P++;
    }
    else {
      aux.push_back((*individus)[D]);
      D++;
    }
  }
  
    if (P > milieu) {
    while (D<=fin) {
      aux.push_back((*individus)[D]);
      D++;
    }
  }
  else {
    while (P<=milieu) {
      aux.push_back((*individus)[P]);
      P++;
    }
  }
	}
	else if (individus->at(0).ADN.getTypeGenes() == 2){
		 while ((P <= milieu) && (D <= fin)){
			 
    if ((*individus)[P].getNoteEvaluationFlottant() > (*individus)[D].getNoteEvaluationFlottant()) {
      aux.push_back((*individus)[P]);
      P++;
    }
    else {
      aux.push_back((*individus)[D]);
      D++;
    }
  }
    if (P > milieu) {
    while (D<=fin) {
      aux.push_back((*individus)[D]);
      D++;
    }
  }
  else {
    while (P<=milieu) {
      aux.push_back((*individus)[P]);
      P++;
    }
  }
		
	}
	}
	else if (this->maximisation_minimisation == 2){
			if ((individus->at(0).ADN.getTypeGenes()) == 1 || (individus->at(0).ADN.getTypeGenes() == 3)){
       while ((P <= milieu) && (D <= fin)){
    
    if ((*individus)[P].getNoteEvaluation() < (*individus)[D].getNoteEvaluation()) {
      aux.push_back((*individus)[P]);
      P++;
    }
    else {
      aux.push_back((*individus)[D]);
      D++;
    }
  }
    if (P > milieu) {
    while (D<=fin) {
      aux.push_back((*individus)[D]);
      D++;
    }
  }
  else {
    while (P<=milieu) {
      aux.push_back((*individus)[P]);
      P++;
    }
  }
	}
	else if (individus->at(0).ADN.getTypeGenes() == 2){
		 while ((P <= milieu) && (D <= fin)){
			 
    if ((*individus)[P].getNoteEvaluationFlottant() < (*individus)[D].getNoteEvaluationFlottant()) {
      aux.push_back((*individus)[P]);
      P++;
    }
    else {
      aux.push_back((*individus)[D]);
      D++;
    }
  }
    if (P > milieu) {
    while (D<=fin) {
      aux.push_back((*individus)[D]);
      D++;
    }
  }
  else {
    while (P<=milieu) {
      aux.push_back((*individus)[P]);
      P++;
    }
  }	
	}
	}
  for (int i=debut;i<=fin;i++) {
   (*individus).at(i)=aux[i-debut];}
}

void operationsGenetiques::croisement(float taux_croisement, float taux_mutation, int taille_population, std::string chaine_evaluation){
	int taille_stable = individus->size() * taux_croisement;
	evaluation e = evaluation (chaine_evaluation);
		int i1, i2, x, y,j;
		if ((individus->at(0).ADN.getTypeGenes() == 1) || (individus->at(0).ADN.getTypeGenes() == 3)){
		individu individu_x_i = individu(individus->at(0).ADN.getMinIntervalle(),individus->at(0).ADN.getMaxIntervalle(), individus->at(0).ADN.getNombreGenes(), individus->at(0).ADN.getTypeGenes());
		individu individu_y_i = individu(individus->at(0).ADN.getMinIntervalle(),individus->at(0).ADN.getMaxIntervalle(), individus->at(0).ADN.getNombreGenes(), individus->at(0).ADN.getTypeGenes());
		for (int i=individus->size(); i<taille_population; i= i+2) {
		i1 = rand() % taille_stable;
		i2 = rand() % taille_stable;			
		 while (i1 == i2){
		i2 = rand() % taille_stable;
		}
		for (int k = 0; k< individus->at(0).ADN.getNombreGenes(); k++){
			if (k%2){
		individu_x_i.ADN.setGenes((*individus)[i1].ADN.genes_int[k]);
		individu_y_i.ADN.setGenes((*individus)[i2].ADN.genes_int[k]);
		}else {
			individu_x_i.ADN.setGenes((*individus)[i2].ADN.genes_int[k]);
		individu_y_i.ADN.setGenes((*individus)[i1].ADN.genes_int[k]);
			}
      	}
      	evaluation e = evaluation (chaine_evaluation);
      	e.evaluer(&individu_x_i);
      	evaluation e1 = evaluation (chaine_evaluation);
      	e1.evaluer(&individu_y_i);
		y =0;
		x = rand() %100;
		while(x == y)
		x = rand() %100;
		y = x;
		if (x < taux_mutation*100) {//calculer un nombre aleatoire entre individu x ou individu y...
			mutation(&individu_x_i, taux_mutation);
			}
		individus->push_back(individu_x_i);
		individus->push_back(individu_y_i);
		}
		}
		if (individus->at(0).ADN.getTypeGenes() == 2){
		individu individu_x = individu(individus->at(0).ADN.getMinIntervalleFlottant(),individus->at(0).ADN.getMaxIntervalleFlottant(), individus->at(0).ADN.getNombreGenes(), individus->at(0).ADN.getTypeGenes());
		individu individu_y = individu(individus->at(0).ADN.getMinIntervalleFlottant(),individus->at(0).ADN.getMaxIntervalleFlottant(), individus->at(0).ADN.getNombreGenes(), individus->at(0).ADN.getTypeGenes());
		for (int i=individus->size(); i<taille_population; i= i+2) {
		i1 = rand() % taille_stable;
		i2 = rand() % taille_stable;			
		 while (i1 == i2){
		i2 = rand() % taille_stable;
		}
		for (int k = 0; k< individus->at(0).ADN.getNombreGenes(); k++){
			if (k%2){
		individu_x.ADN.setGenes((*individus)[i1].ADN.genes_double[k]);
		individu_y.ADN.setGenes((*individus)[i2].ADN.genes_double[k]);
		}else {
			individu_x.ADN.setGenes((*individus)[i2].ADN.genes_double[k]);
		individu_y.ADN.setGenes((*individus)[i1].ADN.genes_double[k]);
			}
      	}
      	evaluation e = evaluation (chaine_evaluation);
      	e.evaluer(&individu_x);
      	evaluation e1 = evaluation (chaine_evaluation);
      	e1.evaluer(&individu_y);
      	
		y =0;
		x = rand() %100;
		while(x == y)
		x = rand() %100;
		y = x;
		if (x < taux_mutation*100) {//calculer un nombre aleatoire entre individu x ou individu y...
			mutation(&individu_x, taux_mutation);
			}
		individus->push_back(individu_x);
		individus->push_back(individu_y);
		}
	}
}

void operationsGenetiques::mutation(individu* individu_x, float taux_mutation){
		for (int i =0; i<individu_x->ADN.getNombreGenes(); i++){
				if (individu_x->ADN.getTypeGenes() == 1 || individu_x->ADN.getTypeGenes() == 3 )
				individu_x->ADN.genes_int.at(i) =  rand()%(individu_x->ADN.getMaxIntervalle() - individu_x->ADN.getMinIntervalle()) + individu_x->ADN.getMinIntervalle();
			else if (individu_x->ADN.getTypeGenes() == 2)
			individu_x->ADN.genes_double.at(i) =  fmod((double)rand(),(individu_x->ADN.getMaxIntervalleFlottant() - individu_x->ADN.getMinIntervalleFlottant()));
		}
}

int operationsGenetiques::getMaximisationMinimisation(){
	return this->maximisation_minimisation;
}
void operationsGenetiques::setMaximisationMinimisation(int maximisation_minimisation){
	this->maximisation_minimisation = maximisation_minimisation;
}

int operationsGenetiques::getNmbr_indiv_a_selec(){
	return this->nmbr_indiv_a_selec;
}	
void operationsGenetiques::setNmbr_indiv_a_selec(int nmbr_indiv_a_selec){
	this->nmbr_indiv_a_selec = nmbr_indiv_a_selec;
}
