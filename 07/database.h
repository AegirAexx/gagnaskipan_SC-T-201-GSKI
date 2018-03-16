#ifndef DATABASE_H
#define DATABASE_H

#include <string>
#include <vector>
#include <fstream>
#include <iostream>
#include <sstream>
#include <random>
#include "score.h"
#include <algorithm>

class DataBase
{
    public:
        DataBase();
        virtual ~DataBase();

        void writeToDatabase(std::string newWord);
        void addToScoresDatabase(Score score); 

        void fetchScores(); 
        void writeScoresToFile();

        void fetchWords();
        std::string getRandomWord();
        std::vector<std::string> getWordDatabase();
        void sortVector();
        void printVector();

    private:
        std::vector<std::string> wordDatabase;
        std::vector<Score> scoresDatabase;
};

#endif // DATABASE_H
