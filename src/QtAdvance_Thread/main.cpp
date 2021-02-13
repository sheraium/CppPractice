#include <QCoreApplication>
#include <QDebug>

#include "worker.h"

using namespace std;


int main(int argc, char *argv[]) {
    QCoreApplication a(argc, argv);

    Worker worker;
    worker.start();


    return a.exec();
}

