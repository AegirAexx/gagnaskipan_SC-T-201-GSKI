#ifndef INSERTSORTEDARRAY_H
#define INSERTSORTEDARRAY_H

#include <ostream>

using namespace std;

class IndexOutOfBoundsException{};
class EmptyException{};

constexpr int INITIAL_CAPACITY = 4;

class CharacterArray{
    public:
        CharacterArray();
        CharacterArray(char* str, int length);
        virtual ~CharacterArray();

        void append(char c);
        void insert(char c, int index);
        void setAt(char c, int index);

        char getAt(int index) const;

        char popBack();
        char removeAt(int index);
        void clear();

        int length();

        bool isEmpty();

        char* substring(int startIndex, int length);

        friend ostream& operator << (ostream& out, const CharacterArray& ca);

    private:
        int capacity;
        int itemCount;
        char* str;
};

#endif // INSERTSORTEDARRAY_H
