#include <iostream>
#include <time.h>		
#include "operations_genetiques.h"
#include "EntreesSorties.h"

using namespace std;

EntreesSorties saisie_des_entrees(){
	std::string chaine_evaluation;
	int taille_population;
	int nombre_iterations;
	int nmbr_indiv_a_selec;
	int choix_selection;
	int nombre_genes;
	float taux_croisement;
	float taux_mutation;
	int generation_satisfaisante;
	double generation_satisfaisante_d;
	int type_genes;
	int min_intervalle;
	int max_intervalle;
	double min_intervalle_d;
	double max_intervalle_d;
	int maximisation;
	cout << "------------------------Algorithme Génétique-----------------------------------"<<endl;
	cout << "________________________________________________________________________________\n";
	cout << "0 : Modéliser un problème\n";
	cout << "1 : Charger une configuration\n";	
	cout << "Votre Choix : ";	
	int choix = 0;
	cin >> choix;
	if (choix) return EntreesSorties("configuration1.txt");
	else { 
	cout << "________________________________________________________________________________\n";
	cout << "                     Taille de la population : ";
	cin >>   taille_population;
	cout << "________________________________________________________________________________\n";
	cout << "                         Type des gènes : \n";
	cout << "1 :   Entier\n";
	cout << "2 :   Double\n";
	cout << "3 :   Booléen\n";
	cout << "                         Votre choix : ";
	cin >>   type_genes;
	cout << "________________________________________________________________________________\n";
	cout << "                        Nombre de gènes : ";
	cin >>   nombre_genes;
	cout << "________________________________________________________________________________\n";
	cout << "               Donner l'équation de l'évaluation : ";
	cout << "a : gène1| b : gène2| c : gène3| d : géne4\n";
	cin >>   chaine_evaluation;
	cout << "________________________________________________________________________________\n";
	cout << "                     intervalle des genes : \n";
	cout << "                   [ ";
	if (type_genes == 1 || type_genes == 3)cin >> min_intervalle;
	else if (type_genes == 2 ) cin >> min_intervalle_d;
	cout <<"                              ,     ";
	if (type_genes == 1 || type_genes == 3)cin >> max_intervalle;
	else if (type_genes == 2 ) cin >> max_intervalle_d;
	cout <<"                                        ]\n";
	cout << "________________________________________________________________________________\n";
	cout << "                      Condition d'arret : ";
	cout << "Score totale de la génération satisfaisante : ";
	if (type_genes == 1 || type_genes == 3 ) cin >> generation_satisfaisante;
	else if (type_genes == 2 ) cin >> generation_satisfaisante_d;
    cout << "________________________________________________________________________________\n";
	cout << "                  nombre maximum d'itérations : ";
	cin >>   nombre_iterations;
    cout << "________________________________________________________________________________\n";
	cout << "                choisir un type de séléction : \n";
	cout << "1 :   séléction par rang\n";
	cout << "2 :   séléction par tournois\n";
	cout << "3 :   séléction par roulette\n";
	cout << "                                    Choix : ";
	cin >>   choix_selection;
    cout << "_______________________________________________________________________________\n";
	cout << "    donner le nombre d'individus qui seront séléctionner : ";
	cin >>   nmbr_indiv_a_selec;
	cout << "________________________________________________________________________________\n";
	while((taux_croisement * nmbr_indiv_a_selec) < 2){
	cout << "              donner le taux de croisement : ";
	cin >> taux_croisement;
	}
	cout << "________________________________________________________________________________\n";
	cout << "               donner le taux de mutation : ";
	cin >> taux_mutation;
	cout << "________________________________________________________________________________\n";
	cout << "1 :   Maximisation\n";
	cout << "2 :   Minimisation\n";
	cout << "                                    Choix : ";
	cin >> maximisation;
	cout << "________________________________________________________________________________\n";
	if (type_genes == 1 || type_genes == 3)return EntreesSorties(chaine_evaluation, taille_population, nombre_iterations, nmbr_indiv_a_selec, choix_selection , nombre_genes, taux_croisement, taux_mutation, generation_satisfaisante, type_genes, min_intervalle, max_intervalle, maximisation);
	else if (type_genes == 2 ) return EntreesSorties(chaine_evaluation, taille_population, nombre_iterations, nmbr_indiv_a_selec, choix_selection , nombre_genes, taux_croisement, taux_mutation, generation_satisfaisante_d, type_genes, min_intervalle_d, max_intervalle_d, maximisation);
	}
}

