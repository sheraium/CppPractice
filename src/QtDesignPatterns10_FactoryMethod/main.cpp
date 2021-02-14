#include <QCoreApplication>
#include <QDebug>
#include <QTimer>
#include <QSharedPointer>
#include <QTextStream>
#include "interfaces/idelay.h"
#include "longdelay.h"
#include "shortdelay.h"

using namespace std;

QSharedPointer<IDelay> ptr;
QSharedPointer<QTimer> timer;

void timeout() {
    qInfo() << "Do other things while we wait...";
    if (ptr->isComplete()) {
        timer->stop();
        qInfo() << "Complete";
    }
}

IDelay *getDelay(int ms) {
    if (ms < 100) {
        qInfo() << "Returning short delay";
        return new ShortDelay();
    }

    qInfo() << "Returning long delay";
    return new LongDelay();
}

int getTimeout() {
    QTextStream stream(stdin);
    qInfo() << "Enter the number of milliseconds to delay";

    QString data = stream.readLine();
    bool isOk;
    int value = data.toInt(&isOk);
    if (isOk)return value;
    return getTimeout();
}

int main(int argc, char *argv[]) {
    QCoreApplication a(argc, argv);

    timer.reset(new QTimer);
    timer->setInterval(1000);
    QObject::connect(&a, &QCoreApplication::aboutToQuit, timer.data(), &QTimer::stop);
    QObject::connect(timer.data(), &QTimer::timeout, timeout);

    int value = getTimeout();
    ptr.reset(getDelay(value));
    timer->start();
    ptr->delay(value);

    return a.exec();
}

