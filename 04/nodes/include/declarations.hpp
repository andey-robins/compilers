/*
 * declarations.hpp
 * Andey Robins
 * 10/20/22
 * Compilers Program 4
 *
 *
 */

#ifndef DECLARATIONS_HPP
#define DECLARATIONS_HPP

#include "block.hpp"

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

class NConstDecl : public BaseNode
{
public:
    NConstDecl(NId *id, NParam *p, NBlock *b);
    virtual void print();

private:
    NId *id;
    NParam *params;
    NBlock *block;
};

class NMethDecl : public BaseNode
{
public:
    NMethDecl(NResultType *rt, NId *id, LParams *p, NBlock *b);
    virtual void print();
};

class NClassBody : public BaseNode
{
public:
    // declarations are tracked in NClassBody->next
    NClassBody(NVarDecl *declHead);
    NClassBody(NConstDecl *declHead);
    NClassBody(NMethDecl *declHead);
    ~NClassBody();
    virtual void print();
};

class NClassDecl : public BaseNode
{
public:
    NClassDecl(NId *id, NClassBody *cb);
    ~NClassDecl();
    virtual void print();

private:
    NId *className;
    NClassBody *classBody;
};

#endif