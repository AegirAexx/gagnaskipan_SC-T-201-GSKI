#include "binarytree.h"

#include <iostream>

using namespace std;

BinaryTree::BinaryTree()
{
    //root = new BinaryTreeNode('A', new BinaryTreeNode('B', new BinaryTreeNode('C'), new BinaryTreeNode('D')), new BinaryTreeNode('E', NULL, new BinaryTreeNode('F')));
    root = NULL;
}

BinaryTree::~BinaryTree()
{
    clear();

}

void BinaryTree::clear() {

    removeSubTree(root);
    root = NULL;
}

bool BinaryTree::insert (char key, DataClass data) {

    BinaryTreeNode* &node = find(key, root);  //Verð að fá node pointer reference þarna svo ég fái aðgang að þessu tiltekna NULL, til að geta bætt gögnum inní þá tilteknu nóðu, vill skil aðgangi að staðnum þar sem ég vil hengja nýju nóðuna

    if(node == NULL) {
        node = new BinaryTreeNode(key, data); //Bý til nýja nóðu á staðnum sem var skilað úr find fallinu, þetta gerist allt útaf & merkinu, ef ég væri ekki með reference á þessu þá myndi þetta ekki virka, nóðan myndi ekki bætast inn á réttan stað
        return true;
    }
    return false;
}

bool BinaryTree::contains(char key) {

    BinaryTreeNode* node = find(key, root);
    if(node == NULL) { //Við treystum find fallinu, ef find fann eitthvað þá er stakið í tréinu, ef find fallið er NULL þá fannst ekkert, í raun hægt að segja ///return find(c, root); ef maður vill
        return false;
    }

    return true;
}

DataClass BinaryTree::get(char key) {

    BinaryTreeNode* &node = find(key, root);

    if(node == NULL) {
        throw NotFoundException();
    }
    return node->data;
}

bool BinaryTree::remove(char key) {

    BinaryTreeNode* &node = find(key, root);
    if(node == NULL) {
        return false;
    }

    removeNode(node);
    return true;
}

BinaryTreeNode* &BinaryTree::find(char key, BinaryTreeNode* &node) {

    if(node == NULL) { //Ef engin gögn
        return node;  //Hérna skilar maður nóðunni sjálfri en ekki return NULL, við viljum skila nóðunni sjálfri
    }

    if(key < node->key) { //ef gögnin eru stærri en c
        return find(key, node->left);
    }
    else if (node->key < key) {  //Ef gögnin eru minni en c
        return find(key, node->right);
    }

    return node;  //Það eru í raun 2 base case, hérna er annað base caseið, þ.e. ef gögnin eru jafnstór og c
}

void BinaryTree::removeNode(BinaryTreeNode* &node) {

    if(node->left == NULL && node->right == NULL) { //Þetta er lauf
        cout << "REMOVE LEAF" << endl;
        delete node;
        node = NULL;  //Þetta virkar því ég er að senda node inn sem reference &
    }
    else if(node->right == NULL) { //Vinstri barn er til
        cout << "REMOVE Node with leeft child" << endl;
        BinaryTreeNode* tmp = node; //tengja framhjá og delete
        node = node->left;
        delete tmp;
    }
    else if(node->left == NULL) { //Hægri barn er til
        cout << "REMOVE Node with right child" << endl;
        BinaryTreeNode* tmp = node; //tengja framhjá og delete
        node = node->right;
        delete tmp;
    }
    else { //Bæði börn eru til
        cout << "REMOVE Node with 2 children" << endl;
        BinaryTreeNode* &nodeForDeletion = findRightMostNode(node->left); //Búa til reference pointer á nóðuna
        node->data = nodeForDeletion->data; //afrita gögnin úr nóðunni sem er lengst til hægri yfir í nóðuna sem við erum að vinna með
        removeNode(nodeForDeletion);
    }
}

BinaryTreeNode* &BinaryTree::findRightMostNode(BinaryTreeNode* &node) {

    if(node->right == NULL) {
        return node;
    }
    return findRightMostNode(node->right);

}

void BinaryTree::removeSubTree(BinaryTreeNode* &node) {  //reference á pointer, til að geta sett NULL sem node neðst, við viljum breyta nóðubendinum sem er allstaðar,ekki bara það sem er í fallinu. Við þurfum að geta breytt nóðunni sjálfri

    if(node != NULL) {
        removeSubTree(node->left);
        removeSubTree(node->right);
        delete node;
        node = NULL;
    }
}

void BinaryTree::printPreorder() {

    printPreorder(root);
}

void BinaryTree::printInorder() {

    printInorder(root);
}

void BinaryTree::printPostorder() {

}

void BinaryTree::printPreorder(BinaryTreeNode* node) {

    if(node != NULL) {
        cout << node->data;
        printPreorder(node->left);
        printPreorder(node->right);
    }
}

void BinaryTree::printInorder(BinaryTreeNode* node) {

    if(node != NULL) {
        printInorder(node->left);
        cout << node->data << " ";
        printInorder(node->right);
    }
}
