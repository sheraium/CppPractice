#include "worker.h"

Worker::Worker(QObject* parent) : QObject(parent) {
    timer.setInterval(1000);
    connect(&timer, &QTimer::timeout, this, &Worker::timeout);
}

Worker::~Worker() {
    timer.stop();
}

void Worker::timeout() {
    qInfo() << "Do Stuff" << QDateTime::currentDateTime().toString("yyyy-MM-dd hh:mm:ss.zzz");
}

int Worker::getValue()
{
    qInfo()<< "Start Get Value";
    qInfo() << "Current Thread: " << QThread::currentThread();
    QThread::sleep(3);
    qInfo()<<"End Get Value";
    return 123;
}

void Worker::start() {
    timer.start();
}

QFuture<int> Worker::GetValue()
{
    QFuture<int> result = QtConcurrent::run([&]{
        return this->getValue();
    });

    return result;
}

