#ifndef STACK_H
#define STACK_H

#include "node.h"

class Stack{
    public:
        Stack();
        virtual ~Stack();

        void push(Measurement data);
        Measurement pop();

        int size() const;
        bool isEmpty() const;

        friend std::ostream& operator << (std::ostream& out, const Stack& s);

    private:
        Node *head;
        Node *tail;
        int counter;
};

#endif // STACK_H
