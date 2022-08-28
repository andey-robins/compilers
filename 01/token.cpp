#include <cstring>
#include <string>
#include "token.hpp"

TOKEN stringToToken(std::string tString)
{
    if (strcmp(tString.c_str(), "==") == 0)
    {
        return EQUAL;
    }
    else if (strcmp(tString.c_str(), ">") == 0)
    {
        return GREATER;
    }
    else if (strcmp(tString.c_str(), "<") == 0)
    {
        return LESS;
    }
    else if (strcmp(tString.c_str(), ">=") == 0)
    {
        return GREATER_EQUAL;
    }
    else if (strcmp(tString.c_str(), "<=") == 0)
    {
        return LESS_EQUAL;
    }
    else if (strcmp(tString.c_str(), "!=") == 0)
    {
        return NOT_EQUAL;
    }
    else if (strcmp(tString.c_str(), "||") == 0)
    {
        return OR;
    }
    else if (strcmp(tString.c_str(), "&&") == 0)
    {
        return AND;
    }
    else if (strcmp(tString.c_str(), "+") == 0)
    {
        return PLUS;
    }
    else if (strcmp(tString.c_str(), "-") == 0)
    {
        return MINUS;
    }
    else if (strcmp(tString.c_str(), "*") == 0)
    {
        return MULTIPLY;
    }
    else if (strcmp(tString.c_str(), "/") == 0)
    {
        return DIVIDE;
    }
    else if (strcmp(tString.c_str(), "{") == 0)
    {
        return LBRACE;
    }
    else if (strcmp(tString.c_str(), "}") == 0)
    {
        return RBRACE;
    }
    else if (strcmp(tString.c_str(), "[") == 0)
    {
        return LBRACKET;
    }
    else if (strcmp(tString.c_str(), "]") == 0)
    {
        return RBRACKET;
    }
    else if (strcmp(tString.c_str(), ")") == 0)
    {
        return LPAREN;
    }
    else if (strcmp(tString.c_str(), "(") == 0)
    {
        return RPAREN;
    }
    else if (strcmp(tString.c_str(), ".") == 0)
    {
        return PERIOD;
    }
    else if (strcmp(tString.c_str(), ",") == 0)
    {
        return COMMA;
    }
    else if (strcmp(tString.c_str(), ";") == 0)
    {
        return SEMICOLON;
    }
    else if (strcmp(tString.c_str(), "this") == 0)
    {
        return THIS;
    }
    else if (strcmp(tString.c_str(), "if") == 0)
    {
        return IF;
    }
    else if (strcmp(tString.c_str(), "else") == 0)
    {
        return ELSE;
    }
    else if (strcmp(tString.c_str(), "while") == 0)
    {
        return WHILE;
    }
    else if (strcmp(tString.c_str(), "\n") == 0)
    {
        return NEWLINE;
    }
    else if (strcmp(tString.c_str(), " ") == 0)
    {
        return SPACE;
    }
    else if (strcmp(tString.c_str(), "\t") == 0)
    {
        return TAB;
    }
    else if (tString.c_str()[0] == '/' && tString.c_str()[1] == '*')
    {
        return COMMENT;
    }

    return VALUE;
}