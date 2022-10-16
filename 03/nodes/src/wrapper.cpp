#include "../include/nodes.hpp"

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

NodeMultiBrack::NodeMultiBrack()
{
    this->setType("multibrack");
}

// TODO: get working for multiple sets of multi brackets
void NodeMultiBrack::print(ostream *out)
{
    indentation--;
    *out << string(indentation * 2, ' ')
         << "<multibrackets> --> []"
         << endl;
    return;
}