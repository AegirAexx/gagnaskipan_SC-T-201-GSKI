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
    if(head == NULL || head->next == NULL) {  //Ef ad Head == NULL (listinn er tómur), ef head-next == NULL þá er eitt stak í listanum og við skilum head
        return head;
    }

    ListNode *tmpNode = reverseList(head->next);  //Búum til tmpNode sem kallar recursive á reverseList og tekur inn næstu node
    head->next->next = head; //Snúum síðasta gildinu við
    head->next = NULL; //látum næstsíðasta gildið benda á NULL

    return tmpNode; //Skilum bendinu á nýja hausinn
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
