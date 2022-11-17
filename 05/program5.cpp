/*
 * program5.cpp
 * Andey Robins
 * 11/7/22
 * Compilers Program 5
 *
 * This file contains the main() function for the program, which drives the entire lexer.
 * It also includes a definition for the pretty printer used in the output for program3
 */

#define YYDEBUG 1

#include <iostream>
#include <iomanip>
#include <FlexLexer.h>
#include <typeinfo>
#include "program5.hpp"
#include "program5.tab.hpp"

yyFlexLexer lexer;
BaseNode *ast;
SymbolTree *symbols;
SymbolTable *activeSymbols;
extern int indentation;
extern int symbolIndentation;

int main()
{
    ast = 0;
    yydebug = 0;
    symbols = new SymbolTree();
    yyparse();

    // Two spaces to separate errors from parse tree
    cout << endl
         << endl;
    // ast->print(&cout);
    if (ast)
    {
        // ast->print(&cout);
        static_cast<NProgram *>(ast)->addSymbols(symbols);
    }

    cout << endl
         << endl;

    symbols->print();

    cout << endl;
    return 0;
}