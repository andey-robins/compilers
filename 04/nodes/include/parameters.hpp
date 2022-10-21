/*
 * parameters.hpp
 * Andey Robins
 * 10/20/22
 * Compilers Program 4
 *
 *
 */

#ifndef PARAMETERS_HPP
#define PARAMETERS_HPP

#include "nodes.hpp"

class LParams : public BaseList
{
public:
    LParams();
    virtual void print(ostream *out);
};

class NParam : public BaseNode
{
public:
    NParam(NType *t, NId *id);
    virtual void print(ostream *out);
};

class LArgs : public BaseList
{
public:
    LArgs();
    virtual void print(ostream *out);
};

#endif