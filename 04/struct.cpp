/*
 * struct.cpp
 * Andey Robins
 * 10/20/22
 * Compilers Program 4
 *
 *  Structural nodes for the AST. Only the Program node
 *  currently, though other language structure productions
 *  and nodes could find their home here eventually
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