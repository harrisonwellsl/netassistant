#include "tcpserver.h"

#define TCP_SERVER_MAX_CONNECTS 1

/**
 * @brief tcpServer::tcpServer
 * @param ip
 * @param port
 * 构造函数
 */
tcpServer::tcpServer(const QString &ip, quint16 port, QTextBrowser *textBrowser)
{
    qDebug() << ip;
    qDebug() << port;
    this->ip = new QHostAddress(ip);
    this->port = port;
    this->pTextBrowser = textBrowser;
}

/**
 * @brief tcpServer::tcpServerOpen
 * @return
 * 打开TCP服务器
 */
int tcpServer::tcpServerOpen()
{
    this->pTcpServer = new QTcpServer(this);
    this->pTcpServer->setMaxPendingConnections(TCP_SERVER_MAX_CONNECTS);
    bool status = this->pTcpServer->listen(*this->ip, this->port);
    if (status == false)
    {
        return -1;
    }

    /**
     * 连接信号，当有新连接的时候触发信号执行函数
     */
    QObject::connect(this->pTcpServer, SIGNAL(newConnection()), this, SLOT(acceptConnection()));
    return 0;
}

int tcpServer::tcpServerClose()
{
    if (this-pTcpServer->isListening())
    {
        this->pTcpServer->close();
    }

    if (this->pTcpSocketConnection->isOpen())
    {
        this->pTcpSocketConnection->close();
    }

    return 0;
}

/**
 * @brief tcpServer::acceptConnection
 * 当链接到来的时候补充pTcpSocketConnection参数
 */
void tcpServer::acceptConnection()
{
    qDebug() << "has a new connection";
    this->pTcpSocketConnection = this->pTcpServer->nextPendingConnection();
    QObject::connect(this->pTcpSocketConnection, SIGNAL(readyRead()), this, SLOT(resvDataAndFlush()));
}

/**
 * @brief tcpServer::resvDataAndFlush
 * 槽函数，接收数据并将其显示到界面当中
 */
void tcpServer::resvDataAndFlush()
{
    qDebug() << "resv data";
    QByteArray data = this->pTcpSocketConnection->readAll();
    this->pTextBrowser->append(QString("TCP server: ") + QString(data));
    qDebug() << data;
}

/**
 * @brief tcpServer::~tcpServer
 * 析构函数，把分配的内存释放出来
 */
tcpServer::~tcpServer()
{
    if (this->pTcpServer->isListening())
        this->pTcpServer->close();

    delete this->pTcpServer;
    delete this->ip;
}
