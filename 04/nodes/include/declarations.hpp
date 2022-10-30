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

#include "nodes.hpp"
#include "list-base.hpp"

class LVarDecl : public BaseList
{
public:
    LVarDecl();
    virtual void print();
};

class NVarDecl : public BaseNode
{
public:
    NVarDecl(NType *t, NId *id);
    virtual void print();
};

class LConstDecl : public BaseList
{
public:
    LConstDecl();
    virtual void print();
};

class NConstDecl : public BaseNode
{
public:
    NConstDecl(NId *id, LParams *p, NBlock *b);
    virtual void print();
};

class LMethDecl : public BaseList
{
public:
    LMethDecl();
    virtual void print();
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
    NClassBody(LVarDecl *vd, LConstDecl *cd, LMethDecl *md);
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