#include "interface.h"

int main(int argc, char* argv[]){

    QApplication app(argc, argv);
    srand(unsigned(time(NULL)));
    qsrand(QTime(0,0,0).secsTo(QTime::currentTime()));
    voyageurDeCommerceInterface *interface = new voyageurDeCommerceInterface();
    interface->show();
    return app.exec();
}