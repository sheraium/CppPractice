#include "HouseCat.h"

HouseCat::HouseCat(QObject *parent) : QObject(parent) {
    qInfo() << this << "Created";
}

HouseCat::~HouseCat() {
    qInfo() << this << "Destroyed";
}

void HouseCat::eat() {
    qInfo() << this << "eat";

}

void HouseCat::sleep() {
    qInfo() << this << "sleep";

}

void HouseCat::move() {
    qInfo() << this << "move";

}

