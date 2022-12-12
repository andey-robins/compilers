/*
 * block.cpp
 * Andey Robins
 * 12/2/22
 * Compilers Program 6
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

void NBlock::print(ostream *out)
{
    *out << string(indentation * 2, ' ')
         << "<block> --> { <localvardecs>* <statements>* }"
         << endl;
    indentation++;
    auto *derivedDecl = dynamic_cast<NLocalVarDecl *>(this->next);
    auto *derivedStmt = dynamic_cast<NStatement *>(this->next);

    if (derivedDecl)
    {
        derivedDecl->print(out);
    }
    else
    {
        derivedStmt->print(out);
    }
    indentation--;
}

void NBlock::typecheck(SymbolTree *node)
{
    // cout << "block typechecking" << endl;
    if (this->next)
    {
        auto *derivedVar = dynamic_cast<NLocalVarDecl *>(this->next);
        auto *derivedStmt = dynamic_cast<NStatement *>(this->next);

        if (derivedVar)
        {
            // cout << "block derived localvar" << endl;
            derivedVar->typecheck(node);
        }
        else if (derivedStmt)
        {
            // cout << "block derived statement" << endl;
            derivedStmt->typecheck(node);
        }
        else
        {
            cout << "failed to derive next from block" << endl;
        }
    }
}

NVarDecl::NVarDecl(NType *t, NId *id)
{
    this->type = t;
    this->id = id;
    this->next = 0;
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

void NVarDecl::print(ostream *out)
{
    *out << string(indentation * 2, ' ')
         << "<vardecs> --> <vardecs> <vardec>"
         << endl;
    indentation++;
    *out << string(indentation * 2, ' ')
         << "<vardec> --> <type> ID SEMI"
         << endl;
    indentation++;
    this->type->print(out);
    if (this->type->getType() == "ID")
    {
        *out << endl;
    }
    static_cast<NId *>(this->id)->print(out);
    *out << endl;
    indentation -= 2;
    // expand the <vardecs> nonterminal
    if (this->next)
    {
        this->next->print(out);
    }
}

void NVarDecl::typecheck(SymbolTree *node)
{
    // cout << "nvardecl" << endl;
    // cout << this->id->getSymbol() << endl;
    // cout << "after" << endl;
    node->registerSymbolWithValue(this->id->getSymbol(), this->type->getType());
    SymbolTree *child = new SymbolTree();
    node->setChild(child);
    child->setParent(node);

    if (this->next)
    {
        auto *derivedVar = dynamic_cast<NVarDecl *>(this->next);
        auto *derivedCons = dynamic_cast<NConstDecl *>(this->next);
        auto *derivedMeth = dynamic_cast<NMethDecl *>(this->next);

        if (derivedVar)
        {
            derivedVar->typecheck(node);
        }
        else if (derivedCons)
        {
            derivedCons->typecheck(node);
        }
        else if (derivedMeth)
        {
            derivedMeth->typecheck(node);
        }
    }
}

NLocalVarDecl::NLocalVarDecl(NVarDecl *vd)
{
    this->vd = vd;
}

void NLocalVarDecl::print(ostream *out)
{
    *out << string(indentation * 2, ' ')
         << "<localvardec> --> <vardec>"
         << endl;
    indentation++;
    this->vd->print(out);
    indentation--;
    if (this->next)
    {
        this->next->print(out);
    }
}

void NLocalVarDecl::typecheck(SymbolTree *node)
{
    this->vd->typecheck(node);
    auto *derivedVar = dynamic_cast<NLocalVarDecl *>(this->next);
    auto *derivedStmt = dynamic_cast<NStatement *>(this->next);

    if (derivedVar)
    {
        derivedVar->typecheck(node);
    }
    else if (derivedStmt)
    {
        derivedStmt->typecheck(node);
    }
}