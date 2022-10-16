/*
 * leaves.hpp
 * Andey Robins
 * 10/15/22
 * Compilers Program 3
 *
 * Definitions for the AST of all leaf nodes
 */
#include "node.hpp"

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