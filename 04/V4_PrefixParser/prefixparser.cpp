#include <iostream>
#include "prefixparser.h"


using namespace std;

int parseExpression(istream& ins){

    string strInput;

    ins >> strInput;

    if(strInput == "+") {
        return parseExpression(ins) + parseExpression(ins);
    }
    else if (strInput == "-") {
        return parseExpression(ins) - parseExpression(ins);
    }
    else if (strInput == "/") {
        int number1 = parseExpression(ins);
        int number2 = parseExpression(ins);

        if (number2 == 0 ) {
                throw DivideByZeroException();
        }
        return number1 / number2;
    }
    else if (strInput == "*") {
        return parseExpression(ins) * parseExpression(ins);
    }
    else {

        int someInt = atoi(strInput.c_str());

        return someInt;
    }

    return 0;

}
