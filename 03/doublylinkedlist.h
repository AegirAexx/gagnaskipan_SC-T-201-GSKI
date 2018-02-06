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
            while(!isEmpty()){
                removeThisNode(head->next);
            }
            delete head;
            delete tail;           
        }

        void clear(){
            while(!isEmpty()){
                removeThisNode(head->next);
            }
            currNode = nullptr;
        }

        void insert(const T& item){
            addAtThisNode(currNode, item);
        }

        void append(const T& item){
            addAtThisNode(tail, item);
        }

        T remove(){
            T retValue = currNode->data;
            removeThisNode(currNode);
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
            iteratorExceptionHandler(currNode->prev, head);
            currNode = currNode->prev;
            currentPosition--;
        }

        void next(){
            iteratorExceptionHandler(currNode->next, tail);
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
            if(pos < 0 || pos > size){
                throw InvalidPositionException();
            }
            int stepsToMove = currentPosition - pos;
            if(stepsToMove > 0){
                for(size_t i = 0; 0 < stepsToMove; ++i){
                    prev();                
                }
            }else if(stepsToMove < 0){
                stepsToMove *= -1;
                for(size_t i = 0; 0 < stepsToMove; ++i){
                    next();
                }                
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
                currentPosition = 1;
            }
            if(indexNode == nullptr){
                indexNode = tail;
                currentPosition = size;
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
