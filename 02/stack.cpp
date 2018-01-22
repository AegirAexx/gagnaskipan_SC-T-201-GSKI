#include "stack.h"


Stack::Stack(): head(NULL), tail(NULL), counter(0){}

Stack::~Stack(){

    for(Node *tmpNode; tmpNode != NULL; head = head->next){
        delete tmpNode;
        tmpNode = head;
    }
}

void Stack::push(Measurement data){
    Node *tmpNode = new Node(data, head);

    if(head == NULL){
        tail = tmpNode;
    }

    head = tmpNode;
    counter++;
}

Measurement Stack::pop(){

    if(isEmpty()){
        throw EmptyException();
    }
    else{
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
    }
    else{
        return false;
    }
}

ostream& operator << (ostream& out, const Stack& s){

    for(Node *node = s.head; node != NULL; node = node->next){
        out << node->data << " ";
    }

    return out;
}
