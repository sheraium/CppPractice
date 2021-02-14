#include "mypoolitem.h"

MyPoolItem::MyPoolItem(QObject *parent) : QObject(parent) {
    m_aquired = false;
}

void MyPoolItem::setAquired(bool aquired) {
    qInfo() << this << "aquired" << aquired;
    m_aquired = aquired;
}

void MyPoolItem::test() {
    qInfo() << this << "test";
}

MyPoolItem::~MyPoolItem() {

}

void MyPoolItem::reset() {
    m_aquired = false;
}

bool MyPoolItem::aquired() {
    return m_aquired;
}




