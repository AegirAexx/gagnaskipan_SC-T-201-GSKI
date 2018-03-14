#include "gameplay.h"

using namespace std;

GamePlay::GamePlay()
{
    missesLeft = 0;
    guessCount = 0;
    correctCount = 0;
    guess = '\0';
    guessValidation = false;
}

GamePlay::~GamePlay()
{
    //dtor
}

void GamePlay::initialize() {

    data.fetchWords();

    word = data.getRandomWord();

    hideWord();



    cout << "The word has " << word.length() << " letters" << endl;
    cout << hidden << endl;

    cout << "Please enter number of misses allowed: ";
    cin >> missesLeft;

    play(word);

} //�etta fall setur �etta � gang, �arna n�r ma�ur � or� sem � a� spila me�, og spyr notandann hversu m�rg misses hann vill leyfa

void GamePlay::play(string word) {

        while(missesLeft >= 0 && correctCount < word.length()) {
            cout << "Enter a letter: " << endl;
            cin >> guess;

            for(unsigned int i = 0; i < word.length(); i++) {
                if(guess == word[i]) {
                    hidden[i] = guess;
                    correctCount++;
                    guessValidation = true;
                }
            }

            if(guessValidation == false) {
                missesLeft--;
            }

            cout << hidden << endl;
            guessCount++;
        }

    if(missesLeft <= 0) {  ///fall sem prentar �t �rslitin
        cout << "You lose!" << endl;
    }
    else if (correctCount == word.length()) {
        cout << "You win!" << endl;
    }
}

void GamePlay::hideWord (){
    hidden = word;

    for(unsigned int i = 0; i < hidden.length(); i++) {
        hidden[i] = '-';
    }

}
