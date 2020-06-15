#include "qclienttcp.h"

QClientTCP::QClientTCP()
{

}

bool QClientTCP::connectToServer(QString ip, int port)
{
    this->connectToHost(ip, port);
    bool connected = this->waitForConnected(2000);

    return connected;
}

bool QClientTCP::closeToServer()
{
    this->disconnectFromHost();
    /*
    if(this->waitForDisconnected(2000))
        return true;
    else
        return false;
    */

    return true;
}

int QClientTCP::sendbuff(char *buff, int len)
{
    int ret = this->write(buff, len);
    if(this->waitForBytesWritten())
        return ret;
    return ret;
}

int QClientTCP::recvbuff(char *buff, int len)
{
    int ret = this->read(buff, len);
    //this->waitForReadyRead();

    return ret;
}
