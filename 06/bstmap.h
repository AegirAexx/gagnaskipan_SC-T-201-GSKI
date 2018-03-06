#ifndef BSTMAP_H
#define BSTMAP_H

#include "binarytreenode.h"
#include "map.h"

template <class K, class T>
class BSTMap : public Map<K, T>
{
    public:
        BSTMap<K, T>() {
            root = NULL;
            treeCount = 0;
        }

        virtual ~BSTMap<K, T>() {
            clear();
            delete root;
        }

        void insert(K key, T data) {
            BinaryTreeNode<K, T>* &node = find(key, root);

            if(node != NULL) {
                throw ItemExistsException();
            }

            node = new BinaryTreeNode<K, T>(key, data);
            treeCount++;
        }

        void update(K key, T data) {

            BinaryTreeNode<K, T>* &node = find(key, root);

            if(node == NULL) {
                throw NotFoundException();
            }

            node->data = data;
        }

        T get(K key) {
            BinaryTreeNode<K, T>* &node = find(key, root);

            if(node == NULL) {
                throw NotFoundException();
            }

            return node->data;
        }

        void remove(K key) {
            BinaryTreeNode<K, T>* &node = find(key, root);

            if(node == NULL) {
                throw NotFoundException();
            }

            removeNode(node);
            treeCount--;
        }

        bool contains(K key) {

            BinaryTreeNode<K, T>* node = find(key, root);

            if(node == NULL) {
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
            root = NULL;
            treeCount = 0;
        }

        void print(ostream& out) const {

            printInorder(root);
        }



    private:
        BinaryTreeNode<K, T>* root;
        int treeCount;

        void removeNode(BinaryTreeNode<K, T>* &node) {

            if(node->left == NULL && node->right == NULL) {
                delete node;
                node = NULL;
            }
            else if(node->right == NULL) {
                BinaryTreeNode<K, T>* tmp = node;
                node = node->left;
                delete tmp;
            }
            else if(node->left == NULL) {
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

            if(node != NULL) {
                removeSubTree(node->left);
                removeSubTree(node->right);
                delete node;
                node = NULL;
            }
        }

        void printInorder(BinaryTreeNode<K, T>* node) const {

            if(node != NULL) {
                printInorder(node->left);
                cout << node->data << " ";
                printInorder(node->right);
            }
        }

        BinaryTreeNode<K, T>* &find(char key, BinaryTreeNode<K, T>* &node) {

            if(node == NULL) {
                return node;
            }

            if(key < node->key) {
                return find(key, node->left);
            }
            else if (node->key < key) {
                return find(key, node->right);
            }

            return node;
        }

        BinaryTreeNode<K, T>* &findRightMostNode(BinaryTreeNode<K, T>* &node) {

            if(node->right == NULL) {
                return node;
            }
            return findRightMostNode(node->right);

        }
};

#endif // BSTMAP_H
