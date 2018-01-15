#include "characterarray.h"

CharacterArray::CharacterArray()
{
    capacity = INITIAL_CAPACITY;

    item_count = 0;
    str = new char[capacity];
    str[capacity - 1] = '/0';
}

CharacterArray::CharacterArray(char* str, int length)
{
    capacity = length + 1;
    item_count = length;
    this->str = new char[capacity];
    str[capacity - 1] = '/0';

}



CharacterArray::~CharacterArray()
{
    delete [] str;
}

void CharacterArray::append(char c) {

    if(item_count - 1 >= capacity){
        //resize fall
            //kópera í nýja
            //eyða gamla
    }

    if(isEmpty()){
        str[item_count] = c;
        str[item_count + 1] = '/0';
    }
    else{
        str[item_count + 1] = c;
        str[item_count + 2] = '/0';
    }
    item_count++;
}

void CharacterArray::insert(char c, int index) {

     if(item_count - 1 >= capacity){ //Bua til bool fall til að tekka hvort capacity se fullt
        //resize fall
            //kópera í nýja
            //eyða gamla
    }

    for(int i = item_count + 1; i >= index; i--){
        str[i + 1] = str[i];
    }
    item_count++;

}

void CharacterArray::setAt(char c, int index) {

    //Capacity check

    str[index] = c;

}

char CharacterArray::getAt(int index) {

    //index out of bounds exception

    return str[index]; //change or remove this line
}

char CharacterArray::pop_back() {

    //Example of throwing an exception
    if(isEmpty()) {
        throw EmptyException();
    }

    char last = str[item_count];

    str[item_count] = '/0';
    item_count--;

    return last; //change or remove this line
}

char CharacterArray::removeAt(int index) {

    char returnChar = str[index];

    for(int i = index; i <= item_count + 1; i++){
        str[i] = i + 1;
    }
    item_count--;

    return returnChar; //change or remove this line
}

void CharacterArray::clear() {

    str[0] = '/0';
    item_count = 0;
}

int CharacterArray::length() {

    return item_count; //change or remove this line
}

bool CharacterArray::isEmpty() {

    if(str[0] == '/0'){
        return true;
    }
    else{
        return false;
    }
}

char* CharacterArray::substring(int startIndex, int length) {


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
