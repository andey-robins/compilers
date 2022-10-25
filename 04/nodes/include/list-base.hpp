/*
 * list-base.hpp
 * Andey Robins
 * 10/20/22
 * Compilers Program 4
 *
 *
 */

#ifndef LIST_BASE_HPP
#define LIST_BASE_HPP

#include <iostream>
#include <vector>
#include "nodes.hpp"

using std::ostream;
using std::vector;

// BaseList is a wrapper around std::vector for use in an AST
class BaseList
{
public:
    BaseList();
    virtual ~BaseList();
    virtual void print();
    void push(BaseNode *);
    BaseNode *pop();
    vector<BaseNode *> *getList();

private:
    vector<BaseNode *> vect;
};

#endif