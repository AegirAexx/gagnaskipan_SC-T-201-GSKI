//aegir15@ru.is & dagur17@ru.is

#include "queue.h"




Queue::Queue(): head(nullptr), tail(nullptr), counter(0) {}

Queue::~Queue(){
/*
    for(Node *tmpNode = head; tmpNode != nullptr; head = head->next){
        delete tmpNode;
        tmpNode = head;
    }*/

    Node *node = head;
    while(node != nullptr){

        head = head->next;
        delete node;
        node = head;
    }
}

void Queue::add(Measurement data){

    /*if(head == nullptr){
        Node *tmpNode = new Node(data, tail);
        head = tmpNode;
        tail = tmpNode;
        counter++;
    }else{
        tail->next = new Node(data);
        tail = tail->next;
        counter++;
    }*/

    if(head == nullptr){
        Node *tmpNode = new Node(data);

        head = tmpNode;
        tail = tmpNode;
        counter++;
    }
    else{
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

/*
     for(Node *node = q.head; node != nullptr; node = node->next){
        out << node->data << " ";
    }
*/
    Node *node = q.head;

    while(node != nullptr){

        out << node->data << " ";
        node = node->next;
    }

    /*for(int i = 0; i < q.size(); i++){
        out << q.head->node->data;
    }*/


    return out;
}

//Unit test

void Queue::unitAddress() const{

    std::cout << "Head next: " << head->next << std::endl;
    std::cout << "Tail next: " << tail->next << std::endl;

    std::cout << "Head: " << head << std::endl;
    std::cout << "Tail: " << tail << std::endl;
}
