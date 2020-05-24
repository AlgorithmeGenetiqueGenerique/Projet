#include "operationsgenetiques.h"

operationsGenetiques::operationsGenetiques(std::vector<individu>* individus, int maximisation_minimisation, int nmbr_indiv_a_selec){
	this->individus = individus; 
	this->maximisation_minimisation = maximisation_minimisation;
	this->nmbr_indiv_a_selec = nmbr_indiv_a_selec;
}

void operationsGenetiques::selectionParRang(){
    int taille_population = individus->size();
    triFusion(0, taille_population-1);

    for (int i = taille_population-1; i>=nmbr_indiv_a_selec ; i--)
    {
        individus->erase(individus->begin() + i);
    }
}

void operationsGenetiques::selectionParRoulette()
{
	std::vector<individu> intermediaire;
	if ((individus->at(0).ADN.getTypeGenes() == 1) || (individus->at(0).ADN.getTypeGenes() == 3)){
	int nombre_aleatoire;
	if (maximisation_minimisation == 1){
	for (int i = 0; i< nmbr_indiv_a_selec; i++)
	{
		nombre_aleatoire = individus->at(0).valeurAleatoire(0,calculeNoteTotal());
		configurationIntervalles();
		for (int j = 0; j< individus->size(); j++)
        {
			 if((nombre_aleatoire >= (*individus)[j].getDebutItervalle()) && (nombre_aleatoire <(*individus)[j].getFinItervalle()))
                {
                    intermediaire.push_back((*individus)[j]);
					individus->erase(individus->begin() + j);
				}
		}
	}}
	else if (maximisation_minimisation == 2){
	for (int i = 0; i< nmbr_indiv_a_selec; i++)
	{	
		nombre_aleatoire = individus->at(0).valeurAleatoire(0,calculeNoteTotal());
		configurationIntervalles();
				triFusion(0, individus->size()-1);
			int j = individus->size();
			j--;
			individu inter = individu();
			for(int i= 0; i< individus->size()/2; i++){
					inter.setDebutIntervalle((*individus)[i].getDebutItervalle());
					inter.setFinIntervalle((*individus)[i].getFinItervalle());
					(*individus)[i].setDebutIntervalle((*individus)[j].getDebutItervalle());
					(*individus)[i].setFinIntervalle((*individus)[j].getFinItervalle());
					(*individus)[j].setDebutIntervalle(inter.getDebutItervalle());
					(*individus)[j].setFinIntervalle(inter.getFinItervalle());
					j--;
				}
		for (int j = 0; j< individus->size(); j++)
        {
			 if((nombre_aleatoire >= (*individus)[j].getDebutItervalle()) && (nombre_aleatoire <(*individus)[j].getFinItervalle()))
                {
                    intermediaire.push_back((*individus)[j]);
					individus->erase(individus->begin() + j);
				}
		}
	}
}
	}
	else if (individus->at(0).ADN.getTypeGenes() == 2){
	double nombre_aleatoire;
	if (maximisation_minimisation == 1){
	for (int i = 0; i< nmbr_indiv_a_selec; i++)
	{
		nombre_aleatoire = individus->at(0).valeurAleatoire(0.0,calculeNoteTotalFlottant());
		configurationIntervalles();
		for (int j = 0; j< individus->size(); j++)
        {
			 if((nombre_aleatoire >= (*individus)[j].getDebutIntervalleFlottant()) && (nombre_aleatoire <(*individus)[j].getFinIntervalleFlottant()))
                {
                    intermediaire.push_back((*individus)[j]);
					individus->erase(individus->begin() + j);
				}
		}
	}}
		else if (maximisation_minimisation == 2){
	for (int i = 0; i< nmbr_indiv_a_selec; i++)
	{	
		nombre_aleatoire = individus->at(0).valeurAleatoire(0.0,calculeNoteTotalFlottant());
		configurationIntervalles();
				triFusion(0, individus->size()-1);
			int j = individus->size();
			j--;
			individu inter = individu();
			for(int i= 0; i< individus->size()/2; i++){
					inter.setDebutIntervalleFlottant((*individus)[i].getDebutIntervalleFlottant());
					inter.setFinIntervalleFlottant((*individus)[i].getFinIntervalleFlottant());
					(*individus)[i].setDebutIntervalleFlottant((*individus)[j].getDebutIntervalleFlottant());
					(*individus)[i].setFinIntervalleFlottant((*individus)[j].getFinIntervalleFlottant());
					(*individus)[j].setDebutIntervalleFlottant(inter.getDebutIntervalleFlottant());
					(*individus)[j].setFinIntervalleFlottant(inter.getFinIntervalleFlottant());
					j--;
				}
		for (int j = 0; j< individus->size(); j++)
        {
			 if((nombre_aleatoire >= (*individus)[j].getDebutIntervalleFlottant()) && (nombre_aleatoire <(*individus)[j].getFinIntervalleFlottant()))
                {
                    intermediaire.push_back((*individus)[j]);
					individus->erase(individus->begin() + j);
				}
		}
	}
}
	}
(*individus).clear();
	 for (int i=0;i< intermediaire.size();i++)
		(*individus).push_back(intermediaire.at(i));
		intermediaire.clear();
}

