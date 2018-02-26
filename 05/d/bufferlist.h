#ifndef BUFFERLIST_H
#define BUFFERLIST_H

#include <iostream>

#include "stack.h"
#include "queue.h"

const int INITIAL_CAPACITY = 4;

template <class T>
class BufferList : public Queue<T>, public Stack<T>
{
public:
    BufferList() {
        capacity = INITIAL_CAPACITY;
        itemCount = 0;
        data = new T [capacity];
    }

    virtual ~BufferList() {
        delete [] data;
    }

    void push(T t){
        if(itemCount == capacity){
            resizeArray();
        }
        for(int i = itemCount - 1; i >= 0; --i){
            data[i + 1] = data[i];
        }
        data[0] = t;
        itemCount++;
    }

    T pop(){
        if(itemCount == 0) {
            throw EmptyException();
        }
        T retData = data[0];
        for(int i = 0; i < itemCount - 1; ++i){
            data[i] = data[i + 1];
        }
        itemCount--;
        return retData;
    }

    void add(T t){
        if(itemCount == capacity){
            resizeArray();
        }
        data[itemCount] = t;
        itemCount++;
    }

    T remove(){
        if(itemCount == 0) {
            throw EmptyException();
        }
        T retData = data[0];
        for(int i = 0; i < itemCount - 1; ++i){
            data[i] = data[i + 1];
        }
        itemCount--;
        return retData;
    }

    void print(ostream &outs) const {
        for(int i = 0; i < itemCount; ++i){
            outs << data[i] << " ";
        }
    }

    friend ostream& operator <<(ostream& outs, const BufferList<T> &lis) {
        lis.print(outs);
        return outs;
    }

private:
    int capacity;
    int itemCount;
    T *data;

    void resizeArray(){
        capacity *= 2;
        T *tempArray = new T [capacity];
        for(int i = 0; i < itemCount; ++i){
            tempArray[i] = data[i];
        }
        delete [] data;
        data = tempArray;
    }

};

#endif // BUFFERLIST_H
