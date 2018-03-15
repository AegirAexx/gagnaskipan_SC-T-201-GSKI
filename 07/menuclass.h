#ifndef MENUCLASS_H
#define MENUCLASS_H

#include <iostream>
#include "gameplay.h"

class MenuClass {
public:
    MenuClass();
    virtual ~MenuClass();

    void mainMenu();
    void mainMenuSelector(char c);

    void dataMenu();
    void dataMenuSelector(char c);
    void dataMenuAddWord();
    void dataMenuViewWords();

    void headBanner();
    void instructions();
    void clearScreen();
    void anyKey();

private:
    GamePlay game;
    DataBase data;
};

#endif // MENUCLASS_H
