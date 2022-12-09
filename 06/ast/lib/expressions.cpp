/*
 * expressions.cpp
 * Andey Robins
 * 12/2/22
 * Compilers Program 6
 *
 *
 */

#include "../include/nodes.hpp"

void NExp::print(ostream *out)
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
        derivedInfix->print(out);
    }
    else if (derivedOpt)
    {
        derivedOpt->print(out);
    }
    else if (derivedNull)
    {
        derivedNull->print(out);
    }
    else if (derivedParen)
    {
        derivedParen->print(out);
    }
    else if (derivedCall)
    {
        derivedCall->print(out);
    }
    else if (derivedRead)
    {
        derivedRead->print(out);
    }
    else if (derivedNew)
    {
        derivedNew->print(out);
    }
    else if (derivedPrefix)
    {
        derivedPrefix->print(out);
    }

    if (this->next)
    {
        this->next->print(out);
    }
}

void NExp::addSymbols(SymbolTree *node)
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
        derivedInfix->addSymbols(node);
    }
    else if (derivedOpt)
    {
        derivedOpt->addSymbols(node);
    }
    else if (derivedNull)
    {
        derivedNull->addSymbols(node);
    }
    else if (derivedParen)
    {
        derivedParen->addSymbols(node);
    }
    else if (derivedCall)
    {
        derivedCall->addSymbols(node);
    }
    else if (derivedRead)
    {
        derivedRead->addSymbols(node);
    }
    else if (derivedNew)
    {
        derivedNew->addSymbols(node);
    }
    else if (derivedPrefix)
    {
        derivedPrefix->addSymbols(node);
    }
}

NInfixExp::NInfixExp(NOperator *o, NExp *left, NExp *right)
{
    this->left = left;
    this->right = right;
    this->op = o;
    this->next = 0;
    if (left->annotation == right->annotation)
    {
        this->annotation = left->annotation;
    }
    else if (o->getText() == "==" && !(left->annotation == "void" && right->annotation == "int") && !(right->annotation == "void" && left->annotation == "int"))
    {
        this->annotation = "int";
    }
    else
    {
        cout << "Syntax Error: mismatched types of " << left->annotation << " and " << right->annotation << endl;
        this->annotation = "type error";
    }
}

NInfixExp::~NInfixExp()
{
    delete this->left;
    delete this->right;
    delete this->op;
}

void NInfixExp::print(ostream *out)
{
    *out << string(indentation * 2, ' ')
         << "<exp> --> <exp> "
         << this->op->getOp()
         << " <exp>"
         << endl;
    indentation++;
    this->left->print(out);
    this->right->print(out);
    indentation--;
    if (this->next)
    {
        this->next->print(out);
    }
}

void NInfixExp::addSymbols(SymbolTree *node)
{
}

NOptExp::NOptExp()
{
    this->e = 0;
    this->next = 0;
    this->annotation = "void";
}

NOptExp::NOptExp(NExp *e)
{
    this->e = e;
    this->next = 0;
    this->annotation = e->annotation;
}

void NOptExp::print(ostream *out)
{
    if (this->e)
    {
        this->e->print(out);
    }
    if (this->next)
    {
        this->next->print(out);
    }
}

bool NOptExp::maybe()
{
    return this->e != 0;
}

NExpNull::NExpNull()
{
    this->next = 0;
    this->annotation = "void";
}

void NExpNull::print(ostream *out)
{
    *out << string(indentation * 2, ' ')
         << "<exp> --> null"
         << endl;
    if (this->next)
    {
        this->next->print(out);
    }
}

NParenExp::NParenExp(NExp *inner)
{
    this->in = inner;
    this->next = 0;
    this->annotation = inner->annotation;
}

NParenExp::~NParenExp()
{
    delete this->in;
}

void NParenExp::print(ostream *out)
{
    *out << string(indentation * 2, ' ')
         << "<exp> --> ( <exp> )"
         << endl;
    indentation++;
    this->in->print(out);
    indentation--;
    if (this->next)
    {
        this->next->print(out);
    }
}

NExpCall::NExpCall(NName *n, NArg *a)
{
    this->name = n;
    this->args = a;
    this->next = 0;
    this->annotation = n->annotation;
}

NExpCall::~NExpCall()
{
    delete this->name;
    delete this->args;
}

