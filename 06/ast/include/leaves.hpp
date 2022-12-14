/*
 * leaves.hpp
 * Andey Robins
 * 12/2/22
 * Compilers Program 6
 *
 * Declarations for leaf nodes
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
    virtual void print(ostream *out = 0);
    string getSymbol();

private:
    string text;
};

class NKeyword : public BaseNode
{
public:
    NKeyword(string key);
    string getText();
    virtual void print(ostream *out = 0);
    string getSymbol();

private:
    string text;
};

class NNumber : public BaseNode
{
public:
    NNumber(int n);
    int getVal();
    virtual void print(ostream *out = 0);
    string getSymbol();

private:
    int num;
};

class NOperator : public BaseNode
{
public:
    NOperator(string op);
    string getOp();
    virtual void print(ostream *out = 0);
    string getSymbol();

private:
    string op;
};

#endif