/*
 * types.cpp
 * Andey Robins
 * 11/7/22
 * Compilers Program 5
 *
 *
 */

#include "../include/nodes.hpp"

NSimpleType::NSimpleType(NKeyword *k)
{
    // this is for int keywords
    this->next = k;
    this->isId = false;
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

void NSimpleType::print(ostream *out)
{
    if (this->isId)
    {
        *out << string(indentation * 2, ' ')
             << "<type> --> ID"
             << endl;
        indentation++;
        this->next->print(out);
        indentation--;
    }
    else
    {
        *out << string(indentation * 2, ' ')
             << "<type> --> INT"
             << endl;
    }
}

void NSimpleType::printClipped(ostream *out)
{
    *out << string(indentation * 2, ' ')
         << "<type> --> ";
    if (this->isId)
    {
        *out << "ID";
    }
    else
    {
        *out << "INT";
    }
}

void NSimpleType::printNext(ostream *out)
{
    indentation++;
    // *out << string(indentation * 2, ' ')
    //      << "ID --> ";
    this->next->print(out);
    *out << endl;
    indentation--;
}

NType::NType(NSimpleType *st)
{
    this->next = st;
    this->type = st->getType();
    this->brackCount = 0;
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

void NType::print(ostream *out)
{
    // Todo handle printing brackets
    this->next->print(out);
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

void NResultType::print(ostream *out)
{
    if (this->type)
    {
        *out << string(indentation * 2, ' ')
             << "<resulttype> --> <type>"
             << endl;
        indentation++;
        this->type->print(out);
        indentation--;
    }
    else
    {
        *out << string(indentation * 2, ' ')
             << "<resulttype> --> ";
        this->voidType->print(out);
    }
}

NEpsilon::NEpsilon()
{
    this->setVal("epsilon");
}

void NEpsilon::print(ostream *out)
{
}