int main(int argc, char *argv[])
{
	//--------------------------------------variables----------------------------------------
	
	srand(unsigned(time(NULL)));
	
	int score_totale = 0;
	double score_totale_d = 0;
	int meilleur_premier;
	double meilleur_premier_d;
	
	int score_debut = 0;
	double score_debut_d = 0;
	
	bool arret = false;
	vector<int> score_total;
	vector<double> score_total_d;
	vector<int> meillleur_individu;
	vector<double> meillleur_individu_d;
	vector<individu> individus; // Notre population
	int compteur_generation = 0;
	//-------------------------------------les affichages--------------------------------------
	EntreesSorties ee = saisie_des_entrees();
	//-------------------------initialisations et évaluation---------------
	operationsGenetiques op = operationsGenetiques(&individus, ee.getMaximisationMinimisation(), ee.getNmbr_indiv_a_selec());
	for (int j = 0; j< ee.getNombreiterations(); j++){
		if(!j){
			for (int i = 0; i< ee.getTaillePopulation(); i++){
				if ((ee.getTypeGenes() == 1) || (ee.getTypeGenes() == 3))
				individus.push_back(individu(ee.getMinIntervalle(),ee.getMaxIntervalle(), ee.getNombreGenes(),ee.getTypeGenes()));
				else if (ee.getTypeGenes() == 2)
				individus.push_back(individu(ee.getMinIntervalleFlottant(),ee.getMaxIntervalleFlottant(), ee.getNombreGenes(),ee.getTypeGenes()));
				evaluation e = evaluation (ee.getChaineEvaluation());
				e.evaluer(&individus[i]);
				//cout <<"a : "<< individus[i].ADN.genes_int.at(0) << endl;
				//cout <<"b : "<< individus[i].ADN.genes_int.at(1) << endl;
				//cout << " = " <<individus[i].getNoteEvaluation()<< endl;
				if (ee.getTypeGenes() == 1)
					score_totale += individus[i].getNoteEvaluation();
				else if (ee.getTypeGenes() == 2)
					score_totale_d += individus[i].getNoteEvaluationFlottant();
				else if (ee.getTypeGenes() == 3)
					score_totale += individus[0].convertionVersDecimale(individus[i].getNoteEvaluation());
			}
			//op.tri_fusion_decroissant(&individus, 0, ee.getTaillePopulation()-1);
			evaluation e = evaluation (ee.getChaineEvaluation());
			if (ee.getTypeGenes() == 1){
				for(int i= 0; i< individus.size(); i++)
					cout << individus[i].getNoteEvaluation()<<endl;
				meilleur_premier = individus[0].getNoteEvaluation();
				score_totale = score_totale/individus.size();
				arret = e.testArret(score_totale,ee.getGenerationSatisfaisante(), ee.getMaximisationMinimisation());
				meillleur_individu.push_back(individus.at(0).getNoteEvaluation());
				score_total.push_back(score_totale);
			}
			if (ee.getTypeGenes() == 2){
				for(int i= 0; i< individus.size(); i++)
					cout << individus[i].getNoteEvaluationFlottant()<<endl;
				meilleur_premier_d = individus[0].getNoteEvaluationFlottant();
				score_totale_d = score_totale_d/individus.size();
				arret = e.testArret(score_totale_d,ee.getGenerationSatisfaisanteFlottant(), ee.getMaximisationMinimisation());
				meillleur_individu_d.push_back(individus.at(0).getNoteEvaluationFlottant());
				score_total_d.push_back(score_totale_d);
			}
			else if (ee.getTypeGenes() == 3){	
				for(int i= 0; i< individus.size(); i++)
					cout << individus[i].getNoteEvaluation()<<endl;
				meilleur_premier = individus[0].getNoteEvaluation();
				score_totale = individus[0].conversionVersBinaire(score_totale/individus.size());
				arret = e.testArret(score_totale,ee.getGenerationSatisfaisante(), ee.getMaximisationMinimisation());
				meillleur_individu.push_back(individus.at(0).getNoteEvaluation());
				score_total.push_back(score_totale);
			}	
		}
		if (arret) break;
	//-------------------------Sélection---------------
	if (ee.getChoixSelection() == 1)
		op.selectionParRang();
	/*else if (ee.getChoixSelection() == 2)// modifier reel-------
		{
			op.selectionParTournoi();
		}
	else if (ee.getChoixSelection() == 3)//modifier reel--------
		{
			op.selectionParRoulette();
		}*/
		
	//-------------------------Croisement---------------
	cout<<"----------------------------------------------------------------\n";
	if ((ee.getTypeGenes() == 1) || (ee.getTypeGenes() == 3))
	score_totale = 0;
	else if (ee.getTypeGenes() == 2)
	score_totale_d = 0;
	op.croisement(ee.getTauxCroisement(), ee.getTauxMutation(), ee.getTaillePopulation(), ee.getChaineEvaluation());
		for (int i = 0; i< individus.size(); i++){
			evaluation e = evaluation (ee.getChaineEvaluation());
			e.evaluer(&individus[i]);
			if (ee.getTypeGenes() == 1){
				score_totale += individus[i].getNoteEvaluation();
			}
			else if (ee.getTypeGenes() == 2){
				score_totale_d += individus[i].getNoteEvaluationFlottant();
			}
			else if (ee.getTypeGenes() == 3)
				score_totale += individus[0].convertionVersDecimale(individus[i].getNoteEvaluation());
		}	
		evaluation e2 = evaluation (ee.getChaineEvaluation());
		if (ee.getTypeGenes() == 1){
			arret = e2.testArret(score_totale/individus.size(),ee.getGenerationSatisfaisante(), ee.getMaximisationMinimisation());
			score_total.push_back(score_totale/individus.size());
				meillleur_individu.push_back(individus.at(0).getNoteEvaluation());
				cout << "generation : "<< compteur_generation << " : "<<score_total[compteur_generation]<<endl;
		}
		else if (ee.getTypeGenes() == 2){
			arret = e2.testArret(score_totale_d/individus.size(),ee.getGenerationSatisfaisanteFlottant(), ee.getMaximisationMinimisation());
			score_total_d.push_back(score_totale_d/individus.size());
			meillleur_individu_d.push_back(individus.at(0).getNoteEvaluationFlottant());
			cout << "generation : "<< compteur_generation << " : "<<score_total_d[compteur_generation]<<endl;
		}
		else if (ee.getTypeGenes() == 3){
			arret = e2.testArret(individus[0].conversionVersBinaire(score_totale/individus.size()),ee.getGenerationSatisfaisante(), ee.getMaximisationMinimisation());
			score_total.push_back(individus[0].conversionVersBinaire(score_totale/individus.size()));
			meillleur_individu.push_back(individus.at(0).getNoteEvaluation());
			cout << "generation : "<< compteur_generation << " : "<<score_total[compteur_generation]<<endl;
		}
			compteur_generation++;
			if (arret) break;
			//op.tri_fusion_decroissant(&individus, 0, individus.size()-1);
			if ((ee.getTypeGenes() == 1) || (ee.getTypeGenes() == 3))
				for(int i= 0; i< individus.size(); i++)
					cout << individus[i].getNoteEvaluation()<<endl;
			//else if (ee.getTypeGenes() == 2)
				//for(int i= 0; i< individus.size(); i++)
					//cout << individus[i].getNoteEvaluationFlottant()<<endl;
					
	
	}
	if ((ee.getTypeGenes() == 1) || (ee.getTypeGenes() == 3)){
		cout << "score génération 0 : "<<  score_total[0]<<endl;
		cout << "score génération : "<<compteur_generation<<" : "<<  score_total[compteur_generation]<<endl;
		ee.setNoteMoyenne(score_total);
		ee.setMeilleurIndividu(meillleur_individu);
		ee.genererLatex(&individus, "Statistiques.txt");
	}
	else if (ee.getTypeGenes() == 2){
		cout << "score génération 0 : "<<  score_total_d[0]<<endl;
		cout << "score génération  : "<<compteur_generation<<" : "<<  score_total_d[compteur_generation]<<endl;
		ee.setNoteMoyenneFlottant(score_total_d);
		ee.setMeilleurIndividuFlottant(meillleur_individu_d);
		ee.genererLatex(&individus, "Statistiques.txt");
	}
cout << "Voulez vous sauvegarder la configuration  : \n"<<endl;
cout << "1 : Oui\n"<<endl;
cout << "2 : Non\n"<<endl;
cout << "Réponse : ";
int rep = 0;
cin >> rep; 
if (rep == 1) ee.sauvegarde("configuration3.txt", &individus);
return 0;
}







