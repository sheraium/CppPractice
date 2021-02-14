#ifndef LOGADAPTER_H
#define LOGADAPTER_H

#include <QObject>
#include <QDateTime>
#include "filelogger.h"

class LogAdapter : public QObject
{
    Q_OBJECT
public:
     LogAdapter(FileLogger* logger, QObject* parent = nullptr);

    void write(QString message);
    FileLogger* logger() const;
    void setLogger(FileLogger* logger);

signals:

private:
    FileLogger* _logger;
};

#endif // LOGADAPTER_H
