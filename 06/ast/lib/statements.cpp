/*
 * statements.cpp
 * Andey Robins
 * 12/2/22
 * Compilers Program 6
 *
 *
 */

#include "../include/nodes.hpp"

void NStatement::print(ostream *out)
{
    auto *derivedAssign = dynamic_cast<NStateAssign *>(this);
    auto *derivedCall = dynamic_cast<NStateCall *>(this);

    if (derivedAssign)
    {
        derivedAssign->print(out);
    }
    else if (derivedCall)
    {
        derivedCall->print(out);
    }
}

NStateAssign::NStateAssign(NName *n, NExp *e)
{
    this->name = n;
    this->exp = e;
    this->next = 0;
}

NStateAssign::~NStateAssign()
{
    delete this->name;
    delete this->exp;
}

void NStateAssign::print(ostream *out)
{
    *out << string(indentation * 2, ' ')
         << "<statement> --> <name> = <expression> SEMI"
         << endl;
    indentation++;
    this->name->print(out);
    this->exp->print(out);
    indentation--;
    if (this->next)
    {
        this->next->print(out);
    }
}

NStateCall::NStateCall(NName *n, NArg *a)
{
    this->name = n;
    this->args = a;
    this->next = 0;
}

NStateCall::~NStateCall()
{
    delete this->name;
    delete this->args;
}

void NStateCall::print(ostream *out)
{
    *out << string(indentation * 2, ' ')
         << "<statement> --> <name> ( <argList> ) SEMI"
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

NStateWhile::NStateWhile(NExp *e, NStatement *s)
{
    this->e = e;
    this->s = s;
    this->next = 0;
}

NStateWhile::~NStateWhile()
{
    delete this->e;
    delete this->s;
}

void NStateWhile::print(ostream *out)
{
    *out << string(indentation * 2, ' ')
         << "<statement> --> WHILE ( <exp> ) <statement>"
         << endl;
    indentation++;
    this->e->print(out);
    this->s->print(out);
    indentation--;
    if (this->next)
    {
        this->next->print(out);
    }
}

NStateReturn::NStateReturn(NOptExp *oe)
{
    this->oe = oe;
    this->next = 0;
}

NStateReturn::~NStateReturn()
{
    delete this->oe;
}

void NStateReturn::print(ostream *out)
{
    if (this->oe->maybe())
    {
        *out << string(indentation * 2, ' ')
             << "<statement> --> RETURN <exp>"
             << endl;
        indentation++;
        this->oe->print(out);
        indentation--;
    }
    else
    {
        *out << string(indentation * 2, ' ')
             << "<statement> --> RETURN"
             << endl;
    }
    if (this->next)
    {
        this->next->print(out);
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

void NStateBlock::print(ostream *out)
{
    *out << string(indentation * 2, ' ')
         << "<statement> --> <block>"
         << endl;
    indentation++;
    this->block->print(out);
    indentation--;
    if (this->next)
    {
        this->next->print(out);
    }
}

NCondition::NCondition(NExp *e, NStatement *s)
{
    this->cond = e;
    this->trueBlock = s;
    this->falseBlock = 0;
    this->next = 0;
}

NCondition::NCondition(NExp *e, NStatement *t, NStatement *f)
{
    this->cond = e;
    this->trueBlock = t;
    this->falseBlock = f;
    this->next = 0;
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

void NCondition::print(ostream *out)
{
    if (this->falseBlock)
    {
        *out << string(indentation * 2, ' ')
             << "<condition> --> IF ( <exp> ) <statement> ELSE <statement>"
             << endl;
        indentation++;
        this->cond->print(out);
        this->trueBlock->print(out);
        this->falseBlock->print(out);
        indentation--;
    }
    else
    {
        *out << string(indentation * 2, ' ')
             << "<condition> --> IF ( <exp> ) <statement>"
             << endl;
        indentation++;
        this->cond->print(out);
        this->trueBlock->print(out);
        indentation--;
    }
    if (this->next)
    {
        this->next->print(out);
    }
}

NStateCond::NStateCond(NCondition *c)
{
    this->cond = c;
    this->next = 0;
}

NStateCond::~NStateCond()
{
    delete this->cond;
}

void NStateCond::print(ostream *out)
{
    *out << string(indentation * 2, ' ')
         << "<statement> --> <condition>"
         << endl;
    indentation++;
    this->cond->print(out);
    indentation--;
    if (this->next)
    {
        this->next->print(out);
    }
}