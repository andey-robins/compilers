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