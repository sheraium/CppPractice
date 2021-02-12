#ifndef TENNIS_H
#define TENNIS_H

#include <QtCore>
#include <QMap>
#include <QtMath>

class tennis {
public:
    tennis(QString firstPlayer, QString secondPlayer);

    QString Score();

    void FirstPlayerScore();

    void SecondPlayerScore();

private:
    QString firstPlayerName;
    QString secondPlayerName;
    int firstPlayerScoreTimes;
    int secondPlayerScoreTimes;
    QMap<int, QString> scoreMap;

    QString SameScore();

    QString AdvPlayer();

    bool IsGamePoint() const;

    int IsAdv() const;

    bool IsDifferent() const;

    QString LookupScore();

    bool IsDeuce() const;
};

#endif // TENNIS_H
