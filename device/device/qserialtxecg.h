#ifndef QSERIALTXECG_H
#define QSERIALTXECG_H

#include <QObject>
#include <QWidget>

class QSerialTxEcg : public QWidget
{
    Q_OBJECT
public:
    explicit QSerialTxEcg(QWidget *parent = nullptr);

signals:

};

#endif // QSERIALTXECG_H
