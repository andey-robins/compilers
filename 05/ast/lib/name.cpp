/*
 * name.cpp
 * Andey Robins
 * 11/7/22
 * Compilers Program 5
 *
 *
 */

#include "../include/nodes.hpp"

NNameThis::NNameThis()
{
    this->next = 0;
}

void NNameThis::print(ostream *out)
{
    if (this->next)
    {
        *out << string(indentation * 2, ' ')
             << "<name> --> THIS"
             << endl;
        this->next->print(out);
    }
    else
    {
        *out << string(indentation * 2, ' ')
             << "<name> --> THIS"
             << endl;
    }
}

NNameThisDot::NNameThisDot(NName *next)
{
    this->next = next;
}

void NNameThisDot::print(ostream *out)
{
    *out << string(indentation * 2, ' ')
         << "<name> --> THIS . <name>"
         << endl;
    indentation++;
    this->next->print(out);
    indentation--;
}

NNameId::NNameId(NId *id)
{
    this->next = id;
    this->be = 0;
}

NNameId::NNameId(NId *id, NBrackExps *be)
{
    this->next = id;
    this->be = be;
}

NNameId::~NNameId()
{
    delete this->next;
    if (this->be)
    {
        delete this->be;
    }
}

void NNameId::print(ostream *out)
{
    *out << string(indentation * 2, ' ')
         << "<name> --> ID"
         << endl;
    indentation++;
    this->next->print(out);
    if (this->be)
    {
        this->be->print(out);
    }
    *out << endl;
    indentation--;
}

NNameDotId::NNameDotId(NId *id, NName *n)
{
    this->id = id;
    this->next = n;
}

void NNameDotId::print(ostream *out)
{
    *out << string(indentation * 2, ' ')
         << "<name> --> ID . <name>"
         << endl;
    indentation++;
    this->id->print(out);
    *out << endl;
    this->next->print(out);
    indentation--;
}