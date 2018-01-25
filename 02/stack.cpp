//aegir15@ru.is & dagur17@ru.is

#include "stack.h"

Stack::Stack(): head(nullptr), tail(nullptr), counter(0) {}

Stack::~Stack(){

    // for(Node *tmpNode = head; tmpNode != nullptr; head = head->next){
    //     delete tmpNode;
    //     tmpNode = head;
    // }

    Node *node = head;
    while(node != nullptr){
        head = head->next;
        delete node;
        node = head;
    }
}

void Stack::push(Measurement data){

    Node *tmpNode = new Node(data, head);
    if(isEmpty()){
        tail = tmpNode;
    }
    head = tmpNode;
    counter++;
}

Measurement Stack::pop(){

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

int Stack::size() const{
    return counter;
}

bool Stack::isEmpty() const{

    if(head == nullptr){
        return true;
    }else{
        return false;
    }
}

std::ostream& operator << (std::ostream& out, const Stack& s){

    for(Node *node = s.head; node != nullptr; node = node->next){
        out << node->data << " ";
    }
    return out;
}
