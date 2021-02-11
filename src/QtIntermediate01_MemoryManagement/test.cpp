#include <QDebug>
#include "test.h"

test::test(QObject *parent) : QObject(parent) {
    qInfo() << this << "Constructed";
}

test::~test() {
    qInfo() << this << "Deconstructed";
}

void test::makeChile(QString name) {
    test *child = new test(this);
    child->setObjectName(name);
}

void test::useWidget() {
    if (!widget.data()) {
        qInfo() << "No Pointer!!!";
        return;
    }

    qInfo() << "widget = " << widget.data();
    widget.data()->setObjectName("used Widget!");
}
