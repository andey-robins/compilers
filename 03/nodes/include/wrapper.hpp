/*
 * wrapper.hpp
 * Andey Robins
 * 10/15/22
 * Compilers Program 3
 *
 * Definitions for the AST of all wrapper nodes
 */

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