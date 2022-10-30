/*
 * struct.hpp
 * Andey Robins
 * 10/20/22
 * Compilers Program 4
 *
 *
 */

#include "nodes.hpp"
#include "leaves.hpp"
#include "list-base.hpp"

#ifndef STRUCT_HPP
#define STRUCT_HPP

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