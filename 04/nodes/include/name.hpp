/*
 * name.hpp
 * Andey Robins
 * 10/20/22
 * Compilers Program 4
 *
 *
 */

#ifndef NAME_HPP
#define NAME_HPP

#include "nodes.hpp"

class NName : public BaseNode
{
};

class NNameThis : public NName
{
public:
    NNameThis();
    virtual void print();
};

class NNameId : public NName
{
public:
    NNameId(NId *id);
    virtual void print();
};

class NNameDotId : public NName
{
public:
    NNameDotId(NName *n, NId *id);
    virtual void print();
};

class NNameExp : public NName
{
public:
    NNameExp(NName *n, NExp *e);
    virtual void print();
};

#endif