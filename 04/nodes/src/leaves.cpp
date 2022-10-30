/*
 * leaves.cpp
 * Andey Robins
 * 10/20/22
 * Compilers Program 4
 *
 *
 */

#include "../include/nodes.hpp"

NId::NId(string id)
{
    this->text = id;
}

void NId::print()
{
    cout << string(indentation * 2, ' ')
         << "ID --> "
         << this->text
         << endl;
}

NKeyword::NKeyword(string key)
{
    this->text = key;
}

void NKeyword::print()
{
    cout << "i'm a keyword" << endl;
}