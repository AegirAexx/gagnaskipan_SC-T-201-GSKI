#include "menuclass.h"


using namespace std;

MenuClass::MenuClass() {}

MenuClass::~MenuClass() {}

void MenuClass::prePlayGame() {
    int setMisses {0};
    game.initialize();
    clearScreen();
    headBanner();
    cout << endl << endl << endl << "\tInitializing the game, but first you must decide on" << endl;
    cout << "\thow many misses are allowed before the game is over." << endl << endl;
    cout << "\t<How many misses?> ";
    cin >> setMisses;

    game.setMissesRemain(setMisses);
    game.play();
}

void MenuClass::mainMenu() {

    char choice;

    clearScreen();
    headBanner();
    
    cout << "\tWelcome to this->HangMan!\n" << endl;
    cout << "\t[ 1 ] - Play this->HangMan" << endl;
    cout << "\t[ 2 ] - Word database" << endl;
    cout << "\t[ 3 ] - Instructions" << endl;
    cout << "\t[ 4 ] - Hi-Score List" << endl;
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
    cout << "\t[ 3 ] - Remove a word" << endl;
    cout << "\t[ 4 ] - Clear words from database" << endl;
    cout << "\t[ R ] - Return to Main menu\n" << endl;
    cout << "\t<Database/> ";

    cin >> choice;

    dataMenuSelector(choice);
}

void MenuClass::mainMenuSelector(char c) {
    
    switch(c) {
        case '1': 
                prePlayGame();
                break;
        case '2': 
                dataMenu();
                break;
        case '3': 
                cout << "\tInstructions" << endl;
                break;
        case '4': 
                cout << "\tHi-Score List" << endl;
                break;
        case 'q':
        case 'Q':    
                cout << "\tThank you, come again!" << endl;
                break;
        default:
                std::cout << "\n\n\tERROR!\n\n";
                break;
    }

}

void MenuClass::dataMenuSelector(char c) {
    
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
                mainMenu();
                break;
        default:
                std::cout << "\n\n\tERROR!\n\n";
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
    cout << endl;
    cout << endl;
    cout << endl;
    cout << endl;

    anyKey();

    dataMenu();
}

void MenuClass::headBanner() {

    cout << endl;
    cout << endl;
    cout << " ___________.._______" << endl;
    cout << "| .__________))______|" << endl;
    cout << "| | / /      ||                _________  ___  ___  ___  ________                 ___" << endl;
    cout << "| |/ /       ||               |\\___   ___\\\\  \\|\\  \\|\\  \\|\\   ____\\               |\\  \\" << endl;
    cout << "| | /        ||.-''.          \\|___ \\  \\_\\ \\  \\\\\\  \\ \\  \\ \\  \\___|_  ____________\\ \\  \\" << endl;
    cout << "| |/         |/  _  \\              \\ \\  \\ \\ \\   __  \\ \\  \\ \\_____  \\|\\____________\\ \\  \\" << endl;
    cout << "| |          ||  `/,|               \\ \\  \\ \\ \\  \\ \\  \\ \\  \\|____|\\  \\|____________|\\/  /|" << endl;
    cout << "| |          (\\\\`_.'                 \\ \\__\\ \\ \\__\\ \\__\\ \\__\\____\\_\\  \\             /  //" << endl;
    cout << "| |         .-`--'.                   \\|__|  \\|__|\\|__|\\|__|\\_________\\           /_ //" << endl;
    cout << "| |        /Y . . Y\\                                       \\|_________|          |__|/" << endl;
    cout << "| |       // |   | \\\\" << endl;
    cout << "| |      //  | . |  \\\\" << endl;
    cout << "| |     ')   |   |   (`        ___  ___  ________  ________   ________  _____ ______   ________  ________" << endl;
    cout << "| |          ||'||            |\\  \\|\\  \\|\\   __  \\|\\   ___  \\|\\   ____\\|\\   _ \\  _   \\|\\   __  \\|\\   ___  \\" << endl;
    cout << "| |          || ||            \\ \\  \\\\\\  \\ \\  \\|\\  \\ \\  \\\\ \\  \\ \\  \\___|\\ \\  \\\\\\__\\ \\  \\ \\  \\|\\  \\ \\  \\\\ \\  \\" << endl;
    cout << "| |          || ||             \\ \\   __  \\ \\   __  \\ \\  \\\\ \\  \\ \\  \\  __\\ \\  \\\\|__| \\  \\ \\   __  \\ \\  \\\\ \\  \\" << endl;
    cout << "| |          || ||              \\ \\  \\ \\  \\ \\  \\ \\  \\ \\  \\\\ \\  \\ \\  \\|\\  \\ \\  \\    \\ \\  \\ \\  \\ \\  \\ \\  \\\\ \\  \\" << endl;
    cout << "| |         / | | \\              \\ \\__\\ \\__\\ \\__\\ \\__\\ \\__\\\\ \\__\\ \\_______\\ \\__\\    \\ \\__\\ \\__\\ \\__\\ \\__\\\\ \\__\\" << endl;
    cout << "\"\"\"\"\"\"\"\"\"\"|_`-' `-' |\"\"\"|         \\|__|\\|__|\\|__|\\|__|\\|__| \\|__|\\|_______|\\|__|     \\|__|\\|__|\\|__|\\|__| \\|__|" << endl;
    cout << "|\"|\"\"\"\"\"\"\"\\ \\       '\"|\"|" << endl;
    cout << "| |        \\ \\        | |" << endl;
    cout << ": :         \\ \\       : :" << endl;
    cout << ". .          `'       . ." << endl;
    cout << endl;
    cout << endl;
}

void MenuClass::clearScreen() {
    for(int i = 0; i < 40; ++i){
        cout << endl;
    }
}

void MenuClass::anyKey(){
    cout << "\tPress anykey to continue...";
    cin.ignore();
    cin.get();
}
