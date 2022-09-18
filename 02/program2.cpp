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

    cout << "Line     Column   Type     Length   Value" << left << endl;

    do {
        string tokenStr = lexer->YYText();
        int lineNum = lexer->lineno();
        int tokenLen = lexer->YYLeng();

        if (type == 11) {
            printTokenLine(lineNum-1, col, type, tokenLen, tokenStr);
        } else {
            printTokenLine(lineNum, col, type, tokenLen, tokenStr);
        }
    } while ((rtn = lexer->yylex()) != 0);

    return 0;
}

void printTokenLine(int line_no, int col_no, int type, int length, string token)
{
    cout << setw(8)
         << line_no << " " << setw(8) << left
         << col_no << " " << setw(8) << left
         << type << " " << setw(8) << left
         << length << " " << setw(8) << left
         << token << " " << setw(8) << left
         << endl;
}