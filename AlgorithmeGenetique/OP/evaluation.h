#ifndef EVALUATION_H
#define EVALUATION_H

#include <vector>
#include <string>
#include <math.h>
#include <cstdlib>
#include "individu.h"
#include <iostream>

#define MAXIMUM 20 
#define PI 3.14159265359

class evaluation{
	
	public : 
	
	 evaluation(std::string chaine_evaluation);
	 void evaluer(individu* individu_x);
     bool testArret(int note_totale, int generation_satisfaisante, int maximisation_minimisation);
     bool testArret(double note_totale, double generation_satisfaisante, int maximisation_minimisation);
		 
	private :
	
	 void analyseSyntaxiqueTypes(individu* individu_x);
	 void analyseSyntaxique(individu* individu_x);
	 void identification(individu* individu_x);
	 void operations(individu* individu_x);
	 int operationsLogiques(int binaire_1, int binaire_2);
	 
	 int pileVide(int sommet_pile);
	 int pilePleine(int sommet_pile);
     void empiler(int valeur);
     int depiler();
     void empilerFlottants(double valeur);
     double depilerFlottants();
	
	
	std::string chaine_evaluation;
	char caractere;
	int indice;
	int sommet_pile;
	int noeud;
	int entier;
	double flottant;
	int pile_entiers[20];
	double pile_flottants[20];
	static const int GENE;
	static const int ENTIER;
	static const int ADDITION;
	static const int SOUSTRACTION;
	static const int MULTIPLICATION;
    static const int DIVISION;
    static const int PARENTHESE_O;
    static const int PARENTHESE_F;
    static const int PUISSANCE;
    static const int RACINE;
    static const int RACINEC;
    static const int MODULO;
    static const int V_ABSOLUE;
    static const int LOG_2;
    static const int LOG_10;
    static const int LN;
    static const int COSINUS;
    static const int COSINUSH;
    static const int ACOSINUS;
    static const int SINUS;
    static const int SINUSH;
    static const int ASINUS;
    static const int TANGENTE;
    static const int TANGENTEH;
    static const int ATANGENTE;
    static const int DOUBLE;
    static const int CEIL;
    static const int FLOOR;
    static const int EXPONENTIELLE;
    static const int AND;
    static const int OR;
    static const int NOR;
    static const int NOT;
    static const int XOR;
    static const int NAND;
	static const int FIN;
	
};
#endif
