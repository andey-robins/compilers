#include <iostream>
#
#include <FlexLexer.h>
#include "program2.hpp"

int main()
{
    FlexLexer *lexer = new yyFlexLexer;
    int rtn = lexer->yylex();

    do {
        std::string tokenStr = lexer->YYText();
        std::cout << tokenStr << std::endl;
    } while ((rtn = lexer->yylex()) != 0);

    return 0;
}