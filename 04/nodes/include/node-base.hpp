#ifndef NODE_BASE_HPP
#define NODE_BASE_HPP
#include <iostream>

using std::ostream;
using std::endl;

class BaseNode
{
public:
    BaseNode();
    virtual ~BaseNode();
    void setNext(BaseNode *n);
    BaseNode* getNext();
    virtual void print(ostream *out=0);

protected:
    BaseNode *next;
};

#endif