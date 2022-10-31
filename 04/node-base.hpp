/*
 * node-base.hpp
 * Andey Robins
 * 10/20/22
 * Compilers Program 4
 *
 *
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