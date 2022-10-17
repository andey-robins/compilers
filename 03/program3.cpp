/*
 * program3.cpp
 * Andey Robins
 * 10/1/22
 * Compilers Program 3
 *
 * This file contains the main() function for the program, which drives the entire lexer.
 * It also includes a definition for the pretty printer used in the output for program3
 */

#include <iostream>
#include <iomanip>
#include <FlexLexer.h>
#include <typeinfo>
#include "nodes.hpp"
#include "program3.tab.hpp"
#include "program3.hpp"

yyFlexLexer lexer;
Node *tree;
int indentation = 0;

int main()
{
    tree = 0;

    yyparse();

    // Two spaces to separate errors from parse tree
    cout << endl
         << endl;
    tree->print(&cout);
    cout << endl;
    return 0;
}