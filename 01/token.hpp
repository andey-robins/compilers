#ifndef TOKEN_HPP
#define TOKEN_HPP

enum TOKEN
{
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

    // KEYWORDS
    THIS,
    IF,
    ELSE,
    WHILE,

    // IDENTIFIER
    ID,

    // NUMBERS
    INT,
    FLOAT,

    // WHITESPACE
    NEWLINE,
    SPACE,
    TAB,

    // MISC TOKENS
    VALUE,
    UNKNOWN,
    EOFTOKEN
};

TOKEN stringToToken(std::string tString);

#endif