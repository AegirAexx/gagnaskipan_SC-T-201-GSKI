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
/*
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
    bstMap = NULL;
*/

    ///RB hackers test below
/*
    Map<int, int> *bstMap = new BSTMap<int, int>();

    testInsert(bstMap, 3, (int)3);
    testInsert(bstMap, 1, (int)1);
    testInsert(bstMap, 2, (int)2);
    testInsert(bstMap, 4, (int)4);
    testInsert(bstMap, 5, (int)5);
    testInsert(bstMap, 9, (int)9);
    testInsert(bstMap, 2, (int)2);
    testInsert(bstMap, 4, (int)4);
    testInsert(bstMap, 5, (int)5);
    testInsert(bstMap, 9, (int)9);

    printMap(bstMap);
    testSize(bstMap);

    testContains(bstMap, 9);
    testContains(bstMap, 7);

    testGet(bstMap, 9);
    testContains(bstMap, 9);
    testRemove(bstMap, 9); //
    testContains(bstMap, 10);
    testEmpty(bstMap);

    printMap(bstMap);
    testSize(bstMap);

    testGet(bstMap, 4);
    testGet(bstMap, 2);
    testGet(bstMap, 9);

    testUpdate(bstMap, 2, (int)666);

    testGet(bstMap, 2);
    testGet(bstMap, 9);
    testGet(bstMap, 23);

    printMap(bstMap);
    testSize(bstMap);

    testRemove(bstMap, 9);
    testRemove(bstMap, 2);
    testRemove(bstMap, 103);

    testUpdate(bstMap, 4, (int)376);

    testGet(bstMap, 399);
    testGet(bstMap, 512);
    testGet(bstMap, 12);

    testRemove(bstMap, 9);
    testRemove(bstMap, 2);
    testRemove(bstMap, 103);

    testClear(bstMap);

    testRemove(bstMap, 9);
    testRemove(bstMap, 2);
    testRemove(bstMap, 103);

    testInsert(bstMap, 9, (int)9);

    testRemove(bstMap, 2);
    testRemove(bstMap, 1);

    testEmpty(bstMap);

    printMap(bstMap);
    testSize(bstMap);

    testRemove(bstMap, 2);
    testEmpty(bstMap);

    printMap(bstMap);
    testSize(bstMap);

    testInsert(bstMap, 3, (int)1);
    testInsert(bstMap, 1, (int)3);
    testInsert(bstMap, 2, (int)2);
    testInsert(bstMap, 4, (int)4);
    testInsert(bstMap, 5, (int)5);
    testInsert(bstMap, 9, (int)9);
    testInsert(bstMap, 2, (int)2);
    testInsert(bstMap, 4, (int)4);
    testInsert(bstMap, 5, (int)5);
    testInsert(bstMap, 9, (int)9);


    testEmpty(bstMap);
    printMap(bstMap);
    testSize(bstMap);

    testClear(bstMap);
    testEmpty(bstMap);
    printMap(bstMap);
    testSize(bstMap);

    delete bstMap;
    bstMap = NULL;
*/

    Map<int, string> *bstMap = new BSTMap<int, string>();

    testInsert(bstMap, 3, (string)"Three");
    testInsert(bstMap, 1, (string)"One");
    testInsert(bstMap, 2, (string)"Two");
    testInsert(bstMap, 4, (string)"Four");
    testInsert(bstMap, 5, (string)"Five");
    testInsert(bstMap, 9, (string)"Nine");
    testInsert(bstMap, 2, (string)"Two");
    testInsert(bstMap, 4, (string)"Four");
    testInsert(bstMap, 5, (string)"Five");
    testInsert(bstMap, 9, (string)"Nine");
    testInsert(bstMap, 6, (string)"Six");
    testInsert(bstMap, 7, (string)"Seven");
    testInsert(bstMap, 8, (string)"Eight");
    testInsert(bstMap, 10, (string)"Ten");
    testInsert(bstMap, 0, (string)"NULL");
    testInsert(bstMap, -1, (string)"Minus");

    printMap(bstMap);

    testUpdate(bstMap, 4, (string)"four-updated");
    testUpdate(bstMap, 12, (string)"four updated");

    printMap(bstMap);

    testGet(bstMap, 6);
    testGet(bstMap, -100);

    testGet(bstMap, 6);

    testRemove(bstMap, 0);
    printMap(bstMap);
    testRemove(bstMap, 0);
    printMap(bstMap);
    testRemove(bstMap, 3);
    printMap(bstMap);
    testRemove(bstMap, 4);
    printMap(bstMap);
    testRemove(bstMap, 5);
    printMap(bstMap);
    testRemove(bstMap, 6);
    printMap(bstMap);
    testRemove(bstMap, 7);
    printMap(bstMap);
    testRemove(bstMap, 8);
    printMap(bstMap);
    testRemove(bstMap, 9);
    printMap(bstMap);
    testRemove(bstMap, 10);
    printMap(bstMap);
    testRemove(bstMap, 11);
    printMap(bstMap);
    testRemove(bstMap, 9);

    printMap(bstMap);

    testClear(bstMap);
    testRemove(bstMap, 9);

    testEmpty(bstMap);

    testInsert(bstMap, 4, (string)"Four");
    testRemove(bstMap, 9);
    testRemove(bstMap, 4);

    testContains(bstMap, 9);
    testContains(bstMap, 7);

    testClear(bstMap);
    testEmpty(bstMap);

}
