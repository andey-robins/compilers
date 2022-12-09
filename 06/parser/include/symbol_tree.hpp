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