#ifndef STRINGNODE_H
#define STRINGNODE_H

template <typename T>
class ListNode{
    
    private:
        T data;
        ListNode<T> *prev;
        ListNode<T> *next;
        friend class DoublyLinkedList;

    public:
        ListNode(): prev(nullptr), next(nullptr) {}
        ListNode(T value): data(value), prev(nullptr), next(nullptr) {}
        ListNode(ListNode<T> *prev, ListNode<T> *next): prev(prev), next(next) {}
        ListNode(T value, ListNode<T> *prev, ListNode<T> *next): data(value), prev(prev), next(next) {}
        virtual ~ListNode() {}
};

#endif // INTNODE_H
