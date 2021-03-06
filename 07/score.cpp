#include "score.h"

Score::Score(): totalScore(0) {}

Score::~Score() {}

 bool operator < (const Score& leftScore, const Score& rightScore) {
    return leftScore.totalScore < rightScore.totalScore;
 }

std::ostream& operator << (std::ostream& out, const Score &score) {
    out << "\tName: ";

    for(int i = 0; i < 3; i++) {
        out << score.name[i];
    }

    out << " Score: " << score.totalScore << std::endl;

    return out;
 }
