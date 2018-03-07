#ifndef BINARYTREENODE_H
#define BINARYTREENODE_H

template <typename K, typename T>
class BinaryTreeNode {

public:
    BinaryTreeNode(K key, T data, BinaryTreeNode *left = nullptr, BinaryTreeNode *right = nullptr): 
        key(key), 
        data(data), 
        left(left), 
        right(right)
    {}
    
    virtual ~BinaryTreeNode() {}

    K key;
    T data;
    BinaryTreeNode *left;
    BinaryTreeNode *right;
};

#endif // BINARYTREENODE_H
