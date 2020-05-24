#include "bouton.h"
#include <QGraphicsTextItem>

Bouton::Bouton(QString name, QGraphicsItem *parent)
    :QGraphicsRectItem(parent)
{
    //draw the rect
    setRect(0,0,200,25);

    brush.setStyle(Qt::SolidPattern);
    brush.setColor(Qt::white);
    setBrush(brush);

    //draw Text
    text = new QGraphicsTextItem(name,this);
    int xPos = rect().width()/2 - text ->boundingRect().width()/2;
    int yPos = rect().height()/2 - text ->boundingRect().height()/2;
    text->setPos(xPos,yPos);
    text->setDefaultTextColor(Qt::black);

    //Allow responding to hover
    setAcceptHoverEvents(true);
}

void Bouton::mousePressEvent(QGraphicsSceneMouseEvent *event)
{
    if(event)
    emit clicked();

}



