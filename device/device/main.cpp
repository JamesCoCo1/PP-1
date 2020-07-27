#include <QApplication>
#include <QWidget>
#include "cloudmonitor.h"
#include "qserialtxecg.h"
#include "qserialtxibp2.h"
#include "qserialtxspo2.h"

int main(int argc, char *argv[])
{
    QApplication a(argc, argv);

/*
 *
 * 初始化三个发送串口 将串口连接好
 *  具体入口参数取决于写法
 *
 */

    CloudMonitor *monitor = new CloudMonitor();

    monitor->resize(400, 400);

    monitor->show();

    return a.exec();
}
