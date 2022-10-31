/*
 * block.cpp
 * Andey Robins
 * 10/20/22
 * Compilers Program 4
 *
 *
 */

#include "../include/nodes.hpp"

NBlock::NBlock(NLocalVarDecl *vd)
{
    this->next = vd;
}

NBlock::NBlock(NStatement *s)
{
    this->next = s;
}

void NBlock::print()
{
    // TODO
    // cout << "TODO write print for blocks" << endl;

    cout << string(indentation * 2, ' ')
         << "<block> --> { <localvardecs>* <statements>* }"
         << endl;
    indentation++;
    this->next->print();
    indentation--;
}

NVarDecl::NVarDecl(NType *t, NId *id)
{
    this->type = t;
    this->id = id;
}

NVarDecl::~NVarDecl()
{
    delete this->type;
    delete this->id;

    if (this->next)
    {
        delete this->next;
    }
}

void NVarDecl::print()
{
    cout << string(indentation * 2, ' ')
         << "<vardecs> --> <vardecs> <vardec>"
         << endl;
    indentation++;
    cout << string(indentation * 2, ' ')
         << "<vardec> --> <type> ID SEMI"
         << endl;
    indentation++;
    this->type->print();
    static_cast<NId *>(this->id)->print();
    indentation -= 2;
    // expand the <vardecs> nonterminal
    if (this->next)
    {
        this->next->print();
    }
}

NLocalVarDecl::NLocalVarDecl(NVarDecl *vd)
{
    this->next = vd;
}

void NLocalVarDecl::print()
{
    if (this->next)
    {
        static_cast<NVarDecl *>(this->next)->print();
    }
}