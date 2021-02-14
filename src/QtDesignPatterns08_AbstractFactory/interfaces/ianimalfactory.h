#ifndef IANIMALFACTORY_H
#define IANIMALFACTORY_H

class IAnimalFactory {
public:
    virtual IAnimal *createSmall() = 0;

    virtual IAnimal *createMedium() = 0;

    virtual IAnimal *createLarge() = 0;

    virtual ~IAnimalFactory() {};
};

#endif // IANIMALFACTORY_H
