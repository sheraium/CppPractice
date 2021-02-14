#include "logadapter.h"

LogAdapter::LogAdapter(FileLogger* logger, QObject* parent) : QObject(parent)
{
    _logger = logger;
}

void LogAdapter::write(QString message)
{
    if(!_logger)    {
        qInfo() << "Please set the logger!";
        return;
    }

    QString current = QDateTime:: currentDateTime().toString();
    QString newMessage = current + " " + message;
    _logger->write(newMessage);
}

FileLogger* LogAdapter::logger() const
{
    return _logger;
}

void LogAdapter::setLogger(FileLogger* logger)
{
    _logger = logger;
}
