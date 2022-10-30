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
#line 9 "program4.ypp" /* yacc.c:339  */


#include <iostream>
#include <FlexLexer.h>
#include <string>
#include <typeinfo>
#include "nodes/include/nodes.hpp"
#define YYERROR_VERBOSE

using std::cerr;
using std::cout;
using std::endl;

class BaseNode;
extern BaseNode *ast;
extern yyFlexLexer lexer;

#define yylex() lexer.yylex()
void yyerror(const char* string);


#line 88 "y.tab.c" /* yacc.c:339  */

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
/* Tokens.  */
#define PLUS 260
#define MINUS 261
#define NOT 262
#define OR 263
#define SEMI 264
#define DOT 265
#define COMMA 266
#define ID 267
#define LPAREN 268
#define RPAREN 269
#define LBRACKET 270
#define RBRACKET 271
#define RBRACE 272
#define LBRACE 273
#define NUMBER 274
#define NULLT 275
#define READ 276
#define NEW 277
#define THIS 278
#define IF 279
#define ELSE 280
#define WHILE 281
#define RETURN 282
#define CLASS 283
#define PRINT 284
#define VOID 285
#define TIMES 286
#define DIV 287
#define MOD 288
#define AND 289
#define EQ 290
#define NE 291
#define GE 292
#define LE 293
#define GT 294
#define LT 295
#define ASSIGN 296
#define INT 297
#define ER_WD 298
#define ER_CH 299

/* Value type.  */
#if ! defined YYSTYPE && ! defined YYSTYPE_IS_DECLARED

union YYSTYPE
{
#line 33 "program4.ypp" /* yacc.c:355  */

    BaseNode *ttype;

#line 213 "y.tab.c" /* yacc.c:355  */
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



/* Copy the second part of user declarations.  */

#line 244 "y.tab.c" /* yacc.c:358  */

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
#define YYFINAL  5
/* YYLAST -- Last index in YYTABLE.  */
#define YYLAST   267

/* YYNTOKENS -- Number of terminals.  */
#define YYNTOKENS  45
/* YYNNTS -- Number of nonterminals.  */
#define YYNNTS  27
/* YYNRULES -- Number of rules.  */
#define YYNRULES  80
/* YYNSTATES -- Number of states.  */
#define YYNSTATES  182

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
       0,    60,    60,    67,    73,    79,    82,    85,    88,    92,
      96,    99,   102,   106,   109,   112,   116,   119,   125,   129,
     135,   138,   143,   149,   156,   159,   162,   165,   171,   172,
     175,   178,   181,   184,   187,   190,   193,   199,   202,   206,
     209,   212,   218,   221,   227,   230,   236,   237,   238,   239,
     240,   241,   242,   243,   244,   245,   250,   251,   252,   253,
     257,   258,   263,   264,   267,   270,   273,   276,   279,   282,
     288,   291,   294,   297,   300,   306,   309,   315,   318,   324,
     327
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
  "localVarDeclaration", "statement", "thisName", "name", "argList",
  "conditionalStatement", "expression", "rterm", "term", "factor",
  "newExpression", "newExpTypes", "brackExp", "bracks", YY_NULLPTR
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

#define YYPACT_NINF -135

#define yypact_value_is_default(Yystate) \
  (!!((Yystate) == (-135)))

#define YYTABLE_NINF -61

#define yytable_value_is_error(Yytable_value) \
  0

