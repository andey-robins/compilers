/*
 * type.hpp
 * Andey Robins
 * 12/2/22
 * Compilers Program 6
 *
 * Declaration of type classes
 */

#ifndef TYPES_HPP
#define TYPES_HPP

#include "leaves.hpp"
#include <sstream>

class NBrackExps;

class NSimpleType : public BaseNode
{
public:
    NSimpleType(NKeyword *k); // int keyword
    NSimpleType(NId *id);
    string getType();
    virtual void print(ostream *out = 0);
    void printClipped(ostream *out = 0);
    void printNext(ostream *out = 0);

private:
    bool isId = false;
    string type;
};

class NType : public BaseNode
{
public:
    NType(NSimpleType *st);
    NType(NType *t, int bracks);
    NType(NType *t, NBrackExps *bes);
    int getBracks();
    string getType();
    virtual void print(ostream *out = 0);

private:
    int brackCount;
    NBrackExps *bracketExps;
    string type;
};

class NResultType : public BaseNode
{
public:
    NResultType(NType *t);
    NResultType(NKeyword *k);
    string getType();
    virtual void print(ostream *out = 0);

private:
    NType *type;
    NKeyword *voidType;
};

class NEpsilon : public BaseNode
{
public:
    NEpsilon();
    string getType();
    virtual void print(ostream *out = 0);

private:
    string type;
};

#endif