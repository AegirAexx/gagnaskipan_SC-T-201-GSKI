#ifndef STACK_H
#define STACK_H

#include "measurement.h"
#include "node.h"
#include <ostream>


class Stack {
  public:
    Stack();
    virtual ~Stack();

    void push(Measurement data);
    Measurement pop();

    int size() const;

    bool isEmpty() const;

    friend ostream& operator << (ostream& out, const Stack& s);

  private:
    Node *head;
    Node *tail;
    int counter;


};




#endif // STACK_H
