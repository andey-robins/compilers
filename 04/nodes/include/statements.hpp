/*
 * statement.hpp
 * Andey Robins
 * 10/20/22
 * Compilers Program 4
 *
 *
 */

#include "list-base.hpp"
#include "nodes.hpp"

#ifndef STATEMENTS_HPP
#define STATEMENTS_HPP

class LStatements : public BaseList
{
public:
    LStatements();
    virtual void print();
};

class NStatement : public BaseNode
{
};

class NStateAssign : public NStatement
{
public:
    NStateAssign(NName *n, NExp *e);
    virtual void print();
};

class NStateCall : public NStatement
{
public:
    NStateCall(NName *n, LArgs *a);
    virtual void print();
};

class NStatePrint : public NStatement
{
public:
    NStatePrint(LArgs *a);
    virtual void print();
};

class NStateWhile : public NStatement
{
public:
    NStateWhile(NExp *e, NStatement *s);
    virtual void print();
};

class NStateReturn : public NStatement
{
public:
    NStateReturn(NOptExp *oe);
    virtual void print();
};

class NCondition : public NStatement
{
public:
    NCondition(NExp *e, NStatement *s);
    NCondition(NExp *e, NStatement *trueStmt, NStatement *falseStmt);
    virtual void print();

protected:
    NStatement *trueBlock;
    NStatement *falseBlock;
};

class NStateCond : public NStatement
{
public:
    NStateCond(NCondition *c);
    virtual void print();
};

#endif