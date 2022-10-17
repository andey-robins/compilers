/*
 * struct.hpp
 * Andey Robins
 * 10/15/22
 * Compilers Program 3
 *
 * Definitions for the AST of all struct nodes (statement adjacent nodes)
 */

#include "node.hpp"

// NodeElement is the element sub-production of program
class NodeElement : public Node
{
public:
    NodeElement(NodeExp *e);
    virtual void print(ostream *out = 0);
};

// NodeProgram is the highest level node
// Contains the node for the
class NodeProgram : public Node
{
public:
    NodeProgram(NodeElement *e);
    virtual void print(ostream *out = 0);
};

// NodeOptProgram allows for sequential versions of a program
class NodeOptProgram : public Node
{
public:
    NodeOptProgram(NodeElement *e);
    virtual void print(ostream *out = 0);
};