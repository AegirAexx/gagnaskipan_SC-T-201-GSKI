#include <iostream>

#include "characterarray.h"

using namespace std;

void printArray(CharacterArray &ca) {

    cout << "printing array" << endl;
    cout << "CharacterArray: \"" << ca << "\"" << endl;
    cout << "string length: " << ca.length() << endl;
    cout << endl;
}

void append(CharacterArray &ca, char c) {

    cout << "append: '" << c << "'" << endl;
    ca.append(c);
    cout << "CharacterArray: \"" << ca << "\"" << endl;
    cout << "string length: " << ca.length() << endl;
    cout << endl;
}

void setAt(CharacterArray &ca, char c, int index) {

    try {
        cout << "set: '" << c << "' at index: " << index << endl;
        ca.setAt(c, index);
        cout << "CharacterArray: \"" << ca << "\"" << endl;
    }
    catch (IndexOutOfBoundsException e) {
        cout << "index out of bounds" << endl;
    }
    cout << "string length: " << ca.length() << endl;
    cout << endl;
}

void getAt(CharacterArray &ca, int index) {

    try {
        cout << "get character at index: " << index << endl;
        char c = ca.getAt(index);
        cout << "Returned value: '" << c << "'" << endl;
    }
    catch (IndexOutOfBoundsException e) {
        cout << "index out of bounds" << endl;
    }
    cout << endl;
}

void popFromArray(CharacterArray &ca) {

    try {
        cout << "popping character from back" << endl;
        char c = ca.pop_back();
        cout << "Returned value: '" << c << "'" << endl;
        cout << "CharacterArray: \"" << ca << "\"" << endl;
    }
    catch (EmptyException e) {
        cout << "array is empty" << endl;
    }
    cout << "string length: " << ca.length() << endl;
    cout << endl;
}

void removeAt(CharacterArray &ca, int index) {

    try {
        cout << "remove character at index: " << index << endl;
        char c = ca.removeAt(index);
        cout << "Returned value: '" << c << "'" << endl;
        cout << "CharacterArray: \"" << ca << "\"" << endl;
    }
    catch (IndexOutOfBoundsException e) {
        cout << "index out of bounds" << endl;
    }
    cout << "string length: " << ca.length() << endl;
    cout << endl;
}

void substring(CharacterArray &ca, int s, int l) {

    try {
        cout << "substring from " << s << " of length " << l << endl;
        char* tmp = ca.substring(s, l);
        if(tmp != NULL) {
            cout << "Returned array: \"" << tmp << "\"" << endl;
            delete tmp;
        }
        else {
            cout << "Returned array: NULL" << endl;
        }
    }
    catch (IndexOutOfBoundsException e) {
        cout << "index out of bounds" << endl;
    }
    cout << endl;
}

void clearArray(CharacterArray &ca) {

    if(ca.isEmpty()) {
        cout << "array is empty" << endl;
    }
    else {
        cout << "clearing array" << endl;
        ca.clear();
        cout << "CharacterArray: \"" << ca << "\"" << endl;
        cout << "string length: " << ca.length() << endl;
    }
    cout << endl;
}

int main() {

    CharacterArray ca1;

    printArray(ca1);

    append(ca1, 's');
    append(ca1, 'o');
    append(ca1, 'm');
    append(ca1, 'e');
    append(ca1, ' ');
    append(ca1, 's');
    append(ca1, 't');
    append(ca1, 'u');
    append(ca1, 'f');
    append(ca1, 'f');

    removeAt(ca1, 8);
    removeAt(ca1, 8);
    removeAt(ca1, 1);
    removeAt(ca1, 1);
    removeAt(ca1, 2);
    removeAt(ca1, 2);
    removeAt(ca1, 3);
    removeAt(ca1, 0);
    removeAt(ca1, 0);
    removeAt(ca1, 0);

    append(ca1, 'm');
    append(ca1, 'o');
    append(ca1, 'r');
    append(ca1, 'e');

    removeAt(ca1, 2);

    append(ca1, 'l');
    append(ca1, 'e');
    append(ca1, 's');
    append(ca1, 's');

    removeAt(ca1, 2);
    removeAt(ca1, 1);
    removeAt(ca1, 0);

    removeAt(ca1, 3);
    removeAt(ca1, 2);
    removeAt(ca1, 0);
    removeAt(ca1, 0);

    append(ca1, 'd');
    append(ca1, 'o');
    append(ca1, 'n');
    append(ca1, 'e');


    return 0;
}
