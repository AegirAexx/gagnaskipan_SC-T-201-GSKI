#ifndef DOUBLY_LINKED_LIST_H
#define DOUBLY_LINKED_LIST_H

#include <ostream>

class InvalidPositionException {};

template <typename T>
class DoublyLinkedList {
  
  // The Node in the list - 
  // Private Member - Nested Class - ADT?
  private:
    template <typename T>
    struct Node {
      Node<T>(): perv(nullptr), next(nullptr) {}
      T item;
      Node<T> *prev;
      Node<T> *next;
    }

  // The iterator - Represented by the current Node - 
  // Public Member - Nested Class - ADT?
  public:
    template<typename T>
    class Iterator { 
      public:
        T& operator* ();

        bool operator ==(const Iterator<T>& p) const;
        bool operator !=(const Iterator<T>& p) const;

        Iterator<T>& operator ++();
        Iterator<T>& operator --();

        friend Class DoublyLinkedList;

      private:    
        Iterator(Node<T> *node);
        Node<T> *currNode;
    };

  // The Public API - DoublyLinkedList()
  // Public Member Functions - Parent Class? - Super Class?
  public:
    DoublyLinkedList<T>();
    virtual ~DoublyLinkedList<T>();

    int length() const;
    int curr_pos() const;

    bool isEmpty() const;

    Iterator<T> begin() const;
    Iterator<T> end() const;
    Iterator<T> location() const;

    void insert(const T& item);
    void insertFront(const T& item);    
    void append(const T& item);
    void append(const T& item);

    T remove();
    void clear();

    void move_to_start();
    void move_to_end();
    void move_to_pos(int pos);
    void prev();
    void next();

    // private?
    void iteratorExceptionHandler(Node<T> *location, Node<T> *end);

    friend ostream& operator <<(ostream& out, const DoublyLinkedList<T>& lis);

  // DoublyLinkedList() Private Member Variables -
  // Private Utility Functions
  private:
    Node *head;
    Node *tail;
    int listSize;
    int currentPosition;

    void addAtThisNode(Node<T> *indexNode, const T& item);
    void removeThisNode(Node<T> *toRemove);

};

#endif // DOUBLY_LINKED_LIST_H