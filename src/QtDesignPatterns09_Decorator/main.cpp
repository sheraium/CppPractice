#include <QCoreApplication>
#include <QDebug>
#include <QString>
#include "text.h"
#include "boldtext.h"
#include "italictext.h"

using namespace std;

int main(int argc, char *argv[]) {
    QCoreApplication a(argc, argv);
    QString value = "text";
    Text t(new BoldText(new ItalicText(&a)));
    t.process(value);

    qInfo() << value;

    return 0;
}

