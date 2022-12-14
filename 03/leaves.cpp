/*
 * leaves.cpp
 * Andey Robins
 * 10/15/22
 * Compilers Program 3
 *
 * Implementations for the AST of all leaf nodes
 */
#include "nodes.hpp"

// LeafId holds the ID value of a leaf in the node's string
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

// LeafNumber holds the number of the leaf in the node's int
LeafNumber::LeafNumber(int i)
{
    this->setVal(i);
}

void LeafNumber::print(ostream *out)
{
    *out << string(indentation * 2, ' ')
         << "<exp> --> NUMBER"
         << endl;
    indentation++;
    *out << string(indentation * 2, ' ')
         << "NUMBER --> "
         << this->getInt()
         << endl;
    indentation -= 2;
    if (this->getNext())
    {
        this->getNext()->print(out);
    }
    return;
}

// LeafKeyword is currently unused.
// Potentially of value when keywords need to be distinguished from IDs?
// Maybe pre-define them in the symbol table instead? TBD
LeafKeyword::LeafKeyword(string s)
{
    this->setVal(s);
}

void LeafKeyword::print(ostream *out)
{
    *out << string(indentation * 2, ' ')
         << "Keyword --> "
         << this->getString()
         << endl;
    if (this->getNext())
    {
        this->getNext()->print(out);
    }
}