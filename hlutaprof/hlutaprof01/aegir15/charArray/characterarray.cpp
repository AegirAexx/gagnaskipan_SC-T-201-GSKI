#include "characterarray.h"

CharacterArray::CharacterArray()
{
    capacity = 2;
    size = 0;
    arr = new char[capacity + 1];
    for(int i = 0; i < capacity + 1; i++) {
        arr[i] = '\0';
    }
}

CharacterArray::CharacterArray(char* str, int length)
{
    capacity = length;
    size = length;
    arr = new char[capacity + 1];
    for(int i = 0; i < length; i++) {
        arr[i] = str[i];
    }
    arr[length] = '\0';
}

CharacterArray::~CharacterArray()
{
    delete[] arr;
}

void CharacterArray::append(char c) {

    if(size == capacity) {
        resizeArray();
    }
    arr[size] = c;
    size++;
}

void CharacterArray::setAt(char c, int index) {

    if(index < 0 || index >= size) {
        throw IndexOutOfBoundsException();
    }
    arr[index] = c;
}

char CharacterArray::getAt(int index) const {

    if(index < 0 || index >= size) {
        throw IndexOutOfBoundsException();
    }
    return arr[index];
}

char CharacterArray::pop_back() {

    if(isEmpty()) {
        throw EmptyException();
    }
    char retVal = arr[size-1];
    arr[size-1] = '\0';
    size--;
    return retVal;
}

char CharacterArray::removeAt(int index) {

    if(index < 0 || index >= size) {
        throw IndexOutOfBoundsException();
    }

    char retVal = arr[index];

    for(int i = index; i < size; ++i){
        arr[i] = arr[i + 1];
    }
    size--;

    return retVal;
}

void CharacterArray::clear() {

    for(int i = 0; i < size; i++) {
        arr[i] = '\0';
    }
    size = 0;
}

int CharacterArray::length() const{

    return size;
}

bool CharacterArray::isEmpty() const{

    return (size == 0);
}

char* CharacterArray::substring(int startIndex, int length) {

    if(startIndex < 0 || startIndex + length > size || length < 0) {
        throw IndexOutOfBoundsException();
    }
    char* tmp = new char[length + 1];
    for(int i = 0; i < length; i++) {
        tmp[i] = arr[i + startIndex];
    }
    tmp[length] = '\0';
    return tmp;
}

ostream& operator <<(ostream& out, const CharacterArray& ca) {
    out << ca.arr;
    return out;
}

void CharacterArray::resizeArray() {

    capacity *= 2;
    char *tmp = new char[capacity + 1];
    for(int i = 0; i < size; i++) {
        tmp[i] = arr[i];
    }
    delete[] arr;
    arr = tmp;
    for(int i = size; i < capacity + 1; i++) {
        arr[i] = '\0';
    }
}
