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

    //Kalla í populate vector fallið innan úr DataBase klasanum

    word = "DJkari"; //Herna þarf að velja random orð úr gagnagrunninum

    display = word;

    for(unsigned int i = 0; i < display.length(); i++) {
        display[i] = '-';
    }

    cout << "The word has " << word.length() << " letters" << endl;
    cout << display << endl;

    cout << "Please enter number of misses allowed: ";
    cin >> missesLeft;

} //þetta fall setur þetta í gang, þarna nær maður í orð sem á að spila með, og spyr notandann hversu mörg misses hann vill leyfa


void play();
