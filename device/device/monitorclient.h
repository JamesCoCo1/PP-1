#ifndef MONITORCLIENT_H
#define MONITORCLIENT_H

#include <QObject>
#include <QWidget>
#include "mytcpclient.h"



class MonitorClient : public MyTcpClient
{
    Q_OBJECT
public:
    explicit MonitorClient(quint16 port, QWidget *parent = nullptr);

    // 槽
    void txDataPre(char pID, int data);
    void tcpConnected();
    void tcpRead();
signals:

};

#endif // MONITORCLIENT_H
