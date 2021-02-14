#ifndef MYPOOL_H
#define MYPOOL_H

#include <QObject>
#include "interfaces/ipool.h"
#include "interfaces/ipoolitem.h"
#include "mypoolitem.h"

class MyPool : public QObject, public IPool {
Q_OBJECT
public:
    explicit MyPool(QObject *parent = nullptr);

    ~MyPool();

    IPoolItem *aquire() override;

    void release(IPoolItem *item) override;

signals:

private:
    QList<MyPoolItem *> m_list;
};

#endif // MYPOOL_H
