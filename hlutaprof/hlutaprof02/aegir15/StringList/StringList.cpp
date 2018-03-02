#include <iostream>
#include <stdio.h>
#include "StringList.h"

StringList::StringList() {
    size = 0;

    //initialize head and tail
    head = new StringNode();
    tail = new StringNode();

    //Connect head and tail to each other
    head->next = tail;
    tail->prev = head;

    //currNode is set at tail, so new nodes will be added before currNode
    currNode = tail;

    currentPosition = 0;
}

StringList::~StringList() {

    //Clear the list
    clear();

    // Also delete the preceding and trailing nodes, head an tail
    // because we need to free all memory
    delete head;
    delete tail;
}

void StringList::clear() {
    // Start at next after head,
    // because head itself is an
    // extra empty node, not one
    // of the data nodes.
    currNode = head->next;

    // As soon as we're at tail we stop
    // because tail itself is an
    // extra empty node, not one
    // of the data nodes.
    while(currNode != tail) {
        head->next = currNode->next;
        delete currNode;
        currNode = head->next;
    }

    //Make sure to reconnect head an tail both directions.
    tail->prev = head;
    size = 0;
    currentPosition = 0;
}


void StringList::insert(const string& item) {

    if(head->next == tail){
        NodePtr newNode = new StringNode(item, tail->prev, head->next);
        tail->prev = newNode;
        head->next = newNode;
    }
    else{
        NodePtr newNode = new StringNode(item, currNode->prev, currNode);
        currNode->prev = newNode;
        currNode->prev->next = newNode;
    }

    size++;
    currentPosition++;

}

void StringList::append(const string& item) {

    //Make a new node, containing the data item,
    // that connects to the tail with "next"
    // and the node before tail with "prev"
    StringNode *newNode = new StringNode(item, tail->prev, tail);

    // The node before tail connects to the new node with "next"
    tail->prev->next = newNode;

    // The tail connects to the new node with "prev"
    // remember that tail is not a real data node, so
    // the new node is in effect the last node now,
    // even though tail is behind it
    tail->prev = newNode;

    // If our current position is at the back of the list
    // the new node becomes the current node as well
    if(currNode == tail) {
        currNode = newNode;
    }

    // THe list is now one element longer
    size++;
}

string StringList::remove() {

    if(currNode == tail){
        throw InvalidPositionException();
    }

    NodePtr tempPrev = currNode->prev;
    NodePtr tempNext = currNode->next;

    string returnData = currNode->data;
    currNode->prev->next = tempNext;
    currNode->next->prev = tempPrev;

    delete currNode;
    currNode = tempNext;
    size--;


    return returnData;  // REMOVE THIS LINE - Its just to return something
}

void StringList::move_to_start() {

    // Move the the node after head, because head is not an actual data node
    currNode = head->next;
    currentPosition = 0;
}

void StringList::move_to_end() {

    // Move to tail, because we can be at a position one behind the list
    // in order to add to its end
    currNode = tail;
    currentPosition = size;
}

void StringList::prev() {
    if(currNode != head->next) {
        currNode = currNode->prev;
        currentPosition--;
    }
}

void StringList::next() {
    if(currNode != tail) {
        currNode = currNode->next;
        currentPosition++;
    }
}

int StringList::length() const {
    return size;
}

int StringList::curr_pos() const {
    return currentPosition;
}

void StringList::move_to_pos(int pos) {
    if(pos < 0 || pos > size) {
        throw InvalidPositionException();
    }

    // while the current position is still higher than
    // the desired position we move forward in the list
    while(pos < currentPosition) {
        prev();
    }

    // while the current position is still lower than
    // the desired position we move backward in the list
    while(pos > currentPosition) {
        next();
    }
}

const string& StringList::get_value() const {

    if(currNode == tail) {
        throw InvalidPositionException();
    }

    // Return the data element from the current node
    return currNode->data;
}

ostream& operator <<(ostream& outs, const StringList& lis) {

    // Start at the node after head, and and before tail
    // since head and tail are not actual data nodes themselves
    StringNode *tmpNode = lis.head->next;
    while(tmpNode != lis.tail) {
        outs << tmpNode->data << " ";
        tmpNode = tmpNode->next;
    }

    return outs;
}
