#ifndef MENUCLASS_H
#define MENUCLASS_H

#include <iostream>
#include "gameplay.h"
#include "headtemplate.h"

class MenuClass: public HeadTemplate {
public:
    MenuClass();
    virtual ~MenuClass();

    void mainMenu();
    void mainMenuSelector(char c);

    void dataMenu();
    void dataMenuSelector(char c);
    void dataMenuAddWord();
    void dataMenuViewWords();

    void prePlayGame();
    void playGame();
    void postPlayGame();

    char getGuess();

    void instructions();

private:
    GamePlay game;
    DataBase data;
};

#endif // MENUCLASS_H
