/*
 * declarations.hpp
 * Andey Robins
 * 10/20/22
 * Compilers Program 4
 *
 *  Declaration related class implementations
 *  Used for class, method, var, and constructor declarations
 */

#ifndef DECLARATIONS_HPP
#define DECLARATIONS_HPP

#include "block.hpp"

class NConstDecl : public BaseNode
{
public:
    NConstDecl(NId *id, NParam *p, NBlock *b);
    virtual void print();

private:
    NId *id;
    NParam *params;
    NBlock *block;
};

class NMethDecl : public BaseNode
{
public:
    NMethDecl(NResultType *rt, NId *id, NParam *p, NBlock *b);
    virtual void print();

private:
    NResultType *resType;
    NId *id;
    NParam *params;
    NBlock *block;
};

class NClassBody : public BaseNode
{
public:
    // declarations are tracked in NClassBody->next
    NClassBody(NVarDecl *declHead);
    NClassBody(NConstDecl *declHead);
    NClassBody(NMethDecl *declHead);
    ~NClassBody();
    virtual void print();
};

class NClassDecl : public BaseNode
{
public:
    NClassDecl(NId *id, NClassBody *cb);
    ~NClassDecl();
    virtual void print();

private:
    NId *className;
    NClassBody *classBody;
};

#endif