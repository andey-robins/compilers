/*
 * struct.cpp
 * Andey Robins
 * 10/20/22
 * Compilers Program 4
 *
 *
 */

#include "nodes.hpp"

NProgram::NProgram(NClassDecl *cd)
{
    this->classDeclaration = cd;
}

NProgram::~NProgram()
{
    delete this->classDeclaration;
}

void NProgram::print()
{
    cout << "<program> -> <classdec>" << endl;
    indentation = 1;
    this->classDeclaration->print();
    indentation = 0;
}