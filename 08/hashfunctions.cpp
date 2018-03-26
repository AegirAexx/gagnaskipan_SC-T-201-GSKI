#include "hashfunctions.h"

int char_hash(char c) {

    return int(c);
}

int int_hash(int i) {

    if(i < 0) {
        return -i;
    }
    return i;
}

int string_hash(string s) {

    unsigned int hash = 1315423911;

    for(size_t i = 0; i < s.length(); i++)
    {
        hash ^= ((hash << 5) + s[i] + (hash >> 2));
    }

    return (hash & 0x7FFFFFFF);
}
