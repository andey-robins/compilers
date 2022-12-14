/*
 * statements.cpp
 * Andey Robins
 * 12/2/22
 * Compilers Program 6
 *
 * Implementations of statement classes
 */

#include "../include/nodes.hpp"
#include <typeinfo>
#include <bits/stdc++.h>

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

void NStatement::typecheck(SymbolTree *node)
{
    auto *derivedAssign = dynamic_cast<NStateAssign *>(this);
    auto *derivedCall = dynamic_cast<NStateCall *>(this);
    auto *derivedWhile = dynamic_cast<NStateWhile *>(this);
    auto *derivedReturn = dynamic_cast<NStateReturn *>(this);
    auto *derivedBlockStmt = dynamic_cast<NStateBlock *>(this);
    auto *derivedCond = dynamic_cast<NStateCond *>(this);
    auto *derivedBlock = dynamic_cast<NBlock *>(this);

    if (derivedAssign)
    {
        derivedAssign->typecheck(node);
    }
    else if (derivedCall)
    {
        derivedCall->typecheck(node);
    }
    else if (derivedWhile)
    {
        derivedWhile->typecheck(node);
    }
    else if (derivedReturn)
    {
        derivedReturn->typecheck(node);
    }
    else if (derivedBlockStmt)
    {
        derivedBlock->typecheck(node);
    }
    else if (derivedCond)
    {
        derivedCond->typecheck(node);
    }
    else if (derivedBlock)
    {
        SymbolTree *child = new SymbolTree();
        node->setChild(child);
        child->setParent(node);
        derivedBlock->typecheck(child);
    }
}

