#include "stack.h"

Stack::Stack(): head(nullptr), tail(nullptr), counter(0) {}

Stack::~Stack(){

    for(Node *tmpNode = head; tmpNode != nullptr; head = head->next){
        delete tmpNode;
        tmpNode = head;
    }
}

void Stack::push(Measurement data){

    Node *tmpNode = new Node(data, head);
    if(head == nullptr){
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

    if(counter == 0){
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
