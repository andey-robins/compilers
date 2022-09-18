/*
 * program2.hpp
 * Andey Robins
 * 9/17/22
 * Compilers Program 2
 *
 * This is the header file associated with program2.cpp.
 * It contains definitions for TOKEN constants that will be replaced with bison token
 * definitions when we begin work with bison.
 * It also declares a pretty print function that is defined in program2.cpp
 */

#ifndef PROGRAM2_HPP
#define PROGRAM2_HPP

#include<string>

extern std::string colStr;
extern std::string token;
extern int col;

enum TOKEN
{
    EOFTOKEN,

    // COMPARISON OPS
    EQUAL,
    GREATER,
    LESS,
    GREATER_EQUAL,
    LESS_EQUAL,
    NOT_EQUAL,

    // LOGICAL OPS
    OR,
    AND,

    // MATH OPS
    PLUS,
    MINUS,
    MULTIPLY,
    DIVIDE,
    MOD,

    // ENCLOSING OPS
    LBRACE,
    RBRACE,
    LBRACKET,
    RBRACKET,
    LPAREN,
    RPAREN,

    // PUNCTUATION
    PERIOD,
    COMMA,
    SEMICOLON,
    NOT,
    ASSIGN,

    // KEYWORDS
    KEY_INT,
    VOID,
    CLASS,
    NEW,
    PRINT,
    READ,
    RETURN,
    THIS,
    IF,
    ELSE,
    WHILE,
    NULLT,

    // IDENTIFIER
    ID,

    // NUMBERS
    VAL_INT,

    // WHITESPACE
    NEWLINE,
    SPACE,
    TAB,

    // MISC TOKENS
    COMMENT,
    VALUE,
    UNKNOWN,

    // ERROR TOKENS
    ER_CH,
    ER_WD,
    ERRORS
};

void printTokenLine(int line_no, int col_no, std::string token, std::string value);

#endif