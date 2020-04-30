#include <QGraphicsRectItem>
#include <QBrush>
#include <QGraphicsSceneMouseEvent>
#include "piece.h"
class Piece;
class BoxEchiquier:public QGraphicsRectItem
{
public:
    BoxEchiquier(QGraphicsItem *parent=0);
    ~BoxEchiquier();

    void placePiece(Piece *piece);
    QColor getCouleur();
    void setCouleur(QColor Valeur);
    int getLigne();
    int getColonne();
    void setLigne();
    void setColonne();
    
    Piece * PieceActuel;
    private:
    int ligne;
    int colonne;
    QBrush brush;
    QColor Couleur;
};
