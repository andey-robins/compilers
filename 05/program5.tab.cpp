/* A Bison parser, made by GNU Bison 3.0.4.  */

/* Bison implementation for Yacc-like parsers in C

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

/* C LALR(1) parser skeleton written by Richard Stallman, by
   simplifying the original so-called "semantic" parser.  */

/* All symbols defined below should begin with yy or YY, to avoid
   infringing on user name space.  This should be done even for local
   variables, as they might otherwise be expanded by user macros.
   There are some unavoidable exceptions within include files to
   define necessary library symbols; they are noted "INFRINGES ON
   USER NAME SPACE" below.  */

/* Identify Bison output.  */
#define YYBISON 1

/* Bison version.  */
#define YYBISON_VERSION "3.0.4"

/* Skeleton name.  */
#define YYSKELETON_NAME "yacc.c"

/* Pure parsers.  */
#define YYPURE 0

/* Push parsers.  */
#define YYPUSH 0

/* Pull parsers.  */
#define YYPULL 1




/* Copy the first part of user declarations.  */
#line 9 "program5.ypp" /* yacc.c:339  */


#include <iostream>
#include <FlexLexer.h>
#include <string>
#include <typeinfo>
#include "program5.hpp"
#define YYERROR_VERBOSE

using std::cerr;

class BaseNode;
extern BaseNode *ast;
extern yyFlexLexer lexer;

#define yylex() lexer.yylex()
void yyerror(const char* string);


#line 86 "program5.tab.cpp" /* yacc.c:339  */

# ifndef YY_NULLPTR
#  if defined __cplusplus && 201103L <= __cplusplus
#   define YY_NULLPTR nullptr
#  else
#   define YY_NULLPTR 0
#  endif
# endif

/* Enabling verbose error messages.  */
#ifdef YYERROR_VERBOSE
# undef YYERROR_VERBOSE
# define YYERROR_VERBOSE 1
#else
# define YYERROR_VERBOSE 0
#endif

/* In a future release of Bison, this section will be replaced
   by #include "program5.tab.hpp".  */
#ifndef YY_YY_PROGRAM5_TAB_HPP_INCLUDED
# define YY_YY_PROGRAM5_TAB_HPP_INCLUDED
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
#line 31 "program5.ypp" /* yacc.c:355  */

    BaseNode *ttype;

#line 173 "program5.tab.cpp" /* yacc.c:355  */
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

#endif /* !YY_YY_PROGRAM5_TAB_HPP_INCLUDED  */

/* Copy the second part of user declarations.  */

#line 204 "program5.tab.cpp" /* yacc.c:358  */

#ifdef short
# undef short
#endif

#ifdef YYTYPE_UINT8
typedef YYTYPE_UINT8 yytype_uint8;
#else
typedef unsigned char yytype_uint8;
#endif

#ifdef YYTYPE_INT8
typedef YYTYPE_INT8 yytype_int8;
#else
typedef signed char yytype_int8;
#endif

#ifdef YYTYPE_UINT16
typedef YYTYPE_UINT16 yytype_uint16;
#else
typedef unsigned short int yytype_uint16;
#endif

#ifdef YYTYPE_INT16
typedef YYTYPE_INT16 yytype_int16;
#else
typedef short int yytype_int16;
#endif

#ifndef YYSIZE_T
# ifdef __SIZE_TYPE__
#  define YYSIZE_T __SIZE_TYPE__
# elif defined size_t
#  define YYSIZE_T size_t
# elif ! defined YYSIZE_T
#  include <stddef.h> /* INFRINGES ON USER NAME SPACE */
#  define YYSIZE_T size_t
# else
#  define YYSIZE_T unsigned int
# endif
#endif

#define YYSIZE_MAXIMUM ((YYSIZE_T) -1)

#ifndef YY_
# if defined YYENABLE_NLS && YYENABLE_NLS
#  if ENABLE_NLS
#   include <libintl.h> /* INFRINGES ON USER NAME SPACE */
#   define YY_(Msgid) dgettext ("bison-runtime", Msgid)
#  endif
# endif
# ifndef YY_
#  define YY_(Msgid) Msgid
# endif
#endif

#ifndef YY_ATTRIBUTE
# if (defined __GNUC__                                               \
      && (2 < __GNUC__ || (__GNUC__ == 2 && 96 <= __GNUC_MINOR__)))  \
     || defined __SUNPRO_C && 0x5110 <= __SUNPRO_C
#  define YY_ATTRIBUTE(Spec) __attribute__(Spec)
# else
#  define YY_ATTRIBUTE(Spec) /* empty */
# endif
#endif

#ifndef YY_ATTRIBUTE_PURE
# define YY_ATTRIBUTE_PURE   YY_ATTRIBUTE ((__pure__))
#endif

#ifndef YY_ATTRIBUTE_UNUSED
# define YY_ATTRIBUTE_UNUSED YY_ATTRIBUTE ((__unused__))
#endif

#if !defined _Noreturn \
     && (!defined __STDC_VERSION__ || __STDC_VERSION__ < 201112)
# if defined _MSC_VER && 1200 <= _MSC_VER
#  define _Noreturn __declspec (noreturn)
# else
#  define _Noreturn YY_ATTRIBUTE ((__noreturn__))
# endif
#endif

/* Suppress unused-variable warnings by "using" E.  */
#if ! defined lint || defined __GNUC__
# define YYUSE(E) ((void) (E))
#else
# define YYUSE(E) /* empty */
#endif

#if defined __GNUC__ && 407 <= __GNUC__ * 100 + __GNUC_MINOR__
/* Suppress an incorrect diagnostic about yylval being uninitialized.  */
# define YY_IGNORE_MAYBE_UNINITIALIZED_BEGIN \
    _Pragma ("GCC diagnostic push") \
    _Pragma ("GCC diagnostic ignored \"-Wuninitialized\"")\
    _Pragma ("GCC diagnostic ignored \"-Wmaybe-uninitialized\"")
# define YY_IGNORE_MAYBE_UNINITIALIZED_END \
    _Pragma ("GCC diagnostic pop")
#else
# define YY_INITIAL_VALUE(Value) Value
#endif
#ifndef YY_IGNORE_MAYBE_UNINITIALIZED_BEGIN
# define YY_IGNORE_MAYBE_UNINITIALIZED_BEGIN
# define YY_IGNORE_MAYBE_UNINITIALIZED_END
#endif
#ifndef YY_INITIAL_VALUE
# define YY_INITIAL_VALUE(Value) /* Nothing. */
#endif


#if ! defined yyoverflow || YYERROR_VERBOSE

/* The parser invokes alloca or malloc; define the necessary symbols.  */

# ifdef YYSTACK_USE_ALLOCA
#  if YYSTACK_USE_ALLOCA
#   ifdef __GNUC__
#    define YYSTACK_ALLOC __builtin_alloca
#   elif defined __BUILTIN_VA_ARG_INCR
#    include <alloca.h> /* INFRINGES ON USER NAME SPACE */
#   elif defined _AIX
#    define YYSTACK_ALLOC __alloca
#   elif defined _MSC_VER
#    include <malloc.h> /* INFRINGES ON USER NAME SPACE */
#    define alloca _alloca
#   else
#    define YYSTACK_ALLOC alloca
#    if ! defined _ALLOCA_H && ! defined EXIT_SUCCESS
#     include <stdlib.h> /* INFRINGES ON USER NAME SPACE */
      /* Use EXIT_SUCCESS as a witness for stdlib.h.  */
#     ifndef EXIT_SUCCESS
#      define EXIT_SUCCESS 0
#     endif
#    endif
#   endif
#  endif
# endif

# ifdef YYSTACK_ALLOC
   /* Pacify GCC's 'empty if-body' warning.  */
#  define YYSTACK_FREE(Ptr) do { /* empty */; } while (0)
#  ifndef YYSTACK_ALLOC_MAXIMUM
    /* The OS might guarantee only one guard page at the bottom of the stack,
       and a page size can be as small as 4096 bytes.  So we cannot safely
       invoke alloca (N) if N exceeds 4096.  Use a slightly smaller number
       to allow for a few compiler-allocated temporary stack slots.  */
#   define YYSTACK_ALLOC_MAXIMUM 4032 /* reasonable circa 2006 */
#  endif
# else
#  define YYSTACK_ALLOC YYMALLOC
#  define YYSTACK_FREE YYFREE
#  ifndef YYSTACK_ALLOC_MAXIMUM
#   define YYSTACK_ALLOC_MAXIMUM YYSIZE_MAXIMUM
#  endif
#  if (defined __cplusplus && ! defined EXIT_SUCCESS \
       && ! ((defined YYMALLOC || defined malloc) \
             && (defined YYFREE || defined free)))
#   include <stdlib.h> /* INFRINGES ON USER NAME SPACE */
#   ifndef EXIT_SUCCESS
#    define EXIT_SUCCESS 0
#   endif
#  endif
#  ifndef YYMALLOC
#   define YYMALLOC malloc
#   if ! defined malloc && ! defined EXIT_SUCCESS
void *malloc (YYSIZE_T); /* INFRINGES ON USER NAME SPACE */
#   endif
#  endif
#  ifndef YYFREE
#   define YYFREE free
#   if ! defined free && ! defined EXIT_SUCCESS
void free (void *); /* INFRINGES ON USER NAME SPACE */
#   endif
#  endif
# endif
#endif /* ! defined yyoverflow || YYERROR_VERBOSE */


#if (! defined yyoverflow \
     && (! defined __cplusplus \
         || (defined YYLTYPE_IS_TRIVIAL && YYLTYPE_IS_TRIVIAL \
             && defined YYSTYPE_IS_TRIVIAL && YYSTYPE_IS_TRIVIAL)))

/* A type that is properly aligned for any stack member.  */
union yyalloc
{
  yytype_int16 yyss_alloc;
  YYSTYPE yyvs_alloc;
  YYLTYPE yyls_alloc;
};

/* The size of the maximum gap between one aligned stack and the next.  */
# define YYSTACK_GAP_MAXIMUM (sizeof (union yyalloc) - 1)

/* The size of an array large to enough to hold all stacks, each with
   N elements.  */
# define YYSTACK_BYTES(N) \
     ((N) * (sizeof (yytype_int16) + sizeof (YYSTYPE) + sizeof (YYLTYPE)) \
      + 2 * YYSTACK_GAP_MAXIMUM)

# define YYCOPY_NEEDED 1

/* Relocate STACK from its old location to the new one.  The
   local variables YYSIZE and YYSTACKSIZE give the old and new number of
   elements in the stack, and YYPTR gives the new location of the
   stack.  Advance YYPTR to a properly aligned location for the next
   stack.  */
# define YYSTACK_RELOCATE(Stack_alloc, Stack)                           \
    do                                                                  \
      {                                                                 \
        YYSIZE_T yynewbytes;                                            \
        YYCOPY (&yyptr->Stack_alloc, Stack, yysize);                    \
        Stack = &yyptr->Stack_alloc;                                    \
        yynewbytes = yystacksize * sizeof (*Stack) + YYSTACK_GAP_MAXIMUM; \
        yyptr += yynewbytes / sizeof (*yyptr);                          \
      }                                                                 \
    while (0)

#endif

#if defined YYCOPY_NEEDED && YYCOPY_NEEDED
/* Copy COUNT objects from SRC to DST.  The source and destination do
   not overlap.  */
# ifndef YYCOPY
#  if defined __GNUC__ && 1 < __GNUC__
#   define YYCOPY(Dst, Src, Count) \
      __builtin_memcpy (Dst, Src, (Count) * sizeof (*(Src)))
#  else
#   define YYCOPY(Dst, Src, Count)              \
      do                                        \
        {                                       \
          YYSIZE_T yyi;                         \
          for (yyi = 0; yyi < (Count); yyi++)   \
            (Dst)[yyi] = (Src)[yyi];            \
        }                                       \
      while (0)
#  endif
# endif
#endif /* !YYCOPY_NEEDED */

/* YYFINAL -- State number of the termination state.  */
#define YYFINAL  9
/* YYLAST -- Last index in YYTABLE.  */
#define YYLAST   308

