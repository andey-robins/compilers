/*
 * symbol_tree.hpp
 * Andey Robins
 * 12/2/22
 * Compilers Program 6
 *
 * Defines the SymbolTree class
 */

#include <list>

class SymbolTree
{
public:
    SymbolTree();
    void setParent(SymbolTree *parent);
    void setChild(SymbolTree *child);
    void registerSymbol(string symbol);
    void registerSymbolWithValue(string symbol, string val);
    string lookupSymbol(string symbol);
    void print();
    SymbolTable *getTable();

private:
    SymbolTree *parent;
    std::list<SymbolTree *> *children;
    SymbolTable *table;
};