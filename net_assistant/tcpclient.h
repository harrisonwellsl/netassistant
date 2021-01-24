#ifndef TCPCLIENT_H
#define TCPCLIENT_H

#include <QTcpSocket>
#include <QObject>
#include <QTextEdit>
#include <QHostAddress>
#include <QTextBrowser>
#include <QAbstractSocket>

class tcpClient : public QObject
{
    Q_OBJECT
public:
    tcpClient(QString &ip, quint16 port, QTextBrowser *whereToShow, QTextEdit *whereToGet);
    ~tcpClient();
    int tcpClientConnect();
    void send(QString msg);
    int tcpClientDisconnect();

signals:
    void tcpServerStateChanged();

public slots:
    void stateChangedMsg(QAbstractSocket::SocketState state);

private:
    QTcpSocket *tcpClientPrivate;
    QHostAddress *pHostAddress;
    QTextEdit *pTextEdit;
    QTextBrowser *pTextBrowser;
    quint16 port;
};

#endif // TCPCLIENT_H
