#ifndef DATA_H
#define DATA_H

#include "mainmenu.h"
#include "database.h"

class Data: public MainMenu {
public:
    Data();
    virtual ~Data();

    void dataMenu();
    void dataMenuSelector(char c);
    void dataMenuAddWord();
    void dataMenuViewWords();
    void printWords();



private:
    DataBase data;


};

#endif // DATA_H