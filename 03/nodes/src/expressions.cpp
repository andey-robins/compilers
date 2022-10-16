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
    *out << "( )" << endl;
    return;
}

// NewExpressions
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

// Name Node
NodeName::NodeName(NodeName *nn, string id)
{
    this->setType("name");
    this->setNext(nn);
    this->setVal(id);
}

void NodeName::print(ostream *out)
{
    *out << "<name> ";
    next->print(out);
    return;
}
