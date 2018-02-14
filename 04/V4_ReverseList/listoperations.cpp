#include "listoperations.h"

ListOperations::ListOperations()
{
    //ctor
}

ListOperations::~ListOperations()
{
    //dtor
}

ListNode* ListOperations::reverseList(ListNode *head) {

    ///TODO: Implement
    if(head == NULL || head->next == NULL) {  //Ef ad Head == NULL (listinn er t�mur), ef head-next == NULL �� er eitt stak � listanum og vi� skilum head
        return head;
    }

    ListNode *tmpNode = reverseList(head->next);  //B�um til tmpNode sem kallar recursive � reverseList og tekur inn n�stu node
    head->next->next = head; //Sn�um s��asta gildinu vi�
    head->next = NULL; //l�tum n�sts��asta gildi� benda � NULL

    return tmpNode; //Skilum bendinu � n�ja hausinn
}

void ListOperations::printList(ostream& out, ListNode *head) {
    while(head != NULL) {
        out << head->data << " ";
        head = head->next;
    }
    out << endl;
}

void ListOperations::deleteList(ListNode *head) {
    if(head != NULL) {
        deleteList(head->next);
        delete head;
    }
}
