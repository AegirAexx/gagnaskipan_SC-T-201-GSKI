#ifndef STACK_H
#define STACK_H

#include <iostream>

using namespace std;

template <class T>
class Stack
{
    public:
        virtual ~Stack(){};

        virtual void print(ostream& outs) const = 0;

        virtual void push(T t) = 0;

        virtual T pop() = 0;

        friend ostream& operator <<(ostream& outs, const Stack<T> &stac) {
            stac.print(outs);
            return outs;
        }

};

#endif // STACK_H

