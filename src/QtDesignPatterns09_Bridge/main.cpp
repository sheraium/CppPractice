#include <QCoreApplication>
#include <QDebug>

using namespace std;
#include "simplelogger.h"
#include "advancedlogger.h"

void log(iLogger *logger)
{
    for(int i = 0; i < 5; i++)
    {
        logger->write("Item" + QString::number(i));
    }
}
int main(int argc, char *argv[]) {
    QCoreApplication a(argc, argv);
    SimpleLogger slog;
    AdvancedLogger alog;

    log(&slog);
    log(&alog);
    return 0;
}

