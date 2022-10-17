/*
 * types.hpp
 * Andey Robins
 * 10/15/22
 * Compilers Program 3
 *
 * Definitions for the AST of all type nodes
 */

#include "node.hpp"

// NodeSimpleType is the only type used in this version of the program
// Always holds the "int" type
class NodeSimpleType : public Node
{
public:
    NodeSimpleType(string s);
    virtual void print(ostream *out = 0);
};

// NodeType is the root node for all type based productions
class NodeType : public Node
{
public:
    NodeType(NodeSimpleType *st = 0);
    virtual void print(ostream *out = 0);
};

// Epsilon is an empty node used to provide left refactoring for
// grammar
class NodeEpsilon : public Node
{
public:
    NodeEpsilon();
    virtual void print(ostream *out = 0);
};