#include "queue.h"

Queue::Queue(): head(NULL), tail(NULL), counter(0){}

Queue::~Queue(){

    /*for(Node *tmpNode; tmpNode != NULL; head = head->next){
        delete tmpNode;
        tmpNode = head;
    }*/

    Node *tmpNode = head;

    while(tmpNode != NULL){

        head = head->next;
        delete tmpNode;
        tmpNode = head;
    }
}

void Queue::add(Measurement data){
    /*Node *tmpNode = new Node(data, head);

    if(head == NULL){
        head = tmpNode;
    }

    tail = tmpNode;
    counter++;*/

    if(head == NULL){
        Node *tmpNode = new Node(data, tail);

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

int Queue::size() const{
    return counter;
}

bool Queue::isEmpty() const{

    if(counter == 0){
        return true;
    }
    else{
        return false;
    }
}

ostream& operator << (ostream& out, const Queue& q){

     for(Node *node = q.head; node != NULL; node = node->next){
        out << node->data << " ";
    }

    return out;

}
