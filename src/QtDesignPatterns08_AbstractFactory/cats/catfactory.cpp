#include "catfactory.h"

CatFactory::CatFactory(QObject *parent) : QObject(parent)
{

}

IAnimal *CatFactory::createSmall() {
    return new HouseCat();
}

IAnimal *CatFactory::createMedium() {
    return new BobCat();
}

IAnimal *CatFactory::createLarge() {
    return new Lion();
}
