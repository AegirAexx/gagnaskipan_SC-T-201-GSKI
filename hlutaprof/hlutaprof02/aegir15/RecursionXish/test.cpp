#include <iostream>
#include <string.h>
//#include <ctype.h>

using namespace std;

int main(){

    string word = "AbCdEf";
    char letter = 'f';

    //tolower(letter);

    cout << "the toLower is: " << (char)tolower(letter) << endl;
    cout << "the letter is: " << letter << endl;


    return 0;
}