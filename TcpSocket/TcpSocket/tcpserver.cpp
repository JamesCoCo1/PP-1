#include "tcpserver.h"

MyTcpServer::MyTcpServer(int maxCon, QWidget *parent) : QWidget(parent)
{
    this->mTcpServer = new QTcpServer(this);
    this->mTcpServer->setMaxPendingConnections(maxCon); // 最大连接数
    connect(this->mTcpServer, &QTcpServer::newConnection, this, &MyTcpServer::tcpNewConnection);

    this->mTcpServer->listen(QHostAddress::Any, 1234);
}

void MyTcpServer::tcpNewConnection()
{
    this->mSocket = mTcpServer->nextPendingConnection();
    if (this->mSocket)
    {
        MyTcpSocket *mySocket = new MyTcpSocket();
        mySocket->setSocketDescriptor(this->mSocket->socketDescriptor());

        // 新建一个线程
        QThread *t = new QThread();
        mySocket->moveToThread(t);
        t->start();

        connect(mySocket, &MyTcpSocket::handled, this, &MyTcpServer::writeToClient);

        connect(mySocket, &QTcpSocket::disconnected, this, &MyTcpServer::tcpDisconnect);
        qDebug()<<"TCP 连接成功";
    }
}

void MyTcpServer::tcpReadyRead()
{
    qDebug()<<"tcpReadyRead"<<this->mSocket->readAll();
}

void MyTcpServer::tcpDisconnect()
{
    this->mSocket->deleteLater();
    mSocket = 0;
    qDebug()<<"断开连接";
}

void MyTcpServer::writeToClient()
{
    qDebug()<<"向Client返回数据";
}

// 需要添加一个写事件 向请求端返回数据

