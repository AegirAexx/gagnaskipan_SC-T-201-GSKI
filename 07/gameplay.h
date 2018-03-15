#ifndef GAMEPLAY_H
#define GAMEPLAY_H

#include <iostream>
#include <string>
#include <vector>
#include "database.h"
#include "headtemplate.h"

class GamePlay: public HeadTemplate {
    public:
        GamePlay();
        virtual ~GamePlay();

        void initialize(); //�etta fall setur �etta � gang, �arna n�r ma�ur � or� sem � a� spila me�, og spyr notandann hversu m�rg misses hann vill leyfa

        void play();

        void printDisplayWord();

        void hideWord();

        void setMissesRemain(int m);

        std::string getWord();

        std::string getHidden();

        void printWrongGuesses();

        void printHidden();

        void getGuess();

        void checkOutcome();



    private:
        int missesRemain;
        int guessCount;
        int correctCount;
        std::string word;
        std::string hidden;
        char guess;
        bool guessValidation;
        bool wrongValidation;
        std::vector<char> wrongGuesses;
        DataBase data;
        Score score;
        int currentRunWins;
        int currentRunLosses;

};

#endif // GAMEPLAY_H
