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
    // cout << "statement" << endl;
    if (derivedAssign)
    {
        // cout << "derivedassign" << endl;
        derivedAssign->print(out);
    }
    else if (derivedCall)
    {
        // cout << "derivedcall" << endl;
        derivedCall->print(out);
    }
    else
    {
        // cout << "derivedother" << endl;
    }
}

void NStatement::addSymbols(SymbolTree *node)
{
    auto *derivedAssign = dynamic_cast<NStateAssign *>(this);
    auto *derivedCall = dynamic_cast<NStateCall *>(this);
    auto *derivedWhile = dynamic_cast<NStateWhile *>(this);
    auto *derivedReturn = dynamic_cast<NStateReturn *>(this);
    auto *derivedBlock = dynamic_cast<NStateBlock *>(this);
    auto *derivedCond = dynamic_cast<NStateCond *>(this);

    if (derivedAssign)
    {
        // cout << "derived assign addsymbol" << endl;
        derivedAssign->addSymbols(node);
    }
    else if (derivedCall)
    {
        // cout << "derived call addsymbol" << endl;
        derivedCall->addSymbols(node);
    }
    else if (derivedWhile)
    {
        // cout << "derived while addsymbol" << endl;
        derivedWhile->addSymbols(node);
    }
    else if (derivedReturn)
    {
        // cout << "derived return addsymbol" << endl;
        derivedReturn->addSymbols(node);
    }
    else if (derivedBlock)
    {
        // cout << "derived block addsymbol" << endl;
        derivedBlock->addSymbols(node);
    }
    else if (derivedCond)
    {
        // cout << "derived cond addsymbol" << endl;
        derivedCond->addSymbols(node);
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

void NStateAssign::addSymbols(SymbolTree *node)
{
    // check for assign statements of new expressions
    // cout << "NStateAssign" << endl;
    // cout << this->exp->annotation << endl;
    auto derivedNewExp = dynamic_cast<NExpNewExp *>(this->exp);
    if (derivedNewExp)
    {
        // check that the declared type exists
        string type = node->lookupSymbol(derivedNewExp->annotation);
        if (type == "" && derivedNewExp->annotation != "int")
        {
            cout << "Semantic Error: type "
                 << derivedNewExp->annotation
                 << " not found in symbol table"
                 << endl;
        }
        else
        {
            // check that the left and right types match
            string targetType = node->lookupSymbol(node->lookupSymbol(this->name->annotation));
            if (derivedNewExp->annotation == "int")
            {
                type = "int";
            }
            if (targetType == "" || targetType != type)
            {

                cout << "Semantic Error: mismatched types"
                     << endl
                     << "---------------------"
                     << endl
                     << "| Type of the left hand side does not match "
                     << endl
                     << "| the type of the right hand side"
                     << endl
                     << "|"
                     << endl
                     << "| left type -> "
                     << ((targetType == "") ? "void" : targetType)
                     << endl
                     << "| right type -> "
                     << ((type == "") ? "void" : type)
                     << endl
                     << "---------------------"
                     << endl
                     << endl;
            }
        }
    }

    this->name->addSymbols(node);
    // this->exp->addSymbols(node);
    if (dynamic_cast<NStatement *>(this->next))
    {
        static_cast<NStatement *>(this->next)->addSymbols(node);
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

void NStateCall::addSymbols(SymbolTree *node)
{
    string callType = node->lookupSymbol(this->name->annotation);
    if (callType.length() >= 16 && callType.substr(0, 16) == "constructor_type")
    {
        cout << "Semantic Error: calling constructors is disallowed" << endl;
    }

    if (this->next)
    {
        static_cast<NStatement *>(this->next)->addSymbols(node);
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

void NStateReturn::addSymbols(SymbolTree *node)
{
    string funcRetType = node->getTable()->lookupSymbol("method_type");
    if (funcRetType == "")
    {
        cout << "Semantic Error: invalid return statement"
             << endl
             << "---------------------"
             << endl
             << "| return was called outside of a method"
             << endl
             << "|"
             << endl
             << "| remove the statement in question and try again"
             << endl
             << "---------------------"
             << endl
             << endl;
    }
    else if (funcRetType == "void" && this->oe->maybe())
    {
        cout << "Semantic Error: invalid return statement"
             << endl
             << "---------------------"
             << endl
             << "| method has return type void but tries to return a value "
             << endl
             << "|"
             << endl
             << "| remove the value from the return or update the return type"
             << endl
             << "---------------------"
             << endl
             << endl;
    }
    else if (funcRetType != "void" && !this->oe->maybe())
    {
        cout << "Semantic Error: invalid return statement"
             << endl
             << "---------------------"
             << endl
             << "| function does not return a value,"
             << endl
             << "| has a return statement, "
             << endl
             << "| and is not declared void "
             << endl
             << "---------------------"
             << endl
             << endl;
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

void NStateBlock::addSymbols(SymbolTree *node)
{
    this->block->addSymbols(node);
    if (dynamic_cast<NStatement *>(this->next))
    {
        static_cast<NStatement *>(this->next)->addSymbols(node);
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