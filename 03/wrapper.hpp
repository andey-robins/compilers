/*
 * wrapper.hpp
 * Andey Robins
 * 10/15/22
 * Compilers Program 3
 *
 * Definitions for the AST of all wrapper nodes
 */

#include "node.hpp"

// NodeBracketExp is the most generic version of a bracketed expression
class NodeBracketExp : public Node
{
public:
    NodeBracketExp(NodeBracketExp *nn);
    NodeBracketExp(NodeEpsilon *ne);
    virtual void print(ostream *out = 0);
};

// NodeMultiBrack is a class for holding a sequence of empty brackets
class NodeMultiBrack : public Node
{
public:
    NodeMultiBrack();
    virtual void print(ostream *out = 0);
};