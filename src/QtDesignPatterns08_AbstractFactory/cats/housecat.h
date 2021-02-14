#ifndef HOUSECAT_H
#define HOUSECAT_H

#include <QObject>
#include <QDebug>

#include "../interfaces/IAnimal.h"

class HouseCat : public QObject, public IAnimal
{
    Q_OBJECT
public:
    explicit HouseCat(QObject* parent = nullptr);

    virtual ~HouseCat();

    void eat() override;

    void sleep() override;

    void move() override;

signals:

};

#endif // HOUSECAT_H
