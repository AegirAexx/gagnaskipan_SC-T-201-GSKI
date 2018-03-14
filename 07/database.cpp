#include "database.h"

using namespace std;

DataBase::DataBase()
{
    //ctor
}

DataBase::~DataBase()
{
    //dtor
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

    cout << "reading from file: " << endl;

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
                    cout << "word: ";
                    cout << strWord << endl;  // <--- Output!
                }
            }

        readData.close ();

        for(auto x: wordDatabase) {
            cout << x << " ";
        }

        cout << wordDatabase[0].length() << endl;
        cout << wordDatabase.size() << endl;
    }
}

string DataBase::getRandomWord() {

    int randNumber = rand() % wordDatabase.size();

    return wordDatabase[randNumber];
}
