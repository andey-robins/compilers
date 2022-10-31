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
    auto *derivedOpt = dynamic_cast<NOptExp *>(this);
    auto *derivedNull = dynamic_cast<NExpNull *>(this);
    auto *derivedParen = dynamic_cast<NParenExp *>(this);
    auto *derivedCall = dynamic_cast<NExpCall *>(this);
    auto *derivedRead = dynamic_cast<NExpRead *>(this);
    auto *derivedNew = dynamic_cast<NExpNewExp *>(this);
    auto *derivedPrefix = dynamic_cast<NPrefixExp *>(this);

    if (derivedInfix)
    {
        derivedInfix->print();
    }
    else if (derivedOpt)
    {
        derivedOpt->print();
    }
    else if (derivedNull)
    {
        derivedNull->print();
    }
    else if (derivedParen)
    {
        derivedParen->print();
    }
    else if (derivedCall)
    {
        derivedCall->print();
    }
    else if (derivedRead)
    {
        derivedRead->print();
    }
    else if (derivedNew)
    {
        derivedNew->print();
    }
    else if (derivedPrefix)
    {
        derivedPrefix->print();
    }

    if (this->next)
    {
        this->next->print();
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
    if (this->next)
    {
        this->next->print();
    }
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

NExpNull::NExpNull()
{
}

void NExpNull::print()
{
    cout << string(indentation * 2, ' ')
         << "<exp> --> null"
         << endl;
    if (this->next)
    {
        this->next->print();
    }
}

NParenExp::NParenExp(NExp *inner)
{
    this->in = inner;
}

NParenExp::~NParenExp()
{
    delete this->in;
}

void NParenExp::print()
{
    cout << string(indentation * 2, ' ')
         << "<exp> --> ( <exp> )"
         << endl;
    indentation++;
    this->in->print();
    indentation--;
    if (this->next)
    {
        this->next->print();
    }
}

NExpCall::NExpCall(NName *n, NArg *a)
{
    this->name = n;
    this->args = a;
}

NExpCall::~NExpCall()
{
    delete this->name;
    delete this->args;
}

void NExpCall::print()
{
    cout << string(indentation * 2, ' ')
         << "<exp> --> <name> ( <exp> )"
         << endl;
    indentation++;
    this->name->print();
    this->args->print();
    indentation--;
    if (this->next)
    {
        this->next->print();
    }
}

NExpRead::NExpRead()
{
}

void NExpRead::print()
{
    cout << string(indentation * 2, ' ')
         << "<exp> --> READ"
         << endl;
    if (this->next)
    {
        this->next->print();
    }
}

NExpNewExp::NExpNewExp(NNewExp *ne)
{
    this->newExp = ne;
}

NExpNewExp::~NExpNewExp()
{
    delete this->newExp;
}

void NExpNewExp::print()
{
    cout << string(indentation * 2, ' ')
         << "<exp> --> <newexp>"
         << endl;
    indentation++;
    this->newExp->print();
    indentation--;
    if (this->next)
    {
        this->next->print();
    }
}

NPrefixExp::NPrefixExp(NOperator *o, NExp *e)
{
    this->op = o;
    this->exp = e;
}

NPrefixExp::~NPrefixExp()
{
    delete this->op;
    delete this->exp;
}

void NPrefixExp::print()
{
    cout << string(indentation * 2, ' ')
         << "<exp> --> "
         << this->op->getOp()
         << " <exp>"
         << endl;
    indentation++;
    this->exp->print();
    indentation--;
    if (this->next)
    {
        this->next->print();
    }
}