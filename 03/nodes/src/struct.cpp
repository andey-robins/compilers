#include "../include/nodes.hpp"

NodeProgram::NodeProgram(NodeElement *e)
{
    this->setType("program");
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
    this->setType("optprogram");
    this->setNext(e);
    // cout << "opt" << endl;
}

void NodeOptProgram::print(ostream *out)
{
    *out << "<program> --> <program> <elements>" << endl;
    indentation = 1;
    if (this->getNext() != 0)
    {
        this->getNext()->print(out);
    }
    indentation--;
    return;
}

NodeElement::NodeElement(NodeExp *e)
{
    this->setType("element");
    this->setNext(e);
}

void NodeElement::print(ostream *out)
{
    *out << "<elements> --> ";
    if (this->getNext() != 0)
    {
        this->getNext()->print(out);
    }
    return;
}