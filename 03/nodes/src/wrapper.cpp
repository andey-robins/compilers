#include "../include/nodes.hpp"

NodeBracketExp::NodeBracketExp(NodeExp *nn)
{
    this->setNext(nn);
}

void NodeBracketExp::print(ostream *out)
{
    *out << string(indentation * 2, ' ')
         << "<bracketexp> --> [ <exp> ]"
         << endl;
    indentation++;
    if (this->getNext() != 0)
    {
        this->getNext()->print(out);
    }
    indentation--;
    return;
}