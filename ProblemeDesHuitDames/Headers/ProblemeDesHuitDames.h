#include "individu.h"

class ProblemeDesHuitDames{
	public 
	ProblemeDesHuitDames(individu* individu_x);
	void detection_positions();
	void generation_echiquier();
	void verification_solution();
	int getGene1Ligne();
	int getGene2Ligne();
	int getGene3Ligne();
	int getGene4Ligne();
	int getGene5Ligne();
	int getGene6Ligne();
	int getGene7Ligne();
	int getGene8Ligne();
	void setGene1Ligne(int valeur);
	void setGene2Ligne(int valeur);
	void setGene3Ligne(int valeur);
	void setGene4Ligne(int valeur);
	void setGene5Ligne(int valeur);
	void setGene6Ligne(int valeur);
	void setGene7Ligne(int valeur);
	void setGene8Ligne(int valeur);
	
	int** echiquier;
	individu* individu_x;
	private 
	int gene_1_ligne;
	int gene_2_ligne;
	int gene_3_ligne;
	int gene_4_ligne;
	int gene_5_ligne;
	int gene_6_ligne;
	int gene_7_ligne;
	int gene_8_ligne;
	int gene_1_colonne;
	int gene_2_colonne;
	int gene_3_colonne;
	int gene_4_colonne;	
	int gene_5_colonne;
	int gene_6_colonne;
	int gene_7_colonne;
	int gene_8_colonne;	
};
