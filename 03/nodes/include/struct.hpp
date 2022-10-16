/*
 * struct.hpp
 * Andey Robins
 * 10/15/22
 * Compilers Program 3
 *
 * Definitions for the AST of all struct nodes (statement adjacent nodes)
 */

#include "node.hpp"

class NodeVarDec : public Node
{
public:
    NodeVarDec(string id1, string id2);
    virtual void print(ostream *out = 0);
};

class NodeElement : public Node
{
public:
    NodeElement(NodeExp *e);
    virtual void print(ostream *out = 0);
};

class NodeProgram : public Node
{
public:
    NodeProgram(NodeElement *e);
    virtual void print(ostream *out = 0);
};

class NodeOptProgram : public Node
{
public:
    NodeOptProgram(NodeElement *e);
    virtual void print(ostream *out = 0);
};