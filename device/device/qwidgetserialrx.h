#ifndef QWIDGETSERIALRX_H
#define QWIDGETSERIALRX_H

#include <QWidget>

class QWidgetSerialRx : public QWidget
{
    Q_OBJECT
public:
    explicit QWidgetSerialRx(QWidget *parent = nullptr);

signals:
    // 接收成功后发出一个信号给画图端
    // 如果为了适配 socket 发送数据 这边需要再多一点参数 具体再确定去了
    void rxDataSignal(int rxData);

};

#endif // QWIDGETSERIALRX_H
