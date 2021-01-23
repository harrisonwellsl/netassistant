#include "mainwindow.h"
#include "ui_mainwindow.h"

MainWindow::MainWindow(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::MainWindow)
{
    this->tcpServerOpened = false;

    ui->setupUi(this);
    ui->startTransmitButton->setText(tr("&Start the network"));
    ui->startTransmitButton->setEnabled(false);

    /**
     * 下拉菜单选择
     */
    ui->modeSelectBox->addItem("UDP unicast");
    ui->modeSelectBox->addItem("UDP multicast");
    ui->modeSelectBox->addItem("TCP unicast");
    ui->modeSelectBox->addItem("TCP server");

    QObject::connect(ui->ipaddrLineEdit, SIGNAL(textChanged(QString)), this, SLOT(changeTxButton(QString)));
    QObject::connect(ui->startTransmitButton, SIGNAL(clicked(bool)), this, SLOT(startNetworkAssistant()));
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
        qDebug() << "TCP unicast";
        break;
    case 3:
        this->tcpServerMode();
        qDebug() << "TCP server";
        break;
    default:
        break;
    }
}

MainWindow::~MainWindow()
{
    delete this->server;
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
