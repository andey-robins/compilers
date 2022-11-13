/*
 * node-base.cpp
 * Andey Robins
 * 11/7/22
 * Compilers Program 5
 *
 *
 */

#include "../include/nodes.hpp"

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

void BaseNode::print(ostream *out)
{
}