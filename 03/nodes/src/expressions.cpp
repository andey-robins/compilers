/*
 * expression.cpp
 * Andey Robins
 * 10/15/22
 * Compilers Program 3
 *
 * Implementations for the AST of all expression nodes
 */
#include "../include/nodes.hpp"

// Expressions

// NodeExp is a root node created whenever a generic expression is needed
NodeExp::NodeExp(Node *n)
{
    this->setType("exp");
    this->setNext(n);
}

void NodeExp::print(ostream *out)
{
    Node::print(out);
    return;
}

// NodeCallExp is the node for call expressions like ID()
NodeCallExp::NodeCallExp(NodeName *nn)
{
    this->setType("call exp");
    this->setNext(nn);
}

void NodeCallExp::print(ostream *out)
{
    // print out the name parameter
    if (this->getNext())
    {
        this->getNext()->print(out);
    }
    return;
}

// New Expressions
// NodeNewExp houses a generic new expression. It's constructor is overloaded
// to allow for whatever new expression layout is appropriate
// perhaps that should be refactored to the many (many) class style of expressions?
NodeNewExp::NodeNewExp(string id)
{
    this->setType("newexp");
    this->setType("newesp-id");
    this->setVal(id);
}

NodeNewExp::NodeNewExp(NodeType *nt)
{
    this->setType("newexp");
    this->setType("newexp-nt");
    this->setNext(nt);
}

void NodeNewExp::print(ostream *out)
{
    // TODO: Determine which version we need to print here.
    *out << string(indentation * 2, ' ')
         << "<newexp> --> NEW ID ( ) "
         << endl;
    indentation++;

    if (sval != "")
    {
        *out << string(indentation * 2, ' ')
             << "ID --> "
             << sval
             << endl;
    }

    Node::print(out);

    indentation--;
    return;
}

// The node associated with the production newexp -> NEW simpletype
NodeNewExpType::NodeNewExpType(NodeType *nt)
{
    this->setType("newexp type");
    this->setNext(nt);
}

void NodeNewExpType::print(ostream *out)
{
    *out << string(indentation * 2, ' ')
         << "<newexp> --> NEW <type>"
         << endl;
    indentation++;
    this->getNext()->print(out);
    indentation--;
    return;
}

// The node associated with the production newexp -> NEW simpletype bracketexps
NodeNewExpTypeBrack::NodeNewExpTypeBrack(NodeType *nt, Node *nb)
{
    this->setType("newexp type brack");
    this->setLeft(nt);
    this->setRight(static_cast<NodeBracketExp *>(nb));
}

void NodeNewExpTypeBrack::print(ostream *out)
{
    *out << string(indentation * 2, ' ')
         << "<newexp> --> NEW <type> <bracketexps>"
         << endl;
    indentation++;
    this->getLeft()->print(out);
    this->getRight()->print(out);
    // this->getRight()->getNext()->print(out);
    indentation--;
    if (this->getNext() != 0)
    {
        this->getNext()->print(out);
    }
    return;
}

// The node associated with the production newexp -> NEW ID bracketexps
NodeNewExpIdBrack::NodeNewExpIdBrack(string id, Node *nb)
{
    this->setType("newexp id brack");
    this->setVal(id);
    this->setNext(static_cast<NodeBracketExp *>(nb));
}

void NodeNewExpIdBrack::print(ostream *out)
{
    *out << string(indentation * 2, ' ')
         << "<newexp> --> NEW ID <bracketexps>"
         << endl;
    indentation++;
    *out << string(indentation * 2, ' ')
         << "ID --> "
         << sval
         << endl;
    Node::print(out);
    indentation -= 2;
    return;
}

// The node associated with the production newexp -> NEW simpletype bracketexps multibrackets
NodeNewTypeBrackMult::NodeNewTypeBrackMult(NodeType *nt, Node *nb, Node *mb)
{
    this->setType("newexp type brack mult");
    this->setLeft(static_cast<NodeType *>(nt));
    this->setRight(static_cast<NodeBracketExp *>(nb));
    this->setNext(static_cast<NodeMultiBrack *>(mb));
}

void NodeNewTypeBrackMult::print(ostream *out)
{
    *out << string(indentation * 2, ' ')
         << "<newexp> --> NEW <type> <bracketexps> <multibrackets>"
         << endl;
    indentation++;
    this->getLeft()->print(out);
    this->getRight()->print(out);
    *out << this->getNext()->getType();
    this->getNext()->print(out);
    indentation--;
    return;
}

// The node associated with the production newexp -> NEW ID bracketexps multibrackets
NodeNewIdBrackMult::NodeNewIdBrackMult(string id, Node *nb, Node *mb)
{
    this->setType("newexp brack mult");
    this->setVal(id);
    this->setLeft(static_cast<NodeBracketExp *>(nb));
    this->setNext(static_cast<NodeMultiBrack *>(mb));
}

void NodeNewIdBrackMult::print(ostream *out)
{
    *out << string(indentation * 2, ' ')
         << "<newexp> --> NEW <type> <bracketexps> <multibrackets>"
         << endl;
    indentation++;
    *out << this->getString() << endl;
    this->getLeft()->print(out);
    *out << this->getNext()->getType();
    this->getNext()->print(out);
    indentation--;
    return;
}

// Name corresponds to the name productions. The constructor is overloaded
// (maybe refactor to not use overloaded constructors?)
NodeName::NodeName(NodeName *nn, string id)
{
    this->setType("name");
    this->setNext(nn);
    this->setVal(id);
}

NodeName::NodeName(NodeName *nn, Node *nb)
{
    this->setLeft(nn);
    this->setNext(static_cast<NodeBracketExp *>(nb));
}

void NodeName::print(ostream *out)
{
    if (this->getLeft())
    {
        this->getLeft()->print(out);
    }
    if (this->getNext())
    {
        this->getNext()->print(out);
    }
    return;
}

// NodeInfixExp keeps track of any infix notation expression
// The operator is stored in the string value of the Node
NodeInfixExp::NodeInfixExp(Node *ln, Node *rn, string op)
{
    this->setType("exp infix");
    this->setVal(op);
    this->setLeft(ln);
    this->setRight(rn);
}

void NodeInfixExp::print(ostream *out)
{
    *out << string(indentation * 2, ' ')
         << "<exp> --> <exp> "
         << this->getString()
         << " <exp>"
         << endl;
    indentation++;
    this->getLeft()->print(out);
    this->getRight()->print(out);
    indentation++;
    if (this->getNext())
    {
        this->getNext()->print(out);
    }
    indentation--;
    return;
}

// NodePrefixExp keeps track of all prefix expressions
// The operator is stored in the node's string
NodePrefixExp::NodePrefixExp(string op, Node *n)
{
    this->setType("exp prefix");
    this->setVal(op);
    this->setNext(n);
}

void NodePrefixExp::print(ostream *out)
{
    *out << string(indentation * 2, ' ')
         << "<exp> --> "
         << this->getString()
         << " <exp>"
         << endl;
    indentation++;
    this->getNext()->print(out);
    indentation--;
    return;
}