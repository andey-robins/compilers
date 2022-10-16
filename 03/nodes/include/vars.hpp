/*
 * vars.hpp
 * Andey Robins
 * 10/16/22
 * Compilers Program 3
 *
 * Definitions for the AST of all vardec nodes
 */
#include "node.hpp"

class NodeVarTypeId : public Node
{
public:
    NodeVarTypeId(Node *nt, string id);
    virtual void print(ostream *out);
};

class NodeVarIdId : public Node
{
public:
    NodeVarIdId(string id1, string id2);
    virtual void print(ostream *out);
};

class NodeVarTypeMult : public Node
{
public:
    NodeVarTypeMult(Node *nt, Node *mb, string id);
    virtual void print(ostream *out);
};

class NodeVarIdMult : public Node
{
public:
    NodeVarIdMult(string id1, Node *mb, string id2);
    virtual void print(ostream *out);
};