#include <iostream>
#include "characterarray.h"

using namespace std;

void printArray(CharacterArray &ca){

    cout << "printing array" << endl;
    cout << "CharacterArray: \"" << ca << "\"" << endl;
    cout << "string length: " << ca.length() << endl;
    cout << endl;
}

void append(CharacterArray &ca, char c){

    cout << "append: '" << c << "'" << endl;
    ca.append(c);
    cout << "CharacterArray: \"" << ca << "\"" << endl;
    cout << "string length: " << ca.length() << endl;
    cout << endl;
}

void insertIntoArray(CharacterArray &ca, char c, int index){

    try{
        cout << "insert: '" << c << "' at index: " << index << endl;
        ca.insert(c, index);
        cout << "CharacterArray: \"" << ca << "\"" << endl;
    }catch(IndexOutOfBoundsException e){
        cout << "index out of bounds" << endl;
    }
    cout << "string length: " << ca.length() << endl;
    cout << endl;
}

void setAt(CharacterArray &ca, char c, int index){

    try{
        cout << "set: '" << c << "' at index: " << index << endl;
        ca.setAt(c, index);
        cout << "CharacterArray: \"" << ca << "\"" << endl;
    }catch(IndexOutOfBoundsException e){
        cout << "index out of bounds" << endl;
    }
    cout << "string length: " << ca.length() << endl;
    cout << endl;
}

void getAt(CharacterArray &ca, int index){

    try{
        cout << "get character at index: " << index << endl;
        char c = ca.getAt(index);
        cout << "Returned value: '" << c << "'" << endl;
    }catch(IndexOutOfBoundsException e){
        cout << "index out of bounds" << endl;
    }
    cout << endl;
}

void popFromArray(CharacterArray &ca){

    try{
        cout << "popping character from back" << endl;
        char c = ca.popBack();
        cout << "Returned value: '" << c << "'" << endl;
        cout << "CharacterArray: \"" << ca << "\"" << endl;
    }catch(EmptyException e){
        cout << "array is empty" << endl;
    }
    cout << "string length: " << ca.length() << endl;
    cout << endl;
}

void removeAt(CharacterArray &ca, int index){

    try{
        cout << "remove character at index: " << index << endl;
        char c = ca.removeAt(index);
        cout << "Returned value: '" << c << "'" << endl;
        cout << "CharacterArray: \"" << ca << "\"" << endl;
    }catch(IndexOutOfBoundsException e){
        cout << "index out of bounds" << endl;
    }
    cout << "string length: " << ca.length() << endl;
    cout << endl;
}

void substring(CharacterArray &ca, int s, int l){

    try{
        cout << "substring from " << s << " of length " << l << endl;
        char* tmp = ca.substring(s, l);
        if(tmp != NULL){
            cout << "Returned array: \"" << tmp << "\"" << endl;
            delete[] tmp;
        }else{
            cout << "Returned array: NULL" << endl;
        }
    }catch(IndexOutOfBoundsException e){
        cout << "index out of bounds" << endl;
    }
    cout << endl;
}

void clearArray(CharacterArray &ca){

    if(ca.isEmpty()){
        cout << "array is empty" << endl;
    }else{
        cout << "clearing array" << endl;
        ca.clear();
        cout << "CharacterArray: \"" << ca << "\"" << endl;
        cout << "string length: " << ca.length() << endl;
    }
    cout << endl;
}

int main(){

    // CharacterArray ca1;

    // printArray(ca1);

    // append(ca1, 'k');
    // insertIntoArray(ca1, 'a', 0);
    // setAt(ca1, 'j', 1);
    // getAt(ca1, 1);
    // insertIntoArray(ca1, 'r', 1);
    // popFromArray(ca1);
    // removeAt(ca1, 0);

    // clearArray(ca1);
    // clearArray(ca1);

    // cout << endl << endl;

    // CharacterArray ca2((char*)"parameter constructor", 21);
    // printArray(ca2);
    // substring(ca2, 4, 11);


//Example output from the Kari

    CharacterArray ca;

    printArray(ca);

    insertIntoArray(ca, 'a', 1);
    insertIntoArray(ca, 'a', 0);
    insertIntoArray(ca, 'b', 1);
    insertIntoArray(ca, 'c', 0);
    insertIntoArray(ca, 'd', 4);
    insertIntoArray(ca, ' ', 3);
    insertIntoArray(ca, 'd', 4);
    insertIntoArray(ca, 'l', 2);
    insertIntoArray(ca, 'e', 3);
    insertIntoArray(ca, 'e', 7);
    insertIntoArray(ca, 'a', 7);
    insertIntoArray(ca, 'k', 8);
    insertIntoArray(ca, 'r', 7);
    insertIntoArray(ca, 's', -1);

    append(ca, ' ');
    append(ca, 'm');
    append(ca, 'o');
    append(ca, 'r');
    append(ca, 'e');
    append(ca, ' ');
    append(ca, 's');
    append(ca, 't');
    append(ca, 'u');
    append(ca, 'f');
    append(ca, 'f');

    setAt(ca, 'g', 12);

    getAt(ca, 3);
    getAt(ca, 12);
    getAt(ca, 17);
    getAt(ca, 16);
    getAt(ca, 9);
    getAt(ca, 22);
    getAt(ca, 0);

    append(ca, ' ');
    append(ca, 'p');
    append(ca, 'o');
    append(ca, 'p');

    popFromArray(ca);
    popFromArray(ca);
    popFromArray(ca);
    popFromArray(ca);

    removeAt(ca, 16);
    removeAt(ca, 5);
    removeAt(ca, 10);

    substring(ca, 2, 6);
    substring(ca, 6, 5);
    substring(ca, 0, 5);
    substring(ca, 19, 7);
    substring(ca, -2, 4);
    substring(ca, 4, 0);

    clearArray(ca);
    clearArray(ca);

    return 0;
}
