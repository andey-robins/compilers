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
    cout << endl;
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

NBracks::NBracks(int count)
{
    this->count = count;
}

int NBracks::getCount()
{
    return this->count;
}

void NBracks::print()
{
    for (int i = 0; i < this->count; i++)
    {
        cout << " []";
    }
    cout << endl;
    if (this->next)
    {
        this->next->print();
    }
}

NBrackExps::NBrackExps(NExp *e)
{
    this->exp = e;
}

NBrackExps::~NBrackExps()
{
    delete this->exp;
}

void NBrackExps::print()
{
    cout << " [<exp>]";
    if (this->next)
    {
        this->next->print();
    }
    cout << endl;
    indentation++;
    this->exp->print();
    indentation--;
}