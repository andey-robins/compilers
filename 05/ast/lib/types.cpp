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
    this->type = id->getSymbol();
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
    if (t != 0)
    {
        string typeString = t->getType();
        for (int i = 0; i < bracks; i++)
        {
            typeString += "[]";
        }
        type = typeString;
    }
    else
    {
        type = "unknown";
    }
}

NType::NType(NType *t, NBrackExps *bes)
{
    this->brackCount = 0;
    this->bracketExps = bes;
    if (t != 0)
    {
        string typeString = t->getType();
        std::stringstream s;
        bes->printType(&s);
        typeString += s.str();
        type = typeString;
    }
    else
    {
        type = "unknown";
    }
}

int NType::getBracks()
{
    return this->brackCount;
}

string NType::getType()
{
    string typeString;
    typeString += this->type;
    return typeString;
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

string NResultType::getType()
{
    if (this->type)
    {
        return this->type->getType();
    }
    return "void";
}

NEpsilon::NEpsilon()
{
    this->setVal("epsilon");
}

string NEpsilon::getType()
{
    return "void";
}

void NEpsilon::print(ostream *out)
{
}