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

#ifndef YY_YY_PROGRAM4_TAB_HPP_INCLUDED
# define YY_YY_PROGRAM4_TAB_HPP_INCLUDED
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
    PLUS = 260,
    MINUS = 261,
    NOT = 262,
    OR = 263,
    SEMI = 264,
    DOT = 265,
    COMMA = 266,
    ID = 267,
    LPAREN = 268,
    RPAREN = 269,
    LBRACKET = 270,
    RBRACKET = 271,
    RBRACE = 272,
    LBRACE = 273,
    NUMBER = 274,
    NULLT = 275,
    READ = 276,
    NEW = 277,
    THIS = 278,
    IF = 279,
    ELSE = 280,
    WHILE = 281,
    RETURN = 282,
    CLASS = 283,
    PRINT = 284,
    VOID = 285,
    TIMES = 286,
    DIV = 287,
    MOD = 288,
    AND = 289,
    EQ = 290,
    NE = 291,
    GE = 292,
    LE = 293,
    GT = 294,
    LT = 295,
    ASSIGN = 296,
    INT = 297,
    ER_WD = 298,
    ER_CH = 299
  };
#endif

/* Value type.  */
#if ! defined YYSTYPE && ! defined YYSTYPE_IS_DECLARED

union YYSTYPE
{
#line 33 "program4.ypp" /* yacc.c:1909  */

    BaseNode *ttype;

#line 101 "program4.tab.hpp" /* yacc.c:1909  */
};

typedef union YYSTYPE YYSTYPE;
# define YYSTYPE_IS_TRIVIAL 1
# define YYSTYPE_IS_DECLARED 1
#endif

/* Location type.  */
#if ! defined YYLTYPE && ! defined YYLTYPE_IS_DECLARED
typedef struct YYLTYPE YYLTYPE;
struct YYLTYPE
{
  int first_line;
  int first_column;
  int last_line;
  int last_column;
};
# define YYLTYPE_IS_DECLARED 1
# define YYLTYPE_IS_TRIVIAL 1
#endif


extern YYSTYPE yylval;
extern YYLTYPE yylloc;
int yyparse (void);

#endif /* !YY_YY_PROGRAM4_TAB_HPP_INCLUDED  */
