/*
 * wrapper.cpp
 * Andey Robins
 * 10/15/22
 * Compilers Program 3
 *
 * Implementations for the AST of all wrapper nodes
 */
#include "nodes.hpp"

// NodeBracketExp is the most generic version of a bracketed expression
NodeBracketExp::NodeBracketExp(NodeBracketExp *nb)
{
    this->setType("bracketexp");
    this->setNext(nb);
}

NodeBracketExp::NodeBracketExp(NodeEpsilon *ne)
{
    this->setType("bracketexp -> epsilon");
    this->setNext(ne);
}

void NodeBracketExp::print(ostream *out)
{
    if (this->getNext()->getType() != "multibrack")
    {
        *out << string(indentation * 2, ' ')
             << "<bracketexp> --> [ <exp> ]"
             << endl;
    }
    indentation++;
    if (this->getNext() != 0)
    {
        this->getNext()->print(out);
    }
    indentation--;
    return;
}

// NodeMultiBrack is a class for holding a sequence of empty brackets
NodeMultiBrack::NodeMultiBrack()
{
    this->setVal(1);
    this->setType("multibrack");
}

void NodeMultiBrack::print(ostream *out)
{
    indentation--;
    *out << string(indentation * 2, ' ')
         << "<multibrackets> --> []";

    Node *next = this->getNext();
    while (next->getType() == "multibrack" || next->getType() == "bracketexp -> epsilon")
    {
        if (next->getType() == "multibrack")
        {
            *out << "[]";
        }
        next = next->getNext();
    }
    *out << endl;

    if (next)
    {
        next->print(out);
    }
    return;
}