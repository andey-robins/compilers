/*
 * struct.hpp
 * Andey Robins
 * 10/20/22
 * Compilers Program 4
 *
 *  Structural nodes for the AST. Only the Program node
 *  currently, though other language structure productions
 *  and nodes could find their home here eventually
 */

#ifndef STRUCT_HPP
#define STRUCT_HPP

#include "declarations.hpp"

class NProgram : public BaseNode
{
public:
    NProgram(NClassDecl *cd);
    ~NProgram();
    virtual void print();

private:
    NClassDecl *classDeclaration;
};

#endif