#ifndef BOBCAT_H
#define BOBCAT_H

#include <QObject>
#include <QDebug>
#include "../interfaces/IAnimal.h"

class BobCat : public QObject, public IAnimal
{
    Q_OBJECT
public:
    explicit BobCat(QObject *parent = nullptr);
    virtual ~BobCat();

    void eat() override;

    void sleep() override;

    void move() override;
signals:

};

#endif // BOBCAT_H
