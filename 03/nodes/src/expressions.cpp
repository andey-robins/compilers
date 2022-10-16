#include "../include/nodes.hpp"

// Expressions
NodeExp::NodeExp(Node *n)
{
    this->setNext(n);
}

void NodeExp::print(ostream *out)
{
    Node::print(out);
    return;
}

NodeCallExp::NodeCallExp(NodeName *nn)
{
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
    this->setType("newesp-id");
    this->setVal(id);
}

NodeNewExp::NodeNewExp(NodeType *nt)
{
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
