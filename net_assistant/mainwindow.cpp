#include "mainwindow.h"
#include "ui_mainwindow.h"

MainWindow::MainWindow(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::MainWindow)
{
    this->tcpServerOpened = false;
    this->tcpClientOpened = false;

    this->server = NULL;
    this->pTcpClient = NULL;

    ui->setupUi(this);
    ui->startTransmitButton->setText(tr("&Start the network"));
    ui->startTransmitButton->setEnabled(false);

    ui->sendMsgButton->setText("Send message");
    ui->sendMsgButton->setEnabled(false);

    /**
     * 下拉菜单选择
     */
    ui->modeSelectBox->addItem("UDP unicast");
    ui->modeSelectBox->addItem("UDP multicast");
    ui->modeSelectBox->addItem("TCP unicast");
    ui->modeSelectBox->addItem("TCP server");
    ui->modeSelectBox->addItem("UDP server");

    QObject::connect(ui->ipaddrLineEdit, SIGNAL(textChanged(QString)), this, SLOT(changeTxButton(QString)));
    QObject::connect(ui->startTransmitButton, SIGNAL(clicked(bool)), this, SLOT(startNetworkAssistant()));
    QObject::connect(ui->sendMsgButton, SIGNAL(clicked(bool)), this, SLOT(sendMsg()));
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
    int modeSlectBoxIndex = -1;
    modeSlectBoxIndex = this->ui->modeSelectBox->currentIndex();
    qDebug() << "run here!";
    qDebug() << modeSlectBoxIndex;

    switch (modeSlectBoxIndex)
    {
    case 0:
        qDebug() << "UDP unicast";
        break;
    case 1:
        qDebug() << "UDP multicast";
        break;
    case 2:
        this->tcpClientMode();
        qDebug() << "TCP unicast";
        break;
    case 3:
        this->tcpServerMode();
        qDebug() << "TCP server";
        break;
    case 4:
        qDebug() << "UDP server";
        break;
    default:
        break;
    }
}

void MainWindow::sendMsg()
{
    this->pTcpClient->send(this->ui->msgSendTextEdit->toPlainText());
}

MainWindow::~MainWindow()
{
    /* 释放服务器内存 */
    if (this->server != NULL)
        delete this->server;
    /* 释放客户端内存 */
    if (this->pTcpClient != NULL)
        delete this->pTcpClient;
    delete ui;
}

void MainWindow::tcpServerMode()
{
    if (this->tcpServerOpened == false)
    {
        /* 打开TCP服务器 */
        QString ip = this->ui->ipaddrLineEdit->text();
        qint16 port = this->ui->portLineEdit->text().toUShort();
        this->server = new tcpServer(ip, port, this->ui->showTheResvData);
        int status = this->server->tcpServerOpen();
        if (status < 0)
        {
            qDebug() << "tcp server open failed";
            return;
        }

        /* 禁止使能模式选择按钮 */
        this->ui->modeSelectBox->setEnabled(false);

        /* 标记TCP服务器当前已经打开 */
        this->tcpServerOpened = true;
        this->ui->startTransmitButton->setText("Close the network");
    }
    else
    {
        this->server->tcpServerClose();
        delete this->server;
        this->server = NULL;
        this->tcpServerOpened = false;
        this->ui->modeSelectBox->setEnabled(true);
        this->ui->startTransmitButton->setText("Start the network");
    }
}

void MainWindow::tcpClientMode()
{
    if (this->tcpClientOpened == false)
    {
        /* 打开TCP客户端 */
        this->ui->startTransmitButton->setText("Close the network");
        this->tcpClientOpened = true;
        this->ui->sendMsgButton->setEnabled(true);
        this->ui->modeSelectBox->setEnabled(false);

        QString ip = this->ui->ipaddrLineEdit->text();
        qint16 port = this->ui->portLineEdit->text().toUShort();

        this->pTcpClient = new tcpClient(ip, port, this->ui->showTheSendData, this->ui->msgSendTextEdit);
        pTcpClient->tcpClientConnect();
    }
    else
    {
        /* 关闭TCP客户端 */
        this->ui->startTransmitButton->setText("Start the network");
        this->tcpClientOpened = false;
        this->ui->sendMsgButton->setEnabled(false);
        this->ui->modeSelectBox->setEnabled(true);

        this->pTcpClient->tcpClientDisconnect();
        delete this->pTcpClient;
        this->pTcpClient = NULL;
    }
}
