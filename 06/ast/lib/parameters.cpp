/*
 * parameters.cpp
 * Andey Robins
 * 12/2/22
 * Compilers Program 6
 *
 *
 */

#include "../include/nodes.hpp"

NParam::NParam(NType *t, NId *id)
{
    this->type = t;
    this->id = id;
    this->next = 0;
    this->annotation = t->annotation;
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

string NParam::getMangling()
{
    cout << "getting parameter mangling" << endl;
    // cout << this->annotation << endl;
    // cout << this->type << endl;
    if (this->next)
    {
        auto *derivedParam = dynamic_cast<NParam *>(this->next);
        if (derivedParam)
        {
            // cout << "returning type x next params" << endl;
            return this->type->getType() + " x " + derivedParam->getMangling();
        }
    }

    if (this->id && this->type)
    {
        // cout << "returning type" << endl;
        // cout << typeid(this->type).name() << endl;
        // cout << this->type->getType() << endl;
        // if (dynamic_cast<NType *>(this->type))
        // {
        //     // cout << "dynmaically casted to NType" << endl;
        //     static_cast<NType *>(this->type)->print(&cout);
        // }
        // cout << static_cast<NType *>(this->type)->annotation << endl;
        // cout << this->type->annotation << endl;
        return this->type->getType();
    }

    return "void";
}

void NParam::typecheck(SymbolTree *node)
{
    if (this->id && this->type)
    {
        node->registerSymbolWithValue(this->id->getSymbol(), this->type->getType());
    };
    if (this->next)
    {
        static_cast<NParam *>(this->next)->typecheck(node);
    }
}

NArg::NArg(NExp *e)
{
    this->e = e;
    this->next = 0;
    this->annotation = e->annotation;
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
    this->annotation = "brackets";
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
    if (this->next)
    {
        this->next->print(out);
    }
    *out << endl;
}

NBrackExps::NBrackExps(NExp *e)
{
    this->exp = e;
    this->next = 0;
    this->annotation = "[" + e->annotation + "]";
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

void NBrackExps::printType(ostream *out, bool printEndline)
{
    *out << " [<exp>]";
    if (this->next)
    {
        this->next->print(out);
    }
    if (printEndline)
    {
        *out << endl;
    }
}

void NBrackExps::printExpression(ostream *out)
{
    indentation++;
    this->exp->print(out);
    indentation--;
}