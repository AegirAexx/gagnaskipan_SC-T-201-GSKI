#include "score.h"

Score::Score()
{
    name = 'A';
    totalScore = 0;
}

Score::Score(char n, int score)
{
    name = n;
    totalScore = score;
}

Score::~Score()
{
    //dtor
}
