#include "Piece.h"
#include "InterfaceQueen.h"
#include <QDebug>

extern InterfaceQueen *Queen;
Piece::Piece(QString Jeu):QGraphicsPixmapItem()
{
    Jeu="Reine";
 setImagePiece();
}
void Piece::setImagePiece()
{
        setPixmap(QPixmap(":images/queen.png"));
}

void Piece::setBoxActuel(BoxEchiquier *box)
{

    Box = box;
}

BoxEchiquier *Piece::getBoxActuel()
{
    return Box;
}




