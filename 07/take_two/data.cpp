#include "data.h"

using namespace std;

Data::Data() {}

Data::~Data() {}

void Data::dataMenu() {
    
    char choice;

    clearScreen();
    headBanner();
    
    cout << "\tthis->HangMan! - Database\n" << endl;
    cout << "\t[ 1 ] - Add a word" << endl;
    cout << "\t[ 2 ] - View words" << endl;
    cout << "\t[ 3 ] - Remove a word" << endl;
    cout << "\t[ 4 ] - Clear words from database" << endl;
    cout << "\t[ R ] - Return to Main menu\n" << endl;
    cout << "\t<Database/> ";

    cin >> choice;

    dataMenuSelector(choice);
}

// VANTAR TENGINGU Í ORÐIN Í DATABASE
void Data::dataMenuAddWord() {

    string newWord;
    char choice = 'y';

    while(choice == 'y' || choice == 'Y') {
        clearScreen();
        headBanner();
        cout << endl << endl << endl << endl << "\tPlease enter a word to add to database: ";
        cin >> newWord;

        data.writeToDatabase(newWord);

        cout << endl << "\tAdd another word? [y / n] ";
        cin >> choice;
    }

    dataMenu();
}

void Data::dataMenuViewWords() {

    clearScreen();
    headBanner();
    
    printWords();

    anyKey();

    dataMenu();
}

// VANTAR TENGINGU Í ORÐIN Í DATABASE
void Data::printWords() {

    data.fetchWords();

    cout << endl << endl << "\tWords in the database: " << endl << endl;
    cout << "\t";

    for(auto x: data.getWordDatabase()){
        cout << x << ", ";
    }
    
    cout << endl << endl << endl << endl;
}


void Data::dataMenuSelector(char c) {
    
    switch(c) {
        case '1': 
                dataMenuAddWord();
                break;
        case '2': 
                dataMenuViewWords();
                break;
        case '3': 
                cout << "\tRemove a word!" << endl;
                break;
        case '4': 
                cout << "\tClear words from database!" << endl;
                break;
        case 'r':
        case 'R':    
                runHangMan();
                break;
        default:
                clearScreen();
                headBanner();
                cout << endl << endl << endl << endl << "\tERROR!" << endl << endl << endl << endl;
                anyKey();
                dataMenu();
                break;
    }
}


