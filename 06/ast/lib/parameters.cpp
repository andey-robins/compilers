/*
 * parameters.cpp
 * Andey Robins
 * 12/2/22
 * Compilers Program 6
 *
 * Implementations of parameter classes
 *
 */

#include "../include/nodes.hpp"

NParam::NParam(NType *t, NId *id)
{
    this->type = t;
    this->id = id;
    this->next = 0;
    this->annotation = t->annotation;
    this->line = t->line + " " + id->line;
    this->lineNumber = t->lineNumber;
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
    if (this->next)
    {
        auto *derivedParam = dynamic_cast<NParam *>(this->next);
        if (derivedParam)
        {
            return this->type->getType() + " x " + derivedParam->getMangling();
        }
    }

    if (this->id && this->type)
    {
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
    this->line = e->line;
    this->lineNumber = e->lineNumber;
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
    this->line = e->line;
    this->lineNumber = e->lineNumber;
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