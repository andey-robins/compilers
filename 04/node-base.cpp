/*
 * node-base.cpp
 * Andey Robins
 * 10/20/22
 * Compilers Program 4
 *
 *  The NodeBase which is extended by every node in the AST
 *  This implementation is more on the minimal side with very little
 *  being incldued in the structure by default, instead additional
 *  data is associated with the child nodes
 */

#include "nodes.hpp"

BaseNode::BaseNode() {}

BaseNode::~BaseNode()
{
    if (this->next)
    {
        delete this->next;
    }
}

void BaseNode::setNext(BaseNode *n)
{
    if (n)
    {
        if (this->next)
        {
            this->next->setNext(n);
        }
        else
        {
            this->next = n;
        }
    }
    else
    {
        this->next = 0;
    }
}

void BaseNode::setVal(string s)
{
    this->text = s;
}

BaseNode *BaseNode::getNext()
{
    if (this->next)
    {
        return this->next;
    }
    else
    {
        return 0;
    }
}

string BaseNode::getText()
{
    return this->text;
}

void BaseNode::print()
{
}