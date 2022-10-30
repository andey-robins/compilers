/*
 * types.cpp
 * Andey Robins
 * 10/20/22
 * Compilers Program 4
 *
 *
 */

#include "../include/nodes.hpp"

NSimpleType::NSimpleType(NKeyword *k)
{
    this->next = k;
}

NSimpleType::NSimpleType(NId *id)
{
    this->next = id;
    this->isId = true;
}

void NSimpleType::print()
{
    if (this->isId)
    {
        cout << string(indentation * 2, ' ')
             << "<type> -> ID";
        indentation++;
        this->next->print();
        indentation--;
    }
    else
    {
        cout << string(indentation * 2, ' ')
             << "<type> -> INT"
             << endl;
    }
}

NType::NType(NSimpleType *st)
{
    this->next = st;
}

NType::NType(NType *t, int bracks)
{
    this->brackCount = bracks;
    this->next = t;
}

int NType::getBracks()
{
    return this->brackCount;
}

void NType::print()
{
    // Todo handle printing brackets
    this->next->print();
}

NEpsilon::NEpsilon()
{
    this->setVal("epsilon");
}

void NEpsilon::print()
{
    // TODO remove this
    cout << string(indentation * 2, ' ')
         << "epsilon"
         << endl;
}