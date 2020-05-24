#ifndef BOX_H
#define BOX_H

#include <QGraphicsRectItem>
#include <QBrush>
#include "Piece.h"
#include <QGraphicsSceneMouseEvent>

class Piece;
class BoxEchiquier:public QGraphicsRectItem
{
public:


    BoxEchiquier(QGraphicsItem *parent=0);
    ~BoxEchiquier();



    void placePiece(Piece *piece);
    void setCouleur(QColor Valeur);

    int ligne;
    int collone;
    Piece * PieceActuel;
    private:
    QBrush brush;
    QColor Couleur;


};

#endif // CHESSBOX_H
