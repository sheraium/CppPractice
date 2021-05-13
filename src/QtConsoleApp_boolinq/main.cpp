#include <QCoreApplication>
#include <QDebug>
#include <QMap>

#include "boolinq.h"

using namespace std;
using namespace boolinq;

struct Man {
    QString name;
    int age;
};


int main(int argc, char *argv[]) {
    QCoreApplication a(argc, argv);

    double value = 1.2345;
    QString str = QString::number(value, 'f', 0);


    int num[] = {1,2,3,4,5,6,7,8,9,10};

    auto first = from(num).first();
    qInfo()<< first;
    auto anyGreaterThan5 = from(num).count([](const int &x){return x> 5;});
    qInfo() << anyGreaterThan5;

    Man Kevin;
    Kevin.name = "Kevin";
    Kevin.age = 14;

    Man Anton;
    Anton.name = "Anton";
    Anton.age = 18;

    Man Terra;
    Terra.name = "Terra";
    Terra.age = 17;


    QMap<QString, Man> map;
    map.insert("Kevin", Kevin);
    map.insert("Anton", Anton);
    map.insert("Terra", Terra);

    foreach(auto d, map){
        qInfo() << d.name;
    }

    try {
        auto data = from(map)
                .orderBy([](const Man &man){return man.age;})
                .where([](const Man &man){return man.age>=17;})
                .select([](const Man &man){ return man; })
                .toStdList();

//        auto list = QList<QString>::fromStdList(data);

        foreach(auto d, data){
            qInfo() << d.name;
        }

    } catch (char* e){
        qWarning() << "We caught a pointer to char* " << e;
    } catch (exception const& e) {
        qInfo()<< e.what();
    }
    catch (...){
        qInfo()<<"Error";
    }

    return a.exec();
}

