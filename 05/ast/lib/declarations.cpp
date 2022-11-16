/*
 * declarations.cpp
 * Andey Robins
 * 11/7/22
 * Compilers Program 5
 *
 *
 */

#include "../include/nodes.hpp"

NClassDecl::NClassDecl(NId *id, NClassBody *cb)
{
    this->className = id;
    this->classBody = cb;
}

NClassDecl::~NClassDecl()
{
    delete this->className;
    delete this->classBody;
}

void NClassDecl::print(ostream *out)
{
    *out << string(indentation * 2, ' ')
         << "<classdec> --> CLASS ID <classbody>"
         << endl;
    indentation++;
    this->className->print(out);
    *out << endl;
    this->classBody->print(out);
    indentation--;
}

void NClassDecl::addSymbols(SymbolTree *node)
{
    // in this context, node == root
    node->registerSymbolWithValue(this->className->getSymbol(), "class_type");
    SymbolTree *child = new SymbolTree();
    node->setChild(child);
    child->setParent(node);
    this->classBody->addSymbols(child);
}

NClassBody::NClassBody(NVarDecl *declHead)
{
    this->next = declHead;
}

NClassBody::NClassBody(NConstDecl *declHead)
{
    this->next = declHead;
}

NClassBody::NClassBody(NMethDecl *declHead)
{
    this->next = declHead;
}

NClassBody::~NClassBody()
{
    if (this->next)
    {
        delete this->next;
    }
}

void NClassBody::print(ostream *out)
{
    *out << string(indentation * 2, ' ')
         << "<classbody> --> { <vardecs> <consdecs> <methdecs> }"
         << endl;
    indentation++;
    if (this->next)
    {
        this->next->print(out);
    }
    indentation--;
}

void NClassBody::addSymbols(SymbolTree *node)
{
    if (this->next)
    {
        auto *derivedVar = dynamic_cast<NVarDecl *>(this->next);
        auto *derivedCons = dynamic_cast<NConstDecl *>(this->next);
        auto *derivedMeth = dynamic_cast<NMethDecl *>(this->next);

        if (derivedVar)
        {
            derivedVar->addSymbols(node);
        }
        else if (derivedCons)
        {
            derivedCons->addSymbols(node);
        }
        else if (derivedMeth)
        {
            derivedMeth->addSymbols(node);
        }
    }
}

NConstDecl::NConstDecl(NId *id, NParam *p, NBlock *b)
{
    this->id = id;
    this->params = p;
    this->block = b;
}

void NConstDecl::print(ostream *out)
{
    *out << string(indentation * 2, ' ')
         << "<consdecs> --> <consdecs> <consdec>"
         << endl;
    indentation++;
    if (this->params->getText() == "epsilon")
    {
        *out << string(indentation * 2, ' ')
             << "<consdec> --> ID () <block>"
             << endl;
        indentation++;
        this->id->print(out);
        *out << endl;
        this->block->print(out);
        indentation -= 2;
    }
    else
    {
        *out << string(indentation * 2, ' ')
             << "<consdec> --> ID ( <params> ) <block>"
             << endl;
        indentation++;
        this->id->print(out);
        *out << endl;
        *out << string(indentation * 2, ' ')
             << "<paramlist> --> <param>"
             << endl;
        indentation++;
        this->params->print(out);
        indentation--;
        this->block->print(out);
        indentation -= 2;
    }

    // expand the <constdecs> nonterminal
    if (this->next)
    {
        this->next->print(out);
    }
}

void NConstDecl::addSymbols(SymbolTree *node)
{
    node->registerSymbolWithValue(this->id->getSymbol(), "constructor_type <- ");
    SymbolTree *child = new SymbolTree();
    node->setChild(child);
    child->setParent(node);
    this->block->addSymbols(child);
    if (this->next)
    {
        auto *derivedCons = dynamic_cast<NConstDecl *>(this->next);
        auto *derivedMeth = dynamic_cast<NMethDecl *>(this->next);

        if (derivedCons)
        {
            derivedCons->addSymbols(node);
        }
        else if (derivedMeth)
        {
            derivedMeth->addSymbols(node);
        }
    }
}

NMethDecl::NMethDecl(NResultType *rt, NId *id, NParam *p, NBlock *b)
{
    this->resType = rt;
    this->id = id;
    this->params = p;
    this->block = b;
}

void NMethDecl::print(ostream *out)
{
    *out << string(indentation * 2, ' ')
         << "<methdecs> --> <methdecs> <methdec>"
         << endl;
    indentation++;
    if (this->params->getText() == "epsilon")
    {
        *out << string(indentation * 2, ' ')
             << "<methdec> --> <resulttype> ID () <block>"
             << endl;
        indentation++;
        this->resType->print(out);
        this->id->print(out);
        *out << endl;
        this->block->print(out);
        indentation -= 2;
    }
    else
    {
        *out << string(indentation * 2, ' ')
             << "<methdec> --> <resulttype> ID ( <params> ) <block>"
             << endl;
        indentation++;
        this->resType->print(out);
        this->id->print(out);
        *out << endl;
        *out << string(indentation * 2, ' ')
             << "<paramlist> --> <param>"
             << endl;
        indentation++;
        this->params->print(out);
        indentation--;
        this->block->print(out);
        indentation -= 2;
    }

    // expand the <constdecs> nonterminal
    if (this->next)
    {
        this->next->print(out);
    }
}

void NMethDecl::addSymbols(SymbolTree *node)
{
    string value = "method_type " + this->resType->getType() + " <- " + this->params->getMangling();
    node->registerSymbolWithValue(this->id->getSymbol(), value);
    SymbolTree *child = new SymbolTree();
    node->setChild(child);
    child->setParent(node);
    this->block->addSymbols(child);
    if (this->next)
    {
        auto *derivedCons = dynamic_cast<NConstDecl *>(this->next);
        auto *derivedMeth = dynamic_cast<NMethDecl *>(this->next);

        if (derivedCons)
        {
            derivedCons->addSymbols(node);
        }
        else if (derivedMeth)
        {
            derivedMeth->addSymbols(node);
        }
    }
}