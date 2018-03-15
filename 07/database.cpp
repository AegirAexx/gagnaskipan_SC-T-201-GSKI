#include "database.h"

using namespace std;

DataBase::DataBase() {}

DataBase::~DataBase() {}

vector<string> DataBase::getWordDatabase() {
    return wordDatabase;
}


void DataBase::writeToDatabase(std::string newWord) {
    fstream writeData;

    writeData.open ("data.txt",ios::app);

    if (!writeData)
    {
        cout << "Error writing to file!";
        return;
    }
    else {
        writeData << newWord  << endl;
        writeData.close();
    }
}

void DataBase::fetchWords() {

    fstream readData;
    readData.open("data.txt",ios::in);

    if (!readData) {
        cout<<"Error reading file!";
        return;
    }
    else {
        string strLine;

        while (getline (readData, strLine)) {
              // Use std::stringstream to isolate words using operator >>
            stringstream buffer (strLine);

            string strWord;
                while (buffer >> strWord) {

                    wordDatabase.push_back(strWord);
                }
        }
        readData.close ();
    }
}

string DataBase::getRandomWord() {
    random_device rd;
    uniform_int_distribution<int> dist(0, wordDatabase.size() - 1);
    return wordDatabase[dist(rd)];
}
