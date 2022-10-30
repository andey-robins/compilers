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
    if (this->next)
    {
        delete this->next;
    }
}

void BaseNode::setNext(BaseNode *n)
{
    if (n)
    {
        this->next = n;
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
    cout << "BaseNode" << endl;
    cout << "Next" << endl;
    cout << "print not extended" << endl;
}