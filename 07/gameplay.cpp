#include "gameplay.h"

using namespace std;

Gameplay::Gameplay()
{
    //ctor
}

Gameplay::~Gameplay()
{
    //dtor
}

void Gameplay::initialize() {

    //Kalla � populate vector falli� innan �r DataBase klasanum

    word = "DJkari"; //Herna �arf a� velja random or� �r gagnagrunninum

    display = word;

    for(unsigned int i = 0; i < display.length(); i++) {
        display[i] = '-';
    }

    cout << "The word has " << word.length() << " letters" << endl;
    cout << display << endl;

    cout << "Please enter number of misses allowed: ";
    cin >> missesLeft;

} //�etta fall setur �etta � gang, �arna n�r ma�ur � or� sem � a� spila me�, og spyr notandann hversu m�rg misses hann vill leyfa


void play();
