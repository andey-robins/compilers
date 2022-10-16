#include "node.hpp"

class NodeName : public Node
{
public:
    NodeName(string s);
    NodeName(NodeName *nn, string id);
    virtual void print(ostream *out = 0);
};

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