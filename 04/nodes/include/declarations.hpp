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

class NClassDecl : public BaseNode
{
public:
    NClassDecl(NKeyword *cls, NId *id, NClassBody *cb);
    virtual void print();
};

class LVarDecl : public BaseList
{
public:
    LVarDecl();
    virtual void print();
};

class LLocalVarDecl : public LVarDecl
{
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

#endif