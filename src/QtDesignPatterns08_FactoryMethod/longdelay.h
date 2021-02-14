#ifndef LONGDELAY_H
#define LONGDELAY_H

#include <QObject>
#include <QTimer>
#include "interfaces/idelay.h"

class LongDelay : public QObject, public IDelay {
Q_OBJECT
public:
    explicit LongDelay(QObject *parent = nullptr);

    void delay(int ms) override;

    bool isComplete() override;


signals:

private slots:

    void timeout();

private:
    QTimer timer;
    bool complete;


};

#endif // LONGDELAY_H
