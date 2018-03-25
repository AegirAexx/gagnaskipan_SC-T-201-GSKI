#ifndef KEYDATALISTNODE_H
#define KEYDATALISTNODE_H

#include <string>

template <class K, class T>
class KeyDataListNode
{
    public:

        KeyDataListNode(K key, T data, KeyDataListNode *next) : key(key), data(data), next(next) {};
        virtual ~KeyDataListNode() {};

        K key;
        T data;
        KeyDataListNode<K, T> *next;

    protected:

    private:
};

#endif // KEYDATALISTNODE_H
