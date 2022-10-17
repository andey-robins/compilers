/*
 * expression.hpp
 * Andey Robins
 * 10/15/22
 * Compilers Program 3
 *
 * Definitions for the AST of all expression nodes
 */
#include "node.hpp"

// Name corresponds to the name productions. The constructor is overloaded
// (maybe refactor to not use overloaded constructors?)
// Include name here in expressions until it fits in a better area
class NodeName : public Node
{
public:
    NodeName(string s);
    NodeName(NodeName *nn, string id);
    NodeName(NodeName *nn, Node *nb);
    virtual void print(ostream *out = 0);
};

// New Expressions
// NodeNewExp houses a generic new expression. It's constructor is overloaded
// to allow for whatever new expression layout is appropriate
// perhaps that should be refactored to the many (many) class style of expressions?
class NodeNewExp : public Node
{
public:
    NodeNewExp(string id);
    NodeNewExp(NodeType *nt);
    virtual void print(ostream *out = 0);
};

// The node associated with the production newexp -> NEW simpletype
class NodeNewExpType : public Node
{
public:
    NodeNewExpType(NodeType *nt);
    virtual void print(ostream *out = 0);
};

// The node associated with the production newexp -> NEW simpletype bracketexps
class NodeNewExpTypeBrack : public Node
{
public:
    NodeNewExpTypeBrack(NodeType *nt, Node *nb);
    virtual void print(ostream *out = 0);
};

// The node associated with the production newexp -> NEW ID bracketexps
class NodeNewExpIdBrack : public Node
{
public:
    NodeNewExpIdBrack(string id, Node *nb);
    virtual void print(ostream *out = 0);
};

// The node associated with the production newexp -> NEW simpletype bracketexps multibrackets
class NodeNewTypeBrackMult : public Node
{
public:
    NodeNewTypeBrackMult(NodeType *nt, Node *nb, Node *mb);
    virtual void print(ostream *out = 0);
};

// The node associated with the production newexp -> NEW ID bracketexps multibrackets
class NodeNewIdBrackMult : public Node
{
public:
    NodeNewIdBrackMult(string id, Node *nb, Node *mb);
    virtual void print(ostream *out = 0);
};

// Expressions
// NodeExp is a root node created whenever a generic expression is needed
class NodeExp : public Node
{
public:
    NodeExp(Node *n = 0);
    virtual void print(ostream *out = 0);
};

// NodeCallExp is the node for call expressions like ID()
class NodeCallExp : public Node
{
public:
    NodeCallExp(NodeName *nn = 0);
    virtual void print(ostream *out = 0);
};

// NodeInfixExp keeps track of any infix notation expression
// The operator is stored in the string value of the Node
class NodeInfixExp : public Node
{
public:
    NodeInfixExp(Node *ln, Node *rn, string op);
    virtual void print(ostream *out = 0);
};

// NodePrefixExp keeps track of all prefix expressions
// The operator is stored in the node's string
class NodePrefixExp : public Node
{
public:
    NodePrefixExp(string op, Node *n);
    virtual void print(ostream *out = 0);
};