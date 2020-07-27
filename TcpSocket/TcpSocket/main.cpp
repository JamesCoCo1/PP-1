#include <QApplication>
#include <QWidget>
#include "tcpserver.h"

int main(int argc, char *argv[])
{
    QApplication a(argc, argv);
    QWidget *mainWin = new QWidget();
    MyTcpServer *newServer = new MyTcpServer(2);

    mainWin->resize(400, 400);

    mainWin->show();
    return a.exec();
}
