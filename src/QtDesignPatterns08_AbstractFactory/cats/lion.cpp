#include "lion.h"


Lion::Lion(QObject *parent) : QObject(parent) {
    qInfo() << this << "Created";
}

Lion::~Lion() {
    qInfo() << this << "Destroyed";
}

void Lion::eat() {
    qInfo() << this << "eat";

}

void Lion::sleep() {
    qInfo() << this << "sleep";

}

void Lion::move() {
    qInfo() << this << "move";

}