/* YYNTOKENS -- Number of terminals.  */
#define YYNTOKENS  45
/* YYNNTS -- Number of nonterminals.  */
#define YYNNTS  28
/* YYNRULES -- Number of rules.  */
#define YYNRULES  96
/* YYNSTATES -- Number of states.  */
#define YYNSTATES  217

/* YYTRANSLATE[YYX] -- Symbol number corresponding to YYX as returned
   by yylex, with out-of-bounds checking.  */
#define YYUNDEFTOK  2
#define YYMAXUTOK   299

#define YYTRANSLATE(YYX)                                                \
  ((unsigned int) (YYX) <= YYMAXUTOK ? yytranslate[YYX] : YYUNDEFTOK)

/* YYTRANSLATE[TOKEN-NUM] -- Symbol number corresponding to TOKEN-NUM
   as returned by yylex, without out-of-bounds checking.  */
static const yytype_uint8 yytranslate[] =
{
       0,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     1,     2,     3,     4,
       5,     6,     7,     8,     9,    10,    11,    12,    13,    14,
      15,    16,    17,    18,    19,    20,    21,    22,    23,    24,
      25,    26,    27,    28,    29,    30,    31,    32,    33,    34,
      35,    36,    37,    38,    39,    40,    41,    42,    43,    44
};

#if YYDEBUG
  /* YYRLINE[YYN] -- Source line where rule number YYN was defined.  */
static const yytype_uint16 yyrline[] =
{
       0,    59,    59,    63,    64,    65,    69,    75,    79,    83,
     101,   105,   115,   125,   134,   144,   148,   164,   168,   178,
     190,   202,   212,   222,   228,   236,   247,   254,   260,   268,
     273,   278,   286,   297,   315,   319,   323,   327,   331,   337,
     342,   350,   361,   364,   367,   370,   375,   378,   381,   385,
     396,   400,   404,   408,   411,   416,   423,   430,   436,   443,
     448,   451,   457,   461,   465,   469,   473,   477,   481,   485,
     489,   493,   497,   501,   505,   509,   516,   517,   522,   526,
     529,   532,   536,   539,   542,   545,   551,   555,   558,   563,
     566,   574,   578,   585,   590,   596,   599
};
#endif

#if YYDEBUG || YYERROR_VERBOSE || 0
/* YYTNAME[SYMBOL-NUM] -- String name of the symbol SYMBOL-NUM.
   First, the terminals, then, starting at YYNTOKENS, nonterminals.  */
static const char *const yytname[] =
{
  "$end", "error", "$undefined", "\"shift\"", "\"reduce\"", "PLUS",
  "MINUS", "NOT", "OR", "SEMI", "DOT", "COMMA", "ID", "LPAREN", "RPAREN",
  "LBRACKET", "RBRACKET", "RBRACE", "LBRACE", "NUMBER", "NULLT", "READ",
  "NEW", "THIS", "IF", "ELSE", "WHILE", "RETURN", "CLASS", "PRINT", "VOID",
  "TIMES", "DIV", "MOD", "AND", "EQ", "NE", "GE", "LE", "GT", "LT",
  "ASSIGN", "INT", "ER_WD", "ER_CH", "$accept", "program",
  "classDeclarations", "classBody", "varDeclHeaderChoice",
  "constDeclHeaderChoice", "methDeclHeaderChoice", "type", "parameterList",
  "parameterListStar", "parameter", "block", "blockHeadChoice",
  "blockStatementChoice", "localVarDeclaration", "statement", "name",
  "argList", "argListStar", "conditionalStatement", "expression", "rterm",
  "term", "factor", "newExpression", "newExpTypes", "brackExp", "bracks", YY_NULLPTR
};
#endif

# ifdef YYPRINT
/* YYTOKNUM[NUM] -- (External) token number corresponding to the
   (internal) symbol number NUM (which must be that of a token).  */
static const yytype_uint16 yytoknum[] =
{
       0,   256,   257,   258,   259,   260,   261,   262,   263,   264,
     265,   266,   267,   268,   269,   270,   271,   272,   273,   274,
     275,   276,   277,   278,   279,   280,   281,   282,   283,   284,
     285,   286,   287,   288,   289,   290,   291,   292,   293,   294,
     295,   296,   297,   298,   299
};
# endif

#define YYPACT_NINF -172

#define yypact_value_is_default(Yystate) \
  (!!((Yystate) == (-172)))

#define YYTABLE_NINF -77

#define yytable_value_is_error(Yytable_value) \
  0

  /* YYPACT[STATE-NUM] -- Index in YYTABLE of the portion describing
     STATE-NUM.  */
static const yytype_int16 yypact[] =
{
      98,    -5,     3,   111,  -172,  -172,   100,   109,    17,  -172,
     119,   125,  -172,    10,    89,  -172,  -172,    56,  -172,   107,
      -3,  -172,  -172,  -172,  -172,  -172,    45,    22,    41,   134,
     105,    91,   138,    10,    22,   132,   201,   157,   145,   171,
     168,   103,    22,    10,    22,   122,  -172,   170,  -172,  -172,
    -172,  -172,  -172,    48,    22,  -172,  -172,    10,    22,   180,
    -172,   198,    10,    22,    48,  -172,   194,    44,   171,  -172,
     212,    48,    48,  -172,   216,    44,  -172,   117,  -172,    93,
     195,   220,   243,   224,   207,   217,  -172,  -172,   194,   215,
      46,  -172,   192,   213,  -172,  -172,    48,    44,    44,    48,
    -172,    -2,   226,   260,  -172,    -2,   277,  -172,   277,   277,
     277,  -172,   110,   277,  -172,  -172,   227,    43,   230,     8,
    -172,   130,  -172,  -172,   277,   238,   244,  -172,  -172,   277,
     277,   241,   245,   248,   262,    44,  -172,  -172,    44,  -172,
    -172,    57,  -172,   101,   116,  -172,   152,   261,   264,  -172,
     263,   277,   277,   277,   277,  -172,   277,   277,   277,   277,
     277,   277,   277,   277,   277,   277,   271,   137,  -172,  -172,
     272,   162,   274,   275,  -172,  -172,  -172,   222,   222,  -172,
    -172,   277,   168,  -172,   278,   130,   130,   147,   130,  -172,
    -172,  -172,  -172,  -172,  -172,  -172,  -172,  -172,  -172,   282,
     277,  -172,   284,  -172,  -172,   269,  -172,   281,  -172,  -172,
    -172,   137,  -172,   222,  -172,  -172,  -172
};

  /* YYDEFACT[STATE-NUM] -- Default reduction number in state STATE-NUM.
     Performed when YYTABLE does not specify something else to do.  Zero
     means the default is an error.  */
static const yytype_uint8 yydefact[] =
{
       0,     8,     0,     0,     2,     5,     0,     0,     0,     1,
       0,     0,    10,     0,     0,     4,     3,     0,    23,     0,
       0,     9,    15,    17,     8,     6,     0,    27,     0,     0,
       0,     0,     0,     0,    27,     0,     0,     0,     0,    29,
      96,     0,    27,     0,    27,     0,    14,     0,    32,    25,
      31,    24,    30,     0,     0,    26,    95,     0,    27,     0,
      13,     0,     0,    27,     0,    34,     0,     0,    29,    12,
       0,     0,     0,    11,     0,     0,    42,    50,    38,    55,
       0,     0,     0,     0,     0,     0,    33,    36,     0,     0,
       0,    46,     0,     0,    16,    28,     0,     0,     0,     0,
      22,     0,     0,     0,    52,     0,     0,    54,     0,     0,
       0,    49,    50,     0,    81,    82,     0,     0,    79,     0,
      76,    71,    77,    85,    57,     0,     0,    35,    37,    57,
       0,     0,     0,     0,     0,     0,    18,    21,     0,    51,
      41,     0,    53,     0,     0,    78,     0,     0,    91,    92,
      87,    57,     0,     0,     0,    48,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,    59,    40,    39,
       0,     0,     0,     0,    20,    19,    94,     0,     0,    80,
      84,    57,    89,    88,     0,    68,    69,    70,     0,    62,
      63,    67,    66,    65,    64,    72,    73,    74,    75,     0,
       0,    56,     0,    43,    93,    60,    47,     0,    90,    83,
      45,    59,    44,     0,    86,    58,    61
};

  /* YYPGOTO[NTERM-NUM].  */
static const yytype_int16 yypgoto[] =
{
    -172,  -172,   287,  -172,   153,   -47,  -172,   -55,   151,   234,
     249,     6,   218,   219,  -172,  -171,   -64,  -121,    94,  -172,
     -77,   150,   106,   197,  -172,  -172,   -78,   -17
};

  /* YYDEFGOTO[NTERM-NUM].  */
static const yytype_int16 yydefgoto[] =
{
      -1,     3,     4,    14,    21,    22,    23,    37,    38,    55,
      39,    67,    86,    87,    88,    89,   118,   166,   201,    91,
     167,   120,   121,   122,   123,   150,   104,    49
};

  /* YYTABLE[YYPACT[STATE-NUM]] -- What to do in state STATE-NUM.  If
     positive, shift that token.  If negative, reduce the rule whose
     number is the opposite.  If YYTABLE_NINF, syntax error.  */
static const yytype_int16 yytable[] =
{
      29,   107,    90,    32,     5,   119,   205,   206,   170,    31,
     112,    85,    28,   152,   153,     8,   154,   155,    12,    51,
      94,    79,    17,    56,    90,    90,   141,    18,   100,   141,
     184,   143,   144,    85,    35,    13,   146,   139,     6,     7,
      19,   142,   216,   156,   157,   158,   159,   160,   161,    65,
     136,   137,    20,   171,    33,   148,    92,    40,    34,   129,
     207,    18,   152,   153,    36,   154,    66,    51,    26,    27,
      75,    28,   182,   176,    19,   132,   134,    97,    98,   189,
     190,   191,   192,   193,   194,   149,    93,   130,   174,    -7,
      24,   175,   156,   157,   158,   159,   160,   161,   204,     1,
      43,    10,   135,   105,    44,   138,   152,   153,   106,   154,
      11,     9,    57,    90,    90,   177,    58,     2,    42,    30,
     101,   152,   153,   211,   154,   106,     2,   101,    15,   102,
     178,    62,   103,   183,    16,    63,   156,   157,   158,   159,
     160,   161,   152,   153,    48,   154,    41,    28,   200,    90,
      45,   156,   157,   158,   159,   160,   161,   152,   153,    53,
     154,   162,   163,   164,   165,   208,   179,   152,   153,    52,
     154,   203,   156,   157,   158,   159,   160,   161,   -76,   -76,
     -76,   -76,    54,    28,    64,    47,    46,   156,   157,   158,
     159,   160,   161,    59,    71,    61,    60,   156,   157,   158,
     159,   160,   161,    76,   131,    27,    77,    28,   108,    70,
      69,    78,    72,    50,    74,    73,    28,    79,    80,   125,
      81,    82,    28,    83,    76,   133,    96,   112,    28,   126,
      99,    76,    78,   109,   112,   140,    84,   124,    79,    80,
     147,    81,    82,   151,    83,    79,    80,   168,    81,    82,
     110,    83,   111,   169,    34,   112,   113,   172,   185,   186,
     188,    44,   114,   115,   116,   117,    79,   110,   195,   196,
     197,   198,   112,   113,   173,   180,    40,   181,   103,   114,
     115,   116,   117,    79,   110,   199,   202,    58,    63,   112,
     113,   210,   209,   212,   213,   214,   114,   115,   116,   117,
      79,    25,    95,    68,   187,   215,   127,   145,   128
};

