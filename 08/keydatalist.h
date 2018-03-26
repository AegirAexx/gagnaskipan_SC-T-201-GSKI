#ifndef KEYDATALIST_H
#define KEYDATALIST_H

#include <ostream>
#include "keydatalistnode.h"
#include <string>
#include "map.h"

using namespace std;


template <class K, class T>
class KeyDataList
{
    public:
        KeyDataList<K, T>() {
            head = NULL;
        };

        virtual ~KeyDataList<K, T>() {
            clear();
        };

        bool add(K key, T data) {

            if(head == NULL) {  //Ef ekkert er á þessum stað
                head = new KeyDataListNode<K, T>(key, data, NULL);
                return true;
            }

            KeyDataListNode<K, T>* tmp = head;
            while(tmp->next != NULL) {
                if(tmp->key == key) {
                    return false;
                }
                tmp = tmp->next;
            }

            if(tmp->key == key) { //þarf ég þetta?
                return false;
            }

            tmp->next = new KeyDataListNode<K, T>(key, data, NULL);
            return true;
        }

        bool update(K key, T data) {

            if(head == NULL) {  //Ef ekkert er á þessum stað
                return false;
            }

            KeyDataListNode<K, T>* tmp = head;
            while(tmp->next != NULL) {
                if(tmp->key == key) {
                    tmp->data = data;
                    return true;
                }
                tmp = tmp->next;
            }

            if(tmp->key == key) { //þarf ég þetta hérna líka?
                tmp->data = data;
                return true;
            }

            return false;
        }

        T find(K key) {

            if(head == NULL) {  //Ef ekkert er á þessum stað, sennilega throw exc
                throw NotFoundException();
            }

            KeyDataListNode<K, T>* tmp = head;
            while(tmp->next != NULL) {
                if(tmp->key == key) {
                    return tmp->data;
                }
                tmp = tmp->next;
            }

            if(tmp->key == key) { //þarf ég þetta hérna líka?
                return tmp->data;
            }

            throw NotFoundException();
        }

        bool remove(K key) {

            if(head == NULL) {
                return false;
            }

            if(head->key == key) {
                KeyDataListNode<K, T> *forDeletion = head;
                head = head->next;
                delete forDeletion;
                return true;
            }

            KeyDataListNode<K, T>* tmp = head;
            while(tmp->next != NULL) {
                if(tmp->next->key == key) {
                    KeyDataListNode<K, T> *forDeletion = tmp->next;
                    tmp->next = tmp->next->next;
                    delete forDeletion;
                    return true;
                }
                tmp = tmp->next;
            }
            return false;
        }

        bool contains(K key) {

            if(head == NULL) {  //Ef ekkert er á þessum stað, sennilega throw exc
                return false;
            }

            KeyDataListNode<K, T>* tmp = head;
            while(tmp->next != NULL) {
                if(tmp->key == key) {
                    return true;
                }
                tmp = tmp->next;
            }

            if(tmp->key == key) { //þarf ég þetta hérna líka?
                return true;
            }

            return false;
        }

        void clear() {
            KeyDataListNode<K, T> *tmp = head;
            while(head != NULL) {
                head = head->next;
                delete tmp;
                tmp = head;
            }
        }

        bool pop(K &key, T &data) {  //Þetta hefur hugsanlega eitthvað með resize að gera

            if(head == NULL) {
                return false;
            }
            else {
                key = head->key;
                data = head->data;
                KeyDataListNode<K, T>* tmp = head;
                head = head->next;
                delete tmp;

                return true;
            }

        }

        void print() const {

            if(head != NULL) {
                KeyDataListNode<K, T>* tmp = head;
                while(tmp->next != NULL) {
                    cout << "Data for key " << tmp->key << " is: " << tmp->data << endl;
                    tmp = tmp->next;
                }
                cout << "Data for key " << tmp->key << " is: " << tmp->data << endl;
            }
        }

        bool isEmpty() {
            if(head == NULL) {
                return true;
            }
            else {
                return false;
            }
        }

    protected:

    private:
        KeyDataListNode<K, T> *head;
};

#endif // KEYDATALIST_H
