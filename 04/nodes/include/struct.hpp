#ifndef STRUCT_HPP
#define STRUCT_HPP

#include "nodes.hpp"
#include "leaves.hpp"
#include "list-base.hpp"

class NProgram : public BaseNode
{
public:
    NProgram(NClassDecl *cd);
    virtual void print(ostream *out = 0);
};

class NClassBody : public BaseNode
{
public:
    NClassBody(LVarDecl *vd, LConstDecl *cd, LMethDecl *md);
    virtual void print(ostream *out = 0);
};

class NBlock : public BaseNode
{
public:
    NBlock(LLocalVarDecl *lvd, LStatements *s);
    virtual void print(ostream *out);
};

#endif