static const yytype_uint8 yycheck[] =
{
      17,    79,    66,    20,     9,    82,   177,   178,   129,    12,
      12,    66,    15,     5,     6,    12,     8,     9,     1,    36,
      67,    23,    12,    40,    88,    89,   103,    17,    75,   106,
     151,   108,   109,    88,    12,    18,   113,   101,    43,    44,
      30,   105,   213,    35,    36,    37,    38,    39,    40,     1,
      97,    98,    42,   130,     9,    12,    12,    16,    13,    13,
     181,    17,     5,     6,    42,     8,    18,    84,    12,    13,
      64,    15,   150,    16,    30,    92,    93,    71,    72,   156,
     157,   158,   159,   160,   161,    42,    42,    41,   135,     0,
       1,   138,    35,    36,    37,    38,    39,    40,   176,     1,
       9,     1,    96,    10,    13,    99,     5,     6,    15,     8,
       1,     0,     9,   177,   178,    14,    13,    28,    13,    12,
      10,     5,     6,   200,     8,    15,    28,    10,     9,    12,
      14,     9,    15,   150,     9,    13,    35,    36,    37,    38,
      39,    40,     5,     6,    12,     8,    12,    15,    11,   213,
      12,    35,    36,    37,    38,    39,    40,     5,     6,    14,
       8,    31,    32,    33,    34,   182,    14,     5,     6,    12,
       8,     9,    35,    36,    37,    38,    39,    40,    31,    32,
      33,    34,    11,    15,    14,    34,    33,    35,    36,    37,
      38,    39,    40,    42,    14,    44,    43,    35,    36,    37,
      38,    39,    40,     9,    12,    13,    12,    15,    13,    58,
      57,    17,    14,    12,    63,    62,    15,    23,    24,    12,
      26,    27,    15,    29,     9,    12,    14,    12,    15,    12,
      14,     9,    17,    13,    12,     9,    42,    13,    23,    24,
      13,    26,    27,    13,    29,    23,    24,     9,    26,    27,
       7,    29,     9,     9,    13,    12,    13,    12,   152,   153,
     154,    13,    19,    20,    21,    22,    23,     7,   162,   163,
     164,   165,    12,    13,    12,    14,    16,    13,    15,    19,
      20,    21,    22,    23,     7,    14,    14,    13,    13,    12,
      13,     9,    14,     9,    25,    14,    19,    20,    21,    22,
      23,    14,    68,    54,   154,   211,    88,   110,    89
};

  /* YYSTOS[STATE-NUM] -- The (internal number of the) accessing
     symbol of state STATE-NUM.  */
static const yytype_uint8 yystos[] =
{
       0,     1,    28,    46,    47,     9,    43,    44,    12,     0,
       1,     1,     1,    18,    48,     9,     9,    12,    17,    30,
      42,    49,    50,    51,     1,    47,    12,    13,    15,    72,
      12,    12,    72,     9,    13,    12,    42,    52,    53,    55,
      16,    12,    13,     9,    13,    12,    49,    53,    12,    72,
      12,    72,    12,    14,    11,    54,    72,     9,    13,    53,
      49,    53,     9,    13,    14,     1,    18,    56,    55,    49,
      53,    14,    14,    49,    53,    56,     9,    12,    17,    23,
      24,    26,    27,    29,    42,    52,    57,    58,    59,    60,
      61,    64,    12,    42,    50,    54,    14,    56,    56,    14,
      50,    10,    12,    15,    71,    10,    15,    71,    13,    13,
       7,     9,    12,    13,    19,    20,    21,    22,    61,    65,
      66,    67,    68,    69,    13,    12,    12,    57,    58,    13,
      41,    12,    72,    12,    72,    56,    50,    50,    56,    61,
       9,    65,    61,    65,    65,    68,    65,    13,    12,    42,
      70,    13,     5,     6,     8,     9,    35,    36,    37,    38,
      39,    40,    31,    32,    33,    34,    62,    65,     9,     9,
      62,    65,    12,    12,    50,    50,    16,    14,    14,    14,
      14,    13,    71,    72,    62,    67,    67,    66,    67,    65,
      65,    65,    65,    65,    65,    67,    67,    67,    67,    14,
      11,    63,    14,     9,    71,    60,    60,    62,    72,    14,
       9,    65,     9,    25,    14,    63,    60
};

  /* YYR1[YYN] -- Symbol number of symbol that rule YYN derives.  */
static const yytype_uint8 yyr1[] =
{
       0,    45,    46,    46,    46,    46,    47,    47,    47,    48,
      48,    49,    49,    49,    49,    49,    50,    50,    51,    51,
      51,    51,    51,    51,    52,    52,    53,    53,    54,    54,
      55,    55,    55,    56,    56,    57,    57,    58,    58,    59,
      59,    59,    60,    60,    60,    60,    60,    60,    60,    60,
      61,    61,    61,    61,    61,    61,    62,    62,    63,    63,
      64,    64,    65,    65,    65,    65,    65,    65,    65,    65,
      65,    65,    66,    66,    66,    66,    67,    67,    68,    68,
      68,    68,    68,    68,    68,    68,    69,    69,    69,    69,
      69,    70,    70,    71,    71,    72,    72
};

  /* YYR2[YYN] -- Number of symbols on the right hand side of rule YYN.  */
static const yytype_uint8 yyr2[] =
{
       0,     2,     1,     4,     4,     2,     4,     3,     1,     2,
       1,     5,     5,     4,     4,     1,     6,     1,     7,     8,
       8,     7,     7,     1,     2,     2,     2,     0,     3,     0,
       2,     2,     2,     2,     1,     2,     1,     2,     1,     3,
       3,     3,     1,     4,     5,     5,     1,     5,     3,     2,
       1,     3,     2,     3,     2,     1,     2,     0,     3,     0,
       5,     7,     3,     3,     3,     3,     3,     3,     3,     3,
       3,     1,     3,     3,     3,     3,     1,     1,     2,     1,
       3,     1,     1,     4,     3,     1,     5,     2,     3,     3,
       4,     1,     1,     4,     3,     3,     2
};


#define yyerrok         (yyerrstatus = 0)
#define yyclearin       (yychar = YYEMPTY)
#define YYEMPTY         (-2)
#define YYEOF           0

#define YYACCEPT        goto yyacceptlab
#define YYABORT         goto yyabortlab
#define YYERROR         goto yyerrorlab


#define YYRECOVERING()  (!!yyerrstatus)

#define YYBACKUP(Token, Value)                                  \
do                                                              \
  if (yychar == YYEMPTY)                                        \
    {                                                           \
      yychar = (Token);                                         \
      yylval = (Value);                                         \
      YYPOPSTACK (yylen);                                       \
      yystate = *yyssp;                                         \
      goto yybackup;                                            \
    }                                                           \
  else                                                          \
    {                                                           \
      yyerror (YY_("syntax error: cannot back up")); \
      YYERROR;                                                  \
    }                                                           \
while (0)

/* Error token number */
#define YYTERROR        1
#define YYERRCODE       256


/* YYLLOC_DEFAULT -- Set CURRENT to span from RHS[1] to RHS[N].
   If N is 0, then set CURRENT to the empty location which ends
   the previous symbol: RHS[0] (always defined).  */

#ifndef YYLLOC_DEFAULT
# define YYLLOC_DEFAULT(Current, Rhs, N)                                \
    do                                                                  \
      if (N)                                                            \
        {                                                               \
          (Current).first_line   = YYRHSLOC (Rhs, 1).first_line;        \
          (Current).first_column = YYRHSLOC (Rhs, 1).first_column;      \
          (Current).last_line    = YYRHSLOC (Rhs, N).last_line;         \
          (Current).last_column  = YYRHSLOC (Rhs, N).last_column;       \
        }                                                               \
      else                                                              \
        {                                                               \
          (Current).first_line   = (Current).last_line   =              \
            YYRHSLOC (Rhs, 0).last_line;                                \
          (Current).first_column = (Current).last_column =              \
            YYRHSLOC (Rhs, 0).last_column;                              \
        }                                                               \
    while (0)
#endif

#define YYRHSLOC(Rhs, K) ((Rhs)[K])


/* Enable debugging if requested.  */
#if YYDEBUG

# ifndef YYFPRINTF
#  include <stdio.h> /* INFRINGES ON USER NAME SPACE */
#  define YYFPRINTF fprintf
# endif

# define YYDPRINTF(Args)                        \
do {                                            \
  if (yydebug)                                  \
    YYFPRINTF Args;                             \
} while (0)


/* YY_LOCATION_PRINT -- Print the location on the stream.
   This macro was not mandated originally: define only if we know
   we won't break user code: when these are the locations we know.  */

#ifndef YY_LOCATION_PRINT
# if defined YYLTYPE_IS_TRIVIAL && YYLTYPE_IS_TRIVIAL

/* Print *YYLOCP on YYO.  Private, do not rely on its existence. */

YY_ATTRIBUTE_UNUSED
static unsigned
yy_location_print_ (FILE *yyo, YYLTYPE const * const yylocp)
{
  unsigned res = 0;
  int end_col = 0 != yylocp->last_column ? yylocp->last_column - 1 : 0;
  if (0 <= yylocp->first_line)
    {
      res += YYFPRINTF (yyo, "%d", yylocp->first_line);
      if (0 <= yylocp->first_column)
        res += YYFPRINTF (yyo, ".%d", yylocp->first_column);
    }
  if (0 <= yylocp->last_line)
    {
      if (yylocp->first_line < yylocp->last_line)
        {
          res += YYFPRINTF (yyo, "-%d", yylocp->last_line);
          if (0 <= end_col)
            res += YYFPRINTF (yyo, ".%d", end_col);
        }
      else if (0 <= end_col && yylocp->first_column < end_col)
        res += YYFPRINTF (yyo, "-%d", end_col);
    }
  return res;
 }

#  define YY_LOCATION_PRINT(File, Loc)          \
  yy_location_print_ (File, &(Loc))

# else
#  define YY_LOCATION_PRINT(File, Loc) ((void) 0)
# endif
#endif


# define YY_SYMBOL_PRINT(Title, Type, Value, Location)                    \
do {                                                                      \
  if (yydebug)                                                            \
    {                                                                     \
      YYFPRINTF (stderr, "%s ", Title);                                   \
      yy_symbol_print (stderr,                                            \
                  Type, Value, Location); \
      YYFPRINTF (stderr, "\n");                                           \
    }                                                                     \
} while (0)


/*----------------------------------------.
| Print this symbol's value on YYOUTPUT.  |
`----------------------------------------*/

static void
yy_symbol_value_print (FILE *yyoutput, int yytype, YYSTYPE const * const yyvaluep, YYLTYPE const * const yylocationp)
{
  FILE *yyo = yyoutput;
  YYUSE (yyo);
  YYUSE (yylocationp);
  if (!yyvaluep)
    return;
# ifdef YYPRINT
  if (yytype < YYNTOKENS)
    YYPRINT (yyoutput, yytoknum[yytype], *yyvaluep);
# endif
  YYUSE (yytype);
}


/*--------------------------------.
| Print this symbol on YYOUTPUT.  |
`--------------------------------*/

static void
yy_symbol_print (FILE *yyoutput, int yytype, YYSTYPE const * const yyvaluep, YYLTYPE const * const yylocationp)
{
  YYFPRINTF (yyoutput, "%s %s (",
             yytype < YYNTOKENS ? "token" : "nterm", yytname[yytype]);

  YY_LOCATION_PRINT (yyoutput, *yylocationp);
  YYFPRINTF (yyoutput, ": ");
  yy_symbol_value_print (yyoutput, yytype, yyvaluep, yylocationp);
  YYFPRINTF (yyoutput, ")");
}

/*------------------------------------------------------------------.
| yy_stack_print -- Print the state stack from its BOTTOM up to its |
| TOP (included).                                                   |
`------------------------------------------------------------------*/

static void
yy_stack_print (yytype_int16 *yybottom, yytype_int16 *yytop)
{
  YYFPRINTF (stderr, "Stack now");
  for (; yybottom <= yytop; yybottom++)
    {
      int yybot = *yybottom;
      YYFPRINTF (stderr, " %d", yybot);
    }
  YYFPRINTF (stderr, "\n");
}

# define YY_STACK_PRINT(Bottom, Top)                            \
do {                                                            \
  if (yydebug)                                                  \
    yy_stack_print ((Bottom), (Top));                           \
} while (0)


/*------------------------------------------------.
| Report that the YYRULE is going to be reduced.  |
`------------------------------------------------*/

