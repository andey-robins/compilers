/*
 * struct.cpp
 * Andey Robins
 * 12/2/22
 * Compilers Program 6
 *
 * Implementation of program class
 *
 */

#include "../include/nodes.hpp"

int indentation = 0;

NProgram::NProgram(NClassDecl *cd)
{
    this->classDeclaration = cd;
}

NProgram::~NProgram()
{
    delete this->classDeclaration;
}

void NProgram::print(ostream *out)
{
    *out << "<program> -> <classdec>" << endl;
    indentation = 1;
    this->classDeclaration->print(out);
    indentation = 0;
}

void NProgram::typecheck(SymbolTree *node)
{
    this->classDeclaration->typecheck(node);
}