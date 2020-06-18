#ifndef PLANTHREAD_H
#define PLANTHREAD_H

#include <QObject>
#include "plantest.h"
#include <QThread>
#include <QMutex>

//#include <QAndroidJniObject>

class PlanThread : public QThread
{
   Q_OBJECT

public:
    PlanThread();
    PlanThread(QString ip);

#ifndef WINDOWS
    //QAndroidJniObject thread;
#endif

    PlanTest *plan;
    int isPlan;

    //QAndroidJniObject thread;

    void isStop(bool stopped);
    bool getStopped();
    void startThread();

protected:
    void run();

private:
    volatile bool stopped;
    QMutex mutex;

public slots:

    void openConn();
    void closeConn();
    void setPlan(int i);
    void stopThread();

};

#endif // PLANTHREAD_H
