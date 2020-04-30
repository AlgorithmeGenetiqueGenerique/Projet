#include "evaluation.h"
#include <iostream>

const int evaluation::GENE = 1;
const int evaluation::ADDITION = 2;
const int evaluation::SOUSTRACTION = 3;
const int evaluation::MULTIPLICATION = 4;
const int evaluation::DIVISION = 5;
const int evaluation::PARENTHESE_O = 6;
const int evaluation::PARENTHESE_F = 7;
const int evaluation::PUISSANCE = 8;
const int evaluation::FIN = 9;
const int evaluation::ENTIER = 10;
const int evaluation::RACINE = 11;
const int evaluation::MODULO = 12;
const int evaluation::V_ABSOLUE = 13;
const int evaluation::LOG_2 = 14;
const int evaluation::DOUBLE = 15;
const int evaluation::AND = 16;
	
evaluation::evaluation(std::string chaine_evaluation){
	 this->chaine_evaluation = chaine_evaluation;
	 noeud= 0;
	 indice = 1;
	 entier = 0;
	 flottant = 0.0;
	 sommet_pile = -1;
	 caractere = chaine_evaluation[0];
}

void evaluation::evaluer(individu* individu_x){
	chaine_evaluation+='#';
	analyseSyntaxiqueTypes(individu_x);
	identification(individu_x);
	operations(individu_x);
	if (individu_x->ADN.getTypeGenes() == 1)
		individu_x->setNoteEvaluation(depiler());
	else if (individu_x->ADN.getTypeGenes() == 2)
		individu_x->setNoteEvaluationFlottant(depilerFlottants());
	else if (individu_x->ADN.getTypeGenes() == 3)
	individu_x->setNoteEvaluation(individu_x->conversionVersBinaire(depiler()));
	//std::cout <<"a : "<< individu_x->ADN.genes_double.at(0) << std::endl;
	//std::cout <<"b : "<< individu_x->ADN.genes_double.at(1) << std::endl;
	//std::cout << " = " <<individu_x->getNoteEvaluationFlottant()<< std::endl;
}

void evaluation::analyseSyntaxiqueTypes(individu* individu_x){
	int n = 0;
	bool apres_virgule = false;
	int cpt = 1;
	double virgule = 0.0;
	while( caractere ==' ' ) indice++;
	if (individu_x->ADN.getTypeGenes() == 1 || individu_x->ADN.getTypeGenes() == 3){
	entier =0;
		while( ('0' <= caractere)&&('9' >= caractere) )
	{
		n = 1;
		noeud = ENTIER;
		entier = (caractere - '0') + entier * 10;
		caractere = chaine_evaluation[indice++];
	}
	
	}//---------------------------------------------
	else if (individu_x->ADN.getTypeGenes() == 2){
		flottant = 0.0;
			while( ('0' <= caractere)&&('9' >= caractere) || ('.' == caractere))
		{	
			
			n = 2;
			noeud = DOUBLE;
			if ('.' == caractere){
				if (apres_virgule == false) apres_virgule = true;
				caractere = chaine_evaluation[indice++];
			}
			else {
			if (apres_virgule == false){
				flottant = (caractere - '0') + flottant * 10;
				caractere = chaine_evaluation[indice++];
			}
			else {
			virgule = (caractere - '0') + virgule * 10;
			cpt*= 10;
			caractere = chaine_evaluation[indice++];
			}
			}
		}
}
if (n == 2){
	 flottant = (double)flottant + ((double)virgule/(double)cpt);
}
		if (!n) analyseSyntaxique(individu_x);
}

