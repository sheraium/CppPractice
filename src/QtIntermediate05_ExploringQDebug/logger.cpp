#include "logger.h"

bool logger::logging = false;
bool logger::showInConsole = true;
QString logger::filename =
        QDir::currentPath() + QDir::separator()
        + "logs" + QDir::separator()
        + "logfile.log";

const QtMessageHandler QT_DEFAULT_MESSAGE_HANDLER = qInstallMessageHandler(nullptr);

logger::logger(QObject *parent) : QObject(parent) {

}

void logger::attach() {
    logger::logging = true;
    qInstallMessageHandler(logger::handler);
}

void logger::handler(QtMsgType type, const QMessageLogContext &context, const QString &msg) {
    if (logger::logging) {
        QString txt;
        switch (type) {
            case QtInfoMsg:
                txt = QString("Info| %1").arg(msg);
                break;
            case QtDebugMsg:
                txt = QString("Debug| %1").arg(msg);
                break;
            case QtWarningMsg:
                txt = QString("Warning| %1").arg(msg);
                break;
            case QtCriticalMsg:
                txt = QString("Critical| %1").arg(msg);
                break;
            case QtFatalMsg:
                txt = QString("Fatal| %1").arg(msg);
                break;
        }

        int pos = logger::filename.lastIndexOf(QDir::separator());
        QString parent = logger::filename.mid(0, pos);
        QDir dir(parent);
        if(!dir.exists()){
            dir.mkpath(parent);
        }

        QFile file(logger::filename);
        if (file.open(QIODevice::WriteOnly | QIODevice::Append)) {
            QTextStream ts(&file);
            ts << QDateTime::currentDateTime().toString("yyyy-MM-dd hh:mm:ss.zzz")
               << "|" << txt
               << "| file: " << context.file
               << " line: " << context.line
               << endl;
            ts.flush();
            file.close();
        }
    }

    if (logger::showInConsole) {
        (*QT_DEFAULT_MESSAGE_HANDLER)(type, context, msg);
    }
}
