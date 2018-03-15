#ifndef DATABASE_H
#define DATABASE_H

#include <string>
#include <vector>


class DataBase {

public:
        DataBase();
        virtual ~DataBase();

        void writeToDatabase(std::string newWord);

        void fetchWords();
        std::string getRandomWord();
        std::vector<std::string> getWordDatabase();

    private:
        std::vector<std::string> wordDatabase;





};

#endif // DATABASE_H
