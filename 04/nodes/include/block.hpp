#ifndef BLOCK_HPP
#define BLOCK_HPP

#include "nodes.hpp"

class LLocalVarDecl : public BaseList
{
public:
    LLocalVarDecl();
    virtual void print();
};

class NBlock : public BaseNode
{
public:
    NBlock(LLocalVarDecl *lvd, LStatements *s);
    virtual void print();
};

#endif