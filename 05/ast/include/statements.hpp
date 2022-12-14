/*
 * statement.hpp
 * Andey Robins
 * 11/7/22
 * Compilers Program 5
 *
 *
 */

#ifndef STATEMENTS_HPP
#define STATEMENTS_HPP

#include "expressions.hpp"

class NBlock;

class NStatement : public BaseNode
{
public:
    virtual void print(ostream *out = 0);
    void addSymbols(SymbolTree *node);
};

class NStateAssign : public NStatement
{
public:
    NStateAssign(NName *n, NExp *e);
    ~NStateAssign();
    virtual void print(ostream *out = 0);

private:
    NName *name;
    NExp *exp;
};

class NStateCall : public NStatement
{
public:
    NStateCall(NName *n, NArg *a);
    ~NStateCall();
    virtual void print(ostream *out = 0);

private:
    NName *name;
    NArg *args;
};

class NStateWhile : public NStatement
{
public:
    NStateWhile(NExp *e, NStatement *s);
    ~NStateWhile();
    virtual void print(ostream *out = 0);

private:
    NExp *e;
    NStatement *s;
};

class NStateReturn : public NStatement
{
public:
    NStateReturn(NOptExp *oe);
    ~NStateReturn();
    virtual void print(ostream *out = 0);

private:
    NOptExp *oe;
};

class NStateBlock : public NStatement
{
public:
    NStateBlock(NBlock *b);
    ~NStateBlock();
    virtual void print(ostream *out = 0);
    void addSymbols();

private:
    NBlock *block;
};

class NCondition : public NStatement
{
public:
    NCondition(NExp *e, NStatement *s);
    NCondition(NExp *e, NStatement *trueStmt, NStatement *falseStmt);
    ~NCondition();
    virtual void print(ostream *out = 0);

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
    virtual void print(ostream *out = 0);

private:
    NCondition *cond;
};

#endif