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
    virtual void print();
};

class NClassBody : public BaseNode
{
public:
    NClassBody(LVarDecl *vd, LConstDecl *cd, LMethDecl *md);
    virtual void print();
};

class NBlock : public BaseNode
{
public:
    NBlock(LLocalVarDecl *lvd, LStatements *s);
    virtual void print();
};

#endif