#include "gameplay.h"

using namespace std;

GamePlay::GamePlay(): missesRemain(0), guessCount(0), correctCount(0), guess('\0'), guessValidation(false), wrongValidation(false) {}

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
         wrongValidation = false;
        
        clearScreen();
        headBanner();
        cout << "[guessCount: " << guessCount << "][missesRemain: " << missesRemain << "][correctCount: " << correctCount << "]" << endl;
        printHidden();
        printWrongGuesses();
        getGuess();

        for(size_t i = 0; i < word.length(); i++) {
            if(guess == word[i] && guess != hidden[i]) {
                hidden[i] = guess;
                correctCount++;
                guessCount++;
                guessValidation = true;
            }
            else if(guess == word[i] && guess == hidden[i]){
                guessValidation = true;
            }
        }
        
        for(size_t i = 0; i < wrongGuesses.size(); i++){
            if(wrongGuesses[i] == guess){
                wrongValidation = true;
            }
        }
        if(guessValidation == false && !wrongValidation) {
            missesRemain--;
            guessCount++;
            wrongGuesses.push_back(guess);
        }        
    }
    checkOutcome();
}

void GamePlay::printWrongGuesses(){
    cout << "\tWrong guesses [ ";
    for(size_t i = 0; i < wrongGuesses.size(); ++i){
        cout << wrongGuesses.at(i) << " ";
    }
    cout << " ]" << endl;
}

void GamePlay::printHidden() {
    cout << "\tHidden word [ ";
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

void GamePlay::checkOutcome(){
    if(missesRemain <= 0) {
        cout << "\tYou lose!" << endl;
    }
    else if (correctCount == word.length() && word == hidden) {
        cout << "\tYou win!" << endl;
    }
}

