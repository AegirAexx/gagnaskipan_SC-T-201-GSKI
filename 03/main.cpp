#include "doublylinkedlist.h"
#include <string>

int main(){

    cout << endl << "STRING_LIST" << endl << endl;

    DoublyLinkedList<string> stringList;

    // Append to list
    cout << "Appending to the list" << endl;
    stringList.append("111");
    stringList.append("222");
    stringList.append("333");
    stringList.append("444");
    stringList.append("555");
    stringList.append("666");
    stringList.append("777");
    stringList.append("888");
    cout << "Appended to the list: " << stringList << endl << endl;

    // Print out the current position
    cout << "Current position: " << stringList.curr_pos() << endl;

    // Print out the current size of the list
    cout << "Current list size is: " << stringList.length() << endl;

    try {
        // Print out the current value
        cout << "Current value is: " << stringList.get_value() << endl << endl;
    }
    catch(InvalidPositionException) {
        cout << "Caught InvalidPositionException - GET VALUE" << endl << endl;
    }

    for (int i = 0; i < stringList.length() + 1; ++i) {
        // Move current position one back
        try {
            cout << "Position before (prev): " << stringList.curr_pos() << endl;
            stringList.prev();
            cout << "Current position: " << stringList.curr_pos() << endl << endl;
        }
        catch(InvalidPositionException) {
            cout << "Caught InvalidPositionException - PREV" << endl << endl;
        }
    }

    // Print out the current position
    cout << "Current position: " << stringList.curr_pos() << endl;

    // Print out the current size of the list
    cout << "Current list size is: " << stringList.length() << endl;

    try {
        // Print out the current value
        cout << "Current value is: " << stringList.get_value() << endl << endl;
    }
    catch(InvalidPositionException) {
        cout << "Caught InvalidPositionException - GET VALUE" << endl << endl;
    }

    for (int i = 0; i < stringList.length() + 1; ++i) {
        // Move current position one forward
        try {
            cout << "Position before (next): " << stringList.curr_pos() << endl;
            stringList.next();
            cout << "Current position: " << stringList.curr_pos() << endl << endl;
        }
        catch(InvalidPositionException) {
            cout << "Caught InvalidPositionException - NEXT" << endl << endl;
        }
    }

    // Print out the current position
    cout << "Current position: " << stringList.curr_pos() << endl;

    // Print out the current size of the list
    cout << "Current list size is: " << stringList.length() << endl;

    try {
        // Print out the current value
        cout << "Current value is: " << stringList.get_value() << endl << endl;
    }
    catch(InvalidPositionException) {
        cout << "Caught InvalidPositionException - GET VALUE" << endl << endl;
    }

    // Clear the list
    cout << "Clearing list" << endl << endl;
    stringList.clear();

    // Print out the current position
    cout << "Current position: " << stringList.curr_pos() << endl;

    // Print out the current size of the list
    cout << "Current list size is: " << stringList.length() << endl;

    try {
        // Print out the current value
        cout << "Current value is: " << stringList.get_value() << endl << endl;
    }
    catch(InvalidPositionException) {
        cout << "Caught InvalidPositionException - GET VALUE" << endl << endl;
    }

    // Insert to the list
    cout << "Inserting to the list" << endl;
    stringList.insert("aaa");
    stringList.insert("bbb");
    stringList.insert("ccc");
    stringList.insert("ddd");
    stringList.insert("eee");
    stringList.insert("fff");
    stringList.insert("ggg");
    stringList.insert("hhh");
    cout << "Inserted to the list: " << stringList << endl << endl;

    for (int i = 0; i < stringList.length() + 1; ++i) {
        // Move current position one back
        try {
            cout << "Position before (prev): " << stringList.curr_pos() << endl;
            stringList.prev();
            cout << "Current position: " << stringList.curr_pos() << endl << endl;
        }
        catch(InvalidPositionException) {
            cout << "Caught InvalidPositionException - PREV" << endl << endl;
        }
    }

    // Print out the current position
    cout << "Current position: " << stringList.curr_pos() << endl;

    // Print out the current size of the list
    cout << "Current list size is: " << stringList.length() << endl;

    try {
        // Print out the current value
        cout << "Current value is: " << stringList.get_value() << endl << endl;
    }
    catch(InvalidPositionException) {
        cout << "Caught InvalidPositionException - GET VALUE" << endl << endl;
    }

    for (int i = 0; i < stringList.length() + 1; ++i) {
        // Move current position one forward
        try {
            cout << "Position before (next): " << stringList.curr_pos() << endl;
            stringList.next();
            cout << "Current position: " << stringList.curr_pos() << endl << endl;
        }
        catch(InvalidPositionException) {
            cout << "Caught InvalidPositionException - NEXT" << endl << endl;
        }
    }

    // Print out the current position
    cout << "Current position: " << stringList.curr_pos() << endl;

    // Print out the current size of the list
    cout << "Current list size is: " << stringList.length() << endl;

    try {
        // Print out the current value
        cout << "Current value is: " << stringList.get_value() << endl << endl;
    }
    catch(InvalidPositionException) {
        cout << "Caught InvalidPositionException - GET VALUE" << endl << endl;
    }

     for (int i = 0; i < stringList.length() + 1; ++i) {
        // Move current position one back
        try {
            cout << "Position before (prev): " << stringList.curr_pos() << endl;
            stringList.prev();
            cout << "Current position: " << stringList.curr_pos() << endl << endl;
        }
        catch(InvalidPositionException) {
            cout << "Caught InvalidPositionException - PREV" << endl << endl;
        }
    }

    for (int i = 0; i < 10; ++i) {
        // Remove a item form the list
        try {
            cout << "Item removed from list: " << stringList.remove() << endl << endl;
        }
        catch(InvalidPositionException) {
            cout << "Caught InvalidPositionException - REMOVE" << endl << endl;
        }
        // Print out the current position
        cout << "Current position: " << stringList.curr_pos() << endl;

        // Print out the current size of the list
        cout << "Current list size is: " << stringList.length() << endl;

        try {
            // Print out the current value
            cout << "Current value is: " << stringList.get_value() << endl << endl;
        }
        catch(InvalidPositionException) {
            cout << "Caught InvalidPositionException - GET VALUE" << endl << endl;
        }

    }
/*
    // Append to list
    cout << "Appending and Inserting to the list" << endl;
    stringList.append("111");
    stringList.insert("222");
    stringList.append("333");
    stringList.insert("444");
    stringList.append("555");
    stringList.insert("666");
    stringList.append("777");
    stringList.insert("888");
    cout << "Appended and Inserted to the list: " << stringList << endl << endl;

    // Print out the current position
    cout << "Current position: " << stringList.curr_pos() << endl;

    // Print out the current size of the list
    cout << "Current list size is: " << stringList.length() << endl;

    try {
        // Print out the current value
        cout << "Current value is: " << stringList.get_value() << endl << endl;
    }
    catch(InvalidPositionException) {
        cout << "Caught InvalidPositionException - GET VALUE" << endl << endl;
    }

    // Moving to a different place
    try {
        cout << "Moving to position 0" << endl;
        stringList.move_to_pos(0);
        cout << "Current position: " << stringList.curr_pos() << endl;
        try {
            // Print out the current value
            cout << "Current value is: " << stringList.get_value() << endl << endl;
        }
        catch(InvalidPositionException) {
            cout << "Caught InvalidPositionException - GET VALUE" << endl << endl;
        }
    }
    catch(InvalidPositionException) {
        cout << "Caught InvalidPositionException" << endl << endl;
    }

    // Moving to a different place
    try {
        cout << "Moving to position 7" << endl;
        stringList.move_to_pos(7);
        cout << "Current position: " << stringList.curr_pos() << endl;
        try {
            // Print out the current value
            cout << "Current value is: " << stringList.get_value() << endl << endl;
        }
        catch(InvalidPositionException) {
            cout << "Caught InvalidPositionException - GET VALUE" << endl << endl;
        }
    }
    catch(InvalidPositionException) {
        cout << "Caught InvalidPositionException" << endl << endl;
    }

    // Moving to a different place
    try {
        cout << "Moving to position 10" << endl;
        stringList.move_to_pos(10);
        cout << "Current position: " << stringList.curr_pos() << endl;
        try {
            // Print out the current value
            cout << "Current value is: " << stringList.get_value() << endl << endl;
        }
        catch(InvalidPositionException) {
            cout << "Caught InvalidPositionException - GET VALUE" << endl << endl;
        }
    }
    catch(InvalidPositionException) {
        cout << "Caught InvalidPositionException" << endl << endl;
    }

    // Moving to a different place
    try {
        cout << "Moving to position 8" << endl;
        stringList.move_to_pos(8);
        cout << "Current position: " << stringList.curr_pos() << endl;
        try {
            // Print out the current value
            cout << "Current value is: " << stringList.get_value() << endl << endl;
        }
        catch(InvalidPositionException) {
            cout << "Caught InvalidPositionException - GET VALUE" << endl << endl;
        }
    }
    catch(InvalidPositionException) {
        cout << "Caught InvalidPositionException" << endl << endl;
    }

    // Moving to a different place
    try {
        cout << "Moving to position -1" << endl;
        stringList.move_to_pos(-1);
        cout << "Current position: " << stringList.curr_pos() << endl;
        try {
            // Print out the current value
            cout << "Current value is: " << stringList.get_value() << endl << endl;
        }
        catch(InvalidPositionException) {
            cout << "Caught InvalidPositionException - GET VALUE" << endl << endl;
        }
    }
    catch(InvalidPositionException) {
        cout << "Caught InvalidPositionException" << endl << endl;
    }

    // Moving to either end og the list
    cout << "Moving to the end" << endl;
    stringList.move_to_end();
    cout << "Current position: " << stringList.curr_pos() << endl;
    try {
        // Print out the current value
        cout << "Current value is: " << stringList.get_value() << endl << endl;
    }
    catch(InvalidPositionException) {
        cout << "Caught InvalidPositionException - GET VALUE" << endl << endl;
    }
    cout << "Current list size is: " << stringList.length() << endl << endl;

    cout << "Moving to the start" << endl;
    stringList.move_to_start();
    cout << "Current position: " << stringList.curr_pos() << endl;
    try {
        // Print out the current value
        cout << "Current value is: " << stringList.get_value() << endl << endl;
    }
    catch(InvalidPositionException) {
        cout << "Caught InvalidPositionException - GET VALUE" << endl << endl;
    }
    cout << "Current list size is: " << stringList.length() << endl << endl;
*/
    return 0;
}




