#include "node.hpp"

class NodeBracketExp : public Node
{
public:
    NodeBracketExp(NodeBracketExp *nn);
    NodeBracketExp(NodeEpsilon *ne);
    virtual void print(ostream *out = 0);
};

class NodeMultiBrack : public Node
{
public:
    NodeMultiBrack();
    virtual void print(ostream *out = 0);
};