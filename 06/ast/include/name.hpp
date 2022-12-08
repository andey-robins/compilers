/*
 * name.hpp
 * Andey Robins
 * 12/2/22
 * Compilers Program 6
 *
 *
 */

#ifndef NAME_HPP
#define NAME_HPP

#include "parameters.hpp"

class NName : public BaseNode
{
public:
    void addSymbols(SymbolTree *node);
    string getSupertype();
};

class NNameThis : public NName
{
public:
    NNameThis();
    virtual void print(ostream *out = 0);
    void addSymbols(SymbolTree *node);
};

class NNameThisDot : public NName
{
public:
    NNameThisDot(NName *next);
    virtual void print(ostream *out = 0);
    void addSymbols(SymbolTree *node);
};

class NNameId : public NName
{
public:
    NNameId(NId *id);
    NNameId(NId *id, NBrackExps *be);
    ~NNameId();
    virtual void print(ostream *out = 0);
    void addSymbols(SymbolTree *node);

private:
    NBrackExps *be;
};

class NNameDotId : public NName
{
public:
    NNameDotId(NId *id, NName *n);
    virtual void print(ostream *out = 0);
    void addSymbols(SymbolTree *node);

private:
    NId *id;
};

#endif