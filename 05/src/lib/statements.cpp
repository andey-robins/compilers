/*
 * statements.cpp
 * Andey Robins
 * 11/7/22
 * Compilers Program 5
 *
 *
 */

#include "nodes.hpp"

NStateAssign::NStateAssign(NName *n, NExp *e)
{
    this->name = n;
    this->exp = e;
}

NStateAssign::~NStateAssign()
{
    delete this->name;
    delete this->exp;
}

void NStateAssign::print()
{
    cout << string(indentation * 2, ' ')
         << "<statement> --> <name> = <expression> SEMI"
         << endl;
    indentation++;
    this->name->print();
    this->exp->print();
    indentation--;
    if (this->next)
    {
        this->next->print();
    }
}

NStateCall::NStateCall(NName *n, NArg *a)
{
    this->name = n;
    this->args = a;
}

NStateCall::~NStateCall()
{
    delete this->name;
    delete this->args;
}

void NStateCall::print()
{
    cout << string(indentation * 2, ' ')
         << "<statement> --> <name> ( <argList> ) SEMI"
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

NStateWhile::NStateWhile(NExp *e, NStatement *s)
{
    this->e = e;
    this->s = s;
}

NStateWhile::~NStateWhile()
{
    delete this->e;
    delete this->s;
}

void NStateWhile::print()
{
    cout << string(indentation * 2, ' ')
         << "<statement> --> WHILE ( <exp> ) <statement>"
         << endl;
    indentation++;
    this->e->print();
    this->s->print();
    indentation--;
    if (this->next)
    {
        this->next->print();
    }
}

NStateReturn::NStateReturn(NOptExp *oe)
{
    this->oe = oe;
}

NStateReturn::~NStateReturn()
{
    delete this->oe;
}

void NStateReturn::print()
{
    if (this->oe->maybe())
    {
        cout << string(indentation * 2, ' ')
             << "<statement> --> RETURN <exp>"
             << endl;
        indentation++;
        this->oe->print();
        indentation--;
    }
    else
    {
        cout << string(indentation * 2, ' ')
             << "<statement> --> RETURN"
             << endl;
    }
    if (this->next)
    {
        this->next->print();
    }
}

NStateBlock::NStateBlock(NBlock *b)
{
    this->block = b;
}

NStateBlock::~NStateBlock()
{
    delete this->block;
}

void NStateBlock::print()
{
    cout << string(indentation * 2, ' ')
         << "<statement> --> <block>"
         << endl;
    indentation++;
    this->block->print();
    indentation--;
    if (this->next)
    {
        this->next->print();
    }
}

NCondition::NCondition(NExp *e, NStatement *s)
{
    this->cond = e;
    this->trueBlock = s;
    this->falseBlock = 0;
}

NCondition::NCondition(NExp *e, NStatement *t, NStatement *f)
{
    this->cond = e;
    this->trueBlock = t;
    this->falseBlock = f;
}

NCondition::~NCondition()
{
    delete this->cond;
    delete this->trueBlock;
    if (this->falseBlock)
    {
        delete this->falseBlock;
    }
}

void NCondition::print()
{
    if (this->falseBlock)
    {
        cout << string(indentation * 2, ' ')
             << "<condition> --> IF ( <exp> ) <statement> ELSE <statement>"
             << endl;
        indentation++;
        this->cond->print();
        this->trueBlock->print();
        this->falseBlock->print();
        indentation--;
    }
    else
    {
        cout << string(indentation * 2, ' ')
             << "<condition> --> IF ( <exp> ) <statement>"
             << endl;
        indentation++;
        this->cond->print();
        this->trueBlock->print();
        indentation--;
    }
    if (this->next)
    {
        this->next->print();
    }
}

NStateCond::NStateCond(NCondition *c)
{
    this->cond = c;
}

NStateCond::~NStateCond()
{
    delete this->cond;
}

void NStateCond::print()
{
    cout << string(indentation * 2, ' ')
         << "<statement> --> <condition>"
         << endl;
    indentation++;
    this->cond->print();
    indentation--;
    if (this->next)
    {
        this->next->print();
    }
}