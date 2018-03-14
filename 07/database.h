#ifndef DATABASE_H
#define DATABASE_H

#include <string>
#include <vector>
#include <fstream>
#include <iostream>
#include <sstream>
#include <random>

class DataBase
{
    public:
        DataBase();
        virtual ~DataBase();

        void writeToDatabase(std::string newWord);

        void fetchWords();
        std::string getRandomWord();

    private:
        std::vector<std::string> wordDatabase;

};

#endif // DATABASE_H
