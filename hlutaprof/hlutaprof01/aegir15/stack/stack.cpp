#include "stack.h"

Stack::Stack()
{
    top = NULL;
    count = 0;
}

Stack::~Stack()
{
    ListNode * node = top;
    while(top != NULL) {
        top = top->next;
        delete node;
        node = top;
    }
}

void Stack::push(Measurement data) {

    ListNode *node = new ListNode(data, top);
    top = node;
    count++;

}

Measurement Stack::pop() {
    if(top == NULL) {
        throw EmptyException();
    }
    Measurement data = top->data;
    ListNode *node = top;
    top = top->next;
    delete node;
    count--;
    return data;
}

int Stack::size() {
    return count;
}

bool Stack::isEmpty() {
    return count == 0;
}

ostream& operator <<(ostream &out, const Stack &s) {

    ListNode *node = s.top;
    while(node != NULL) {
        out << node->data << " ";
        node = node->next;
    }
    return out;
}
