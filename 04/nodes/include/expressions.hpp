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

#include "nodes.hpp"

class NExp : public BaseNode
{
};

// A maybe monad adapted to hold an optional expression
class NOptExp : public BaseNode
{
public:
    NOptExp();
    NOptExp(NExp *e);
    virtual void print();
    NExp *maybe();

protected:
    bool isEmpty;
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
    virtual void print();
};

class NParenExp : public NExp
{
public:
    NParenExp(NExp *inner);
    virtual void print();
};

// ^^^
// expressions
// 
// new expressions
// vvv

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

#endif