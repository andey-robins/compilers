/*
 * type.hpp
 * Andey Robins
 * 10/20/22
 * Compilers Program 4
 *
 *
 */

#ifndef TYPES_HPP
#define TYPES_HPP

#include "leaves.hpp"
#include "list-base.hpp"

class NSimpleType : public BaseNode
{
public:
    NSimpleType(NKeyword *k); // int keyword
    NSimpleType(NId *id);
    virtual void print();

private:
    bool isId = false;
};

class NType : public BaseNode
{
public:
    NType(NSimpleType *st);
    NType(NType *t, int bracks);
    int getBracks();
    virtual void print();

private:
    int brackCount;
};

class NResultType : public BaseNode
{
public:
    NResultType(NType *t);
    NResultType(NKeyword *k);
    virtual void print();

private:
    NType *type;
    NKeyword *voidType;
};

class NEpsilon : public BaseNode
{
public:
    NEpsilon();
    virtual void print();
};

#endif