#include "../include/parser.hpp"

SymbolTree::SymbolTree()
{
    this->parent = 0;
    std::list<SymbolTree *> *childrenPt = new std::list<SymbolTree *>;
    this->children = childrenPt;
    this->table = new SymbolTable();
}

void SymbolTree::setParent(SymbolTree* parent)
{
    this->parent = parent;
}

void SymbolTree::setChild(SymbolTree* child)
{
    (*this->children).push_back(child);
}

void SymbolTree::registerSymbol(string symbol)
{
    this->table->registerSymbol(symbol);
}

void SymbolTree::registerSymbolWithValue(string symbol, string val)
{
    this->table->registerSymbolWithValue(symbol, val);
}

string SymbolTree::lookupSymbol(string symbol)
{
    // TODO big time
    return 0;
}

void SymbolTree::print()
{
    this->table->print();
    symbolIndentation++;
    for (auto it = (*this->children).begin(); it != (*this->children).end(); ++it)
    {
        auto child = (*it);
        child->print();
    }
    symbolIndentation--;
}