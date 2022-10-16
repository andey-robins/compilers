#include "../include/nodes.hpp"

NodeType::NodeType(NodeSimpleType *st)
{
    this->setType("type");
    this->setNext(st);
}

void NodeType::print(ostream *out)
{
    *out << "<type> ";
    if (this->getNext() != 0)
    {
        this->getNext()->print(out);
    }
    return;
}

NodeSimpleType::NodeSimpleType(string s)
{
    this->setType("simpletype");
    this->setVal(s);
}

void NodeSimpleType::print(ostream *out)
{
    *out << string(indentation * 2, ' ')
         << "<type> -> INT"
         << endl;
    if (this->getNext() != 0)
    {
        this->getNext()->print(out);
    }
    return;
}

NodeEpsilon::NodeEpsilon()
{
    this->setType("epsilon");
    this->setVal("epsilon");
}

void NodeEpsilon::print(ostream *out)
{
    // NodeEpsilon is an empty node, so nothing should be printed
    // TODO: Remove
    // *out << "epsilon";
    // we do want to continue printing out the tree elements stored in next if there are any sequenced after
    if (this->getNext() != 0)
    {
        this->getNext()->print(out);
    }
    return;
}