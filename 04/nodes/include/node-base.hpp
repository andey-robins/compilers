/*
 * node-base.hpp
 * Andey Robins
 * 10/20/22
 * Compilers Program 4
 *
 *
 */

#ifndef NODE_BASE_HPP
#define NODE_BASE_HPP
#include <iostream>

using std::endl;
using std::ostream;

class BaseNode
{
public:
    BaseNode();
    virtual ~BaseNode();
    void setNext(BaseNode *n);
    BaseNode *getNext();
    virtual void print(ostream *out = 0);

protected:
    BaseNode *next;
};

#endif