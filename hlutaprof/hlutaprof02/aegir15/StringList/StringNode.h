#ifndef STRINGNODE_H
#define STRINGNODE_H

#include <string>

using namespace std;

struct StringNode
{
    string data;
    StringNode *prev;
    StringNode *next;

    StringNode() : data(""), prev(NULL), next(NULL) { }
    StringNode(string value, StringNode *prev = NULL, StringNode *next = NULL)
    : data(value), prev(prev), next(next) { }

};

typedef StringNode* NodePtr;

#endif // INTNODE_H
