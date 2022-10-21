/*
 * expressions.hpp
 * Andey Robins
 * 10/20/22
 * Compilers Program 4
 *
 *
 */

#ifndef EXPRESSIONS_HPP
#define EXPRESSIONS_HPP

#include "nodes.hpp"

class NExp : public BaseNode
{
};

// A maybe monad adapted to hold an optional expression
class NOptExp : public BaseNode
{
public:
    NOptExp();
    NOptExp(NExp *e);
    virtual void print(ostream *out);
    NExp *maybe();

protected:
    bool isEmpty;
};

#endif