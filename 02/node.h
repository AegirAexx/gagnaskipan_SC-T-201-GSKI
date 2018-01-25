//aegir15@ru.is & dagur17@ru.is

#ifndef NODE_H
#define NODE_H

#include "measurement.h"

class EmptyException{};

class Node{
    public:
        Node();
        Node(Measurement data);
        Node(Measurement data, Node *node);

        virtual ~Node();

        Node *next;
        Measurement data;
};

#endif // NODE_H
