/*
 * scope.cpp
 * Andey Robins
 * 12/2/22
 * Compilers Program 6
 *
 * A generic scope wrapper which can create individual scopes.
 * Overruled by the SymbolTree class
 */

#include "../include/parser.hpp"

int symbolIndentation = 0;

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
    cout << "trying" << endl;
    cout << (*this->scopeStack).top() << endl;
    cout << (*this->scopeStack).top();
}
void Scope::registerGlobalSymbolWithValue(string symbol, Value *val)
{
}

void Scope::print()
{
    cout << "scope print" << endl;
    if ((*this->scopeStack).top())
    {
        (*this->scopeStack).top()->print();
    }
}