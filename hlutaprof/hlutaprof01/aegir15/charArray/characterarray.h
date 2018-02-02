#ifndef INSERTSORTEDARRAY_H
#define INSERTSORTEDARRAY_H

#include <ostream>

using namespace std;

class IndexOutOfBoundsException{};
class EmptyException{};

class CharacterArray
{
    public:
        CharacterArray();
        CharacterArray(char* str, int length);
        virtual ~CharacterArray();

        void append(char c);
        void setAt(char c, int index);

        char getAt(int index) const;

        char pop_back();
        char removeAt(int index);
        void clear();

        int length() const;

        bool isEmpty() const;

        char* substring(int startIndex, int length);

        friend ostream& operator <<(ostream& out, const CharacterArray& ca);

    protected:

    private:
        char *arr;
        int capacity;
        int size;

        void resizeArray();

};

#endif // INSERTSORTEDARRAY_H
