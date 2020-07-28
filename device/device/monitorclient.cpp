#include "monitorclient.h"

MonitorClient::MonitorClient(quint16 port, QWidget *parent)
    : MyTcpClient(port, parent)
{
    connect(this->mySocket, &QTcpSocket::connected, this, &MonitorClient::tcpConnected);
    connect(this->mySocket, &QTcpSocket::readyRead, this, &MonitorClient::tcpRead);
}



// 预发送信号 打算放到一个 buffer 里面
// buffer 满了之后自动发送、
// 这是个需要集中处理的地方 争取今天上午全部搞定
void MonitorClient::txDataPre(char pID, int data)
{
//    this->mySocket->write(QByteArray(data));
    qDebug()<<"发送数据";
}

// 处理 TCP 已连接时的动作
void MonitorClient::tcpConnected()
{
    qDebug()<<"TCP 已连接";
}

void MonitorClient::tcpRead()
{
    qDebug()<<"Client received: "<<this->mySocket->readAll();
}
