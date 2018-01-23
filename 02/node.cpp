#include "node.h"

Node::Node(): next(nullptr), data("", 0.0) {}

Node::Node(Measurement data): next(nullptr), data(data) {}

Node::Node(Measurement data, Node *next): next(next), data(data) {}

Node::~Node() {};

std::ostream& operator << (std::ostream& out, const Node& node){
    out << node.data;
    return out;
}
