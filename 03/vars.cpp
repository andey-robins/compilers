/*
 * expression.cpp
 * Andey Robins
 * 10/16/22
 * Compilers Program 3
 *
 * Implementations for the AST of all vardec nodes
 */
#include "../include/nodes.hpp"

// NodeVarTypeId is the class for the production vardec -> type ID
NodeVarTypeId::NodeVarTypeId(Node *nt, string id)
{
    this->setType("vardec type id");
    this->setLeft(static_cast<NodeSimpleType *>(nt));
    this->setVal(id);
}

void NodeVarTypeId::print(ostream *out)
{
    *out << string(indentation * 2, ' ')
         << "<vardec> --> <type> ID"
         << endl;
    indentation++;
    this->getLeft()->print(out);
    *out << string(indentation * 2, ' ')
         << "ID --> "
         << this->getString()
         << endl;
    indentation--;
    if (this->getNext())
    {
        this->getNext()->print(out);
    }
    return;
}

// NodeVarIdId is the class for the production vardec -> ID ID
NodeVarIdId::NodeVarIdId(string id1, string id2)
{
    this->setType("vardec id id");
    this->setLeft(new LeafId(id1));
    this->setRight(new LeafId(id2));
}

void NodeVarIdId::print(ostream *out)
{
    *out << string(indentation * 2, ' ')
         << "<vardec> --> ID ID"
         << endl;
    indentation++;
    this->getLeft()->print(out);
    this->getRight()->print(out);
    if (this->getNext())
    {
        this->getNext()->print(out);
    }
    indentation--;
    return;
}

// NodeVarTypeMult is the node associated with the production vardec -> type multibrackets ID
NodeVarTypeMult::NodeVarTypeMult(Node *nt, Node *mb, string id)
{
    this->setType("vardec type multibrack");
    this->setVal(id);
    this->setLeft(static_cast<NodeSimpleType *>(nt));
    this->setRight(static_cast<NodeMultiBrack *>(mb));
}

void NodeVarTypeMult::print(ostream *out)
{
    *out << string(indentation * 2, ' ')
         << "<vardec> --> <type> <multibrackets> ID"
         << endl;
    indentation++;
    this->getLeft()->print(out);
    indentation++;
    this->getRight()->print(out);
    *out << string(indentation * 2, ' ')
         << "ID --> "
         << this->getString()
         << endl;
    indentation--;
    if (this->getNext())
    {
        *out << "next::" << this->getNext()->getType() << endl;
        this->getNext()->print(out);
    }
    return;
}

// NodeVarIdMult is the node for the production vardec -> ID multibrackets ID
NodeVarIdMult::NodeVarIdMult(string id1, Node *mb, string id2)
{
    this->setType("vardec id multibrack id");
    this->setLeft(new LeafId(id1));
    this->setRight(static_cast<NodeMultiBrack *>(mb));
    this->setNext(new LeafId(id2));
}

void NodeVarIdMult::print(ostream *out)
{
    *out << string(indentation * 2, ' ')
         << "<vardec> --> ID <multibrackets> ID"
         << endl;
    indentation++;
    Node::print(out);
    return;
}