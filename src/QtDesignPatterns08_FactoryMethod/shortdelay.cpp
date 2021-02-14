#include "shortdelay.h"

ShortDelay::ShortDelay(QObject *parent) : QObject(parent) {
    complete = false;
}

ShortDelay::~ShortDelay() {

}

void ShortDelay::delay(int ms) {
    complete = false;
    QThread::currentThread()->msleep(ms);
    complete = true;
}

bool ShortDelay::isComplete() {
    return complete;
}
