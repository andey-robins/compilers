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

class LStatements : public BaseList
{
public:
    LStatements();
    virtual void print(ostream *out = 0);
};

class NStatement : public BaseNode
{
};

class NStateAssign : public NStatement
{
public:
    NStateAssign(NName *n, NExp *e);
    virtual void print(ostream *out);
};

class NStateCall : public NStatement
{
public:
    NStateCall(NName *n, LArgs *a);
    virtual void print(ostream *out);
};

class NStatePrint : public NStatement
{
public:
    NStatePrint(LArgs *a);
    virtual void print(ostream *out);
};

class NStateCond : public NStatement
{
public:
    NStateCond(NCondition *c);
    virtual void print(ostream *out);
};

class NStateWhile : public NStatement
{
public:
    NStateWhile(NExp *e, NStatement *s);
    virtual void print(ostream *out);
};

class NStateReturn : public NStatement
{
public:
    NStateReturn(NOptExp *oe);
    virtual void print(ostream *out);
};

class NCondition : public NStatement
{
public:
    NCondition(NExp *e, NStatement *s);
    NCondition(NExp *e, NStatement *trueStmt, NStatement *falseStmt);
    virtual void print(ostream *out);

protected:
    NStatement *trueBlock;
    NStatement *falseBlock;
};

#endif