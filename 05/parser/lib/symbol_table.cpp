/*
 * symbol_table.cpp
 * Andey Robins
 * 11/7/22
 * Compilers Program 5
 *
 * a thin wrapper over std::map
 * 
 */

#include "../include/symbol_table.hpp"

// Symbol Table
SymbolTable::SymbolTable()
{
    std::map<string, string> *syms = new std::map<string, string>();
    this->symbols = syms;
}

SymbolTable::~SymbolTable()
{
    delete this->symbols;
}

void SymbolTable::registerSymbol(string symbol)
{
    (*this->symbols)[symbol] = "";
}

void SymbolTable::registerSymbolWithValue(string symbol, string val)
{
    (*this->symbols)[symbol] = val;
}

// Returns 0 if the symbol is not found. Allows for:
// if (auto symb = table->lookupSymbol(symbol)) { // do something with symb; }
string SymbolTable::lookupSymbol(string symbol)
{
    if ((*this->symbols).find(symbol) != (*this->symbols).end())
    {
        return (*this->symbols)[symbol];
    }

    // tail recursive lookup that moves through more general scopes until terminating when
    // the symbol is found or we hit the root node
    return 0;
}

void SymbolTable::print()
{
    if ((*this->symbols).begin() != (*this->symbols).end())
    {
        // https://stackoverflow.com/questions/14070940/how-can-i-print-out-c-map-values
        // iterate through the keys in a map
        for (auto it = (*this->symbols).begin(); it != (*this->symbols).end(); ++it)
        {
            cout << string(symbolIndentation * 2, ' ')
                 << it->first 
                 << " "
                 << it->second
                 << endl;
        }
    }
}