/*
 * expression.hpp
 * Andey Robins
 * 10/15/22
 * Compilers Program 3
 *
 * Definitions for the AST of all expression nodes
 */
#include "node.hpp"

// Include name here in expressions until it fits in a better area
class NodeName : public Node
{
public:
    NodeName(string s);
    NodeName(NodeName *nn, string id);
    virtual void print(ostream *out = 0);
};

// New Expressions
class NodeNewExp : public Node
{
public:
    NodeNewExp(string id);
    NodeNewExp(NodeType *nt);
    virtual void print(ostream *out = 0);
};

class NodeNewExpType : public Node
{
public:
    NodeNewExpType(NodeType *nt);
    virtual void print(ostream *out = 0);
};

class NodeNewExpTypeBrack : public Node
{
public:
    NodeNewExpTypeBrack(NodeType *nt, Node *nb);
    virtual void print(ostream *out = 0);
};

class NodeNewExpIdBrack : public Node
{
public:
    NodeNewExpIdBrack(string id, Node *nb);
    virtual void print(ostream *out = 0);
};

class NodeNewTypeBrackMult : public Node
{
public:
    NodeNewTypeBrackMult(NodeType *nt, Node *nb, Node *mb);
    virtual void print(ostream *out = 0);
};

class NodeNewIdBrackMult : public Node
{
public:
    NodeNewIdBrackMult(string id, Node *nb, Node *mb);
    virtual void print(ostream *out = 0);
};

// Expressions
class NodeExp : public Node
{
public:
    NodeExp(Node *n = 0);
    virtual void print(ostream *out = 0);
};

class NodeCallExp : public Node
{
public:
    NodeCallExp(NodeName *nn = 0);
    virtual void print(ostream *out = 0);
};

class NodeInfixExp : public Node
{
public:
    NodeInfixExp(Node *ln, Node *rn, string op);
    virtual void print(ostream *out = 0);
};

class NodePrefixExp : public Node
{
public:
    NodePrefixExp(string op, Node *n);
    virtual void print(ostream *out = 0);
};