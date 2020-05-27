#include "ProblemeDesHuitDames.h"
#include <iostream>
#include <QDebug>
#include <QString>

ProblemeDesHuitDames::ProblemeDesHuitDames(individu* individu_x_att){

	individu_x = individu_x_att;
	
}

void ProblemeDesHuitDames::verification_solution(){

    int i,j,x,note_individu=0;
    int note=0;
    for(i=0; i<8; i++){

        
		
        //Check vertical et horizontal
        for(j=0;j<8;j++)
        {     

            if(j!=i)
            {
            if(gene[i][0] == gene[j][0] || gene[i][1]== gene[j][1])
            {
                note++;
                note_individu++;
			}
			}
        }
        //check diagonales 
        for(x=1;gene[i][0]-x >= 0 || gene[i][1]-x >= 0;x++)
        {
            for(j=0;j<8;j++){
                if(gene[i][0]-x == gene[j][0] && gene[i][1]-x == gene[j][1])
                {
                    note++;
                    note_individu++;
				}
            }
        }
        for(x=1;gene[i][0]+x <= 7 || gene[i][1]-x >= 0;x++){
            for(j=0;j<8;j++){
                if(gene[i][0]+x == gene[j][0] && gene[i][1]-x == gene[j][1])
                {
                    note++;
                    note_individu++;
				}
				}
        }
        for(x=1; gene[i][0]-x >=0 || gene[i][0]+x<=7; x++){
            for(j=0;j<8;j++){
                if(gene[i][0]-x == gene[j][0] && gene[i][1]+x == gene[j][1])
                   {
                    note++;
                    note_individu++;
				}
            }
        }
        for(x=1;gene[i][0]+x <= 7 || gene[i][0]+x <= 7 ;x++){
            for(j=0;j<8;j++){
                if(gene[i][0]+x == gene[j][0] && gene[i][1]+x == gene[j][1])
                   {
                    note++;
                    note_individu++;
				}
            }
        }
        individu_x->ADN.genes_int[i]=gene[i][0]*100+gene[i][1]*10+note_individu;
    note_individu=0;
    }
    
}

void ProblemeDesHuitDames::detection_position(int a)
{

    int i;
    for(i=0;i<8;i++)
    {
        if (a==1)
        {   int inter= individu_x->ADN.genes_int[i]/10;
            gene[i][0] = inter/10;
            gene[i][1] = inter%10;
        }
        else
        {
        gene[i][0] = i;
        gene[i][1] = individu_x->ADN.genes_int[i]/8;
        }

    }
}

void ProblemeDesHuitDames::generation_echiquier(){

    int i,j;
    echiquier = (int**) malloc(sizeof(*echiquier) * 8);
    for (i=0;i<8;i++){
        echiquier[i] = (int*)malloc(sizeof(**echiquier)*8);
    }
     for(i=0;i<8;i++)
     {
        for(j=0;j<8;j++)
        {
            echiquier[i][j]=0;
        }
    }
    for(i=0;i<8;i++){
        int x = gene[i][0];
        int y = gene[i][1];
        echiquier[x][y]=1;
    }
}
 int ** ProblemeDesHuitDames::getech()
 {
     return echiquier;
 }
void ProblemeDesHuitDames::printSolution()
{
	        printf("\n");

    for (int i = 0; i < 8; i++) {
        for (int j = 0; j < 8; j++)
            qDebug()<< QString::number(echiquier[i][j]);
        qDebug() <<"\n" ;
    }
}
