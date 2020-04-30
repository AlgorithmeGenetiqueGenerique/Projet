#include "gene.h"
#include <iostream>
gene::gene(){
	genes_int.clear();
	genes_double.clear();
}

gene::gene(int type_genes, int min_intervalle, int max_intervalle, int nombre_genes){
	this->type_genes = type_genes;
	genes_int.clear();
	genes_double.clear();
	this->min_intervalle = min_intervalle;
	this->max_intervalle = max_intervalle;
	this->nombre_genes = nombre_genes;
}
gene::gene(int type_genes, double min_intervalle, double max_intervalle, int nombre_genes){
	this->type_genes = type_genes;
	genes_int.clear();
	genes_double.clear();
	this->min_intervalle_flottant = min_intervalle;
	this->max_intervalle_flottant = max_intervalle;
	this->nombre_genes = nombre_genes;
}

int gene::getTypeGenes(){
	return type_genes;
}
void gene::setTypeGenes(int type_genes){
	this->type_genes = type_genes;
}

void gene::setGenes(int genes){
	genes_int.push_back(genes);
}

void gene::setGenes(double genes){
	genes_double.push_back(genes);
}

int gene::getMinIntervalle(){
	return min_intervalle;
}
int gene::getMaxIntervalle(){
	return max_intervalle;
}
double gene::getMinIntervalleFlottant(){
	return min_intervalle_flottant;
}
double gene::getMaxIntervalleFlottant(){
	return max_intervalle_flottant;
}

int gene::getNombreGenes(){
	return nombre_genes;
}

void gene::setNombreGenes(int nombre_genes){
	this->nombre_genes = nombre_genes;
}

void gene::setMinIntervalleFlottant(double min_intervalle){
	this->min_intervalle_flottant = min_intervalle;
}
void gene::setMaxIntervalleFlottant(double max_intervalle){
	this->max_intervalle_flottant = max_intervalle;
}
void gene::setMinIntervalle(int min_intervalle){
	this->min_intervalle = min_intervalle;
}
void gene::setMaxIntervalle(int max_intervalle){
	this->max_intervalle = max_intervalle;
}
gene::~gene(){
}
