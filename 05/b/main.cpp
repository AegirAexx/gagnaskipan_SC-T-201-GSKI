#include <iostream>
#include "stack.h"
#include "bufferlist.h"

using namespace std;

template <class T>
void pushTest(Stack<T> *stac, T value) {
    cout << "push(" << value << ")" << endl;
    stac->push(value);
    cout << "stack: " << *stac << endl;
    cout << endl;
}

template <class T>
void popTest(Stack<T> *stac) {
    try
    {
        cout << "pop()" << endl;
        T value = stac->pop();
        cout << "value = " << value << endl;
        cout << "stack: " << *stac << endl;
    }
    catch(EmptyException) {
        cout << "Caught EmptyException" << endl;
    }
    cout << endl;
}


void intStackTest(Stack<int> *stac) {

    pushTest(stac, 53);

    popTest(stac);
    popTest(stac);

    pushTest(stac, 3);
    pushTest(stac, 8);
    pushTest(stac, 43);

    popTest(stac);

    pushTest(stac, 58);
    pushTest(stac, 1003);

    popTest(stac);
    popTest(stac);

    pushTest(stac, 333);
    pushTest(stac, 338);
    pushTest(stac, 3343);
    pushTest(stac, 118);
    pushTest(stac, 1143);
    pushTest(stac, 3000000);

    popTest(stac);
    popTest(stac);
    popTest(stac);
    popTest(stac);

    popTest(stac);
    popTest(stac);
    popTest(stac);
    popTest(stac);

    popTest(stac);
    popTest(stac);
}

void doubleStackTest(Stack<double> *stac) {

    pushTest(stac, 53.8);

    popTest(stac);
    popTest(stac);

    pushTest(stac, 33.35);
    pushTest(stac, 8.7);
    pushTest(stac, 43.56);

    popTest(stac);

    pushTest(stac, 58.6);
    pushTest(stac, 1003.5);

    popTest(stac);
    popTest(stac);
}

void stringStackTest(Stack<string> *stac) {

    pushTest(stac, (string)"ned");


    popTest(stac);


    popTest(stac);

    pushTest(stac, (string)"brandon");

    pushTest(stac, (string)"jamie");

    pushTest(stac, (string)"tywin");


    popTest(stac);

    pushTest(stac, (string)"sandor");

    pushTest(stac, (string)"gregor");


    popTest(stac);
    popTest(stac);
}


void testBufferListStack() {

    cout << "\n -- new Stack --" << endl;
    Stack<int> *stac1 = new BufferList<int>();
    intStackTest(stac1);
    delete stac1;

    cout << "\n -- new Stack --" << endl;
    Stack<double> *stac2 = new BufferList<double>();
    doubleStackTest(stac2);
    delete stac2;

    cout << "\n -- new Stack --" << endl;
    Stack<string> *stac3 = new BufferList<string>();
    stringStackTest(stac3);
    delete stac3;
}


int main() {

    ///Comment these out one by one for more focused tests

    testBufferListStack();

    cout << "Everything was able to finish!!" << endl;

    return 0;
}