#include <iostream>

#include "pair.h"

using namespace std;

/////////////////DO NOT MAKE CHANGES IN THIS FILE/////////////////////

int main() {

    Pair<string, int> p0("zero", 0);
    cout << "Your output:     " << p0 << endl;
    cout << "Expected output: {zero, 0}" << endl;
    cout << endl;

    Pair<double, int> p1(1.1, 1);
    cout << "Your output:     " << p1 << endl;
    cout << "Expected output: {1.1, 1}" << endl;
    cout << endl;

    Pair<string, string> p2("two", "another two");
    cout << "Your output:     " << p2 << endl;
    cout << "Expected output: {two, another two}" << endl;
    cout << endl;

    Pair<int, string> p3(3, "three");
    cout << "Your output:     " << p3 << endl;
    cout << "Expected output: {3, three}" << endl;
    cout << endl;

    Pair<int, int> p4(4, 4);
    cout << "Your output:     " << p4 << endl;
    cout << "Expected output: {4, 4}" << endl;
    cout << endl;

    Pair<char, int> p5('5', 5);
    cout << "Your output:     " << p5 << endl;
    cout << "Expected output: {5, 5}" << endl;
    cout << endl;

    Pair<char, string> p6('6', "6");
    cout << "Your output:     " << p6 << endl;
    cout << "Expected output: {6, 6}" << endl;
    cout << endl;

    Pair<char, string> p7('7', "seven");
    cout << "Your output:     " << p7 << endl;
    cout << "Expected output: {7, seven}" << endl;
    cout << endl;

    Pair<long long, int> p8(8888888888888888888, 8888888888888888888);
    cout << "Your output:     " << p8 << endl;
    cout << "Expected output: {" << (long long)(8888888888888888888) << ", " << (int)(8888888888888888888) << "}" << endl;
    cout << endl;

    Pair<string, double> p9("almost ten", 9.9999);
    cout << "Your output:     " << p9 << endl;
    cout << "Expected output: {almost ten, 9.9999}" << endl;
    cout << endl;


    return 0;
}
