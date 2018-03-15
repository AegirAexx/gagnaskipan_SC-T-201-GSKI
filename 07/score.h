#ifndef SCORE_H
#define SCORE_H


class Score
{
    public:
        Score();
        Score(char n, int score);
        virtual ~Score();
        char name;
        int totalScore;
};

#endif // SCORE_H
