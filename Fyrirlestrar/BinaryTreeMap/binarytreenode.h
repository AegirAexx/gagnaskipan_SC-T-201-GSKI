#ifndef BINARYTREENODE_H
#define BINARYTREENODE_H

#include "dataclass.h"
#include <stdio.h>

class BinaryTreeNode
{
    public:
        BinaryTreeNode(char key, DataClass data, BinaryTreeNode *left = NULL, BinaryTreeNode *right = NULL)
                        : key(key), data(data), left(left), right(right) {};
        virtual ~BinaryTreeNode() {};

        char key;
        DataClass data;
        BinaryTreeNode *left;
        BinaryTreeNode *right;
};

#endif // BINARYTREENODE_H
