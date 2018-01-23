#ifndef QUEUE_H
#define QUEUE_H

#include "node.h"

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