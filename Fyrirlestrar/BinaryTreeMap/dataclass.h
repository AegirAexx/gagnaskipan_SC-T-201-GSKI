#ifndef DATACLASS_H
#define DATACLASS_H

#include <iostream>
#include <string>

using namespace std;

class DataClass
{
    public:
        DataClass(int n, string nm, double r) : number(n), name(nm), result(r) {};
        virtual ~DataClass();

        friend ostream& operator <<(ostream &out, const DataClass &data) {

            out << "[" << data.number << ", " << data.name << ", " << data.result << "]";
            return out;
        }

    protected:

    private:
        int number;
        string name;
        double result;
};

#endif // DATACLASS_H
