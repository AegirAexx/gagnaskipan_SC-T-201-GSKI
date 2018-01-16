#include "characterarray.h"

CharacterArray::CharacterArray(){

    capacity = INITIAL_CAPACITY;
    itemCount = 0;
    str = new char[capacity];
    str[0] = '\0';  //Breytti tessu ur str[capacity - 1]

}

CharacterArray::CharacterArray(char* inStr, int length){

    capacity = length + 1;  //Breytti her i length + 1, er tad ekki rett??
    itemCount = 0;
    str = new char[capacity];

    for(int i = 0; i < length; ++i){
        str[i] = inStr[i];
        itemCount++;
    }

    str[capacity - 1] = '\0';  //Breytti her i capacity - 1

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

        if((itemCount + 1) >= capacity){  //Er forsendan fyrir tvi ad nota resize fallid ekki eitthvad vitlaus hja okkur? //breytti ur itemCount - 1 yfir i itemCount + 1... er tad ekki rett hugsad??
        resizeArray();
        }
        str[itemCount] = c;
        str[itemCount + 1] = '\0';    //breytti her (var + 1 og + 2)
    }

    itemCount++;

}

void CharacterArray::insert(char c, int index){

    if(index < 0 || index > itemCount){                  //Baetti tessu inn
        throw IndexOutOfBoundsException();
    }

    if(itemCount + 1 >= capacity){  //breytti ur itemCount - 1 yfir i itemCount + 1... er tad ekki rett hugsad??
        resizeArray();
    }

    for(int i = itemCount + 1; i >= index; --i){
        str[i + 1] = str[i];
    }

    str[index] = c;

    itemCount++;

}

void CharacterArray::setAt(char c, int index){

    if(index < capacity){
        str[index] = c;
    }

}

char CharacterArray::getAt(int index) const{

    if(index < 0 || index > itemCount){                  //Baetti tessu inn
        throw IndexOutOfBoundsException();
    }

    if(index < capacity){
        return str[index];
    }

}

char CharacterArray::popBack(){

    //Example of throwing an exception
    if(isEmpty()){
        throw EmptyException();
    }

    char last = str[itemCount - 1];
    itemCount--;
    str[itemCount] = '\0';

    return last;

}

char CharacterArray::removeAt(int index){

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
    }else{
        return false;
    }

}

char* CharacterArray::substring(int startIndex, int length){

    if(startIndex < 0 || startIndex > itemCount){                  //Baetti tessu inn
        throw IndexOutOfBoundsException();
    }

    if(length < 0 || startIndex + length > itemCount){                  //Baetti tessu inn   Kannski maetti taka adeins til i tessu spaghetti
        throw IndexOutOfBoundsException();
    }

    char* sub = new char[length + 1];

    for(int i = startIndex; i < startIndex + length; ++i){
        sub[i - startIndex] = str[i];
    }

    sub[length + 1] = '\0';

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
