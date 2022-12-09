/*
 * declarations.cpp
 * Andey Robins
 * 12/2/22
 * Compilers Program 6
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
    // cout << "class decl" << endl;
    // cout << this->className->getSymbol() << endl;
    // in this context, node == root
    node->registerSymbolWithValue(this->className->getSymbol(), "class_type");
    SymbolTree *child = new SymbolTree();
    node->setChild(child);
    child->setParent(node);
    if (this->classBody)
    {
        this->classBody->addSymbols(child);
    }

    // continue to next class declaration
    auto *derivedNext = dynamic_cast<NClassDecl *>(this->next);
    if (derivedNext)
    {
        static_cast<NClassDecl *>(this->next)->addSymbols(node);
    }
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
    string value = "constructor_type <- " + this->params->getMangling();
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
    // check if method is main for type checking
    if (this->id->getSymbol() == "main")
    {
        if (node->lookupSymbol("main") != "")
        {
            cout << endl
                 << "Semantic Error: main already declared"
                 << endl
                 << "---------------------"
                 << endl
                 << "| previous declaration has type: "
                 << endl
                 << "| "
                 << node->lookupSymbol("main")
                 << endl
                 << "|"
                 << endl
                 << "| discarding previous declaration."
                 << endl
                 << "| if this is not the desired behavior, eliminate the latter declaration(s)."
                 << endl
                 << "---------------------"
                 << endl;
        }

        if (!(this->resType->getType() == "void" || this->resType->getType() == "int"))
        {
            cout << endl
                 << "Semantic Error: invalid return type for main"
                 << endl
                 << "---------------------"
                 << endl
                 << "| main has declared return type: "
                 << endl
                 << "| "
                 << this->resType->getType()
                 << endl
                 << "|"
                 << endl
                 << "| expected type to be int or void"
                 << endl
                 << "---------------------"
                 << endl;
        }

        if (this->params->getMangling() != "void")
        {
            cout << endl
                 << "Semantic Error: function main takes no arguments"
                 << endl
                 << "---------------------"
                 << endl
                 << "| main has declared parameter types: "
                 << endl
                 << "| "
                 << this->params->getMangling()
                 << endl
                 << "|"
                 << endl
                 << "| expected no parameters"
                 << endl
                 << "---------------------"
                 << endl;
        }
    }

    // put method in symbol table
    string value = "method_type " + this->resType->getType() + " <- " + this->params->getMangling();
    node->registerSymbolWithValue(this->id->getSymbol(), value);
    // create the sub-table for the method's internal scope
    SymbolTree *child = new SymbolTree();
    child->getTable()->registerSymbolWithValue("method_type", this->resType->getType());
    node->setChild(child);
    child->setParent(node);

    this->params->addSymbols(child);
    this->block->addSymbols(child);

    // continue adding next set of symbols to the table
    if (this->next)
    {
        auto *derivedMeth = dynamic_cast<NMethDecl *>(this->next);

        if (derivedMeth)
        {
            derivedMeth->addSymbols(node);
        }
    }
}