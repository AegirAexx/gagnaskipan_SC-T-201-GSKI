#include "characterarray.h"

CharacterArray::CharacterArray(){

    capacity = INITIAL_CAPACITY;
    itemCount = 0;
    str = new char[capacity + 1];
    str[0] = '\0';

}

CharacterArray::CharacterArray(char* inStr, int length){

    capacity = length;
    itemCount = 0;
    str = new char[capacity + 1];

    for(int i = 0; i < length; ++i){
        str[i] = inStr[i];
        itemCount++;
    }

    str[capacity] = '\0';

}

CharacterArray::~CharacterArray(){

    delete [] str;

}

void CharacterArray::resizeArray(){

    capacity *= 2;
    char* tempArray = new char[capacity + 1];

    for(int i = 0; i < itemCount; ++i){
        tempArray[i] = str[i];
    }

    delete [] str;
    str = tempArray;

}

void CharacterArray::append(char c){

    if(isEmpty()){
        str[itemCount] = c;
        str[itemCount + 1] = '\0';
    }else{
        if((itemCount + 1) > capacity){
            resizeArray();
        }
        str[itemCount] = c;
        str[itemCount + 1] = '\0';
    }

    itemCount++;

}

void CharacterArray::insert(char c, int index){

    if(index < 0 || index > itemCount){
        throw IndexOutOfBoundsException();
    }

    if(itemCount + 1 > capacity){
        resizeArray();
    }

    for(int i = itemCount; i >= index; --i){
        str[i + 1] = str[i];
    }

    str[index] = c;

    itemCount++;

}

void CharacterArray::setAt(char c, int index){

    if(index < 0 || index >= itemCount){
        throw IndexOutOfBoundsException();
    }

    str[index] = c;

}

char CharacterArray::getAt(int index) const{

    if(index < 0 || index >= itemCount){
        throw IndexOutOfBoundsException();
    }

    return str[index];

}

char CharacterArray::pop_back(){

    if(isEmpty()){
        throw EmptyException();
    }

    char last = str[itemCount - 1];
    itemCount--;
    str[itemCount] = '\0';

    return last;

}

char CharacterArray::removeAt(int index){

    if(index < 0 || index >= itemCount){
        throw IndexOutOfBoundsException();
    }

    char returnChar = str[index];

    for(int i = index; i < itemCount; ++i){
        str[i] = str[i + 1];
    }

    itemCount--;

    return returnChar;

}

void CharacterArray::clear(){

    str[0] = '\0';
    itemCount = 0;

}

int CharacterArray::length() const{

    return itemCount;

}

bool CharacterArray::isEmpty(){

    if(str[0] == '\0'){
        return true;
    }

    return false;

}

char* CharacterArray::substring(int startIndex, int length){

    if(startIndex < 0 || startIndex > itemCount){
        throw IndexOutOfBoundsException();
    }

    if(length < 0 || startIndex + length > itemCount){
        throw IndexOutOfBoundsException();
    }

    char* sub = new char[length + 1];

    for(int i = startIndex; i < startIndex + length; ++i){
        sub[i - startIndex] = str[i];
    }

    sub[length] = '\0';

    return sub;

}

ostream& operator <<(ostream& out, const CharacterArray& ca) {

    for(int i = 0; i < ca.length(); ++i){
        out << ca.str[i];
    }

    return out;

}
