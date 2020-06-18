#include "planthread.h"
#include "clientdialog.h"

#ifndef WINDOWS
//#include <QAndroidJniEnvironment>
//#include <QAndroidJniObject>
#endif

PlanThread::PlanThread()
{
    this->plan = new PlanTest;
    this->stopped = false;
    this->isPlan = 0;
    this->start();
}

PlanThread::PlanThread(QString ip){
    this->plan = new PlanTest;
    this->plan->set_routerIP(ip);
    this->stopped = false;
    this->isPlan = 0;
    this->start();
}

void PlanThread::startThread()
{
    if (!this->isRunning())
    {
        this->isStop(false);
        this->start();
    }
}

void PlanThread::stopThread()
{
#ifdef WINDOWS
    this->terminate();
    this->wait();
#else
    /*
    QAndroidJniObject thread =
               QAndroidJniObject::callStaticObjectMethod(
                    "java/lang/Thread", "currentThread",
                     "()Ljava/lang/Thread;");
    thread.callMethod<void>("stop");
    QAndroidJniObject stringJinObj = thread.callObjectMethod<jstring>("getName");
    qDebug() << "thread name: " << stringJinObj.toString();
    thread.callMethod<void>("interrupt");
    this->isStop(true);
    */
    //childThread->terminate();
    //childThread->exit(0);
    this->terminate();
    this->isInterruptionRequested();
#endif
}

void PlanThread::openConn()
{
    plan->openConn();
}

void PlanThread::closeConn()
{
    plan->closeConn();
}

void PlanThread::isStop(bool stoped)
{
    mutex.lock();
    stopped = stoped;
    mutex.unlock();
}

bool PlanThread::getStopped(){
    return stopped;
}

void PlanThread::run()
{
#ifndef WINDOWS
    /*
    thread = QAndroidJniObject::callStaticObjectMethod(
                    "java/lang/Thread", "currentThread",
                     "()Ljava/lang/Thread;");
    QAndroidJniObject stringJinObj = thread.callObjectMethod<jstring>("getName");
    qDebug() << "thread name: " << stringJinObj.toString();
    */
    //thread.callMethod<void>("interrupt");
#endif
    while(!stopped)
    {
        switch(isPlan)
        {
           case 1:
             qDebug() << "PlanThread openConn...";
             plan->openConn();
             isPlan = 0;
             break;
           case 2:
             qDebug() << "PlanThread closeConn...";
             plan->closeConn();
             isPlan = 0;
             break;
           case 3:
             plan->make_up();
             isPlan = 0;
             break;
           case 4:
             plan->make_down();
             isPlan = 0;
             break;
           case 5:
             plan->make_left();
             isPlan = 0;
             break;
           case 6:
             plan->make_right();
             isPlan = 0;
             break;
           case 7:
             qDebug() << "PlanThread make_stop...";
             plan->make_stop();
             isPlan = 0;
             break;
           case 8:
             plan->make_left_back();
             break;
           case 9:
             plan->make_right_back();
             break;
           case 10:
             plan->make_planA();
             isPlan = 0;
             break;
           case 11:
             plan->make_planB();
             isPlan = 0;
             break;
           case 12:
             plan->make_planC();
             isPlan = 0;
             break;
           case 13:
             plan->make_up_press();
             break;
           case 14:
             plan->make_down_press();
             break;
           case 15:
             plan->make_left_press();
             break;
           case 16:
             plan->make_right_press();
             break;
        }
    }
}

void PlanThread::setPlan(int i)
{
    startThread();
    mutex.lock();
    switch(i)
    {
       case 1:
         isPlan = 1;
         break;
       case 2:
         isPlan = 2;
         break;
       case 3:
         isPlan = 3;
         break;
       case 4:
         isPlan = 4;
         break;
       case 5:
         isPlan = 5;
         break;
       case 6:
         isPlan = 6;
         break;
       case 7:
         isPlan = 7;
         break;
       case 8:
         isPlan = 8;
         break;
       case 9:
         isPlan = 9;
         break;
       case 10:
         isPlan = 10;
         break;
       case 11:
         isPlan = 11;
         break;
       case 12:
         isPlan = 12;
         break;
       case 13:
         isPlan = 13;
         break;
       case 14:
         isPlan = 14;
         break;
       case 15:
         isPlan = 15;
         break;
       case 16:
         isPlan = 16;
         break;
    }
    mutex.unlock();
}
