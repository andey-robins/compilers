#ifndef DECLARATIONS_HPP
#define DECLARATIONS_HPP

#include "nodes.hpp"

class NClassDecl : public BaseNode
{
public:
    NClassDecl(NKeyword *cls, NId *id, NClassBody *cb);
    virtual void print(ostream *out = 0);
};

class LVarDecl : public BaseList
{
public:
    LVarDecl();
    virtual void print(ostream *out = 0);
};

class LLocalVarDecl : public LVarDecl {};

class NVarDecl : public BaseNode
{
public:
    NVarDecl(NType *t, NId *id);
    virtual void print(ostream *out = 0);
};

class LConstDecl : public BaseList
{
public:
    LConstDecl();
    virtual void print(ostream *out = 0);
};

class NConstDecl : public BaseNode
{
public:
    NConstDecl(NId *id, LParams *p, NBlock *b);
    virtual void print(ostream *out);
};

class LMethDecl : public BaseList
{
public:
    LMethDecl();
    virtual void print(ostream *out);
};

class NMethDecl : public BaseNode
{
public:
    NMethDecl(NResultType *rt, NId *id, LParams *p, NBlock *b);
    virtual void print(ostream *out);
};

#endif