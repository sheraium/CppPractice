#ifndef CATFACTORY_H
#define CATFACTORY_H

#include <QObject>

class CatFactory : public QObject
{
    Q_OBJECT
public:
    explicit CatFactory(QObject *parent = nullptr);

signals:

};

#endif // CATFACTORY_H
