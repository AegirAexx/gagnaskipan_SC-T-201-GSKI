#ifndef GAMEPLAY_H
#define GAMEPLAY_H

#include <iostream>
#include <string>
#include <vector>

class Gameplay
{
    public:
        Gameplay();
        virtual ~Gameplay();

        void initialize(); //þetta fall setur þetta í gang, þarna nær maður í orð sem á að spila með, og spyr notandann hversu mörg misses hann vill leyfa

        void play();

        void printDisplayWord();


    private:
        int missesLeft;
        int guessCount;
        int correctCount;
        std::string word;
        std::string display;
        std::vector<std::string> wordDatabase;
};

#endif // GAMEPLAY_H
