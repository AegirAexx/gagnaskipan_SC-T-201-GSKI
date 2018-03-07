#include <iostream>
// #include <string.h>
#include <string.h>

using namespace std;

///////IMPLEMENT THIS FUNCTION///////////////////
//You can add helper functions as you see fit.

// bool Xish(const char* strX, const char* strWord) {

//     ///This is the length of strX, if you need it!
//     int lengthOfX = strlen(strX);

//     //REMOVE/REPLACE THIS LINE
//     return false;
// }

// bool Xish(const char* strX, const char* strWord) {

//     ///This is the length of strX, if you need it!
//     //int lengthOfX = strlen(strX);
//     int lengthOfWord = strlen(strWord);

//     bool returnBoolean = false;
//     bool e = false;
//     bool l = false;
//     bool f = false;
//     for(auto i = 0; i < lengthOfWord; ++i){
//         if(strWord[i] == 'e' || strWord[i] == 'E'){
//             e = true;
//         }
//         else if(strWord[i] == 'l' || strWord[i] == 'L'){
//             l = true;
//         }
//         else if(strWord[i] == 'f' || strWord[i] == 'F'){
//             f = true;
//         }
//     }
//     if(e && l && f){
//         returnBoolean = true;
//     }

//     //REMOVE/REPLACE THIS LINE
//     return returnBoolean;
// }

int findX (int indexX, int indexW, const char *strX, const char *strWord, int found) {
    if(strX[indexX] == '\0') { //Ef að búið er að tékka á öllum í strX þá bara return-a found tölunni
        return found;
    }
    else if (strWord[indexW] == '\0') { //Ef að komið er út í enda á strWord þá kalla aftur á recursion með næsta staki í strX
        return findX(indexX + 1, 0, strX, strWord, found);
    }
    else if (strX[indexX] != strWord[indexW]) { //Ef strX stakið er ekki eins og strWord stakið þá kallar maður aftur á recursion með næsta staki af strWord
        return findX(indexX, indexW + 1, strX, strWord, found);
    }
    else if (strX[indexX] == strWord[indexW]) { //Ef maður finnur match þá bætir maður einum við found töluna og kallar svo aftur á recursion með næsta staki af strX
        found++;
        return findX(indexX + 1, 0, strX, strWord, found);
    }
    return found;
}
bool Xish(const char* strX, const char* strWord) {
    ///This is the length of strX, if you need it!
    int lengthOfX = strlen(strX);
    int matchFound = 0;  //breyta sem heldur utan um fjölda af matches sem finnast
    int found = 0; //Breyta sem er send inn í recursion-ið til að skilast í gegnum allt recursionið og endar svo í að setja gildið inn í matchfound
    matchFound = findX(0, 0, strX, strWord, found);  //kallað á recursion fallið í fyrsta sinn með indeX = 0, indexW = 0, found = 0
    if(matchFound >= lengthOfX) {
        return true;
    }
    else {
        return false;
    }
}

////////////////////////////////DO NOT CHANGE ANYTHING BELOW THIS LINE////////////////////////////////////////////


// void checkXish(string X, string word) {

//     if(Xish(X, word)) {
//         cout << word << " is " << X << "-ish" << endl;
//     }
//     else {
//         cout << word << " is NOT " << X << "-ish" << endl;
//     }
// }

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
