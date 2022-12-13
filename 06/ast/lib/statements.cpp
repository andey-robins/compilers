/*
 * statements.cpp
 * Andey Robins
 * 12/2/22
 * Compilers Program 6
 *
 *
 */

#include "../include/nodes.hpp"
#include <typeinfo>

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
        // cout << "derivedother print" << endl;
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

    // cout << "typechecking statement" << endl;

    if (derivedAssign)
    {
        // cout << "derived assign addsymbol" << endl;
        derivedAssign->typecheck(node);
    }
    else if (derivedCall)
    {
        // cout << "derived call addsymbol" << endl;
        derivedCall->typecheck(node);
    }
    else if (derivedWhile)
    {
        // cout << "derived while addsymbol" << endl;
        derivedWhile->typecheck(node);
    }
    else if (derivedReturn)
    {
        // cout << "derived return addsymbol" << endl;
        derivedReturn->typecheck(node);
    }
    else if (derivedBlockStmt)
    {
        // cout << "derived block statement addsymbol" << endl;
        derivedBlock->typecheck(node);
    }
    else if (derivedCond)
    {
        // cout << "derived cond addsymbol" << endl;
        derivedCond->typecheck(node);
    }
    else if (derivedBlock)
    {
        // cout << "derived NBlock in statement" << endl;
        SymbolTree *child = new SymbolTree();
        node->setChild(child);
        child->setParent(node);
        derivedBlock->typecheck(child);
    }
    else
    {
        // cout << "derived no statement type" << endl;
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
    // cout << "NStateAssign" << endl;
    // cout << this->exp->annotation << endl;
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
        // cout << "alternative discovery of expression annotation" << endl;
        type = (this->exp->annotation == "int" || this->exp->annotation == "void")
                   ? this->exp->annotation
                   : node->lookupSymbol(this->exp->annotation);
    }
    // cout << "done with type discovery" << endl;
    // cout << type << endl;

    // check that the left and right types match
    // cout << this->name->annotation << endl;
    // cout << node->lookupSymbol(this->name->annotation) << endl;
    string targetType = node->lookupSymbol(this->name->annotation);
    // cout << targetType << endl;
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
    // cout << "going to typecheck exp" << endl;
    if (this->exp)
        this->exp->typecheck(node);
    // cout << "going to next" << endl;
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
}

NCondition::NCondition(NExp *e, NBlock *t, NBlock *f)
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
    // cout << "typechecked condition" << endl;
}