#include <QWidget>
#include <QApplication>
#include <QDebug>

#include "animal.h"


int main(int argc, char *argv[]) {
    QApplication a(argc, argv);

    animal cat;
    animal dot;
    animal bird;

    cat.speak("meow");
    dot.speak("bark");
    bird.speak("caw");

    return 0;
}

