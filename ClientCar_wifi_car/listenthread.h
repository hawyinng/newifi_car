#ifndef LISTENTHREAD_H
#define LISTENTHREAD_H

#include <QObject>
#include "plantest.h"
#include <QThread>
#include "planthread.h"

class ListenThread : public PlanThread
{
    Q_OBJECT

public:
    ListenThread();

public slots:
    void setPlan(int i);

};

#endif // LISTENTHREAD_H
