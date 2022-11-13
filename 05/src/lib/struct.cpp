/*
 * struct.cpp
 * Andey Robins
 * 11/7/22
 * Compilers Program 5
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