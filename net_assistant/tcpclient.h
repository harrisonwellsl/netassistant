#ifndef TCPCLIENT_H
#define TCPCLIENT_H

#include <QTcpSocket>
#include <QObject>
#include <QTextEdit>
#include <QHostAddress>

class tcpClient : public QObject
{
    Q_OBJECT
public:
    tcpClient(QString &ip, quint16 port, QTextEdit *whereToShow);
    ~tcpClient();
    int tcpClientConnect();
    void send(QString &msg);
#if 0
signals:

public slots:
#endif
private:
    QTcpSocket *tcpClientPrivate;
    QHostAddress *pHostAddress;
    QTextEdit *pTextEdit;
    quint16 port;
};

#endif // TCPCLIENT_H
