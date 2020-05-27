#include "BoxEchiquier.h"
#include "InterfaceQueen.h"
#include <QDebug>

extern InterfaceQueen *game;
BoxEchiquier::BoxEchiquier():QGraphicsRectItem()
{
    //making the Square CHess Box
    setRect(0,0,100,100);
    brush.setStyle(Qt::SolidPattern);
    setZValue(-1);

    PieceActuel = NULL;
}

BoxEchiquier::~BoxEchiquier()
{
    delete this;
}


void BoxEchiquier::setCouleur(QColor Valeur)
{
    brush.setColor(Valeur);
    setBrush(Valeur);
}

void BoxEchiquier::placePiece(Piece *piece)
{

    piece->setPos(x()+50- piece->pixmap().width()/2  ,y()+50-piece->pixmap().width()/2);
    piece->setBoxActuel(this);
    PieceActuel = piece;

}


