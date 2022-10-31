/*
 * expressions.cpp
 * Andey Robins
 * 10/20/22
 * Compilers Program 4
 *
 *
 */

#include "../include/nodes.hpp"

void NExp::print()
{
    auto *derivedInfix = dynamic_cast<NInfixExp *>(this);

    if (derivedInfix)
    {
        derivedInfix->print();
    }
}

NInfixExp::NInfixExp(NOperator *o, NExp *left, NExp *right)
{
    this->left = left;
    this->right = right;
    this->op = o;
}

NInfixExp::~NInfixExp()
{
    delete this->left;
    delete this->right;
    delete this->op;
}

void NInfixExp::print()
{
    cout << string(indentation * 2, ' ')
         << "<exp> --> <exp> "
         << this->op->getOp()
         << " <exp>"
         << endl;
    indentation++;
    this->left->print();
    this->right->print();
    indentation--;
}

NOptExp::NOptExp()
{
    this->e = 0;
}

NOptExp::NOptExp(NExp *e)
{
    this->e = e;
}

void NOptExp::print()
{
    if (this->e)
    {
        this->e->print();
    }
    if (this->next)
    {
        this->next->print();
    }
}

bool NOptExp::maybe()
{
    return this->e != 0;
}