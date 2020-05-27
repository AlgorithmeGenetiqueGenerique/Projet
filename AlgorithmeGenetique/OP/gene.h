#ifndef GENE_H
#define GENE_H

#include <vector>

class gene
{
    public:
    //Constructeur par défaut
    gene();
    //Constructeur utiliser pour les gènes de type entier ou binaire
    gene(int type_genes, int min_intervalle, int max_intervalle, int nombre_genes);
    //Constructeur  utiliser pour les gènes de type flottant
    gene(int type_genes, double min_intervalle, double max_intervalle, int nombre_genes);
    //déstructeur
    ~gene();
	int getTypeGenes();
	void setTypeGenes(int type_genes);
	
	void setGenes(int genes);
	void setGenes(double genes);
	
	int getMinIntervalle();
	int getMaxIntervalle();
	double getMinIntervalleFlottant();
	double getMaxIntervalleFlottant();
	
	void setMinIntervalle(int min_intervalle);
	void setMaxIntervalle(int max_intervalle);
	void setMinIntervalleFlottant(double min_intervalle);
	void setMaxIntervalleFlottant(double max_intervalle);

	int getNombreGenes();
	void setNombreGenes(int nombre_genes);

    //contenant des gènes du type entier ou du type binaire
	std::vector<int> genes_int;
    //contenant des gènes du type ﬂottant
	std::vector<double> genes_double;
	
    private:
    int type_genes;
    int nombre_genes;
    int min_intervalle;
    int max_intervalle;
    double min_intervalle_flottant;
    double max_intervalle_flottant;
};
#endif // GENE_H
