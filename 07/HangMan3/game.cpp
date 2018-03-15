#include "game.h"

using namespace std;

Game::Game(): missesRemain(0), guessCount(0), correctCount(0), guess('\0'), guessValidation(false) {}

Game::~Game() {}

void Game::startGame() {

    initialize();

    clearScreen();
    headBanner();
    cout << endl << endl << endl << "\tInitializing the game, but first you must decide on" << endl;
    cout << "\thow many misses are allowed before the game is over." << endl << endl;
    cout << "\t<How many misses?> ";
    cin >> missesRemain;

    play();
}

void Game::play() {

    while(missesRemain >= 0 && correctCount < word.length()) {

        clearScreen();
        headBanner();

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

        printHidden();

        printWrongGuesses();

        guessCount++;
    }
    checkOutcome();
}

void Game::initialize() {
    data.fetchWords();
    word = data.getRandomWord();
    hideWord();
}

void Game::printHidden() {
    cout << "\t[ ";
    for(size_t i = 0; i < hidden.length(); ++i){
        cout << hidden[i] << " ";
    }
    cout << "]" << endl;
}

void Game::printWrongGuesses() {
    cout << "\tWrong letters [ ";

    for(size_t i = 0; i < wrongGuesses.size(); ++i){
        cout << wrongGuesses.at(i) << " ";
    }

    cout << " ]" << endl;
}

void Game::getGuess() {
    cout << "\tEnter a letter: ";
    cin >> guess;
}

void Game::checkOutcome() {

    if(missesRemain <= 0) {
        cout << "\tYou lose!" << endl;
    }
    else if (correctCount == word.length()) {
        cout << "\tYou win!" << endl;
    }
}

void Game::hideWord() {
    hidden = word;

    for(unsigned int i = 0; i < hidden.length(); i++) {
        hidden[i] = '-';
    }

}


void Game::headBanner() {

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

void Game::clearScreen() {
    for(int i = 0; i < 40; ++i){
        cout << endl;
    }
}

void Game::anyKey(){
    cout << "\tPress anykey to continue...";
    cin.ignore();
    cin.get();
}
