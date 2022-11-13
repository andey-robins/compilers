/*
 * program5.cpp
 * Andey Robins
 * 11/7/22
 * Compilers Program 5
 *
 * This file contains the main() function for the program, which drives the entire lexer.
 * It also includes a definition for the pretty printer used in the output for program3
 */

#include <iostream>
#include <iomanip>
#include <FlexLexer.h>
#include <typeinfo>
#include "nodes.hpp"
#include "program5.tab.hpp"
#include "program5.hpp"

yyFlexLexer lexer;
BaseNode *ast;
int indentation = 0;

int main()
{
    ast = 0;
    yyparse();

    // Two spaces to separate errors from parse tree
    cout << endl
         << endl;
    ast->print();
    cout << endl;
    return 0;
}