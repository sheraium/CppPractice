#ifndef WORKER_H
#define WORKER_H

#include <QObject>
#include <QTimer>
#include <QDebug>
#include <QDateTime>

#include <QFuture>
#include <QtConcurrent>

class Worker : public QObject {
Q_OBJECT
public:
    explicit Worker(QObject *parent = nullptr);

    virtual ~Worker();

    void start();
    QFuture<int> GetValue();
    int getValue();

signals:

public slots:

    void timeout();

private:
    QTimer timer;


};

#endif // WORKER_H
