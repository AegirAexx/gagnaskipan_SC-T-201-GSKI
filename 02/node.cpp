#include "node.h"

Node::Node(): next(NULL), data("", 0.0){}

Node::Node(Measurement data): next(NULL), data(data){}

Node::Node(Measurement data, Node *next): next(next), data(data){}

Node::~Node(){};

ostream& operator << (ostream& out, const Node& node){

}


