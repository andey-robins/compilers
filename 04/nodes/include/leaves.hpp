/*
 * leaves.hpp
 * Andey Robins
 * 10/20/22
 * Compilers Program 4
 *
 *
 */

#ifndef LEAVES_HPP
#define LEAVES_HPP

#include <string>
#include "node-base.hpp"

using std::string;

class NId : public BaseNode
{
public:
    NId(string id);
    virtual void print();

private:
    string text;
};

class NKeyword : public BaseNode
{
public:
    NKeyword(string key);
    virtual void print();

private:
    string text;
};

class NNumber : public BaseNode
{
    // TODO
};

class NOperator : public BaseNode
{
    // TODO
};

#endif