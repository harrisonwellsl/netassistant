#ifndef TCPSERVER_H
#define TCPSERVER_H

#include <QTcpSocket>
#include <QTcpServer>
#include <QString>

#define TCP_SERVER_MAX_CONNECTS 20

class tcpServer {
public:
    tcpServer(const QString& ip, unsigned short port);
    ~tcpServer();
    int tcpServerOpen();

private:
    QHostAddress *ip;
    QTcpServer *pTcpServer;
    QTcpSocket *pTcpSocketConnection;
    unsigned port;

private slots:
    void acceptConnection();
};

#endif // TCPSERVER_H
