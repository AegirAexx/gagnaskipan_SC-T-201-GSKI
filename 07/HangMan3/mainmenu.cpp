#include "mainmenu.h"

using namespace std;

MainMenu::MainMenu() {}

MainMenu::~MainMenu() {}

void MainMenu::runHangMan() {
    menu();
}

void MainMenu::menu() {

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

    menuSelector(choice);
}

void MainMenu::menuSelector(char c) {

    switch(c) {
        case '1':
                game.startGame();
                break;
        case '2':
                // data.dataMenu();
                break;
        case '3':
                cout << "\tInstructions" << endl;
                break;
        case '4':
                cout << "\tHi-Score List" << endl;
                break;
        case 'q':
        case 'Q':
                clearScreen();
                headBanner();
                cout << endl << endl << endl << endl << "\tThank you for playing!" << endl << endl << endl << endl;
                anyKey();
                break;
        default:
                clearScreen();
                headBanner();
                cout << endl << endl << endl << endl << "\tERROR!" << endl << endl << endl << endl;
                anyKey();
                menu();
                break;
    }

}

void MainMenu::headBanner() {

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

void MainMenu::clearScreen() {
    for(int i = 0; i < 40; ++i){
        cout << endl;
    }
}

void MainMenu::anyKey(){
    cout << "\tPress anykey to continue...";
    cin.ignore();
    cin.get();
}
