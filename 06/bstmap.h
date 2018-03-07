#ifndef BSTMAP_H
#define BSTMAP_H

#include "binarytreenode.h"
#include "map.h"

template <typename K, typename T>
class BSTMap : public Map<K, T> {

public:
    BSTMap<K, T>(): 
        root(nullptr), 
        treeCount(0)
    {}

    virtual ~BSTMap<K, T>() {
        clear();
        delete root;
    }

    void insert(K key, T data) {
        BinaryTreeNode<K, T>* &node = find(key, root);
        if(node != nullptr) {
            throw ItemExistsException();
        }
        node = new BinaryTreeNode<K, T>(key, data);
        treeCount++;
    }

    void update(K key, T data) {
        BinaryTreeNode<K, T>* &node = find(key, root);
        if(node == nullptr) {
            throw NotFoundException();
        }
        node->data = data;
    }

    T get(K key) {
        BinaryTreeNode<K, T>* &node = find(key, root);
        if(node == nullptr) {
            throw NotFoundException();
        }
        return node->data;
    }

    void remove(K key) {
        BinaryTreeNode<K, T>* &node = find(key, root);
        if(node == nullptr) {
            throw NotFoundException();
        }
        removeNode(node);
        treeCount--;
    }

    bool contains(K key) {
        BinaryTreeNode<K, T>* node = find(key, root);
        if(node == nullptr) {
            return false;
        }
        return true;
    }

    int size() const {
        return treeCount;
    }

    bool empty() const {
        return size() == 0;
    }

    void clear() {
        removeSubTree(root);
        root = nullptr;
        treeCount = 0;
    }

    void print(std::ostream& out) const {
        printInorder(root);
    }

private:
    BinaryTreeNode<K, T>* root;
    int treeCount;

    void removeNode(BinaryTreeNode<K, T>* &node) {
        if(node->left == nullptr && node->right == nullptr) {
            delete node;
            node = nullptr;
        }
        else if(node->right == nullptr) {
            BinaryTreeNode<K, T>* tmp = node;
            node = node->left;
            delete tmp;
        }
        else if(node->left == nullptr) {
            BinaryTreeNode<K, T>* tmp = node;
            node = node->right;
            delete tmp;
        }
        else {
            BinaryTreeNode<K, T>* &nodeForDeletion = findRightMostNode(node->left);
            node->data = nodeForDeletion->data;
            node->key = nodeForDeletion->key;
            removeNode(nodeForDeletion);
        }
    }

    void removeSubTree(BinaryTreeNode<K, T>* &node) {
        if(node != nullptr) {
            removeSubTree(node->left);
            removeSubTree(node->right);
            delete node;
            node = nullptr;
        }
    }

    void printInorder(BinaryTreeNode<K, T>* node) const {
        if(node != nullptr) {
            printInorder(node->left);
            std::cout << node->data << " ";
            printInorder(node->right);
        }
    }

    BinaryTreeNode<K, T>* &find(char key, BinaryTreeNode<K, T>* &node) {
        if(node == nullptr) {
            return node;
        }
        if(key < node->key) {
            return find(key, node->left);
        }
        else if (key > node->key) {
            return find(key, node->right);
        }
        return node;
    }

    BinaryTreeNode<K, T>* &findRightMostNode(BinaryTreeNode<K, T>* &node) {
        if(node->right == nullptr) {
            return node;
        }
        return findRightMostNode(node->right);
    }
};

#endif // BSTMAP_H
