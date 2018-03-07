#include <iostream>
#include <string>

#include "bstmap.h"

using namespace std;

template <class K, class T>
void testInsert(Map<K, T> *map, K key, T data) {

    try {
        cout << "inserting: [" << key << ", " << data << "]" << endl;
        map->insert(key, data);
    }
    catch(ItemExistsException e) {
        cout << "caught ItemExistsException" << endl;
    }
    cout << endl;
}

template <class K, class T>
void testUpdate(Map<K, T> *map, K key, T data) {

    try {
        cout << "updating: [" << key << ", " << data << "]" << endl;
        map->update(key, data);
    }
    catch(NotFoundException e) {
        cout << "caught NotFoundException" << endl;
    }
    cout << endl;
}

template <class K, class T>
void testGet(Map<K, T> *map, K key) {

    try {
        cout << "getting: " << key << endl;
        T data = map->get(key);
        cout << "item: " << data << endl;
    }
    catch(NotFoundException e) {
        cout << "caught NotFoundException" << endl;
    }
    cout << endl;
}

template <class K, class T>
void testRemove(Map<K, T> *map, K key) {

    try {
        cout << "removing: " << key << endl;
        map->remove(key);
    }
    catch(NotFoundException e) {
        cout << "caught NotFoundException" << endl;
    }
    cout << endl;
}

template <class K, class T>
void testContains(Map<K, T> *map, K key) {

    if(map->contains(key)) {
        cout << "map does contain " << key << endl;
    }
    else {
        cout << "map does NOT contain " << key << endl;
    }
    cout << endl;
}

template <class K, class T>
void testSize(Map<K, T> *map) {

    cout << "size of map: " << map->size() << endl;
    cout << endl;
}

template <class K, class T>
void testEmpty(Map<K, T> *map) {

    if(map->empty()) {
        cout << "map is empty" << endl;
    }
    else {
        cout << "map is NOT empty" << endl;
    }
    cout << endl;
}

template <class K, class T>
void testClear(Map<K, T> *map) {

    cout << "clearing contents of map" << endl;
    map->clear();
    cout << endl;
}

template <class K, class T>
void printMap(Map<K, T> *map) {

    cout << "contents: " << *map << endl;
    cout << endl;
}