  /* YYPACT[STATE-NUM] -- Index in YYTABLE of the portion describing
     STATE-NUM.  */
static const yytype_int16 yypact[] =
{
     -10,    28,    30,  -135,    42,  -135,    16,  -135,   107,  -135,
      60,    -6,  -135,  -135,  -135,    94,     2,    83,   128,   135,
     132,   137,    16,   136,   136,   143,   142,   146,   136,    40,
       2,    16,   141,  -135,  -135,  -135,  -135,   140,     2,  -135,
    -135,    16,     2,   151,  -135,    16,     2,   170,    68,   146,
    -135,   158,   140,  -135,   166,  -135,    46,  -135,   169,   171,
     172,   198,   178,   180,  -135,  -135,   170,   170,    18,  -135,
    -135,    82,   136,  -135,  -135,   140,    68,   140,   169,   215,
    -135,    47,  -135,   232,   232,   232,  -135,   232,  -135,  -135,
     185,     5,   189,    78,  -135,   209,  -135,  -135,   232,   174,
    -135,  -135,   232,   232,   196,   197,    68,  -135,    68,  -135,
      -1,   232,    88,   124,  -135,   131,   176,   201,  -135,   200,
     232,   232,   232,   232,  -135,   232,   232,   232,   232,   232,
     232,   232,   232,   232,   232,   202,    69,  -135,   210,   138,
     213,   217,  -135,  -135,  -135,   177,   177,  -135,  -135,   232,
     136,  -135,   218,   209,   209,   229,   209,  -135,  -135,  -135,
    -135,  -135,  -135,  -135,  -135,  -135,  -135,   214,  -135,   224,
    -135,  -135,   225,  -135,   235,  -135,  -135,  -135,  -135,   177,
    -135,  -135
};

  /* YYDEFACT[STATE-NUM] -- Default reduction number in state STATE-NUM.
     Performed when YYTABLE does not specify something else to do.  Zero
     means the default is an error.  */
static const yytype_uint8 yydefact[] =
{
       0,     0,     0,     2,     0,     1,     0,     3,     0,    15,
       0,     0,     4,     9,    12,     0,    19,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,    21,    80,     0,
      19,     0,     0,     8,    17,    16,    22,     0,     0,    18,
      79,     0,    19,     0,     7,     0,    19,     0,     0,    21,
       6,     0,     0,     5,     0,    28,    39,    26,     0,     0,
       0,     0,     0,     0,    36,    23,     0,     0,     0,    38,
      32,     0,     0,    10,    20,     0,     0,     0,     0,     0,
      41,    39,    37,     0,     0,     0,    35,     0,    65,    66,
       0,     0,    63,     0,    60,    55,    61,    69,    43,     0,
      24,    25,    43,     0,     0,     0,     0,    11,     0,    40,
       0,     0,     0,     0,    62,     0,     0,    75,    76,    71,
      43,     0,     0,     0,    34,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,    43,    27,     0,     0,
       0,     0,    14,    13,    78,     0,     0,    64,    68,    43,
      73,    72,     0,    52,    53,    54,     0,    46,    47,    51,
      50,    49,    48,    56,    57,    58,    59,     0,    42,     0,
      29,    77,    44,    33,     0,    74,    67,    31,    30,     0,
      70,    45
};

  /* YYPGOTO[NTERM-NUM].  */
static const yytype_int16 yypgoto[] =
{
    -135,  -135,  -135,  -135,    90,   -35,  -135,    86,   183,   216,
     226,   -27,    12,  -135,  -134,   -45,   -26,   -94,  -135,   -60,
     144,   125,   181,  -135,  -135,   -90,    -8
};

  /* YYDEFGOTO[NTERM-NUM].  */
static const yytype_int16 yydefgoto[] =
{
      -1,     2,     3,     7,    12,    13,    14,    25,    26,    39,
      27,    64,    65,    66,    67,    92,    69,   135,    70,   136,
      94,    95,    96,    97,   119,    80,    34
};

