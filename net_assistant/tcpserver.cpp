#include "tcpserver.h"

tcpServer::tcpServer(const QString &ip, unsigned short port)
{
    this->ip = ip;
    this->port = port;
}

int tcpServer::tcpServerOpen()
{
    QHostAddress pHostAddress = QHostAddress(this->port);
}
