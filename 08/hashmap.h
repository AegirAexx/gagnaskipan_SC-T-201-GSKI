#ifndef HASHMAP_H
#define HASHMAP_H

#include <ostream>
#include "map.h"
#include "keydatalist.h"
#include "hashfunctions.h"
#include <string>

using namespace std;

template <class K, class T>
class HashMap : public Map<K, T>
{
    public:
        HashMap<K, T>(int (*func)(K key)) {

            hash_func = func;
            array_size = 2;
            count = 0;

            arr = new KeyDataList<K, T>[array_size];

        };
        virtual ~HashMap<K, T>() {};

        ///Erfð function
        void insert(K key, T data) {

            if(count + 1 > array_size) {
                resize();
            }

            int index = hash_func(key) % array_size;
            arr[index].add(key, data);
            count++;
        }

        void update(K key, T data) {
            int index = hash_func(key) % array_size;
            arr[index].update(key, data);
        }

        T get(K key) {
            int index = hash_func(key) % array_size;
            return arr[index].find(key);
        }

        void remove(K key) {
            if(count > 0) {
                int index = hash_func(key) % array_size;
                arr[index].remove(key);
                count--;
            }
        }

        bool contains(K key) {
            int index = hash_func(key) % array_size;
            return arr[index].contains(key);
        }

        int size() const {
            return count;
        }

        bool empty() const {
            return (count == 0);
        }

        void clear() {
            for(unsigned int i = 0; i < array_size; i++) {
                arr[i].clear();
            }
        }

        void print(ostream& out) const {

            for(unsigned int i = 0; i < array_size; i++) {
                cout << endl << "Bucket #" << i << endl;
                arr[i].print();
                cout << endl;
            }
        }

        void resize(){
            KeyDataList<K, T> *oldArr = arr;
            int old_size = array_size;
            array_size *= 2;

            arr = new KeyDataList<K, T>[array_size]; //Búa til stærri útgáfu af arr
            count = 0;

            for(int i = 0; i < array_size; ++i){
                if(oldArr[i].isEmpty()) {
                    while(oldArr[i].isEmpty() != true) {
                        K tmpKey;
                        T tmpData;

                        oldArr[i].pop(tmpKey, tmpData);
                        insert(tmpKey, tmpData);
                    }
                }
            }
              //Gera arraysize stærra
        }

    protected:

    private:
        KeyDataList<K, T> *arr;
        int (*hash_func)(K key);
        unsigned int array_size;
        int count;
};

#endif // HASHMAP_H
