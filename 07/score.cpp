#include "score.h"

Score::Score()
{
    totalScore = 0;
}
/*
Score::Score(char n, int score)
{
    name = n;
    totalScore = score;
}*/

Score::~Score()
{
    //dtor
}

 bool operator < (const Score &leftScore, const Score & rightScore) {
    return leftScore.totalScore < rightScore.totalScore;
 }

std::ostream& operator << (std::ostream& out, const Score &score) {
    out << "Name: ";

    for(int i = 0; i < 3; i++) {
        out << score.name[i];
    }

    out << "Score: " << score.totalScore << std::endl;

    return out;
 }
