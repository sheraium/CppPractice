#ifndef TST_TENNISTESTCASE_H
#define TST_TENNISTESTCASE_H

#include <gtest/gtest.h>
#include <gmock/gmock-matchers.h>
#include <QDebug>
#include "tennis.h"

using namespace testing;

class TennisTests : public Test {
protected:
    tennis *target;

    TennisTests() {
        target = new tennis("Joey", "Tom");
    }

    ~TennisTests() {
        delete target;
    }

    virtual void SetUp() {
        qInfo() << "SetUp";
    }

    virtual void TearDown() {
        qInfo() << "TearDown";
    }

    void GivenDeuce() {
        GivenFirstPlayerScoreTimes(3);
        GivenSecondPlayerScore(3);
    }

    void GivenSecondPlayerScore(int times) {
        for (int i = 0; i < times; ++i) {
            target->SecondPlayerScore();
        }
    }

    void GivenFirstPlayerScoreTimes(int times) {
        for (int i = 0; i < times; ++i) {
            target->FirstPlayerScore();
        }
    }

    void ScoreShouldBe(const char *expect) {
        QString score = target->Score();
        ASSERT_EQ(score, expect);
    }
};


TEST_F(TennisTests, love_all) {
    ScoreShouldBe("Love All");
}

TEST_F(TennisTests, fifteen_love) {
    GivenFirstPlayerScoreTimes(1);
    ScoreShouldBe("Fifteen Love");
}

TEST_F(TennisTests, thirty_love) {
    GivenFirstPlayerScoreTimes(2);
    ScoreShouldBe("Thirty Love");
}

TEST_F(TennisTests, forty_love) {
    GivenFirstPlayerScoreTimes(3);
    ScoreShouldBe("Forty Love");
}

TEST_F(TennisTests, love_fifteen) {
    GivenSecondPlayerScore(1);
    ScoreShouldBe("Love Fifteen");
}

TEST_F(TennisTests, love_thirty) {
    GivenSecondPlayerScore(2);
    ScoreShouldBe("Love Thirty");
}

TEST_F(TennisTests, fifteen_all) {
    GivenFirstPlayerScoreTimes(1);
    GivenSecondPlayerScore(1);
    ScoreShouldBe("Fifteen All");
}

TEST_F(TennisTests, thirty_all) {
    GivenFirstPlayerScoreTimes(2);
    GivenSecondPlayerScore(2);
    ScoreShouldBe("Thirty All");
}

TEST_F(TennisTests, deuce) {
    GivenDeuce();
    ScoreShouldBe("Deuce");
}

TEST_F(TennisTests, firstPlayer_adv) {
    GivenDeuce();
    GivenFirstPlayerScoreTimes(1);
    ScoreShouldBe("Joey Adv");
}

TEST_F(TennisTests, secondPlayer_adv) {
    GivenDeuce();
    GivenSecondPlayerScore(1);
    ScoreShouldBe("Tom Adv");
}

TEST_F(TennisTests, secondPlayer_win) {
    GivenDeuce();
    GivenSecondPlayerScore(2);
    ScoreShouldBe("Tom Win");
}


#endif // TST_TENNISTESTCASE_H
