/*
 * value.hpp
 * Andey Robins
 * 12/2/22
 * Compilers Program 6
 *
 */

#ifndef VALUE_HPP
#define VALUE_HPP

#include "parser.hpp"

class Value
{
public:
    Value(); // an empty value i.e. a declaration without a value
    Value(string *s);
    Value(int i);
    virtual ~Value();
    bool isString();
    bool isInt();
    bool isEpsilon();
    string *getString();
    int getInt();
    void print();

private:
    string *s;
    int i;
    bool epsilon;
};

#endif