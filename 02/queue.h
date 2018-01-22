#ifndef QUEUE_H
#define QUEUE_H

#include "measurement.h"
#include "node.h"
#include <ostream>


class Queue {
  public:
    Queue();
    virtual ~Queue();


    void add(Measurement data);

    Measurement remove();

    int size() const;

    bool isEmpty() const;

    friend ostream& operator << (ostream& out, const Queue& q);

  private:
    Node *head;
    Node *tail;
    int counter;



};




#endif // QUEUE_H