int main() {

    Map<char, string> *bstMap = new BSTMap<char, string>();

    testInsert(bstMap, 'd', (string)"item-d");
    testInsert(bstMap, 'b', (string)"item-b");
    testInsert(bstMap, 'f', (string)"item-f");
    testInsert(bstMap, 'g', (string)"item-g");
    testInsert(bstMap, 'e', (string)"item-e");
    testInsert(bstMap, 'c', (string)"item-c");

    printMap(bstMap);
    testSize(bstMap);

    testContains(bstMap, 'a');
    testContains(bstMap, 'b');

    testRemove(bstMap, 'b');
    testContains(bstMap, 'b');

    testEmpty(bstMap);

    printMap(bstMap);
    testSize(bstMap);

    testGet(bstMap, 'c');
    testGet(bstMap, 'f');
    testGet(bstMap, 'e');

    testUpdate(bstMap, 'f', (string)"item-f-updated");

    testGet(bstMap, 'c');
    testGet(bstMap, 'f');
    testGet(bstMap, 'e');

    printMap(bstMap);
    testSize(bstMap);

    testRemove(bstMap, 'c');
    testRemove(bstMap, 'a');
    testRemove(bstMap, 'f');

    testUpdate(bstMap, 'f', (string)"item-f-updated");

    testGet(bstMap, 'c');
    testGet(bstMap, 'f');
    testGet(bstMap, 'e');

    testRemove(bstMap, 'e');
    testRemove(bstMap, 'g');

    testEmpty(bstMap);

    printMap(bstMap);
    testSize(bstMap);

    testRemove(bstMap, 'd');
    testEmpty(bstMap);

    printMap(bstMap);
    testSize(bstMap);

    testInsert(bstMap, 'd', (string)"item-d");
    testInsert(bstMap, 'b', (string)"item-b");
    testInsert(bstMap, 'f', (string)"item-f");
    testInsert(bstMap, 'g', (string)"item-g");
    testInsert(bstMap, 'e', (string)"item-e");
    testInsert(bstMap, 'c', (string)"item-c");

    testEmpty(bstMap);
    printMap(bstMap);
    testSize(bstMap);

    testClear(bstMap);
    testEmpty(bstMap);
    printMap(bstMap);
    testSize(bstMap);

    delete bstMap;
    bstMap = nullptr;


    ///dagur17 og aegir15 test

    Map<int, int> *bstMap2 = new BSTMap<int, int>();

    testInsert(bstMap2, 3, (int)3);
    testInsert(bstMap2, 1, (int)1);
    testInsert(bstMap2, 2, (int)2);
    testInsert(bstMap2, 4, (int)4);
    testInsert(bstMap2, 5, (int)5);
    testInsert(bstMap2, 9, (int)9);
    testInsert(bstMap2, 2, (int)2);
    testInsert(bstMap2, 4, (int)4);
    testInsert(bstMap2, 5, (int)5);
    testInsert(bstMap2, 9, (int)9);

    printMap(bstMap2);
    testSize(bstMap2);

    testContains(bstMap2, 9);
    testContains(bstMap2, 7);

    testGet(bstMap2, 9);
    testContains(bstMap2, 9);
    testRemove(bstMap2, 9); //
    testContains(bstMap2, 10);
    testEmpty(bstMap2);

    printMap(bstMap2);
    testSize(bstMap2);

    testGet(bstMap2, 4);
    testGet(bstMap2, 2);
    testGet(bstMap2, 9);

    testUpdate(bstMap2, 2, (int)666);

    testGet(bstMap2, 2);
    testGet(bstMap2, 9);
    testGet(bstMap2, 23);

    printMap(bstMap2);
    testSize(bstMap2);

    testRemove(bstMap2, 9);
    testRemove(bstMap2, 2);
    testRemove(bstMap2, 103);

    testUpdate(bstMap2, 4, (int)376);

    testGet(bstMap2, 399);
    testGet(bstMap2, 512);
    testGet(bstMap2, 12);

    testRemove(bstMap2, 9);
    testRemove(bstMap2, 2);
    testRemove(bstMap2, 103);

    testClear(bstMap2);

    testRemove(bstMap2, 9);
    testRemove(bstMap2, 2);
    testRemove(bstMap2, 103);

    testInsert(bstMap2, 9, (int)9);

    testRemove(bstMap2, 2);
    testRemove(bstMap2, 1);

    testEmpty(bstMap2);

    printMap(bstMap2);
    testSize(bstMap2);

    testRemove(bstMap2, 2);
    testEmpty(bstMap2);

    printMap(bstMap2);
    testSize(bstMap2);

    testInsert(bstMap2, 3, (int)1);
    testInsert(bstMap2, 1, (int)3);
    testInsert(bstMap2, 2, (int)2);
    testInsert(bstMap2, 4, (int)4);
    testInsert(bstMap2, 5, (int)5);
    testInsert(bstMap2, 9, (int)9);
    testInsert(bstMap2, 2, (int)2);
    testInsert(bstMap2, 4, (int)4);
    testInsert(bstMap2, 5, (int)5);
    testInsert(bstMap2, 9, (int)9);


    testEmpty(bstMap2);
    printMap(bstMap2);
    testSize(bstMap2);

    testClear(bstMap2);
    testEmpty(bstMap2);
    printMap(bstMap2);
    testSize(bstMap2);

    delete bstMap2;
    bstMap2 = nullptr;


    Map<int, string> *bstMap3 = new BSTMap<int, string>();

    testInsert(bstMap3, 3, (string)"Three");
    testInsert(bstMap3, 1, (string)"One");
    testInsert(bstMap3, 2, (string)"Two");
    testInsert(bstMap3, 4, (string)"Four");
    testInsert(bstMap3, 5, (string)"Five");
    testInsert(bstMap3, 9, (string)"Nine");
    testInsert(bstMap3, 2, (string)"Two");
    testInsert(bstMap3, 4, (string)"Four");
    testInsert(bstMap3, 5, (string)"Five");
    testInsert(bstMap3, 9, (string)"Nine");
    testInsert(bstMap3, 6, (string)"Six");
    testInsert(bstMap3, 7, (string)"Seven");
    testInsert(bstMap3, 8, (string)"Eight");
    testInsert(bstMap3, 10, (string)"Ten");
    testInsert(bstMap3, 0, (string)"NULL");
    testInsert(bstMap3, -1, (string)"Minus");

    printMap(bstMap3);

    testUpdate(bstMap3, 4, (string)"four-updated");
    testUpdate(bstMap3, 12, (string)"four updated");

    printMap(bstMap3);

    testGet(bstMap3, 6);
    testGet(bstMap3, -100);

    testGet(bstMap3, 6);

    testRemove(bstMap3, 0);
    printMap(bstMap3);
    testRemove(bstMap3, 0);
    printMap(bstMap3);
    testRemove(bstMap3, 3);
    printMap(bstMap3);
    testRemove(bstMap3, 4);
    printMap(bstMap3);
    testRemove(bstMap3, 5);
    printMap(bstMap3);
    testRemove(bstMap3, 6);
    printMap(bstMap3);
    testRemove(bstMap3, 7);
    printMap(bstMap3);
    testRemove(bstMap3, 8);
    printMap(bstMap3);
    testRemove(bstMap3, 9);
    printMap(bstMap3);
    testRemove(bstMap3, 10);
    printMap(bstMap3);
    testRemove(bstMap3, 11);
    printMap(bstMap3);
    testRemove(bstMap3, 9);

    printMap(bstMap3);

    testClear(bstMap3);
    testRemove(bstMap3, 9);

    testEmpty(bstMap3);

    testInsert(bstMap3, 4, (string)"Four");
    testRemove(bstMap3, 9);
    testRemove(bstMap3, 4);

    testContains(bstMap3, 9);
    testContains(bstMap3, 7);

    testClear(bstMap3);
    testEmpty(bstMap3);

    delete bstMap3;
    bstMap3 = nullptr;


    /// Error feedback test

    Map<int, char> *bstMap4 = new BSTMap<int, char>();

    //Error line 572  //Villa fannst í parameter sem var ad koma inn í find fallid
    testClear(bstMap4);

    testSize(bstMap4);
    testInsert(bstMap4, -92, 'p');
    testUpdate(bstMap4, -77, 'a');
    testSize(bstMap4);
    testInsert(bstMap4, -94, 'm');
    testSize(bstMap4);
    testGet(bstMap4, 182);
    testEmpty(bstMap4);
    testUpdate(bstMap4, 156, 'k');
    testInsert(bstMap4, -73, 'i');
    testInsert(bstMap4, 33, 'c');
    testInsert(bstMap4, -65, 'h');
    testGet(bstMap4, 164);

    //Error line 874 //Sama villan og ad ofan, i find fallinu
    testClear(bstMap4);

    testSize(bstMap4);
    testSize(bstMap4);
    testRemove(bstMap4, 49);
    testInsert(bstMap4, 114, 'f');
    testInsert(bstMap4, 150, 'f');
    testInsert(bstMap4, 37, 'f');
    testRemove(bstMap4, 150);

    //Error line 1531 //Sama villan og ad ofan, i find fallinu
    testClear(bstMap4);

    testInsert(bstMap4, 163, 'a');
    testRemove(bstMap4, -72);
    testRemove(bstMap4, 187);
    testRemove(bstMap4, -54);
    testInsert(bstMap4, 163, 'f');

    //Error line 1606 //Sama villan og ad ofan, i find fallinu
    testClear(bstMap4);

    testSize(bstMap4);
    testSize(bstMap4);
    testEmpty(bstMap4);
    testInsert(bstMap4, 198, 'a');
    testRemove(bstMap4, -3);
    testUpdate(bstMap4, -67, 'e');
    testRemove(bstMap4, 160);
    testRemove(bstMap4, 198);
    testEmpty(bstMap4);

    //Error line 1717 - 1722 //Sama villan og ad ofan, i find fallinu
    testClear(bstMap4);

    testInsert(bstMap4, 150, 'f');
    testUpdate(bstMap4, 150, 'l');
    testGet(bstMap4, -20);
    testUpdate(bstMap4, 150, 'o');
    testUpdate(bstMap4, -8, 'z');
    testGet(bstMap4, 150);

    return 0;
}