NStateAssign::NStateAssign(NName *n, NExp *e)
{
    this->name = n;
    this->exp = e;
    this->next = 0;
    this->line = n->line + e->line;
    this->lineNumber = n->lineNumber;
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

void NStateAssign::typecheck(SymbolTree *node)
{
    // check for assign statements of new expressions
    string type;
    auto derivedNewExp = dynamic_cast<NExpNewExp *>(this->exp);

    if (derivedNewExp)
    {
        // check that the declared type exists
        type = node->lookupSymbol(derivedNewExp->annotation);
        if (type == "" && derivedNewExp->annotation != "int")
        {
            this->semanticError("type not found", "check for declarations of the types in this line", "Unknown Type => " + derivedNewExp->annotation);
        }
    }
    else
    {
        type = (this->exp->annotation == "int" || this->exp->annotation == "void")
                   ? this->exp->annotation
                   : node->lookupSymbol(this->exp->annotation);
    }

    // check that the left and right types match
    string targetType = node->lookupSymbol(this->name->annotation);
    if (targetType == "" || targetType != type)
    {
        targetType = node->lookupSymbol(targetType);
        if (targetType != type)
        {
            this->semanticError("mismatched types",
                                "Type of the left hand side does not match the right",
                                "Left type => " + ((targetType == "") ? "void" : targetType),
                                "Right type => " + ((type == "") ? "void" : type));
        }
    }

    if (this->name)
        this->name->typecheck(node);
    if (this->exp)
        this->exp->typecheck(node);
    if (dynamic_cast<NStatement *>(this->next))
    {
        static_cast<NStatement *>(this->next)->typecheck(node);
    }
}

NStateCall::NStateCall(NName *n, NArg *a)
{
    this->name = n;
    this->args = a;
    this->next = 0;
    this->line = n->line;
    this->lineNumber = n->lineNumber;

    if (a->getText() != "epsilon")
    {
        this->argCount++;
        NArg *curr = dynamic_cast<NArg *>(a->getNext());
        while (dynamic_cast<NArg *>(curr))
        {
            this->argCount++;
            curr = static_cast<NArg *>(curr->getNext());
        }
        cout << this->argCount << endl;
    }
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

void NStateCall::typecheck(SymbolTree *node)
{
    string callType = node->lookupSymbol(this->name->annotation);
    if (callType.length() >= 16 && callType.substr(0, 16) == "constructor_type")
    {
        this->semanticError("calling constructor",
                            "constructors may not be invoked",
                            "check the name called and the declaration of the invoked code");
    }

    int idx = callType.find("<-");
    string neededArgTypes = callType.substr(((idx + 3 > callType.length()) ? callType.length() : idx + 3), callType.length());

    if (this->argCount == 0)
    {
        // zero arguments
        if (neededArgTypes.length() >= 1)
        {
            this->semanticError("mismatched argument number",
                                "Incorrect number of arguments provided",
                                "Expected => " + neededArgTypes);
        }
    }
    else
    {
        if (neededArgTypes.find("x") != string::npos)
        {
            cout << neededArgTypes.find("x") << endl;
            cout << std::count(neededArgTypes.begin(), neededArgTypes.end(), 'x') + 1 << endl;
            // multiple args in definition
            if (std::count(neededArgTypes.begin(), neededArgTypes.end(), 'x') + 1 != this->argCount)
            {
                this->semanticError("mismatched argument number",
                                    "Incorrect number of arguments provided",
                                    "Expected => " + neededArgTypes);
            }
        }
        else
        {
            if (this->argCount != 1)
            {
                this->semanticError("mismatched argument number",
                                    "Incorrect number of arguments provided",
                                    "Expected => " + neededArgTypes);
            }
        }
    }

    if (this->next)
    {
        static_cast<NStatement *>(this->next)->typecheck(node);
    }
}

NStateWhile::NStateWhile(NExp *e, NStatement *s)
{
    this->e = e;
    this->s = s;
    this->next = 0;
    this->line = e->line;
    this->lineNumber = e->lineNumber;
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
    this->line = oe->line;
    this->lineNumber = oe->lineNumber;
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

void NStateReturn::typecheck(SymbolTree *node)
{
    string funcRetType = node->getTable()->lookupSymbol("method_type");
    if (funcRetType == "")
    {
        this->semanticError("invalid return statement",
                            "return was called outside of a method",
                            "remove the statement in question");
    }
    else if (funcRetType == "void" && this->oe->maybe())
    {
        this->semanticError("invalid return statement",
                            "method has return type void but tries to return a value",
                            "remove the value from the return or update the return type");
    }
    else if (funcRetType != "void" && !this->oe->maybe())
    {
        this->semanticError("invalid return statement",
                            "function does not return a value,",
                            "has a return statement,",
                            "and is not declared void");
    }
}

NStateBlock::NStateBlock(NBlock *b)
{
    this->block = b;
    this->line = b->line;
    this->lineNumber = b->lineNumber;
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

void NStateBlock::typecheck(SymbolTree *node)
{
    this->block->typecheck(node);
    if (dynamic_cast<NStatement *>(this->next))
    {
        static_cast<NStatement *>(this->next)->typecheck(node);
    }
}

NCondition::NCondition(NExp *e, NBlock *s)
{
    this->cond = e;
    this->trueBlock = s;
    this->falseBlock = 0;
    this->next = 0;
    this->lineNumber = e->lineNumber;
    this->line = e->line;
}

NCondition::NCondition(NExp *e, NBlock *t, NBlock *f)
{
    this->cond = e;
    this->trueBlock = t;
    this->falseBlock = f;
    this->next = 0;
    this->lineNumber = e->lineNumber;
    this->line = e->line;
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

void NCondition::typecheck(SymbolTree *node)
{
    this->cond->typecheck(node);
    static_cast<NBlock *>(this->trueBlock)->typecheck(node);
    if (dynamic_cast<NBlock *>(this->falseBlock))
    {
        static_cast<NBlock *>(this->falseBlock)->typecheck(node);
    }
}

NStateCond::NStateCond(NCondition *c)
{
    this->cond = c;
    this->next = 0;
    this->line = c->line;
    this->lineNumber = c->lineNumber;
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

void NStateCond::typecheck(SymbolTree *node)
{
    this->cond->typecheck(node);
}