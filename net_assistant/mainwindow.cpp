#include "mainwindow.h"
#include "ui_mainwindow.h"
#include "tcpserver.h"

MainWindow::MainWindow(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::MainWindow)
{
    ui->setupUi(this);
    ui->startTransmitButton->setText(tr("&Start the network"));
    ui->startTransmitButton->setEnabled(false);

    QObject::connect(ui->ipaddrLineEdit, SIGNAL(textChanged(QString)), this, SLOT(changeTxButton(QString)));
    QObject::connect(ui->startTransmitButton, SIGNAL(clicked(bool)), this, SLOT(startNetworkAssistant()));

    tcpServer *server = new tcpServer("0.0.0.0", 8888);
    int  status = server->tcpServerOpen();
    if (status == -1)
    {
        qDebug() << "tcp server open failed";
    }
}

void MainWindow::changeTxButton(QString ip)
{
    if (ip == "")
    {
        this->ui->startTransmitButton->setEnabled(false);
    }
    else
    {
        this->ui->startTransmitButton->setEnabled(true);
    }
}

void MainWindow::startNetworkAssistant()
{
    /* 总共有四种测试的类型，需要将四种类型的助手服务分开处理 */
    qDebug() << "run here!";
}

MainWindow::~MainWindow()
{
    delete ui;
}
