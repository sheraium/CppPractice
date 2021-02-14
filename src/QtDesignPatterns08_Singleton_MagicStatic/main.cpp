#include <QCoreApplication>
#include <QDebug>
#include "singleton.h"
#include "myclass.h"

using namespace std;

void scopetest() {
    Singleton<MyClass>::GetInstance().setObjectName("Godzilla!");
    Singleton<MyClass>::GetInstance().display("from scope test");
}

void looptest() {
    Singleton<MyClass>::GetInstance().display("starting loop");
    for (int i = 0; i < 10; ++i) {
        Singleton<MyClass>::GetInstance().display(QString::number(i));
    }
    Singleton<MyClass>::GetInstance().display("finished loop");
}

int main(int argc, char *argv[]) {
    QCoreApplication a(argc, argv);

    scopetest();
    looptest();
    Singleton<MyClass>::GetInstance().display("hello from main");
    qInfo() << Singleton<MyClass>::GetInstance().objectName();
    return 0;
}

