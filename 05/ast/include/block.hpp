#ifndef BLOCK_HPP
#define BLOCK_HPP

#include "statements.hpp"

class NVarDecl : public BaseNode
{
public:
    NVarDecl(NType *t, NId *id);
    ~NVarDecl();
    virtual void print(ostream *out = 0);

private:
    NType *type;
    NId *id;
};

class NLocalVarDecl : public BaseNode
{
public:
    NLocalVarDecl(NVarDecl *vd);
    virtual void print(ostream *out = 0);

private:
    NVarDecl *vd;
};

class NBlock : public BaseNode
{
public:
    NBlock(NLocalVarDecl *vd);
    NBlock(NStatement *s);
    virtual void print(ostream *out = 0);
};

#endif