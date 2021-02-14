#ifndef IPOOL_H
#define IPOOL_H

#include "ipoolitem.h"

class IPool {
public:
    virtual ~IPool() {}

    virtual IPoolItem *aquire() = 0;

    virtual void release(IPoolItem *item) = 0;
};

#endif // IPOOL_H
