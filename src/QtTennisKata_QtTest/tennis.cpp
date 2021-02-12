#include "tennis.h"

tennis::tennis(QString firstPlayer, QString secondPlayer) {
    firstPlayerName = firstPlayer;
    secondPlayerName = secondPlayer;
    firstPlayerScoreTimes = 0;
    secondPlayerScoreTimes = 0;
    scoreMap.insert(0, "Love");
    scoreMap.insert(1, "Fifteen");
    scoreMap.insert(2, "Thirty");
    scoreMap.insert(3, "Forty");
}

QString tennis::Score() {

    if (IsDifferent()) {
        if (IsGamePoint()) {
            if (IsAdv()) {
                return AdvPlayer() + " Adv";
            }
            return AdvPlayer() + " Win";
        }
        return LookupScore();
    }
    if (IsDeuce()) {
        return "Deuce";
    }
    return SameScore();
}

bool tennis::IsDeuce() const { return firstPlayerScoreTimes >= 3; }

QString tennis::LookupScore() { return scoreMap[firstPlayerScoreTimes] + " " + scoreMap[secondPlayerScoreTimes]; }

bool tennis::IsDifferent() const { return firstPlayerScoreTimes != secondPlayerScoreTimes; }

int tennis::IsAdv() const { return qAbs(firstPlayerScoreTimes - secondPlayerScoreTimes) == 1; }

bool tennis::IsGamePoint() const { return firstPlayerScoreTimes >= 3 && secondPlayerScoreTimes >= 3; }

QString tennis::AdvPlayer() {
    return firstPlayerScoreTimes > secondPlayerScoreTimes
           ? firstPlayerName : secondPlayerName;
}

QString tennis::SameScore() { return scoreMap[firstPlayerScoreTimes] + " All"; }

void tennis::FirstPlayerScore() {
    firstPlayerScoreTimes++;
}

void tennis::SecondPlayerScore() {
    secondPlayerScoreTimes++;
}
