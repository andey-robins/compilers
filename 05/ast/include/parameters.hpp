/*
 * parameters.hpp
 * Andey Robins
 * 11/7/22
 * Compilers Program 5
 *
 *
 */

#ifndef PARAMETERS_HPP
#define PARAMETERS_HPP

#include "type.hpp"

class NExp;

// class NParams : public BaseNode
// {
// public:
//     NParams();
//     virtual void print(ostream *out = 0);
// };

class NParam : public BaseNode
{
public:
    NParam(NType *t, NId *id);
    virtual void print(ostream *out = 0);

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

private:
    NExp *exp;
};

#endif