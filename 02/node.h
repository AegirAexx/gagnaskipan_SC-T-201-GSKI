#ifndef NODE_H
#define NODE_H

#include "measurement.h"
#include <string>
#include <iostream>

class EmptyException{};

class Node {
  public:
    Node();
    Node(Measurement data);
    Node(Measurement data, Node *node);

    virtual ~Node();

    Node *next;
    Measurement data;

    friend ostream& operator << (ostream& out, const Node& node);

  private:



};




#endif // NODE_H
