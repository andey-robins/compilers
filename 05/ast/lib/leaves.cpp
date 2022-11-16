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

string NId::getSymbol()
{
    return this->text;
}

NKeyword::NKeyword(string key)
{
    this->text = key;
}

string NKeyword::getText()
{
    return this->text;
}

void NKeyword::print(ostream *out)
{
    *out << this->text << endl;
}

string NKeyword::getSymbol()
{
    return this->text;
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

string NNumber::getSymbol()
{
    return std::to_string(this->num);
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

string NOperator::getSymbol()
{
    return this->op;
}