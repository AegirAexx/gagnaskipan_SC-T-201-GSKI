#include <iostream>
#include "doublylinkedlist.h"

using namespace std;

int main(){

    cout << endl << "STRING_LIST" << endl << endl;

    DoublyLinkedList<string> stringList;

    stringList.append("fic");
    stringList.append("sdf");
    stringList.append("wet");
    stringList.append("fgh");
    
    
    cout << "current position" << endl;
    cout << stringList.curr_pos() << endl;

    cout << "current size is:" << endl;
    cout << stringList.length() << endl;

    cout << "moving to position 2" << endl;
    stringList.move_to_pos(2);

    cout << "current position" << endl;
    cout << stringList.curr_pos() << endl;

    
    
    cout << stringList << endl;
    
    // stringList.clear();
    // stringList.insert("pod");
    
    // cout << stringList << endl;
    
    // stringList.prev();
    // stringList.append("bxph");
    
    // cout << stringList << endl;
    
    // stringList.next();
    
    // cout << stringList << endl;
    
    // try{
    //     stringList.remove();
    //     cout << stringList << endl;
    // }catch(InvalidPositionException) {
    //     cout << "Caught InvalidPositionException" << endl;
    // }

    // try{
    //     stringList.remove();
    //     cout << stringList << endl;
    // }catch(InvalidPositionException) {
    //     cout << "Caught InvalidPositionException" << endl;
    // }

    // cout << stringList << endl;
    
    // stringList.prev();

    // cout << stringList << endl;
    
    // stringList.insert("ah");

    // cout << stringList << endl;

    // stringList.next();
    
    // cout << stringList << endl;
    
    // stringList.next();

    // cout << stringList << endl;
    
    // stringList.prev();

    // cout << stringList << endl;
    
    // stringList.append("z");
    
    // cout << stringList << endl;

    // cout << endl << "INT_LIST" << endl << endl;

    // cout << "initializing..." << endl;
    // DoublyLinkedList<int> intList;
    // cout << "initializing done...." << endl << endl;
    // cout << "adding to the end 4" << endl;
    // intList.append(4);
    // cout << "item added" << endl;
    // cout << "adding to the end 5" << endl;
    // intList.append(5);
    // cout << "item added" << endl;
    // cout << "adding to the end 6" << endl;
    // intList.append(6);
    // cout << "item added" << endl;
    // cout << "adding to the end 7" << endl;
    // intList.append(7);
    // cout << "item added" << endl;
    // cout << "adding to the end 8" << endl;
    // intList.append(8);
    // cout << "item added" << endl;


    // cout << "atempting to write to screen" << endl;
    // intList.move_to_start();
    // intList.insert(7);
    
    // cout << intList << endl;

    return 0;
}

