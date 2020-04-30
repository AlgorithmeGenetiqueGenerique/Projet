#include <QGraphicsRectItem>
#include "piece.h"
class Echiquier
{
public:
    Echiquier();
    ~Echiquier()
    void Dessiner_box(int x, int y);
    void setPiece();
    void AjouterPiece();
    void reset();
private:
    QList <Piece *> Piece;
};
