/*
 * block.hpp
 * Andey Robins
 * 12/2/22
 * Compilers Program 6
 *
 * Declarations for various block related structs
 *
 */

#ifndef BLOCK_HPP
#define BLOCK_HPP

#include "statements.hpp"

class NVarDecl : public BaseNode
{
public:
    NVarDecl(NType *t, NId *id);
    ~NVarDecl();
    virtual void print(ostream *out = 0);
    void typecheck(SymbolTree *node);

private:
    NType *type;
    NId *id;
};

class NLocalVarDecl : public BaseNode
{
public:
    NLocalVarDecl(NVarDecl *vd);
    virtual void print(ostream *out = 0);
    void typecheck(SymbolTree *node);

private:
    NVarDecl *vd;
};

class NBlock : public BaseNode
{
public:
    NBlock(NLocalVarDecl *vd);
    NBlock(NStatement *s);
    virtual void print(ostream *out = 0);
    void typecheck(SymbolTree *node);
};

#endif