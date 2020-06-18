#ifndef LISTENTHREAD_H
#define LISTENTHREAD_H

#include <QObject>
#include "plantest.h"
#include <QThread>
#include "planthread.h"
#include <QMutex>

class ListenThread : public PlanThread
{
    Q_OBJECT

public:
    ListenThread();
    ListenThread(QString ip);

private:
    volatile bool stopped;
    QMutex mutex;

protected:
    void run();

public slots:
    void setPlan(int i);

};

#endif // LISTENTHREAD_H
