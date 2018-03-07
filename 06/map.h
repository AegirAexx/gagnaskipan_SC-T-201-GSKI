#ifndef MAP_H
#define MAP_H

#include <ostream>

class NotFoundException{};
class ItemExistsException{};

template <typename K, typename T>
class Map {

public:
    virtual ~Map() {};

    virtual void insert(K key, T data) = 0;
    virtual void update(K key, T data) = 0;
    virtual T get(K key) = 0;
    virtual void remove(K key) = 0;
    virtual bool contains(K key) = 0;
    virtual int size() const = 0;
    virtual bool empty() const = 0;
    virtual void clear() = 0;
    virtual void print(std::ostream& out) const = 0;

    friend std::ostream& operator <<(std::ostream& out, const Map<K, T>& bm) {
        bm.print(out);
        return out;
    }
};

#endif // MAP_H
