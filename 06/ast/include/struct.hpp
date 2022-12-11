/*
 * struct.hpp
 * Andey Robins
 * 12/2/22
 * Compilers Program 6
 *
 *
 */

#ifndef STRUCT_HPP
#define STRUCT_HPP

#include "declarations.hpp"

class NProgram : public BaseNode
{
public:
    NProgram(NClassDecl *cd);
    ~NProgram();
    virtual void print(ostream *out = 0);
    void typecheck(SymbolTree *node);

private:
    NClassDecl *classDeclaration;
};

#endif