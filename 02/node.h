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

        friend std::ostream& operator << (std::ostream& out, const Node& node);

        Node *next;
        Measurement data;
};

#endif // NODE_H