void NExpCall::print(ostream *out)
{
    *out << string(indentation * 2, ' ')
         << "<exp> --> <name> ( <exp> )"
         << endl;
    indentation++;
    this->name->print(out);
    this->args->print(out);
    indentation--;
    if (this->next)
    {
        this->next->print(out);
    }
}

NExpRead::NExpRead()
{
    this->next = 0;
    this->annotation = "int";
}

void NExpRead::print(ostream *out)
{
    *out << string(indentation * 2, ' ')
         << "<exp> --> READ"
         << endl;
    if (this->next)
    {
        this->next->print(out);
    }
}

NExpNewExp::NExpNewExp(NNewExp *ne)
{
    this->newExp = ne;
    this->next = 0;
    // QUESTION is this actually the right type? do we want to return the memory address?
    // what would be the appropriate type for a new expression expression
    this->annotation = "int";
}

NExpNewExp::~NExpNewExp()
{
    delete this->newExp;
}

void NExpNewExp::print(ostream *out)
{
    *out << string(indentation * 2, ' ')
         << "<exp> --> <newexp>"
         << endl;
    indentation++;
    this->newExp->print(out);
    indentation--;
    if (this->next)
    {
        this->next->print(out);
    }
}

NPrefixExp::NPrefixExp(NOperator *o, NExp *e)
{
    this->op = o;
    this->exp = e;
    this->next = 0;
    this->annotation = "int";
}

NPrefixExp::~NPrefixExp()
{
    delete this->op;
    delete this->exp;
}

void NPrefixExp::print(ostream *out)
{
    *out << string(indentation * 2, ' ')
         << "<exp> --> "
         << this->op->getOp()
         << " <exp>"
         << endl;
    indentation++;
    this->exp->print(out);
    indentation--;
    if (this->next)
    {
        this->next->print(out);
    }
}

NNewExpType::NNewExpType(NSimpleType *s, NBrackExps *bes, NBracks *bs)
{
    this->t = s;
    this->bes = bes;
    this->bs = bs;
    this->next = 0;
    this->annotation = "array " + s->annotation;
}

NNewExpType::NNewExpType(NSimpleType *s, NBrackExps *bes)
{
    this->t = s;
    this->bes = bes;
    this->bs = 0;
    this->next = 0;
    this->annotation = "array " + s->annotation;
}

NNewExpType::NNewExpType(NSimpleType *s, NBracks *bs)
{
    this->t = s;
    this->bes = 0;
    this->bs = bs;
    this->next = 0;
    this->annotation = "array " + s->annotation;
}

NNewExpType::NNewExpType(NSimpleType *s)
{
    this->t = s;
    this->bes = 0;
    this->bs = 0;
    this->next = 0;
    this->annotation = s->annotation;
}

NNewExpType::~NNewExpType()
{
    delete this->t;
    delete this->bes;
    delete this->bs;
}

void NNewExpType::print(ostream *out)
{
    *out << string(indentation * 2, ' ')
         << "<newexp> --> NEW <type>"
         << endl;
    indentation++;
    static_cast<NSimpleType *>(this->t)->printClipped(out);
    // inject type brackets between type and next
    if (this->bes && !this->bs)
    {
        this->bes->printType(out, true);
    }
    if (this->bs && !this->bes)
    {
        this->bs->print(out);
    }
    if (this->bs && this->bes)
    {
        this->bes->printType(out, false);
        this->bs->print(out);
    }
    if (!this->bes && !this->bs)
    {
        *out << endl;
    }
    static_cast<NSimpleType *>(this->t)->printNext(out);
    indentation--;
    if (this->next)
    {
        this->next->print(out);
    }
    indentation++;
    if (this->bes)
    {
        this->bes->printExpression(out);
    }
    indentation--;
}

NNewExpIdArgs::NNewExpIdArgs(NId *i, NArg *a)
{
    this->id = i;
    this->args = a;
    this->next = 0;
    this->annotation = i->annotation;
}

NNewExpIdArgs::~NNewExpIdArgs()
{
    delete this->id;
    delete this->args;
}

void NNewExpIdArgs::print(ostream *out)
{
    *out << string(indentation * 2, ' ')
         << "<newexp> --> NEW ID ( <arglist> )"
         << endl;
    indentation++;
    this->id->print(out);
    *out << endl;
    this->args->print(out);
    indentation--;
    if (this->next)
    {
        this->next->print(out);
    }
}