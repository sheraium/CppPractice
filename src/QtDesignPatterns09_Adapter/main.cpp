#include <QCoreApplication>
#include <QDebug>
#include "filelogger.h"
#include "logadapter.h"

using namespace std;

int main(int argc, char *argv[]) {
    QCoreApplication a(argc, argv);
    QString message = "Hello from legacy system";
    FileLogger logger;

//    logger.write(message);

    LogAdapter adapter(&logger);
//    adapter.setLogger(&logger);
    adapter.write("Hello new system");
    return 0;
}

