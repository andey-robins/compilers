/*
 * node.hpp
 * Andey Robins
 * 10/15/22
 * Compilers Program 3
 *
 * Root class for nodes in the AST
 */
#include <typeinfo>
#include "../include/nodes.hpp"

Node::Node(Node *lt, Node *rt) : ival(0), dval(0.0), left(lt), right(rt), next(0)
{
  reset();
}

Node::~Node()
{
  if (left)
    delete left;
  if (right)
    delete right;
}

int Node::getInt() const
{
  return ival;
}
double Node::getDouble() const
{
  return dval;
}
string Node::getString() const
{
  return sval;
}
void Node::setVal(const char *v)
{
  sval = v;
}
void Node::setVal(const string s)
{
  sval = s;
}
void Node::setVal(int i)
{
  ival = i;
}
void Node::setVal(double d)
{
  dval = d;
}
void Node::setType(string t)
{
  type = t;
}
string Node::getType()
{
  return type;
}

void Node::reset()
{
  myline = mycol = 1;
  sval.clear();
}

void Node::setLeft(Node *p)
{
  left = p;
  return;
}

void Node::setRight(Node *p)
{
  right = p;
  return;
}

void Node::setNext(Node *p)
{
  if (next == 0)
    next = p;
  else
    next->setNext(p);
  return;
}

Node *Node::getLeft()
{
  return left;
}

Node *Node::getRight()
{
  return right;
}

Node *Node::getNext()
{
  return next;
}

void Node::print(ostream *out)
{
  if (left)
  {
    left->print(out);
  }

  if (right)
  {
    right->print(out);
  }

  if (next)
  {
    next->print(out);
  }
  return;
}

NodeName::NodeName(string s)
{
  sval = s;
}