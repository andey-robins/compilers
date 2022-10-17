/*
 * struct.cpp
 * Andey Robins
 * 10/15/22
 * Compilers Program 3
 *
 * Implementations for the AST of all struct nodes
 */
#include "nodes.hpp"

// NodeProgram is the highest level node
// Contains the node for the
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

// NodeOptProgram allows for sequential versions of a program
NodeOptProgram::NodeOptProgram(NodeElement *e)
{
    this->setType("optprogram");
    this->setNext(e);
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

// NodeElement is the element sub-production of program
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