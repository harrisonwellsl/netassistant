#include "mainwindow.h"
#include "ui_mainwindow.h"
#include "tcpserver.h"

MainWindow::MainWindow(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::MainWindow)
{
    ui->setupUi(this);
    ui->startTransmitButton->setText(tr("&Start the network"));
    tcpServer *server = new tcpServer("0.0.0.0", 8888);
    int  status = server->tcpServerOpen();
    if (status == -1)
    {
        qDebug() << "tcp server open failed";
    }
}

MainWindow::~MainWindow()
{
    delete ui;
}
