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
