#include "longdelay.h"

LongDelay::LongDelay(QObject *parent) : QObject(parent) {
    complete = false;
}

void LongDelay::delay(int ms) {
    complete = false;
    timer.singleShot(ms, this, &LongDelay::timeout);
}

bool LongDelay::isComplete() {
    return complete;
}

void LongDelay::timeout() {
    complete = true;
}
