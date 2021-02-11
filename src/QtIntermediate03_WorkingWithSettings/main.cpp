#include <QCoreApplication>
#include <QDebug>
#include <QSettings>
#include <QStringList>
#include <QRandomGenerator>

void saveAge(QSettings *settings, QString group, QString name, int age) {
    settings->beginGroup(group);
    settings->setValue(name, age);
    settings->endGroup();
}

int getAge(QSettings *settings, QString group, QString name) {
    settings->beginGroup(group);
    if (!settings->contains(name)) {
        qWarning() << "Does not contain " << name << " in " << group;
        settings->endGroup();
        return 0;
    }
    bool ok;
    int value = settings->value(name).toInt(&ok);
    settings->endGroup();
    if (!ok) {
        qWarning() << "Failed to convert to int!!!";
        settings->endGroup();
        return 0;
    }
    return value;
}

using namespace std;

int main(int argc, char *argv[]) {
    QCoreApplication a(argc, argv);

    QCoreApplication::setOrganizationName("VoidRealms");
    QCoreApplication::setOrganizationDomain("VoidRealms.com");
    QCoreApplication::setApplicationName("Tester");

    QSettings settings(QCoreApplication::organizationName(), QCoreApplication::applicationName());
    // Save the setting
//    settings.setValue("test", 123);
    // Read the setting back
//    qInfo() << settings.value("test").toString();
//    qInfo() << settings.value("test").toInt();

    // Groups
    const char *groupPeople = "people";
    const char *groupBeer = "beer";
    saveAge(&settings, groupPeople, "Bryan", 44);
    saveAge(&settings, groupBeer, "TwoHeart", 1);
    saveAge(&settings, groupBeer, "Bryan", 11);
    qInfo() << "TwoHeart" << getAge(&settings, groupBeer, "Bryan");
    qInfo() << "Bryan (people)" << getAge(&settings, groupPeople, "Bryan");
    qInfo() << "Bryan (beer)" << getAge(&settings, groupBeer, "Bryan");

    // Navigating groups
    QStringList people;
    people << "Bryan" << "Tammy" << "Hea" << "Chr";
            foreach(QString person, people) {
            int value = QRandomGenerator::global()->bounded(100);
            saveAge(&settings, "test", person, value);
        }
    settings.sync();
    qInfo() << settings.fileName();
    foreach(QString group, settings.childGroups()){
        settings.beginGroup(group);
        qInfo()<<"Group: "<<group;
        foreach(QString key, settings.childKeys()){
            qInfo()<<"... key:"<<key<< " = "<< settings.value(key).toString();
        }
        settings.endGroup();
    }

    return 0;
}

