#include <iostream>
#include "StringList.h"

using namespace std;

int main() {

    StringList lis;

    cout << "Testing insert()" << endl;

    lis.append("bxp");
    lis.append("fic");
    lis.append("wet");
    lis.append("gor");
    cout << lis << endl;
    cout << "expected output: " << "bxp fic wet gor" << endl;
    cout << "your output:     " << lis << endl;

    lis.move_to_pos(2);
    lis.insert("pod");
    cout << "expected output: " << "bxp fic pod wet gor" << endl;
    cout << "your output:     " << lis << endl;

    lis.move_to_pos(2);
    lis.insert("sed");
    cout << "expected output: " << "bxp fic sed pod wet gor" << endl;
    cout << "your output:     " << lis << endl;

    lis.move_to_start();
    lis.insert("doc");
    cout << "expected output: " << "doc bxp fic sed pod wet gor" << endl;
    cout << "your output:     " << lis << endl;

    lis.move_to_end();
    lis.insert("cal");
    cout << "expected output: " << "doc bxp fic sed pod wet gor cal" << endl;
    cout << "your output:     " << lis << endl;

    cout << endl;
    cout << "Testing remove()" << endl;
    lis.clear();
    lis.append("doc");
    lis.append("bxp");
    lis.append("fic");
    lis.append("sed");
    lis.append("pod");
    lis.append("wet");
    lis.append("gor");
    lis.append("cal");

    cout << "expected output: " << "doc bxp fic sed pod wet gor cal" << endl;
    cout << "your output:     " << lis << endl;


    lis.move_to_pos(4);

    cout << "expected output: " << "doc bxp fic sed wet gor cal" << endl;
    cout << "your output:     ";
    try{
        lis.remove();
        cout << lis << endl;
    }catch(InvalidPositionException) {
        cout << "Caught InvalidPositionException" << endl;
    }

    lis.move_to_end();

    cout << "expected output: " << "Caught InvalidPositionException" << endl;
    cout << "your output:     ";
    try{
        lis.remove();
        cout << lis << endl;
    }catch(InvalidPositionException) {
        cout << "Caught InvalidPositionException" << endl;
    }

    lis.prev();

    cout << "expected output: " << "doc bxp fic sed wet gor" << endl;
    cout << "your output:     ";
    try{
        lis.remove();
        cout << lis << endl;
    }catch(InvalidPositionException) {
        cout << "Caught InvalidPositionException" << endl;
    }

    lis.move_to_start();

    cout << "expected output: " << "bxp fic sed wet gor" << endl;
    cout << "your output:     ";
    try{
        lis.remove();
        cout << lis << endl;
    }catch(InvalidPositionException) {
        cout << "Caught InvalidPositionException" << endl;
    }

    lis.move_to_pos(1);

    cout << "expected output: " << "bxp sed wet gor" << endl;
    cout << "your output:     ";
    try{
        lis.remove();
        cout << lis << endl;
    }catch(InvalidPositionException) {
        cout << "Caught InvalidPositionException" << endl;
    }

    lis.move_to_start();

    cout << "expected output: " << "sed wet gor" << endl;
    cout << "your output:     ";
    try{
        lis.remove();
        cout << lis << endl;
    }catch(InvalidPositionException) {
        cout << "Caught InvalidPositionException" << endl;
    }

    cout << "expected output: " << "wet gor" << endl;
    cout << "your output:     ";
    try{
        lis.remove();
        cout << lis << endl;
    }catch(InvalidPositionException) {
        cout << "Caught InvalidPositionException" << endl;
    }

    cout << "expected output: " << "gor" << endl;
    cout << "your output:     ";
    try{
        lis.remove();
        cout << lis << endl;
    }catch(InvalidPositionException) {
        cout << "Caught InvalidPositionException" << endl;
    }

    cout << "expected output: " << "" << endl;
    cout << "your output:     ";
    try{
        lis.remove();
        cout << lis << endl;
    }catch(InvalidPositionException) {
        cout << "Caught InvalidPositionException" << endl;
    }

    cout << "expected output: " << "Caught InvalidPositionException" << endl;
    cout << "your output:     ";
    try{
        lis.remove();
        cout << lis << endl;
    }catch(InvalidPositionException) {
        cout << "Caught InvalidPositionException" << endl;
    }

    cout << endl;
    cout << "Testing insert() into empty" << endl;

    lis.clear();
    cout << "expected output: " << "" << endl;
    cout << "your output:     " << lis << endl;

    lis.insert("single");
    cout << "expected output: " << "single" << endl;
    cout << "your output:     " << lis << endl;

    return 0;
}

