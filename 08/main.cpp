#include <iostream>
#include <string>

#include "hashmap.h"
#include "hashfunctions.h"

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

template <class K, class T>
void testResize(Map<K, T> *map) {

    cout << "Resizing: " << endl;
    map->resize();
    cout << endl;
}





int main() {

    ///Test á KeyDataList
/*
    KeyDataList<int, char> test;

    test.add(1, 'd');
    test.add(2, 'g');
    test.add(3, 'u');

    test.add(4, 'k');

    test.add(5, 'a');
    test.add(6, 'b');
    test.add(7, 'c');

    cout << "test: " << endl;
    test.print();

    test.update(4, 'x');
    test.update(3, 'x');

    cout << endl;
    cout << endl;
    cout << "test: " << endl;
    test.print();

    test.remove(5);
    test.remove(7);
    test.remove(1);

    cout << endl;
    cout << endl;
    cout << "test: " << endl;
    test.print();

  //  test.clear();

    test.add(1, 'd');

    cout << endl;
    cout << endl;
    cout << "test: " << endl;
    test.print();  //ATH! print á tómt gefur error

    cout << "Testing pop: ";

    int tmpKey = 0;
    char tmpData = 0;

    test.pop(tmpKey, tmpData);
    test.pop(tmpKey, tmpData);
    test.pop(tmpKey, tmpData);
    test.pop(tmpKey, tmpData);
    test.pop(tmpKey, tmpData);
    test.pop(tmpKey, tmpData);
    test.pop(tmpKey, tmpData);
    test.pop(tmpKey, tmpData);
    test.pop(tmpKey, tmpData);
    test.pop(tmpKey, tmpData);
    test.pop(tmpKey, tmpData);
    test.pop(tmpKey, tmpData);
    test.pop(tmpKey, tmpData);
    test.pop(tmpKey, tmpData);
    test.pop(tmpKey, tmpData);
    test.pop(tmpKey, tmpData);

    cout << "tmpKey: " << tmpKey << endl;
    cout << "tmpData: " << tmpData << endl;

    test.print();

*/


    Map<char, string> *charHashMap = new HashMap<char, string>(char_hash);

    testInsert(charHashMap, 'a', (string)"item-d");
    testInsert(charHashMap, 'b', (string)"item-b");
    testInsert(charHashMap, 'c', (string)"item-f");
    testInsert(charHashMap, 'd', (string)"item-g");
    testInsert(charHashMap, 'e', (string)"item-e");
    testInsert(charHashMap, 'f', (string)"item-c");
    testInsert(charHashMap, 'g', (string)"item-g");
    testInsert(charHashMap, 'h', (string)"item-d");
    testInsert(charHashMap, 'i', (string)"item-b");
    testInsert(charHashMap, 'j', (string)"item-f");
    testInsert(charHashMap, 'k', (string)"item-g");
    testInsert(charHashMap, 'l', (string)"item-e");
    testInsert(charHashMap, 'm', (string)"item-c");
    testInsert(charHashMap, 'n', (string)"item-g");
    testInsert(charHashMap, 'd', (string)"item-d");

    printMap(charHashMap);


    testSize(charHashMap);

    testContains(charHashMap, 'a');
    testContains(charHashMap, 'b');

    testRemove(charHashMap, 'b');
    testSize(charHashMap);
    testRemove(charHashMap, 'b');
    testSize(charHashMap);
    testRemove(charHashMap, 'b');
    testSize(charHashMap);
    testRemove(charHashMap, 'm');
    testSize(charHashMap);
    testRemove(charHashMap, 'k');
    testSize(charHashMap);

    testContains(charHashMap, 'b');

    testEmpty(charHashMap);

    testClear(charHashMap);

    testEmpty(charHashMap);

    testRemove(charHashMap, 'b');
    testSize(charHashMap);
    testRemove(charHashMap, 'b');
    testSize(charHashMap);
    testRemove(charHashMap, 'b');
    testSize(charHashMap);

    printMap(charHashMap);
    testSize(charHashMap);

    testGet(charHashMap, 'c');
    testGet(charHashMap, 'f');
    testGet(charHashMap, 'e');

    testUpdate(charHashMap, 'f', (string)"item-f-updated");

    testInsert(charHashMap, 'a', (string)"item-d");
    testInsert(charHashMap, 'b', (string)"item-b");
    testInsert(charHashMap, 'c', (string)"item-f");
    testInsert(charHashMap, 'd', (string)"item-g");
    testInsert(charHashMap, 'e', (string)"item-e");
    testInsert(charHashMap, 'f', (string)"item-c");
    testInsert(charHashMap, 'g', (string)"item-g");
    testInsert(charHashMap, 'h', (string)"item-d");
    testInsert(charHashMap, 'i', (string)"item-b");
    testInsert(charHashMap, 'j', (string)"item-f");
    testInsert(charHashMap, 'k', (string)"item-g");
    testInsert(charHashMap, 'l', (string)"item-e");
    testInsert(charHashMap, 'm', (string)"item-c");
    testInsert(charHashMap, 'n', (string)"item-g");
    testInsert(charHashMap, 'd', (string)"item-d");

    printMap(charHashMap);
    testSize(charHashMap);

    testGet(charHashMap, 'c');
    testGet(charHashMap, 'f');
    testGet(charHashMap, 'e');

    testUpdate(charHashMap, 'f', (string)"item-f-updated");

    testGet(charHashMap, 'c');
    testGet(charHashMap, 'f');
    testGet(charHashMap, 'e');

    printMap(charHashMap);
    testSize(charHashMap);

    testRemove(charHashMap, 'c');
    testRemove(charHashMap, 'a');
    testRemove(charHashMap, 'f');

    testUpdate(charHashMap, 'f', (string)"item-f-updated");

    testGet(charHashMap, 'c');
    testGet(charHashMap, 'f');
    testGet(charHashMap, 'e');

    testRemove(charHashMap, 'e');
    testRemove(charHashMap, 'g');

    testEmpty(charHashMap);

    printMap(charHashMap);
    testSize(charHashMap);

    testRemove(charHashMap, 'd');
    testEmpty(charHashMap);

    printMap(charHashMap);
    testSize(charHashMap);

    testInsert(charHashMap, 'd', (string)"item-d");
    testInsert(charHashMap, 'b', (string)"item-b");
    testInsert(charHashMap, 'f', (string)"item-f");
    testInsert(charHashMap, 'g', (string)"item-g");
    testInsert(charHashMap, 'e', (string)"item-e");
    testInsert(charHashMap, 'c', (string)"item-c");

    testEmpty(charHashMap);
    printMap(charHashMap);
    testSize(charHashMap);

    testClear(charHashMap);
    testEmpty(charHashMap);
    printMap(charHashMap);
    testSize(charHashMap);

    delete charHashMap;
    charHashMap = NULL;


    Map<string, string> *stringHashMap = new HashMap<string, string>(string_hash);

    testInsert(stringHashMap, (string)"key1", (string)"data1");
    testInsert(stringHashMap, (string)"key2", (string)"data2");
    testInsert(stringHashMap, (string)"key3", (string)"data3");
    testInsert(stringHashMap, (string)"key4", (string)"data4");
    testInsert(stringHashMap, (string)"key5", (string)"data5");
    testInsert(stringHashMap, (string)"key6", (string)"data1");
    testInsert(stringHashMap, (string)"key7", (string)"data2");
    testInsert(stringHashMap, (string)"key8", (string)"data3");
    testInsert(stringHashMap, (string)"key9", (string)"data4");
    testInsert(stringHashMap, (string)"key10", (string)"data5");
    testInsert(stringHashMap, (string)"key11", (string)"data1");
    testInsert(stringHashMap, (string)"key12", (string)"data2");
    testInsert(stringHashMap, (string)"key13", (string)"data3");
    testInsert(stringHashMap, (string)"key14", (string)"data4");
    testInsert(stringHashMap, (string)"key15", (string)"data5");
    testInsert(stringHashMap, (string)"key16", (string)"data1");
    testInsert(stringHashMap, (string)"key17", (string)"data2");
    testInsert(stringHashMap, (string)"key18", (string)"data3");
    testInsert(stringHashMap, (string)"key19", (string)"data4");
    testInsert(stringHashMap, (string)"key20", (string)"data5");

    printMap(stringHashMap);
    testSize(stringHashMap);

    testClear(stringHashMap);
    testUpdate(stringHashMap, (string)"key2", (string)"data2_updated");

    testInsert(stringHashMap, (string)"key1", (string)"data1");
    testInsert(stringHashMap, (string)"key2", (string)"data2");
    testInsert(stringHashMap, (string)"key3", (string)"data3");
    testInsert(stringHashMap, (string)"key4", (string)"data4");
    testInsert(stringHashMap, (string)"key5", (string)"data5");
    testInsert(stringHashMap, (string)"key6", (string)"data1");
    testInsert(stringHashMap, (string)"key7", (string)"data2");
    testInsert(stringHashMap, (string)"key8", (string)"data3");
    testInsert(stringHashMap, (string)"key9", (string)"data4");
    testInsert(stringHashMap, (string)"key10", (string)"data5");
    testInsert(stringHashMap, (string)"key11", (string)"data1");
    testInsert(stringHashMap, (string)"key12", (string)"data2");
    testInsert(stringHashMap, (string)"key13", (string)"data3");
    testInsert(stringHashMap, (string)"key14", (string)"data4");
    testInsert(stringHashMap, (string)"key15", (string)"data5");
    testInsert(stringHashMap, (string)"key16", (string)"data1");
    testInsert(stringHashMap, (string)"key17", (string)"data2");
    testInsert(stringHashMap, (string)"key18", (string)"data3");
    testInsert(stringHashMap, (string)"key19", (string)"data4");
    testInsert(stringHashMap, (string)"key20", (string)"data5");

    testContains(stringHashMap, (string)"key5");
    testContains(stringHashMap, (string)"keyeye");

    testGet(stringHashMap, (string)"key2");

    testUpdate(stringHashMap, (string)"key2", (string)"data2_updated");

    testRemove(stringHashMap, (string)"key3");

    testContains(stringHashMap, (string)"key3");
    testContains(stringHashMap, (string)"key2");

    testGet(stringHashMap, (string)"key2");

    printMap(stringHashMap);
    testSize(stringHashMap);

    delete stringHashMap;
    stringHashMap = NULL;

}
