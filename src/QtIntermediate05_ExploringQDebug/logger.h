#ifndef LOGGER_H
#define LOGGER_H

#include <QObject>
#include <QDir>
#include <QTextStream>
#include <QDateTime>
#include <QLoggingCategory>

class logger : public QObject {
Q_OBJECT
public:
    explicit logger(QObject *parent = nullptr);

    static bool logging;
    static bool showInConsole;
    static QString filename;

    static void attach();

    static void handler(QtMsgType type, const QMessageLogContext &context, const QString &msg);

signals:

};

#endif // LOGGER_H
