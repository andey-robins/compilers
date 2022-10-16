#include "../include/nodes.hpp"

// Expressions
NodeExp::NodeExp(Node *n)
{
    this->setNext(n);
}

void NodeExp::print(ostream *out)
{
    if (this->getNext())
    {
        this->getNext()->print(out);
    }
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
    this->setVal(id);
}

NodeNewExp::NodeNewExp(NodeType *nt)
{
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

    if (this->getNext())
    {
        this->getNext()->print(out);
    }

    indentation--;
    return;
}

NodeNewExpType::NodeNewExpType(NodeType *nt)
{
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
