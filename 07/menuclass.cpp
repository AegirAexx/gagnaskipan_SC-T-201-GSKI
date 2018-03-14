#include "menuclass.h"


using namespace std;

MenuClass::MenuClass()
{
    //ctor
}

MenuClass::~MenuClass()
{
    //dtor
}


void MenuClass::welcome() {  //Maetti utfaera betur og flottar
    cout << "********************************" << endl;
    cout << "           Welcome to           " << endl;
    cout << "         this->HangMan!         " << endl;
    cout << "********************************" << endl;

    mainMenu();
}

void MenuClass::mainMenu() {  //vantar ad koma i veg fyrir rangt input

    char choice;

    cout << "Select 1 to play this->HangMan, select 2 to add words to database, select Q to return to reality" << endl;
    cout << "Please choose what to do: " << endl;
    cin >> choice;

    if(choice == '1') {
        game.initialize();
    }
    else if (choice == '2') {
        dataMenu();
    }
    else if (choice == 'Q' || choice == 'q') {
        cout << "Thank you, come again!" << endl;
        return;
    }
}

void MenuClass::dataMenu() {
    string newWord;
    char cont = 'y';

    while(cont == 'y' || cont == 'Y') {
        cout << "Please enter a word to add to database: ";
        cin >> newWord;

        data.writeToDatabase(newWord);

        cout << "Press y to add another word? ";
        cin >> cont;
    }

    mainMenu();
}
