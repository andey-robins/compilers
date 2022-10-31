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
    auto *derivedDecl = dynamic_cast<NLocalVarDecl *>(this->next);
    auto *derivedStmt = dynamic_cast<NStatement *>(this->next);

    if (derivedDecl)
    {
        derivedDecl->print();
    }
    else
    {
        derivedStmt->print();
    }
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
    this->vd = vd;
}

void NLocalVarDecl::print()
{
    cout << string(indentation * 2, ' ')
         << "<localvardec> --> <vardec>"
         << endl;
    indentation++;
    this->vd->print();
    indentation--;
    if (this->next)
    {
        this->next->print();
    }
}