#ifndef TCPSERVER_H
#define TCPSERVER_H

#include <QObject>
#include <QWidget>
#include <QTcpServer>
#include <QTcpSocket>
#include <QDebug>
#include <QThread>
#include "mytcpsocket.h"

class MyTcpServer : public QWidget
{
    Q_OBJECT
public:
    explicit MyTcpServer(int maxCon, QWidget *parent = nullptr);

    QTcpServer *mTcpServer;
    QTcpSocket *mSocket;
private:

private slots:
    void tcpNewConnection();
    void tcpReadyRead();
    void tcpDisconnect();

    void writeToClient();

signals:

};

#endif // TCPSERVER_H
