#ifndef CLIENTDIALOG_H
#define CLIENTDIALOG_H

//#define WINDOWS

#ifdef WINDOWS
    #include <QMessageBox>
#endif

#include <QMainWindow>
#include <QCloseEvent>
#include "plantest.h"
#include <QButtonGroup>
#include <QThread>
#include "planmovetothread.h"
#include "planthread.h"
#include "listenthread.h"
#include <QtAndroid>

namespace Ui {
class Clientdialog;
}

class Clientdialog : public QMainWindow
{
    Q_OBJECT

public:
    explicit Clientdialog(QWidget *parent = 0);
    ~Clientdialog();

    QButtonGroup planBtnGroup;
    //PLanMoveToThread *planThread;
    PlanThread *planThread;
    ListenThread *lthread;

    bool noConnect = true;
    bool isBack = false;

signals:
    void checkedID(int id);
    void setPlanID(int i);
    void _setPlanID(int i);
    void setStop(bool stoped);
    void stopPthread();
    void stopLthread();
    void isstop(bool stop);
    void setIP(QString ip);

public slots:
    int openConn();
    int closeConn();

    void make_up();
    void make_down();
    void make_left();
    void make_right();
    void make_stop();

    void plan_run();
    void plan_stop();

    void errRWBuff(const int i);
    void recvbuff(QString str);

    void errOpenfile(int i);
    void retOpenConn(int i);
    void retCloseConn(int i);

private slots:
    void on_pushButton_up_pressed();

    void on_pushButton_down_pressed();

    void on_pushButton_left_pressed();

    void on_pushButton_right_pressed();

    void on_pushButton_up_released();

    void on_pushButton_down_released();

    void on_pushButton_left_released();

    void on_pushButton_right_released();

    void on_radioButton_clicked();

    void on_Clientdialog_destroyed();

    void closeEvent(QCloseEvent *event);

    void init_lineEdit_IP();

    void on_pushButton_modify_pressed();

    void on_pushButton_save_pressed();

    void open_file();
    void save_file();

    bool checkPermission();

private:
    Ui::Clientdialog *ui;
};

#endif // CLIENTDIALOG_H
