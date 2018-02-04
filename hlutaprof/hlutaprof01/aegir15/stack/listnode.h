#ifndef LISTNODE_H
#define LISTNODE_H

#include "measurement.h"

class EmptyException{};

class ListNode
{
    public:
        ListNode() : data("", 0), next(NULL) {};
        ListNode(Measurement data, ListNode *next) : data(data), next(next) {};
        virtual ~ListNode(){};

        Measurement data;
        ListNode *next;
};

#endif // LISTNODE_H
