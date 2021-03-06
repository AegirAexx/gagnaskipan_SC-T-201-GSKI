#ifndef INSERTSORTEDARRAY_H
#define INSERTSORTEDARRAY_H

#include <ostream>

using namespace std;

class IndexOutOfBoundsException{};
class EmptyException{};

const int INITIAL_CAPACITY = 4;

class CharacterArray{
    public:
        CharacterArray();
        CharacterArray(char* inStr, int length);
        virtual ~CharacterArray();

        void append(char c);
        void insert(char c, int index);
        void setAt(char c, int index);

        char getAt(int index) const;

        char pop_back();
        char removeAt(int index);
        void clear();

        int length() const;

        bool isEmpty();

        char* substring(int startIndex, int length);

        friend ostream& operator << (ostream& out, const CharacterArray& ca);

    private:
        int capacity;
        int itemCount;
        char* str;

        void resizeArray();
};

#endif // INSERTSORTEDARRAY_H