static void
yy_reduce_print (yytype_int16 *yyssp, YYSTYPE *yyvsp, YYLTYPE *yylsp, int yyrule)
{
  unsigned long int yylno = yyrline[yyrule];
  int yynrhs = yyr2[yyrule];
  int yyi;
  YYFPRINTF (stderr, "Reducing stack by rule %d (line %lu):\n",
             yyrule - 1, yylno);
  /* The symbols being reduced.  */
  for (yyi = 0; yyi < yynrhs; yyi++)
    {
      YYFPRINTF (stderr, "   $%d = ", yyi + 1);
      yy_symbol_print (stderr,
                       yystos[yyssp[yyi + 1 - yynrhs]],
                       &(yyvsp[(yyi + 1) - (yynrhs)])
                       , &(yylsp[(yyi + 1) - (yynrhs)])                       );
      YYFPRINTF (stderr, "\n");
    }
}

# define YY_REDUCE_PRINT(Rule)          \
do {                                    \
  if (yydebug)                          \
    yy_reduce_print (yyssp, yyvsp, yylsp, Rule); \
} while (0)

/* Nonzero means print parse trace.  It is left uninitialized so that
   multiple parsers can coexist.  */
int yydebug;
#else /* !YYDEBUG */
# define YYDPRINTF(Args)
# define YY_SYMBOL_PRINT(Title, Type, Value, Location)
# define YY_STACK_PRINT(Bottom, Top)
# define YY_REDUCE_PRINT(Rule)
#endif /* !YYDEBUG */


/* YYINITDEPTH -- initial size of the parser's stacks.  */
#ifndef YYINITDEPTH
# define YYINITDEPTH 200
#endif

/* YYMAXDEPTH -- maximum size the stacks can grow to (effective only
   if the built-in stack extension method is used).

   Do not make this value too large; the results are undefined if
   YYSTACK_ALLOC_MAXIMUM < YYSTACK_BYTES (YYMAXDEPTH)
   evaluated with infinite-precision integer arithmetic.  */

#ifndef YYMAXDEPTH
# define YYMAXDEPTH 10000
#endif


#if YYERROR_VERBOSE

# ifndef yystrlen
#  if defined __GLIBC__ && defined _STRING_H
#   define yystrlen strlen
#  else
/* Return the length of YYSTR.  */
static YYSIZE_T
yystrlen (const char *yystr)
{
  YYSIZE_T yylen;
  for (yylen = 0; yystr[yylen]; yylen++)
    continue;
  return yylen;
}
#  endif
# endif

# ifndef yystpcpy
#  if defined __GLIBC__ && defined _STRING_H && defined _GNU_SOURCE
#   define yystpcpy stpcpy
#  else
/* Copy YYSRC to YYDEST, returning the address of the terminating '\0' in
   YYDEST.  */
static char *
yystpcpy (char *yydest, const char *yysrc)
{
  char *yyd = yydest;
  const char *yys = yysrc;

  while ((*yyd++ = *yys++) != '\0')
    continue;

  return yyd - 1;
}
#  endif
# endif

# ifndef yytnamerr
/* Copy to YYRES the contents of YYSTR after stripping away unnecessary
   quotes and backslashes, so that it's suitable for yyerror.  The
   heuristic is that double-quoting is unnecessary unless the string
   contains an apostrophe, a comma, or backslash (other than
   backslash-backslash).  YYSTR is taken from yytname.  If YYRES is
   null, do not copy; instead, return the length of what the result
   would have been.  */
static YYSIZE_T
yytnamerr (char *yyres, const char *yystr)
{
  if (*yystr == '"')
    {
      YYSIZE_T yyn = 0;
      char const *yyp = yystr;

      for (;;)
        switch (*++yyp)
          {
          case '\'':
          case ',':
            goto do_not_strip_quotes;

          case '\\':
            if (*++yyp != '\\')
              goto do_not_strip_quotes;
            /* Fall through.  */
          default:
            if (yyres)
              yyres[yyn] = *yyp;
            yyn++;
            break;

          case '"':
            if (yyres)
              yyres[yyn] = '\0';
            return yyn;
          }
    do_not_strip_quotes: ;
    }

  if (! yyres)
    return yystrlen (yystr);

  return yystpcpy (yyres, yystr) - yyres;
}
# endif

/* Copy into *YYMSG, which is of size *YYMSG_ALLOC, an error message
   about the unexpected token YYTOKEN for the state stack whose top is
   YYSSP.

   Return 0 if *YYMSG was successfully written.  Return 1 if *YYMSG is
   not large enough to hold the message.  In that case, also set
   *YYMSG_ALLOC to the required number of bytes.  Return 2 if the
   required number of bytes is too large to store.  */
static int
yysyntax_error (YYSIZE_T *yymsg_alloc, char **yymsg,
                yytype_int16 *yyssp, int yytoken)
{
  YYSIZE_T yysize0 = yytnamerr (YY_NULLPTR, yytname[yytoken]);
  YYSIZE_T yysize = yysize0;
  enum { YYERROR_VERBOSE_ARGS_MAXIMUM = 5 };
  /* Internationalized format string. */
  const char *yyformat = YY_NULLPTR;
  /* Arguments of yyformat. */
  char const *yyarg[YYERROR_VERBOSE_ARGS_MAXIMUM];
  /* Number of reported tokens (one for the "unexpected", one per
     "expected"). */
  int yycount = 0;

  /* There are many possibilities here to consider:
     - If this state is a consistent state with a default action, then
       the only way this function was invoked is if the default action
       is an error action.  In that case, don't check for expected
       tokens because there are none.
     - The only way there can be no lookahead present (in yychar) is if
       this state is a consistent state with a default action.  Thus,
       detecting the absence of a lookahead is sufficient to determine
       that there is no unexpected or expected token to report.  In that
       case, just report a simple "syntax error".
     - Don't assume there isn't a lookahead just because this state is a
       consistent state with a default action.  There might have been a
       previous inconsistent state, consistent state with a non-default
       action, or user semantic action that manipulated yychar.
     - Of course, the expected token list depends on states to have
       correct lookahead information, and it depends on the parser not
       to perform extra reductions after fetching a lookahead from the
       scanner and before detecting a syntax error.  Thus, state merging
       (from LALR or IELR) and default reductions corrupt the expected
       token list.  However, the list is correct for canonical LR with
       one exception: it will still contain any token that will not be
       accepted due to an error action in a later state.
  */
  if (yytoken != YYEMPTY)
    {
      int yyn = yypact[*yyssp];
      yyarg[yycount++] = yytname[yytoken];
      if (!yypact_value_is_default (yyn))
        {
          /* Start YYX at -YYN if negative to avoid negative indexes in
             YYCHECK.  In other words, skip the first -YYN actions for
             this state because they are default actions.  */
          int yyxbegin = yyn < 0 ? -yyn : 0;
          /* Stay within bounds of both yycheck and yytname.  */
          int yychecklim = YYLAST - yyn + 1;
          int yyxend = yychecklim < YYNTOKENS ? yychecklim : YYNTOKENS;
          int yyx;

          for (yyx = yyxbegin; yyx < yyxend; ++yyx)
            if (yycheck[yyx + yyn] == yyx && yyx != YYTERROR
                && !yytable_value_is_error (yytable[yyx + yyn]))
              {
                if (yycount == YYERROR_VERBOSE_ARGS_MAXIMUM)
                  {
                    yycount = 1;
                    yysize = yysize0;
                    break;
                  }
                yyarg[yycount++] = yytname[yyx];
                {
                  YYSIZE_T yysize1 = yysize + yytnamerr (YY_NULLPTR, yytname[yyx]);
                  if (! (yysize <= yysize1
                         && yysize1 <= YYSTACK_ALLOC_MAXIMUM))
                    return 2;
                  yysize = yysize1;
                }
              }
        }
    }

  switch (yycount)
    {
# define YYCASE_(N, S)                      \
      case N:                               \
        yyformat = S;                       \
      break
      YYCASE_(0, YY_("syntax error"));
      YYCASE_(1, YY_("syntax error, unexpected %s"));
      YYCASE_(2, YY_("syntax error, unexpected %s, expecting %s"));
      YYCASE_(3, YY_("syntax error, unexpected %s, expecting %s or %s"));
      YYCASE_(4, YY_("syntax error, unexpected %s, expecting %s or %s or %s"));
      YYCASE_(5, YY_("syntax error, unexpected %s, expecting %s or %s or %s or %s"));
# undef YYCASE_
    }

  {
    YYSIZE_T yysize1 = yysize + yystrlen (yyformat);
    if (! (yysize <= yysize1 && yysize1 <= YYSTACK_ALLOC_MAXIMUM))
      return 2;
    yysize = yysize1;
  }

  if (*yymsg_alloc < yysize)
    {
      *yymsg_alloc = 2 * yysize;
      if (! (yysize <= *yymsg_alloc
             && *yymsg_alloc <= YYSTACK_ALLOC_MAXIMUM))
        *yymsg_alloc = YYSTACK_ALLOC_MAXIMUM;
      return 1;
    }

  /* Avoid sprintf, as that infringes on the user's name space.
     Don't have undefined behavior even if the translation
     produced a string with the wrong number of "%s"s.  */
  {
    char *yyp = *yymsg;
    int yyi = 0;
    while ((*yyp = *yyformat) != '\0')
      if (*yyp == '%' && yyformat[1] == 's' && yyi < yycount)
        {
          yyp += yytnamerr (yyp, yyarg[yyi++]);
          yyformat += 2;
        }
      else
        {
          yyp++;
          yyformat++;
        }
  }
  return 0;
}
#endif /* YYERROR_VERBOSE */

/*-----------------------------------------------.
| Release the memory associated to this symbol.  |
`-----------------------------------------------*/

static void
yydestruct (const char *yymsg, int yytype, YYSTYPE *yyvaluep, YYLTYPE *yylocationp)
{
  YYUSE (yyvaluep);
  YYUSE (yylocationp);
  if (!yymsg)
    yymsg = "Deleting";
  YY_SYMBOL_PRINT (yymsg, yytype, yyvaluep, yylocationp);

  YY_IGNORE_MAYBE_UNINITIALIZED_BEGIN
  YYUSE (yytype);
  YY_IGNORE_MAYBE_UNINITIALIZED_END
}




/* The lookahead symbol.  */
int yychar;

/* The semantic value of the lookahead symbol.  */
YYSTYPE yylval;
/* Location data for the lookahead symbol.  */
YYLTYPE yylloc
# if defined YYLTYPE_IS_TRIVIAL && YYLTYPE_IS_TRIVIAL
  = { 1, 1, 1, 1 }
# endif
;
/* Number of syntax errors so far.  */
int yynerrs;


/*----------.
| yyparse.  |
`----------*/

