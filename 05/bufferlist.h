#ifndef BUFFERLIST_H
#define BUFFERLIST_H

#include <iostream>

#include "queue.h"
#include "stack.h"

///You MUST use this value of initial capacity when you return you final version
///but feel free to change it while testing (to first test regular functionality)
#define INITIAL_CAPACITY 4

///TODO: Inherit both Queue and Stack
class BufferList
{
    public:
        BufferList() {

            ///TODO: Initialize buffer (dynamic array) of size INITIAL_CAPACITY (this is important!!)
        }

        virtual ~BufferList() {

            ///TODO: Delete your buffer (dynamic array)
        }

        ///TODO: Override functions from Stack ADT

        ///TODO: Override functions from Queue ADT

        ///print override:
        void print(ostream &outs) const {

            ///TODO: Implement print for your own testing
            ///This is not tested on Mooshak, so it doesn't
            ///matter exactly how you print the list
        }

        friend ostream& operator <<(ostream& outs, const BufferList<T> &lis) {
            lis.print(outs);
            return outs;
        }

    private:
        ///TODO: Set up class variables and private helper functions, as needed


};

#endif // BUFFERLIST_H
