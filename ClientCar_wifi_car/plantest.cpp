#include "plantest.h"
#include <QDebug>
#include "clientdialog.h"
#include "qclienttcp.h"

#ifdef WINDOWS
    #include <synchapi.h>
    #define Sleep  Sleep
#else
    #define Sleep  sleep
#endif

#define sleeptime 500

PlanTest::PlanTest(QObject *parent) : QObject(parent)
{
    #ifdef WINDOWS
        openfile();
    #else
        //this->ip = "192.168.0.1";
        this->port = 8989;
    #endif

    //tcpsocket = new QClientTCP;

}

void PlanTest::set_routerIP(QString ip){
    this->routerIP = ip;
}

void PlanTest::sleep(int s)
{
    QTime t;
    t.start();
    while(t.elapsed()< s);
        //QCoreApplication::processEvents();
}

bool PlanTest::get_p_connect(){
    return this->p_connect;
}

int PlanTest::openfile()
{
    QFile file(QString("./config.txt"));
    if (file.open(QIODevice::ReadOnly | QIODevice::Text) < 0)
    {
        //QMessageBox::warning(0, QString::fromLocal8Bit("配置文件"), QString::fromLocal8Bit("读取配置文件错误"));
        emit errOpenFile(0);

        return -1;
    }else //找到了就直接读文件
    {
        file.seek(0);
        QTextStream stream(&file);
        QString line;
        QStringList list;

        do
        {
            line = stream.readLine();
            if (line.size() <=0)
            {
                break;
            }
            list = line.split(" ");
        } while(!line.isNull());

        this->ip = list.at(0);
        QString sPort = list.at(1);
        this->port = sPort.toInt();

        qDebug() << "ip" << ip << "\n" << "port" << port;

        emit errOpenFile(1);
    }

    file.close();
    return 0;
}

void PlanTest::initTcpSocket()
{
    if(tcpsocket == NULL)
        tcpsocket = new QClientTCP;
}

//打开连接
bool PlanTest::openConn()
{
    initTcpSocket();

    //建立socket连接
    if(!p_connect){
        //p_connect = tcpsocket->connectToServer(this->ip, this->port);
        p_connect = tcpsocket->connectToServer(this->routerIP, this->port);
        if(p_connect == false)
        {
            emit recvOpenConn(0);
            return false;
        }else
        {
            emit recvOpenConn(1);
            return true;
        }
    }

    return true;
}

//关闭连接
bool PlanTest::closeConn()
{
    if(p_connect){
        if(tcpsocket->closeToServer()){
            p_connect = false;
            emit recvCloseConn(1);

            return true;
        }
    }

    return false;
}

int PlanTest::sendBuff(int fd, char *buff, int len)
{
    if(p_connect){
        int ret = tcpsocket->sendbuff(buff, len);
        if(ret < 0)
        {
            //QMessageBox::warning(this, QString::fromLocal8Bit("发送数据"), QString::fromLocal8Bit("发送数据错误"));
            emit errReadWriteBuff(0);
            tcpsocket->closeToServer();
            //qDebug() << ret;
            return -1;
        }
    }

    return 0;
}

int PlanTest::readBuff(int fd, char *buff, int len)
{
    if(p_connect){
        int ret = tcpsocket->recvbuff(buff, len);
        if(ret < 0)
        {
            //QMessageBox::warning(this, QString::fromLocal8Bit("接收数据"), QString::fromLocal8Bit("接收数据错误"));
            emit errReadWriteBuff(1);
            tcpsocket->closeToServer();
            return -1;
        }

        QString str = QString(QLatin1String(buff));
        emit recvBuff(str);
    }

    return 0;
}

void PlanTest::make_up()
{
    if(p_connect){
        this->up();
        QThread::msleep(sleeptime);
        this->make_stop();
    }
}

void PlanTest::make_up_press()
{
    if(p_connect){
        this->up();
        QThread::msleep(sleeptime);
    }
}

void PlanTest::up()
{
    memset(&elem, 0x00, sizeof(struct ELEM));
    elem.cmd= UP;
    make_packet(&elem);
    //qDebug() << "make_up buff lenth" << elem.len << "\n";
    sendBuff(fd, sendbuff, sizeof(sendbuff));
    memset(recvbuff, 0x00, sizeof(recvbuff));
    readBuff(fd, recvbuff, sizeof(recvbuff));
}

void PlanTest::make_down()
{
    if(p_connect){
        this->down();
        QThread::msleep(sleeptime);
        this->make_stop();
    }
}

void PlanTest::make_down_press()
{
    if(p_connect){
        this->down();
        QThread::msleep(sleeptime);
    }
}

void PlanTest::down()
{
    memset(&elem, 0x00, sizeof(struct ELEM));
    elem.cmd = DOWN;
    make_packet(&elem);
    //qDebug() << "make_down buff lenth" << elem.len << "\n";
    sendBuff(fd, sendbuff, sizeof(sendbuff));
    memset(recvbuff, 0x00, sizeof(recvbuff));
    readBuff(fd, recvbuff, sizeof(recvbuff));
}

void PlanTest::make_left()
{
    if(p_connect){
        this->left();
        QThread::msleep(sleeptime);
        this->make_stop();
    }
}

