#ifndef MYPOOLITEM_H
#define MYPOOLITEM_H

#include <QObject>
#include <QDebug>
#include "interfaces/ipoolitem.h"

class MyPoolItem : public QObject, public IPoolItem {
Q_OBJECT
public:
    explicit MyPoolItem(QObject *parent = nullptr);

    ~MyPoolItem() override;
    void setAquired(bool aquired);
    void test();

    void reset() override;

    bool aquired() override;


signals:

private:
    bool m_aquired;
};

#endif // MYPOOLITEM_H
