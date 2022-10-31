/*
 * statement.hpp
 * Andey Robins
 * 10/20/22
 * Compilers Program 4
 *
 *
 */

#ifndef STATEMENTS_HPP
#define STATEMENTS_HPP

#include "expressions.hpp"

class NBlock;

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
    ~NStateAssign();
    virtual void print();

private:
    NName *name;
    NExp *exp;
};

class NStateCall : public NStatement
{
public:
    NStateCall(NName *n, NArg *a);
    ~NStateCall();
    virtual void print();

private:
    NName *name;
    NArg *args;
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
    ~NStateWhile();
    virtual void print();

private:
    NExp *e;
    NStatement *s;
};

class NStateReturn : public NStatement
{
public:
    NStateReturn(NOptExp *oe);
    ~NStateReturn();
    virtual void print();

private:
    NOptExp *oe;
};

class NStateBlock : public NStatement
{
public:
    NStateBlock(NBlock *b);
    ~NStateBlock();
    virtual void print();

private:
    NBlock *block;
};

class NCondition : public NStatement
{
public:
    NCondition(NExp *e, NStatement *s);
    NCondition(NExp *e, NStatement *trueStmt, NStatement *falseStmt);
    ~NCondition();
    virtual void print();

protected:
    NExp *cond;
    NStatement *trueBlock;
    NStatement *falseBlock;
};

class NStateCond : public NStatement
{
public:
    NStateCond(NCondition *c);
    ~NStateCond();
    virtual void print();

private:
    NCondition *cond;
};

#endif