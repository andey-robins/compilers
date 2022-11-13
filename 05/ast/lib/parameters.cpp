/*
 * parameters.cpp
 * Andey Robins
 * 11/7/22
 * Compilers Program 5
 *
 *
 */

#include "../include/nodes.hpp"

NParam::NParam(NType *t, NId *id)
{
    this->type = t;
    this->id = id;
    this->next = 0;
}

void NParam::print(ostream *out)
{
    *out << string(indentation * 2, ' ')
         << "<param> --> <type> ID"
         << endl;
    indentation++;
    this->type->print(out);
    *out << endl;
    this->id->print(out);
    *out << endl;
    indentation--;
    if (this->next)
    {
        this->next->print(out);
    }
}

NArg::NArg(NExp *e)
{
    this->e = e;
    this->next = 0;
}

NArg::~NArg()
{
    delete this->e;
}

void NArg::print(ostream *out)
{
    *out << string(indentation * 2, ' ')
         << "<arg> --> <expression>"
         << endl;
    indentation++;
    this->e->print(out);
    indentation--;
    if (this->next)
    {
        this->next->print(out);
    }
}

NBracks::NBracks(int count)
{
    this->count = count;
    this->next = 0;
}

int NBracks::getCount()
{
    return this->count;
}

void NBracks::print(ostream *out)
{
    for (int i = 0; i < this->count; i++)
    {
        *out << " []";
    }
    *out << endl;
    if (this->next)
    {
        this->next->print(out);
    }
}

NBrackExps::NBrackExps(NExp *e)
{
    this->exp = e;
    this->next = 0;
}

NBrackExps::~NBrackExps()
{
    delete this->exp;
}

void NBrackExps::print(ostream *out)
{
    *out << " [<exp>]";
    if (this->next)
    {
        this->next->print(out);
    }
    *out << endl;
    indentation++;
    this->exp->print(out);
    indentation--;
}