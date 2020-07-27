#ifndef QSERIALRXECG_H
#define QSERIALRXECG_H

#include <QObject>
#include <QWidget>
#include "qwidgetserialrx.h"

/*
 * 参照我已经写好的代码应该不难弄出来
 * 应该直接复制过来就行了
 *
*/

class QSerialRxEcg : public QWidget
{
    Q_OBJECT
public:
    explicit QSerialRxEcg(QWidget *parent = nullptr);

signals:

};

#endif // QSERIALRXECG_H
