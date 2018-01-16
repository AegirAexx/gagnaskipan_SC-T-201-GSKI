#include "characterarray.h"

CharacterArray::CharacterArray(){
    
    capacity = INITIAL_CAPACITY;
    itemCount = 0;
    this->str = new char[capacity];
    str[capacity - 1] = '/0';

}

CharacterArray::CharacterArray(char* str, int length){
    
    capacity = length + 1;
    itemCount = length;
    this->str = new char[capacity];
    str[capacity - 1] = '/0';

}

CharacterArray::~CharacterArray(){

    delete [] str;

}

void CharacterArray::append(char c){

    if((itemCount - 1) >= capacity){
        //resize fall
            //k�pera � n�ja
            //ey�a gamla
    }

    if(isEmpty()){
        str[itemCount] = c;
        str[itemCount + 1] = '/0';
    }else{
        str[itemCount + 1] = c;
        str[itemCount + 2] = '/0';
    }

    itemCount++;

}

void CharacterArray::insert(char c, int index){

     if(itemCount - 1 >= capacity){ //Bua til bool fall til a� tekka hvort capacity se fullt
        //resize fall
            //k�pera � n�ja
            //ey�a gamla
    }

    for(int i = itemCount + 1; i >= index; i--){
        str[i + 1] = str[i];
    }

    itemCount++;

}

void CharacterArray::setAt(char c, int index){

    //Capacity check

    str[index] = c;

}

char CharacterArray::getAt(int index){

    //index out of bounds exception

    return str[index]; //change or remove this line

}

char CharacterArray::popBack(){

    //Example of throwing an exception
    if(isEmpty()){
        throw EmptyException();
    }

    char last = str[itemCount];

    str[itemCount] = '/0';
    itemCount--;

    return last; //change or remove this line

}

char CharacterArray::removeAt(int index){

    char returnChar = str[index];

    for(int i = index; i <= itemCount + 1; i++){
        str[i] = i + 1;
    }

    itemCount--;

    return returnChar; //change or remove this line

}

void CharacterArray::clear(){

    str[0] = '/0';
    itemCount = 0;

}

int CharacterArray::length(){

    return itemCount; //change or remove this line

}

bool CharacterArray::isEmpty(){

    if(str[0] == '/0'){
        return true;
    }else{
        return false;
    }

}

char* CharacterArray::substring(int startIndex, int length){

    char* sub = new char[length + 1];

    for(int i = startIndex; i < startIndex + length; i++){
        sub[i] = str[i];
    }

    sub[length + 1] = '/0';

    return sub;

}

ostream& operator <<(ostream& out, const CharacterArray& ca) {

    int i = 0;

    while(ca.str[i] != '/0'){
        out << ca.str[i] << " ";
        i++;
    }

    return out; //change or remove this line

}
