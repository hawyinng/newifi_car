#ifndef QCLIENTTCP_H
#define QCLIENTTCP_H

#include <QObject>
#include <QtNetwork>

class QClientTCP : public QTcpSocket
{
     Q_OBJECT
public:
    QClientTCP();

    bool connectToServer(QString ip, int port);
    bool closeToServer();
    int sendbuff(char *buff, int len);
    int recvbuff(char *buff, int len);

signals:

public slots:
};

#endif // QCLIENTTCP_H