void operationsGenetiques::configurationIntervalles(){
	if ((individus->at(0).ADN.getTypeGenes() == 1) || (individus->at(0).ADN.getTypeGenes() == 3)){
		for (int i = 0; i< individus->size(); i++)
		{
			if(i==0){(*individus)[i].setDebutIntervalle(0);} else {(*individus)[i].setDebutIntervalle((*individus)[i-1].getFinItervalle());}
			if(i == (individus->size() - 1)){(*individus)[i].setFinIntervalle(calculeNoteTotalFlottant());} else { (*individus)[i].setFinIntervalle(((*individus)[i].getDebutItervalle()) + ((*individus)[i].getNoteEvaluation()));}
		}
	}
	else if (individus->at(0).ADN.getTypeGenes() == 2){
		for (int i = 0; i< individus->size(); i++)
		{
			if(i==0){(*individus)[i].setDebutIntervalleFlottant(0.0);} else {(*individus)[i].setDebutIntervalleFlottant((*individus)[i-1].getFinIntervalleFlottant());}
			if(i == (individus->size() - 1)){(*individus)[i].setFinIntervalleFlottant(calculeNoteTotalFlottant());} else { (*individus)[i].setFinIntervalleFlottant(((*individus)[i].getDebutIntervalleFlottant()) + ((*individus)[i].getNoteEvaluationFlottant()));}
		}
	}
}

double operationsGenetiques::calculeNoteTotalFlottant()
{
	double score_total =0.0;
	int taille_population = individus->size();
		for (int i = 0; i< taille_population; i++)
		{
			score_total = score_total+(*individus)[i].getNoteEvaluationFlottant();
		}
		return score_total;
}

int operationsGenetiques::calculeNoteTotal()
{
	int score_total =0;
	int taille_population = individus->size();
		for (int i = 0; i< taille_population; i++)
		{
			score_total = score_total+(*individus)[i].getNoteEvaluation();
		}
		return score_total;
}

