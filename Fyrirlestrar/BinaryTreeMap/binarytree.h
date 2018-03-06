#ifndef BINARYTREE_H
#define BINARYTREE_H

#include "dataclass.h"
#include <stdio.h>
#include "binarytreenode.h"

class NotFoundException{};

class BinaryTree
{
    public:
        BinaryTree();
        virtual ~BinaryTree();

        bool insert (char key, DataClass);
        bool contains(char key);
        DataClass get(char key);
        bool remove(char key);



        void printPreorder();
        void printInorder();
        void printPostorder();

        void clear();
        void removeSubTree(BinaryTreeNode* &node);

    protected:

    private:
        BinaryTreeNode *root;

        void printPreorder(BinaryTreeNode* node);
        void printInorder(BinaryTreeNode* node);

        BinaryTreeNode* &find(char c, BinaryTreeNode* &node);

        void removeNode(BinaryTreeNode* &node);

        BinaryTreeNode* &findRightMostNode(BinaryTreeNode* &node);
};

#endif // BINARYTREE_H
