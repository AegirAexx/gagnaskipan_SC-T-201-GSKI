#include "menuclass.h"


using namespace std;

MenuClass::MenuClass() {}

MenuClass::~MenuClass() {}

// void MenuClass::prePlayGame() {
//     setMisses = 0;
//     game.initialize();
//     clearScreen();
//     headBanner();
//     cout << endl << endl << endl << "\tInitializing the game, but first you must decide on" << endl;
//     cout << "\thow many misses are allowed before the game is over." << endl << endl;
//     cout << "\t<How many misses?> ";
//     cin >> setMisses;

//     game.setMissesRemain(setMisses);
//     game.play();
// }

void MenuClass::mainMenu() {

    char choice;

    clearScreen();
    headBanner();

    cout << "\tWelcome to this->HangMan!\n" << endl;
    cout << "\t[ 1 ] - Play this->HangMan" << endl;
    cout << "\t[ 2 ] - Word database" << endl;
    cout << "\t[ 3 ] - Hi-Score List" << endl;
    cout << "\t[ Q ] - Return to reality\n" << endl;
    cout << "\t</> ";

    cin >> choice;

    mainMenuSelector(choice);
}

void MenuClass::dataMenu() {

    char choice;

    clearScreen();
    headBanner();

    cout << "\tthis->HangMan! - Database\n" << endl;
    cout << "\t[ 1 ] - Add a word" << endl;
    cout << "\t[ 2 ] - View words" << endl;
    cout << "\t[ R ] - Return to Main menu\n" << endl;
    cout << "\t<Database/> ";

    cin >> choice;

    dataMenuSelector(choice);
}

void MenuClass::mainMenuSelector(char c) {

    switch(c) {
        case '1':
                game.initialize();
                mainMenu();
                break;
        case '2':
                dataMenu();
                mainMenu();
                break;
        case '3':
                data.fetchScores();
                data.sortVector();
                data.printVector();
                anyKey();
                cout << "\tHi-Score List" << endl;
                break;
        case 'q':
        case 'Q':
                clearScreen();
                headBanner();
                cout << "Adding your score to the database " << endl;
                data.addToScoresDatabase(game.getScore());
                data.writeScoresToFile();
                cout << endl << endl << endl << endl << "\tThank you for playing!" << endl << endl << endl << endl;
                anyKey();
                break;
        default:
                clearScreen();
                headBanner();
                cout << endl << endl << endl << endl << "\tERROR!" << endl << endl << endl << endl;
                anyKey();
                mainMenu();
                break;
    }

}

void MenuClass::dataMenuSelector(char c) {

    switch(c) {
        case '1':
                dataMenuAddWord();
                dataMenu();
                break;
        case '2':
                dataMenuViewWords();
                dataMenu();
                break;
        case 'r':
        case 'R':
                mainMenu();
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

void MenuClass::dataMenuAddWord() {

    string newWord;
    char choice = 'y';

    while(choice == 'y' || choice == 'Y') {
        clearScreen();
        headBanner();
        cout << endl << endl << endl << endl << "\tPlease enter a word to add to database: ";
        cin >> newWord;

        for(size_t i = 0; i < newWord.length(); ++i){
            newWord[i] = tolower(newWord[i]);
        }

        data.writeToDatabase(newWord);

        cout << endl << "\tAdd another word? [y / n] ";
        cin >> choice;
    }

    dataMenu();
}

void MenuClass::dataMenuViewWords() {

    clearScreen();
    headBanner();

    data.fetchWords();

    cout << endl << endl << "\tWords in the database: " << endl << endl;
    cout << "\t";
    for(auto x: data.getWordDatabase()){
        cout << x << ", ";
    }
    cout << endl << endl << endl << endl;
    anyKey();

    dataMenu();
}
