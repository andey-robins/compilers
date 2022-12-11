/*
 * declarations.hpp
 * Andey Robins
 * 12/2/22
 * Compilers Program 6
 *
 *
 */

#ifndef DECLARATIONS_HPP
#define DECLARATIONS_HPP

#include "block.hpp"

class NConstDecl : public BaseNode
{
public:
    NConstDecl(NId *id, NParam *p, NBlock *b);
    NConstDecl(NId *id, NBlock *b);
    virtual void print(ostream *out = 0);
    void typecheck(SymbolTree *node);

private:
    NId *id;
    NParam *params;
    NBlock *block;
};

class NMethDecl : public BaseNode
{
public:
    NMethDecl(NResultType *rt, NId *id, NParam *p, NBlock *b);
    virtual void print(ostream *out = 0);
    void typecheck(SymbolTree *node);

private:
    NResultType *resType;
    NId *id;
    NParam *params;
    NBlock *block;
};

class NClassBody : public BaseNode
{
public:
    // declarations are tracked in NClassBody->next
    NClassBody(NVarDecl *declHead);
    NClassBody(NConstDecl *declHead);
    NClassBody(NMethDecl *declHead);
    ~NClassBody();
    virtual void print(ostream *out = 0);
    void typecheck(SymbolTree *node);
};

class NClassDecl : public BaseNode
{
public:
    NClassDecl(NId *id, NClassBody *cb);
    ~NClassDecl();
    virtual void print(ostream *out = 0);
    void typecheck(SymbolTree *node);

private:
    NId *className;
    NClassBody *classBody;
};

#endif