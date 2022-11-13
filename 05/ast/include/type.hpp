/*
 * type.hpp
 * Andey Robins
 * 11/7/22
 * Compilers Program 5
 *
 *
 */

#ifndef TYPES_HPP
#define TYPES_HPP

#include "leaves.hpp"

class NSimpleType : public BaseNode
{
public:
    NSimpleType(NKeyword *k); // int keyword
    NSimpleType(NId *id);
    string getType();
    virtual void print(ostream *out = 0);

private:
    bool isId = false;
    string type;
};

class NType : public BaseNode
{
public:
    NType(NSimpleType *st);
    NType(NType *t, int bracks);
    int getBracks();
    string getType();
    virtual void print(ostream *out = 0);

private:
    int brackCount;
    string type;
};

class NResultType : public BaseNode
{
public:
    NResultType(NType *t);
    NResultType(NKeyword *k);
    virtual void print(ostream *out = 0);

private:
    NType *type;
    NKeyword *voidType;
};

class NEpsilon : public BaseNode
{
public:
    NEpsilon();
    virtual void print(ostream *out = 0);
};

#endif