void evaluation::analyseSyntaxique(individu* individu_x){
		int n = 0;
		int type_genes = individu_x->ADN.getTypeGenes();
		while( ('a' <= caractere)&&('d' >= caractere) ){
		n = 1;
		noeud = GENE;
		switch(individu_x->ADN.getTypeGenes()){
		case 1 : {
		if (caractere == 'a')
			entier = individu_x->ADN.genes_int.at(0);
		else if (caractere == 'b')
			entier = individu_x->ADN.genes_int.at(1);
		else if (caractere == 'c')
			entier = individu_x->ADN.genes_int[2];
		else if (caractere == 'd')
			entier = individu_x->ADN.genes_int[3];
			break;
			}	
		case 2 : {
		if (caractere == 'a')
			flottant = individu_x->ADN.genes_double.at(0);
		else if (caractere == 'b')
			flottant = individu_x->ADN.genes_double.at(1);
		else if (caractere == 'c')
			flottant = individu_x->ADN.genes_double[2];
		else if (caractere == 'd')
			flottant = individu_x->ADN.genes_double[3];
			break;
			}
			case 3 : {
		if (caractere == 'a')
			entier = individu_x->ADN.genes_int.at(0);
		else if (caractere == 'b')
			entier = individu_x->ADN.genes_int.at(1);
		else if (caractere == 'c')
			entier = individu_x->ADN.genes_int[2];
		else if (caractere == 'd')
			entier = individu_x->ADN.genes_int[3];
			break;
			}	
		}
	caractere = chaine_evaluation[indice++];
	}  
	
	if(!n)
		switch(caractere)
	{
	case '+':{	
				caractere = chaine_evaluation[indice++];			
				noeud = ADDITION;
				break;
			 }
	case '-':{
				if (indice == 1){
							caractere = chaine_evaluation[indice++];
							while( ('0' <= caractere)&&('9' >= caractere) )
							{
								noeud = ENTIER;
								entier = (caractere - '0') + entier * 10;
								caractere = chaine_evaluation[indice++];
								n = 1;
							}
							entier *= -1;
				}else if (chaine_evaluation[indice-2] == '('){
					caractere = chaine_evaluation[indice++];
					while( ('0' <= caractere)&&('9' >= caractere) )
							{
								noeud = ENTIER;
								entier = (caractere - '0') + entier * 10;
								caractere = chaine_evaluation[indice++];
								n = 1;
							}
							entier *= -1;
				} else {
						noeud = SOUSTRACTION;
						caractere = chaine_evaluation[indice++];
				}
				break;
			 }
	case '*':{
				caractere = chaine_evaluation[indice++];
				noeud = MULTIPLICATION;
				break;
			 }
	case '/':{
				caractere = chaine_evaluation[indice++];
				noeud = DIVISION;
				break;
			 }
     case '&':{
				caractere = chaine_evaluation[indice++];
				noeud = AND;
				break;
			 }
	case '(':{
				caractere = chaine_evaluation[indice++];
				noeud = PARENTHESE_O;
				break;
			 }
	case ')':{
				caractere = chaine_evaluation[indice++];
				noeud = PARENTHESE_F;
				break;
			 }	
	case '#':{
			    caractere = chaine_evaluation[indice++];
				noeud = FIN;
				break;
			 }
	}
}

void evaluation::identification(individu* individu_x){
	switch(noeud)
	{
	case GENE :{
					if (individu_x->ADN.getTypeGenes() == 1)
					empiler(entier);
					else if (individu_x->ADN.getTypeGenes() == 2)
					empilerFlottants(flottant);
					else if (individu_x->ADN.getTypeGenes() == 3)
					empiler(individu_x->convertionVersDecimale(entier));
					analyseSyntaxiqueTypes(individu_x);
					break;
				  }
	case ENTIER :{
					if (individu_x->ADN.getTypeGenes() == 1)
					empiler(entier);
					else if (individu_x->ADN.getTypeGenes() == 3)
					empiler(individu_x->convertionVersDecimale(entier));
					analyseSyntaxiqueTypes(individu_x);
					break;
				  }
	case DOUBLE :{
					empilerFlottants(flottant);
					analyseSyntaxiqueTypes(individu_x);
					break;
				  }
	case PARENTHESE_O:{
					analyseSyntaxiqueTypes(individu_x);
					identification(individu_x);
					operations(individu_x);
					if( noeud == PARENTHESE_F )
						analyseSyntaxiqueTypes(individu_x);
					else
					{
						analyseSyntaxiqueTypes(individu_x);
						printf("Parenthese fermante manquante.\n");
					}
					break;
				  }
	default:{
				printf("Erreur dans identification.\n");
				break;
			}
	}
}

