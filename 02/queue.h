//aegir15@ru.is & dagur17@ru.is

#ifndef QUEUE_H
#define QUEUE_H

#include "node.h"
#include <iostream>

class Queue{
    public:
        Queue();
        virtual ~Queue();

        void add(Measurement data);
        Measurement remove();

        int size() const;
        bool isEmpty() const;

        friend std::ostream& operator << (std::ostream& out, const Queue& q);

    private:
        Node *head;
        Node *tail;
        int counter;
};

#endif // QUEUE_H
