#ifndef DOUBLY_LINKED_LIST_H
#define DOUBLY_LINKED_LIST_H

#include <iostream>

#include "listnode.h"

using namespace std;

class InvalidPositionException {};

class emptyListException {};

// I had to add <T> everywhere the name of the class is invoked.
template <typename T>

class DoublyLinkedList{
    
    public:
        // I am not able to inline initialize the member variables.
        // TODO: WHY can't I ILI the variables like there initialized everywhere else?
        // DoublyLinkedList<T>(): head(nullptr), tail(nullptr), currNode(nullptr), size(0), currentPosition(0)  {}
        // DoublyLinkedList<T>(): head(new ListNode<T>(nullptr, tail), tail(new ListNode<T>(head, nullptr), currNode(nullptr), size(0), currentPosition(0)  {}

        DoublyLinkedList<T>(){
            head = nullptr;
            tail = nullptr;
            head = new ListNode<T>(nullptr, tail);
            tail = new ListNode<T>(head, nullptr);
            currNode = nullptr;
            size = 0;
            currentPosition = 0;
        }

        ~DoublyLinkedList<T>(){            
            while(!isEmpty()){
                removeThisNode(head->next);
            }
            delete head;
            delete tail;           
        }

        /// Clear contents from the list, to make it empty.
        /// Worst-case time complexity: Linearb
        void clear(){
            while(!isEmpty()){
                removeThisNode(head->next);
            }
        }

        /// Insert an element at the current location.
        /// item: The element to be inserted
        /// Worst-case time complexity: Constant
        void insert(const T& item){
            addAtThisNode(currNode, item);
        }

        /// Append an element at the end of the list.
        /// item: The element to be appended.
        /// Worst-case time complexity: Constant
        void append(const T& item){
            addAtThisNode(tail, item);
        }

        /// Remove and return the current element.
        /// Return: the element that was removed.
        /// Worst-case time complexity: Constant
        /// Throws InvalidPositionException if current position is
        /// behind the last element
        T remove(){
            T retValue = currNode->data;
            removeThisNode(currNode);
            return retValue;
        }

        /// Set the current position to the start of the list
        /// Worst-case time complexity: Constant
        void move_to_start(){
            currNode = head->next;
            currentPosition = 1;
        }

        /// Set the current position to the end of the list
        /// Worst-case time complexity: Constant
        void move_to_end(){
            currNode = tail->prev;
            currentPosition = size;
        }

        /// Move the current position one step left. No change
        /// if already at beginning.
        /// Worst-case time complexity: Constant
        void prev(){
            if(currNode->prev == head){
                throw InvalidPositionException();
            }
            currNode = currNode->prev;
            currentPosition--;
        }

        /// Move the current position one step right. No change
        /// if already at end.
        /// Worst-case time complexity: Constant
        void next(){
            if(currNode->next == tail){
                throw InvalidPositionException();
            }
            currNode = currNode->next;
            currentPosition++;
        }

        /// Return: The number of elements in the list.
        /// Worst-case time complexity: Constant
        int length() const{
            return size;
        }

        /// Return: The position of the current element.
        /// Worst-case time complexity: Constant
        int curr_pos() const{
            return currentPosition;
        }

        /// Set current position.
        /// pos: The position to make current.
        /// Worst-case time complexity: Linear
        /// Throws InvalidPositionException if 'pos' is not a valid position
        void move_to_pos(int pos){
            if(pos < 1 || pos > size || pos == currentPosition){
                throw InvalidPositionException();
            }
            int stepsToMove = currentPosition - pos;
            If(stepsToMove > 0){
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

        // This funtion was added for functionality.
        bool isEmpty() const{
            return (head->next == tail);
        }

        // Remove function added for Destructor. To start it's a "remove from the front" function.
        // It needs to be generalized to work from anywhere in the list.
        void removeThisNode(ListNode<T> *toRemove){
            if(toRemove->prev == head && toRemove->next == tail){
                throw emptyListException();
            }

            ListNode<T> *tempPrev = toRemove->prev;
            ListNode<T> *tempNext = toRemove->next;
            tempPrev->next = tempNext;
            tempNext->prev = tempPrev;
            delete toRemove;

        }

        void addAtThisNode(ListNode<T> *indexNode, T& item){
            ListNode<T> *node = new ListNode<T>(item, indexNode->prev, indexNode);
            indexNode->prev->next = node;
            indexNode->prev = node;
            if(currNode == nullprt){
                currNode = node;
                currentPosition = 1;
            }
            size++;
        }

        /// Return: The current element.
        /// Worst-case time complexity: Constant
        /// Throws InvalidPositionException if current position is
        /// behind the last element
        const T& get_value() const{
            return currNode->data;
        }


        /// Outputs the elements of 'lis' to the stream 'outs', separated
        /// by a single space.
        friend ostream& operator <<(ostream& outs, const DoublyLinkedList& lis){
            for(ListNode<T> *node = lis.head->next; node->next != tail; node = node->next){
                out << node->data << " ";
            return outs;
        }

    private:

        ListNode<T> *head;
            // T data; [NOT USED]
            // ListNode<T> *prev;
            // ListNode<T> *next;

        ListNode<T> *tail;
            // T data; [NOT USED]
            // ListNode<T> *prev;
            // ListNode<T> *next;
        

        ///currNode is the node at the current position
        ListNode<T> *currNode;
            // T data;
            // ListNode<T> *prev;
            // ListNode<T> *next;

        int size;
        int currentPosition;

};


#endif // DOUBLY_LINKED_LIST_H
