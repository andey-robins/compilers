/*
 * node-base.cpp
 * Andey Robins
 * 10/20/22
 * Compilers Program 4
 *
 *
 */

#include "../include/nodes.hpp"

BaseNode::BaseNode() {}

BaseNode::~BaseNode()
{
    if (next)
    {
        delete next;
    }
}

void BaseNode::setNext(BaseNode *n)
{
    if (n)
    {
        next = n;
    }
    else
    {
        next = 0;
    }
}

BaseNode *BaseNode::getNext()
{
    if (next)
    {
        return next;
    }
    else
    {
        return 0;
    }
}

void BaseNode::print(ostream *out)
{
    *out << "BaseNode" << endl;
    *out << "Next" << endl;
    *out << "print not extended" << endl;
}