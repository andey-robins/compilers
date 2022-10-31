/*
 * leaves.cpp
 * Andey Robins
 * 10/20/22
 * Compilers Program 4
 *
 *
 */

#include "nodes.hpp"

NId::NId(string id)
{
    this->text = id;
}

void NId::print()
{
    cout << string(indentation * 2, ' ')
         << "ID --> "
         << this->text;
}

NKeyword::NKeyword(string key)
{
    this->text = key;
}

void NKeyword::print()
{
    cout << this->text << endl;
}

NNumber::NNumber(int n)
{
    this->num = n;
}

int NNumber::getVal()
{
    return this->num;
}

void NNumber::print()
{
    cout << string(indentation * 2, ' ')
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

void NOperator::print()
{
    cout << this->op;
}