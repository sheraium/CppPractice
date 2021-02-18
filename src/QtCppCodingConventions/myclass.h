#ifndef MYCLASS_H
#define MYCLASS_H

// C/C++ 標準庫， Qt庫
#include <iostream>
#include <QObject>

// 自定義類別 Header file


class MyClass : public QObject
{
    Q_OBJECT
public:
    explicit MyClass(QObject* parent = nullptr);

signals:

};

#endif // MYCLASS_H
