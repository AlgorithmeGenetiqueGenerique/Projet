#ifndef PIECE_H
#define PIECE_H

#include <QGraphicsPixmapItem>
#include "BoxEchiquier.h"
#include <QPixmap>

#include <QGraphicsSceneMouseEvent>

class BoxEchiquier;
class Piece:public QGraphicsPixmapItem
{
public:
    Piece(QString Jeu="",QGraphicsItem *parent = 0);

    void setBoxActuel(BoxEchiquier *box);
    BoxEchiquier *getBoxActuel() ;
    void setImagePiece();

protected:
    BoxEchiquier *Box;
    QString Jeu;

};

#endif // CHESSPIECE_H
