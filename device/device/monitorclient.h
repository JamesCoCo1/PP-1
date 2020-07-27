#ifndef MONITORCLIENT_H
#define MONITORCLIENT_H

#include <QObject>

class MonitorClient : public QObject
{
    Q_OBJECT
public:
    explicit MonitorClient(QObject *parent = nullptr);

    // 槽
    void txDataPre();
signals:

};

#endif // MONITORCLIENT_H
