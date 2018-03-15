#ifndef DATABASE_H
#define DATABASE_H

#include <string>
#include <vector>
#include <fstream>
#include <iostream>
#include <sstream>
#include <random>
#include "score.h"

class DataBase
{
    public:
        DataBase();
        virtual ~DataBase();

        void writeToDatabase(std::string newWord);
        void addToScoresDatabase(Score score);  //b�tir score � scoredatabase vectorinn

        void fetchScores();  //populate-ar vectorinn �r file-num

        void writeScoresToFile();

        void fetchWords();
        std::string getRandomWord();
        std::vector<std::string> getWordDatabase();

    private:
        std::vector<std::string> wordDatabase;
        std::vector<Score> scoresDatabase;
};

#endif // DATABASE_H
