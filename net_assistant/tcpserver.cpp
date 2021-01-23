#include "tcpserver.h"

/**
 * @brief tcpServer::tcpServer
 * @param ip
 * @param port
 * 构造函数
 */
tcpServer::tcpServer(const QString &ip, unsigned short port)
{
    this->ip = new QHostAddress(ip);
    this->port = port;
    QObject::connect(this->pTcpServer, SIGNAL(newConnection(), )
}

/**
 * @brief tcpServer::tcpServerOpen
 * @return
 * 打开TCP服务器
 */
int tcpServer::tcpServerOpen()
{
    this->pTcpServer = new QTcpServer(nullptr);
    pTcpServer->setMaxPendingConnections(TCP_SERVER_MAX_CONNECTS);
    return 0;
}

/**
 * @brief tcpServer::acceptConnection
 * 当链接到来的时候补充pTcpSocketConnection参数
 */
void tcpServer::acceptConnection()
{
    this->pTcpSocketConnection = this->pTcpServer->nextPendingConnection();
}

tcpServer::~tcpServer()
{
    if (this->pTcpServer->isListening())
        this->pTcpServer->close();

    delete this->pTcpServer;
    delete this->ip;
}
