#include <iostream>

#include "binarytree.h"
#include "dataclass.h"

using namespace std;

int main()
{
    BinaryTree MapBST;

    MapBST.insert('r', DataClass(7, "ragnar", 5.365));
    MapBST.insert('d', DataClass(6, "david", 57.365));
    MapBST.insert('g', DataClass(39, "gunnar", 7.365));
    MapBST.insert('a', DataClass(71, "agnar", 8.365));
    MapBST.insert('e', DataClass(62, "einar", 9.365));
    MapBST.insert('s', DataClass(5, "sigridur", 3.365));
    MapBST.insert('h', DataClass(3, "hanna", 4.365));
    MapBST.insert('a', DataClass(32, "alphonse", 5.365));
    MapBST.insert('f', DataClass(5, "finnur", 3.365));
    MapBST.insert('c', DataClass(3, "catrin", 4.365));
    MapBST.insert('b', DataClass(32, "bui", 5.365));

    if(MapBST.contains('a')) {
        cout << "INNIHELDUR" << endl;
        cout << "Stakid er " << MapBST.get('a') << endl;
    }
    else {
        cout << "EKKI" << endl;
    }

    cout << "Current tree: ";
    MapBST.printInorder();
    cout << endl;
    MapBST.printPreorder();
    cout << endl;


    cout << endl;

    cout << "remove s" << endl;
    MapBST.remove('s');
    cout << "Current tree: " << endl;
    MapBST.printInorder();
    cout << endl;

    cout << "remove a" << endl;
    MapBST.remove('a');
    cout << "Current tree: " << endl;;
    MapBST.printInorder();
    cout << endl;



    return 0;
}
