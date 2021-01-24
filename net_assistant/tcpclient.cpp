#include "tcpclient.h"

tcpClient::tcpClient(QString &ip, quint16 port, QTextBrowser *whereToShow, QTextEdit *whereToGet)
{
    this->pHostAddress = new QHostAddress(ip);
    this->port = port;
    this->pTextEdit = whereToGet;
    this->pTextBrowser = whereToShow;

    this->tcpClientPrivate = NULL;
}

tcpClient::~tcpClient()
{
    if (this->tcpClientPrivate->isOpen())
        this->tcpClientPrivate->close();
    if (this->tcpClientPrivate != NULL)
        delete this->tcpClientPrivate;
    delete this->pHostAddress;
}

int tcpClient::tcpClientConnect()
{
    this->tcpClientPrivate = new QTcpSocket(this);
    this->tcpClientPrivate->connectToHost(*this->pHostAddress, this->port);
    return 0;
}

void tcpClient::send(QString msg)
{
    this->pTextBrowser->append(QString("TCP Client send: ") + msg);
    this->tcpClientPrivate->write(msg.toAscii());
}

int tcpClient::tcpClientDisconnect()
{
    if (this->tcpClientPrivate->isOpen())
        this->tcpClientPrivate->close();
    return 0;
}
