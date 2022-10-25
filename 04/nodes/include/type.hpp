/*
 * type.hpp
 * Andey Robins
 * 10/20/22
 * Compilers Program 4
 *
 *
 */

#include "nodes.hpp"
#include "list-base.hpp"

#ifndef TYPES_HPP
#define TYPES_HPP

class NType : public BaseNode
{
public:
    NType(NSimpleType *st);
    NType(NType *t);
    virtual void print();
};

class NSimpleType : public BaseNode
{
public:
    NSimpleType(NKeyword *k); // int keyword
    NSimpleType(NId *id);
    virtual void print();
};

class NResultType : public BaseNode
{
public:
    NResultType(NType *t);
    NResultType(NKeyword *k);
    virtual void print();
};

class NEpsilon : public BaseNode
{
public:
    NEpsilon();
    virtual void print();
};

#endif