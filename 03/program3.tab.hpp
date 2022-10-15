/* A Bison parser, made by GNU Bison 3.0.4.  */

/* Bison interface for Yacc-like parsers in C

   Copyright (C) 1984, 1989-1990, 2000-2015 Free Software Foundation, Inc.

   This program is free software: you can redistribute it and/or modify
   it under the terms of the GNU General Public License as published by
   the Free Software Foundation, either version 3 of the License, or
   (at your option) any later version.

   This program is distributed in the hope that it will be useful,
   but WITHOUT ANY WARRANTY; without even the implied warranty of
   MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
   GNU General Public License for more details.

   You should have received a copy of the GNU General Public License
   along with this program.  If not, see <http://www.gnu.org/licenses/>.  */

/* As a special exception, you may create a larger work that contains
   part or all of the Bison parser skeleton and distribute that work
   under terms of your choice, so long as that work isn't itself a
   parser generator using the skeleton or a modified version thereof
   as a parser skeleton.  Alternatively, if you modify or redistribute
   the parser skeleton itself, you may (at your option) remove this
   special exception, which will cause the skeleton and the resulting
   Bison output files to be licensed under the GNU General Public
   License without this special exception.

   This special exception was added by the Free Software Foundation in
   version 2.2 of Bison.  */

#ifndef YY_YY_PROGRAM3_TAB_HPP_INCLUDED
# define YY_YY_PROGRAM3_TAB_HPP_INCLUDED
/* Debug traces.  */
#ifndef YYDEBUG
# define YYDEBUG 0
#endif
#if YYDEBUG
extern int yydebug;
#endif

/* Token type.  */
#ifndef YYTOKENTYPE
# define YYTOKENTYPE
  enum yytokentype
  {
    SEMI = 260,
    DOT = 261,
    ID = 262,
    NUMBER = 263,
    null = 264,
    READ = 265,
    NEW = 266,
    THIS = 267,
    LPAREN = 268,
    RPAREN = 269,
    LBRACKET = 270,
    RBRACKET = 271,
    PLUS = 272,
    MINUS = 273,
    NOT = 274,
    OR = 275,
    TIMES = 276,
    DIV = 277,
    MOD = 278,
    AND = 279,
    EQ = 280,
    NE = 281,
    GE = 282,
    LE = 283,
    GT = 284,
    LT = 285,
    INT = 286,
    ER_WD = 287,
    ER_CH = 288,
    TAB = 289,
    WHILE = 290,
    NULLT = 291,
    RETURN = 292,
    CLASS = 293,
    PRINT = 294,
    VOID = 295,
    ELSE = 296,
    IF = 297,
    COMMA = 298,
    ASSIGN = 299,
    KEY_INT = 300,
    RBRACE = 301,
    LBRACE = 302
  };
#endif

/* Value type.  */
#if ! defined YYSTYPE && ! defined YYSTYPE_IS_DECLARED

union YYSTYPE
{
#line 34 "program3.ypp" /* yacc.c:1909  */

    Node *ttype;

#line 104 "program3.tab.hpp" /* yacc.c:1909  */
};

typedef union YYSTYPE YYSTYPE;
# define YYSTYPE_IS_TRIVIAL 1
# define YYSTYPE_IS_DECLARED 1
#endif


extern YYSTYPE yylval;

int yyparse (void);

#endif /* !YY_YY_PROGRAM3_TAB_HPP_INCLUDED  */
