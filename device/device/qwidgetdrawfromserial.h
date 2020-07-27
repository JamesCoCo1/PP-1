#ifndef QWIDGETDRAWFROMSERIAL_H
#define QWIDGETDRAWFROMSERIAL_H

#include <QWidget>

class QWidgetDrawFromSerial : public QWidget
{
    Q_OBJECT
public:
    explicit QWidgetDrawFromSerial(QWidget *parent = nullptr);

    // 槽信号
    void refreshFromData();

signals:

};

#endif // QWIDGETDRAWFROMSERIAL_H
