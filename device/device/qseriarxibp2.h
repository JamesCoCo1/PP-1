#ifndef QSERIARXIBP2_H
#define QSERIARXIBP2_H

#include <QWidget>
#include "qwidgetserialrx.h"

/*
 * QSeriaRxIBP2
 *      用于处理从串口接收来的
 *
 *
*/


class QSeriaRxIBP2 : public QWidget
{
    Q_OBJECT
public:
    explicit QSeriaRxIBP2(QWidget *parent = nullptr);

signals:

};

#endif // QSERIARXIBP2_H
