#ifndef LION_H
#define LION_H

#include <QObject>
#include <QDebug>
#include "../interfaces/IAnimal.h"

class Lion : public QObject, public IAnimal
{
    Q_OBJECT
public:
    explicit Lion(QObject *parent = nullptr);
    virtual ~Lion();

    void eat() override;

    void sleep() override;

    void move() override;
signals:

};

#endif // LION_H
