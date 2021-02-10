#ifndef DESTINATION_H
#define DESTINATION_H

#include <QObject>
#include <QDebug>

class destination : public QObject
{
    Q_OBJECT
public:
    explicit destination(QObject *parent = nullptr);

public slots:
    void onMessage(QString message);

signals:

};

#endif // DESTINATION_H
