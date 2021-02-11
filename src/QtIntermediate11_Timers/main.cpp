#include <QCoreApplication>
#include <QDebug>
#include <QTimer>

#include "test.h"

using namespace std;

void print() {
    qInfo() << "Thank you for waiting!";
}

int main(int argc, char *argv[]) {
    QCoreApplication a(argc, argv);
    QTimer::singleShot(5000, &print);

    test t;
    t.doStuff();


    return a.exec();
}

