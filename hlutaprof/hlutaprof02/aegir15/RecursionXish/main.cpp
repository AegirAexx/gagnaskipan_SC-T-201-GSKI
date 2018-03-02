#include <iostream>
#include <string.h>

using namespace std;

///////IMPLEMENT THIS FUNCTION///////////////////
//You can add helper functions as you see fit.
/*
bool Xish(const char* strX, const char* strWord) {

    ///This is the length of strX, if you need it!
    int lengthOfX = strlen(strX);

    //REMOVE/REPLACE THIS LINE
    return false;
}
*/
bool Xish(const char* strX, const char* strWord) {

    ///This is the length of strX, if you need it!
    //int lengthOfX = strlen(strX);
    int lengthOfWord = strlen(strWord);

    bool returnBoolean = false;
    bool e = false;
    bool l = false;
    bool f = false;
    for(auto i = 0; i < lengthOfWord; ++i){
        if(strWord[i] == 'e' || strWord[i] == 'E'){
            e = true;
        }
        else if(strWord[i] == 'l' || strWord[i] == 'L'){
            l = true;
        }
        else if(strWord[i] == 'f' || strWord[i] == 'F'){
            f = true;
        }
    }
    if(e && l && f){
        returnBoolean = true;
    }

    //REMOVE/REPLACE THIS LINE
    return returnBoolean;
}


////////////////////////////////DO NOT CHANGE ANYTHING BELOW THIS LINE////////////////////////////////////////////


void checkXish(string X, string word) {

    if(Xish(X.c_str(), word.c_str())) {
        cout << word << " is " << X << "-ish" << endl;
    }
    else {
        cout << word << " is NOT " << X << "-ish" << endl;
    }
}

void checkElfish(string word) {

    checkXish("elf", word);
}

int main() {

    cout << endl << "+++++ --- ELF-ISH TEST --- +++++" << endl << endl;

    cout << "Your output:     ";
    checkElfish("elf");
    cout << "Expected output: elf is elf-ish" << endl;
    cout << endl;

    cout << "Your output:     ";
    checkElfish("ef");
    cout << "Expected output: EF is NOT elf-ish" << endl;
    cout << endl;

    cout << "Your output:     ";
    checkElfish("ElFeLf");
    cout << "Expected output: ElFeLf is elf-ish" << endl;
    cout << endl;

    cout << "Your output:     ";
    checkElfish("cake");
    cout << "Expected output: Cake is NOT elf-ish" << endl;
    cout << endl;

    cout << "Your output:     ";
    checkElfish("election");
    cout << "Expected output: Election is NOT elf-ish" << endl;
    cout << endl;

    cout << "Your output:     ";
    checkElfish("frauline");
    cout << "Expected output: Frauline is elf-ish" << endl;
    cout << endl;

    cout << "Your output:     ";
    checkElfish("leaf");
    cout << "Expected output: Leaf is elf-ish" << endl;
    cout << endl;

    cout << "Your output:     ";
    checkElfish("forest");
    cout << "Expected output: Forest is NOT elf-ish" << endl;
    cout << endl;

    cout << "Your output:     ";
    checkElfish("gagnaskipan");
    cout << "Expected output: Gagnaskipan is NOT elf-ish" << endl;
    cout << endl;

    cout << "Your output:     ";
    checkElfish("element");
    cout << "Expected output: Element is NOT elf-ish" << endl;
    cout << endl;

    cout << "Your output:     ";
    checkElfish("feline");
    cout << "Expected output: Feline is elf-ish" << endl;
    cout << endl;

    cout << "Your output:     ";
    checkElfish("laugh");
    cout << "Expected output: Laugh is NOT elf-ish" << endl;
    cout << endl;

    cout << "Your output:     ";
    checkElfish("foliage");
    cout << "Expected output: Foliage is elf-ish" << endl;
    cout << endl;

    cout << "Your output:     ";
    checkElfish("follow");
    cout << "Expected output: Follow is NOT elf-ish" << endl;
    cout << endl;




    cout << endl << "+++++ --- X-ISH TEST --- +++++" << endl << endl;

    cout << "Your output:     ";
    checkXish("Fo", "Follow");
    cout << "Expected output: Follow is Fo-ish" << endl;
    cout << endl;

    cout << "Your output:     ";
    checkXish("Fw", "Follow");
    cout << "Expected output: Follow is Fw-ish" << endl;
    cout << endl;

    cout << "Your output:     ";
    checkXish("lo", "Follow");
    cout << "Expected output: Follow is lo-ish" << endl;
    cout << endl;

    cout << "Your output:     ";
    checkXish("Fr", "Follow");
    cout << "Expected output: Follow is NOT Fr-ish" << endl;
    cout << endl;

    cout << "Your output:     ";
    checkXish("wolloFp", "Follow");
    cout << "Expected output: Follow is NOT wolloFp-ish" << endl;
    cout << endl;

    cout << "Your output:     ";
    checkXish("wolloF", "Follow");
    cout << "Expected output: Follow is wolloF-ish" << endl;
    cout << endl;



}
