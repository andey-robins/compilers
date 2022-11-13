/*
 * symbol_table.hpp
 * Andey Robins
 * 11/7/22
 * Compilers Program 5
 *
 */

#ifndef SYMBOL_TABLE_HPP
#define SYMBOL_TABLE_HPP

#include "parser.hpp"

class Value;

class SymbolTable
{
public:
    SymbolTable(SymbolTable *prev);
    virtual ~SymbolTable();
    void registerSymbol(string symbol);
    void registerSymbolWithValue(string symbol, Value *val);
    Value *lookupSymbol(string symbol);
    void print();

private:
    SymbolTable *prev;
    std::map<string, Value *> *symbols;
};

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
    Value *lookupSymbol(string symbol);
    void print();

private:
    std::stack<SymbolTable *> *scopeStack;
};

#endif