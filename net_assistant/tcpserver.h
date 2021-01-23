#ifndef TCPSERVER_H
#define TCPSERVER_H

#include <QObject>
#include <QTcpSocket>
#include <QTcpServer>
#include <QString>
#include <QByteArray>
#include <QDebug>
#include <QTextBrowser>

class tcpServer : public QObject {

    Q_OBJECT
public:
    tcpServer(const QString& ip, quint16 port, QTextBrowser *pTextBrowser);
    ~tcpServer();
    int tcpServerOpen();
    int tcpServerClose();

private:
    QHostAddress *ip;
    QTcpServer *pTcpServer;
    QTcpSocket *pTcpSocketConnection;
    QTextBrowser *pTextBrowser;
    quint16 port;

public slots:
    void acceptConnection();
    void resvDataAndFlush();
};

#endif // TCPSERVER_H
