#include "../include/nodes.hpp"

NodeProgram::NodeProgram(NodeElement *e)
{
    this->setNext(e);
}

void NodeProgram::print(ostream *out)
{
    *out << "<program> --> <elements>" << endl;
    indentation++;
    if (this->getNext())
    {
        this->getNext()->print(out);
    }
    indentation--;
    return;
}

NodeOptProgram::NodeOptProgram(NodeElement *e)
{
    this->setNext(e);
}

void NodeOptProgram::print(ostream *out)
{
    *out << "<program> --> <program> <elements>" << endl;
    indentation = 1;
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