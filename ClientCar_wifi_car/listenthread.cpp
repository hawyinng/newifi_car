#include "listenthread.h"

ListenThread::ListenThread()
{
    this->start();
}

ListenThread::ListenThread(QString ip)
{
    this->stopped = false;
    this->plan->set_routerIP(ip);
    this->start();
}

void ListenThread::run()
{
    while(!stopped)
    {
        switch(isPlan)
        {
           case 1:
             plan->openConn();
             qDebug() << "ListenThread openConn...";
             isPlan = 0;
             break;
           case 2:
             plan->closeConn();
             isPlan = 0;
             break;
           case 7:
             qDebug() << "ListenThread make_stop...";
             plan->make_stop();
             isPlan = 0;
             break;
        }
    }
}

void ListenThread::setPlan(int i)
{
    this->startThread();
    mutex.lock();
    switch(i)
    {
        case 1:
          isPlan = 1;
          qDebug() << "ListenThread setPlan 1...";
          break;
        case 2:
          isPlan = 2;
          break;
        case 7:
          isPlan = 7;
          break;
    }
    mutex.unlock();
}
