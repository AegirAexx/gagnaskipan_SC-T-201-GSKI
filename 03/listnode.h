#ifndef LISTNODE_H
#define LISTNODE_H

template <typename T>
class ListNode {
public:
    ListNode<T>(): prev(nullptr), next(nullptr) {}

    ListNode<T>(T value): data(value), prev(nullptr), next(nullptr) {}
    
    ListNode<T>(ListNode<T> *prev, ListNode<T> *next): prev(prev), next(next) {}
    
    ListNode<T>(T value, ListNode<T> *prev, ListNode<T> *next): data(value), prev(prev), next(next) {}
    
    virtual ~ListNode() {}

    T data;
    ListNode<T> *prev;
    ListNode<T> *next;

};

#endif // LISTNODE_H
