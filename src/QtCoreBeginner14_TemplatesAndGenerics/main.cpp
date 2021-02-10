#include <QCoreApplication>
#include <QDebug>

#include "test.h"

using namespace std;

template<typename T>
void print(T value) {
    qInfo() << value;
}

template<class F1, class F2>
F1 add(F1 value1, F2 value2) {
    return value1 + value2;
}

int main(int argc, char *argv[]) {
    QCoreApplication a(argc, argv);

    print<int>(1);
    print<double>(126.007);
    print<QString>("Hello world");

    qInfo() << add(1, 4.6);
    qInfo() << add(55, true);
//    qInfo() << add(55, "Hello world"); // fail!!

    test<int> intCalc;
    qInfo() << intCalc.add(1, 4);

    return 0;
}