  /* YYTABLE[YYPACT[STATE-NUM]] -- What to do in state STATE-NUM.  If
     positive, shift that token.  If negative, reduce the rule whose
     number is the opposite.  If YYTABLE_NINF, syntax error.  */
static const yytype_int16 yytable[] =
{
      18,    93,    68,    21,   121,   122,    20,   123,   138,    17,
      48,   172,   173,    73,    23,   144,    35,   117,     1,   110,
      40,    68,    68,   112,   113,    76,   152,   115,     8,   150,
       5,   102,    82,     9,   125,   126,   127,   128,   129,   130,
       4,   107,   168,   139,    24,   181,    10,   118,   106,    41,
     108,   110,   109,    42,   171,   174,    78,    78,    11,   103,
       6,    79,   111,   104,   105,   157,   158,   159,   160,   161,
     162,   142,    19,   143,   121,   122,    85,   123,   100,   101,
      71,    81,    87,   121,   122,     9,   123,   124,    88,    89,
      90,    91,    58,   121,   122,    16,   123,    17,    10,    28,
      68,    68,   145,    22,   125,   126,   127,   128,   129,   130,
      72,   151,    33,   125,   126,   127,   128,   129,   130,    15,
      16,    44,    17,   125,   126,   127,   128,   129,   130,   121,
     122,    50,   123,    63,    68,    53,   121,   122,   146,   123,
      29,    31,   175,   121,   122,   147,   123,   170,    30,    32,
      45,    17,    63,    63,    46,    36,    37,    38,    47,   125,
     126,   127,   128,   129,   130,    52,   125,   126,   127,   128,
     129,   130,    75,   125,   126,   127,   128,   129,   130,    55,
      77,    81,    56,   137,    83,    84,    55,    57,    47,    81,
     148,    98,    99,    58,    59,    47,    60,    61,   116,    62,
      58,    59,   120,    60,    61,    85,    62,    86,   140,   141,
      81,    87,    24,    43,   149,    79,   167,    88,    89,    90,
      91,    58,    85,   177,   169,    51,    42,    81,    87,    54,
      46,    28,   176,   178,    88,    89,    90,    91,    58,    85,
     131,   132,   133,   134,    81,    87,   153,   154,   156,   180,
     179,    88,    89,    90,    91,    58,   163,   164,   165,   166,
     -60,   -60,   -60,   -60,    49,    74,   114,   155
};

static const yytype_uint8 yycheck[] =
{
       8,    61,    47,    11,     5,     6,    12,     8,   102,    15,
      37,   145,   146,    48,    12,    16,    24,    12,    28,    79,
      28,    66,    67,    83,    84,    52,   120,    87,    12,   119,
       0,    13,    58,    17,    35,    36,    37,    38,    39,    40,
      12,    76,   136,   103,    42,   179,    30,    42,    75,     9,
      77,   111,    78,    13,   144,   149,    10,    10,    42,    41,
      18,    15,    15,    71,    72,   125,   126,   127,   128,   129,
     130,   106,    12,   108,     5,     6,     7,     8,    66,    67,
      12,    12,    13,     5,     6,    17,     8,     9,    19,    20,
      21,    22,    23,     5,     6,    13,     8,    15,    30,    16,
     145,   146,    14,     9,    35,    36,    37,    38,    39,    40,
      42,   119,    22,    35,    36,    37,    38,    39,    40,    12,
      13,    31,    15,    35,    36,    37,    38,    39,    40,     5,
       6,    41,     8,    47,   179,    45,     5,     6,    14,     8,
      12,     9,   150,     5,     6,    14,     8,     9,    13,    12,
       9,    15,    66,    67,    13,    12,    14,    11,    18,    35,
      36,    37,    38,    39,    40,    14,    35,    36,    37,    38,
      39,    40,    14,    35,    36,    37,    38,    39,    40,     9,
      14,    12,    12,     9,    13,    13,     9,    17,    18,    12,
      14,    13,    12,    23,    24,    18,    26,    27,    13,    29,
      23,    24,    13,    26,    27,     7,    29,     9,    12,    12,
      12,    13,    42,    30,    13,    15,    14,    19,    20,    21,
      22,    23,     7,     9,    14,    42,    13,    12,    13,    46,
      13,    16,    14,     9,    19,    20,    21,    22,    23,     7,
      31,    32,    33,    34,    12,    13,   121,   122,   123,    14,
      25,    19,    20,    21,    22,    23,   131,   132,   133,   134,
      31,    32,    33,    34,    38,    49,    85,   123
};

