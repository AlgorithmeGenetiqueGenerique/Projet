#ifndef BOUTON_H
#define BOUTON_H
#include <QGraphicsSceneMouseEvent>
#include <QGraphicsRectItem>
#include <QBrush>


class Bouton:public QObject, public QGraphicsRectItem
{
     Q_OBJECT
public:

    Bouton(QString name);

    //public methods
    void mousePressEvent(QGraphicsSceneMouseEvent *event);

signals:
    void clicked();
private:
    QBrush brush;
    QGraphicsTextItem *text;
};
#endif // BUTTON_H
