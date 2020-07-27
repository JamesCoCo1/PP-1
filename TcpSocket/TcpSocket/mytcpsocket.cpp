#include "mytcpsocket.h"

MyTcpSocket::MyTcpSocket(QTcpSocket *parent) : QTcpSocket(parent)
{
    connect(this, &MyTcpSocket::readyRead, this, &MyTcpSocket::slotReadData);
}

void MyTcpSocket::slotReadData()
{
    // 先只做请求数据库
    QByteArray ba = this->readAll();
    qDebug()<<"slotReadData : receive da "<<ba;
    // 在这个socket我们可以做很多事， 我们需要在这里写很多东西，连接之类的

//    QSqlQueryModel devicePatientModel;
//    devicePatientModel.setQuery("SELECT * FROM patients "
//                   "LEFT JOIN device_patient "
//                   "ON patients.id = device_patient.id "
//                   "LEFT JOIN device "
//                   "ON device.dev_id = device_patient.dev_id");
    this->model->setQuery(ba);  // 假装是完成正确的query语句
    emit handled();
}
