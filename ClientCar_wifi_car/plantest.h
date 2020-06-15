#ifndef PLANTEST_H
#define PLANTEST_H

#include <QMainWindow>
#include <QWidget>
#include <QObject>
#include "qclienttcp.h"

class PlanTest : public QObject
{
    Q_OBJECT
public:
    explicit PlanTest(QObject *parent = nullptr);

    //数据包结构体
    struct ELEM
    {
       int       len;          //数据包长度,4位
       int       cmd;          //操作码，1位
       int       fd;           //标识客户端，4位
       char      buff[10];   //数据包
    }elem;


    //命令常量
    enum cmd_{
        UP             = 0x01,  //前进
        DOWN           = 0x02,  //后退
        LEFT           = 0x03,  //左转
        RIGHT          = 0x04,  //右转
        STOP           = 0x05,  //停止
        LEFT_BACK      = 0x06,  //左后转
        RIGHT_BACK     = 0x07,  //右后转
    };

    char sendbuff[10];
    char recvbuff[10];

    int fd = 0; //socket描述符

    int isConn = 0;

    QString ip;
    int port;

    QClientTCP *tcpsocket = NULL;
    bool p_connect = false;

    void sleep(int s);
    void initTcpSocket();

    int make_packet(ELEM *elem);  //组包
    int sendBuff(int fd, char *buff, int len);
    int readBuff(int fd, char *buff, int len);

    int openfile();
    bool openConn();
    bool closeConn();
    void make_up();
    void make_down();
    void make_left();
    void make_right();
    void make_stop();
    void make_left_back();
    void make_right_back();

    void make_up_press();
    void make_down_press();
    void make_left_press();
    void make_right_press();

    void up();
    void down();
    void left();
    void right();
    void left_back();
    void right_back();

    void make_planA();
    void make_planB();
    void make_planC();

signals:
    void recvOpenConn(int i);
    void recvCloseConn(int i);
    void errReadWriteBuff(const int id);
    void recvBuff(QString str);
    void errOpenFile(int i);

};

#endif // PLANTEST_H
