//#include <QCoreApplication>
//#include <QDebug>
//#include <QtTest>

//#include "TennisTests.h"

//using namespace std;

//int main(int argc, char *argv[]) {
//    QCoreApplication a(argc, argv);

//    TennisTests tester;
//    QTest::qExec(&tester);
//    return 0;

//}

#include <QTest>
#include "TennisTests.h"

QTEST_MAIN(TennisTests);
