#include "bobcat.h"

BobCat::BobCat(QObject *parent) : QObject(parent) {
    qInfo() << this << "Created";
}

BobCat::~BobCat() {
    qInfo() << this << "Destroyed";
}

void BobCat::eat() {
    qInfo() << this << "eat";

}

void BobCat::sleep() {
    qInfo() << this << "sleep";

}

void BobCat::move() {
    qInfo() << this << "move";

}