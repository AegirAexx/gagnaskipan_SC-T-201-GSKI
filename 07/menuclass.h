#ifndef MENUCLASS_H
#define MENUCLASS_H

#include <iostream>
#include "gameplay.h"

class MenuClass
{
    public:
        MenuClass();
        virtual ~MenuClass();

        void welcome();  //Fall sem skrifar welcome to hangman
        void mainMenu(); //Fall sem gefur manni möguleikan á að bæta í gagnagrunninn eða spila leikinn
        void dataMenu();

    private:
        GamePlay game;
        DataBase data;
};

#endif // MENUCLASS_H
