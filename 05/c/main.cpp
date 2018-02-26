#include <iostream>
#include "queue.h"
#include "bufferlist.h"

using namespace std;

template <class T>
void addTest(Queue<T> *que, T value) {
    cout << "add(" << value << ")" << endl;
    que->add(value);
    cout << "queue: " << *que << endl;
    cout << endl;
}

template <class T>
void removeTest(Queue<T> *que) {
    try
    {
        cout << "remove()" << endl;
        T value = que->remove();
        cout << "value = " << value << endl;
        cout << "queue: " << *que << endl;
    }
    catch(EmptyException) {
        cout << "Caught EmptyException" << endl;
    }
    cout << endl;
}

void intQueueTest(Queue<int> *que) {

    addTest(que, 53);

    removeTest(que);
    removeTest(que);

    addTest(que, 3);
    addTest(que, 8);
    addTest(que, 43);

    removeTest(que);

    addTest(que, 58);
    addTest(que, 1003);

    removeTest(que);
    removeTest(que);

    addTest(que, 333);
    addTest(que, 338);
    addTest(que, 3343);
    addTest(que, 118);
    addTest(que, 1143);
    addTest(que, 3000000);

    removeTest(que);
    removeTest(que);
    removeTest(que);
    removeTest(que);

    removeTest(que);
    removeTest(que);
    removeTest(que);
    removeTest(que);

    removeTest(que);
    removeTest(que);
}

void doubleQueueTest(Queue<double> *que) {

    addTest(que, 53.7);


    removeTest(que);
    removeTest(que);

    addTest(que, 3.4);

    addTest(que, 8.8);

    addTest(que, 43.3);


    removeTest(que);

    addTest(que, 58.2);

    addTest(que, 1003.7);


    removeTest(que);
    removeTest(que);
}

void stringQueueTest(Queue<string> *que) {

    addTest(que, (string)"cercei");

    removeTest(que);
    removeTest(que);

    addTest(que, (string)"arya");
    addTest(que, (string)"daenerys");
    addTest(que, (string)"margaery");

    removeTest(que);

    addTest(que, (string)"sansa");
    addTest(que, (string)"olenna");

    removeTest(que);
    removeTest(que);
}

void testBufferListQueue() {

    cout << "\n -- new Queue --" << endl;
    Queue<int> *que1 = new BufferList<int>();
    intQueueTest(que1);
    delete que1;

    cout << "\n -- new Queue --" << endl;
    Queue<double> *que2 = new BufferList<double>();
    doubleQueueTest(que2);
    delete que2;

    cout << "\n -- new Queue --" << endl;
    Queue<string> *que3 = new BufferList<string>();
    stringQueueTest(que3);
    delete que3;
}

int main() {

    ///Comment these out one by one for more focused tests

    testBufferListQueue();

    return 0;
}