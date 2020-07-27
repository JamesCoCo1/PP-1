#ifndef CLOUDMONITOR_H
#define CLOUDMONITOR_H

#include <QWidget>
#include "qwidgetserialrx.h"
#include "qserialrxecg.h"
#include "qserialrxspo2.h"
#include "qserialrxibp2.h"
#include "interfacedisplay.h"
#include "monitorclient.h"


class CloudMonitor: public QWidget
{
    Q_OBJECT
public:
    CloudMonitor(QWidget *parent = nullptr);

    // 这里的入口参数需要自己设置下
    // 初始化这个类中的所有对象
    void initMonitor();

private:
    // 串口接收
    // 这个或许用一种串口就行了 直接用端口来区分不同的信号类型，不去区分
    QWidgetSerialRx *ecgRx;
    QWidgetSerialRx *ibp2Rx;
    QWidgetSerialRx *spo2Rx;
    // 接收信号需要发送一个什么呢？这部分可以利用多态吗？要不还是干脆分开吧
    // 界面显示
    InterfaceDisplay *displayer;

    // 数据发送 通过 TcpSocket
    MonitorClient *mSocket;

    // 设备 ID 上传信息时会使用到
    QString dev_id;

    void initSignalConnection();

private slots:

signals:

};

#endif // CLOUDMONITOR_H