void operationsGenetiques::selectionParTournoi(){
	int indice_aleatoire, taille_population;
	std::vector<individu> intermediaire;
	if ((individus->at(0).ADN.getTypeGenes() == 1) || (individus->at(0).ADN.getTypeGenes() == 3)){
	individu individu_1 = individu (individus->at(0).ADN.getMinIntervalle(), individus->at(0).ADN.getMaxIntervalle(), individus->at(0).ADN.getNombreGenes(), individus->at(0).ADN.getTypeGenes());
	individu individu_2 = individu (individus->at(0).ADN.getMinIntervalle(), individus->at(0).ADN.getMaxIntervalle(), individus->at(0).ADN.getNombreGenes(), individus->at(0).ADN.getTypeGenes());
	taille_population = individus->size();
	for (int i = 0; i< nmbr_indiv_a_selec; i++){
		indice_aleatoire = rand() % individus->size();
		individu_1 = (*individus)[indice_aleatoire];
		indice_aleatoire = rand() % individus->size();
		individu_2 = (*individus)[indice_aleatoire];
		if (this->maximisation_minimisation == 1){
			if(individu_1.getNoteEvaluation() > individu_2.getNoteEvaluation()){
				intermediaire.push_back(individu_1);
			}
			else {
				intermediaire.push_back(individu_2);
			}
		}
		if (this->maximisation_minimisation == 2){
			if(individu_1.getNoteEvaluation() < individu_2.getNoteEvaluation()){
				intermediaire.push_back(individu_1);
			}
			else {
				intermediaire.push_back(individu_2);
			}
		}
	}
	}
	else if (individus->at(0).ADN.getTypeGenes() == 2){ 
	individu individu_1 = individu (individus->at(0).ADN.getMinIntervalleFlottant(), individus->at(0).ADN.getMaxIntervalleFlottant(), individus->at(0).ADN.getNombreGenes(), individus->at(0).ADN.getTypeGenes());
	individu individu_2 = individu (individus->at(0).ADN.getMinIntervalleFlottant(), individus->at(0).ADN.getMaxIntervalleFlottant(), individus->at(0).ADN.getNombreGenes(), individus->at(0).ADN.getTypeGenes());
	taille_population = individus->size();
	for (int i = 0; i< nmbr_indiv_a_selec; i++){
		indice_aleatoire = rand() % individus->size();
		individu_1 = (*individus)[indice_aleatoire];
		indice_aleatoire = rand() % individus->size();
		individu_2 = (*individus)[indice_aleatoire];
		if (this->maximisation_minimisation == 1){
			if(individu_1.getNoteEvaluationFlottant() > individu_2.getNoteEvaluationFlottant()){
				intermediaire.push_back(individu_1);
			}
			else {
				intermediaire.push_back(individu_2);
			}
		}
		if (this->maximisation_minimisation == 2){
			if(individu_1.getNoteEvaluationFlottant() < individu_2.getNoteEvaluationFlottant()){
				intermediaire.push_back(individu_1);
			}
			else {
				intermediaire.push_back(individu_2);
			}
		}
	}
	}
	(*individus).clear();
	 for (int i=0;i< intermediaire.size();i++)
		(*individus).push_back(intermediaire.at(i));
		intermediaire.clear();
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
		if (x < taux_mutation*100) {
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
		if (x < taux_mutation*100) {
			mutation(&individu_x, taux_mutation);
			}
		individus->push_back(individu_x);
		individus->push_back(individu_y);
		}
	}
}

void operationsGenetiques::mutation(individu* individu_x, float taux_mutation){
		for (int i =0; i<individu_x->ADN.getNombreGenes(); i++){
				if (individu_x->ADN.getTypeGenes() == 1)
				individu_x->ADN.genes_int.at(i) =  rand()%(individu_x->ADN.getMaxIntervalle() - individu_x->ADN.getMinIntervalle()) + individu_x->ADN.getMinIntervalle();
			else if (individu_x->ADN.getTypeGenes() == 2)
			individu_x->ADN.genes_double.at(i) =  fmod((double)rand(),(individu_x->ADN.getMaxIntervalleFlottant() - individu_x->ADN.getMinIntervalleFlottant()));
		else if (individu_x->ADN.getTypeGenes() == 3){
		individu_x->ADN.genes_int.at(i) =  individu_x->conversionVersBinaire(rand()%(individu_x->convertionVersDecimale(individu_x->ADN.getMaxIntervalle()) - individu_x->convertionVersDecimale(individu_x->ADN.getMinIntervalle())) + individu_x->convertionVersDecimale(individu_x->ADN.getMinIntervalle()));

		}
		
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
