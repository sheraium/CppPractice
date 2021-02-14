#ifndef CATFACTORY_H
#define CATFACTORY_H

#include <QObject>
#include "housecat.h"
#include "bobcat.h"
#include "lion.h"
#include "../interfaces/ianimalfactory.h"

class CatFactory : public QObject, public IAnimalFactory
{
    Q_OBJECT
public:
    explicit CatFactory(QObject *parent = nullptr);

    IAnimal *createSmall() override;

    IAnimal *createMedium() override;

    IAnimal *createLarge() override;

signals:

};

#endif // CATFACTORY_H
