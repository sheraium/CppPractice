#include <QCoreApplication>
#include <QDebug>
#include <QRandomGenerator>
#include "cats/catfactory.h"
#include "interfaces/ianimal.h"

using namespace std;

void makeAnimals(QList<IAnimal *> &animals, int count) {
    CatFactory factory;

    for (int i = 0; i < count; ++i) {
        IAnimal *animal;
        int value = QRandomGenerator::global()->bounded(0, 3);

        switch (value) {
            case 0:
                animal = factory.createSmall();
                break;
            case 1:
                animal = factory.createMedium();
                break;
            case 2:
                animal = factory.createLarge();
                break;
            default:
                qInfo() << "OTHER";
        }

        animals.append(animal);
    }
}

int main(int argc, char *argv[]) {
    QCoreApplication a(argc, argv);

    QList<IAnimal*> animals;
    makeAnimals(animals, 25);

    foreach(IAnimal *animal, animals){
        animal->eat();
        animal->sleep();
    }

    qDeleteAll(animals);
    animals.clear();

    return a.exec();
}

