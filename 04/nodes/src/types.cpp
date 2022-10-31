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
    this->type = k->getText();
}

NSimpleType::NSimpleType(NId *id)
{
    this->next = id;
    this->isId = true;
    this->type = "ID";
}

string NSimpleType::getType()
{
    return this->type;
}

void NSimpleType::print()
{
    if (this->isId)
    {
        cout << string(indentation * 2, ' ')
             << "<type> -> ID"
             << endl;
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
    this->type = st->getType();
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

string NType::getType()
{
    return this->type;
}

void NType::print()
{
    // Todo handle printing brackets
    this->next->print();
}

NResultType::NResultType(NType *t)
{
    this->type = t;
    this->voidType = 0;
}

NResultType::NResultType(NKeyword *k)
{
    this->voidType = k;
    this->type = 0;
}

void NResultType::print()
{
    if (this->type)
    {
        cout << string(indentation * 2, ' ')
             << "<resultype> --> <type>"
             << endl;
        indentation++;
        this->type->print();
        indentation--;
    }
    else
    {
        cout << string(indentation * 2, ' ')
             << "<resultype> --> ";
        this->voidType->print();
    }
}

NEpsilon::NEpsilon()
{
    this->setVal("epsilon");
}

void NEpsilon::print()
{
}