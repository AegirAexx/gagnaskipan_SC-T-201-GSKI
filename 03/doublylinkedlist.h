#ifndef DOUBLY_LINKED_LIST_H
#define DOUBLY_LINKED_LIST_H

#include <iostream>
#include "listnode.h"

using namespace std;

class InvalidPositionException {};

template <typename T>

class DoublyLinkedList{

    public:

        DoublyLinkedList<T>(): head(new ListNode<T>(nullptr, tail)), tail(new ListNode<T>(head, nullptr)), currNode(nullptr), size(0), currentPosition(0) {}

        ~DoublyLinkedList<T>(){
            clear();

            delete head;
            delete tail;
        }

        void clear(){
            while(!isEmpty()){
                removeThisNode(head->next);
            }
            currNode = head->next;
            currentPosition = 0;
        }

        void insert(const T& item){
            addAtThisNode(currNode, item);
        }

        void append(const T& item){
            addAtThisNode(tail, item);
            currentPosition = size;
            currNode = tail->prev;
        }

        T remove(){
            if(isEmpty()){
                throw InvalidPositionException();
            }
            T retValue = currNode->data;
            ListNode<T> *tmp = currNode->next;
            removeThisNode(currNode);
            currNode = tmp;
            return retValue;
        }

        void move_to_start(){
            currNode = head->next;
            currentPosition = 1;
        }

        void move_to_end(){
            currNode = tail->prev;
            currentPosition = size;
        }

        void prev(){
            if(currNode->prev == head){
                throw InvalidPositionException();
            }
            currNode = currNode->prev;
            currentPosition--;
        }

        void next(){
            if(currNode->next == tail){
                throw InvalidPositionException();
            }
            currNode = currNode->next;
            currentPosition++;
        }

        int length() const{
            return size;
        }

        int curr_pos() const{
            return currentPosition;
        }

        bool isEmpty() const{
            return (head->next == tail);
        }

        const T& get_value() const{
            return currNode->data;
        }

        void move_to_pos(int pos){
            int steps = (size - 1) - pos;

            if(steps < 0){
                throw InvalidPositionException();
            }

            currNode = tail->prev;
            currentPosition = size - 1;

            for(int i = 0; i < steps; ++i){
                  prev();
            }
        }

        void removeThisNode(ListNode<T> *toRemove){
            ListNode<T> *tempPrev = toRemove->prev;
            ListNode<T> *tempNext = toRemove->next;
            tempPrev->next = tempNext;
            tempNext->prev = tempPrev;
            delete toRemove;
            size--;
        }

        void addAtThisNode(ListNode<T> *indexNode, const T& item){
            size++;
            ListNode<T> *node = new ListNode<T>(item, indexNode->prev, indexNode);
            if(isEmpty()){
                currNode = node;
            }
            if(indexNode == nullptr){
                indexNode = tail;
            }
            if(indexNode == head){
                indexNode = head->next;
            }
            indexNode->prev->next = node;
            indexNode->prev = node;
        }

        void iteratorExceptionHandler(ListNode<T> *currentLocation, ListNode<T> *relativeEnd){
            if(currentLocation == relativeEnd){
                throw InvalidPositionException();
            }
        }

        friend ostream& operator <<(ostream& out, const DoublyLinkedList& lis){
            for(ListNode<T> *node = lis.head->next; node->next != lis.tail->next; node = node->next){
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
};


#endif // DOUBLY_LINKED_LIST_H
