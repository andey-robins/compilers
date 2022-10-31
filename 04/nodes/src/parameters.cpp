/*
 * parameters.cpp
 * Andey Robins
 * 10/20/22
 * Compilers Program 4
 *
 *
 */

#include "../include/nodes.hpp"

NParam::NParam(NType *t, NId *id)
{
    this->type = t;
    this->id = id;
}

void NParam::print()
{
    cout << string(indentation * 2, ' ')
         << "<param> --> <type> ID"
         << endl;
    indentation++;
    this->type->print();
    this->id->print();
    indentation--;
    if (this->next)
    {
        this->next->print();
    }
}

NArg::NArg(NExp *e)
{
    this->e = e;
}

NArg::~NArg()
{
    delete this->e;
}

void NArg::print()
{
    cout << string(indentation * 2, ' ')
         << "<arg> --> <expression>"
         << endl;
    indentation++;
    this->e->print();
    indentation--;
    if (this->next)
    {
        this->next->print();
    }
}