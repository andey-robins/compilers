/*
 * struct.hpp
 * Andey Robins
 * 11/7/22
 * Compilers Program 5
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
    virtual void print();

private:
    NClassDecl *classDeclaration;
};

#endif