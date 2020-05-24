#ifndef ECHIQUIER_H
#define ECHIQUIER_H
#include <QGraphicsRectItem>
#include "Piece.h"
class Echiquier
{
public:
    Echiquier();
    ~Echiquier();
    //drawing public function
    void Dessiner_box(int x, int y);
    void setPiece();QList <Piece *> Pieces;
    void AjouterPiece(int i,int **echiquier);
    void reset(QGraphicsScene *scene_du_jeu);
private:


     Piece *piece[];


};

#endif // CHESSBOARD_H
