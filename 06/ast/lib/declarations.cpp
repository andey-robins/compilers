/*
 * declarations.cpp
 * Andey Robins
 * 12/2/22
 * Compilers Program 6
 *
 *
 */

#include "../include/nodes.hpp"

NClassDecl::NClassDecl(NId *id, NClassBody *cb)
{
    this->className = id;
    this->classBody = cb;
}

NClassDecl::~NClassDecl()
{
    delete this->className;
    delete this->classBody;
}

void NClassDecl::print(ostream *out)
{
    *out << string(indentation * 2, ' ')
         << "<classdec> --> CLASS ID <classbody>"
         << endl;
    indentation++;
    this->className->print(out);
    *out << endl;
    this->classBody->print(out);
    indentation--;
}

void NClassDecl::typecheck(SymbolTree *node)
{
    // cout << "class decl" << endl;
    // cout << this->className->getSymbol() << endl;
    // in this context, node == root
    node->registerSymbolWithValue(this->className->getSymbol(), "class_type");
    SymbolTree *child = new SymbolTree();
    node->setChild(child);
    child->setParent(node);
    if (this->classBody)
    {
        this->classBody->typecheck(child);
    }

    // continue to next class declaration
    auto *derivedNext = dynamic_cast<NClassDecl *>(this->next);
    if (derivedNext)
    {
        static_cast<NClassDecl *>(this->next)->typecheck(node);
    }
}

NClassBody::NClassBody(NVarDecl *declHead)
{
    this->next = declHead;
}

NClassBody::NClassBody(NConstDecl *declHead)
{
    this->next = declHead;
}

NClassBody::NClassBody(NMethDecl *declHead)
{
    this->next = declHead;
}

NClassBody::~NClassBody()
{
    if (this->next)
    {
        delete this->next;
    }
}

void NClassBody::print(ostream *out)
{
    *out << string(indentation * 2, ' ')
         << "<classbody> --> { <vardecs> <consdecs> <methdecs> }"
         << endl;
    indentation++;
    if (this->next)
    {
        this->next->print(out);
    }
    indentation--;
}

void NClassBody::typecheck(SymbolTree *node)
{
    // cout << "class body typecheck" << endl;
    if (this->next)
    {
        auto *derivedVar = dynamic_cast<NVarDecl *>(this->next);
        auto *derivedCons = dynamic_cast<NConstDecl *>(this->next);
        auto *derivedMeth = dynamic_cast<NMethDecl *>(this->next);

        if (derivedVar)
        {
            // cout << "derived var in class body" << endl;
            derivedVar->typecheck(node);
        }
        else if (derivedCons)
        {
            // cout << "derived constructor in class body" << endl;
            derivedCons->typecheck(node);
        }
        else if (derivedMeth)
        {
            // cout << "derived method in class body" << endl;
            derivedMeth->typecheck(node);
        }
    }
}

NConstDecl::NConstDecl(NId *id, NParam *p, NBlock *b)
{
    this->id = id;
    this->params = p;
    this->block = b;
    this->annotation = "constructor";
}

NConstDecl::NConstDecl(NId *id, NBlock *b)
{
    this->id = id;
    this->block = b;
    this->annotation = "constructor";
}

void NConstDecl::print(ostream *out)
{
    *out << string(indentation * 2, ' ')
         << "<consdecs> --> <consdecs> <consdec>"
         << endl;
    indentation++;
    if (this->params->getText() == "epsilon")
    {
        *out << string(indentation * 2, ' ')
             << "<consdec> --> ID () <block>"
             << endl;
        indentation++;
        this->id->print(out);
        *out << endl;
        this->block->print(out);
        indentation -= 2;
    }
    else
    {
        *out << string(indentation * 2, ' ')
             << "<consdec> --> ID ( <params> ) <block>"
             << endl;
        indentation++;
        this->id->print(out);
        *out << endl;
        *out << string(indentation * 2, ' ')
             << "<paramlist> --> <param>"
             << endl;
        indentation++;
        this->params->print(out);
        indentation--;
        this->block->print(out);
        indentation -= 2;
    }

    // expand the <constdecs> nonterminal
    if (this->next)
    {
        this->next->print(out);
    }
}