int
yyparse (void)
{
    int yystate;
    /* Number of tokens to shift before error messages enabled.  */
    int yyerrstatus;

    /* The stacks and their tools:
       'yyss': related to states.
       'yyvs': related to semantic values.
       'yyls': related to locations.

       Refer to the stacks through separate pointers, to allow yyoverflow
       to reallocate them elsewhere.  */

    /* The state stack.  */
    yytype_int16 yyssa[YYINITDEPTH];
    yytype_int16 *yyss;
    yytype_int16 *yyssp;

    /* The semantic value stack.  */
    YYSTYPE yyvsa[YYINITDEPTH];
    YYSTYPE *yyvs;
    YYSTYPE *yyvsp;

    /* The location stack.  */
    YYLTYPE yylsa[YYINITDEPTH];
    YYLTYPE *yyls;
    YYLTYPE *yylsp;

    /* The locations where the error started and ended.  */
    YYLTYPE yyerror_range[3];

    YYSIZE_T yystacksize;

  int yyn;
  int yyresult;
  /* Lookahead token as an internal (translated) token number.  */
  int yytoken = 0;
  /* The variables used to return semantic value and location from the
     action routines.  */
  YYSTYPE yyval;
  YYLTYPE yyloc;

#if YYERROR_VERBOSE
  /* Buffer for error messages, and its allocated size.  */
  char yymsgbuf[128];
  char *yymsg = yymsgbuf;
  YYSIZE_T yymsg_alloc = sizeof yymsgbuf;
#endif

#define YYPOPSTACK(N)   (yyvsp -= (N), yyssp -= (N), yylsp -= (N))

  /* The number of symbols on the RHS of the reduced rule.
     Keep to zero when no symbol should be popped.  */
  int yylen = 0;

  yyssp = yyss = yyssa;
  yyvsp = yyvs = yyvsa;
  yylsp = yyls = yylsa;
  yystacksize = YYINITDEPTH;

  YYDPRINTF ((stderr, "Starting parse\n"));

  yystate = 0;
  yyerrstatus = 0;
  yynerrs = 0;
  yychar = YYEMPTY; /* Cause a token to be read.  */
  yylsp[0] = yylloc;
  goto yysetstate;

/*------------------------------------------------------------.
| yynewstate -- Push a new state, which is found in yystate.  |
`------------------------------------------------------------*/
 yynewstate:
  /* In all cases, when you get here, the value and location stacks
     have just been pushed.  So pushing a state here evens the stacks.  */
  yyssp++;

 yysetstate:
  *yyssp = yystate;

  if (yyss + yystacksize - 1 <= yyssp)
    {
      /* Get the current used size of the three stacks, in elements.  */
      YYSIZE_T yysize = yyssp - yyss + 1;

#ifdef yyoverflow
      {
        /* Give user a chance to reallocate the stack.  Use copies of
           these so that the &'s don't force the real ones into
           memory.  */
        YYSTYPE *yyvs1 = yyvs;
        yytype_int16 *yyss1 = yyss;
        YYLTYPE *yyls1 = yyls;

        /* Each stack pointer address is followed by the size of the
           data in use in that stack, in bytes.  This used to be a
           conditional around just the two extra args, but that might
           be undefined if yyoverflow is a macro.  */
        yyoverflow (YY_("memory exhausted"),
                    &yyss1, yysize * sizeof (*yyssp),
                    &yyvs1, yysize * sizeof (*yyvsp),
                    &yyls1, yysize * sizeof (*yylsp),
                    &yystacksize);

        yyls = yyls1;
        yyss = yyss1;
        yyvs = yyvs1;
      }
#else /* no yyoverflow */
# ifndef YYSTACK_RELOCATE
      goto yyexhaustedlab;
# else
      /* Extend the stack our own way.  */
      if (YYMAXDEPTH <= yystacksize)
        goto yyexhaustedlab;
      yystacksize *= 2;
      if (YYMAXDEPTH < yystacksize)
        yystacksize = YYMAXDEPTH;

      {
        yytype_int16 *yyss1 = yyss;
        union yyalloc *yyptr =
          (union yyalloc *) YYSTACK_ALLOC (YYSTACK_BYTES (yystacksize));
        if (! yyptr)
          goto yyexhaustedlab;
        YYSTACK_RELOCATE (yyss_alloc, yyss);
        YYSTACK_RELOCATE (yyvs_alloc, yyvs);
        YYSTACK_RELOCATE (yyls_alloc, yyls);
#  undef YYSTACK_RELOCATE
        if (yyss1 != yyssa)
          YYSTACK_FREE (yyss1);
      }
# endif
#endif /* no yyoverflow */

      yyssp = yyss + yysize - 1;
      yyvsp = yyvs + yysize - 1;
      yylsp = yyls + yysize - 1;

      YYDPRINTF ((stderr, "Stack size increased to %lu\n",
                  (unsigned long int) yystacksize));

      if (yyss + yystacksize - 1 <= yyssp)
        YYABORT;
    }

  YYDPRINTF ((stderr, "Entering state %d\n", yystate));

  if (yystate == YYFINAL)
    YYACCEPT;

  goto yybackup;

/*-----------.
| yybackup.  |
`-----------*/
yybackup:

  /* Do appropriate processing given the current state.  Read a
     lookahead token if we need one and don't already have one.  */

  /* First try to decide what to do without reference to lookahead token.  */
  yyn = yypact[yystate];
  if (yypact_value_is_default (yyn))
    goto yydefault;

  /* Not known => get a lookahead token if don't already have one.  */

  /* YYCHAR is either YYEMPTY or YYEOF or a valid lookahead symbol.  */
  if (yychar == YYEMPTY)
    {
      YYDPRINTF ((stderr, "Reading a token: "));
      yychar = yylex ();
    }

  if (yychar <= YYEOF)
    {
      yychar = yytoken = YYEOF;
      YYDPRINTF ((stderr, "Now at end of input.\n"));
    }
  else
    {
      yytoken = YYTRANSLATE (yychar);
      YY_SYMBOL_PRINT ("Next token is", yytoken, &yylval, &yylloc);
    }

  /* If the proper action on seeing token YYTOKEN is to reduce or to
     detect an error, take that action.  */
  yyn += yytoken;
  if (yyn < 0 || YYLAST < yyn || yycheck[yyn] != yytoken)
    goto yydefault;
  yyn = yytable[yyn];
  if (yyn <= 0)
    {
      if (yytable_value_is_error (yyn))
        goto yyerrlab;
      yyn = -yyn;
      goto yyreduce;
    }

  /* Count tokens shifted since error; after three, turn off error
     status.  */
  if (yyerrstatus)
    yyerrstatus--;

  /* Shift the lookahead token.  */
  YY_SYMBOL_PRINT ("Shifting", yytoken, &yylval, &yylloc);

  /* Discard the shifted token.  */
  yychar = YYEMPTY;

  yystate = yyn;
  YY_IGNORE_MAYBE_UNINITIALIZED_BEGIN
  *++yyvsp = yylval;
  YY_IGNORE_MAYBE_UNINITIALIZED_END
  *++yylsp = yylloc;
  goto yynewstate;


/*-----------------------------------------------------------.
| yydefault -- do the default action for the current state.  |
`-----------------------------------------------------------*/
yydefault:
  yyn = yydefact[yystate];
  if (yyn == 0)
    goto yyerrlab;
  goto yyreduce;


/*-----------------------------.
| yyreduce -- Do a reduction.  |
`-----------------------------*/
yyreduce:
  /* yyn is the number of a rule to reduce with.  */
  yylen = yyr2[yyn];

  /* If YYLEN is nonzero, implement the default value of the action:
     '$$ = $1'.

     Otherwise, the following line sets YYVAL to garbage.
     This behavior is undocumented and Bison
     users should not rely upon it.  Assigning to YYVAL
     unconditionally makes the parser a bit smaller, and it avoids a
     GCC warning that YYVAL may be used uninitialized.  */
  yyval = yyvsp[1-yylen];

  /* Default location.  */
  YYLLOC_DEFAULT (yyloc, (yylsp - yylen), yylen);
  YY_REDUCE_PRINT (yyn);
  switch (yyn)
    {
        case 2:
#line 59 "program5.ypp" /* yacc.c:1646  */
    { 
        ast = new NProgram(static_cast<NClassDecl *>((yyvsp[0].ttype)));
        (yyval.ttype) = ast;
    }
#line 1539 "program5.tab.cpp" /* yacc.c:1646  */
    break;

  case 3:
#line 63 "program5.ypp" /* yacc.c:1646  */
    { yyerror("err: unsupported character in line"); }
#line 1545 "program5.tab.cpp" /* yacc.c:1646  */
    break;

  case 4:
#line 64 "program5.ypp" /* yacc.c:1646  */
    { yyerror("err: unsupported word in line"); }
#line 1551 "program5.tab.cpp" /* yacc.c:1646  */
    break;

  case 5:
#line 65 "program5.ypp" /* yacc.c:1646  */
    { yyerror("err: syntax error in line"); }
#line 1557 "program5.tab.cpp" /* yacc.c:1646  */
    break;

  case 6:
#line 69 "program5.ypp" /* yacc.c:1646  */
    {
        NId *id = new NId((yyvsp[-2].ttype)->getText());
        NClassDecl *cls = new NClassDecl(id, static_cast<NClassBody *>((yyvsp[-1].ttype)));
        cls->setNext(static_cast<NClassDecl *>((yyvsp[0].ttype)));
        (yyval.ttype) = cls;
    }
#line 1568 "program5.tab.cpp" /* yacc.c:1646  */
    break;

  case 7:
#line 75 "program5.ypp" /* yacc.c:1646  */
    {
        NId *id = new NId((yyvsp[-1].ttype)->getText());
        (yyval.ttype) = new NClassDecl(id, static_cast<NClassBody *>((yyvsp[0].ttype)));
    }
#line 1577 "program5.tab.cpp" /* yacc.c:1646  */
    break;

  case 8:
#line 79 "program5.ypp" /* yacc.c:1646  */
    { yyerror("err: bad class declaration"); }
#line 1583 "program5.tab.cpp" /* yacc.c:1646  */
    break;

  case 9:
#line 83 "program5.ypp" /* yacc.c:1646  */
    {
        auto *derivedVar = dynamic_cast<NVarDecl *>((yyvsp[0].ttype));
        auto *derivedConst = dynamic_cast<NConstDecl *>((yyvsp[0].ttype));
        auto *derivedMeth = dynamic_cast<NMethDecl *>((yyvsp[0].ttype));

        if (derivedVar) 
        {
            (yyval.ttype) = new NClassBody(derivedVar);
        }
        else if (derivedConst) 
        {
            (yyval.ttype) = new NClassBody(derivedConst);
        }
        else if (derivedMeth) 
        {
            (yyval.ttype) = new NClassBody(derivedMeth);
        }
    }
#line 1606 "program5.tab.cpp" /* yacc.c:1646  */
    break;

  case 10:
#line 101 "program5.ypp" /* yacc.c:1646  */
    { yyerror("err: bad class body. check declarations"); }
#line 1612 "program5.tab.cpp" /* yacc.c:1646  */
    break;

  case 11:
#line 105 "program5.ypp" /* yacc.c:1646  */
    {
        int bracks = static_cast<NType*>((yyvsp[-3].ttype))->getBracks();
        NKeyword *key = new NKeyword((yyvsp[-4].ttype)->getText());
        NSimpleType *st = new NSimpleType(key);
        NType *stWrapper = new NType(st);
        NType *type = new NType(stWrapper, bracks);
        NVarDecl *curr = new NVarDecl(type, static_cast<NId*>((yyvsp[-2].ttype)));
        curr->setNext((yyvsp[0].ttype));
        (yyval.ttype) = curr;
    }
#line 1627 "program5.tab.cpp" /* yacc.c:1646  */
    break;

  case 12:
#line 115 "program5.ypp" /* yacc.c:1646  */
    {
        int bracks = static_cast<NType*>((yyvsp[-3].ttype))->getBracks();
        NId *id = new NId((yyvsp[-4].ttype)->getText());
        NSimpleType *st = new NSimpleType(id);
        NType *stWrapper = new NType(st);
        NType *type = new NType(stWrapper, bracks);
        NVarDecl *curr = new NVarDecl(type, static_cast<NId*>((yyvsp[-2].ttype)));
        curr->setNext((yyvsp[0].ttype));
        (yyval.ttype) = curr;
    }
#line 1642 "program5.tab.cpp" /* yacc.c:1646  */
    break;

  case 13:
#line 125 "program5.ypp" /* yacc.c:1646  */
    {
        NKeyword *key = new NKeyword((yyvsp[-3].ttype)->getText());
        NId *id = new NId((yyvsp[-2].ttype)->getText());
        NSimpleType *st = new NSimpleType(key);
        NType *type = new NType(st);
        NVarDecl *curr = new NVarDecl(type, id);
        curr->setNext((yyvsp[0].ttype));
        (yyval.ttype) = curr;
    }
#line 1656 "program5.tab.cpp" /* yacc.c:1646  */
    break;

  case 14:
#line 134 "program5.ypp" /* yacc.c:1646  */
    {
        NId *idOne = new NId((yyvsp[-3].ttype)->getText());
        NId *idTwo = new NId((yyvsp[-2].ttype)->getText());
        NSimpleType *st = new NSimpleType(idOne);
        NType *type = new NType(st);
        NVarDecl *curr = new NVarDecl(type, idTwo);
        curr->setNext((yyvsp[0].ttype));
        (yyval.ttype) = curr;
    }
#line 1670 "program5.tab.cpp" /* yacc.c:1646  */
    break;

  case 16:
#line 148 "program5.ypp" /* yacc.c:1646  */
    {
        NId *id = new NId((yyvsp[-5].ttype)->getText());
        NConstDecl *curr;
        if ((yyvsp[-3].ttype)->getText() == "epsilon") 
        {
            NParam *epsilon = new NParam(0, 0);
            epsilon->setVal("epsilon");
            curr = new NConstDecl(id, epsilon, static_cast<NBlock *>((yyvsp[-1].ttype)));
        }
        else 
        {
            curr = new NConstDecl(id, static_cast<NParam *>((yyvsp[-3].ttype)), static_cast<NBlock *>((yyvsp[-1].ttype)));
        }
        curr->setNext((yyvsp[0].ttype));
        (yyval.ttype) = curr;
    }
#line 1691 "program5.tab.cpp" /* yacc.c:1646  */
    break;

  case 18:
#line 168 "program5.ypp" /* yacc.c:1646  */
    {
        NId *id = new NId((yyvsp[-5].ttype)->getText());
        NKeyword *key = new NKeyword("void");
        NSimpleType *st = new NSimpleType(key);
        NType *type = new NType(st);
        NResultType *resType = new NResultType(type);
        NMethDecl *method = new NMethDecl(resType, id, static_cast<NParam *>((yyvsp[-3].ttype)), static_cast<NBlock *>((yyvsp[-1].ttype)));
        method->setNext((yyvsp[0].ttype));
        (yyval.ttype) = method;
    }
#line 1706 "program5.tab.cpp" /* yacc.c:1646  */
    break;

  case 19:
#line 178 "program5.ypp" /* yacc.c:1646  */
    {
        int bracks = static_cast<NType*>((yyvsp[-6].ttype))->getBracks();
        NId *id = new NId((yyvsp[-5].ttype)->getText());
        NKeyword *intId = new NKeyword("int");
        NSimpleType *st = new NSimpleType(intId);
        NType *stWrapper = new NType(st);
        NType *type = new NType(stWrapper, bracks);
        NResultType *resType = new NResultType(type);
        NMethDecl *method = new NMethDecl(resType, id, static_cast<NParam *>((yyvsp[-3].ttype)), static_cast<NBlock *>((yyvsp[-1].ttype)));
        method->setNext((yyvsp[0].ttype));
        (yyval.ttype) = method;
    }
#line 1723 "program5.tab.cpp" /* yacc.c:1646  */
    break;

  case 20:
#line 190 "program5.ypp" /* yacc.c:1646  */
    {
        int bracks = static_cast<NType*>((yyvsp[-6].ttype))->getBracks();
        NId *id = new NId((yyvsp[-5].ttype)->getText());
        NId *intId = new NId((yyvsp[-7].ttype)->getText());
        NSimpleType *st = new NSimpleType(intId);
        NType *stWrapper = new NType(st);
        NType *type = new NType(stWrapper, bracks);
        NResultType *resType = new NResultType(type);
        NMethDecl *method = new NMethDecl(resType, id, static_cast<NParam *>((yyvsp[-3].ttype)), static_cast<NBlock *>((yyvsp[-1].ttype)));
        method->setNext((yyvsp[0].ttype));
        (yyval.ttype) = method;
    }
#line 1740 "program5.tab.cpp" /* yacc.c:1646  */
    break;

  case 21:
#line 202 "program5.ypp" /* yacc.c:1646  */
    {
        NId *id = new NId((yyvsp[-5].ttype)->getText());
        NKeyword *key = new NKeyword("int");
        NSimpleType *st = new NSimpleType(key);
        NType *type = new NType(st);
        NResultType *resType = new NResultType(type);
        NMethDecl *method = new NMethDecl(resType, id, static_cast<NParam *>((yyvsp[-3].ttype)), static_cast<NBlock *>((yyvsp[-1].ttype)));
        method->setNext((yyvsp[0].ttype));
        (yyval.ttype) = method;
    }
#line 1755 "program5.tab.cpp" /* yacc.c:1646  */
    break;

  case 22:
#line 212 "program5.ypp" /* yacc.c:1646  */
    {
        NId *id = new NId((yyvsp[-5].ttype)->getText());
        NKeyword *key = new NKeyword("int");
        NSimpleType *st = new NSimpleType(key);
        NType *type = new NType(st);
        NResultType *resType = new NResultType(type);
        NMethDecl *method = new NMethDecl(resType, id, static_cast<NParam *>((yyvsp[-3].ttype)), static_cast<NBlock *>((yyvsp[-1].ttype)));
        method->setNext((yyvsp[0].ttype));
        (yyval.ttype) = method;
    }
#line 1770 "program5.tab.cpp" /* yacc.c:1646  */
    break;

  case 23:
#line 222 "program5.ypp" /* yacc.c:1646  */
    {
        (yyval.ttype) = new NEpsilon();
    }
#line 1778 "program5.tab.cpp" /* yacc.c:1646  */
    break;

  case 24:
#line 228 "program5.ypp" /* yacc.c:1646  */
    {
        int bracks = static_cast<NType*>((yyvsp[0].ttype))->getBracks();
        NKeyword *key = new NKeyword("int");
        NSimpleType *st = new NSimpleType(key);
        NType *stWrapper = new NType(st);
        NType *type = new NType(stWrapper, bracks);
        (yyval.ttype) = type;
    }
#line 1791 "program5.tab.cpp" /* yacc.c:1646  */
    break;

  case 25:
#line 236 "program5.ypp" /* yacc.c:1646  */
    {
        int bracks = static_cast<NType*>((yyvsp[0].ttype))->getBracks();
        NId *id = new NId((yyvsp[-1].ttype)->getText());
        NSimpleType *st = new NSimpleType(id);
        NType *stWrapper = new NType(st);
        NType *type = new NType(stWrapper, bracks);
        (yyval.ttype) = type;
    }
#line 1804 "program5.tab.cpp" /* yacc.c:1646  */
    break;

  case 26:
#line 247 "program5.ypp" /* yacc.c:1646  */
    {
        if ((yyvsp[0].ttype)->getText() != "epsilon")
        {
            (yyvsp[-1].ttype)->setNext((yyvsp[0].ttype));
        }
        (yyval.ttype) = static_cast<NParam *>((yyvsp[-1].ttype));
    }
#line 1816 "program5.tab.cpp" /* yacc.c:1646  */
    break;

  case 27:
#line 254 "program5.ypp" /* yacc.c:1646  */
    {
        (yyval.ttype) = new NEpsilon();
    }
#line 1824 "program5.tab.cpp" /* yacc.c:1646  */
    break;

  case 28:
#line 260 "program5.ypp" /* yacc.c:1646  */
    {
        if ((yyvsp[0].ttype)->getText() != "epsilon")
        {
            (yyvsp[-1].ttype)->setNext((yyvsp[0].ttype));

        }
        (yyval.ttype) = static_cast<NParam *>((yyvsp[-1].ttype));
    }
#line 1837 "program5.tab.cpp" /* yacc.c:1646  */
    break;

  case 29:
#line 268 "program5.ypp" /* yacc.c:1646  */
    {
        (yyval.ttype) = new NEpsilon();
    }
#line 1845 "program5.tab.cpp" /* yacc.c:1646  */
    break;

  case 30:
#line 273 "program5.ypp" /* yacc.c:1646  */
    {
        NId *id = new NId((yyvsp[0].ttype)->getText());
        NParam *param = new NParam(static_cast<NType *>((yyvsp[-1].ttype)), id);
        (yyval.ttype) = param;
    }
#line 1855 "program5.tab.cpp" /* yacc.c:1646  */
    break;

  case 31:
#line 278 "program5.ypp" /* yacc.c:1646  */
    {
        NKeyword *key = new NKeyword("int");
        NSimpleType *st = new NSimpleType(key);
        NType *type = new NType(st);
        NId *id = new NId((yyvsp[0].ttype)->getText());
        NParam *param = new NParam(type, id);
        (yyval.ttype) = param;
    }
#line 1868 "program5.tab.cpp" /* yacc.c:1646  */
    break;

  case 32:
#line 286 "program5.ypp" /* yacc.c:1646  */
    {
        NId *idOne = new NId((yyvsp[-1].ttype)->getText());
        NId *idTwo = new NId((yyvsp[0].ttype)->getText());
        NSimpleType *st = new NSimpleType(idOne);
        NType *type = new NType(st);
        NParam *param = new NParam(type, idTwo);
        (yyval.ttype) = param;
    }
#line 1881 "program5.tab.cpp" /* yacc.c:1646  */
    break;

  case 33:
#line 297 "program5.ypp" /* yacc.c:1646  */
    {
        auto *derivedLocalVars = dynamic_cast<NLocalVarDecl *>((yyvsp[0].ttype));
        auto *derivedStatements = dynamic_cast<NStatement *>((yyvsp[0].ttype));
        auto *derivedEpsilon = dynamic_cast<NEpsilon *>((yyvsp[0].ttype));

        if (derivedLocalVars)
        {
            (yyval.ttype) = new NBlock(derivedLocalVars);
        }
        else if (derivedStatements)
        {
            (yyval.ttype) = new NBlock(derivedStatements);
        }
        else if (derivedEpsilon)
        {
            (yyval.ttype) = derivedEpsilon;
        }
    }
#line 1904 "program5.tab.cpp" /* yacc.c:1646  */
    break;

  case 34:
#line 315 "program5.ypp" /* yacc.c:1646  */
    { yyerror("err: error detected within block"); }
#line 1910 "program5.tab.cpp" /* yacc.c:1646  */
    break;

  case 35:
#line 319 "program5.ypp" /* yacc.c:1646  */
    {
        (yyvsp[-1].ttype)->setNext((yyvsp[0].ttype));
        (yyval.ttype) = (yyvsp[-1].ttype);
    }
#line 1919 "program5.tab.cpp" /* yacc.c:1646  */
    break;

  case 37:
#line 327 "program5.ypp" /* yacc.c:1646  */
    {
        (yyvsp[-1].ttype)->setNext((yyvsp[0].ttype));
        (yyval.ttype) = (yyvsp[-1].ttype);
    }
#line 1928 "program5.tab.cpp" /* yacc.c:1646  */
    break;

  case 38:
#line 331 "program5.ypp" /* yacc.c:1646  */
    {
        (yyval.ttype) = new NEpsilon();
    }
#line 1936 "program5.tab.cpp" /* yacc.c:1646  */
    break;

  case 39:
#line 337 "program5.ypp" /* yacc.c:1646  */
    {
        NId *id = new NId((yyvsp[-1].ttype)->getText());
        NVarDecl *var = new NVarDecl(static_cast<NType *>((yyvsp[-2].ttype)), id);
        (yyval.ttype) = new NLocalVarDecl(var);
    }
#line 1946 "program5.tab.cpp" /* yacc.c:1646  */
    break;

  case 40:
#line 342 "program5.ypp" /* yacc.c:1646  */
    {
        NId *id = new NId((yyvsp[-1].ttype)->getText());
        NKeyword *key = new NKeyword("int");
        NSimpleType *st = new NSimpleType(key);
        NType *type = new NType(st);
        NVarDecl *var = new NVarDecl(type, id);
        (yyval.ttype) = new NLocalVarDecl(var);
    }
#line 1959 "program5.tab.cpp" /* yacc.c:1646  */
    break;

  case 41:
#line 350 "program5.ypp" /* yacc.c:1646  */
    {
        NId *idOne = new NId((yyvsp[-2].ttype)->getText());
        NId *idTwo = new NId((yyvsp[-1].ttype)->getText());
        NSimpleType *st = new NSimpleType(idOne);
        NType *type = new NType(st);
        NVarDecl *var = new NVarDecl(type, idTwo);
        (yyval.ttype) = new NLocalVarDecl(var);
    }
#line 1972 "program5.tab.cpp" /* yacc.c:1646  */
    break;

  case 42:
#line 361 "program5.ypp" /* yacc.c:1646  */
    {
        (yyval.ttype) = new NEpsilon();
    }
#line 1980 "program5.tab.cpp" /* yacc.c:1646  */
    break;

  case 43:
#line 364 "program5.ypp" /* yacc.c:1646  */
    {
        (yyval.ttype) = new NStateAssign(static_cast<NName *>((yyvsp[-3].ttype)), static_cast<NExp *>((yyvsp[-1].ttype)));
    }
#line 1988 "program5.tab.cpp" /* yacc.c:1646  */
    break;

  case 44:
#line 367 "program5.ypp" /* yacc.c:1646  */
    {
        (yyval.ttype) = new NStateCall(static_cast<NName *>((yyvsp[-4].ttype)), static_cast<NArg *>((yyvsp[-2].ttype)));
    }
#line 1996 "program5.tab.cpp" /* yacc.c:1646  */
    break;

  case 45:
#line 370 "program5.ypp" /* yacc.c:1646  */
    {
        NId *printId = new NId("print");
        NNameId *print = new NNameId(printId);
        (yyval.ttype) = new NStateCall(print, static_cast<NArg *>((yyvsp[-2].ttype)));
    }
#line 2006 "program5.tab.cpp" /* yacc.c:1646  */
    break;

  case 46:
#line 375 "program5.ypp" /* yacc.c:1646  */
    {
        (yyval.ttype) = new NStateCond(static_cast<NCondition *>((yyvsp[0].ttype)));
    }
#line 2014 "program5.tab.cpp" /* yacc.c:1646  */
    break;

  case 47:
#line 378 "program5.ypp" /* yacc.c:1646  */
    {
        (yyval.ttype) = new NStateWhile(static_cast<NExp *>((yyvsp[-2].ttype)), static_cast<NStatement *>((yyvsp[0].ttype)));
    }
#line 2022 "program5.tab.cpp" /* yacc.c:1646  */
    break;

  case 48:
#line 381 "program5.ypp" /* yacc.c:1646  */
    {
        NOptExp *oe = new NOptExp(static_cast<NExp *>((yyvsp[-1].ttype)));
        (yyval.ttype) = new NStateReturn(oe);
    }
#line 2031 "program5.tab.cpp" /* yacc.c:1646  */
    break;

  case 49:
#line 385 "program5.ypp" /* yacc.c:1646  */
    {
        NOptExp *oe = new NOptExp(); // None monad
        (yyval.ttype) = new NStateReturn(oe);
    }
#line 2040 "program5.tab.cpp" /* yacc.c:1646  */
    break;

  case 50:
#line 396 "program5.ypp" /* yacc.c:1646  */
    {
        NId *id = new NId((yyvsp[0].ttype)->getText());
        (yyval.ttype) = new NNameId(id);
    }
#line 2049 "program5.tab.cpp" /* yacc.c:1646  */
    break;

  case 51:
#line 400 "program5.ypp" /* yacc.c:1646  */
    {
        NId *id = new NId((yyvsp[-2].ttype)->getText());
        (yyval.ttype) = new NNameDotId(id, static_cast<NName *>((yyvsp[0].ttype)));
    }
#line 2058 "program5.tab.cpp" /* yacc.c:1646  */
    break;

  case 52:
#line 404 "program5.ypp" /* yacc.c:1646  */
    {
        NId *id = new NId((yyvsp[-1].ttype)->getText());
        (yyval.ttype) = new NNameId(id, static_cast<NBrackExps *>((yyvsp[0].ttype)));
    }
#line 2067 "program5.tab.cpp" /* yacc.c:1646  */
    break;

  case 53:
#line 408 "program5.ypp" /* yacc.c:1646  */
    {
        (yyval.ttype) = new NNameThisDot(static_cast<NName *>((yyvsp[0].ttype)));
    }
#line 2075 "program5.tab.cpp" /* yacc.c:1646  */
    break;

  case 54:
#line 411 "program5.ypp" /* yacc.c:1646  */
    {
        NNameThis *name = new NNameThis();
        name->setNext(static_cast<NBrackExps *>((yyvsp[0].ttype)));
        (yyval.ttype) = name;
    }
#line 2085 "program5.tab.cpp" /* yacc.c:1646  */
    break;

  case 55:
#line 416 "program5.ypp" /* yacc.c:1646  */
    {
        (yyval.ttype) = new NNameThis();
    }
#line 2093 "program5.tab.cpp" /* yacc.c:1646  */
    break;

  case 56:
#line 423 "program5.ypp" /* yacc.c:1646  */
    {
        if ((yyvsp[0].ttype)->getText() != "epsilon")
        {
            (yyvsp[-1].ttype)->setNext((yyvsp[0].ttype));
        }
        (yyval.ttype) = static_cast<NArg *>((yyvsp[-1].ttype));
    }
#line 2105 "program5.tab.cpp" /* yacc.c:1646  */
    break;

  case 57:
#line 430 "program5.ypp" /* yacc.c:1646  */
    {
        (yyval.ttype) = new NEpsilon();
    }
#line 2113 "program5.tab.cpp" /* yacc.c:1646  */
    break;

  case 58:
#line 436 "program5.ypp" /* yacc.c:1646  */
    {
        if ((yyvsp[0].ttype)->getText() != "epsilon")
        {
            (yyvsp[-1].ttype)->setNext((yyvsp[0].ttype));
        }
        (yyval.ttype) = static_cast<NArg *>((yyvsp[-1].ttype));
    }
#line 2125 "program5.tab.cpp" /* yacc.c:1646  */
    break;

  case 59:
#line 443 "program5.ypp" /* yacc.c:1646  */
    {
        (yyval.ttype) = new NEpsilon();
    }
#line 2133 "program5.tab.cpp" /* yacc.c:1646  */
    break;

  case 60:
#line 448 "program5.ypp" /* yacc.c:1646  */
    {
        (yyval.ttype) = new NCondition(static_cast<NExp *>((yyvsp[-2].ttype)), static_cast<NStatement *>((yyvsp[0].ttype)));
    }
#line 2141 "program5.tab.cpp" /* yacc.c:1646  */
    break;

  case 61:
#line 451 "program5.ypp" /* yacc.c:1646  */
    {
        (yyval.ttype) = new NCondition(static_cast<NExp *>((yyvsp[-4].ttype)), static_cast<NStatement *>((yyvsp[-2].ttype)), static_cast<NStatement *>((yyvsp[0].ttype)));
    }
#line 2149 "program5.tab.cpp" /* yacc.c:1646  */
    break;

  case 62:
#line 457 "program5.ypp" /* yacc.c:1646  */
    {
        NOperator *op = new NOperator("==");
        (yyval.ttype) = new NInfixExp(op, static_cast<NExp *>((yyvsp[-2].ttype)), static_cast<NExp *>((yyvsp[0].ttype)));
    }
#line 2158 "program5.tab.cpp" /* yacc.c:1646  */
    break;

  case 63:
#line 461 "program5.ypp" /* yacc.c:1646  */
    {
        NOperator *op = new NOperator("!=");
        (yyval.ttype) = new NInfixExp(op, static_cast<NExp *>((yyvsp[-2].ttype)), static_cast<NExp *>((yyvsp[0].ttype)));
    }
#line 2167 "program5.tab.cpp" /* yacc.c:1646  */
    break;

  case 64:
#line 465 "program5.ypp" /* yacc.c:1646  */
    {
        NOperator *op = new NOperator("<");
        (yyval.ttype) = new NInfixExp(op, static_cast<NExp *>((yyvsp[-2].ttype)), static_cast<NExp *>((yyvsp[0].ttype)));
    }
#line 2176 "program5.tab.cpp" /* yacc.c:1646  */
    break;

  case 65:
#line 469 "program5.ypp" /* yacc.c:1646  */
    {
        NOperator *op = new NOperator(">");
        (yyval.ttype) = new NInfixExp(op, static_cast<NExp *>((yyvsp[-2].ttype)), static_cast<NExp *>((yyvsp[0].ttype)));
    }
#line 2185 "program5.tab.cpp" /* yacc.c:1646  */
    break;

  case 66:
#line 473 "program5.ypp" /* yacc.c:1646  */
    {
        NOperator *op = new NOperator("<=");
        (yyval.ttype) = new NInfixExp(op, static_cast<NExp *>((yyvsp[-2].ttype)), static_cast<NExp *>((yyvsp[0].ttype)));
    }
#line 2194 "program5.tab.cpp" /* yacc.c:1646  */
    break;

  case 67:
#line 477 "program5.ypp" /* yacc.c:1646  */
    {
        NOperator *op = new NOperator(">=");
        (yyval.ttype) = new NInfixExp(op, static_cast<NExp *>((yyvsp[-2].ttype)), static_cast<NExp *>((yyvsp[0].ttype)));
    }
#line 2203 "program5.tab.cpp" /* yacc.c:1646  */
    break;

  case 68:
#line 481 "program5.ypp" /* yacc.c:1646  */
    {
        NOperator *op = new NOperator("+");
        (yyval.ttype) = new NInfixExp(op, static_cast<NExp *>((yyvsp[-2].ttype)), static_cast<NExp *>((yyvsp[0].ttype)));
    }
#line 2212 "program5.tab.cpp" /* yacc.c:1646  */
    break;

  case 69:
#line 485 "program5.ypp" /* yacc.c:1646  */
    {
        NOperator *op = new NOperator("-");
        (yyval.ttype) = new NInfixExp(op, static_cast<NExp *>((yyvsp[-2].ttype)), static_cast<NExp *>((yyvsp[0].ttype)));
    }
#line 2221 "program5.tab.cpp" /* yacc.c:1646  */
    break;

  case 70:
#line 489 "program5.ypp" /* yacc.c:1646  */
    {
        NOperator *op = new NOperator("||");
        (yyval.ttype) = new NInfixExp(op, static_cast<NExp *>((yyvsp[-2].ttype)), static_cast<NExp *>((yyvsp[0].ttype)));
    }
#line 2230 "program5.tab.cpp" /* yacc.c:1646  */
    break;

  case 72:
#line 497 "program5.ypp" /* yacc.c:1646  */
    {
        NOperator *op = new NOperator("*");
        (yyval.ttype) = new NInfixExp(op, static_cast<NExp *>((yyvsp[-2].ttype)), static_cast<NExp *>((yyvsp[0].ttype)));
    }
#line 2239 "program5.tab.cpp" /* yacc.c:1646  */
    break;

  case 73:
#line 501 "program5.ypp" /* yacc.c:1646  */
    {
        NOperator *op = new NOperator("/");
        (yyval.ttype) = new NInfixExp(op, static_cast<NExp *>((yyvsp[-2].ttype)), static_cast<NExp *>((yyvsp[0].ttype)));
    }
#line 2248 "program5.tab.cpp" /* yacc.c:1646  */
    break;

  case 74:
#line 505 "program5.ypp" /* yacc.c:1646  */
    {
        NOperator *op = new NOperator("%");
        (yyval.ttype) = new NInfixExp(op, static_cast<NExp *>((yyvsp[-2].ttype)), static_cast<NExp *>((yyvsp[0].ttype)));
    }
#line 2257 "program5.tab.cpp" /* yacc.c:1646  */
    break;

  case 75:
#line 509 "program5.ypp" /* yacc.c:1646  */
    {
        NOperator *op = new NOperator("&&");
        (yyval.ttype) = new NInfixExp(op, static_cast<NExp *>((yyvsp[-2].ttype)), static_cast<NExp *>((yyvsp[0].ttype)));
    }
#line 2266 "program5.tab.cpp" /* yacc.c:1646  */
    break;

  case 78:
#line 522 "program5.ypp" /* yacc.c:1646  */
    {
        NOperator *op = new NOperator("!");
        (yyval.ttype) = new NPrefixExp(op, static_cast<NExp *>((yyvsp[0].ttype)));
    }
#line 2275 "program5.tab.cpp" /* yacc.c:1646  */
    break;

  case 79:
#line 526 "program5.ypp" /* yacc.c:1646  */
    {
        (yyval.ttype) = (yyvsp[0].ttype);
    }
#line 2283 "program5.tab.cpp" /* yacc.c:1646  */
    break;

  case 80:
#line 529 "program5.ypp" /* yacc.c:1646  */
    {
        (yyval.ttype) = new NParenExp(static_cast<NExp *>((yyvsp[-1].ttype)));
    }
#line 2291 "program5.tab.cpp" /* yacc.c:1646  */
    break;

  case 81:
#line 532 "program5.ypp" /* yacc.c:1646  */
    {
        int i = atoi((yyvsp[0].ttype)->getText().c_str());
        (yyval.ttype) = new NNumber(i);
    }
#line 2300 "program5.tab.cpp" /* yacc.c:1646  */
    break;

  case 82:
#line 536 "program5.ypp" /* yacc.c:1646  */
    {
        (yyval.ttype) = new NExpNull();
    }
#line 2308 "program5.tab.cpp" /* yacc.c:1646  */
    break;

  case 83:
#line 539 "program5.ypp" /* yacc.c:1646  */
    {
        (yyval.ttype) = new NExpCall(static_cast<NName *>((yyvsp[-3].ttype)), static_cast<NArg *>((yyvsp[-1].ttype)));
    }
#line 2316 "program5.tab.cpp" /* yacc.c:1646  */
    break;

  case 84:
#line 542 "program5.ypp" /* yacc.c:1646  */
    {
        (yyval.ttype) = new NExpRead();
    }
#line 2324 "program5.tab.cpp" /* yacc.c:1646  */
    break;

  case 85:
#line 545 "program5.ypp" /* yacc.c:1646  */
    {
        (yyval.ttype) = new NExpNewExp(static_cast<NNewExp *>((yyvsp[0].ttype)));
    }
#line 2332 "program5.tab.cpp" /* yacc.c:1646  */
    break;

  case 86:
#line 551 "program5.ypp" /* yacc.c:1646  */
    {
        NId *id = new NId((yyvsp[-3].ttype)->getText());
        (yyval.ttype) = new NNewExpIdArgs(id, static_cast<NArg *>((yyvsp[-1].ttype)));
    }
#line 2341 "program5.tab.cpp" /* yacc.c:1646  */
    break;

  case 87:
#line 555 "program5.ypp" /* yacc.c:1646  */
    {
        (yyval.ttype) = new NNewExpType(static_cast<NSimpleType *>((yyvsp[0].ttype)));
    }
#line 2349 "program5.tab.cpp" /* yacc.c:1646  */
    break;

  case 88:
#line 558 "program5.ypp" /* yacc.c:1646  */
    {
        int bracks = static_cast<NType *>((yyvsp[0].ttype))->getBracks();
        NBracks *brackNode = new NBracks(bracks);
        (yyval.ttype) = new NNewExpType(static_cast<NSimpleType *>((yyvsp[-1].ttype)), brackNode);
    }
#line 2359 "program5.tab.cpp" /* yacc.c:1646  */
    break;

  case 89:
#line 563 "program5.ypp" /* yacc.c:1646  */
    {
        (yyval.ttype) = new NNewExpType(static_cast<NSimpleType *>((yyvsp[-1].ttype)), static_cast<NBrackExps *>((yyvsp[0].ttype)));
    }
#line 2367 "program5.tab.cpp" /* yacc.c:1646  */
    break;

  case 90:
#line 566 "program5.ypp" /* yacc.c:1646  */
    {
        int bracks = static_cast<NType *>((yyvsp[0].ttype))->getBracks();
        NBracks *brackNode = new NBracks(bracks);
        (yyval.ttype) = new NNewExpType(static_cast<NSimpleType *>((yyvsp[-2].ttype)), static_cast<NBrackExps *>((yyvsp[-1].ttype)), brackNode);
    }
#line 2377 "program5.tab.cpp" /* yacc.c:1646  */
    break;

  case 91:
#line 574 "program5.ypp" /* yacc.c:1646  */
    {
        NId *id = new NId((yyvsp[0].ttype)->getText());
        (yyval.ttype) = new NSimpleType(id);
    }
#line 2386 "program5.tab.cpp" /* yacc.c:1646  */
    break;

  case 92:
#line 578 "program5.ypp" /* yacc.c:1646  */
    {
        NKeyword *intKey = new NKeyword("int");
        (yyval.ttype) = new NSimpleType(intKey);
    }
#line 2395 "program5.tab.cpp" /* yacc.c:1646  */
    break;

  case 93:
#line 585 "program5.ypp" /* yacc.c:1646  */
    {
        NBrackExps *curr = new NBrackExps(static_cast<NExp *>((yyvsp[-2].ttype)));
        curr->setNext(static_cast<NBrackExps *>((yyvsp[0].ttype)));
        (yyval.ttype) = curr;
    }
#line 2405 "program5.tab.cpp" /* yacc.c:1646  */
    break;

  case 94:
#line 590 "program5.ypp" /* yacc.c:1646  */
    {
        (yyval.ttype) = new NBrackExps(static_cast<NExp *>((yyvsp[-1].ttype)));
    }
#line 2413 "program5.tab.cpp" /* yacc.c:1646  */
    break;

  case 95:
#line 596 "program5.ypp" /* yacc.c:1646  */
    {
        (yyval.ttype) = new NType(0, static_cast<NType *>((yyvsp[0].ttype))->getBracks()+1);
    }
#line 2421 "program5.tab.cpp" /* yacc.c:1646  */
    break;

  case 96:
#line 599 "program5.ypp" /* yacc.c:1646  */
    {
        (yyval.ttype) = new NType(0, 1);
    }
#line 2429 "program5.tab.cpp" /* yacc.c:1646  */
    break;


#line 2433 "program5.tab.cpp" /* yacc.c:1646  */
      default: break;
    }
  /* User semantic actions sometimes alter yychar, and that requires
     that yytoken be updated with the new translation.  We take the
     approach of translating immediately before every use of yytoken.
     One alternative is translating here after every semantic action,
     but that translation would be missed if the semantic action invokes
     YYABORT, YYACCEPT, or YYERROR immediately after altering yychar or
     if it invokes YYBACKUP.  In the case of YYABORT or YYACCEPT, an
     incorrect destructor might then be invoked immediately.  In the
     case of YYERROR or YYBACKUP, subsequent parser actions might lead
     to an incorrect destructor call or verbose syntax error message
     before the lookahead is translated.  */
  YY_SYMBOL_PRINT ("-> $$ =", yyr1[yyn], &yyval, &yyloc);

  YYPOPSTACK (yylen);
  yylen = 0;
  YY_STACK_PRINT (yyss, yyssp);

  *++yyvsp = yyval;
  *++yylsp = yyloc;

  /* Now 'shift' the result of the reduction.  Determine what state
     that goes to, based on the state we popped back to and the rule
     number reduced by.  */

  yyn = yyr1[yyn];

  yystate = yypgoto[yyn - YYNTOKENS] + *yyssp;
  if (0 <= yystate && yystate <= YYLAST && yycheck[yystate] == *yyssp)
    yystate = yytable[yystate];
  else
    yystate = yydefgoto[yyn - YYNTOKENS];

  goto yynewstate;


/*--------------------------------------.
| yyerrlab -- here on detecting error.  |
`--------------------------------------*/
yyerrlab:
  /* Make sure we have latest lookahead translation.  See comments at
     user semantic actions for why this is necessary.  */
  yytoken = yychar == YYEMPTY ? YYEMPTY : YYTRANSLATE (yychar);

  /* If not already recovering from an error, report this error.  */
  if (!yyerrstatus)
    {
      ++yynerrs;
#if ! YYERROR_VERBOSE
      yyerror (YY_("syntax error"));
#else
# define YYSYNTAX_ERROR yysyntax_error (&yymsg_alloc, &yymsg, \
                                        yyssp, yytoken)
      {
        char const *yymsgp = YY_("syntax error");
        int yysyntax_error_status;
        yysyntax_error_status = YYSYNTAX_ERROR;
        if (yysyntax_error_status == 0)
          yymsgp = yymsg;
        else if (yysyntax_error_status == 1)
          {
            if (yymsg != yymsgbuf)
              YYSTACK_FREE (yymsg);
            yymsg = (char *) YYSTACK_ALLOC (yymsg_alloc);
            if (!yymsg)
              {
                yymsg = yymsgbuf;
                yymsg_alloc = sizeof yymsgbuf;
                yysyntax_error_status = 2;
              }
            else
              {
                yysyntax_error_status = YYSYNTAX_ERROR;
                yymsgp = yymsg;
              }
          }
        yyerror (yymsgp);
        if (yysyntax_error_status == 2)
          goto yyexhaustedlab;
      }
# undef YYSYNTAX_ERROR
#endif
    }

  yyerror_range[1] = yylloc;

  if (yyerrstatus == 3)
    {
      /* If just tried and failed to reuse lookahead token after an
         error, discard it.  */

      if (yychar <= YYEOF)
        {
          /* Return failure if at end of input.  */
          if (yychar == YYEOF)
            YYABORT;
        }
      else
        {
          yydestruct ("Error: discarding",
                      yytoken, &yylval, &yylloc);
          yychar = YYEMPTY;
        }
    }

  /* Else will try to reuse lookahead token after shifting the error
     token.  */
  goto yyerrlab1;


