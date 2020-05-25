
#include <Queen/InterfaceQueen.h>
#include <OP/mythread.h>
#include <mainwindow1.h>
#include <QApplication>
#include "OP/modelisationprblm.h"
using namespace std;




InterfaceQueen *game;

int main(int argc, char *argv[])
{        QApplication app(argc, argv);



        //QString locale = QLocale::system().name();



        //QTranslator translator;

        //translator.load(QString("Accueil") + locale);
        //app.installTranslator(&translator);

        ModelisationPrblm rambele;
       // MainWindow1 mainWindow1;
        //mainWindow1.show();
         rambele.show();


        return app.exec();
}















