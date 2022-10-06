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
#include "program3.tab.hpp"
#include "program3.hpp"


using std::cout;
using std::endl;
using std::left;
using std::string;
using std::setw;

yyFlexLexer lexer;
// Node* tree;

int main() {
    yyparse();

    return 0;
}