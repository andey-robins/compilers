/*
 * value.cpp
 * Andey Robins
 * 12/2/22
 * Compilers Program 6
 *
 */

#include "../include/value.hpp"

Value::Value()
{
    this->s = 0;
    this->i = 0;
    this->epsilon = true;
}
Value::Value(string *s)
{
    this->s = s;
    this->i = 0;
    this->epsilon = false;
}
Value::Value(int i)
{
    this->i = i;
    this->s = 0;
    this->epsilon = false;
}

Value::~Value()
{
    delete this->s;
}

bool Value::isString()
{
    return this->s != 0;
}

bool Value::isInt()
{
    return this->s == 0 && !this->epsilon;
}

bool Value::isEpsilon()
{
    return this->epsilon;
}

string *Value::getString()
{
    return this->s;
}

int Value::getInt()
{
    return this->i;
}

void Value::print()
{
    if (this->s)
    {
        cout << (*this->s);
    }
    else
    {
        cout << this->i;
    }
}