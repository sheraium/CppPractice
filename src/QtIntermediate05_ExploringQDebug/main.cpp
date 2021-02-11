#include <QCoreApplication>
#include <QDebug>

#include "logger.h"

using namespace std;

Q_DECLARE_LOGGING_CATEGORY(network);
Q_LOGGING_CATEGORY(network, "network");

int main(int argc, char *argv[]) {
    QCoreApplication a(argc, argv);

    qInfo() << "File: " << logger::filename;
    logger::attach();

    qInfo() << "This is a info message";
    qDebug() << "This is a debug message";
    qWarning() << "This is a warning message";
    qCritical() << "This is a critical message";
    qFatal("This is a fatal message");

    if (!network().isDebugEnabled()) {
        QLoggingCategory::setFilterRules("network.debug=true");
        qDebug(network) << "kitty";
    }
    qDebug(network) << "Debug";

    return 0;
}

