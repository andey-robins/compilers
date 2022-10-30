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