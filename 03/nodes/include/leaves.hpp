/*
 * leaves.hpp
 * Andey Robins
 * 10/15/22
 * Compilers Program 3
 *
 * Definitions for the AST of all leaf nodes
 */
#include "node.hpp"

// LeafId holds the ID value of a leaf in the node's string
class LeafId : public Node
{
public:
    LeafId(string id);
    virtual void print(ostream *out = 0);
};

// LeafNumber holds the number of the leaf in the node's int
class LeafNumber : public Node
{
public:
    LeafNumber(int i);
    virtual void print(ostream *out = 0);
};

// LeafKeyword is currently unused.
// Potentially of value when keywords need to be distinguished from IDs?
// Maybe pre-define them in the symbol table instead? TBD
class LeafKeyword : public Node
{
public:
    LeafKeyword(string s);
    virtual void print(ostream *out = 0);
};