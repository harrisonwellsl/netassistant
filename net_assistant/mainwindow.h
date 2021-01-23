#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>

#include "tcpserver.h"

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

public slots:
    void changeTxButton(QString ip);
    void startNetworkAssistant();
};

#endif // MAINWINDOW_H
