#include "individu.h"
#include <iostream>
individu::individu(){
	ADN = gene();
}

individu::individu(int min_intervalle, int max_intervalle, int nombre_genes, int type_genes){
	note_evaluation = 0;
	ADN = gene(type_genes, min_intervalle, max_intervalle, nombre_genes);
	if (type_genes == 1){
		for (int i =0; i<nombre_genes; i++)
			this->ADN.setGenes(valeurAleatoire(min_intervalle,max_intervalle));
	}
	else if (type_genes == 3){
		int min_entier = convertionVersDecimale(min_intervalle);
		int max_entier = convertionVersDecimale(max_intervalle);
		for (int i =0; i<nombre_genes; i++)
			this->ADN.setGenes(conversionVersBinaire(valeurAleatoire(min_entier,max_entier)));
	}
}

individu::individu(double min_intervalle, double max_intervalle, int nombre_genes, int type_genes){
	note_evaluation = 0;
	ADN = gene(type_genes, min_intervalle, max_intervalle, nombre_genes);
	for (int i =0; i<nombre_genes; i++)
	this->ADN.setGenes(valeurAleatoire(min_intervalle,max_intervalle));
}


int individu::valeurAleatoire(int min_intervalle, int max_intervalle)
{
    return rand()%(max_intervalle - min_intervalle) + min_intervalle;
}

double individu::valeurAleatoire(double min_intervalle, double max_intervalle)
{
    return fmod((double)rand(),(max_intervalle - min_intervalle));
}

void individu::setNoteEvaluation(int note_evaluation){
	this->note_evaluation = note_evaluation;
}

int individu::getNoteEvaluation(){
	return note_evaluation;
}

void individu::setNoteEvaluationFlottant(double note_evaluation_double){
	this->note_evaluation_flottant = note_evaluation_double;
}
double individu::getNoteEvaluationFlottant(){
	return note_evaluation_flottant;
}

void individu::setDebutIntervalleFlottant(double valeur){
	debut_intervalle_flottant = valeur; 
}
void individu::setFinIntervalleFlottant(double valeur){
	fin_intervalle_flottant = valeur;
}

double individu::getDebutIntervalleFlottant(){
	return debut_intervalle_flottant;
}

double individu::getFinIntervalleFlottant(){
	return fin_intervalle_flottant;
}

int individu::convertionVersDecimale(int binaire) 
{ 
    int decimale = 0; 
    int base = 1; 
    while (binaire) { 
        int dernier_chiffre = binaire% 10; 
        binaire = binaire / 10; 
        decimale += dernier_chiffre * base; 
        base = base * 2; 
    } 
    return decimale; 
} 

int individu::conversionVersBinaire(int N) 
{ 
  
    // To store the binary number 
    unsigned long long int B_Number = 0; 
    int cnt = 0; 
    while (N != 0) { 
        int rem = N % 2; 
       unsigned long long int  c = pow(10, cnt); 
        B_Number += rem * c; 
        N /= 2; 
  
        // Count used to store exponent value 
        cnt++; 
    } 
  
    return B_Number; 
}

int individu::getDebutItervalle(){
	return debut_intervalle;
}
int individu::getFinItervalle(){
	return fin_intervalle;
}
void individu::setDebutIntervalle(int debut_intervalle){
	this->debut_intervalle = debut_intervalle;
}
void individu::setFinIntervalle(int fin_intervalle){
	this->fin_intervalle = fin_intervalle;
}
