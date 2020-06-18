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
    checkPermission();

    this->planBtnGroup.addButton(ui->radioPlan1, 0);
    this->planBtnGroup.addButton(ui->radioPlan2, 1);
    this->planBtnGroup.addButton(ui->radioPlan3, 2);

    ui->radioPlan1->setChecked(true);
    ui->closeButton->setDisabled(true);
    ui->planRun->setDisabled(false);
    ui->planStop->setDisabled(true);

    init_lineEdit_IP();
    open_file();
    QString routerIP = ui->lineEdit_IP->text();

    this->lthread = new ListenThread(routerIP);
    this->planThread = new PlanThread(routerIP);

    //connect(ui->connButton,SIGNAL(clicked()),planThread,SLOT(openConn()),Qt::QueuedConnection);
    connect(ui->connButton,SIGNAL(clicked()),this,SLOT(openConn()),Qt::QueuedConnection);
    connect(ui->closeButton,SIGNAL(clicked()),this,SLOT(closeConn()),Qt::QueuedConnection);

    connect(this,SIGNAL(setIP(QString)),this->planThread->plan,SLOT(set_routerIP(QString)),Qt::QueuedConnection);
    connect(this,SIGNAL(setIP(QString)),this->lthread->plan,SLOT(set_routerIP(QString)),Qt::QueuedConnection);

    connect(ui->pushButton_save,SIGNAL(clicked()),this,SLOT(on_pushButton_save_pressed()),Qt::AutoConnection);
    connect(ui->pushButton_up,SIGNAL(clicked()),this,SLOT(make_up()),Qt::AutoConnection);
    connect(ui->pushButton_down,SIGNAL(clicked()),this,SLOT(make_down()),Qt::AutoConnection);
    connect(ui->pushButton_left,SIGNAL(clicked()),this,SLOT(make_left()),Qt::AutoConnection);
    connect(ui->pushButton_right,SIGNAL(clicked()),this,SLOT(make_right()),Qt::AutoConnection);
    connect(ui->pushButton_stop,SIGNAL(clicked()),this,SLOT(make_stop()),Qt::AutoConnection);

    connect(this,SIGNAL(setPlanID(int)),this->planThread,SLOT(setPlan(int)),Qt::DirectConnection);
    connect(this,SIGNAL(_setPlanID(int)),this->lthread,SLOT(setPlan(int)),Qt::DirectConnection);
    connect(this,SIGNAL(stopPthread()),this->planThread,SLOT(stopThread()),Qt::DirectConnection);
    connect(this,SIGNAL(stopLthread()),this->lthread,SLOT(stopThread()),Qt::DirectConnection);

    //connect(ui->planStop,SIGNAL(clicked()),this,SLOT(plan_stop()),Qt::QueuedConnection);
    //connect(ui->planRun,SIGNAL(clicked()),this,SLOT(plan_run()),Qt::QueuedConnection);

    connect(this->planThread->plan,SIGNAL(errReadWriteBuff(const int)),this,SLOT(errRWBuff(const int)),Qt::QueuedConnection);
    connect(this->planThread->plan,SIGNAL(recvBuff(QString)),this,SLOT(recvbuff(QString)),Qt::QueuedConnection);
    connect(this->planThread->plan,SIGNAL(errOpenFile(int)),this,SLOT(errOpenfile(int)),Qt::QueuedConnection);
    connect(this->planThread->plan,SIGNAL(recvOpenConn(int)),this,SLOT(retOpenConn(int)),Qt::QueuedConnection);
    connect(this->planThread->plan,SIGNAL(recvCloseConn(int)),this,SLOT(retCloseConn(int)),Qt::QueuedConnection);

    connect(this->lthread->plan,SIGNAL(errReadWriteBuff(const int)),this,SLOT(errRWBuff(const int)),Qt::QueuedConnection);
    connect(this->lthread->plan,SIGNAL(recvOpenConn(int)),this,SLOT(retOpenConn(int)),Qt::QueuedConnection);
    connect(this->lthread->plan,SIGNAL(recvCloseConn(int)),this,SLOT(retCloseConn(int)),Qt::QueuedConnection);

}

Clientdialog::~Clientdialog()
{
    delete ui;
}

//打开连接
int Clientdialog::openConn()
{
    ui->connButton->setDisabled(true);
    ui->closeButton->setDisabled(false);

    this->planThread->startThread();
    this->lthread->startThread();

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
    this->planThread->closeConn();
    //emit setPlanID(2);
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
    emit setPlanID(7);
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
    emit _setPlanID(7);
#endif
#ifndef WINDOWS
    if(this->planThread->isRunning()){
        qDebug() << "stopthread..." << this->planThread->isRunning();;
        this->planThread->closeConn(); //关闭端口
        emit stopPthread();   //线程里面直接中断线程
        QThread::msleep(50);
        emit _setPlanID(7);
    }
#endif
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
            ui->textBrowser->insertPlainText( QString::fromLocal8Bit("网络连接错误！\n"));
            ui->textBrowser->moveCursor(QTextCursor::End);
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

    emit stopLthread();
    emit stopPthread();
}

