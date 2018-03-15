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
        clearScreen();
        headBanner();
        cout << "\tEnter a letter: ";
        cin >> guess;

        // guess = menu.getGuess();

        //Skilabo� sem segja press ? to guess the whole word
        //�� er kalla� � goForIt

        for(unsigned int i = 0; i < word.length(); i++) {  //validate hvort b�i� s� a� geta r�tt, b�a til vector sem heldur utan um hva� b�i� er a� giska �
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

        cout << "\t" <<  hidden << endl;
        
        cout << "\tWrong letters [ ";
        for(size_t i = 0; i < wrongGuesses.size(); ++i){
            cout << wrongGuesses.at(i) << " ";
        }
        cout << " ]" << endl;

        guessCount++;
    }

    if(missesRemain <= 0) {  ///fall sem prentar �t �rslitin, H�rna m�tti b�a til f�ll
        cout << "\tYou lose!" << endl;
    }
    else if (correctCount == word.length()) {
        cout << "\tYou win!" << endl;
    }


}

void GamePlay::hideWord (){
    hidden = word;

    for(unsigned int i = 0; i < hidden.length(); i++) {
        hidden[i] = '-';
    }

}

void GamePlay::headBanner() {

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

void GamePlay::clearScreen() {
    for(int i = 0; i < 40; ++i){
        cout << endl;
    }
}

void GamePlay::anyKey(){
    cout << "\tPress anykey to continue...";
    cin.ignore();
    cin.get();
}
