#ifndef TEST_H
#define TEST_H

#include <QObject>
#include <QPointer>

class test : public QObject
{
    Q_OBJECT
public:
    explicit test(QObject *parent = nullptr);

    virtual ~test();

    void makeChile(QString name);

    QPointer<QObject> widget;
    void useWidget();

signals:

};

#endif // TEST_H
