/*
 * leaves.cpp
 * Andey Robins
 * 11/7/22
 * Compilers Program 5
 *
 *
 */

#include "../include/nodes.hpp"

NId::NId(string id)
{
    this->text = id;
}

void NId::print(ostream *out)
{
    *out << string(indentation * 2, ' ')
         << "ID --> "
         << this->text;
}

NKeyword::NKeyword(string key)
{
    this->text = key;
}

void NKeyword::print(ostream *out)
{
    *out << this->text << endl;
}

NNumber::NNumber(int n)
{
    this->num = n;
}

int NNumber::getVal()
{
    return this->num;
}

void NNumber::print(ostream *out)
{
    *out << string(indentation * 2, ' ')
         << "NUMBER --> "
         << this->num
         << endl;
}

NOperator::NOperator(string op)
{
    this->op = op;
}

string NOperator::getOp()
{
    return this->op;
}

void NOperator::print(ostream *out)
{
    *out << this->op;
}