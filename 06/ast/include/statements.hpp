/*
 * statement.hpp
 * Andey Robins
 * 12/2/22
 * Compilers Program 6
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
    void typecheck(SymbolTree *node);
};

class NStateAssign : public NStatement
{
public:
    NStateAssign(NName *n, NExp *e);
    ~NStateAssign();
    virtual void print(ostream *out = 0);
    void typecheck(SymbolTree *node);

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
    void typecheck(SymbolTree *node);

private:
    NName *name;
    NArg *args;
    int argCount;
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
    void typecheck(SymbolTree *node);

private:
    NOptExp *oe;
};

class NStateBlock : public NStatement
{
public:
    NStateBlock(NBlock *b);
    ~NStateBlock();
    virtual void print(ostream *out = 0);
    void typecheck(SymbolTree *node);

private:
    NBlock *block;
};

class NCondition : public NStatement
{
public:
    NCondition(NExp *e, NBlock *s);
    NCondition(NExp *e, NBlock *trueStmt, NBlock *falseStmt);
    ~NCondition();
    virtual void print(ostream *out = 0);
    void typecheck(SymbolTree *node);

protected:
    NExp *cond;
    NBlock *trueBlock;
    NBlock *falseBlock;
};

class NStateCond : public NStatement
{
public:
    NStateCond(NCondition *c);
    ~NStateCond();
    virtual void print(ostream *out = 0);
    void typecheck(SymbolTree *node);

private:
    NCondition *cond;
};

#endif