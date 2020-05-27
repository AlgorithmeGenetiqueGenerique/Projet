#include "Echiquier.h"
#include "BoxEchiquier.h"
#include "InterfaceQueen.h"
#include "Piece.h"

extern InterfaceQueen *game;
Echiquier::Echiquier()
{
    setPiece();

}
void Echiquier::Dessiner_box(int x,int y)
{
    int SHIFT = 100;
    for(int i = 0; i < 8; i++) {
        for(int j = 0; j < 8; j++)
        {
            BoxEchiquier *box = new BoxEchiquier();
            game->collection[i][j] = box;
            box->ligne = i;
            box->collone = j;
            box->setPos(x+SHIFT*j,y+SHIFT*i);
            if((i+j)%2==0)
                box->setCouleur(Qt::white);
            else
                box->setCouleur(Qt::black);
            game->AjouterSurScene(box);



        }
    }

}
void Echiquier::reset()
{
       for(int i = 0; i < 8; i++) {
           game->removeFromScene(Pieces[i]);
              }
}

void Echiquier::AjouterPiece(int **echiquier)
{

int f=0;

        for(int x = 0; x < 8; x++)
        {



        for(int j=0;j<8;j++)
        {
            if(echiquier[x][j]==1)
         {
          BoxEchiquier *box =game->collection[x][j];
          box->placePiece(Pieces[f]);
          game->AjouterSurScene(Pieces[f]);f++;
         }
        }


        }

}



void Echiquier::setPiece()
{



    for(int i = 0; i < 8; i++) {
        piece[i] = new Piece();
        Pieces.append(piece[i]);
    }

}

