#ifndef NODES_HPP
#define NODES_HPP
#include <iostream>
#include <string>

using std::endl;
using std::ostream;
using std::string;

class Node
{
public:
    // set the pointers to 0 C++ is trying to get away from NULL
    Node(Node *lt = 0, Node *rt = 0);
    virtual ~Node();
    int getInt() const;
    double getDouble() const;
    string getString() const;
    void setVal(const char *v);
    void setVal(const string s);
    void setVal(int i);
    void setVal(double d);
    void reset();
    void setLeft(Node *p);
    void setRight(Node *p);
    void setNext(Node *p);
    Node *getLeft();
    Node *getRight();
    Node *getNext();
    virtual void print(ostream *out = 0);

protected:
    int myline;
    int mycol;
    int ival;
    double dval;
    string sval;
    Node *left, *right;
    Node *next;
};

// END NODE

// BEGIN LEAF NODES

// END LEAF NODES

class NodeName : public Node
{
public:
    NodeName(string s);
    NodeName(NodeName *nn, string id);
    virtual void print(ostream *out = 0);
};

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

class NodeNewExp : public Node
{
public:
    NodeNewExp(string id);
    NodeNewExp(NodeType *nt);
    virtual void print(ostream *out = 0);
};

class NodeExp : public Node
{
public:
    NodeExp(Node *n = 0);
    virtual void print(ostream *out = 0);
};

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

#endif
