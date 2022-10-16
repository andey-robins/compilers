#include "../include/nodes.hpp"

LeafId::LeafId(string id)
{
    this->setVal(id);
}

void LeafId::print(ostream *out)
{
    *out << string(indentation * 2, ' ')
         << "ID --> "
         << this->getString()
         << endl;
    if (this->getNext())
    {
        this->getNext()->print(out);
    }
    return;
}

LeafNumber::LeafNumber(int i)
{
    this->setVal(i);
}

void LeafNumber::print(ostream *out)
{
    *out << this->getInt() << endl;
    if (this->getNext())
    {
        this->getNext()->print(out);
    }
}

LeafKeyword::LeafKeyword(string s)
{
    this->setVal(s);
}

void LeafKeyword::print(ostream *out)
{
    *out << this->getString() << endl;
    if (this->getNext())
    {
        this->getNext()->print(out);
    }
}