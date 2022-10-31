/*
 * expressions.hpp
 * Andey Robins
 * 10/20/22
 * Compilers Program 4
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
    NNewExpIdArgs(NId *i, LArgs *l);
    virtual void print();
};

class NNewExpType : public NNewExp
{
public:
    NNewExpType(NSimpleType *s, LBrackExps *be, LBracks *b);
    virtual void print();
};

// ^^^
// new expressions
//
// expressions
// vvv

class NExp : public BaseNode
{
public:
    virtual void print();
};

// A maybe monad adapted to hold an optional expression
class NOptExp : public NExp
{
public:
    NOptExp();
    NOptExp(NExp *e);
    virtual void print();
    bool maybe();

protected:
    NExp *e;
};

class NExpName : public NExp
{
public:
    NExpName(NName *n);
    virtual void print();
};

class NExpNumber : public NExp
{
public:
    NExpNumber(NNumber *n);
    virtual void print();
};

class NExpNull : public NExp
{
public:
    NExpNull(NKeyword *k);
    virtual void print();
};

class NExpCall : public NExp
{
public:
    NExpCall(NName *n, LArgs *l);
    virtual void print();
};

class NExpRead : public NExp
{
public:
    NExpRead(NKeyword *k);
    virtual void print();
};

class NExpNewExp : public NExp
{
public:
    NExpNewExp(NNewExp *ne);
    virtual void print();
};

class NPrefixExp : public NExp
{
public:
    NPrefixExp(NOperator *o, NExp *e);
    virtual void print();
};

class NInfixExp : public NExp
{
public:
    NInfixExp(NOperator *o, NExp *left, NExp *right);
    ~NInfixExp();
    virtual void print();

private:
    NOperator *op;
    NExp *left;
    NExp *right;
};

class NParenExp : public NExp
{
public:
    NParenExp(NExp *inner);
    virtual void print();
};

class NNameExp : public NName
{
public:
    NNameExp(NName *n, NExp *e);
    virtual void print();
};

#endif