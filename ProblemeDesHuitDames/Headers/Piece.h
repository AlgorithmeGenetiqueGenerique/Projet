#include <QGraphicsPixmapItem>
#include <QGraphicsSceneMouseEvent>
#include "BoxEchiquier.h"
class Piece:public QGraphicsPixmapItem
{
public:
    Piece(QGraphicsItem *parent = 0);
    ~Piece()
    void setBoxActuelle(BoxEchiquier *box);
    BoxEchiquier *getBoxActuelle();
    void setImagePiece();

protected:
    BoxEchiquier *Box;
};
