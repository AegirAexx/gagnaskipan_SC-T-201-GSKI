#ifndef STACK_H
#define STACK_H

#include <ostream>

#include "listnode.h"

class Stack
{
    public:
        Stack();
        virtual ~Stack();

        void push(Measurement data);
        Measurement pop();
        int size();
        bool isEmpty();

        friend ostream& operator <<(ostream &out, const Stack &s);

    protected:

    private:
        ListNode *top;
        int count;
};

#endif // STACK_H
