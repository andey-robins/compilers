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

  if (sval != "")
  {
    *out << sval << endl;
  }
  else if (ival)
  {
    *out << ival << endl;
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

// END NODE
// BEGIN LEAF NODES

// END LEAF NODES

NodeProgram::NodeProgram(NodeElement *e)
{
  this->setNext(e);
}

void NodeProgram::print(ostream *out)
{
  *out << "<program> --> <elements> ";
  Node::print(out);
  return;
}

NodeElement::NodeElement(NodeExp *e)
{
  this->setNext(e);
}

void NodeElement::print(ostream *out)
{
  *out << "<elements> --> ";
  Node::print(out);
  return;
}

NodeExp::NodeExp(Node *n)
{
  this->setNext(n);
}

void NodeExp::print(ostream *out)
{
  *out << "<exp> ";
  Node::print(out);
}

NodeNewExp::NodeNewExp(string id)
{
  this->setVal(id);
}

NodeNewExp::NodeNewExp(NodeType *nt)
{
  this->setNext(nt);
}

void NodeNewExp::print(ostream *out)
{
  // TODO: Determine which version we need to print here.
  *out << "<newexp> --> NEW ID ( ) "
       << endl
       << "ID --> ";
  Node::print(out);
  return;
}

NodeName::NodeName(string s)
{
  sval = s;
}

NodeName::NodeName(NodeName *nn, string id)
{
  this->setNext(nn);
  this->setVal(id);
}

void NodeName::print(ostream *out)
{
  *out << "<name> ";
  next->print(out);
  return;
}

NodeType::NodeType(NodeSimpleType *st)
{
  this->setNext(st);
}

void NodeType::print(ostream *out)
{
  *out << "<type> ";
  next->print(out);
  return;
}

NodeSimpleType::NodeSimpleType(string s)
{
  this->setVal(s);
}

void NodeSimpleType::print(ostream *out)
{
  *out << "<simpletype> ";
  Node::print(out);
  return;
}