void Clientdialog::init_lineEdit_IP()
{
    //ui->lineEdit_IP->setText("192.168.0.1");
    ui->lineEdit_IP->setEnabled(false);
    ui->pushButton_modify->setEnabled(true);
    ui->pushButton_save->setEnabled(false);
}

void Clientdialog::on_pushButton_modify_pressed()
{
    ui->lineEdit_IP->setEnabled(true);
    ui->pushButton_modify->setEnabled(false);
    ui->pushButton_save->setEnabled(true);

    ui->connButton->setEnabled(true);
    ui->closeButton->setEnabled(false);

    this->lthread->closeConn();
    this->planThread->closeConn();
}

void Clientdialog::on_pushButton_save_pressed()
{
    ui->lineEdit_IP->setEnabled(false);
    ui->pushButton_modify->setEnabled(true);
    ui->pushButton_save->setEnabled(false);

    QString ip = ui->lineEdit_IP->text();
    save_file();
    emit setIP(ip);
}

//打开文件
void Clientdialog::open_file()
{
    QDateTime qtimeObj = QDateTime::currentDateTime();//获取时间
    QString alltext;
    //创建newifi文件夹
    QDir *folder = new QDir;
    bool exist = folder->exists("/storage/emulated/0/newifi");
    if(exist)
    {
#ifdef WINDOWS
        QMessageBox::warning(this, tr("createDir"), tr("Dir is already existed!"));
#endif
        qDebug() << "Dir is already existed!";
    }
    else
    {
        //创建文件夹
        bool ok = folder->mkdir("/storage/emulated/0/newifi");
        if(ok){
#ifdef WINDOWS
            QMessageBox::warning(this, tr("CreateDir"), tr("Create Dir success!"));
#endif
            qDebug() << "Create Dir success!";
        }
        else{
#ifdef WINDOWS
            QMessageBox::warning(this, tr("CreateDir"), tr("Create Dir fail"));
#endif
            qDebug() << "Create Dir fail.";
        }
    }

    //读取newifi内的文件
    QString fileName;
    fileName = tr("/storage/emulated/0/newifi/data.txt");

    QFile file(fileName);
    if(!file.open(QIODevice::ReadWrite | QIODevice::Text))
    {
#ifdef WINDOWS
       QMessageBox::warning(this,tr("错误"),tr("打开文件失败，数据保存失败"));
#endif
       qDebug() << "Open file fail, save data fail.";

       return;
    }
    else
    {
       if(!file.isReadable())
       {
#ifdef WINDOWS
           QMessageBox::warning(this,tr("错误"),tr("该文件不可读，数据保存失败"));
#endif
           qDebug() << "Read file fail.";
       }
       else
       {
           file.seek(0);
           QTextStream stream(&file);
           QString line;
           QStringList datalist;

           do
           {
               line = stream.readLine();
               if (line.size() <=0)
               {
                   break;
               }
               datalist.append(line);
           } while(!line.isNull());

           if(datalist.size()>0){
               ui->lineEdit_IP->setText(datalist.at(0));
           }

#ifdef WINDOWS
           QMessageBox::warning(this,tr("信息"),tr("信息存储成功！\n可在系统根目录文件'newifi'文件夹中查看！"));
#endif
       }
    }

    file.close();
}

//存储文件
void Clientdialog::save_file()
{
    //读取newifi内的文件
    QString fileName;
    fileName = tr("/storage/emulated/0/newifi/data.txt");

    QFile file(fileName);
    if(!file.open(QIODevice::ReadWrite | QIODevice::Text))
    {
#ifdef WINDOWS
       QMessageBox::warning(this,tr("错误"),tr("打开文件失败，数据保存失败"));
#endif
       qDebug() << "Open file fail, save data fail.";

       return;
    }
    else
    {
       if(!file.isReadable())
       {
#ifdef WINDOWS
           QMessageBox::warning(this,tr("错误"),tr("该文件不可读，数据保存失败"));
#endif
           qDebug() << "Read file fail.";
       }
       else
       {
           QTextStream out(&file);
           QString ip = ui->lineEdit_IP->text();
           out<<ip<<endl<<QObject::tr("\n data end");

#ifdef WINDOWS
           QMessageBox::warning(this,tr("信息"),tr("信息存储成功！\n可在系统根目录文件'newifi'文件夹中查看！"));
#endif
           qDebug() << "Save file success!";
       }
    }

    file.close();
}

//申请读写文件权限
bool Clientdialog::checkPermission() {
    QtAndroid::PermissionResult r = QtAndroid::checkPermission("android.permission.WRITE_EXTERNAL_STORAGE");
    if(r == QtAndroid::PermissionResult::Denied) {
        QtAndroid::requestPermissionsSync( QStringList() << "android.permission.WRITE_EXTERNAL_STORAGE" );
        r = QtAndroid::checkPermission("android.permission.WRITE_EXTERNAL_STORAGE");
        if(r == QtAndroid::PermissionResult::Denied) {
             return false;
        }
   }

   return true;
}
