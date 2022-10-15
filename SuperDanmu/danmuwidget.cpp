#include "danmuwidget.h"
#include "ui_danmuwidget.h"

#include <QDebug>
#include <QTcpSocket>

danmuWidget::danmuWidget(QWidget *parent)
    : QWidget(parent)
    , ui(new Ui::danmuWidget)
{
    ui->setupUi(this);

    // 设置标题
    this->setWindowTitle("Super Danmu");

    // 隐藏顶栏
//    this->setWindowFlags(Qt::FramelessWindowHint);

    // 设置初始大小
    this->resize(300, 600);

    // 设置最小尺寸
    this->setMinimumSize(300, 600);

    this->setFixedSize(300, 600);

    // 设置窗体透明度
    this->setWindowOpacity(0.7);

    this->setStyleSheet("QWidget{background-color:gray;border-radius:15px;}");

    this->ui->openBtn->setStyleSheet(
        "QPushButton{background-color: white;border-radius: 5px;}"
        "QPushButton:hover{background-color: white;border-radius: 10px;}"
        "QPushButton:pressed{background-color: grey;}"
    );

    this->isConnected = false;
    this->m_server = new QTcpServer(this);
    connect(this->ui->openBtn, &QPushButton::clicked, this, [&]() {
        if(!this->isConnected) {
            unsigned short port = QString("7170").toInt();
            m_server->listen(QHostAddress::Any, port);
            this->ui->openBtn->setText("Disconnect");
            this->ui->status->setText("Connected");
            this->isConnected = !this->isConnected;
        }
        else {
            this->m_server->close();
            this->ui->openBtn->setText("Connect");
            this->ui->status->setText("No Connection");
            this->isConnected = !this->isConnected;
        }
    });

    connect(this->m_server, &QTcpServer::newConnection, this, [&]() {
        m_tcp = m_server->nextPendingConnection();
        connect(m_tcp, &QTcpSocket::readyRead, this, [&]() {
            QString recvMsg = m_tcp->readAll();
            ui->danmuList->append("客户端: " + recvMsg);
        });
    });


}

danmuWidget::~danmuWidget()
{
    delete ui;
}

