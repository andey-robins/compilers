/*
 * list-base.cpp
 * Andey Robins
 * 10/20/22
 * Compilers Program 4
 *
 *
 */

#include "../include/list-base.hpp"

BaseList::BaseList()
{
    vector<BaseNode *> n;
    this->vect = n;
}

BaseList::~BaseList()
{
    delete &this->vect;
}

void BaseList::print()
{
    // TODO
    cout << "TODO print for BaseList" << endl;
}

void BaseList::push(BaseNode *n)
{
    if (n)
    {
        this->vect.push_back(n);
    }
}

BaseNode *BaseList::pop()
{
    if (this->vect.size() != 0)
    {
        BaseNode *last = this->vect.back();
        this->vect.pop_back();
        return last;
    }
    else
    {
        return 0;
    }
}

vector<BaseNode *> *BaseList::getList()
{
    if (this->vect.size() != 0)
    {
        return &this->vect;
    }
    else
    {
        return 0;
    }
}