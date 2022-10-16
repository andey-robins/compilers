#include "../include/nodes.hpp"

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
    *out << string(indentation * 2, ' ')
         << "<type> -> INT"
         << endl;
    return;
}