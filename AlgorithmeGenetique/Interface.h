#ifndef INTERFACE_H
#define INTERFACE_H

#include <QWidget>

QT_BEGIN_NAMESPACE
class QPushButton;
QT_END_NAMESPACE


class Interface : public QWidget

{


public:
    Interface(QWidget *parent = 0);
    QPushButton *voyageur;
    QPushButton *modelisation;
    QPushButton *huits_dame;
    QPushButton *quitter;
private:

  //  QPushButton *aide;
};

#endif
