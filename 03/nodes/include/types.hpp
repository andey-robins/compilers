/*
 * types.hpp
 * Andey Robins
 * 10/15/22
 * Compilers Program 3
 *
 * Definitions for the AST of all type nodes
 */

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

class NodeEpsilon : public Node
{
public:
    NodeEpsilon();
    virtual void print(ostream *out = 0);
};