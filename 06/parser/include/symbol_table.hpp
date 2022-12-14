/*
 * symbol_table.hpp
 * Andey Robins
 * 12/2/22
 * Compilers Program 6
 *
 * Defines the SymbolTable class
 */

#ifndef SYMBOL_TABLE_HPP
#define SYMBOL_TABLE_HPP

#include "parser.hpp"

class Value;

class SymbolTable
{
public:
    SymbolTable();
    virtual ~SymbolTable();
    void registerSymbol(string symbol);
    void registerSymbolWithValue(string symbol, string val);
    string lookupSymbol(string symbol);
    void print();

private:
    std::map<string, string> *symbols;
};

#endif