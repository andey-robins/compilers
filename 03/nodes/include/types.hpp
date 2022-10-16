#include "node.hpp"

class NodeSimpleType : public Node
{
public:
    NodeSimpleType(string s);
    virtual void print(ostream *out = 0);
};

class NodeType : public Node
{
public:
    NodeType(NodeSimpleType *st = 0);
    virtual void print(ostream *out = 0);
};