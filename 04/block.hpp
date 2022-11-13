/*
 * declarations.hpp
 * Andey Robins
 * 10/20/22
 * Compilers Program 4
 *
 * Class declarations and definitions for block related AST
 * nodes such as Block and LocalVarDeclarations
 */

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
    virtual void print();

private:
    NVarDecl *vd;
};

class NBlock : public BaseNode
{
public:
    NBlock(NLocalVarDecl *vd);
    NBlock(NStatement *s);
    virtual void print();
};

#endif