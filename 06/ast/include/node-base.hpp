/*
 * node-base.hpp
 * Andey Robins
 * 12/2/22
 * Compilers Program 6
 *
 * Base node used for the AST. Inherited by everything
 */

#include <iostream>
#include <string>

#ifndef NODE_BASE_HPP
#define NODE_BASE_HPP

using std::endl;
using std::ostream;
using std::string;

class SymbolTree;

class BaseNode
{
public:
    BaseNode();
    virtual ~BaseNode();
    void setNext(BaseNode *n);
    void setVal(string s);
    BaseNode *getNext();
    string getText();
    void setLineNumber(int ln);
    virtual void print(ostream *out = 0);
    void semanticError(string errType, string errText,
                       string debugOne, string debugTwo);
    void semanticError(string errType, string errText, string debugOne);
    string annotation;
    int lineNumber;
    string line;

protected:
    BaseNode *next;
    string text;
};

#endif