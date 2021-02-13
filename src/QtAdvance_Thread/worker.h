#ifndef WORKER_H
#define WORKER_H

#include <QObject>
#include <QTimer>
#include <QDebug>
#include <QDateTime>

class Worker : public QObject {
Q_OBJECT
public:
    explicit Worker(QObject *parent = nullptr);

    virtual ~Worker();

    void start();


signals:

public slots:

    void timeout();

private:
    QTimer timer;

};

#endif // WORKER_H
