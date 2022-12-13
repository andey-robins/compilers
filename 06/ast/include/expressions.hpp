/*
 * expressions.hpp
 * Andey Robins
 * 12/2/22
 * Compilers Program 6
 *
 *
 */

#ifndef EXPRESSIONS_HPP
#define EXPRESSIONS_HPP

#include "name.hpp"

class NNewExp : public BaseNode
{
};

class NNewExpIdArgs : public NNewExp
{
public:
    NNewExpIdArgs(NId *i, NArg *a);
    ~NNewExpIdArgs();
    virtual void print(ostream *out = 0);

private:
    NId *id;
    NArg *args;
};

class NNewExpType : public NNewExp
{
public:
    NNewExpType(NSimpleType *s, NBrackExps *bes, NBracks *bs);
    NNewExpType(NSimpleType *s, NBrackExps *bes);
    NNewExpType(NSimpleType *s, NBracks *bs);
    NNewExpType(NSimpleType *s);
    ~NNewExpType();
    virtual void print(ostream *out = 0);

private:
    NSimpleType *t;
    NBrackExps *bes;
    NBracks *bs;
};

// ^^^
// new expressions
//
// expressions
// vvv

class NExp : public BaseNode
{
public:
    virtual void print(ostream *out = 0);
    void typecheck(SymbolTree *node);
};

// A maybe monad adapted to hold an optional expression
class NOptExp : public NExp
{
public:
    NOptExp();
    NOptExp(NExp *e);
    virtual void print(ostream *out = 0);
    bool maybe();

protected:
    NExp *e;
};

// class NExpName : public NExp
// {
// public:
//     NExpName(NName *n);
//     virtual void print(ostream *out = 0);
// };

// class NExpNumber : public NExp
// {
// public:
//     NExpNumber(NNumber *n);
//     virtual void print(ostream *out = 0);
// };

class NExpNull : public NExp
{
public:
    NExpNull();
    virtual void print(ostream *out = 0);
};

class NExpCall : public NExp
{
public:
    NExpCall(NName *n, NArg *a);
    ~NExpCall();
    virtual void print(ostream *out = 0);

private:
    NName *name;
    NArg *args;
};

class NExpRead : public NExp
{
public:
    NExpRead();
    virtual void print(ostream *out = 0);
    void typecheck(SymbolTree *node);
};

class NExpNewExp : public NExp
{
public:
    NExpNewExp(NNewExp *ne);
    ~NExpNewExp();
    virtual void print(ostream *out = 0);
    void typecheck(SymbolTree *node);

private:
    NNewExp *newExp;
};

class NPrefixExp : public NExp
{
public:
    NPrefixExp(NOperator *o, NExp *e);
    ~NPrefixExp();
    virtual void print(ostream *out = 0);

private:
    NOperator *op;
    NExp *exp;
};

class NInfixExp : public NExp
{
public:
    NInfixExp(NOperator *o, NExp *left, NExp *right);
    ~NInfixExp();
    virtual void print(ostream *out = 0);
    void typecheck(SymbolTree *node);

private:
    NOperator *op;
    NExp *left;
    NExp *right;
};

class NParenExp : public NExp
{
public:
    NParenExp(NExp *inner);
    ~NParenExp();
    virtual void print(ostream *out = 0);

private:
    NExp *in;
};

// class NNameExp : public NName
// {
// public:
//     NNameExp(NName *n, NExp *e);
//     virtual void print(ostream *out = 0);
// };

#endif