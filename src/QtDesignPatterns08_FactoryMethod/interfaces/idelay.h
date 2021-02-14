#ifndef IDELAY_H
#define IDELAY_H

class IDelay {
public:
    virtual void delay(int ms) = 0;
    virtual bool isComplete() = 0;
    virtual ~IDelay() {} ;
};

#endif // IDELAY_H
