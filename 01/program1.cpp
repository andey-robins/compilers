#include <iostream>
#include <iomanip>
#include <string>
#include <FlexLexer.h>
#include "program1.hpp"

using std::cout;
using std::endl;
using std::left;
using std::setw;
using std::string;

string lineNumber;
string colNumber;
string type;
string length;

int main()
{
    FlexLexer *scanner = new yyFlexLexer;
    int rtn = scanner->yylex();
    int col = 1;

    cout << "Processing the input\n"
         << endl;

    // table header
    cout << "Line     Column   Type     Length   Value" << left << endl;

    do
    {
        string token_str = scanner->YYText();
        TOKEN token = stringToToken(token_str);
        col = getNextColumn(token, token_str, col);

        printTokenLine(scanner->lineno(), col, type, scanner->YYLeng(), token_str);

    } while (((rtn = scanner->yylex()) != 0));

    std::cout
        << "\nProgram1 done" << std::endl;

    return 0;
}

void printTokenLine(int line_no, int col_no, string type, int length, string token)
{
    if (strcmp(token.c_str(), " ") == 0)
    {
        return;
    }

    cout << setw(8)
         << line_no << " " << setw(8) << left
         << col_no << " " << setw(8) << left
         << type << " " << setw(8) << left
         << length << " " << setw(8) << left
         << token << " " << setw(8) << left
         << endl;
}

int getNextColumn(TOKEN token, string tok_str, int col_no)
{
    if (token == TAB)
    {
        return col_no + ((col_no + 1) % 8);
    }
    else if (token == NEWLINE)
    {
        return 1;
    }
    else
    {
        return col_no + tok_str.length();
    }
}
