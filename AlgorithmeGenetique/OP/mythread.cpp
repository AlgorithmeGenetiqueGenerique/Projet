#include "mythread.h"
#include <QtCore>
#include <QDebug>

myThread::myThread(QObject *parent):
    QThread(parent)
{
}

void myThread::run()
{
    if(!Stop)
    {
        for(int i=count;i<=iteration;i++)
        {
            QMutex mutex;
            mutex.lock();
            qDebug()<<"thread on marche"<<Stop;
            qDebug()<<"-------->"<<iteration;
            if(Stop)
                break;

            emit txtEdt(i);
            mutex.unlock();
            this->msleep(300);
        }
    }



}
