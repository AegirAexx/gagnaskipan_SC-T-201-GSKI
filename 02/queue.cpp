//aegir15@ru.is & dagur17@ru.is

#include "queue.h"

Queue::Queue(): head(nullptr), tail(nullptr), counter(0) {}

Queue::~Queue(){

    Node *node = head;
    while(node != nullptr){
        head = head->next;
        delete node;
        node = head;
    }
}

void Queue::add(Measurement data){

    if(isEmpty()){
        Node *tmpNode = new Node(data);
        head = tmpNode;
        tail = tmpNode;
        counter++;
    }else{
        tail->next = new Node(data);
        tail = tail->next;
        counter++;
    }
}

Measurement Queue::remove(){

    if(isEmpty()){
        throw EmptyException();
    }else{
        Node *tmpNode = head;
        head = head->next;
        Measurement retData = tmpNode->data;
        delete tmpNode;
        counter--;
        return retData;
    }
}

int Queue::size() const{
    return counter;
}

bool Queue::isEmpty() const{

    if(head == nullptr){
        return true;
    }else{
        return false;
    }
}

std::ostream& operator << (std::ostream& out, const Queue& q){

    Node *node = q.head;
    while(node != nullptr){
        out << node->data << " ";
        node = node->next;
    }

    return out;
}

