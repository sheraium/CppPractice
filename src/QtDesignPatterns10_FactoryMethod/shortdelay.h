#ifndef SHORTDELAY_H
#define SHORTDELAY_H

#include <QObject>
#include <QThread>
#include "interfaces/idelay.h"

class ShortDelay : public QObject,public IDelay
{
    Q_OBJECT
public:
    explicit ShortDelay(QObject *parent = nullptr);

    ~ShortDelay() override;

    void delay(int ms) override;

    bool isComplete() override;

signals:

private:
    bool complete;

};

#endif // SHORTDELAY_H
