#include <QCoreApplication>
#include <QDebug>
#include <Qvector>
#include <QHash>
#include <QSet>
#include <QMap>
#include <QLinkedList>

using namespace std;

template<class T>
void fill(T &container) {
    for (int i = 0; i < 5; ++i) {
        container.append(i);
    }
}

template<class T>
void display(T &container) {
    for (int i = 0; i < container.length(); ++i) {
        if (i > 0) {
            auto current = reinterpret_cast<std::uintptr_t>(&container.at(i));
            auto previous = reinterpret_cast<std::uintptr_t>(&container.at(i - 1));
            auto distance = current - previous;
            qInfo() << i << "At: " << current << " Previous: " << previous << " Display: " << distance;
        } else {
            qInfo() << i << &container.at(i) << "Distance: 0";
        }
    }
}


int main(int argc, char *argv[]) {
    QCoreApplication a(argc, argv);

    // QList vs QVector
    QVector<int> vect = QVector<int>();
    QList<int> list = QList<int>();
    fill(vect);
    fill(list);
    qInfo() << "Int takes " << sizeof(int) << " bytes of ram";
    qInfo() << "QVector uses continuous locations in memory!";
    display(vect);
    qInfo("");
    qInfo() << "QList uses what ever it can find in memory";
    display(list);
    qInfo("");

    // QHash
    QHash<QString, int> ages;
    ages.insert("Bryan", 44);
    ages.insert("Tammy", 49);
    ages.insert("Hea", 25);
    ages.insert("chr", 27);
    ages.insert("rang", 15);
    qInfo() << "Bryan is " << ages["Bryan"] << "years old";
    qInfo() << "Keys: " << ages.keys();
    qInfo() << "Size: " << ages.size();
    // @formatter:off
    foreach(QString key, ages.keys()) {
        qInfo() << key << " = " << ages[key];
    }
    // @formatter:on

    // QSet, Notice this is out of order!!!
    QSet<QString> people;
    people << "Bryan" << "Hea" << "Tammy" << "Chr";
    people.insert("Rango");
    // @formatter:off
    foreach(QString person, people) {
        qInfo() << person;
    }
    // @formatter:on
    // Very fast
    qInfo() << "Bryan in collection: " << people.contains("Bryan");

    // QMap
    QMap<QString, int> ages1;
    ages1.insert("Bryan", 44);
    ages1.insert("Tammy", 49);
    ages1.insert("Rango", 15);
    qInfo() << "Bryan is " << ages1["Bryan"] << " year old";
    qInfo() << "Keys: " << ages1.keys();
    // @formatter:off
    // Ordered, a little slower
    foreach(QString key, ages1.keys()) {
        qInfo() << key<<" = "<< ages1[key];
    }
    // @formatter:on

    // QLinkedList
    QLinkedList<int> list1;
    for (int i = 0; i < 10; ++i) {
        list1.append(i);
    }
    list1.removeFirst();
    list1.removeLast();
    list1.removeOne(5);
    if(list.contains(3)) qInfo()<< "Contains 3";

    return 0;
}

