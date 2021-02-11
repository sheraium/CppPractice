#include <QCoreApplication>
#include <QDebug>
#include <QPointer>
#include <QScopedPointer>
#include <QSharedPointer>

#include "test.h"
#include "consumer.h"

using namespace std;

void doDeleteLater(test *obj) {
    qInfo() << "Deleting: " << obj;
    obj->deleteLater();
}

QSharedPointer<test> createPointer() {
    test *t = new test();// the bad way!!!
    t->setObjectName("Test Object");
    QSharedPointer<test> p(t, doDeleteLater);
    return p;
}

void doStuff1(QSharedPointer<consumer> ptr) {
    qInfo() << "In function: " << ptr.data()->tester;
    ptr.clear(); // Does not actually delete!, just removes the reference
}

QSharedPointer<consumer> makeConsumer() {
    QSharedPointer<consumer> c(new consumer, &QObject::deleteLater);
    QSharedPointer<test> t = createPointer();
    c.data()->tester.swap(t);
    doStuff1(c);
    return c;
}

//void myTest(QScopedPointer<test> myPointer) {
void myTest(QScopedPointer<test> &myPointer) {
    qInfo() << myPointer.data();
}

void useIt(test *obj) {
    if (!obj)return;
    qInfo() << "Using" << obj;
}

void doStuff() {
    QScopedPointer<test> myPointer(new test());
//    useIt(myPointer.data());
    myTest(myPointer);
}

int main(int argc, char *argv[]) {
    QCoreApplication a(argc, argv);

    // Parent Child Relationships
    test *p = new test(&a);
    p->setObjectName("parent");
    for (int i = 0; i < 5; ++i) {
        p->makeChile(QString::number(i));
    }
    delete p;

    // QPointer
    QObject *obj1 = new QObject(nullptr);
    obj1->setObjectName("My Object");
    QPointer<QObject> p1(obj1);
    test t1;
    t1.widget = p1;
    t1.useWidget();
    if (p1.data()) qInfo() << p1.data();
    delete obj1;
    t1.useWidget();

    // QScopedPointer
    for (int i = 0; i < 100; ++i) {
        doStuff();
    }

    // QSharedPointer
    QSharedPointer<consumer> consume = makeConsumer();
    qInfo() << "In main: " << consume.data()->tester;
    consume.clear();

    return 0;
}

