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

#include "parameters.hpp"

class NName : public BaseNode
{
};

class NNameThis : public NName
{
public:
    NNameThis();
    virtual void print();
};

class NNameThisDot : public NName
{
public:
    NNameThisDot(NName *next);
    virtual void print();
};

class NNameId : public NName
{
public:
    NNameId(NId *id);
    NNameId(NId *id, NBrackExps *be);
    ~NNameId();
    virtual void print();

private:
    NBrackExps *be;
};

class NNameDotId : public NName
{
public:
    NNameDotId(NId *id, NName *n);
    virtual void print();

private:
    NId *id;
};

#endif