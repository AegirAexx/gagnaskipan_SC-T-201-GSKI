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

        void initialize(); //�etta fall setur �etta � gang, �arna n�r ma�ur � or� sem � a� spila me�, og spyr notandann hversu m�rg misses hann vill leyfa

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
