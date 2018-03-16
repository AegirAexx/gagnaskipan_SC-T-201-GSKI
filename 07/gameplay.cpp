#include "gameplay.h"

using namespace std;

GamePlay::GamePlay():
    missesRemain(0),
    guessCount(0),
    correctCount(0),
    guess('\0'),
    guessValidation(false),
    wrongValidation(false),
    currentRunWins(0),
    currentRunLosses(0) {}

GamePlay::~GamePlay() {}

void GamePlay::initialize() {
    correctCount = 0;
    wrongGuesses.clear();
    data.fetchWords();
    word = data.getRandomWord();
    hideWord();
    clearScreen();
    headBanner();
    cout << endl << endl << endl << "\tInitializing the game, but first you must decide on" << endl;
    cout << "\thow many misses are allowed before the game is over." << endl << endl;
    cout << "\t<How many misses?> ";
    cin >> missesRemain;
    play();
}

void GamePlay::setMissesRemain(int m) {
    missesRemain = m;
}

string GamePlay::getWord(){
    return word;
}


void GamePlay::play() {

    while(missesRemain > 0 && correctCount < word.length()) {
        guessValidation = false;
        wrongValidation = false;

        clearScreen();
        headBanner();
        printScore();
        printHidden();
        printWrongGuesses();
        guess = getGuess();

        if(guess == '?') {
            guessWholeWord();
        }
        else {
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
    }
    clearScreen();
    headBanner();
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

void GamePlay::printReal() {
    cout << "\tHidden word [ ";
    for(size_t i = 0; i < word.length(); ++i){
        cout << word[i] << " ";
    }
    cout << "]" << endl;
}

char GamePlay::getGuess() {
    char x;
    cout << "\tEnter a letter: ";
    cin >> x;
    x = tolower(x);
    return x;
}


void GamePlay::hideWord (){
    hidden = word;

    for(unsigned int i = 0; i < hidden.length(); i++) {
        hidden[i] = '-';
    }

}

void GamePlay::checkOutcome(){
    if(missesRemain <= 0) {
        cout << "\tYou lose!" << endl << endl;
        printReal();
        currentRunLosses++;
    }
    else if (correctCount == word.length() && word == hidden) {
        cout << "\tYou win!" << endl << endl;
        printHidden();
        currentRunWins++;
    }
    score.totalScore += (correctCount * (currentRunWins - currentRunLosses));
    playAgain();
}

void GamePlay::playAgain() {

    char choice;

    cout << endl << "\tDo you want to play again? [y / n] ";
    cin >> choice;

    if(choice == 'y' || choice == 'Y') {
        initialize();
    }
    else {
        cout << "\tPlease enter your initials! Max 3 characters: ";
        cin >> score.name;
        return;
    }

}

void GamePlay::printScore(){
    cout << "\t[Wins: " << currentRunWins << "]  [Guesses left: " << missesRemain << "]  [Losses: " << currentRunLosses << "]  [Score: " << score.totalScore << "]" << endl << endl;
    cout << "\tDo you feel lucky? Enter \"?\" and then try to guess the whole word!" << endl << endl;
}

void GamePlay::guessWholeWord() {

    string wordGuess;

    cout << "\tGuess the whole word, remember if you are not right you lose: ";
    cin >> wordGuess;

    for(unsigned int i = 0; i < wordGuess.length(); i++) {
        wordGuess[i] = tolower(wordGuess[i]);
    }

    if(wordGuess == word) {
        correctCount = word.length();
        hidden = word;
    }
    else {
        missesRemain = 0;
    }

}


Score GamePlay::getScore() {

    return score;
}
