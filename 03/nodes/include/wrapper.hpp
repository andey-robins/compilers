#include "node.hpp"

class NodeBracketExp : public Node
{
public:
    NodeBracketExp(NodeExp *nn);
    virtual void print(ostream *out);
};