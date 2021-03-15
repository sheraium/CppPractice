#include <QCoreApplication>
#include <QDebug>
#include <QTimer>
#include <QThread>

#include "test.h"
#include "testb.h"

using namespace std;

void print() {
    qInfo() << "Thank you for waiting!";
}

int main(int argc, char* argv[]) {
    QCoreApplication a(argc, argv);
//    QTimer::singleShot(5000, &print);

    QThread thread(&a);

    test t;
    TestB b;

    t.moveToThread(&thread);
    thread.start();

    t.doStuff();
    b.doStuff();

    return a.exec();
}

