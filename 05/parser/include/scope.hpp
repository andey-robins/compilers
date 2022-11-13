/*
 * scope.hpp
 * Andey Robins
 * 11/7/22
 * Compilers Program 5
 *
 */

#ifndef SCOPE_HPP
#define SCOPE_HPP

#include "parser.hpp"

class SymbolTable;

class Scope
{
public:
    Scope(SymbolTable *rootTable);
    virtual ~Scope();
    void push(SymbolTable *tab);
    SymbolTable *peek();
    SymbolTable *pop();
    void registerSymbol(string symbol);
    void registerSymbolWithValue(string symbol, Value *val);
    void registerGlobalSymbolWithValue(string symbol, Value *val);
    Value *lookupSymbol(string symbol);
    void print();

private:
    std::stack<SymbolTable *> *scopeStack;
};

#endif