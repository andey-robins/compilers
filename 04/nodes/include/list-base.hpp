#ifndef LIST_BASE_HPP
#define LIST_BASE_HPP

#include <iostream>
#include <vector>
#include "nodes.hpp"

using std::vector;
using std::ostream;

// BaseList is a wrapper around std::vector for use in an AST
class BaseList
{
public:
    BaseList();
    virtual ~BaseList();
    virtual void print(ostream *out);
    void push(BaseNode *);
    BaseNode* pop();
    vector<BaseNode*>* getList();

private:
    vector<BaseNode*> vect;
};

#endif