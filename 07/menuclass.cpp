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
}

void MenuClass::mainMenu() {  //vantar ad koma i veg fyrir rangt input

    char choice;

    cout << "Select 1 to play this->HangMan, select 2 to add words to database, select Q to return to reality" << endl;
    cout << "Please choose what to do: " << endl;
    cin >> choice;

    if(choice == '1') {
        Gameplay game;
        game.initialize();
    }
    else if (choice == '2') {

    }
    else if (choice == 'Q' || choice == 'q') {
        cout << "Thank you, come again!" << endl;
        return;
    }
}
