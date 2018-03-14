#ifndef GAMEPLAY_H
#define GAMEPLAY_H

#include <iostream>
#include <string>
#include <vector>
#include "database.h"

class GamePlay
{
    public:
        GamePlay();
        virtual ~GamePlay();

        void initialize(); //þetta fall setur þetta í gang, þarna nær maður í orð sem á að spila með, og spyr notandann hversu mörg misses hann vill leyfa

        void play(std::string word);

        void printDisplayWord();

        void hideWord();


    private:
        int missesLeft;
        int guessCount;
        int correctCount;
        std::string word;
        std::string hidden;
        char guess;
        bool guessValidation;
        DataBase data;

};

#endif // GAMEPLAY_H
