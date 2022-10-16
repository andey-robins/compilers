#ifndef NODE_HPP
#define NODE_HPP
#include <iostream>
#include <string>

using std::endl;
using std::ostream;
using std::string;

class Node
{
public:
    // set the pointers to 0 C++ is trying to get away from NULL
    Node(Node *lt = 0, Node *rt = 0);
    virtual ~Node();
    int getInt() const;
    double getDouble() const;
    string getString() const;
    void setVal(const char *v);
    void setVal(const string s);
    void setVal(int i);
    void setVal(double d);
    void reset();
    void setLeft(Node *p);
    void setRight(Node *p);
    void setNext(Node *p);
    void setType(string t);
    string getType();
    Node *getLeft();
    Node *getRight();
    Node *getNext();
    virtual void print(ostream *out = 0);

protected:
    int myline;
    int mycol;
    int ival;
    double dval;
    string sval;
    string type;
    Node *left, *right;
    Node *next;
};

#endif