//aegir15@ru.is & dagur17@ru.is

#include "node.h"

Node::Node(): next(nullptr), data("", 0.0) {}

Node::Node(Measurement data): next(nullptr), data(data) {}

Node::Node(Measurement data, Node *next): next(next), data(data) {}

Node::~Node() {};
