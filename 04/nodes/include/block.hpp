#ifndef BLOCK_HPP
#define BLOCK_HPP

#include "statements.hpp"

class NVarDecl : public BaseNode
{
public:
    NVarDecl(NType *t, NId *id);
    ~NVarDecl();
    virtual void print();

private:
    NType *type;
    NId *id;
};

class NLocalVarDecl : public BaseNode
{
public:
    NLocalVarDecl(NVarDecl *vd);
};

class NBlock : public BaseNode
{
public:
    NBlock(NLocalVarDecl *vd);
    NBlock(NStatement *s);
    virtual void print();
};

#endif