/*---------------------------------------------------.
| yyerrorlab -- error raised explicitly by YYERROR.  |
`---------------------------------------------------*/
yyerrorlab:

  /* Pacify compilers like GCC when the user code never invokes
     YYERROR and the label yyerrorlab therefore never appears in user
     code.  */
  if (/*CONSTCOND*/ 0)
     goto yyerrorlab;

  yyerror_range[1] = yylsp[1-yylen];
  /* Do not reclaim the symbols of the rule whose action triggered
     this YYERROR.  */
  YYPOPSTACK (yylen);
  yylen = 0;
  YY_STACK_PRINT (yyss, yyssp);
  yystate = *yyssp;
  goto yyerrlab1;


/*-------------------------------------------------------------.
| yyerrlab1 -- common code for both syntax error and YYERROR.  |
`-------------------------------------------------------------*/
yyerrlab1:
  yyerrstatus = 3;      /* Each real token shifted decrements this.  */

  for (;;)
    {
      yyn = yypact[yystate];
      if (!yypact_value_is_default (yyn))
        {
          yyn += YYTERROR;
          if (0 <= yyn && yyn <= YYLAST && yycheck[yyn] == YYTERROR)
            {
              yyn = yytable[yyn];
              if (0 < yyn)
                break;
            }
        }

      /* Pop the current state because it cannot handle the error token.  */
      if (yyssp == yyss)
        YYABORT;

      yyerror_range[1] = *yylsp;
      yydestruct ("Error: popping",
                  yystos[yystate], yyvsp, yylsp);
      YYPOPSTACK (1);
      yystate = *yyssp;
      YY_STACK_PRINT (yyss, yyssp);
    }

  YY_IGNORE_MAYBE_UNINITIALIZED_BEGIN
  *++yyvsp = yylval;
  YY_IGNORE_MAYBE_UNINITIALIZED_END

  yyerror_range[2] = yylloc;
  /* Using YYLLOC is tempting, but would change the location of
     the lookahead.  YYLOC is available though.  */
  YYLLOC_DEFAULT (yyloc, yyerror_range, 2);
  *++yylsp = yyloc;

  /* Shift the error token.  */
  YY_SYMBOL_PRINT ("Shifting", yystos[yyn], yyvsp, yylsp);

  yystate = yyn;
  goto yynewstate;


