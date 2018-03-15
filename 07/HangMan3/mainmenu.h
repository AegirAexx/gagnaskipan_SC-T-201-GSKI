#ifndef MAINMENU_H
#define MAINMENU_H

#include <iostream>
#include "game.h"
//#include "data.h"
//#include "score.h"

class MainMenu {
public:
    MainMenu();
    virtual ~MainMenu();

    void runHangMan();

    void headBanner();
    void clearScreen();
    void anyKey();

private:
    void menu();
    void menuSelector(char c);

    Game game;
//    Score score;
//     Data data;


};

#endif // MAINMENU_H
