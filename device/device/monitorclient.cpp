#include "monitorclient.h"

MonitorClient::MonitorClient(QObject *parent) : QObject(parent)
{

}

// 预发送信号 打算放到一个 buffer 里面
// buffer 满了之后自动发送
void MonitorClient::txDataPre()
{

}