/*-------------------------------------.
| yyacceptlab -- YYACCEPT comes here.  |
`-------------------------------------*/
yyacceptlab:
  yyresult = 0;
  goto yyreturn;

/*-----------------------------------.
| yyabortlab -- YYABORT comes here.  |
`-----------------------------------*/
yyabortlab:
  yyresult = 1;
  goto yyreturn;

#if !defined yyoverflow || YYERROR_VERBOSE
/*-------------------------------------------------.
| yyexhaustedlab -- memory exhaustion comes here.  |
`-------------------------------------------------*/
yyexhaustedlab:
  yyerror (YY_("memory exhausted"));
  yyresult = 2;
  /* Fall through.  */
#endif

yyreturn:
  if (yychar != YYEMPTY)
    {
      /* Make sure we have latest lookahead translation.  See comments at
         user semantic actions for why this is necessary.  */
      yytoken = YYTRANSLATE (yychar);
      yydestruct ("Cleanup: discarding lookahead",
                  yytoken, &yylval, &yylloc);
    }
  /* Do not reclaim the symbols of the rule whose action triggered
     this YYABORT or YYACCEPT.  */
  YYPOPSTACK (yylen);
  YY_STACK_PRINT (yyss, yyssp);
  while (yyssp != yyss)
    {
      yydestruct ("Cleanup: popping",
                  yystos[*yyssp], yyvsp, yylsp);
      YYPOPSTACK (1);
    }
#ifndef yyoverflow
  if (yyss != yyssa)
    YYSTACK_FREE (yyss);
#endif
#if YYERROR_VERBOSE
  if (yymsg != yymsgbuf)
    YYSTACK_FREE (yymsg);
#endif
  return yyresult;
}
#line 605 "program5.ypp" /* yacc.c:1906  */

