#include <QCoreApplication>
#include <QDebug>
#include <QDate>
#include <QTime>
#include <QDateTime>
#include <QVariant>

#include "dog.h"
#include "cat.h"

using namespace std;

void printQObject(QObject *obj) {
    qInfo() << obj;
}

void printQVariant(QVariant value) {
    qInfo() << value;
    int test = 0;
    bool ok = false;
    test = value.toInt(&ok);
    if (ok) {
        qInfo() << "INT = " << test;
    } else {
        qInfo() << "Not a number!";
    }
}

int main(int argc, char *argv[]) {
    QCoreApplication a(argc, argv);

    // QObject
    cat kitty;
    dog fido;
    kitty.setObjectName("Fluffy");
    fido.setObjectName("Doggy");
    printQObject(&kitty);
    printQObject(&fido);

    // Qint
    qint8 value8 = 0;
    qint16 value16 = 0;
    qint32 value32 = 0;
    qint64 value64 = 0;
    qintptr valueptr = 0;
    qInfo() << "value8: " << sizeof(value8);

    // QString
    QString name = "Bryan Cairns";
    qInfo() << name.mid(1, 3);
    qInfo() << name.insert(0, "Mr. ");
    qInfo() << name.split(" ");
    int index = name.indexOf(".");
    qInfo() << name.remove(0, index + 1).trimmed();

    // QDate, QTime, QDatetime
    QDate today = QDate::currentDate();
    qInfo() << today;
    qInfo() << today.addDays(1);
    qInfo() << today.addYears(20);
    qInfo() << today.toString(Qt::SystemLocaleDate);
    qInfo() << today.toString(Qt::DateFormat::TextDate);
    QTime now = QTime::currentTime();
    qInfo() << now;
    qInfo() << now.toString(Qt::DateFormat::DefaultLocaleLongDate);
    qInfo() << now.toString(Qt::DateFormat::DefaultLocaleShortDate);
    QDateTime current = QDateTime::currentDateTime();
    qInfo() << "current: " << current;
    QDateTime expire = current.addDays(45);
    qInfo() << "expire: " << expire;
    if (current > expire) {
        qInfo() << "Expired!";
    } else {
        qInfo() << "Not expired";
    }

    // QByteArray
    QString greeting = "Hello World";
    QByteArray buffer(greeting.toLatin1());
    buffer.append("!");
    qInfo() << buffer;
    qInfo() << buffer.rightJustified(20, '.');
    qInfo() << buffer.at(buffer.length() - 1);
    QString modified(buffer);
    qInfo() << modified;

    // QVariant
    QVariant value = 1;
    QVariant value2 = "Hello World";
    printQVariant(value);
    printQVariant(value2);

    // QStringList
    QString data = "Hello World, how are you";
    QStringList list = data.split(" ");
    qInfo() << list;
            foreach(QString str, list) {
            qInfo() << str;
        }
    list.sort(Qt::CaseInsensitive);
    qInfo() << list;
    QString myvar = "Hello";
    if (list.contains(myvar)) {
        int index = list.indexOf(myvar);
        qInfo() << list.value(index);
    }

    // QList
    QList<QString> listStr = data.split(" ");
    listStr.insert(3, "zzz");
            foreach(QString str, listStr) {
            qInfo() << str;
        }
    QList<int> ages({44, 56, 21, 13});
            foreach(int age, ages) {
            qInfo() << age;
        }

    // QVector
    QVector<int> nums({44, 56, 21, 13});
            foreach(int num, nums) {
            qInfo() << num;
        }

    return 0;
}

