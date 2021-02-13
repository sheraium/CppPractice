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

void Worker::start() {
    timer.start();
}

