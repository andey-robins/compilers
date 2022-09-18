/*
 * program2.cpp
 * Andey Robins
 * 9/17/22
 * Compilers Program 2
 *
 * This file contains the main() function for the program, which drives the entire lexer.
 * It also includes a definition for the pretty printer used in the output for program1
 */

#include <iostream>
#include <iomanip>
#include <FlexLexer.h>
#include "program2.hpp"

using std::cout;
using std::endl;
using std::left;
using std::string;
using std::setw;

int main()
{
    FlexLexer *lexer = new yyFlexLexer;
    int rtn = lexer->yylex();

    int errors = 0;

    cout << "Line     Column   Token    Value" << left << endl;

    do {
        string tokenStr = lexer->YYText();
        int lineNum = lexer->lineno();

        if (rtn == TOKEN::NEWLINE) {
            // for newline, correct the line number output from flex to match expected
            printTokenLine(lineNum-1, col, token, string(""));
        }
        else if (rtn == TOKEN::ID || rtn == TOKEN::VAL_INT) {
            // these are the token types that also include important information in the value
            printTokenLine(lineNum, col, token, tokenStr);
        }
        else if (rtn == TOKEN::ER_CH) {
            errors++;
            printTokenLine(lineNum, col, token, tokenStr.substr(0, 1));
        }
        else if (rtn == TOKEN::ER_WD) {
            errors++;
            printTokenLine(lineNum, col, token, tokenStr);
        }
        else {
            printTokenLine(lineNum, col, token, string(""));
        }

        // exit early if the lexer finds more than 20 errors
        if (errors > 20) {
            printTokenLine(lineNum, col, string("ERRORS"), string(""));
            break;
        }
    } while ((rtn = lexer->yylex()) != 0);

    return 0;
}

// a pretty printer which writes a line of information to the standard output
void printTokenLine(int line_no, int col_no, string token, string value)
{
    cout << setw(8)
         << line_no << " " << setw(8) << left
         << col_no << " " << setw(8) << left
         << token << " " << setw(8) << left
         << value << " " << setw(8) << left
         << endl;
}