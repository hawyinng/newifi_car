#include "clientdialog.h"
#include "ui_clientdialog.h"
#include <QDebug>
#include "plantest.h"

Clientdialog::Clientdialog(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::Clientdialog)
{
    setFixedSize(1080, 1920);
    //setFixedSize(600, 800);
    //this->resize(this->width(), this->height());
    ui->setupUi(this);

    this->planBtnGroup.addButton(ui->radioPlan1, 0);
    this->planBtnGroup.addButton(ui->radioPlan2, 1);
    this->planBtnGroup.addButton(ui->radioPlan3, 2);

    ui->radioPlan1->setChecked(true);
    ui->closeButton->setDisabled(true);
    ui->planRun->setDisabled(false);
    ui->planStop->setDisabled(true);

    this->planThread = new PlanThread;
    this->lthread = new ListenThread;

    //connect(ui->connButton,SIGNAL(clicked()),planThread,SLOT(openConn()),Qt::QueuedConnection);
    //connect(ui->connButton,SIGNAL(clicked()),lthread,SLOT(openConn()),Qt::QueuedConnection);
    //connect(ui->closeButton,SIGNAL(clicked()),planThread,SLOT(closeConn()),Qt::QueuedConnection);

    connect(ui->pushButton_up,SIGNAL(clicked()),this,SLOT(make_up()),Qt::AutoConnection);
    connect(ui->pushButton_down,SIGNAL(clicked()),this,SLOT(make_down()),Qt::AutoConnection);
    connect(ui->pushButton_left,SIGNAL(clicked()),this,SLOT(make_left()),Qt::AutoConnection);
    connect(ui->pushButton_right,SIGNAL(clicked()),this,SLOT(make_right()),Qt::AutoConnection);
    connect(ui->pushButton_stop,SIGNAL(clicked()),this,SLOT(make_stop()),Qt::AutoConnection);

    connect(this,SIGNAL(setPlanID(int)),planThread,SLOT(setPlan(int)),Qt::AutoConnection);
    connect(this,SIGNAL(stopthread()),planThread,SLOT(stopThread()),Qt::AutoConnection);
    connect(this,SIGNAL(_setPlanID(int)),lthread,SLOT(setPlan(int)),Qt::AutoConnection);

    //connect(ui->planStop,SIGNAL(clicked()),this,SLOT(plan_stop()),Qt::QueuedConnection);
    //connect(ui->planRun,SIGNAL(clicked()),this,SLOT(plan_run()),Qt::QueuedConnection);

    connect(this->planThread->plan,SIGNAL(errReadWriteBuff(const int)),this,SLOT(errRWBuff(const int)),Qt::QueuedConnection);
    connect(this->planThread->plan,SIGNAL(recvBuff(QString)),this,SLOT(recvbuff(QString)),Qt::QueuedConnection);
    connect(this->planThread->plan,SIGNAL(errOpenFile(int)),this,SLOT(errOpenfile(int)),Qt::QueuedConnection);
    connect(this->planThread->plan,SIGNAL(recvOpenConn(int)),this,SLOT(retOpenConn(int)),Qt::QueuedConnection);
    connect(this->planThread->plan,SIGNAL(recvCloseConn(int)),this,SLOT(retCloseConn(int)),Qt::QueuedConnection);

}

Clientdialog::~Clientdialog()
{
    delete ui;
}

//打开连接
int Clientdialog::openConn()
{
    planThread->startThread();

    ui->connButton->setDisabled(true);
    ui->closeButton->setDisabled(false);

    emit setPlanID(1);
    emit _setPlanID(1);

    return 0;
}

//关闭连接
int Clientdialog::closeConn()
{
    ui->connButton->setDisabled(false);
    ui->closeButton->setDisabled(true);

#ifndef WINDOWS
    planThread->closeConn();
#endif
#ifdef WINDOWS
    emit setPlanID(2);
#endif

    return 0;
}

void Clientdialog::make_up()
{
    //emit setPlanID(3);
}

void Clientdialog::make_down()
{
    //emit setPlanID(4);
}

void Clientdialog::make_left()
{
    //emit setPlanID(5);
}

void Clientdialog::make_right()
{
    //emit setPlanID(6);
}

void Clientdialog::make_stop()
{
    //emit setPlanID(7);
}

