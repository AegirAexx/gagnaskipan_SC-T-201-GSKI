#include "gameplay.h"

using namespace std;

GamePlay::GamePlay(): missesRemain(0), guessCount(0), correctCount(0), guess('\0'), guessValidation(false) {}

GamePlay::~GamePlay() {}

void GamePlay::initialize() {
    data.fetchWords();
    word = data.getRandomWord();
    hideWord();
} 

void GamePlay::setMissesRemain(int m) {
    missesRemain = m;
}

string GamePlay::getWord(){
    return word;
}


void GamePlay::play() {

    while(missesRemain >= 0 && correctCount < word.length()) {
        guessValidation = false;
        clearScreen();
        headBanner();
        printHidden();
        printWrongGuesses();
        getGuess();

        for(unsigned int i = 0; i < word.length(); i++) {
            if(guess == word[i]) {
                hidden[i] = guess;
                correctCount++;
                guessValidation = true;
            }
        }

        if(guessValidation == false) {
            missesRemain--;
            wrongGuesses.push_back(guess);
        }
        guessCount++;
    }

    if(missesRemain <= 0) {
        cout << "\tYou lose!" << endl;
    }
    else if (correctCount == word.length()) {
        cout << "\tYou win!" << endl;
    }
}

void GamePlay::printWrongGuesses(){
    cout << "\tWrong letters [ ";
    for(size_t i = 0; i < wrongGuesses.size(); ++i){
        cout << wrongGuesses.at(i) << " ";
    }
    cout << " ]" << endl;
}

void GamePlay::printHidden() {
    cout << "\t[ ";
    for(size_t i = 0; i < hidden.length(); ++i){
        cout << hidden[i] << " ";
    }
    cout << "]" << endl;
}

void GamePlay::getGuess() {
    cout << "\tEnter a letter: ";
    cin >> guess;
}


void GamePlay::hideWord (){
    hidden = word;

    for(unsigned int i = 0; i < hidden.length(); i++) {
        hidden[i] = '-';
    }

}

