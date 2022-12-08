/*
 * name.cpp
 * Andey Robins
 * 12/2/22
 * Compilers Program 6
 *
 *
 */

#include "../include/nodes.hpp"

void NName::addSymbols(SymbolTree *node)
{
    auto derivedThis = dynamic_cast<NNameThis *>(this);
    auto derivedThisDot = dynamic_cast<NNameThisDot *>(this);
    auto derivedId = dynamic_cast<NNameId *>(this);
    auto derivedDotId = dynamic_cast<NNameDotId *>(this);

    if (derivedThis)
    {
        derivedThis->addSymbols(node);
    }
    else if (derivedThisDot)
    {
        derivedThisDot->addSymbols(node);
    }
    else if (derivedId)
    {
        derivedId->addSymbols(node);
    }
    else if (derivedDotId)
    {
        derivedDotId->addSymbols(node);
    }
}

string NName::getSupertype()
{
    auto derivedThis = dynamic_cast<NNameThis *>(this);
    auto derivedThisDot = dynamic_cast<NNameThisDot *>(this);
    auto derivedId = dynamic_cast<NNameId *>(this);
    auto derivedDotId = dynamic_cast<NNameDotId *>(this);

    if (derivedThis)
    {
        return "this";
    }
    else if (derivedThisDot)
    {
        return "this dot";
    }
    else if (derivedId)
    {
        return "id";
    }
    else if (derivedDotId)
    {
        return "dot id";
    }
    return "err";
}

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

void NNameThis::addSymbols(SymbolTree *node)
{
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

void NNameThisDot::addSymbols(SymbolTree *node)
{
    if (dynamic_cast<NName *>(this->next))
    {
        auto nextType = static_cast<NName *>(this->next)->getSupertype();
        if (nextType == "this" || nextType == "this dot")
        {
            cout << "Semantic Error: keyword this may not follow keyword this" << endl;
        }
        else
        {
            static_cast<NName *>(this->next)->addSymbols(node);
        }
    }
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

void NNameId::addSymbols(SymbolTree *node)
{
    if (dynamic_cast<NName *>(this->next))
    {
        auto nextType = static_cast<NName *>(this->next)->getSupertype();
        if (nextType == "this" || nextType == "this dot")
        {
            cout << "Semantic Error: keyword this may not follow anything" << endl;
        }
        else
        {
            static_cast<NName *>(this->next)->addSymbols(node);
        }
    }
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

void NNameDotId::addSymbols(SymbolTree *node)
{
    if (dynamic_cast<NName *>(this->next))
    {
        auto nextType = static_cast<NName *>(this->next)->getSupertype();
        if (nextType == "this" || nextType == "this dot")
        {
            cout << "Semantic Error: keyword this may not follow anything" << endl;
        }
        else
        {
            static_cast<NName *>(this->next)->addSymbols(node);
        }
    }
}