/*
 * symbol_table.cpp
 * Andey Robins
 * 11/7/22
 * Compilers Program 5
 *
 */

#include "../include/symbol_table.hpp"

// Symbol Table
SymbolTable::SymbolTable(SymbolTable *prev)
{
    this->prev = prev;
    std::map<string, Value *> *syms = new std::map<string, Value *>();
    this->symbols = syms;
}

SymbolTable::~SymbolTable()
{
    delete this->symbols;

    // should be unnecessary, included incase the method of modeling prev
    // changes in the future
    this->prev = 0;
    delete this->prev;
}

void SymbolTable::registerSymbol(string symbol)
{
    Value *val = new Value();
    (*this->symbols)[symbol] = val;
}

void SymbolTable::registerSymbolWithValue(string symbol, Value *val)
{
    (*this->symbols)[symbol] = val;
}

// Returns 0 if the symbol is not found. Allows for:
// if (auto symb = table->lookupSymbol(symbol)) { // do something with symb; }
Value *SymbolTable::lookupSymbol(string symbol)
{
    if ((*this->symbols).find(symbol) != (*this->symbols).end())
    {
        return (*this->symbols)[symbol];
    }
    else if (this->prev == 0)
    {
        return 0;
    }

    // tail recursive lookup that moves through more general scopes until terminating when
    // the symbol is found or we hit the root node
    return this->prev->lookupSymbol(symbol);
}

void SymbolTable::print()
{
    cout << " SYMBOL TABLE" << endl
         << "--------------" << endl;
    // https://stackoverflow.com/questions/14070940/how-can-i-print-out-c-map-values
    // iterate through the keys in a map
    for (auto it = (*this->symbols).cbegin(); it != (*this->symbols).cend(); ++it)
    {
        cout << it->first << " " << it->second << endl;
    }
    cout << "END OF TABLE" << endl
         << endl;

    this->prev->print();
}

// Scope
Scope::Scope(SymbolTable *rootTable)
{
    std::stack<SymbolTable *> *map = new std::stack<SymbolTable *>();
    this->scopeStack = map;
    (*this->scopeStack).push(rootTable);
}

Scope::~Scope()
{
    while (!(*this->scopeStack).empty())
    {
        (*this->scopeStack).pop();
    }
    delete this->scopeStack;
}

// The following functions provide thin wrappers around
// the stack for a scope object
void Scope::push(SymbolTable *tab)
{
    (*this->scopeStack).push(tab);
}

SymbolTable *Scope::peek()
{
    return (*this->scopeStack).top();
}

SymbolTable *Scope::pop()
{
    SymbolTable *popped = (*this->scopeStack).top();
    (*this->scopeStack).pop();
    return popped;
}

// The following functions provide thin wrappers for the associated
// methods on the symbol table at the top of the stack
// no iteration/recursion is necessary because the symboltables
// also form a linked list moving from most local scope to
// most global scope and recurse themselves when necessary
void Scope::registerSymbol(string symbol)
{
    (*this->scopeStack).top()->registerSymbol(symbol);
}
void Scope::registerSymbolWithValue(string symbol, Value *val)
{
    (*this->scopeStack).top()->registerSymbolWithValue(symbol, val);
}
Value *Scope::lookupSymbol(string symbol)
{
    return (*this->scopeStack).top()->lookupSymbol(symbol);
}
void Scope::print()
{
    (*this->scopeStack).top()->print();
}