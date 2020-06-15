#include "listenthread.h"

ListenThread::ListenThread()
{
    this->start();
}

void ListenThread::setPlan(int i)
{
    this->startThread();
    switch(i)
    {
        case 1:
          isPlan = 1;
          break;
        case 2:
          isPlan = 2;
          break;
        case 7:
          isPlan = 7;
          break;
    }
}
