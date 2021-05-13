#include <QCoreApplication>
#include <QDebug>
#include <QFuture>
#include <QtConcurrent>

#include "worker.h"

using namespace std;


int main(int argc, char *argv[]) {
    QCoreApplication a(argc, argv);

    Worker worker;
    worker.start();


    //    QtConcurrent::run([&]{
    //        QThread::sleep(2);
    //        auto value = worker.getValue();
    //        qInfo() << "Value: " << value;
    //    });


    QtConcurrent::run([&]{
        QThread::sleep(2);
        auto result = worker.GetValue();
        qInfo() << "Value: " << result.result();
    });

    return a.exec();
}

