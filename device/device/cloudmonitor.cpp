#include "cloudmonitor.h"

CloudMonitor::CloudMonitor(QWidget *parent): QWidget(parent)
{
    this->initSignalConnection();
}

// 初始化那些成员变量
void CloudMonitor::initMonitor()
{

}

void CloudMonitor::initSignalConnection()
{
    // 接收到信号时，向画图发送信号
    connect(this->ecgRx, &QWidgetSerialRx::rxDataSignal, this->displayer->ecgDrawer, &QWidgetDrawFromSerial::refreshFromData);
    connect(this->spo2Rx, &QWidgetSerialRx::rxDataSignal, this->displayer->spo2Drawer, &QWidgetDrawFromSerial::refreshFromData);
    connect(this->ibp2Rx, &QWidgetSerialRx::rxDataSignal, this->displayer->ibp2Drawer, &QWidgetDrawFromSerial::refreshFromData);

    // 接收到信号时，向 Socket 发送部分发送信号 参数需要再确定
    // 如果每个串口接收到数据就通过 socket 发送数据 应该不是一个好的选择
    connect(this->ibp2Rx, &QWidgetSerialRx::rxDataSignal, this->mSocket, &MonitorClient::txDataPre);
    connect(this->spo2Rx, &QWidgetSerialRx::rxDataSignal, this->mSocket, &MonitorClient::txDataPre);
    connect(this->spo2Rx, &QWidgetSerialRx::rxDataSignal, this->mSocket, &MonitorClient::txDataPre);
}


