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

    BinaryTreeNode* &node = find(key, root);  //Ver� a� f� node pointer reference �arna svo �g f�i a�gang a� �essu tiltekna NULL, til a� geta b�tt g�gnum inn� �� tilteknu n��u, vill skil a�gangi a� sta�num �ar sem �g vil hengja n�ju n��una

    if(node == NULL) {
        node = new BinaryTreeNode(key, data); //B� til n�ja n��u � sta�num sem var skila� �r find fallinu, �etta gerist allt �taf & merkinu, ef �g v�ri ekki me� reference � �essu �� myndi �etta ekki virka, n��an myndi ekki b�tast inn � r�ttan sta�
        return true;
    }
    return false;
}

bool BinaryTree::contains(char key) {

    BinaryTreeNode* node = find(key, root);
    if(node == NULL) { //Vi� treystum find fallinu, ef find fann eitthva� �� er staki� � tr�inu, ef find falli� er NULL �� fannst ekkert, � raun h�gt a� segja ///return find(c, root); ef ma�ur vill
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

    if(node == NULL) { //Ef engin g�gn
        return node;  //H�rna skilar ma�ur n��unni sj�lfri en ekki return NULL, vi� viljum skila n��unni sj�lfri
    }

    if(key < node->key) { //ef g�gnin eru st�rri en c
        return find(key, node->left);
    }
    else if (node->key < key) {  //Ef g�gnin eru minni en c
        return find(key, node->right);
    }

    return node;  //�a� eru � raun 2 base case, h�rna er anna� base casei�, �.e. ef g�gnin eru jafnst�r og c
}

void BinaryTree::removeNode(BinaryTreeNode* &node) {

    if(node->left == NULL && node->right == NULL) { //�etta er lauf
        cout << "REMOVE LEAF" << endl;
        delete node;
        node = NULL;  //�etta virkar �v� �g er a� senda node inn sem reference &
    }
    else if(node->right == NULL) { //Vinstri barn er til
        cout << "REMOVE Node with leeft child" << endl;
        BinaryTreeNode* tmp = node; //tengja framhj� og delete
        node = node->left;
        delete tmp;
    }
    else if(node->left == NULL) { //H�gri barn er til
        cout << "REMOVE Node with right child" << endl;
        BinaryTreeNode* tmp = node; //tengja framhj� og delete
        node = node->right;
        delete tmp;
    }
    else { //B��i b�rn eru til
        cout << "REMOVE Node with 2 children" << endl;
        BinaryTreeNode* &nodeForDeletion = findRightMostNode(node->left); //B�a til reference pointer � n��una
        node->data = nodeForDeletion->data; //afrita g�gnin �r n��unni sem er lengst til h�gri yfir � n��una sem vi� erum a� vinna me�
        removeNode(nodeForDeletion);
    }
}

BinaryTreeNode* &BinaryTree::findRightMostNode(BinaryTreeNode* &node) {

    if(node->right == NULL) {
        return node;
    }
    return findRightMostNode(node->right);

}

void BinaryTree::removeSubTree(BinaryTreeNode* &node) {  //reference � pointer, til a� geta sett NULL sem node ne�st, vi� viljum breyta n��ubendinum sem er allsta�ar,ekki bara �a� sem er � fallinu. Vi� �urfum a� geta breytt n��unni sj�lfri

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
