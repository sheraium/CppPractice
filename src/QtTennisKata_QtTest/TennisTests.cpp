#include "TennisTests.h"

TennisTests::TennisTests(QObject *parent) : QObject(parent) {

}

void TennisTests::test() {
    qInfo() << "Start tests...";
}

void TennisTests::initTestCase() {
    qInfo() << "initTestCase...";
}

void TennisTests::init() {
    qInfo() << "init...";
    target = new tennis("Joey", "Tom");
}

void TennisTests::cleanup() {
    qInfo() << "cleanup...";
    delete target;
}

void TennisTests::cleanupTestCase() {
    qInfo() << "cleanupTestCase...";
}

void TennisTests::love_all() {
    ScoreShouldBe("Love All");
}

void TennisTests::fifteen_love() {
    GivenFirstPlayerScoreTimes(1);
    ScoreShouldBe("Fifteen Love");
}

void TennisTests::thirty_love() {
    GivenFirstPlayerScoreTimes(2);
    ScoreShouldBe("Thirty Love");
}

void TennisTests::forty_love() {
    GivenFirstPlayerScoreTimes(3);
    ScoreShouldBe("Forty Love");
}

void TennisTests::love_fifteen() {
    GivenSecondPlayerScore(1);
    ScoreShouldBe("Love Fifteen");
}

void TennisTests::love_thirty() {
    GivenSecondPlayerScore(2);
    ScoreShouldBe("Love Thirty");
}
void TennisTests::fifteen_all() {
    GivenFirstPlayerScoreTimes(1);
    GivenSecondPlayerScore(1);
    ScoreShouldBe("Fifteen All");
}
void TennisTests::thirty_all() {
    GivenFirstPlayerScoreTimes(2);
    GivenSecondPlayerScore(2);
    ScoreShouldBe("Thirty All");
}
void TennisTests::deuce() {
    GivenDeuce();
    ScoreShouldBe("Deuce");
}
void TennisTests::firstPlayer_adv() {
    GivenDeuce();
    GivenFirstPlayerScoreTimes(1);
    ScoreShouldBe("Joey Adv");
}
void TennisTests::secondPlayer_adv() {
    GivenDeuce();
    GivenSecondPlayerScore(1);
    ScoreShouldBe("Tom Adv");
}
void TennisTests::secondPlayer_win() {
    GivenDeuce();
    GivenSecondPlayerScore(2);
    ScoreShouldBe("Tom Win");
}

void TennisTests::GivenDeuce() {
    GivenFirstPlayerScoreTimes(3);
    GivenSecondPlayerScore(3);
}

void TennisTests::GivenSecondPlayerScore(int times) {
    for (int i = 0; i < times; ++i) {
        target->SecondPlayerScore();
    }
}

void TennisTests::GivenFirstPlayerScoreTimes(int times) {
    for (int i = 0; i < times; ++i) {
        target->FirstPlayerScore();
    }
}

void TennisTests::ScoreShouldBe(QString expect) {
    QString score = target->Score();
    QCOMPARE(score, expect);
}

