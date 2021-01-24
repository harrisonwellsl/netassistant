#include "tcpclient.h"

tcpClient::tcpClient(QString &ip, quint16 port, QTextEdit *whereToShow)
{
    this->pHostAddress = new QHostAddress(ip);
    this->port = port;
    this->pTextEdit = whereToShow;
}

tcpClient::~tcpClient()
{
    if (this->tcpClientPrivate->isOpen())
        this->tcpClientPrivate->close();
    delete this->tcpClientPrivate;
    delete this->pHostAddress;
}

int tcpClient::tcpClientConnect()
{
    this->tcpClientPrivate = new QTcpSocket(this);
    return 0;
}
