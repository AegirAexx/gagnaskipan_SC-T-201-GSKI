#include "doublylinkedlist.h"

// Iterator Class
DoublyLinkedList::Iterator::Iterator<T>(Node<T> *node){
  currNode = node; 
}

T& DoublyLinkedList::Iterator::operator* (){
  return currNode->item;
}

bool DoublyLinkedList::Iterator::operator== (const Iterator& p) const{
  return currNode == p.currNode;
}

bool DoublyLinkedList::Iterator::operator!= (const Iterator& p) const{
  return currNode != p.currNode;
}

DoublyLinkedList::Iterator<T>& DoublyLinkedList::Iterator::operator++ (){
  // Missing ERROR handler
  // TODO: logic check
  currNode = currNode->next;
  return *this;
}

DoublyLinkedList::Iterator<T>& DoublyLinkedList::Iterator::operator-- (){
  // Missing ERROR handler
  // TODO: logic check
  currNode = currNode->prev;
  return *this;
}

// DoublyLinkedList Class
DoublyLinkedList::DoublyLinkedList<T>(){
  listSize = 0;
  currentPosition = 0;
  head = new Node<T>;
  tail = new Node<T>;
  head->next = tail;
  tail->prev = head;
  currNode = head->next;
}

// DoublyLinkedList<T>(): 
//   head(new Node<T>(nullptr, tail)), 
//   tail(new Node<T>(head, nullptr)), 
//   currNode(nullptr), 
//   size(0), 
//   currentPosition(0) {}

DoublyLinkedList::~DoublyLinkedList<T>(){            
  clear();
  delete head;
  delete tail;           
}

int DoublyLinkedList::length() const{
  return listSize;
}

bool DoublyLinkedList::isEmpty() const{
  return (listSize == 0);
}

Iterator<T> DoublyLinkedList::begin() const{
  return Iterator(head->next);
}

Iterator<T> DoublyLinkedList::end() const{
  return Iterator(tail);
}

Iterator<T> DoublyLinkedList::location() const{
  return Iterator(currNode);
}

// Need to implement iterator TODO: MERGE
int DoublyLinkedList::curr_pos() const{
  return currentPosition;
}

void DoublyLinkedList::insert(const T& item){
  addAtThisNode(currNode, item);
}

void DoublyLinkedList::insertFront(const T& item){
  addAtThisNode(begin(), item);
}

void DoublyLinkedList::append(const T& item){
  addAtThisNode(end(), item);
}

T DoublyLinkedList::remove(){
  T retValue = currNode->data;
  removeThisNode(currNode);
  return retValue;
}

void DoublyLinkedList::clear(){
  while(!isEmpty()){
    removeThisNode(head->next);
  }
}

void DoublyLinkedList::move_to_start(){
  currNode = begin();
}

void DoublyLinkedList::move_to_end(){
  currNode = end();
}

void DoublyLinkedList::move_to_pos(int pos){
  int steps = listSize - pos;
  if(steps < 0){
    throw exception();
  }else{
    currNode = end();
    for(int i = 0; i < steps; ++i){
      currNode--;
    }
  }
}

void DoublyLinkedList::prev(){
  currNode--;
}

void DoublyLinkedList::next(){
  currNode++;
}


void DoublyLinkedList::iteratorExceptionHandler(Node<T> *location, Node<T> *end){
  if(location == end){
    throw InvalidPositionException();
  }
}

ostream& operator <<(ostream& out, const DoublyLinkedList<T>& lis){
  for(Node<T> *nodeOut = lis.head->next; nodeOut->next != lis.tail->next; nodeOut = nodeOut->next){
    out << nodeOut->data << " ";
  }
  return out;
}

void DoublyLinkedList::addAtThisNode(const DoublyLinkedList::iterator& indexNode, const T& item){
  listSize++;
  Node<T> *addNode = new Node<T>(item, indexNode->prev, indexNode);
  if(isEmpty()){
    currNode = addNode ;
    currentPosition = 1;
  }
  if(indexNode == nullptr){
    indexNode = tail;
    currentPosition = listSize;
  }
  if(indexNode == head){
    indexNode = head->next;
  }
  indexNode->prev->next = addNode ;
  indexNode->prev = addNode ;
}

void DoublyLinkedList::removeThisNode(Node<T> *toRemove){
  ListNode<T> *tempPrev = toRemove->prev;
  ListNode<T> *tempNext = toRemove->next;
  tempPrev->next = tempNext;
  tempNext->prev = tempPrev;
  delete toRemove;
  size--;
}
