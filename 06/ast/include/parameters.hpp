/*
 * parameters.hpp
 * Andey Robins
 * 12/2/22
 * Compilers Program 6
 *
 *
 */

#ifndef PARAMETERS_HPP
#define PARAMETERS_HPP

#include "type.hpp"

class NExp;

class NParam : public BaseNode
{
public:
    NParam(NType *t, NId *id);
    virtual void print(ostream *out = 0);
    string getMangling();
    void addSymbols(SymbolTree *node);

private:
    NType *type;
    NId *id;
};

class NArg : public BaseNode
{
public:
    NArg(NExp *e);
    ~NArg();
    virtual void print(ostream *out = 0);

private:
    NExp *e;
};

class NBracks : public BaseNode
{
public:
    NBracks(int count);
    int getCount();
    virtual void print(ostream *out = 0);

private:
    int count;
};

// Subsequent bracket expressions should be in this->next
class NBrackExps : public BaseNode
{
public:
    NBrackExps(NExp *e);
    ~NBrackExps();
    virtual void print(ostream *out = 0);
    void printType(ostream *out = 0, bool printEndline = true);
    void printExpression(ostream *out = 0);

private:
    NExp *exp;
};

#endif