void evaluation::operations(individu* individu_x){
			int facteur_puissance = 0;
	int x = 0;
	double y = 0.0;
	switch(noeud)
	{
				case SOUSTRACTION :{
				 analyseSyntaxiqueTypes(individu_x);
				 identification(individu_x);
				 operations(individu_x);
				 if (individu_x->ADN.getTypeGenes() == 1){
					x = depiler();
					empiler((depiler()-x));
				 }
				 else {
					y = depilerFlottants(); 
					empilerFlottants((depilerFlottants()-y));
				 }
				 operations(individu_x);		 
				 break;
				 }
			case ADDITION :{
				int x,y;
				analyseSyntaxiqueTypes(individu_x);
				identification(individu_x);
				operations(individu_x);
				if (individu_x->ADN.getTypeGenes() == 1)
				empiler((depiler()+depiler()));
				else if (individu_x->ADN.getTypeGenes() == 2)
				empilerFlottants((depilerFlottants()+depilerFlottants()));
				else if (individu_x->ADN.getTypeGenes() == 3)
					empiler((depiler())+(depiler()));
				operations(individu_x);
				break;
				}
	case MULTIPLICATION:{
				analyseSyntaxiqueTypes(individu_x);
				identification(individu_x);
				if (individu_x->ADN.getTypeGenes() == 1)
				empiler((depiler()*depiler()) );
				else 
				empilerFlottants((depilerFlottants()*depilerFlottants()) );
				operations(individu_x);		
				break;
				}
	case DIVISION:{
				 analyseSyntaxiqueTypes(individu_x);
				 identification(individu_x);
				 if (individu_x->ADN.getTypeGenes() == 1){
					x = depiler();
					empiler(depiler()/x );
				 }
				 else {
					y = depilerFlottants();
					empilerFlottants(depilerFlottants()/y );
				 }
				 operations(individu_x);	 
				 break;
				 }
	case AND:{
				 if (individu_x->ADN.getTypeGenes() == 3){
					int x, y;
					analyseSyntaxiqueTypes(individu_x);
					identification(individu_x);
					x = individu_x->conversionVersBinaire(depiler());
					y = individu_x->conversionVersBinaire(depiler());
					x = individu_x->convertionVersDecimale(operationsLogiques(x, y));
					empiler(x);
					operations(individu_x);	
				 }	 
				 break;
				 }
	default: break;
	}
}

bool evaluation::testArret(int score_totale, int generation_satisfaisante, int maximisation){
	if (maximisation == 1){
		if (score_totale >= generation_satisfaisante) return true;
			else return false;
	}
	else if (maximisation == 2){
		if (score_totale <= generation_satisfaisante) return true;
			else return false;
	}
}
bool evaluation::testArret(double score_totale, double generation_satisfaisante, int maximisation){
	if (maximisation == 1){
		if (score_totale >= generation_satisfaisante) return true;
			else return false;
	}
	else if (maximisation == 2){
		if (score_totale <= generation_satisfaisante) return true;
			else return false;
	}
}
int evaluation::pileVide(int sommet_pile)
{
	if(sommet_pile == -1) return 1;
	return 0;
}

int evaluation::pilePleine(int sommet_pile)
{
	if(sommet_pile == MAXIMUM) return 1;
	return 0;
}

void evaluation::empiler(int elt)
{
	if(!pilePleine(sommet_pile))
	{
		if (sommet_pile == -1) sommet_pile=0;
		else sommet_pile = sommet_pile + 1;
		pile_entiers[sommet_pile] = elt;
	}
}

int evaluation::depiler()
{
	int elt = -1;
	if(!pileVide(sommet_pile))
	{
		elt = pile_entiers[sommet_pile];
		sommet_pile = sommet_pile - 1;
	}	
	return elt;
}
void evaluation::empilerFlottants(double elt)
{
	if(!pilePleine(sommet_pile))
	{
		if (sommet_pile == -1) sommet_pile=0;
		else sommet_pile = sommet_pile + 1;
		pile_flottants[sommet_pile] = elt;
	}
}

double evaluation::depilerFlottants()
{
	double elt = -1;
	if(!pileVide(sommet_pile))
	{
		elt = pile_flottants[sommet_pile];
		sommet_pile = sommet_pile - 1;
	}	
	return elt;
}

int evaluation::operationsLogiques(int binaire_1, int binaire_2){
	int taille_1 = std::to_string(binaire_1).length();
	int taille_2 = std::to_string(binaire_2).length();
	std::vector<int> x; 
	std::vector<int> y; 
	if (taille_1 > taille_2){
		int temp = taille_1;
		--temp;
		int midle = pow(10, temp);
		for (int i = 0; i< taille_1; i++){
			x.push_back((binaire_1/midle)%2);
			y.push_back((binaire_2/midle)%2);
			midle/= 10;
		}
		int resultat = 0;  
    for (int j = 0; j < taille_1; j++) { 
        resultat =  (x[j] * y[j]) + resultat * 10;
    }
    return resultat;
	}else {
		int temp = taille_2;
		--temp;
		int midle = pow(10, temp);
		for (int i = 0; i< taille_2; i++){
			x.push_back((binaire_1/midle)%2);
			y.push_back((binaire_2/midle)%2);
			midle/= 10;
		}
		int resultat = 0;  
		
		for (int j = 0; j < taille_2; j++) {  
        resultat =  (x[j] * y[j]) + resultat * 10;
    } 
    return resultat;
	}

}
