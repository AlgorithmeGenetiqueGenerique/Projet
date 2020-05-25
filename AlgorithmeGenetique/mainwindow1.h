#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>
//#include "InterfaceQueen.h"

QT_BEGIN_NAMESPACE
class QAction;
class QMenu;
QT_END_NAMESPACE
class Interface;


class MainWindow1 : public QMainWindow

{
    Q_OBJECT


public:
    MainWindow1();
public slots:
    void huits_dames();
    void modeli();
    void voyageur();
    void fermer();
private:
    Interface *accueil;
    QMenu *fileMenu;
    QAction *exitAct;
};

#endif