void Clientdialog::plan_run()
{
   planThread->startThread();

   ui->planRun->setDisabled(true);
   ui->planStop->setDisabled(false);

   ui->connButton->setDisabled(true);
   ui->closeButton->setDisabled(true);

   switch(this->planBtnGroup.checkedId())
   {
      case 0:
        emit setPlanID(10);
        break;
      case 1:
        emit setPlanID(11);
        break;
      case 2:
        emit setPlanID(12);
        break;
   }

}

void Clientdialog::plan_stop()
{
#ifdef WINDOWS
    planThread->terminate();
#endif
#ifndef WINDOWS
    planThread->closeConn();
    emit stopthread();
#endif

    emit _setPlanID(7);
    ui->planRun->setDisabled(false);
    ui->planStop->setDisabled(true);
    ui->connButton->setDisabled(false);
    ui->closeButton->setDisabled(true);
}

void Clientdialog::errRWBuff(int i)
{
    switch(i)
    {
        case 0:
        #ifdef WINDOWS
            QMessageBox::warning(this, QString::fromLocal8Bit("发送数据"), QString::fromLocal8Bit("发送数据错误"));
        #endif
            break;
        case 1:
        #ifdef WINDOWS
            QMessageBox::warning(this, QString::fromLocal8Bit("接收数据"), QString::fromLocal8Bit("接收数据错误"));
        #endif
            break;
    }
}

void Clientdialog::recvbuff(QString buff)
{
    ui->textBrowser->insertPlainText(buff);
    ui->textBrowser->moveCursor(QTextCursor::End);
}

void Clientdialog::errOpenfile(int i)
{
    if(i == 0)
        ui->textBrowser->insertPlainText(QString::fromLocal8Bit("读取配置文件错误！"));
    if(i == 1)
        ui->textBrowser->insertPlainText(QString::fromLocal8Bit("读取配置文件成功。"));
}

void Clientdialog::retOpenConn(int i)
{
    switch(i)
    {
        case 0:
        #ifdef WINDOWS
            QMessageBox::warning(this, QString::fromLocal8Bit("网络错误"), QString::fromLocal8Bit("网络连接错误！"));
        #endif
            break;
        case 1:
            ui->textBrowser->insertPlainText( QString::fromLocal8Bit("网络连接成功...\n"));
            ui->textBrowser->moveCursor(QTextCursor::End);
            break;
    }
}

void Clientdialog::retCloseConn(int i)
{
    switch(i)
    {
        case 0:
        #ifdef WINDOWS
            QMessageBox::warning(this, QString::fromLocal8Bit("网络错误"), QString::fromLocal8Bit("网络连接错误！"));
        #endif
            break;
        case 1:
            ui->textBrowser->insertPlainText( QString::fromLocal8Bit("网络连接断开...\n"));
            ui->textBrowser->moveCursor(QTextCursor::End);
            break;
    }
}

void Clientdialog::on_pushButton_up_pressed()
{
    emit setPlanID(13);
}

void Clientdialog::on_pushButton_down_pressed()
{
    emit setPlanID(14);
}

void Clientdialog::on_pushButton_left_pressed()
{
    if(!isBack)
        emit setPlanID(15);
    if(isBack)
        emit setPlanID(8);
}

void Clientdialog::on_pushButton_right_pressed()
{
    if(!isBack)
        emit setPlanID(16);
    if(isBack)
        emit setPlanID(9);
}

void Clientdialog::on_pushButton_up_released()
{
    emit setPlanID(7);
}

void Clientdialog::on_pushButton_down_released()
{
    emit setPlanID(7);
}

void Clientdialog::on_pushButton_left_released()
{
    emit setPlanID(7);
}

void Clientdialog::on_pushButton_right_released()
{
    emit setPlanID(7);
}

void Clientdialog::on_radioButton_clicked()
{
    if(ui->radioButton->isChecked())
    {
        isBack = true;
        return;
    }
    if(!ui->radioButton->isChecked()){
        isBack = false;
        return;
    }
}

void Clientdialog::closeEvent(QCloseEvent *event)
{
    /*
    this->lthread->closeConn();
    this->planThread->closeConn();
    ui->planRun->setDisabled(false);
    ui->planStop->setDisabled(true);
    ui->connButton->setDisabled(true);
    ui->closeButton->setDisabled(false);

    event->ignore();
    */
}


void Clientdialog::on_Clientdialog_destroyed()
{
    qDebug() << "on_Clientdialog_destroyed...";
    this->lthread->closeConn();
    this->planThread->closeConn();
}
