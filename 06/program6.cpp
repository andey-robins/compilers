/*
 * program6.cpp
 * Andey Robins
 * 12/2/22
 * Compilers Program 6
 *
 * This file contains the main() function for the program, which drives the entire lexer.
 * It also includes a definition for the pretty printer used in the output for program3
 */

#define YYDEBUG 1

#include <iostream>
#include <iomanip>
#include <FlexLexer.h>
#include <typeinfo>
#include "program6.hpp"
#include "program6.tab.hpp"

yyFlexLexer lexer;
BaseNode *ast;
SymbolTree *symbols;
SymbolTable *activeSymbols;
extern int indentation;
extern int symbolIndentation;

int main()
{
    yydebug = 0;
    ast = 0;
    symbols = new SymbolTree();
    symbols->registerSymbolWithValue("read", "method_type int <- void");
    symbols->registerSymbolWithValue("print", "method_type void <- []");
    yyparse();

    if (ast)
    {
        static_cast<NProgram *>(ast)->typecheck(symbols);
    }
    cout << endl;
    symbols->print();
    cout << endl;
    return 0;
}