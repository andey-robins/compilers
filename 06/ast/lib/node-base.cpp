/*
 * node-base.cpp
 * Andey Robins
 * 12/2/22
 * Compilers Program 6
 *
 * Implementation of the AST base node, inherited by all
 */

#include "../include/nodes.hpp"

string leftTrim(string in)
{
    in.erase(0, in.find_first_not_of(" "));
    return in;
}

BaseNode::BaseNode()
{
    this->annotation = "";
}

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

void BaseNode::setLineNumber(int ln)
{
    this->lineNumber = ln;
}

void BaseNode::print(ostream *out)
{
}

void BaseNode::semanticError(string errType, string errText, string debugOne, string debugTwo)
{
    cout << "Semantic Error: " << errType << endl
         << "Line " << this->lineNumber << ": " << leftTrim(this->line) << endl
         << "---------------------" << endl
         << "| " << errText << endl
         << "|" << endl
         << "| " << debugOne << endl
         << "| " << debugTwo << endl
         << "---------------------" << endl
         << endl;
}

void BaseNode::semanticError(string errType, string errText, string debugOne)
{
    cout << "Semantic Error: " << errType << endl
         << "Line " << this->lineNumber << ": " << leftTrim(this->line) << endl
         << "---------------------" << endl
         << "| " << errText << endl
         << "|" << endl
         << "| " << debugOne << endl
         << "---------------------" << endl
         << endl;
}