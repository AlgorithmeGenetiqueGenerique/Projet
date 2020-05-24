#ifndef MYTHREAD_H
#define MYTHREAD_H
#include <QtCore>
#include <QThread>

class myThread : public QThread
{
    Q_OBJECT
public:
    myThread(QObject *parent=nullptr);
    void run();
    bool Stop;
    int count;
    int iteration;

public slots:


signals:
    void  txtEdt(int);
    void p(int);


};

#endif // MYTHREAD_H
