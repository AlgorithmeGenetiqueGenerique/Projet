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
const int evaluation::CEIL = 17;
const int evaluation::FLOOR = 18;
const int evaluation::EXPONENTIELLE = 19;
const int evaluation::LOG_10 = 20;
const int evaluation::COSINUS = 21;
const int evaluation::COSINUSH = 22;
const int evaluation::ACOSINUS = 23;
const int evaluation::SINUS = 24;
const int evaluation::SINUSH = 25;
const int evaluation::ASINUS = 26;
const int evaluation::TANGENTE = 27;
const int evaluation::TANGENTEH = 28;
const int evaluation::ATANGENTE = 29;
const int evaluation::LN = 30;
const int evaluation::RACINEC = 31;
const int evaluation::OR = 32;
const int evaluation::NOR = 33;
const int evaluation::NAND = 34;
const int evaluation::NOT = 35;
const int evaluation::XOR = 36;
	
evaluation::evaluation(std::string chaine_evaluation){
	 this->chaine_evaluation = chaine_evaluation;
	 noeud= 0;
	 indice = 1;
	 entier = 0;
	 flottant = 0.0;
	 sommet_pile = -1;
	 caractere = chaine_evaluation[0];
     erreur=0;
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
		while( ('a' <= caractere)&&('d' >= caractere)||('w' <= caractere)&&('z' >= caractere)){
		n = 1;
		noeud = GENE;
		switch(individu_x->ADN.getTypeGenes()){
		case 1 : {
		if (caractere == 'a')
			entier = individu_x->ADN.genes_int.at(0);
		else if (caractere == 'b')
        {
            if(individu_x->ADN.getNombreGenes()<2)
                erreur=1;
            else
                entier = individu_x->ADN.genes_int.at(1);
        }
		else if (caractere == 'c')
        {
            if(individu_x->ADN.getNombreGenes()<3)
                erreur=1;
            else
                entier = individu_x->ADN.genes_int[2];
        }

		else if (caractere == 'd')
            {
            if(individu_x->ADN.getNombreGenes()<4)
                erreur=1;
            else
               entier = individu_x->ADN.genes_int[3];
            }

		else if (caractere == 'w')
            {
            if(individu_x->ADN.getNombreGenes()<5)
                erreur=1;
            else
                entier = individu_x->ADN.genes_int[4];
            }

		else if (caractere == 'x')
            {
            if(individu_x->ADN.getNombreGenes()<6)
                erreur=1;
            else
                entier = individu_x->ADN.genes_int[5];
            }

		else if (caractere == 'y')
            {
            if(individu_x->ADN.getNombreGenes()<7)
                erreur=1;
            else
               entier = individu_x->ADN.genes_int[6];
            }

		else if (caractere == 'z')
            {
            if(individu_x->ADN.getNombreGenes()<8)
                erreur=1;
            else
                entier = individu_x->ADN.genes_int[7];
            }

			break;
			}	
		case 2 : {
		if (caractere == 'a')
			flottant = individu_x->ADN.genes_double.at(0);
		else if (caractere == 'b')
        {
            if(individu_x->ADN.getNombreGenes()<2)
                erreur=1;
            else
                flottant = individu_x->ADN.genes_double.at(1);
        }

		else if (caractere == 'c')
        {
           if(individu_x->ADN.getNombreGenes()<3)
                erreur=1;
           else
            flottant = individu_x->ADN.genes_double[2];
        }

		else if (caractere == 'd')
        {
            if(individu_x->ADN.getNombreGenes()<4)
                 erreur=1;
            else
                flottant = individu_x->ADN.genes_double[3];
        }

		else if (caractere == 'w')
        {
            if(individu_x->ADN.getNombreGenes()<5)
                 erreur=1;
            else
                flottant = individu_x->ADN.genes_double[4];
        }

		else if (caractere == 'x')
        {
            if(individu_x->ADN.getNombreGenes()<6)
                 erreur=1;
            else
                flottant = individu_x->ADN.genes_double[5];
        }

		else if (caractere == 'y')
        {
            if(individu_x->ADN.getNombreGenes()<7)
                 erreur=1;
            else
                flottant = individu_x->ADN.genes_double[6];
        }

		else if (caractere == 'z')
        {
            if(individu_x->ADN.getNombreGenes()<8)
                 erreur=1;
            else
             flottant = individu_x->ADN.genes_double[7];
        }

			break;
			}
        case 3 : {
		if (caractere == 'a')
			entier = individu_x->ADN.genes_int.at(0);
		else if (caractere == 'b')
        {
            if(individu_x->ADN.getNombreGenes()<2)
                 erreur=1;
            else
                entier = individu_x->ADN.genes_int.at(1);
        }

		else if (caractere == 'c')
        {
            if(individu_x->ADN.getNombreGenes()<3)
                 erreur=1;
            else
                entier = individu_x->ADN.genes_int[2];
        }

		else if (caractere == 'd')
        {
            if(individu_x->ADN.getNombreGenes()<4)
                 erreur=1;
            else
                entier = individu_x->ADN.genes_int[3];
        }

		else if (caractere == 'w')
        {
            if(individu_x->ADN.getNombreGenes()<5)
                 erreur=1;
            else
                entier = individu_x->ADN.genes_int[4];
        }

		else if (caractere == 'x')
        {
            if(individu_x->ADN.getNombreGenes()<6)
                 erreur=1;
            else
                entier = individu_x->ADN.genes_int[5];
        }

		else if (caractere == 'y')
        {
            if(individu_x->ADN.getNombreGenes()<7)
                 erreur=1;
            else
                entier = individu_x->ADN.genes_int[6];
        }

		else if (caractere == 'z')
        {
            if(individu_x->ADN.getNombreGenes()<8)
                 erreur=1;
            else
                entier = individu_x->ADN.genes_int[7];
        }

			break;
			}	
		}
	caractere = chaine_evaluation[indice++];
	}  
	if(!n)
		switch(caractere)
	{
	case '+':{//ADDITION
				caractere = chaine_evaluation[indice++];			
				noeud = ADDITION;
				break;
			 }
	case '-':{//SOUSTRACTION
				if ((noeud != GENE)&&(noeud != DOUBLE)&&(noeud != ENTIER)&&(noeud != PARENTHESE_F)){
					caractere = chaine_evaluation[indice++];
					if (individu_x->ADN.getTypeGenes() == 1 || individu_x->ADN.getTypeGenes() == 3){
						while( ('0' <= caractere)&&('9' >= caractere) )
						{
							noeud = ENTIER;
							entier = (caractere - '0') + entier * 10;
							caractere = chaine_evaluation[indice++];
							n = 1;
						}
						while( ('a' <= caractere)&&('d' >= caractere)||('w' <= caractere)&&('z' >= caractere)){
							noeud = GENE;
							
							if (caractere == 'a')
			entier = individu_x->ADN.genes_int.at(0);
		else if (caractere == 'b')
			entier = individu_x->ADN.genes_int.at(1);
		else if (caractere == 'c')
			entier = individu_x->ADN.genes_int[2];
		else if (caractere == 'd')
			entier = individu_x->ADN.genes_int[3];
		else if (caractere == 'w')
			entier = individu_x->ADN.genes_int[4];
		else if (caractere == 'x')
			entier = individu_x->ADN.genes_int[5];
		else if (caractere == 'y')
			entier = individu_x->ADN.genes_int[6];
		else if (caractere == 'z')
			entier = individu_x->ADN.genes_int[7];
							n = 1;
							caractere = chaine_evaluation[indice++];
						}
						if (caractere == '^'){
							flottant = 1.1;
						}
						if ((caractere == 'f')||(caractere == '(')){
							analyseSyntaxiqueTypes(individu_x);
							identification(individu_x);
							int x = depiler();
							x *=-1;
							empiler(x);
						}
						else entier *= -1;
						}
					   else if (individu_x->ADN.getTypeGenes() == 2){
						  if (caractere == '>'||caractere == '<'||caractere == 'f'||(caractere == '(')){
							  analyseSyntaxiqueTypes(individu_x);
							identification(individu_x);
							double x = depilerFlottants();
							x *=-1;
							empilerFlottants(x);
						  }else {
						   analyseSyntaxiqueTypes(individu_x);
						   if (caractere == '^')
						   entier = 1;
						   flottant *= -1;
						}
					   }
				}
				else {
						noeud = SOUSTRACTION;
						caractere = chaine_evaluation[indice++];
				}
				break;
			 }
	case '*':{//MULTIPLICATION
				caractere = chaine_evaluation[indice++];
				noeud = MULTIPLICATION;
				break;
			 }
	case '/':{//DIVISION
				caractere = chaine_evaluation[indice++];
				noeud = DIVISION;
				break;
			 }
	case '%':{//MODULO
				caractere = chaine_evaluation[indice++];
				noeud = MODULO;
				break;
			 }
     case '&':{//ET LOGIQUE
				caractere = chaine_evaluation[indice++];
				noeud = AND;
				break;
			 }
	 case '|':{//OU LOGIQUE
				caractere = chaine_evaluation[indice++];
				noeud = OR;
				break;
			 }
	case '(':{//PARENTHESE OUVRANTE
				caractere = chaine_evaluation[indice++];
				noeud = PARENTHESE_O;
				break;
			 }
	case ')':{//PARENTHESE FERMANTE
				caractere = chaine_evaluation[indice++];
				noeud = PARENTHESE_F;
				break;
			 }	
	case '#':{//SYMBOLE DE FIN
			    caractere = chaine_evaluation[indice++];
				noeud = FIN;
				break;
			 }
	case '>':{// ENTIER SUPERIEUR
					caractere = chaine_evaluation[indice++];
					noeud = CEIL;
					break;
				}
	case '<':{//ENTIER INFERIEUR
					caractere = chaine_evaluation[indice++];
					noeud = FLOOR;
					break;
				}
	case '^':{//PUISSANCE
				caractere = chaine_evaluation[indice++];
				noeud = PUISSANCE;
				break;
				
			 }
	case'f':{//FONCTIONS
				caractere = chaine_evaluation[indice++];
				switch(caractere){
					case 'c':{//cosinus et cosinus hyperbolique
						caractere = chaine_evaluation[indice++];
						if(caractere == 'o'){
							caractere = chaine_evaluation[indice++];
							if(caractere == 's'){
								noeud = COSINUS;
								caractere = chaine_evaluation[indice++];
							}	if(caractere == 'h'){
									noeud = COSINUSH;
									caractere = chaine_evaluation[indice++];
								}
						}
						break;
					}
					case 'a':{//acosinus, asinus, atangente
						caractere = chaine_evaluation[indice++];
						switch(caractere){
							case 'c':{//--------------ACOSINUS
								caractere = chaine_evaluation[indice++];
								if(caractere == 'o'){
									caractere = chaine_evaluation[indice++];
									if(caractere == 's'){
										caractere = chaine_evaluation[indice++];
										noeud = ACOSINUS;
									}
								}
								break;//---------------Fin ACOSINUS
							}
							case 's':{//_______________ASINUS
								caractere = chaine_evaluation[indice++];
								if(caractere == 'i'){
									caractere = chaine_evaluation[indice++];
									if (caractere == 'n'){
										caractere = chaine_evaluation[indice++];
										noeud = ASINUS;		
									}
								}
								break;//_______________FIN ASINUS
							}
							case 't':{//---------------ATANGENTE
								caractere = chaine_evaluation[indice++];
								if(caractere == 'a'){
									caractere = chaine_evaluation[indice++];
									if (caractere == 'n'){
										caractere = chaine_evaluation[indice++];
										noeud = ATANGENTE;
									}
								}
								break;//---------------FIN ATANGENTE
							}
						}
						break;// FIN DES ACOS, ASIN, ATAN
					}
					case 's':{// SINUS ET SINUS HYPERBOLIQUE
							caractere = chaine_evaluation[indice++];
							if (caractere == 'i'){
								caractere = chaine_evaluation[indice++];
								if (caractere == 'n'){
									caractere = chaine_evaluation[indice++];
									noeud = SINUS;
									if (caractere == 'h'){
										caractere = chaine_evaluation[indice++];
										noeud = SINUSH;
								}
							}
						}
						break;
					}
					case 't':{//TANGENTE ET TANGENTE HYPERBOLIQUE
						caractere = chaine_evaluation[indice++];
						if (caractere == 'a'){
							caractere = chaine_evaluation[indice++];
							if (caractere == 'n'){
								caractere = chaine_evaluation[indice++];
								noeud = TANGENTE;
								if (caractere == 'h'){
									caractere = chaine_evaluation[indice++];
									noeud = TANGENTEH;
								}
							}
						}
						break;
					}
					case 'l':{//LN, LOG_2 & LOG_10
						caractere = chaine_evaluation[indice++];
						switch(caractere){
							case 'n':{//----------LN
								caractere = chaine_evaluation[indice++];
								noeud = LN;
								break;//----------FIN LN
							}
							case 'o':{//LOG_2 & LOG_10
								caractere = chaine_evaluation[indice++];	
								if(caractere == 'g'){//LOG_2
									caractere = chaine_evaluation[indice++];
									noeud = LOG_2;
									if(caractere == 'x'){//LOG_10
										caractere = chaine_evaluation[indice++];
										noeud = LOG_10;
									}
								}
								break;//FIN LOG_2 & LOG_10
							}
						}
						break;//FIN LN, LOG_2 & LOG_10
					}
					case 'r':{//----RACINE ET RACINE CUBIQUE
						caractere = chaine_evaluation[indice++];
						if(caractere == 'c'){//racine cubique
							caractere = chaine_evaluation[indice++];
							noeud = RACINEC;
						}
						else {//racine carré
							noeud = RACINE;
						}
						break;//----FIN RACINE ET RACINE CUBIQUE
					}
					case 'v':{//VALEURE ABSOLUE
						caractere = chaine_evaluation[indice++];
						if(caractere == 'a'){
							caractere = chaine_evaluation[indice++];
							noeud = V_ABSOLUE;
						}
						break;//FIN VALEUR ABSOLUE
					}
					case 'e':{//EXPONENTIELLE
						caractere = chaine_evaluation[indice++];
						noeud = EXPONENTIELLE;
						break;
					}
					case 'x':{//____________XOR
						caractere = chaine_evaluation[indice++];
						if (caractere == '|'){
							caractere = chaine_evaluation[indice++];
							noeud = XOR;
						}
						break;//____________FIN XOR
					}
					case '~':{//NOT, NAND & NOR
						caractere = chaine_evaluation[indice++];
						switch(caractere){
							case '|':{//-------------NOR
								caractere = chaine_evaluation[indice++];
								noeud = NOR;
								break;//-------------FIN NOR
							}
							case '&':{//_____________NAND
								caractere = chaine_evaluation[indice++];
								noeud = NAND;
								break;//_____________FIN NAND
							}
							default :{//NOT
								noeud = NOT;
								break;// FIN NOT
							}
						}
						break;// FIN NOT, NAND & NOR
					}
				}
				break;// FIN FONCTION
			}
        default :{
                erreur = 7;
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
					if( noeud == PARENTHESE_F ){
						analyseSyntaxiqueTypes(individu_x);
						if (noeud == PUISSANCE) {
							if (individu_x->ADN.getTypeGenes() == 1 || individu_x->ADN.getTypeGenes() == 3){
							double inter = flottant;;
							flottant = 2.2;
							operations(individu_x);
							flottant = inter;
						}
						else if (individu_x->ADN.getTypeGenes() == 2){
								int inter = entier;
								entier = 2;
								operations(individu_x);
								entier = inter;
							}
							}
					}
					else
					{
						analyseSyntaxiqueTypes(individu_x);
                        erreur = 2;
					}
					break;
				  }
	case RACINE:{
				 analyseSyntaxiqueTypes(individu_x);
				 identification(individu_x);
				 if (individu_x->ADN.getTypeGenes() == 1){
					empiler(sqrt(depiler()));
				 }
				 else if (individu_x->ADN.getTypeGenes() == 2){
					empilerFlottants(sqrt(depilerFlottants()));
				 }
					else if (individu_x->ADN.getTypeGenes() == 3)
                    erreur = 3;
				 break;
				 }
	case RACINEC:{
				 analyseSyntaxiqueTypes(individu_x);
				 identification(individu_x);
				 if (individu_x->ADN.getTypeGenes() == 1){
					empiler(cbrt(depiler()));
				 }
				 else if (individu_x->ADN.getTypeGenes() == 2){
					empilerFlottants(cbrt(depilerFlottants()));
				 }
				 else if (individu_x->ADN.getTypeGenes() == 3)
                    erreur = 3;
				 break;
				 }
	case LOG_2:{
				 analyseSyntaxiqueTypes(individu_x);
				 identification(individu_x);
				 if (individu_x->ADN.getTypeGenes() == 1){
                    erreur = 4;
				 }
				 else if (individu_x->ADN.getTypeGenes() == 2){
					empilerFlottants(log2(depilerFlottants()));
				 }
				 else if (individu_x->ADN.getTypeGenes() == 3)
                    erreur = 3;
				 break;
				 }
	case LOG_10:{
				 analyseSyntaxiqueTypes(individu_x);
				 identification(individu_x);
				 if (individu_x->ADN.getTypeGenes() == 1){
                    erreur = 4;
				 }
				 else if (individu_x->ADN.getTypeGenes() == 2){
					empilerFlottants(log10(depilerFlottants()));
				 }
				 else if (individu_x->ADN.getTypeGenes() == 3)
                    erreur = 3;
				 break;
				 }
	case LN:{
				 analyseSyntaxiqueTypes(individu_x);
				 identification(individu_x);
				 if (individu_x->ADN.getTypeGenes() == 2){
					empilerFlottants(log(depilerFlottants()));	
				 } 
				 else if (individu_x->ADN.getTypeGenes() == 1)
                    erreur = 4;
				 else if (individu_x->ADN.getTypeGenes() == 3)
                    erreur = 3;
				 break;
				 }
	case V_ABSOLUE:{
			double y = 0.0;
				 analyseSyntaxiqueTypes(individu_x);
				 identification(individu_x);
				 if (individu_x->ADN.getTypeGenes() == 1){
					empiler(abs(depiler()));
				 }
				 if (individu_x->ADN.getTypeGenes() == 2){
					 y = depilerFlottants();
					 if (y < 0.0) y = -1*y;
					 empilerFlottants(y);
				 }
				 else if (individu_x->ADN.getTypeGenes() == 3)
                    erreur = 3;
				 break;
				 }
	case EXPONENTIELLE:{
				 analyseSyntaxiqueTypes(individu_x);
				 identification(individu_x);
				 if (individu_x->ADN.getTypeGenes() == 1){
					empiler((int)exp(depiler()));
				 }
				 else if (individu_x->ADN.getTypeGenes() == 2){
					empilerFlottants(exp(depilerFlottants()));
				 }
				 else if (individu_x->ADN.getTypeGenes() == 3)
                    erreur = 3;
				 break;
				 }
	case COSINUS:{
				 analyseSyntaxiqueTypes(individu_x);
				 identification(individu_x);
				 if (individu_x->ADN.getTypeGenes() == 2){
					empilerFlottants(cos(depilerFlottants()));
				 }
				 else if (individu_x->ADN.getTypeGenes() == 3)
                    erreur = 3;
				 else if (individu_x->ADN.getTypeGenes() == 1)
                    erreur = 4;
				 break;
				 }
	case COSINUSH:{
				 analyseSyntaxiqueTypes(individu_x);
				 identification(individu_x);
				 if (individu_x->ADN.getTypeGenes() == 2){
					empilerFlottants(cosh(depilerFlottants()));
				 }
				 else if (individu_x->ADN.getTypeGenes() == 3)
                    erreur = 3;
				 else if (individu_x->ADN.getTypeGenes() == 1)
                    erreur = 4;
				 break;
				 }
	case ACOSINUS:{
				 analyseSyntaxiqueTypes(individu_x);
				 identification(individu_x);
				 if (individu_x->ADN.getTypeGenes() == 2){
					empilerFlottants(acos(depilerFlottants()));
				 }
				 else if (individu_x->ADN.getTypeGenes() == 3)
                    erreur = 3;
				 else if (individu_x->ADN.getTypeGenes() == 1)
                    erreur = 4;
				 break;
				 }
	case SINUS:{
				 analyseSyntaxiqueTypes(individu_x);
				 identification(individu_x);
				 if (individu_x->ADN.getTypeGenes() == 2){
					empilerFlottants(sin(depilerFlottants()));
				 }
				 else if (individu_x->ADN.getTypeGenes() == 3)
                    erreur = 3;
				 else if (individu_x->ADN.getTypeGenes() == 1)
                    erreur = 4;
				 break;
				 }
	case SINUSH:{
				 analyseSyntaxiqueTypes(individu_x);
				 identification(individu_x);
				 if (individu_x->ADN.getTypeGenes() == 2){
					empilerFlottants(sinh(depilerFlottants()));
				 }
				 else if (individu_x->ADN.getTypeGenes() == 3)
                    erreur = 3;
				 else if (individu_x->ADN.getTypeGenes() == 1)
                    erreur = 4;
				 break;
				 }
	case ASINUS:{
				 analyseSyntaxiqueTypes(individu_x);
				 identification(individu_x);
				 if (individu_x->ADN.getTypeGenes() == 2){
					empilerFlottants(asin(depilerFlottants()));
				 }
				 else if (individu_x->ADN.getTypeGenes() == 3)
                    erreur = 3;
				 else if (individu_x->ADN.getTypeGenes() == 1)
                    erreur = 4;
				 break;
				 }
	case TANGENTE:{
				 analyseSyntaxiqueTypes(individu_x);
				 identification(individu_x);
				 if (individu_x->ADN.getTypeGenes() == 2){
					empilerFlottants(tan(depilerFlottants()));
				 }
				 else if (individu_x->ADN.getTypeGenes() == 3)
                    erreur = 3;
				 else if (individu_x->ADN.getTypeGenes() == 1)
                    erreur = 4;
				 break;
				 }
	case TANGENTEH:{
				 analyseSyntaxiqueTypes(individu_x);
				 identification(individu_x);
				 if (individu_x->ADN.getTypeGenes() == 2){
					empilerFlottants(tanh(depilerFlottants()));
				 }
				 else if (individu_x->ADN.getTypeGenes() == 3)
                    erreur = 3;
				 else if (individu_x->ADN.getTypeGenes() == 1)
                    erreur = 4;
				 break;
				 }
	case ATANGENTE:{
				 analyseSyntaxiqueTypes(individu_x);
				 identification(individu_x);
				 if (individu_x->ADN.getTypeGenes() == 2){
					empilerFlottants(atan(depilerFlottants()));
				 }
				 else if (individu_x->ADN.getTypeGenes() == 3)
                    erreur = 3;
				 else if (individu_x->ADN.getTypeGenes() == 1)
                    erreur = 4;
				 break;
				 }
	case CEIL:{	
				 analyseSyntaxiqueTypes(individu_x);
				 identification(individu_x);
				 if (individu_x->ADN.getTypeGenes() == 2){
					empilerFlottants(ceil(depilerFlottants()));
				 }
				 else if (individu_x->ADN.getTypeGenes() == 3)
                    erreur = 3;
				 else if (individu_x->ADN.getTypeGenes() == 1)
                    erreur = 4;
				 break;
				 }
	case FLOOR:{	
				 analyseSyntaxiqueTypes(individu_x);
				 identification(individu_x);
				 if (individu_x->ADN.getTypeGenes() == 2){
					empilerFlottants(floor(depilerFlottants()));
				 }
				 if (individu_x->ADN.getTypeGenes() == 3)
                    erreur = 3;
				 if (individu_x->ADN.getTypeGenes() == 1)
                    erreur = 4;
				 break;
				 }
	case NOT:{
				 if (individu_x->ADN.getTypeGenes() == 3){
					int x;
					analyseSyntaxiqueTypes(individu_x);
					identification(individu_x);
					x = individu_x->conversionVersBinaire(depiler());
					flottant = 5.5;
					x = individu_x->convertionVersDecimale(operationsLogiques(x, 0));
					flottant = 0.0;
					empiler(x);
				 }
				 else if (individu_x->ADN.getTypeGenes() == 1){
                     erreur = 4;
				 }  
				 else if (individu_x->ADN.getTypeGenes() == 2){
                     erreur = 5;
				 } 
				 operations(individu_x);
				 break;
				 }
	default:{
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
				 if ((individu_x->ADN.getTypeGenes() == 1) || (individu_x->ADN.getTypeGenes() == 3)){
					analyseSyntaxiqueTypes(individu_x);
					if (caractere == '^') flottant = 1.1;
					identification(individu_x);
					if (flottant != 1.1){
						x = depiler();
						x*=-1;
						empiler(x);
					}
					operations(individu_x);
					x = depiler();
				    int y = depiler();
					empiler(y+x);
				 }
				 else if (individu_x->ADN.getTypeGenes() == 2){
					double x,y;
					analyseSyntaxiqueTypes(individu_x);
					if (caractere == '^') entier = 1;
						identification(individu_x);
					if (entier != 1){
						x = depilerFlottants();
						x*=-1;
						empilerFlottants(x);
					}
					operations(individu_x);
					x = depilerFlottants();
					y = depilerFlottants();
					empilerFlottants(y+x);
				 }	 
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
					
				break;
				}
	case MULTIPLICATION:{	
				if ((individu_x->ADN.getTypeGenes() == 1) || (individu_x->ADN.getTypeGenes() == 3)){
				analyseSyntaxiqueTypes(individu_x);
				identification(individu_x);
				if (noeud == PUISSANCE) {
					flottant = 2.2;
					operations(individu_x);
					flottant = 0.0;
				}
				empiler((depiler()*depiler()) );
				}
				else if (individu_x->ADN.getTypeGenes() == 2){
					analyseSyntaxiqueTypes(individu_x);
					identification(individu_x);
					if (noeud == PUISSANCE) {
						entier = 2;
						operations(individu_x);
						entier = 0;
					}
				empilerFlottants((depilerFlottants()*depilerFlottants()));	
				}
					operations(individu_x);
				break;
				}
	case DIVISION:{
				 if ((individu_x->ADN.getTypeGenes() == 1)|| (individu_x->ADN.getTypeGenes() == 3)){
					analyseSyntaxiqueTypes(individu_x);
					identification(individu_x);
					if (noeud == PUISSANCE) {
						flottant = 2.2;
						operations(individu_x);
						flottant = 0.0;
					}
					x = depiler();
                    if (!x) erreur=6;
					else empiler(depiler()/x );
				 }
				 else {
					 analyseSyntaxiqueTypes(individu_x);
					identification(individu_x);
					if (noeud == PUISSANCE) {
						entier = 2;
						operations(individu_x);
						entier = 0;
					}
					y = depilerFlottants();
                    if (!y) erreur=6;
					else empilerFlottants(depilerFlottants()/y );
				 } 
				 operations(individu_x);
				 break;
				 }
	case PUISSANCE:{
				 analyseSyntaxiqueTypes(individu_x);
				 identification(individu_x);
				 if (individu_x->ADN.getTypeGenes() == 1){
					x = depiler();
					int y = depiler();
					y = pow(y,x);
					if (noeud == PUISSANCE) {
						empiler(y);
						operations(individu_x);
					}
					else {
					if (flottant == 1.1){
						flottant = 0.0;
						if (y>=0)
						y*=-1;
					}
					empiler(y);
					}
					if (flottant != 2.2)operations(individu_x);
				 }
				 else if (individu_x->ADN.getTypeGenes() == 2){
					 double x = 0.0;
					 x = depilerFlottants();
					 y = depilerFlottants();
					 y = pow(y,x);
					 if (entier == 1){
						entier = 0;
						if (y>=0)
						y*=-1;
					}
					 empilerFlottants(y);
					 if (entier != 2)operations(individu_x);
				 }
				 else if (individu_x->ADN.getTypeGenes() == 3){
                    erreur = 3;
				 }	 
				 break;
				 }
	case MODULO:{
				 if (individu_x->ADN.getTypeGenes() == 1){
					analyseSyntaxiqueTypes(individu_x);
					identification(individu_x);
					if (noeud == PUISSANCE) {
					flottant = 2.2;
					operations(individu_x);
					flottant = 0.0;
				}
					x = depiler();
                    if (!x) erreur = 7;
                    else empiler(depiler()%x);
				 }
				 else if (individu_x->ADN.getTypeGenes() == 2){
				 analyseSyntaxiqueTypes(individu_x);
				 identification(individu_x);
				 if (noeud == PUISSANCE) {
					entier = 2;
					operations(individu_x);
					entier = 0;
				}
					 y = depilerFlottants();
                     if (!y) erreur = 7;
                     else  empilerFlottants(fmod(depilerFlottants(),y));
				 }
				 else if (individu_x->ADN.getTypeGenes() == 3)
                    erreur = 3;
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
					flottant = 1.1;
					x = individu_x->convertionVersDecimale(operationsLogiques(x, y));
					flottant = 0.0;
					empiler(x);
                    operations(individu_x);
				 }
				 else if (individu_x->ADN.getTypeGenes() == 1){
                     erreur = 4;
				 }  
				 else if (individu_x->ADN.getTypeGenes() == 2){
                     erreur = 5;
				 }
				 break;
				 }
	case OR:{
				 if (individu_x->ADN.getTypeGenes() == 3){
					int x, y;
					analyseSyntaxiqueTypes(individu_x);
					identification(individu_x);
					operations(individu_x);
					x = individu_x->conversionVersBinaire(depiler());
					y = individu_x->conversionVersBinaire(depiler());
					flottant = 2.2;
					x = individu_x->convertionVersDecimale(operationsLogiques(x, y));
					flottant = 0.0;
					empiler(x);
				 }	
				 else if (individu_x->ADN.getTypeGenes() == 1){
                     erreur = 4;
				 }  
				 else if (individu_x->ADN.getTypeGenes() == 2){
                     erreur = 5;
				 } 
				 break;
				 }
		case NOR:{
				 if (individu_x->ADN.getTypeGenes() == 3){
					int x, y;
					analyseSyntaxiqueTypes(individu_x);
					identification(individu_x);
					operations(individu_x);
					x = individu_x->conversionVersBinaire(depiler());
					y = individu_x->conversionVersBinaire(depiler());
					flottant = 3.3;
					x = individu_x->convertionVersDecimale(operationsLogiques(x, y));
					flottant = 0.0;
					empiler(x);
				 }
				 else if (individu_x->ADN.getTypeGenes() == 1){
                     erreur = 4;
				 }  
				 else if (individu_x->ADN.getTypeGenes() == 2){
                     erreur = 5;
				 } 
				 break;
				 }
		case NAND:{
				 if (individu_x->ADN.getTypeGenes() == 3){
					int x, y;
					analyseSyntaxiqueTypes(individu_x);
					identification(individu_x);
					operations(individu_x);
					x = individu_x->conversionVersBinaire(depiler());
					y = individu_x->conversionVersBinaire(depiler());
					flottant = 4.4;
					x = individu_x->convertionVersDecimale(operationsLogiques(x, y));
					flottant = 0.0;
					empiler(x);
				 }	
				 else if (individu_x->ADN.getTypeGenes() == 1){
                     erreur = 4;
				 }  
				 else if (individu_x->ADN.getTypeGenes() == 2){
                     erreur = 5;
				 } 
				 break;
				 }
	case XOR:{
				 if (individu_x->ADN.getTypeGenes() == 3){
					int x, y;
					analyseSyntaxiqueTypes(individu_x);
					identification(individu_x);
					operations(individu_x);
					x = individu_x->conversionVersBinaire(depiler());
					y = individu_x->conversionVersBinaire(depiler());
					flottant = 6.6;
					x = individu_x->convertionVersDecimale(operationsLogiques(x, y));
					flottant = 0.0;
					empiler(x);
				 }
				 else if (individu_x->ADN.getTypeGenes() == 1){
                     erreur = 4;
				 }  
				 else if (individu_x->ADN.getTypeGenes() == 2){
                     erreur = 5;
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
		if (flottant == 1.1)
			resultat =  (x[j] * y[j]) + resultat * 10;
			else  if (flottant == 2.2)
				resultat =  (x[j] || y[j]) + resultat * 10;
				else  if (flottant == 3.3)
				resultat =  (!(x[j] || y[j])) + resultat * 10;
				else if (flottant == 4.4)
					resultat =  (!(x[j] * y[j])) + resultat * 10;
					else if (flottant == 5.5)
						resultat =  (!x[j]) + resultat * 10;
						else if (flottant == 6.6)
							resultat =  (!(x[j]==y[j])) + resultat * 10;
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
			if (flottant == 1.1)
				resultat =  (x[j] * y[j]) + resultat * 10;
				else if (flottant == 2.2)
					resultat =  (x[j] || y[j]) + resultat * 10;
					else if (flottant == 3.3)
						resultat =  (!(x[j] || y[j])) + resultat * 10;
						else if (flottant == 4.4)
							resultat =  (!(x[j] * y[j])) + resultat * 10;
							else if (flottant == 5.5)
								resultat =  (!x[j]) + resultat * 10;
								else if (flottant == 6.6)
									resultat =  (!(x[j]==y[j])) + resultat * 10;
    } 
    return resultat;
	}
}	

int evaluation::getErreur()
{
    return erreur;
}
