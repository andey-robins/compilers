/*
 * declarations.cpp
 * Andey Robins
 * 10/20/22
 * Compilers Program 4
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

void NClassDecl::print()
{
    cout << string(indentation * 2, ' ')
         << "<classdec> --> CLASS ID <classbody>"
         << endl;
    indentation++;
    this->className->print();
    this->classBody->print();
    indentation--;
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

void NClassBody::print()
{
    cout << string(indentation * 2, ' ')
         << "<classbody> --> { <vardecs> <consdecs> <methdecs> }"
         << endl;
    indentation++;
    if (this->next)
    {
        this->next->print();
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

NConstDecl::NConstDecl(NId *id, NParam *p, NBlock *b)
{
    this->id = id;
    this->params = p;
    this->block = b;
}

void NConstDecl::print()
{
    cout << string(indentation * 2, ' ')
         << "<consdecs> --> <consdecs> <consdec>"
         << endl;
    indentation++;
    if (this->params->getText() == "epsilon")
    {
        cout << string(indentation * 2, ' ')
             << "<consdec> --> ID () <block>"
             << endl;
        indentation++;
        this->id->print();
        this->block->print();
        indentation -= 2;
    }
    else
    {
        cout << string(indentation * 2, ' ')
             << "<consdec> --> ID ( <params> ) <block>"
             << endl;
        indentation++;
        this->id->print();
        cout << string(indentation * 2, ' ')
             << "<paramlist> --> <param>"
             << endl;
        indentation++;
        this->params->print();
        indentation--;
        this->block->print();
        indentation -= 2;
    }

    // expand the <constdecs> nonterminal
    if (this->next)
    {
        this->next->print();
    }
}

NMethDecl::NMethDecl(NResultType *rt, NId *id, LParams *p, NBlock *b)
{
    // TODO
}

void NMethDecl::print()
{
    cout << "Todo NMethDecl" << endl;
}
