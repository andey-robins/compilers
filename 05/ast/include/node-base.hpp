/*
 * node-base.hpp
 * Andey Robins
 * 11/7/22
 * Compilers Program 5
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
    virtual void print(ostream *out = 0);

protected:
    BaseNode *next;
    string text;
};

#endif