#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>

#include "tcpserver.h"
#include "tcpclient.h"

namespace Ui {
class MainWindow;
}

class MainWindow : public QMainWindow
{
    Q_OBJECT

public:
    explicit MainWindow(QWidget *parent = 0);
    ~MainWindow();

private:
    Ui::MainWindow *ui;
    /* TCP 服务器定义 */
    bool tcpServerOpened;
    tcpServer *server;
    void tcpServerMode();

    /* TCP 客户端定义 */
    bool tcpClientOpened;
    tcpClient *pTcpClient;
    void tcpClientMode();

public slots:
    void changeTxButton(QString ip);
    void startNetworkAssistant();

    void sendMsg();
};

#endif // MAINWINDOW_H
