#include "./node.hpp"

class LeafId : public Node
{
public:
    LeafId(string id);
    virtual void print(ostream *out = 0);
};

class LeafNumber : public Node
{
public:
    LeafNumber(int i);
    virtual void print(ostream *out = 0);
};

class LeafKeyword : public Node
{
public:
    LeafKeyword(string s);
    virtual void print(ostream *out = 0);
};