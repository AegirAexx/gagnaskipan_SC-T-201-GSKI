#ifndef PAIR_H
#define PAIR_H

#include <ostream>

using namespace std;

template <typename T1, typename T2>
class Pair
{
public:
    Pair<T1,T2>(T1 leftVar, T2 rightVar): leftVar(leftVar), rightVar(rightVar) {}
    virtual ~Pair<T1,T2>() {}

    friend ostream& operator <<(ostream& out, const Pair<T1,T2>& p) {
        out << "{" << p.leftVar << ", " << p.rightVar << "}";
    return out;
}

protected:

private:
    T1 leftVar;
    T2 rightVar;
};

#endif // PAIR_H
