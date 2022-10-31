/*
 * name.cpp
 * Andey Robins
 * 10/20/22
 * Compilers Program 4
 *
 *
 */

#include "../include/nodes.hpp"

NNameThis::NNameThis() {}

void NNameThis::print()
{
    if (this->next)
    {
        cout << string(indentation * 2, ' ')
             << "<name> -> THIS"
             << endl;
        this->next->print();
    }
    else
    {
        cout << string(indentation * 2, ' ')
             << "<name> --> THIS"
             << endl;
    }
}

NNameThisDot::NNameThisDot(NName *next)
{
    this->next = next;
}

void NNameThisDot::print()
{
    cout << string(indentation * 2, ' ')
         << "<name> --> THIS . <name>"
         << endl;
    this->next->print();
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

void NNameId::print()
{
    cout << string(indentation * 2, ' ')
         << "<name> --> ID"
         << endl;
    indentation++;
    this->next->print();
    if (this->be)
    {
        this->be->print();
    }
    cout << endl;
    indentation--;
}

NNameDotId::NNameDotId(NId *id, NName *n)
{
    this->id = id;
    this->next = n;
}

void NNameDotId::print()
{
    cout << string(indentation * 2, ' ')
         << "<name> --> ID . <name>"
         << endl;
    indentation++;
    this->id->print();
    cout << endl;
    this->next->print();
    indentation--;
}