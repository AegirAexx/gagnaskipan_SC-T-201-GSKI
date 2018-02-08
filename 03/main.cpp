// #include <iostream>
#include "doublylinkedlist.h"

#include <string>
// using namespace std;

/* Unit test
template <typename T>

void insertToList(DoublyLinkedList<T> &lis, T &data){
    try{
        cout << "Insert at current position: " << lis.curr_pos() << endl;
        lis.insert(data);
    }catch(InvalidPositionException) {
        cout << "Caught InvalidPositionException" << endl;
    }
}
*/

int main(){

    cout << endl << "STRING_LIST" << endl << endl;

    DoublyLinkedList<string> stringList;

    stringList.append("111");
    stringList.append("222");
    stringList.append("333");
    stringList.append("444");
    stringList.append("555");
    stringList.append("666");
    stringList.append("777");
    stringList.append("888");



    cout << "current position" << endl;
    cout << stringList.curr_pos() << endl;

    cout << "current size is:" << endl;
    cout << stringList.length() << endl;



    cout << "current value is: " << stringList.get_value() << endl;

    cout << "clearing array" << endl;
    stringList.clear();

    cout << "appending some bullshit to array: " << endl;
    stringList.append("111b");

    cout << "current value is: " << stringList.get_value() << endl;


    try{
       stringList.prev();
       cout << stringList.curr_pos() << endl;
    }catch(InvalidPositionException) {
       cout << "Caught InvalidPositionException" << endl;
    }

    cout << "current position" << endl;
    cout << stringList.curr_pos() << endl;

    cout << "current size is:" << endl;
    cout << stringList.length() << endl;


    try{
       stringList.prev();
       cout << stringList.curr_pos() << endl;
    }catch(InvalidPositionException) {
       cout << "Caught InvalidPositionException" << endl;
    }


    try{
        cout << "moving to position 2" << endl;
        stringList.move_to_pos(2);
    }catch(InvalidPositionException) {
       cout << "Caught InvalidPositionException" << endl;
    }



    cout << "current position" << endl;
    cout << stringList.curr_pos() << endl;



    cout << stringList << endl;

    cout << "clearing array: " << endl;
    stringList.clear();

    cout << "current position" << endl;
    cout << stringList.curr_pos() << endl;

    cout << "current size is:" << endl;
    cout << stringList.length() << endl;


    stringList.insert("pod");

    cout << "current position" << endl;
    cout << stringList.curr_pos() << endl;

    cout << "current size is:" << endl;
    cout << stringList.length() << endl;
    cout << stringList << endl;

    try{
       stringList.prev();
       cout << stringList.curr_pos() << endl;
    }catch(InvalidPositionException) {
       cout << "Caught InvalidPositionException" << endl;
    }
    cout << "current position" << endl;
    cout << stringList.curr_pos() << endl;

    stringList.append("bxph");

    cout << "current position" << endl;
    cout << stringList.curr_pos() << endl;

    cout << "current size is:" << endl;
    cout << stringList.length() << endl;

    stringList.clear();

    cout << "current position" << endl;
    cout << stringList.curr_pos() << endl;

    cout << "current size is:" << endl;
    cout << stringList.length() << endl;

    cout << stringList << endl;

    try{
       stringList.prev();
       cout << stringList.curr_pos() << endl;
    }catch(InvalidPositionException) {
       cout << "Caught InvalidPositionException" << endl;
    }


    try{
       stringList.remove();
       cout << stringList << endl;
    }catch(InvalidPositionException) {
       cout << "Caught InvalidPositionException" << endl;
    }

    stringList.insert("111");
    stringList.insert("222");
    stringList.insert("333");
    stringList.insert("444");
    stringList.insert("555");
    stringList.insert("666");
    stringList.insert("777");
    stringList.insert("888");

    cout << "current position: " << stringList.curr_pos() << endl;
    cout << "moving to position ble: " << endl;
    stringList.move_to_pos(3);
    cout << "current position: " << stringList.curr_pos() << endl;

    try{
       cout << stringList.remove() << endl;
       cout << stringList << endl;
    }catch(InvalidPositionException) {
       cout << "Caught InvalidPositionException" << endl;
    }



    cout << stringList << endl;

    try{
       stringList.remove();
       cout << stringList << endl;
    }catch(InvalidPositionException) {
       cout << "Caught InvalidPositionException" << endl;
    }

    try{
       stringList.remove();
       cout << stringList << endl;
    }catch(InvalidPositionException) {
       cout << "Caught InvalidPositionException" << endl;
    }

    cout << stringList << endl;

    stringList.prev();

    cout << stringList << endl;

    stringList.insert("ah");

    cout << stringList << endl;

    stringList.next();

    cout << stringList << endl;

    stringList.next();

    cout << stringList << endl;

    stringList.prev();

    cout << stringList << endl;

    stringList.append("z");

    cout << stringList << endl;

    cout << endl << "INT_LIST" << endl << endl;

    cout << "initializing..." << endl;
    DoublyLinkedList<int> intList;
    cout << "initializing done...." << endl << endl;
    cout << "adding to the end 4" << endl;
    intList.append(4);
    cout << "item added" << endl;
    cout << "adding to the end 5" << endl;
    intList.append(5);
    cout << "item added" << endl;
    cout << "adding to the end 6" << endl;
    intList.append(6);
    cout << "item added" << endl;
    cout << "adding to the end 7" << endl;
    intList.append(7);
    cout << "item added" << endl;
    cout << "adding to the end 8" << endl;
    intList.append(8);
    cout << "item added" << endl;


    cout << "atempting to write to screen" << endl;
    intList.move_to_start();
    intList.insert(7);

    cout << intList << endl;

    return 0;
}