void NConstDecl::typecheck(SymbolTree *node)
{
    string value;
    if (this->params)
    {
        value = "constructor_type <- " + this->params->getMangling();
    }
    else
    {
        value = "constructor_type <-";
    }
    node->registerSymbolWithValue(this->id->getSymbol(), value);
    SymbolTree *child = new SymbolTree();
    node->setChild(child);
    child->setParent(node);
    this->block->typecheck(child);
    if (this->next)
    {
        auto *derivedCons = dynamic_cast<NConstDecl *>(this->next);
        auto *derivedMeth = dynamic_cast<NMethDecl *>(this->next);

        if (derivedCons)
        {
            derivedCons->typecheck(node);
        }
        else if (derivedMeth)
        {
            derivedMeth->typecheck(node);
        }
    }
}

NMethDecl::NMethDecl(NResultType *rt, NId *id, NParam *p, NBlock *b)
{
    this->resType = rt;
    this->id = id;
    this->params = p;
    this->block = b;
}

void NMethDecl::print(ostream *out)
{
    *out << string(indentation * 2, ' ')
         << "<methdecs> --> <methdecs> <methdec>"
         << endl;
    indentation++;
    if (this->params->getText() == "epsilon")
    {
        *out << string(indentation * 2, ' ')
             << "<methdec> --> <resulttype> ID () <block>"
             << endl;
        indentation++;
        this->resType->print(out);
        this->id->print(out);
        *out << endl;
        this->block->print(out);
        indentation -= 2;
    }
    else
    {
        *out << string(indentation * 2, ' ')
             << "<methdec> --> <resulttype> ID ( <params> ) <block>"
             << endl;
        indentation++;
        this->resType->print(out);
        this->id->print(out);
        *out << endl;
        *out << string(indentation * 2, ' ')
             << "<paramlist> --> <param>"
             << endl;
        indentation++;
        this->params->print(out);
        indentation--;
        this->block->print(out);
        indentation -= 2;
    }

    // expand the <constdecs> nonterminal
    if (this->next)
    {
        this->next->print(out);
    }
}

void NMethDecl::typecheck(SymbolTree *node)
{
    // cout << "in method decl" << endl;
    // check if method is main for type checking
    if (this->id->getSymbol() == "main")
    {
        if (node->lookupSymbol("main") != "")
        {
            this->semanticError("main already declared",
                                "Previous declaration has type: " + node->lookupSymbol("main"),
                                "Discarding previous declaration.",
                                "If this is not the desired behavior, eliminate the latter declaration(s)");
        }

        // cout << "checked for main already declared" << endl;

        if (!(this->resType->getType() == "void" || this->resType->getType() == "int"))
        {
            this->semanticError("invalid return type for main",
                                "Main has delcared return type: " + this->resType->getType(),
                                "Expected type to be int or void");
        }

        // cout << "checked for valid return types" << endl;
        // cout << this->params->getMangling() << endl;
        // cout << "^^^ was the mangling" << endl;
        if (this->params->getMangling() != "void" && this->params->getMangling() != "")
        {
            this->semanticError("function main takes no arguments",
                                "Main has declared parameter types: " + this->params->getMangling(),
                                "Expected no parameters");
        }
    }
    // cout << "done typechecking for method" << endl;

    // put method in symbol table
    string value = "method_type " + this->resType->getType() + " <- " + this->params->getMangling();
    node->registerSymbolWithValue(this->id->getSymbol(), value);
    // create the sub-table for the method's internal scope
    SymbolTree *child = new SymbolTree();
    child->getTable()->registerSymbolWithValue("method_type", this->resType->getType());
    node->setChild(child);
    child->setParent(node);

    // cout << "moving to typecheck params" << endl;
    this->params->typecheck(child);
    // cout << "moving to typecheck block" << endl;
    this->block->typecheck(child);

    // continue adding next set of symbols to the table
    if (this->next)
    {
        auto *derivedMeth = dynamic_cast<NMethDecl *>(this->next);

        if (derivedMeth)
        {
            // cout << "derived method as next from method" << endl;
            derivedMeth->typecheck(node);
        }
        else
        {
            // derives an epsilon as next when at the end
            // cout << "failed to derive next" << endl;
            // cout << typeid(this->next).name() << endl;
            // cout << this->next->annotation << endl;
        }
    }
}