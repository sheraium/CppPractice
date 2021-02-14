#ifndef IPOOLITEM_H
#define IPOOLITEM_H

class IPoolItem {
public:
    virtual void reset() = 0;

    virtual bool aquired() = 0;

    virtual ~IPoolItem() {};
};

#endif // IPOOLITEM_H
