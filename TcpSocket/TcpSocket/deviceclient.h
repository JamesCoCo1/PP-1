#ifndef DEVICECLIENT_H
#define DEVICECLIENT_H
#include "mytcpclient.h"

/*
 * 这个类要处理的问题：
 *      为设备端提供 TCP 连接
 *
 *
*/
class DeviceClient : public MyTcpClient
{
    Q_OBJECT
public:
    DeviceClient(quint16 port);
};

#endif // DEVICECLIENT_H
