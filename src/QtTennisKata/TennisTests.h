#ifndef TENNISTESTS_H
#define TENNISTESTS_H

#include <QObject>
#include <QDebug>
#include <QtTest/QtTest>
#include <QtTest>

#include "tennis.h"

class TennisTests : public QObject {
Q_OBJECT
public:
    explicit TennisTests(QObject *parent = nullptr);

signals:
public slots:

    void test();

private:
    tennis *target;
    void ScoreShouldBe(QString expect);
    void GivenFirstPlayerScoreTimes(int times);
    void GivenSecondPlayerScore(int times);
    void GivenDeuce();

private slots:

    // call befor the first test
    void initTestCase();

    // call before each test
    void init();

    // call after each test
    void cleanup();

    // call after the last test
    void cleanupTestCase();

    void love_all();

    void fifteen_love();

    void thirty_love();

    void forty_love();

    void love_fifteen();


    void love_thirty();

    void fifteen_all();

    void thirty_all();

    void deuce();


    void firstPlayer_adv();

    void secondPlayer_adv();

    void secondPlayer_win();
};

#endif // TENNISTESTS_H
