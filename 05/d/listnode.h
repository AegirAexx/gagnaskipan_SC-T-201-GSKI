#ifndef LISTNODE_H
#define LISTNODE_H

#include "emptyexception.h"

template <class T>
class ListNode
{
    public:
        ListNode(): next(NULL){}
        ListNode(T value) : next(NULL), data(value) {}
        ListNode(ListNode<T> *next, T value) : next(next), data(value) {}
        virtual ~ListNode() {}

        ListNode *next;
        T data;
};

#endif // LISTNODE_H
