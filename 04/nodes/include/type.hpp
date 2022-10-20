#ifndef TYPES_HPP
#define TYPES_HPP

#include "nodes.hpp"
#include "list-base.hpp"

class LType : public BaseList
{
public:
    LType();
    virtual void print(ostream *out);
};

class NType : public BaseNode
{
public:
    NType(NSimpleType *st);
    NType(LType *t);
    virtual void print(ostream *out);
};

class NSimpleType : public BaseNode
{
public:
    NSimpleType(NKeyword *k); // int keyword
    NSimpleType(NId *id);
    virtual void print(ostream *out);
};

class NResultType : public BaseNode
{
public:
    NResultType(NType *t);
    NResultType(NKeyword *k);
    virtual void print(ostream *out);
};

class NEpsilon : public BaseNode
{
public:
    NEpsilon();
    virtual void print(ostream *out);
};

#endif