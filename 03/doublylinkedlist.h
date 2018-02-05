#ifndef DOUBLY_LINKED_LIST_H
#define DOUBLY_LINKED_LIST_H

#include <iostream>

#include "listnode.h"

using namespace std;

class InvalidPositionException {};
class emptyListException {};

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

        void move_to_pos(int pos){
            if(pos < 1 || pos > size || pos == currentPosition){
                throw InvalidPositionException();
            }
            int stepsToMove = currentPosition - pos;
            if(stepsToMove > 0){
                for(size_t i = 0; 0 < stepsToMove; ++i){
                    prev();                
                }
            }else{
                stepsToMove *= -1;
                for(size_t i = 0; 0 < stepsToMove; ++i){
                    next();
                }                
            }
        }

        bool isEmpty() const{
            return (head->next == tail);
        }

        void removeThisNode(ListNode<T> *toRemove){
            // if(toRemove->prev == head && toRemove->next == tail){
            //     throw emptyListException();
            // }
            ListNode<T> *tempPrev = toRemove->prev;
            ListNode<T> *tempNext = toRemove->next;
            tempPrev->next = tempNext;
            tempNext->prev = tempPrev;
            delete toRemove;
            size--;
        }

        void addAtThisNode(ListNode<T> *indexNode, const T& item){
            if(indexNode == nullptr){
                indexNode = tail;
                currentPosition = 1;
            }
            ListNode<T> *node = new ListNode<T>(item, indexNode->prev, indexNode);
            indexNode->prev->next = node;
            indexNode->prev = node;
            if(currNode == nullptr){
                currNode = node;
                currentPosition = 1;
            }
            size++;
        }

        const T& get_value() const{
            return currNode->data;
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
