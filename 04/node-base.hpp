/*
 * node-base.hpp
 * Andey Robins
 * 10/20/22
 * Compilers Program 4
 *
 *  The NodeBase which is extended by every node in the AST
 *  This implementation is more on the minimal side with very little
 *  being incldued in the structure by default, instead additional
 *  data is associated with the child nodes
 */

#include <iostream>
#include <string>

#ifndef NODE_BASE_HPP
#define NODE_BASE_HPP

using std::endl;
using std::ostream;
using std::string;

class BaseNode
{
public:
    BaseNode();
    virtual ~BaseNode();
    void setNext(BaseNode *n);
    void setVal(string s);
    BaseNode *getNext();
    string getText();
    virtual void print();

protected:
    BaseNode *next;
    string text;
};

#endif