void PlanTest::make_left_press()
{
    if(p_connect){
        this->left();
        QThread::msleep(sleeptime);
    }
}

void PlanTest::left()
{
    memset(&elem, 0x00, sizeof(struct ELEM));
    elem.cmd = LEFT;
    make_packet(&elem);
    //qDebug() << "make_left buff lenth" << elem.len << "\n";
    sendBuff(fd, sendbuff, sizeof(sendbuff));
    memset(recvbuff, 0x00, sizeof(recvbuff));
    readBuff(fd, recvbuff, sizeof(recvbuff));
}

void PlanTest::make_left_back()
{
    if(p_connect){
        this->left_back();
        QThread::msleep(sleeptime);
    }
}

void PlanTest::left_back()
{
    memset(&elem, 0x00, sizeof(struct ELEM));
    elem.cmd = LEFT_BACK;
    make_packet(&elem);
    //qDebug() << "make_left buff lenth" << elem.len << "\n";
    sendBuff(fd, sendbuff, sizeof(sendbuff));
    memset(recvbuff, 0x00, sizeof(recvbuff));
    readBuff(fd, recvbuff, sizeof(recvbuff));
}

void PlanTest::make_right()
{
    if(p_connect){
        this->right();
        QThread::msleep(sleeptime);
        this->make_stop();
    }
}

void PlanTest::make_right_press()
{
    if(p_connect){
        this->right();
        QThread::msleep(sleeptime);
    }
}

void PlanTest::right()
{
    memset(&elem, 0x00, sizeof(struct ELEM));
    elem.cmd = RIGHT;
    make_packet(&elem);
    //qDebug() << "make_right buff lenth" << elem.len << "\n";
    sendBuff(fd, sendbuff, sizeof(sendbuff));
    memset(recvbuff, 0x00, sizeof(recvbuff));
    readBuff(fd, recvbuff, sizeof(recvbuff));
}

void PlanTest::make_right_back()
{
    if(p_connect){
        this->right_back();
        QThread::msleep(sleeptime);
    }
}

 void PlanTest::right_back()
 {
     memset(&elem, 0x00, sizeof(struct ELEM));
     elem.cmd = RIGHT_BACK;
     make_packet(&elem);
     //qDebug() << "make_right buff lenth" << elem.len << "\n";
     sendBuff(fd, sendbuff, sizeof(sendbuff));
     memset(recvbuff, 0x00, sizeof(recvbuff));
     readBuff(fd, recvbuff, sizeof(recvbuff));
 }

void PlanTest::make_stop()
{
    if(p_connect){
        memset(&elem, 0x00, sizeof(struct ELEM));
        elem.cmd = STOP;
        make_packet(&elem);
        //qDebug() << "make_right buff lenth" << elem.len << "\n";
        sendBuff(fd, sendbuff, sizeof(sendbuff));
        memset(recvbuff, 0x00, sizeof(recvbuff));
        readBuff(fd, recvbuff, sizeof(recvbuff));
    }
}

//组包函数
int PlanTest::make_packet(ELEM *elem)
{
    char *buf;

    memset(sendbuff, 0x00, sizeof(sendbuff));

    buf = sendbuff;
    elem->fd = this->fd; //socket描述符
    elem->len =sizeof(sendbuff);

    //elem.len = 1+4+strlen(elem.buff);  //数据包长度
    sprintf(buf, "%04d",  elem->len);
    buf += 4;

    sprintf(buf, "%d", elem->cmd);   //命令
    buf += 1;

    sprintf(buf, "%04d", elem->fd);  //客户端标识
    buf += 4;

    memcpy(buf, elem->buff, sizeof(elem->buff)); //buff内容
    //qDebug() << "sendbuff" << sendbuff << "\n";

    return 0;
}

void PlanTest::make_planA()
{
    if(p_connect){
        this->up();
        QThread::msleep(4000);
        this->right();
        QThread::msleep(1500);

        this->up();
        QThread::msleep(4000);
        this->right();
        QThread::msleep(1500);

        this->up();
        QThread::msleep(4000);
        this->right();
        QThread::msleep(1500);

        this->up();
        QThread::msleep(4000);
        this->right();
        QThread::msleep(1500);

        this->make_stop();
    }
}

void PlanTest::make_planB()
{
    if(p_connect){
        this->up();
        QThread::msleep(1500);
        this->right();
        QThread::msleep(1500);
        this->left();
        QThread::msleep(1500);
        this->right();
        QThread::msleep(1500);
        this->left();
        QThread::msleep(1500);
        this->right();
        QThread::msleep(1500);
        this->left();
        QThread::msleep(1500);
        this->right();
        QThread::msleep(1500);
        this->left();
        QThread::msleep(1500);

        this->make_stop();
    }
}

void PlanTest::make_planC()
{
    if(p_connect){
        this->down();
        QThread::msleep(2000);
        this->right_back();
        QThread::msleep(2000);
        this->down();
        QThread::msleep(2000);
        this->left_back();
        QThread::msleep(2000);
        this->down();
        QThread::msleep(2000);
        this->right_back();
        QThread::msleep(2000);
        this->down();
        QThread::msleep(2000);
        this->left_back();
        QThread::msleep(2000);
        this->make_stop();
    }
}

