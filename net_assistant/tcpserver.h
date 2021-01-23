#ifndef TCPSERVER_H
#define TCPSERVER_H

#include <QTcpServer>
#include <QString>

class tcpServer {
public:
    tcpServer(const QString& ip, unsigned short port);
    ~tcpServer() = default;
    int tcpServerOpen();

private:
    QString ip;
    unsigned port;
};

#endif // TCPSERVER_H
