#ifndef DOUBLY_LINKED_LIST_H
#define DOUBLY_LINKED_LIST_H

#include <iostream>
#include "listnode.h"

using namespace std;

class InvalidPositionException { };

template <typename T>
class DoublyLinkedList {
public:

    DoublyLinkedList<T>():
        head(new ListNode<T>(nullptr, tail)),
        tail(new ListNode<T>(head, nullptr)),
        currNode(tail), size(0), currentPosition(0) { }

    ~DoublyLinkedList<T>() {
        clear();
        delete head;
        delete tail;
    }

    void clear() {
        while (!isEmpty()) {
            removeThisNode(head->next);
        }
        currNode = tail;
        currentPosition = 0;
    }

    void insert(const T& item) {
        if (isEmpty()) {
            addAtThisNode(currNode, item);
            currentPosition = size;
        }
        else {
            addAtThisNode(currNode, item);
            currentPosition++;
        }
    }

    void append(const T& item) {
        addAtThisNode(tail, item);

        if(currNode == tail){
            currentPosition = size;
        }

    }

    T remove() {
        if (currNode == tail) {
            throw InvalidPositionException();
        }
        T retValue = currNode->data;
        ListNode<T> *tmp = currNode->next;
        removeThisNode(currNode);

        currNode = tmp;

        return retValue;
    }

    void move_to_start() {
        currNode = head->next;
        currentPosition = 0;
    }

    void move_to_end() {
        currNode = tail;
        currentPosition = size;
    }

    void prev() {
        if (currentPosition > 0) {
            currNode = currNode->prev;
            currentPosition--;
        }
    }

    void next() {
        if(currentPosition < size){
            currNode = currNode->next;
            currentPosition++;
        }
    }

    int length() const {
        return size;
    }

    int curr_pos() const {
        return currentPosition;
    }

    const T& get_value() const {
        if (currNode == tail) {
            throw InvalidPositionException();
        }
        return currNode->data;
    }

    void move_to_pos(int pos) {
        if (pos < 0) {
            throw InvalidPositionException();
        }
        int steps = size - pos;
        if (steps < 0) {
            throw InvalidPositionException();
        }
        currNode = tail;
        currentPosition = size;
        for (int i = 0; i < steps; ++i) {
            prev();
        }
    }

    friend ostream& operator <<(ostream& out, const DoublyLinkedList& lis) {
        for (ListNode<T> *node = lis.head->next; node->next != lis.tail->next; node = node->next) {
            out << node->data << " ";
        }
        return out;
    }

private:

    ListNode<T> *head;
    ListNode<T> *tail;
    ListNode<T> *currNode;
    int size;
    int currentPosition;

    void addAtThisNode(ListNode<T> *indexNode, const T& item) {
        ListNode<T> *node = new ListNode<T>(item, indexNode->prev, indexNode);

        indexNode->prev->next = node;
        indexNode->prev = node;
        size++;
    }

    void removeThisNode(ListNode<T> *toRemove) {
        ListNode<T> *tempPrev = toRemove->prev;
        ListNode<T> *tempNext = toRemove->next;
        tempPrev->next = tempNext;
        tempNext->prev = tempPrev;
        delete toRemove;
        size--;
    }

    bool isEmpty() const {
        return (size == 0);
    }

};


#endif // DOUBLY_LINKED_LIST_H
