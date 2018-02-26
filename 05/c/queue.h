#ifndef QUEUE_H
#define QUEUE_H

#include <iostream>

using namespace std;

template <class T>
class Queue
{
public:
    virtual ~Queue(){};

    virtual void print(ostream& outs) const = 0;

    virtual void add(T t) = 0;

    virtual T remove() = 0;

    friend ostream& operator <<(ostream& outs, const Queue<T> &que) {
        que.print(outs);
        return outs;
    }

};

#endif // QUEUE_H

