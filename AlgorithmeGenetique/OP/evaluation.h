#ifndef EVALUATION_H
#define EVALUATION_H

#include <vector>
#include <string>
#include <math.h>
#include <cstdlib>
#include "individu.h"

//Maximum élément que contiendra une pile
#define MAXIMUM 20 
//constante d’Archimède
#define PI 3.14159265359

class evaluation{
	
	public : 
     //Constructeur de la classe qui prend en paramètre l'équation d'évaluation
	 evaluation(std::string chaine_evaluation);
     //Méthode appelé pour évaluer un individu
	 void evaluer(individu* individu_x);
     // Méthode appelée pour vérifier si la génération est satisfaisante dans le cas où les gènes sont entiers ou binaires
     bool testArret(int note_totale, int generation_satisfaisante, int maximisation_minimisation);
     // Méthode appelée pour vérifier si la génération est satisfaisante dans le cas où les gènes sont flottants
     bool testArret(double note_totale, double generation_satisfaisante, int maximisation_minimisation);
     //Accésseur de l'attribut erreur
     int getErreur();
		 
	private :
     //Cette méthode analyse syntaxiquement l’équation et récupére les entiers ou les ﬂottants si ils y ﬁgurent
	 void analyseSyntaxiqueTypes(individu* individu_x);
     //Cette méthode permet d’identiﬁer les types des éléments de l’équation de les aﬀectés dans l’attribut noeud
	 void analyseSyntaxique(individu* individu_x);
     //Méthode qui vériﬁe si le noeud actuel est un gène, un entier, un ﬂottant ou une parenthése ouvrante ou bien un operateur unaire
	 void identification(individu* individu_x);
     //Vériﬁe si c’est une opération binaire et fait le traitement nécessaire
	 void operations(individu* individu_x);
     //Exécute les opérations logiques (AND, OR, XOR, NAND, NOR, NOT)
	 int operationsLogiques(int binaire_1, int binaire_2);
	 
     // Elle met notre pile à vide à travers l’attribut sommet_pile
	 int pileVide(int sommet_pile);
     //Veriﬁe si la pile est pleine
	 int pilePleine(int sommet_pile);
     //Ajouter un élément au sommet de la pile d’entier
     void empiler(int valeur);
     //Retourner l’élément au sommet de la pile d’entiers et le supprimer de cette dernière
     int depiler();
     //Ajouter un élément au sommet de la pile de ﬂottant
     void empilerFlottants(double valeur);
     //Retourner l’élément au sommet de la pile de ﬂottant et le supprimer de cette dernièr
     double depilerFlottants();
	
    //Attribut stockant un entier indiquant un type d'erreur
    int erreur;
    //contient l’équation que l’utilisateur aura entrée
	std::string chaine_evaluation;
    //porte le caractère actue
	char caractere;
    //représente l’indice du caractère actuel sur la chaine de caractère qui contient l’équation
	int indice;
    //indice du sommet de la pile
	int sommet_pile;
    //il représente un élément (Une opération, Un gène, la ﬁn de l’équation...)
	int noeud;
    //utilisé lorsque l’élément actuelle est un géne ou un entier relatif
	int entier;
    //utilisé lorsque l’élément actuelle est un géne ou un ﬂottan
	double flottant;
    //utilisé pour l’analyse et l’interprétation de l’équation dans le cas où les gènes sont de type entiers ou binaire
    int pile_entiers[MAXIMUM];
    // utilisé pour l’analyse et l’interprétation de l’équation dans le cas où les gènes sont de type flottant
    double pile_flottants[MAXIMUM];
    //identiﬁant d’un noeud "gène
	static const int GENE;
    //identiﬁant d’un noeud "entier"
	static const int ENTIER;
    //identiﬁant de l’opération d’addition
	static const int ADDITION;
    //identiﬁant de l’opération de soustraction
	static const int SOUSTRACTION;
    //identiﬁant de l’opération de multiplication
	static const int MULTIPLICATION;
    //identiﬁant de l’opération de division
    static const int DIVISION;
    //identiﬁant de la parenthèse ouvrante
    static const int PARENTHESE_O;
    //identiﬁant de la parenthèse fermante
    static const int PARENTHESE_F;
    //identiﬁant de l’opération de puissance
    static const int PUISSANCE;
    //identiﬁant de l’opération racine carrée
    static const int RACINE;
    //identiﬁant de l’opération racine cubique
    static const int RACINEC;
    //identiﬁant de l’opération modulo
    static const int MODULO;
    //identiﬁant de l’opération valeur absolue
    static const int V_ABSOLUE;
    //identiﬁant de l’opération logarithme de base 2
    static const int LOG_2;
    //identiﬁant de l’opération logarithme de base 10
    static const int LOG_10;
    //identiﬁant de l’opération logarithme naturel
    static const int LN;
    //identiﬁant de l’opération cosinu
    static const int COSINUS;
    //identiﬁant de l’opération cosinus hyperbolique
    static const int COSINUSH;
    //identiﬁant de l’opération arc cosinus
    static const int ACOSINUS;
    //identiﬁant de l’opération sinus
    static const int SINUS;
    //identiﬁant de l’opération sinus hyperbolique
    static const int SINUSH;
    //identiﬁant de l’opération arc sinus
    static const int ASINUS;
    //identiﬁant de l’opération tangent
    static const int TANGENTE;
    //identiﬁant de l’opération tangente hyperbolique
    static const int TANGENTEH;
    //identiﬁant de l’opération arc tangente
    static const int ATANGENTE;
    //identiﬁant d’un noeud "ﬂottant"
    static const int DOUBLE;
    //identiﬁant de l’opération nombre entier supérieur le plus proche
    static const int CEIL;
    //identiﬁant de l’opération nombre entier inférieur le plus proche
    static const int FLOOR;
    //identiﬁant de l’opération exponentielle
    static const int EXPONENTIELLE;
    //identiﬁant de l’opération du ET logique
    static const int AND;
    //identiﬁant de l’opération du OU logique
    static const int OR;
    //identiﬁant de l’opération NONOU
    static const int NOR;
    //identiﬁant de l’opération négation logiqu
    static const int NOT;
    //identiﬁant de l’opération ou éxclusif
    static const int XOR;
    //identiﬁant de l’opération NONET
    static const int NAND;
    //identiﬁant de la ﬁn de l’équatio
	static const int FIN;
	
};
#endif
