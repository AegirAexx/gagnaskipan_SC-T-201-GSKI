#ifndef GAME_H
#define GAME_H


#include <iostream>
#include <string>
#include <vector>

#include "database.h"

class Game {  //: public MainMenu
public:
    Game();
    virtual ~Game();

    void startGame();
    void play();
    void initialize();
    void printHidden();
    void printWrongGuesses();
    void getGuess();
    void checkOutcome();
    void hideWord();


    /// Inherit
    void headBanner();
    void clearScreen();
    void anyKey();

private:
    DataBase data;
    int missesRemain;
    int guessCount;
    int correctCount;
    std::string word;
    std::string hidden;
    char guess;
    bool guessValidation;
    std::vector<char> wrongGuesses;

};

#endif // GAME_H
