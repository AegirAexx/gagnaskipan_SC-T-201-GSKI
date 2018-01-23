#ifndef MEASUREMENT_H
#define MEASUREMENT_H

#include <ostream>
#include <string>

class Measurement{
    public:
        Measurement(std::string name, double value) : name(name), value(value) {};
        virtual ~Measurement() {};

        friend std::ostream& operator <<(std::ostream &out, const Measurement m){
            out << "[" << m.name << ": " << m.value << "]";
            return out;
        };

    private:
        std::string name;
        double value;
};

#endif // MEASUREMENT_H
