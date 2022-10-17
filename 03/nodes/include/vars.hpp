/*
 * vars.hpp
 * Andey Robins
 * 10/16/22
 * Compilers Program 3
 *
 * Definitions for the AST of all vardec nodes
 */
#include "node.hpp"

// NodeVarTypeId is the class for the production vardec -> type ID
class NodeVarTypeId : public Node
{
public:
    NodeVarTypeId(Node *nt, string id);
    virtual void print(ostream *out);
};

// NodeVarIdId is the class for the production vardec -> ID ID
class NodeVarIdId : public Node
{
public:
    NodeVarIdId(string id1, string id2);
    virtual void print(ostream *out);
};

// NodeVarTypeMult is the node associated with the production vardec -> type multibrackets ID
class NodeVarTypeMult : public Node
{
public:
    NodeVarTypeMult(Node *nt, Node *mb, string id);
    virtual void print(ostream *out);
};

// NodeVarIdMult is the node for the production vardec -> ID multibrackets ID
class NodeVarIdMult : public Node
{
public:
    NodeVarIdMult(string id1, Node *mb, string id2);
    virtual void print(ostream *out);
};