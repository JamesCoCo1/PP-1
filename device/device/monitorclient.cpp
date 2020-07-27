#include "monitorclient.h"

MonitorClient::MonitorClient(quint16 port, QWidget *parent)
    : MyTcpClient(port, parent)
{

}



// 预发送信号 打算放到一个 buffer 里面
// buffer 满了之后自动发送
void MonitorClient::txDataPre()
{
    this->mySocket->write();
}
