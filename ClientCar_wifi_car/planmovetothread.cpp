#include "planmovetothread.h"

PLanMoveToThread::PLanMoveToThread(QObject *parent) : QObject(parent)
{
    this->plan = new PlanTest;

    this->thread = new QThread;
    this->moveToThread(thread);
    thread->start();
}

int PLanMoveToThread::openfile()
{
    if(plan->openfile()<0)
        return -1;
    else
        return 0;
}

int PLanMoveToThread::openConn()
{
    if(plan->openConn()<0)
        return -1;
    else
        return 0;
}

void PLanMoveToThread::closeConn()
{
    plan->closeConn();
}

void PLanMoveToThread::make_up()
{
    if(plan->p_connect)
        plan->make_up();
}

void PLanMoveToThread::make_down()
{
    if(plan->p_connect)
        plan->make_down();
}

void PLanMoveToThread::make_right()
{
    if(plan->p_connect)
        plan->make_right();
}

void PLanMoveToThread::make_left()
{
    if(plan->p_connect)
        plan->make_left();
}

void PLanMoveToThread::make_stop()
{
    if(plan->p_connect){
        this->thread->quit();
        this->thread->wait();
        plan->make_stop();
    }
}

void PLanMoveToThread::choose_plan(int id)
{
    int ID = id;
    if(plan->p_connect){
        switch(ID)
        {
           case 0:
             plan->make_planA();
             break;
           case 1:
             plan->make_planB();
             break;
           case 2:
             plan->make_planC();
             break;
        }
    }
}

void PLanMoveToThread::make_planA()
{
    if(plan->p_connect)
        plan->make_planA();
}

void PLanMoveToThread::make_planB()
{
    if(plan->p_connect)
        plan->make_planB();
}

void PLanMoveToThread::make_planC()
{
    if(plan->p_connect)
        plan->make_planC();
}
