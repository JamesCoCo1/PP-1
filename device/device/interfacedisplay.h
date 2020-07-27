#ifndef INTERFACEDISPLAY_H
#define INTERFACEDISPLAY_H

#include <QWidget>
#include "qwidgetdraw.h"
#include "qwidgetdrawfromserial.h"

/*
 * 获得从串口而来的数据进行绘图
 *
 * 这边里面具体的函数没有写了 有不明白的再说吧
 *
*/

class InterfaceDisplay : public QWidget
{
    Q_OBJECT
public:
    explicit InterfaceDisplay(QWidget *parent = nullptr);

    // 接收绘图部分来的信号进行绘图
    // 也许可以只用一个 但是建立三个也许并无大碍
    QWidgetDrawFromSerial *ecgDrawer;
    QWidgetDrawFromSerial *spo2Drawer;
    QWidgetDrawFromSerial *ibp2Drawer;

/*
 * 这里需要添加其他一些控件 才能实现最终的目标
 * 此外还需要其他的一些调整
 */

signals:

};

#endif // INTERFACEDISPLAY_H
