#ifndef LINKEDLIST_H
#define LINKEDLIST_H

#include "stack.h"
#include "queue.h"
#include "listnode.h"


template <class T>
class LinkedList : public Queue<T>, public Stack<T>
{
    public:
        LinkedList(): head(NULL), tail(NULL){}

        virtual ~LinkedList() {
            for(ListNode<T> *tmpNode = head; tmpNode != NULL; tmpNode = head) {
                head = head->next;
                delete tmpNode;
            }

        }

        void add(T t) {

            if(head == NULL) {
                ListNode<T> *tmpNode = new ListNode<T>(t);
                head = tmpNode;
                tail = tmpNode;
            }
            else {
                tail->next = new ListNode<T>(t);
                tail = tail->next;
            }
        }

        T remove() {

            if(head == NULL) {
                throw EmptyException();
            }
            else {
                ListNode<T> *tmpNode = head;
                head = head->next;
                T retData = tmpNode->data;
                delete tmpNode;
                return retData;
            }
        }

        void push(T t) {

            ListNode<T> *tmpNode = new ListNode<T>(head, t);

            if (head == NULL) {
                tail = tmpNode;
            }

            head = tmpNode;
        }

        T pop() {

            if (head == NULL) {
                throw EmptyException();
            }
            else {
                ListNode<T> *tmpNode = head;
                head = head->next;
                T retData = tmpNode->data;
                delete tmpNode;
                return retData;
            }
        }

        void print(ostream& outs) const {

            for(ListNode<T> *listnode = head; listnode != NULL; listnode = listnode->next) {
                outs << listnode->data << " ";
            }
        }


    private:
        ListNode<T> *head;
        ListNode<T> *tail;

};

#endif // LINKEDLIST_H
