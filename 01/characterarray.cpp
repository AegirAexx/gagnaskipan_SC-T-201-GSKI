#include "characterarray.h"

CharacterArray::CharacterArray(){
    
    capacity = INITIAL_CAPACITY;
    itemCount = 0;
    str = new char[capacity];
    str[capacity - 1] = 48;

}

CharacterArray::CharacterArray(char* inStr, int length){
    
    capacity = length;
    itemCount = 0;
    str = new char[capacity];

    for(int i = 0; i < length; ++i){
        str[i] = inStr[i];
    }

    str[capacity] = 48;

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

    if((itemCount - 1) >= capacity){
        resizeArray();
    }

    if(isEmpty()){
        str[itemCount] = c;
        str[itemCount + 1] = 48;
    }else{
        str[itemCount + 1] = c;
        str[itemCount + 2] = 48;
    }

    itemCount++;

}

void CharacterArray::insert(char c, int index){

     if(itemCount - 1 >= capacity){ //Bua til bool fall til a� tekka hvort capacity se fullt
        resizeArray();
    }

    for(int i = itemCount + 1; i >= index; --i){
        str[i + 1] = str[i];
    }

    itemCount++;

}

void CharacterArray::setAt(char c, int index){

    //Capacity check

    str[index] = c;

}

char CharacterArray::getAt(int index) const{

    //index out of bounds exception

    return str[index]; 

}

char CharacterArray::popBack(){

    //Example of throwing an exception
    if(isEmpty()){
        throw EmptyException();
    }

    char last = str[itemCount];

    str[itemCount] = 48;
    itemCount--;

    return last; 

}

char CharacterArray::removeAt(int index){

    char returnChar = str[index];

    for(int i = index; i <= itemCount + 1; ++i){
        str[i] = i + 1;
    }

    itemCount--;

    return returnChar; 

}

void CharacterArray::clear(){

    str[0] = 48;
    itemCount = 0;

}

int CharacterArray::length() const{

    return itemCount; 

}

bool CharacterArray::isEmpty(){

    if(str[0] == 48){
        return true;
    }else{
        return false;
    }

}

char* CharacterArray::substring(int startIndex, int length){

    char* sub = new char[length + 1];

    for(int i = startIndex; i < startIndex + length; ++i){
        sub[i] = str[i];
    }

    sub[length + 1] = 48;

    return sub;

}

ostream& operator <<(ostream& out, const CharacterArray& ca) {

    // for(int i = 0; i < ca.length() + 5; ++i){
    //     if(ca.str[i] != 48){
    //         out << ca.str[i] << " ";
    //     }else if(ca.str[i] == 48){
    //         break;
    //     }
    // }
    int i = 0;
    while(true){
        if(ca.str[i] != 48){
            out << ca.str[i];
        }else if(ca.str[i] == 48){
            break;
        }
        i++;
    }

    return out;

}
