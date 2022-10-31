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

NMethDecl::NMethDecl(NResultType *rt, NId *id, NParam *p, NBlock *b)
{
    this->resType = rt;
    this->id = id;
    this->params = p;
    this->block = b;
}

void NMethDecl::print()
{
    cout << string(indentation * 2, ' ')
         << "<methdecs> --> <methdecs> <methdec>"
         << endl;
    indentation++;
    if (this->params->getText() == "epsilon")
    {
        cout << string(indentation * 2, ' ')
             << "<methdec> --> <resulttype> ID () <block>"
             << endl;
        indentation++;
        this->resType->print();
        this->id->print();
        this->block->print();
        indentation -= 2;
    }
    else
    {
        cout << string(indentation * 2, ' ')
             << "<methdec> --> <resulttype> ID ( <params> ) <block>"
             << endl;
        indentation++;
        this->resType->print();
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