  /* YYSTOS[STATE-NUM] -- The (internal number of the) accessing
     symbol of state STATE-NUM.  */
static const yytype_uint8 yystos[] =
{
       0,    28,    46,    47,    12,     0,    18,    48,    12,    17,
      30,    42,    49,    50,    51,    12,    13,    15,    71,    12,
      12,    71,     9,    12,    42,    52,    53,    55,    16,    12,
      13,     9,    12,    49,    71,    71,    12,    14,    11,    54,
      71,     9,    13,    53,    49,     9,    13,    18,    56,    55,
      49,    53,    14,    49,    53,     9,    12,    17,    23,    24,
      26,    27,    29,    52,    56,    57,    58,    59,    60,    61,
      63,    12,    42,    50,    54,    14,    56,    14,    10,    15,
      70,    12,    61,    13,    13,     7,     9,    13,    19,    20,
      21,    22,    60,    64,    65,    66,    67,    68,    13,    12,
      57,    57,    13,    41,    71,    71,    56,    50,    56,    61,
      64,    15,    64,    64,    67,    64,    13,    12,    42,    69,
      13,     5,     6,     8,     9,    35,    36,    37,    38,    39,
      40,    31,    32,    33,    34,    62,    64,     9,    62,    64,
      12,    12,    50,    50,    16,    14,    14,    14,    14,    13,
      70,    71,    62,    66,    66,    65,    66,    64,    64,    64,
      64,    64,    64,    66,    66,    66,    66,    14,    62,    14,
       9,    70,    59,    59,    62,    71,    14,     9,     9,    25,
      14,    59
};

  /* YYR1[YYN] -- Symbol number of symbol that rule YYN derives.  */
static const yytype_uint8 yyr1[] =
{
       0,    45,    46,    47,    48,    49,    49,    49,    49,    49,
      50,    50,    50,    51,    51,    51,    52,    52,    53,    53,
      54,    54,    55,    56,    57,    57,    57,    58,    59,    59,
      59,    59,    59,    59,    59,    59,    59,    60,    60,    61,
      61,    61,    62,    62,    63,    63,    64,    64,    64,    64,
      64,    64,    64,    64,    64,    64,    65,    65,    65,    65,
      66,    66,    67,    67,    67,    67,    67,    67,    67,    67,
      68,    68,    68,    68,    68,    69,    69,    70,    70,    71,
      71
};

