#include "characterarray.h"

CharacterArray::CharacterArray(){

    capacity = INITIAL_CAPACITY;
    itemCount = 0;
    str = new char[capacity];
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
    char* tempArray = new char[capacity];

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
        // Tok ut "=" merkid ((itemCount + 1) >= capacity)
        if((itemCount + 1) > capacity){
            resizeArray();
        }
        str[itemCount] = c;
        str[itemCount + 1] = '\0';
    }

    itemCount++;

}

void CharacterArray::insert(char c, int index){
    // setti inn "=" (index >= itemCount)
    if(index < 0 || index >= itemCount){
        throw IndexOutOfBoundsException();
    }

    if(itemCount + 1 >= capacity){
        resizeArray();
    }

    for(int i = itemCount + 1; i >= index; --i){
        str[i + 1] = str[i];
    }

    str[index] = c;

    itemCount++;

}

void CharacterArray::setAt(char c, int index){
    // Setti inn IndexOutOfBoundsException()
    if(index < 0 || index >= itemCount){
        throw IndexOutOfBoundsException();
    }
    
    str[index] = c;

    // if(index < capacity){
    //     str[index] = c;
    // }

}

char CharacterArray::getAt(int index) const{
    // setti inn "=" (index >= itemCount)
    if(index < 0 || index >= itemCount){
        throw IndexOutOfBoundsException();
    }

    return str[index];

    // if(index < capacity){
    //     return str[index];
    // }

}

char CharacterArray::popBack(){

    if(isEmpty()){
        throw EmptyException();
    }

    char last = str[itemCount - 1];
    itemCount--;
    str[itemCount] = '\0';

    return last;

}

char CharacterArray::removeAt(int index){
    // Setti inn IndexOutOfBoundsException()
    if(index < 0 || index >= itemCount){
        throw IndexOutOfBoundsException();
    }

    char returnChar = str[index];

    for(int i = index; i <= itemCount + 1; ++i){
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
    // setti inn "=" (index >= itemCount)
    if(startIndex < 0 || startIndex >= itemCount){                  //Baetti tessu inn
        throw IndexOutOfBoundsException();
    }

    if(length < 0 || startIndex + length > itemCount){                  //Baetti tessu inn   Kannski maetti taka adeins til i tessu spaghetti
        throw IndexOutOfBoundsException();
    }

    char* sub = new char[length];

    for(int i = startIndex; i < startIndex + length; ++i){
        sub[i - startIndex] = str[i];
    }

    sub[length] = '\0';

    return sub;

}

ostream& operator <<(ostream& out, const CharacterArray& ca) {

    int i = 0;
    while(true){
        if(ca.str[i] != '\0'){
            out << ca.str[i];
        }else if(ca.str[i] == '\0'){
            break;
        }
        i++;
    }

    return out;

}
