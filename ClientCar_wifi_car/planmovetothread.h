#ifndef PLANMOVETOTHREAD_H
#define PLANMOVETOTHREAD_H

#include <QObject>
#include <QThread>
#include "plantest.h"

class PLanMoveToThread : public QObject
{
    Q_OBJECT
public:
    explicit PLanMoveToThread(QObject *parent = nullptr);

public:
    PlanTest *plan;
    QThread *thread;

signals:

public slots:
    int openfile();
    int openConn();
    void closeConn();
    void make_up();
    void make_down();
    void make_left();
    void make_right();
    void make_stop();

    void choose_plan(int id);
    void make_planA();
    void make_planB();
    void make_planC();
};

#endif // PLANMOVETOTHREAD_H
