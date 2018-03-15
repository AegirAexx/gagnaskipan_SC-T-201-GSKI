#ifndef SCORE_H
#define SCORE_H

#include <ostream>

class Score
{
    public:
        Score();
        //Score(char n, int score);
        virtual ~Score();
        char name[3];
        int totalScore;

        friend bool operator < (const Score &leftScore, const Score & rightScore);
        friend std::ostream& operator << (std::ostream& out, const Score &score);
};

#endif // SCORE_H