  /* YYR2[YYN] -- Number of symbols on the right hand side of rule YYN.  */
static const yytype_uint8 yyr2[] =
{
       0,     2,     1,     3,     2,     5,     5,     4,     4,     1,
       6,     7,     1,     8,     8,     1,     2,     2,     2,     0,
       3,     0,     2,     2,     2,     2,     1,     3,     1,     4,
       5,     5,     1,     5,     3,     2,     1,     2,     1,     1,
       3,     2,     2,     0,     5,     7,     3,     3,     3,     3,
       3,     3,     3,     3,     3,     1,     3,     3,     3,     3,
       1,     1,     2,     1,     3,     1,     1,     4,     3,     1,
       5,     2,     3,     3,     4,     1,     1,     4,     3,     3,
       2
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
#line 60 "program4.ypp" /* yacc.c:1646  */
    { 
        ast = new NProgram(static_cast<NClassDecl*>((yyvsp[0].ttype)));
        (yyval.ttype) = ast;
    }
#line 1559 "y.tab.c" /* yacc.c:1646  */
    break;

  case 3:
#line 67 "program4.ypp" /* yacc.c:1646  */
    {
        (yyval.ttype) = new NClassDecl(static_cast<NId*>((yyvsp[-1].ttype)), static_cast<NClassBody*>((yyvsp[0].ttype)));
    }
#line 1567 "y.tab.c" /* yacc.c:1646  */
    break;

  case 4:
#line 73 "program4.ypp" /* yacc.c:1646  */
    {
        (yyval.ttype) = new NClassBody((yyvsp[0].ttype));
    }
#line 1575 "y.tab.c" /* yacc.c:1646  */
    break;

  case 5:
#line 79 "program4.ypp" /* yacc.c:1646  */
    {

    }
#line 1583 "y.tab.c" /* yacc.c:1646  */
    break;

  case 6:
#line 82 "program4.ypp" /* yacc.c:1646  */
    {

    }
#line 1591 "y.tab.c" /* yacc.c:1646  */
    break;

  case 7:
#line 85 "program4.ypp" /* yacc.c:1646  */
    {

    }
#line 1599 "y.tab.c" /* yacc.c:1646  */
    break;

  case 8:
#line 88 "program4.ypp" /* yacc.c:1646  */
    {

    }
#line 1607 "y.tab.c" /* yacc.c:1646  */
    break;

  case 10:
#line 96 "program4.ypp" /* yacc.c:1646  */
    {

    }
#line 1615 "y.tab.c" /* yacc.c:1646  */
    break;

  case 11:
#line 99 "program4.ypp" /* yacc.c:1646  */
    {

    }
#line 1623 "y.tab.c" /* yacc.c:1646  */
    break;

  case 13:
#line 106 "program4.ypp" /* yacc.c:1646  */
    {

    }
#line 1631 "y.tab.c" /* yacc.c:1646  */
    break;

  case 14:
#line 109 "program4.ypp" /* yacc.c:1646  */
    {

    }
#line 1639 "y.tab.c" /* yacc.c:1646  */
    break;

  case 15:
#line 112 "program4.ypp" /* yacc.c:1646  */
    { }
#line 1645 "y.tab.c" /* yacc.c:1646  */
    break;

  case 16:
#line 116 "program4.ypp" /* yacc.c:1646  */
    {
        // TODO
    }
#line 1653 "y.tab.c" /* yacc.c:1646  */
    break;

  case 17:
#line 119 "program4.ypp" /* yacc.c:1646  */
    {
        // TODO
    }
#line 1661 "y.tab.c" /* yacc.c:1646  */
    break;

  case 18:
#line 125 "program4.ypp" /* yacc.c:1646  */
    {
        // TODO properly build this list
        // $$ = new LParams();
    }
#line 1670 "y.tab.c" /* yacc.c:1646  */
    break;

  case 19:
#line 129 "program4.ypp" /* yacc.c:1646  */
    {
        // $$ = new NEpsilon();
    }
#line 1678 "y.tab.c" /* yacc.c:1646  */
    break;

  case 20:
#line 135 "program4.ypp" /* yacc.c:1646  */
    {

    }
#line 1686 "y.tab.c" /* yacc.c:1646  */
    break;

  case 21:
#line 138 "program4.ypp" /* yacc.c:1646  */
    {
        // $$ = new NEpsilon();
    }
#line 1694 "y.tab.c" /* yacc.c:1646  */
    break;

  case 22:
#line 143 "program4.ypp" /* yacc.c:1646  */
    {
        // $$ = new NParam(static_cast<NType *>($1), static_cast<NId *>($2));
    }
#line 1702 "y.tab.c" /* yacc.c:1646  */
    break;

  case 23:
#line 149 "program4.ypp" /* yacc.c:1646  */
    {
        // TODO
    }
#line 1710 "y.tab.c" /* yacc.c:1646  */
    break;

  case 24:
#line 156 "program4.ypp" /* yacc.c:1646  */
    {

    }
#line 1718 "y.tab.c" /* yacc.c:1646  */
    break;

  case 25:
#line 159 "program4.ypp" /* yacc.c:1646  */
    {
        // done w/ local var decls
    }
#line 1726 "y.tab.c" /* yacc.c:1646  */
    break;

  case 26:
#line 162 "program4.ypp" /* yacc.c:1646  */
    {}
#line 1732 "y.tab.c" /* yacc.c:1646  */
    break;

  case 27:
#line 165 "program4.ypp" /* yacc.c:1646  */
    {
        // $$ = new NVarDecl(static_cast<NType *>($1), static_cast<NId *>($2));
    }
#line 1740 "y.tab.c" /* yacc.c:1646  */
    break;

  case 28:
#line 171 "program4.ypp" /* yacc.c:1646  */
    {}
#line 1746 "y.tab.c" /* yacc.c:1646  */
    break;

  case 29:
#line 172 "program4.ypp" /* yacc.c:1646  */
    {
        // TODO
    }
#line 1754 "y.tab.c" /* yacc.c:1646  */
    break;

  case 30:
#line 175 "program4.ypp" /* yacc.c:1646  */
    {
        // TODO
    }
#line 1762 "y.tab.c" /* yacc.c:1646  */
    break;

  case 31:
#line 178 "program4.ypp" /* yacc.c:1646  */
    {
        // TODO
    }
#line 1770 "y.tab.c" /* yacc.c:1646  */
    break;

  case 32:
#line 181 "program4.ypp" /* yacc.c:1646  */
    {
        // TODO
    }
#line 1778 "y.tab.c" /* yacc.c:1646  */
    break;

  case 33:
#line 184 "program4.ypp" /* yacc.c:1646  */
    {
        // TODO
    }
#line 1786 "y.tab.c" /* yacc.c:1646  */
    break;

  case 34:
#line 187 "program4.ypp" /* yacc.c:1646  */
    {
        // TODO
    }
#line 1794 "y.tab.c" /* yacc.c:1646  */
    break;

  case 35:
#line 190 "program4.ypp" /* yacc.c:1646  */
    {
        // TODO
    }
#line 1802 "y.tab.c" /* yacc.c:1646  */
    break;

  case 36:
#line 193 "program4.ypp" /* yacc.c:1646  */
    {
        // TODO
    }
#line 1810 "y.tab.c" /* yacc.c:1646  */
    break;

  case 37:
#line 199 "program4.ypp" /* yacc.c:1646  */
    {

    }
#line 1818 "y.tab.c" /* yacc.c:1646  */
    break;

  case 39:
#line 206 "program4.ypp" /* yacc.c:1646  */
    {
        // TODO
    }
#line 1826 "y.tab.c" /* yacc.c:1646  */
    break;

  case 40:
#line 209 "program4.ypp" /* yacc.c:1646  */
    {
        // TODO
    }
#line 1834 "y.tab.c" /* yacc.c:1646  */
    break;

  case 41:
#line 212 "program4.ypp" /* yacc.c:1646  */
    {
        // TODO
    }
#line 1842 "y.tab.c" /* yacc.c:1646  */
    break;

  case 42:
#line 218 "program4.ypp" /* yacc.c:1646  */
    {
        // TODO
    }
#line 1850 "y.tab.c" /* yacc.c:1646  */
    break;

  case 43:
#line 221 "program4.ypp" /* yacc.c:1646  */
    {
        // $$ = new NEpsilon();
    }
#line 1858 "y.tab.c" /* yacc.c:1646  */
    break;

  case 44:
#line 227 "program4.ypp" /* yacc.c:1646  */
    {
        // TODO
    }
#line 1866 "y.tab.c" /* yacc.c:1646  */
    break;

  case 45:
#line 230 "program4.ypp" /* yacc.c:1646  */
    {
        // TODO
    }
#line 1874 "y.tab.c" /* yacc.c:1646  */
    break;

  case 46:
#line 236 "program4.ypp" /* yacc.c:1646  */
    { }
#line 1880 "y.tab.c" /* yacc.c:1646  */
    break;

  case 47:
#line 237 "program4.ypp" /* yacc.c:1646  */
    { }
#line 1886 "y.tab.c" /* yacc.c:1646  */
    break;

  case 48:
#line 238 "program4.ypp" /* yacc.c:1646  */
    { }
#line 1892 "y.tab.c" /* yacc.c:1646  */
    break;

  case 49:
#line 239 "program4.ypp" /* yacc.c:1646  */
    { }
#line 1898 "y.tab.c" /* yacc.c:1646  */
    break;

  case 50:
#line 240 "program4.ypp" /* yacc.c:1646  */
    { }
#line 1904 "y.tab.c" /* yacc.c:1646  */
    break;

  case 51:
#line 241 "program4.ypp" /* yacc.c:1646  */
    { }
#line 1910 "y.tab.c" /* yacc.c:1646  */
    break;

  case 63:
#line 264 "program4.ypp" /* yacc.c:1646  */
    {
        // TODO
    }
#line 1918 "y.tab.c" /* yacc.c:1646  */
    break;

  case 64:
#line 267 "program4.ypp" /* yacc.c:1646  */
    {
        // TODO
    }
#line 1926 "y.tab.c" /* yacc.c:1646  */
    break;

  case 65:
#line 270 "program4.ypp" /* yacc.c:1646  */
    {
        // TODO
    }
#line 1934 "y.tab.c" /* yacc.c:1646  */
    break;

  case 66:
#line 273 "program4.ypp" /* yacc.c:1646  */
    {
        // TODO
    }
#line 1942 "y.tab.c" /* yacc.c:1646  */
    break;

  case 67:
#line 276 "program4.ypp" /* yacc.c:1646  */
    {
        // TODO
    }
#line 1950 "y.tab.c" /* yacc.c:1646  */
    break;

  case 68:
#line 279 "program4.ypp" /* yacc.c:1646  */
    {
        // TODO
    }
#line 1958 "y.tab.c" /* yacc.c:1646  */
    break;

  case 69:
#line 282 "program4.ypp" /* yacc.c:1646  */
    {
        // TODO
    }
#line 1966 "y.tab.c" /* yacc.c:1646  */
    break;

  case 70:
#line 288 "program4.ypp" /* yacc.c:1646  */
    {
        // TODO
    }
#line 1974 "y.tab.c" /* yacc.c:1646  */
    break;

  case 71:
#line 291 "program4.ypp" /* yacc.c:1646  */
    {
        // TODO
    }
#line 1982 "y.tab.c" /* yacc.c:1646  */
    break;

  case 72:
#line 294 "program4.ypp" /* yacc.c:1646  */
    {
        // TODO
    }
#line 1990 "y.tab.c" /* yacc.c:1646  */
    break;

  case 73:
#line 297 "program4.ypp" /* yacc.c:1646  */
    {
        // TODO
    }
#line 1998 "y.tab.c" /* yacc.c:1646  */
    break;

  case 74:
#line 300 "program4.ypp" /* yacc.c:1646  */
    {
        // TODO
    }
#line 2006 "y.tab.c" /* yacc.c:1646  */
    break;

  case 75:
#line 306 "program4.ypp" /* yacc.c:1646  */
    {
        // TODO
    }
#line 2014 "y.tab.c" /* yacc.c:1646  */
    break;

  case 76:
#line 309 "program4.ypp" /* yacc.c:1646  */
    {
        // TODO
    }
#line 2022 "y.tab.c" /* yacc.c:1646  */
    break;

  case 77:
#line 315 "program4.ypp" /* yacc.c:1646  */
    {

    }
#line 2030 "y.tab.c" /* yacc.c:1646  */
    break;

  case 78:
#line 318 "program4.ypp" /* yacc.c:1646  */
    {

    }
#line 2038 "y.tab.c" /* yacc.c:1646  */
    break;

  case 79:
#line 324 "program4.ypp" /* yacc.c:1646  */
    {
        // TODO
    }
#line 2046 "y.tab.c" /* yacc.c:1646  */
    break;


#line 2050 "y.tab.c" /* yacc.c:1646  */
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
#line 331 "program4.ypp" /* yacc.c:1906  */

