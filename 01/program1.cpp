#include <iostream>
#include <string>
#include <FlexLexer.h>

using std::string;

string lineNumber;
string colNumber;
string type;
string length;

int main()
{
    FlexLexer *scanner = new yyFlexLexer;
    int rtn;

    std::cout << "Processing the input\n"
              << std::endl;
    while ((rtn = scanner->yylex()) != 0)
    {
        std::cout << scanner->lineno() << "  " << std::setw(3) << lineNumber;
        std::cout << scanner->columnno() << "  " << std::setw(3) << colNumber;
        std::cout << scanner->type() << "  " << std::setw(3) << type;
        std::cout << scanner->length() << "  " << std::setw(3) << length;
        std::cout << scanner->YYText() << "  " << std::setw(3) << std::endl;
    }

    std::cout << "\nProgram1 done" << std::endl;

    return 0;
}