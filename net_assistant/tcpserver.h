#ifndef TCPSERVER_H
#define TCPSERVER_H

#include <QObject>
#include <QTcpSocket>
#include <QTcpServer>
#include <QString>
#include <QByteArray>
#include <QDebug>

class tcpServer : public QObject {

    Q_OBJECT
public:
    tcpServer(const QString& ip, quint16 port);
    ~tcpServer();
    int tcpServerOpen();

private:
    QHostAddress *ip;
    QTcpServer *pTcpServer;
    QTcpSocket *pTcpSocketConnection;
    quint16 port;

public slots:
    void acceptConnection();
    void resvDataAndFlush();
};

#endif // TCPSERVER_H
