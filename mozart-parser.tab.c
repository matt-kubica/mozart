
/* A Bison parser, made by GNU Bison 2.4.1.  */

/* Skeleton implementation for Bison's Yacc-like parsers in C
   
      Copyright (C) 1984, 1989, 1990, 2000, 2001, 2002, 2003, 2004, 2005, 2006
   Free Software Foundation, Inc.
   
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
#define YYBISON_VERSION "2.4.1"

/* Skeleton name.  */
#define YYSKELETON_NAME "yacc.c"

/* Pure parsers.  */
#define YYPURE 0

/* Push parsers.  */
#define YYPUSH 0

/* Pull parsers.  */
#define YYPULL 1

/* Using locations.  */
#define YYLSP_NEEDED 0



/* Copy the first part of user declarations.  */

/* Line 189 of yacc.c  */
#line 1 "mozart-parser.y"

#include <stdio.h>
#include <stdlib.h> 
#include <ctype.h>
#include <stdbool.h>
<<<<<<< HEAD
#include "symtab.h"
#include "symtabFunctions.h"
extern int yylex();
char * stringConcat(char * str1, char * str2);
Node* trueVal();
Node* falseVal();
Node* greater(Node* node1, Node* node2);
Node* add(Node* node1, Node* node2);
Node* subtract(Node* node1, Node* node2);
Node* multiply(Node* node1, Node* node2);
Node* divide(Node* node1, Node* node2);
void yyerror(char * s);
int getIntValue(Node* n);
float getFloatValue(Node* n);
bool getBoolValue(Node* n);
char* getStringValue(Node* n);
void typeCheck(Node* n1, char * typeKeyword);
Type getType(Node* n);
void printExpr(Node* n);
=======
#include "utils/symtab.h"
#include "utils/expr.h"
#include "utils/logicexpr.h"

extern int yylex();
>>>>>>> master


/* Line 189 of yacc.c  */
#line 86 "mozart-parser.tab.c"

/* Enabling traces.  */
#ifndef YYDEBUG
# define YYDEBUG 0
#endif

/* Enabling verbose error messages.  */
#ifdef YYERROR_VERBOSE
# undef YYERROR_VERBOSE
# define YYERROR_VERBOSE 1
#else
# define YYERROR_VERBOSE 0
#endif

/* Enabling the token table.  */
#ifndef YYTOKEN_TABLE
# define YYTOKEN_TABLE 0
#endif


/* Tokens.  */
#ifndef YYTOKENTYPE
# define YYTOKENTYPE
   /* Put the tokens into the symbol table, so that GDB and other debuggers
      know about them.  */
   enum yytokentype {
     VAR = 258,
     COLON = 259,
     IF = 260,
     ELSE = 261,
     LOOP = 262,
     STARTOFSCOPE = 263,
     ENDOFSCOPE = 264,
     ASSIGNMENT = 265,
     LPAREN = 266,
     RPAREN = 267,
     ENDOFSTMT = 268,
     PLUS = 269,
     MINUS = 270,
     PER = 271,
     DIV = 272,
     MOD = 273,
     GREATEREQUAL = 274,
     LOWEREQUAL = 275,
     GREATER = 276,
     LOWER = 277,
     NOTEQUAL = 278,
     NOT = 279,
     EQUAL = 280,
     OR = 281,
     AND = 282,
     TRUEVAL = 283,
     FALSEVAL = 284,
     INTKEYWORD = 285,
     FLOATKEYWORD = 286,
     BOOLEANKEYWORD = 287,
     STRINGKEYWORD = 288,
     SCALEKEYWORD = 289,
     FUNCTIONDECL = 290,
     RETURNSTMT = 291,
     EXITSTMT = 292,
     ID = 293,
     INTEGERTYPE = 294,
     FLOATTYPE = 295,
     BOOLEANTYPE = 296,
     STRINGTYPE = 297
   };
#endif



#if ! defined YYSTYPE && ! defined YYSTYPE_IS_DECLARED
typedef union YYSTYPE
{

/* Line 214 of yacc.c  */
#line 59 "mozart-parser.y"

    char* LEXEME;
    struct Node* NODE;
    Value VALUE;



/* Line 214 of yacc.c  */
#line 172 "mozart-parser.tab.c"
} YYSTYPE;
# define YYSTYPE_IS_TRIVIAL 1
# define yystype YYSTYPE /* obsolescent; will be withdrawn */
# define YYSTYPE_IS_DECLARED 1
#endif


/* Copy the second part of user declarations.  */


/* Line 264 of yacc.c  */
#line 184 "mozart-parser.tab.c"

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
#elif (defined __STDC__ || defined __C99__FUNC__ \
     || defined __cplusplus || defined _MSC_VER)
typedef signed char yytype_int8;
#else
typedef short int yytype_int8;
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
# elif ! defined YYSIZE_T && (defined __STDC__ || defined __C99__FUNC__ \
     || defined __cplusplus || defined _MSC_VER)
#  include <stddef.h> /* INFRINGES ON USER NAME SPACE */
#  define YYSIZE_T size_t
# else
#  define YYSIZE_T unsigned int
# endif
#endif

#define YYSIZE_MAXIMUM ((YYSIZE_T) -1)

#ifndef YY_
# if YYENABLE_NLS
#  if ENABLE_NLS
#   include <libintl.h> /* INFRINGES ON USER NAME SPACE */
#   define YY_(msgid) dgettext ("bison-runtime", msgid)
#  endif
# endif
# ifndef YY_
#  define YY_(msgid) msgid
# endif
#endif

/* Suppress unused-variable warnings by "using" E.  */
#if ! defined lint || defined __GNUC__
# define YYUSE(e) ((void) (e))
#else
# define YYUSE(e) /* empty */
#endif

/* Identity function, used to suppress warnings about constant conditions.  */
#ifndef lint
# define YYID(n) (n)
#else
#if (defined __STDC__ || defined __C99__FUNC__ \
     || defined __cplusplus || defined _MSC_VER)
static int
YYID (int yyi)
#else
static int
YYID (yyi)
    int yyi;
#endif
{
  return yyi;
}
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
#    if ! defined _ALLOCA_H && ! defined _STDLIB_H && (defined __STDC__ || defined __C99__FUNC__ \
     || defined __cplusplus || defined _MSC_VER)
#     include <stdlib.h> /* INFRINGES ON USER NAME SPACE */
#     ifndef _STDLIB_H
#      define _STDLIB_H 1
#     endif
#    endif
#   endif
#  endif
# endif

# ifdef YYSTACK_ALLOC
   /* Pacify GCC's `empty if-body' warning.  */
#  define YYSTACK_FREE(Ptr) do { /* empty */; } while (YYID (0))
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
#  if (defined __cplusplus && ! defined _STDLIB_H \
       && ! ((defined YYMALLOC || defined malloc) \
	     && (defined YYFREE || defined free)))
#   include <stdlib.h> /* INFRINGES ON USER NAME SPACE */
#   ifndef _STDLIB_H
#    define _STDLIB_H 1
#   endif
#  endif
#  ifndef YYMALLOC
#   define YYMALLOC malloc
#   if ! defined malloc && ! defined _STDLIB_H && (defined __STDC__ || defined __C99__FUNC__ \
     || defined __cplusplus || defined _MSC_VER)
void *malloc (YYSIZE_T); /* INFRINGES ON USER NAME SPACE */
#   endif
#  endif
#  ifndef YYFREE
#   define YYFREE free
#   if ! defined free && ! defined _STDLIB_H && (defined __STDC__ || defined __C99__FUNC__ \
     || defined __cplusplus || defined _MSC_VER)
void free (void *); /* INFRINGES ON USER NAME SPACE */
#   endif
#  endif
# endif
#endif /* ! defined yyoverflow || YYERROR_VERBOSE */


#if (! defined yyoverflow \
     && (! defined __cplusplus \
	 || (defined YYSTYPE_IS_TRIVIAL && YYSTYPE_IS_TRIVIAL)))

/* A type that is properly aligned for any stack member.  */
union yyalloc
{
  yytype_int16 yyss_alloc;
  YYSTYPE yyvs_alloc;
};

/* The size of the maximum gap between one aligned stack and the next.  */
# define YYSTACK_GAP_MAXIMUM (sizeof (union yyalloc) - 1)

/* The size of an array large to enough to hold all stacks, each with
   N elements.  */
# define YYSTACK_BYTES(N) \
     ((N) * (sizeof (yytype_int16) + sizeof (YYSTYPE)) \
      + YYSTACK_GAP_MAXIMUM)

/* Copy COUNT objects from FROM to TO.  The source and destination do
   not overlap.  */
# ifndef YYCOPY
#  if defined __GNUC__ && 1 < __GNUC__
#   define YYCOPY(To, From, Count) \
      __builtin_memcpy (To, From, (Count) * sizeof (*(From)))
#  else
#   define YYCOPY(To, From, Count)		\
      do					\
	{					\
	  YYSIZE_T yyi;				\
	  for (yyi = 0; yyi < (Count); yyi++)	\
	    (To)[yyi] = (From)[yyi];		\
	}					\
      while (YYID (0))
#  endif
# endif

/* Relocate STACK from its old location to the new one.  The
   local variables YYSIZE and YYSTACKSIZE give the old and new number of
   elements in the stack, and YYPTR gives the new location of the
   stack.  Advance YYPTR to a properly aligned location for the next
   stack.  */
# define YYSTACK_RELOCATE(Stack_alloc, Stack)				\
    do									\
      {									\
	YYSIZE_T yynewbytes;						\
	YYCOPY (&yyptr->Stack_alloc, Stack, yysize);			\
	Stack = &yyptr->Stack_alloc;					\
	yynewbytes = yystacksize * sizeof (*Stack) + YYSTACK_GAP_MAXIMUM; \
	yyptr += yynewbytes / sizeof (*yyptr);				\
      }									\
    while (YYID (0))

#endif

/* YYFINAL -- State number of the termination state.  */
#define YYFINAL  33
/* YYLAST -- Last index in YYTABLE.  */
<<<<<<< HEAD
#define YYLAST   182
=======
#define YYLAST   380
>>>>>>> master

/* YYNTOKENS -- Number of terminals.  */
#define YYNTOKENS  43
/* YYNNTS -- Number of nonterminals.  */
#define YYNNTS  9
/* YYNRULES -- Number of rules.  */
<<<<<<< HEAD
#define YYNRULES  32
/* YYNRULES -- Number of states.  */
#define YYNSTATES  75
=======
#define YYNRULES  48
/* YYNRULES -- Number of states.  */
#define YYNSTATES  119
>>>>>>> master

/* YYTRANSLATE(YYLEX) -- Bison symbol number corresponding to YYLEX.  */
#define YYUNDEFTOK  2
#define YYMAXUTOK   297

#define YYTRANSLATE(YYX)						\
  ((unsigned int) (YYX) <= YYMAXUTOK ? yytranslate[YYX] : YYUNDEFTOK)

/* YYTRANSLATE[YYLEX] -- Bison symbol number corresponding to YYLEX.  */
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
      35,    36,    37,    38,    39,    40,    41,    42
};

#if YYDEBUG
/* YYPRHS[YYN] -- Index of the first RHS symbol of rule number YYN in
   YYRHS.  */
static const yytype_uint8 yyprhs[] =
{
<<<<<<< HEAD
       0,     0,     3,     4,     8,     9,    14,    18,    22,    26,
      29,    36,    43,    50,    57,    67,    75,    83,    90,    92,
      94,    98,   102,   106,   110,   114,   118,   122,   124,   126,
     128,   130,   132
=======
       0,     0,     3,     6,    10,    13,    17,    20,    24,    27,
      31,    34,    38,    41,    45,    48,    52,    59,    66,    73,
      80,    90,    98,   105,   112,   120,   127,   129,   131,   135,
     139,   143,   147,   151,   155,   158,   162,   166,   170,   174,
     178,   182,   186,   190,   192,   194,   196,   198,   200
>>>>>>> master
};

/* YYRHS -- A `-1'-separated list of the rules' RHS.  */
static const yytype_int8 yyrhs[] =
{
<<<<<<< HEAD
      43,     0,    -1,    -1,    43,    49,    13,    -1,    -1,    43,
      48,    13,    44,    -1,    43,    45,    13,    -1,    43,    46,
      13,    -1,    43,    47,    13,    -1,    43,    13,    -1,     3,
      37,     4,    30,    10,    49,    -1,     3,    37,     4,    31,
      10,    49,    -1,     3,    37,     4,    32,    10,    49,    -1,
       3,    37,     4,    33,    10,    49,    -1,     5,    11,    48,
      12,     8,    43,     6,    43,     9,    -1,     5,    11,    48,
      12,     8,    43,     9,    -1,    35,    11,    45,    12,     8,
      43,     9,    -1,    35,    11,    12,     8,    43,     9,    -1,
      28,    -1,    29,    -1,    49,    21,    49,    -1,    49,    14,
      49,    -1,    49,    15,    49,    -1,    49,    16,    49,    -1,
      49,    17,    49,    -1,    49,    18,    49,    -1,    11,    49,
      12,    -1,    50,    -1,    37,    -1,    38,    -1,    39,    -1,
      40,    -1,    41,    -1
=======
      44,     0,    -1,    37,    13,    -1,    44,    37,    13,    -1,
      45,    13,    -1,    44,    45,    13,    -1,    50,    13,    -1,
      44,    50,    13,    -1,    49,    13,    -1,    44,    49,    13,
      -1,    46,    13,    -1,    44,    46,    13,    -1,    47,    13,
      -1,    44,    47,    13,    -1,    48,    13,    -1,    44,    48,
      13,    -1,     3,    38,     4,    30,    10,    50,    -1,     3,
      38,     4,    31,    10,    50,    -1,     3,    38,     4,    32,
      10,    50,    -1,     3,    38,     4,    33,    10,    50,    -1,
       5,    11,    49,    12,     8,    44,     6,    44,     9,    -1,
       5,    11,    49,    12,     8,    44,     9,    -1,    39,    16,
       7,     8,    44,     9,    -1,    38,    16,     7,     8,    44,
       9,    -1,    35,    11,    45,    12,     8,    44,     9,    -1,
      35,    11,    12,     8,    44,     9,    -1,    28,    -1,    29,
      -1,    50,    21,    50,    -1,    50,    19,    50,    -1,    50,
      22,    50,    -1,    50,    20,    50,    -1,    50,    25,    50,
      -1,    50,    23,    50,    -1,    24,    49,    -1,    49,    26,
      49,    -1,    49,    27,    49,    -1,    50,    14,    50,    -1,
      50,    15,    50,    -1,    50,    16,    50,    -1,    50,    17,
      50,    -1,    50,    18,    50,    -1,    11,    50,    12,    -1,
      51,    -1,    38,    -1,    39,    -1,    40,    -1,    41,    -1,
      42,    -1
>>>>>>> master
};

/* YYRLINE[YYN] -- source line where rule number YYN was defined.  */
static const yytype_uint8 yyrline[] =
{
<<<<<<< HEAD
       0,    91,    91,    92,    93,    93,    94,    95,    96,    97,
      99,   100,   101,   102,   106,   107,   109,   110,   113,   114,
     115,   120,   121,   122,   123,   124,   125,   126,   127,   129,
     130,   131,   132
=======
       0,    75,    75,    76,    77,    78,    79,    80,    81,    82,
      83,    84,    85,    86,    87,    88,    92,    96,   100,   104,
     111,   112,   116,   117,   121,   122,   126,   127,   128,   129,
     130,   131,   132,   133,   134,   135,   136,   140,   141,   142,
     143,   144,   145,   146,   147,   151,   152,   153,   154
>>>>>>> master
};
#endif

#if YYDEBUG || YYERROR_VERBOSE || YYTOKEN_TABLE
/* YYTNAME[SYMBOL-NUM] -- String name of the symbol SYMBOL-NUM.
   First, the terminals, then, starting at YYNTOKENS, nonterminals.  */
static const char *const yytname[] =
{
  "$end", "error", "$undefined", "VAR", "COLON", "IF", "ELSE", "LOOP",
  "STARTOFSCOPE", "ENDOFSCOPE", "ASSIGNMENT", "LPAREN", "RPAREN",
  "ENDOFSTMT", "PLUS", "MINUS", "PER", "DIV", "MOD", "GREATEREQUAL",
  "LOWEREQUAL", "GREATER", "LOWER", "NOTEQUAL", "NOT", "EQUAL", "OR",
  "AND", "TRUEVAL", "FALSEVAL", "INTKEYWORD", "FLOATKEYWORD",
  "BOOLEANKEYWORD", "STRINGKEYWORD", "SCALEKEYWORD", "FUNCTIONDECL",
<<<<<<< HEAD
  "RETURNSTMT", "ID", "INTEGERTYPE", "FLOATTYPE", "BOOLEANTYPE",
  "STRINGTYPE", "$accept", "LINE", "$@1", "VARDECL", "IFSTMT", "FUNCTION",
  "LOGICEXPR", "EXPR", "TYPEVAL", 0
=======
  "RETURNSTMT", "EXITSTMT", "ID", "INTEGERTYPE", "FLOATTYPE",
  "BOOLEANTYPE", "STRINGTYPE", "$accept", "LINE", "VARDECL", "IFSTMT",
  "LOOPSTMT", "FUNCTION", "LOGICEXPR", "EXPR", "TYPEVAL", 0
>>>>>>> master
};
#endif

# ifdef YYPRINT
/* YYTOKNUM[YYLEX-NUM] -- Internal token number corresponding to
   token YYLEX-NUM.  */
static const yytype_uint16 yytoknum[] =
{
       0,   256,   257,   258,   259,   260,   261,   262,   263,   264,
     265,   266,   267,   268,   269,   270,   271,   272,   273,   274,
     275,   276,   277,   278,   279,   280,   281,   282,   283,   284,
     285,   286,   287,   288,   289,   290,   291,   292,   293,   294,
     295,   296,   297
};
# endif

/* YYR1[YYN] -- Symbol number of symbol that rule YYN derives.  */
static const yytype_uint8 yyr1[] =
{
<<<<<<< HEAD
       0,    42,    43,    43,    44,    43,    43,    43,    43,    43,
      45,    45,    45,    45,    46,    46,    47,    47,    48,    48,
      48,    49,    49,    49,    49,    49,    49,    49,    49,    50,
      50,    50,    50
=======
       0,    43,    44,    44,    44,    44,    44,    44,    44,    44,
      44,    44,    44,    44,    44,    44,    45,    45,    45,    45,
      46,    46,    47,    47,    48,    48,    49,    49,    49,    49,
      49,    49,    49,    49,    49,    49,    49,    50,    50,    50,
      50,    50,    50,    50,    50,    51,    51,    51,    51
>>>>>>> master
};

/* YYR2[YYN] -- Number of symbols composing right hand side of rule YYN.  */
static const yytype_uint8 yyr2[] =
{
<<<<<<< HEAD
       0,     2,     0,     3,     0,     4,     3,     3,     3,     2,
       6,     6,     6,     6,     9,     7,     7,     6,     1,     1,
       3,     3,     3,     3,     3,     3,     3,     1,     1,     1,
       1,     1,     1
=======
       0,     2,     2,     3,     2,     3,     2,     3,     2,     3,
       2,     3,     2,     3,     2,     3,     6,     6,     6,     6,
       9,     7,     6,     6,     7,     6,     1,     1,     3,     3,
       3,     3,     3,     3,     2,     3,     3,     3,     3,     3,
       3,     3,     3,     1,     1,     1,     1,     1,     1
>>>>>>> master
};

/* YYDEFACT[STATE-NAME] -- Default rule to reduce with in state
   STATE-NUM when YYTABLE doesn't specify something else to do.  Zero
   means the default is an error.  */
static const yytype_uint8 yydefact[] =
{
<<<<<<< HEAD
       2,     0,     1,     0,     0,     0,     9,    18,    19,     0,
      28,    29,    30,    31,    32,     0,     0,     0,     0,     0,
      27,     0,     0,     0,     0,     6,     7,     8,     4,     3,
       0,     0,     0,     0,     0,     0,     0,     0,     0,    26,
       0,     0,     5,    21,    22,    23,    24,    25,    20,     0,
       0,     0,     0,     0,     2,     0,     0,     0,     0,     0,
       2,     0,     2,    10,    11,    12,    13,     0,    17,     0,
       2,    15,    16,     0,    14
=======
       0,     0,     0,     0,     0,    26,    27,     0,     0,    44,
      45,    46,    47,    48,     0,     0,     0,     0,     0,     0,
       0,    43,     0,     0,    44,    45,     0,    34,     0,     0,
       2,     0,     0,     1,     0,     0,     0,     0,     0,     0,
       0,     4,    10,    12,    14,     8,     0,     0,     6,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,    42,     0,     0,     0,     0,     3,     5,    11,
      13,    15,     9,     7,    35,    36,    37,    38,    39,    40,
      41,    29,    31,    28,    30,    33,    32,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,    16,    17,    18,    19,     0,
      25,     0,    23,    22,     0,    21,    24,     0,    20
>>>>>>> master
};

/* YYDEFGOTO[NTERM-NUM].  */
static const yytype_int8 yydefgoto[] =
{
<<<<<<< HEAD
      -1,     1,    42,    15,    16,    17,    18,    19,    20
=======
      -1,    14,    15,    16,    17,    18,    19,    20,    21
>>>>>>> master
};

/* YYPACT[STATE-NUM] -- Index in YYTABLE of the portion describing
   STATE-NUM.  */
<<<<<<< HEAD
#define YYPACT_NINF -51
static const yytype_int16 yypact[] =
{
     -51,     3,   -51,   -36,    -6,    45,   -51,   -51,   -51,    -4,
     -51,   -51,   -51,   -51,   -51,     0,     2,     5,    26,   148,
     -51,    46,     8,   164,    -1,   -51,   -51,   -51,   -51,   -51,
      45,    45,    45,    45,    45,    45,    -9,    -3,   156,   -51,
      51,    48,   -51,    17,    17,   -51,   -51,   -51,    82,    54,
      56,    57,    58,    62,   -51,    64,    45,    45,    45,    45,
     -51,    66,   -51,    82,    82,    82,    82,    52,   -51,   105,
     -51,   -51,   -51,   119,   -51
=======
#define YYPACT_NINF -88
static const yytype_int16 yypact[] =
{
     312,   -34,    -5,    -8,    46,   -88,   -88,     1,    10,     3,
       5,   -88,   -88,   -88,   142,    29,    32,    47,    48,    50,
     342,   -88,    58,    46,   -88,   -88,   134,     2,   140,     6,
     -88,     7,    57,   -88,    59,    60,    67,    68,    69,    52,
     355,   -88,   -88,   -88,   -88,   -88,    46,    46,   -88,    -8,
      -8,    -8,    -8,    -8,    -8,    -8,    -8,    -8,    -8,    -8,
      36,    -2,   -88,    28,    71,    63,    82,   -88,   -88,   -88,
     -88,   -88,   -88,   -88,     2,     2,    22,    22,   -88,   -88,
     -88,   158,   158,   158,   158,   158,   158,    92,    93,    94,
      97,   102,   312,   110,   312,   312,    -8,    -8,    -8,    -8,
     312,   204,   312,   226,   248,   158,   158,   158,   158,   182,
     -88,   270,   -88,   -88,   312,   -88,   -88,   292,   -88
>>>>>>> master
};

/* YYPGOTO[NTERM-NUM].  */
static const yytype_int8 yypgoto[] =
{
<<<<<<< HEAD
     -51,   -50,   -51,    38,   -51,   -51,    80,    -5,   -51
=======
     -88,   -87,   -12,     8,    23,    27,    12,    -3,   -88
>>>>>>> master
};

/* YYTABLE[YYPACT[STATE-NUM]].  What to do in state STATE-NUM.  If
   positive, shift that token.  If negative, reduce the rule which
   number is the opposite.  If zero, do what YYDEFACT says.
   If YYTABLE_NINF, syntax error.  */
#define YYTABLE_NINF -1
static const yytype_uint8 yytable[] =
{
<<<<<<< HEAD
      23,    21,     3,     2,    61,    22,     3,    24,     4,    53,
      67,    40,    69,    25,     5,    26,     6,    38,    27,     5,
      73,    49,    50,    51,    52,    43,    44,    45,    46,    47,
      48,     7,     8,    32,    33,    34,     7,     8,     9,    28,
      10,    11,    12,    13,    14,    10,    11,    12,    13,    14,
      36,    63,    64,    65,    66,     3,     5,     4,    70,    54,
      55,    71,    41,     5,    56,     6,    57,    58,    59,     3,
      60,     4,    62,     0,     0,    68,     0,     5,     0,     6,
       7,     8,    10,    11,    12,    13,    14,     9,     0,    10,
      11,    12,    13,    14,     7,     8,    30,    31,    32,    33,
      34,     9,    37,    10,    11,    12,    13,    14,     3,     0,
       4,     0,     0,     0,    72,     0,     5,     0,     6,     0,
       0,     0,     3,     0,     4,     0,     0,     0,    74,     0,
       5,     0,     6,     7,     8,     0,     0,     0,     0,     0,
       9,     0,    10,    11,    12,    13,    14,     7,     8,     0,
       0,     0,     0,     0,     9,     0,    10,    11,    12,    13,
      14,    29,    30,    31,    32,    33,    34,     0,     0,    35,
      30,    31,    32,    33,    34,     0,    39,    35,    30,    31,
      32,    33,    34
=======
      26,    28,    35,     3,    22,   101,    23,   103,   104,     1,
      91,    40,    29,   109,    65,   111,    27,    64,    63,    31,
      28,    32,    36,    30,    46,    47,    39,   117,    46,    47,
      24,    25,    11,    12,    13,    61,    92,    37,    51,    52,
      53,    38,    41,    28,    28,    42,    76,    77,    78,    79,
      80,    81,    82,    83,    84,    85,    86,     3,    74,    75,
      43,    44,    60,    45,    66,    72,    87,    88,    89,    90,
       4,    94,    67,    68,     5,     6,    46,    47,    46,    47,
      69,    70,    71,    93,    24,    25,    11,    12,    13,    35,
      95,    35,    35,   105,   106,   107,   108,    35,    40,    35,
      40,    40,    96,    97,    98,    35,    40,    99,    40,    36,
     100,    36,    36,    39,    40,    39,    39,    36,   102,    36,
       0,    39,     0,    39,    37,    36,    37,    37,    38,    39,
      38,    38,    37,     0,    37,     0,    38,     0,    38,     0,
      37,     0,    33,     0,    38,     1,    62,     2,    49,    50,
      51,    52,    53,     3,    49,    50,    51,    52,    53,    54,
      55,    56,    57,    58,     0,    59,     4,     0,     0,     0,
       5,     6,    49,    50,    51,    52,    53,     7,     0,    34,
       9,    10,    11,    12,    13,     1,     0,     2,   114,     0,
       0,   115,     0,     3,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     4,     1,     0,     2,
       5,     6,     0,   110,     0,     3,     0,     7,     0,    34,
       9,    10,    11,    12,    13,     0,     0,     0,     4,     1,
       0,     2,     5,     6,     0,   112,     0,     3,     0,     7,
       0,    34,     9,    10,    11,    12,    13,     0,     0,     0,
       4,     1,     0,     2,     5,     6,     0,   113,     0,     3,
       0,     7,     0,    34,     9,    10,    11,    12,    13,     0,
       0,     0,     4,     1,     0,     2,     5,     6,     0,   116,
       0,     3,     0,     7,     0,    34,     9,    10,    11,    12,
      13,     0,     0,     0,     4,     1,     0,     2,     5,     6,
       0,   118,     0,     3,     0,     7,     0,    34,     9,    10,
      11,    12,    13,     0,     0,     1,     4,     2,     0,     0,
       5,     6,     0,     3,     0,     0,     0,     7,     0,    34,
       9,    10,    11,    12,    13,     0,     4,     0,     0,     0,
       5,     6,     0,     0,     0,     0,     0,     7,     0,     8,
       9,    10,    11,    12,    13,    48,    49,    50,    51,    52,
      53,    54,    55,    56,    57,    58,     0,    59,    73,    49,
      50,    51,    52,    53,    54,    55,    56,    57,    58,     0,
      59
>>>>>>> master
};

static const yytype_int8 yycheck[] =
{
<<<<<<< HEAD
       5,    37,     3,     0,    54,    11,     3,    11,     5,    12,
      60,    12,    62,    13,    11,    13,    13,    22,    13,    11,
      70,    30,    31,    32,    33,    30,    31,    32,    33,    34,
      35,    28,    29,    16,    17,    18,    28,    29,    35,    13,
      37,    38,    39,    40,    41,    37,    38,    39,    40,    41,
       4,    56,    57,    58,    59,     3,    11,     5,     6,     8,
      12,     9,    24,    11,    10,    13,    10,    10,    10,     3,
       8,     5,     8,    -1,    -1,     9,    -1,    11,    -1,    13,
      28,    29,    37,    38,    39,    40,    41,    35,    -1,    37,
      38,    39,    40,    41,    28,    29,    14,    15,    16,    17,
      18,    35,    22,    37,    38,    39,    40,    41,     3,    -1,
       5,    -1,    -1,    -1,     9,    -1,    11,    -1,    13,    -1,
      -1,    -1,     3,    -1,     5,    -1,    -1,    -1,     9,    -1,
      11,    -1,    13,    28,    29,    -1,    -1,    -1,    -1,    -1,
      35,    -1,    37,    38,    39,    40,    41,    28,    29,    -1,
      -1,    -1,    -1,    -1,    35,    -1,    37,    38,    39,    40,
      41,    13,    14,    15,    16,    17,    18,    -1,    -1,    21,
      14,    15,    16,    17,    18,    -1,    12,    21,    14,    15,
      16,    17,    18
=======
       3,     4,    14,    11,    38,    92,    11,    94,    95,     3,
      12,    14,    11,   100,     7,   102,     4,    29,    12,    16,
      23,    16,    14,    13,    26,    27,    14,   114,    26,    27,
      38,    39,    40,    41,    42,    23,     8,    14,    16,    17,
      18,    14,    13,    46,    47,    13,    49,    50,    51,    52,
      53,    54,    55,    56,    57,    58,    59,    11,    46,    47,
      13,    13,     4,    13,     7,    13,    30,    31,    32,    33,
      24,     8,    13,    13,    28,    29,    26,    27,    26,    27,
      13,    13,    13,    12,    38,    39,    40,    41,    42,   101,
       8,   103,   104,    96,    97,    98,    99,   109,   101,   111,
     103,   104,    10,    10,    10,   117,   109,    10,   111,   101,
       8,   103,   104,   101,   117,   103,   104,   109,     8,   111,
      -1,   109,    -1,   111,   101,   117,   103,   104,   101,   117,
     103,   104,   109,    -1,   111,    -1,   109,    -1,   111,    -1,
     117,    -1,     0,    -1,   117,     3,    12,     5,    14,    15,
      16,    17,    18,    11,    14,    15,    16,    17,    18,    19,
      20,    21,    22,    23,    -1,    25,    24,    -1,    -1,    -1,
      28,    29,    14,    15,    16,    17,    18,    35,    -1,    37,
      38,    39,    40,    41,    42,     3,    -1,     5,     6,    -1,
      -1,     9,    -1,    11,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    24,     3,    -1,     5,
      28,    29,    -1,     9,    -1,    11,    -1,    35,    -1,    37,
      38,    39,    40,    41,    42,    -1,    -1,    -1,    24,     3,
      -1,     5,    28,    29,    -1,     9,    -1,    11,    -1,    35,
      -1,    37,    38,    39,    40,    41,    42,    -1,    -1,    -1,
      24,     3,    -1,     5,    28,    29,    -1,     9,    -1,    11,
      -1,    35,    -1,    37,    38,    39,    40,    41,    42,    -1,
      -1,    -1,    24,     3,    -1,     5,    28,    29,    -1,     9,
      -1,    11,    -1,    35,    -1,    37,    38,    39,    40,    41,
      42,    -1,    -1,    -1,    24,     3,    -1,     5,    28,    29,
      -1,     9,    -1,    11,    -1,    35,    -1,    37,    38,    39,
      40,    41,    42,    -1,    -1,     3,    24,     5,    -1,    -1,
      28,    29,    -1,    11,    -1,    -1,    -1,    35,    -1,    37,
      38,    39,    40,    41,    42,    -1,    24,    -1,    -1,    -1,
      28,    29,    -1,    -1,    -1,    -1,    -1,    35,    -1,    37,
      38,    39,    40,    41,    42,    13,    14,    15,    16,    17,
      18,    19,    20,    21,    22,    23,    -1,    25,    13,    14,
      15,    16,    17,    18,    19,    20,    21,    22,    23,    -1,
      25
>>>>>>> master
};

/* YYSTOS[STATE-NUM] -- The (internal number of the) accessing
   symbol of state STATE-NUM.  */
static const yytype_uint8 yystos[] =
{
<<<<<<< HEAD
       0,    43,     0,     3,     5,    11,    13,    28,    29,    35,
      37,    38,    39,    40,    41,    45,    46,    47,    48,    49,
      50,    37,    11,    49,    11,    13,    13,    13,    13,    13,
      14,    15,    16,    17,    18,    21,     4,    48,    49,    12,
      12,    45,    44,    49,    49,    49,    49,    49,    49,    30,
      31,    32,    33,    12,     8,    12,    10,    10,    10,    10,
       8,    43,     8,    49,    49,    49,    49,    43,     9,    43,
       6,     9,     9,    43,     9
=======
       0,     3,     5,    11,    24,    28,    29,    35,    37,    38,
      39,    40,    41,    42,    44,    45,    46,    47,    48,    49,
      50,    51,    38,    11,    38,    39,    50,    49,    50,    11,
      13,    16,    16,     0,    37,    45,    46,    47,    48,    49,
      50,    13,    13,    13,    13,    13,    26,    27,    13,    14,
      15,    16,    17,    18,    19,    20,    21,    22,    23,    25,
       4,    49,    12,    12,    45,     7,     7,    13,    13,    13,
      13,    13,    13,    13,    49,    49,    50,    50,    50,    50,
      50,    50,    50,    50,    50,    50,    50,    30,    31,    32,
      33,    12,     8,    12,     8,     8,    10,    10,    10,    10,
       8,    44,     8,    44,    44,    50,    50,    50,    50,    44,
       9,    44,     9,     9,     6,     9,     9,    44,     9
>>>>>>> master
};

#define yyerrok		(yyerrstatus = 0)
#define yyclearin	(yychar = YYEMPTY)
#define YYEMPTY		(-2)
#define YYEOF		0

#define YYACCEPT	goto yyacceptlab
#define YYABORT		goto yyabortlab
#define YYERROR		goto yyerrorlab


/* Like YYERROR except do call yyerror.  This remains here temporarily
   to ease the transition to the new meaning of YYERROR, for GCC.
   Once GCC version 2 has supplanted version 1, this can go.  */

#define YYFAIL		goto yyerrlab

#define YYRECOVERING()  (!!yyerrstatus)

#define YYBACKUP(Token, Value)					\
do								\
  if (yychar == YYEMPTY && yylen == 1)				\
    {								\
      yychar = (Token);						\
      yylval = (Value);						\
      yytoken = YYTRANSLATE (yychar);				\
      YYPOPSTACK (1);						\
      goto yybackup;						\
    }								\
  else								\
    {								\
      yyerror (YY_("syntax error: cannot back up")); \
      YYERROR;							\
    }								\
while (YYID (0))


#define YYTERROR	1
#define YYERRCODE	256


/* YYLLOC_DEFAULT -- Set CURRENT to span from RHS[1] to RHS[N].
   If N is 0, then set CURRENT to the empty location which ends
   the previous symbol: RHS[0] (always defined).  */

#define YYRHSLOC(Rhs, K) ((Rhs)[K])
#ifndef YYLLOC_DEFAULT
# define YYLLOC_DEFAULT(Current, Rhs, N)				\
    do									\
      if (YYID (N))                                                    \
	{								\
	  (Current).first_line   = YYRHSLOC (Rhs, 1).first_line;	\
	  (Current).first_column = YYRHSLOC (Rhs, 1).first_column;	\
	  (Current).last_line    = YYRHSLOC (Rhs, N).last_line;		\
	  (Current).last_column  = YYRHSLOC (Rhs, N).last_column;	\
	}								\
      else								\
	{								\
	  (Current).first_line   = (Current).last_line   =		\
	    YYRHSLOC (Rhs, 0).last_line;				\
	  (Current).first_column = (Current).last_column =		\
	    YYRHSLOC (Rhs, 0).last_column;				\
	}								\
    while (YYID (0))
#endif


/* YY_LOCATION_PRINT -- Print the location on the stream.
   This macro was not mandated originally: define only if we know
   we won't break user code: when these are the locations we know.  */

#ifndef YY_LOCATION_PRINT
# if YYLTYPE_IS_TRIVIAL
#  define YY_LOCATION_PRINT(File, Loc)			\
     fprintf (File, "%d.%d-%d.%d",			\
	      (Loc).first_line, (Loc).first_column,	\
	      (Loc).last_line,  (Loc).last_column)
# else
#  define YY_LOCATION_PRINT(File, Loc) ((void) 0)
# endif
#endif


/* YYLEX -- calling `yylex' with the right arguments.  */

#ifdef YYLEX_PARAM
# define YYLEX yylex (YYLEX_PARAM)
#else
# define YYLEX yylex ()
#endif

/* Enable debugging if requested.  */
#if YYDEBUG

# ifndef YYFPRINTF
#  include <stdio.h> /* INFRINGES ON USER NAME SPACE */
#  define YYFPRINTF fprintf
# endif

# define YYDPRINTF(Args)			\
do {						\
  if (yydebug)					\
    YYFPRINTF Args;				\
} while (YYID (0))

# define YY_SYMBOL_PRINT(Title, Type, Value, Location)			  \
do {									  \
  if (yydebug)								  \
    {									  \
      YYFPRINTF (stderr, "%s ", Title);					  \
      yy_symbol_print (stderr,						  \
		  Type, Value); \
      YYFPRINTF (stderr, "\n");						  \
    }									  \
} while (YYID (0))


/*--------------------------------.
| Print this symbol on YYOUTPUT.  |
`--------------------------------*/

/*ARGSUSED*/
#if (defined __STDC__ || defined __C99__FUNC__ \
     || defined __cplusplus || defined _MSC_VER)
static void
yy_symbol_value_print (FILE *yyoutput, int yytype, YYSTYPE const * const yyvaluep)
#else
static void
yy_symbol_value_print (yyoutput, yytype, yyvaluep)
    FILE *yyoutput;
    int yytype;
    YYSTYPE const * const yyvaluep;
#endif
{
  if (!yyvaluep)
    return;
# ifdef YYPRINT
  if (yytype < YYNTOKENS)
    YYPRINT (yyoutput, yytoknum[yytype], *yyvaluep);
# else
  YYUSE (yyoutput);
# endif
  switch (yytype)
    {
      default:
	break;
    }
}


/*--------------------------------.
| Print this symbol on YYOUTPUT.  |
`--------------------------------*/

#if (defined __STDC__ || defined __C99__FUNC__ \
     || defined __cplusplus || defined _MSC_VER)
static void
yy_symbol_print (FILE *yyoutput, int yytype, YYSTYPE const * const yyvaluep)
#else
static void
yy_symbol_print (yyoutput, yytype, yyvaluep)
    FILE *yyoutput;
    int yytype;
    YYSTYPE const * const yyvaluep;
#endif
{
  if (yytype < YYNTOKENS)
    YYFPRINTF (yyoutput, "token %s (", yytname[yytype]);
  else
    YYFPRINTF (yyoutput, "nterm %s (", yytname[yytype]);

  yy_symbol_value_print (yyoutput, yytype, yyvaluep);
  YYFPRINTF (yyoutput, ")");
}

/*------------------------------------------------------------------.
| yy_stack_print -- Print the state stack from its BOTTOM up to its |
| TOP (included).                                                   |
`------------------------------------------------------------------*/

#if (defined __STDC__ || defined __C99__FUNC__ \
     || defined __cplusplus || defined _MSC_VER)
static void
yy_stack_print (yytype_int16 *yybottom, yytype_int16 *yytop)
#else
static void
yy_stack_print (yybottom, yytop)
    yytype_int16 *yybottom;
    yytype_int16 *yytop;
#endif
{
  YYFPRINTF (stderr, "Stack now");
  for (; yybottom <= yytop; yybottom++)
    {
      int yybot = *yybottom;
      YYFPRINTF (stderr, " %d", yybot);
    }
  YYFPRINTF (stderr, "\n");
}

# define YY_STACK_PRINT(Bottom, Top)				\
do {								\
  if (yydebug)							\
    yy_stack_print ((Bottom), (Top));				\
} while (YYID (0))


/*------------------------------------------------.
| Report that the YYRULE is going to be reduced.  |
`------------------------------------------------*/

#if (defined __STDC__ || defined __C99__FUNC__ \
     || defined __cplusplus || defined _MSC_VER)
static void
yy_reduce_print (YYSTYPE *yyvsp, int yyrule)
#else
static void
yy_reduce_print (yyvsp, yyrule)
    YYSTYPE *yyvsp;
    int yyrule;
#endif
{
  int yynrhs = yyr2[yyrule];
  int yyi;
  unsigned long int yylno = yyrline[yyrule];
  YYFPRINTF (stderr, "Reducing stack by rule %d (line %lu):\n",
	     yyrule - 1, yylno);
  /* The symbols being reduced.  */
  for (yyi = 0; yyi < yynrhs; yyi++)
    {
      YYFPRINTF (stderr, "   $%d = ", yyi + 1);
      yy_symbol_print (stderr, yyrhs[yyprhs[yyrule] + yyi],
		       &(yyvsp[(yyi + 1) - (yynrhs)])
		       		       );
      YYFPRINTF (stderr, "\n");
    }
}

# define YY_REDUCE_PRINT(Rule)		\
do {					\
  if (yydebug)				\
    yy_reduce_print (yyvsp, Rule); \
} while (YYID (0))

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
#ifndef	YYINITDEPTH
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
#if (defined __STDC__ || defined __C99__FUNC__ \
     || defined __cplusplus || defined _MSC_VER)
static YYSIZE_T
yystrlen (const char *yystr)
#else
static YYSIZE_T
yystrlen (yystr)
    const char *yystr;
#endif
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
#if (defined __STDC__ || defined __C99__FUNC__ \
     || defined __cplusplus || defined _MSC_VER)
static char *
yystpcpy (char *yydest, const char *yysrc)
#else
static char *
yystpcpy (yydest, yysrc)
    char *yydest;
    const char *yysrc;
#endif
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

/* Copy into YYRESULT an error message about the unexpected token
   YYCHAR while in state YYSTATE.  Return the number of bytes copied,
   including the terminating null byte.  If YYRESULT is null, do not
   copy anything; just return the number of bytes that would be
   copied.  As a special case, return 0 if an ordinary "syntax error"
   message will do.  Return YYSIZE_MAXIMUM if overflow occurs during
   size calculation.  */
static YYSIZE_T
yysyntax_error (char *yyresult, int yystate, int yychar)
{
  int yyn = yypact[yystate];

  if (! (YYPACT_NINF < yyn && yyn <= YYLAST))
    return 0;
  else
    {
      int yytype = YYTRANSLATE (yychar);
      YYSIZE_T yysize0 = yytnamerr (0, yytname[yytype]);
      YYSIZE_T yysize = yysize0;
      YYSIZE_T yysize1;
      int yysize_overflow = 0;
      enum { YYERROR_VERBOSE_ARGS_MAXIMUM = 5 };
      char const *yyarg[YYERROR_VERBOSE_ARGS_MAXIMUM];
      int yyx;

# if 0
      /* This is so xgettext sees the translatable formats that are
	 constructed on the fly.  */
      YY_("syntax error, unexpected %s");
      YY_("syntax error, unexpected %s, expecting %s");
      YY_("syntax error, unexpected %s, expecting %s or %s");
      YY_("syntax error, unexpected %s, expecting %s or %s or %s");
      YY_("syntax error, unexpected %s, expecting %s or %s or %s or %s");
# endif
      char *yyfmt;
      char const *yyf;
      static char const yyunexpected[] = "syntax error, unexpected %s";
      static char const yyexpecting[] = ", expecting %s";
      static char const yyor[] = " or %s";
      char yyformat[sizeof yyunexpected
		    + sizeof yyexpecting - 1
		    + ((YYERROR_VERBOSE_ARGS_MAXIMUM - 2)
		       * (sizeof yyor - 1))];
      char const *yyprefix = yyexpecting;

      /* Start YYX at -YYN if negative to avoid negative indexes in
	 YYCHECK.  */
      int yyxbegin = yyn < 0 ? -yyn : 0;

      /* Stay within bounds of both yycheck and yytname.  */
      int yychecklim = YYLAST - yyn + 1;
      int yyxend = yychecklim < YYNTOKENS ? yychecklim : YYNTOKENS;
      int yycount = 1;

      yyarg[0] = yytname[yytype];
      yyfmt = yystpcpy (yyformat, yyunexpected);

      for (yyx = yyxbegin; yyx < yyxend; ++yyx)
	if (yycheck[yyx + yyn] == yyx && yyx != YYTERROR)
	  {
	    if (yycount == YYERROR_VERBOSE_ARGS_MAXIMUM)
	      {
		yycount = 1;
		yysize = yysize0;
		yyformat[sizeof yyunexpected - 1] = '\0';
		break;
	      }
	    yyarg[yycount++] = yytname[yyx];
	    yysize1 = yysize + yytnamerr (0, yytname[yyx]);
	    yysize_overflow |= (yysize1 < yysize);
	    yysize = yysize1;
	    yyfmt = yystpcpy (yyfmt, yyprefix);
	    yyprefix = yyor;
	  }

      yyf = YY_(yyformat);
      yysize1 = yysize + yystrlen (yyf);
      yysize_overflow |= (yysize1 < yysize);
      yysize = yysize1;

      if (yysize_overflow)
	return YYSIZE_MAXIMUM;

      if (yyresult)
	{
	  /* Avoid sprintf, as that infringes on the user's name space.
	     Don't have undefined behavior even if the translation
	     produced a string with the wrong number of "%s"s.  */
	  char *yyp = yyresult;
	  int yyi = 0;
	  while ((*yyp = *yyf) != '\0')
	    {
	      if (*yyp == '%' && yyf[1] == 's' && yyi < yycount)
		{
		  yyp += yytnamerr (yyp, yyarg[yyi++]);
		  yyf += 2;
		}
	      else
		{
		  yyp++;
		  yyf++;
		}
	    }
	}
      return yysize;
    }
}
#endif /* YYERROR_VERBOSE */


/*-----------------------------------------------.
| Release the memory associated to this symbol.  |
`-----------------------------------------------*/

/*ARGSUSED*/
#if (defined __STDC__ || defined __C99__FUNC__ \
     || defined __cplusplus || defined _MSC_VER)
static void
yydestruct (const char *yymsg, int yytype, YYSTYPE *yyvaluep)
#else
static void
yydestruct (yymsg, yytype, yyvaluep)
    const char *yymsg;
    int yytype;
    YYSTYPE *yyvaluep;
#endif
{
  YYUSE (yyvaluep);

  if (!yymsg)
    yymsg = "Deleting";
  YY_SYMBOL_PRINT (yymsg, yytype, yyvaluep, yylocationp);

  switch (yytype)
    {

      default:
	break;
    }
}

/* Prevent warnings from -Wmissing-prototypes.  */
#ifdef YYPARSE_PARAM
#if defined __STDC__ || defined __cplusplus
int yyparse (void *YYPARSE_PARAM);
#else
int yyparse ();
#endif
#else /* ! YYPARSE_PARAM */
#if defined __STDC__ || defined __cplusplus
int yyparse (void);
#else
int yyparse ();
#endif
#endif /* ! YYPARSE_PARAM */


/* The lookahead symbol.  */
int yychar;

/* The semantic value of the lookahead symbol.  */
YYSTYPE yylval;

/* Number of syntax errors so far.  */
int yynerrs;



/*-------------------------.
| yyparse or yypush_parse.  |
`-------------------------*/

#ifdef YYPARSE_PARAM
#if (defined __STDC__ || defined __C99__FUNC__ \
     || defined __cplusplus || defined _MSC_VER)
int
yyparse (void *YYPARSE_PARAM)
#else
int
yyparse (YYPARSE_PARAM)
    void *YYPARSE_PARAM;
#endif
#else /* ! YYPARSE_PARAM */
#if (defined __STDC__ || defined __C99__FUNC__ \
     || defined __cplusplus || defined _MSC_VER)
int
yyparse (void)
#else
int
yyparse ()

#endif
#endif
{


    int yystate;
    /* Number of tokens to shift before error messages enabled.  */
    int yyerrstatus;

    /* The stacks and their tools:
       `yyss': related to states.
       `yyvs': related to semantic values.

       Refer to the stacks thru separate pointers, to allow yyoverflow
       to reallocate them elsewhere.  */

    /* The state stack.  */
    yytype_int16 yyssa[YYINITDEPTH];
    yytype_int16 *yyss;
    yytype_int16 *yyssp;

    /* The semantic value stack.  */
    YYSTYPE yyvsa[YYINITDEPTH];
    YYSTYPE *yyvs;
    YYSTYPE *yyvsp;

    YYSIZE_T yystacksize;

  int yyn;
  int yyresult;
  /* Lookahead token as an internal (translated) token number.  */
  int yytoken;
  /* The variables used to return semantic value and location from the
     action routines.  */
  YYSTYPE yyval;

#if YYERROR_VERBOSE
  /* Buffer for error messages, and its allocated size.  */
  char yymsgbuf[128];
  char *yymsg = yymsgbuf;
  YYSIZE_T yymsg_alloc = sizeof yymsgbuf;
#endif

#define YYPOPSTACK(N)   (yyvsp -= (N), yyssp -= (N))

  /* The number of symbols on the RHS of the reduced rule.
     Keep to zero when no symbol should be popped.  */
  int yylen = 0;

  yytoken = 0;
  yyss = yyssa;
  yyvs = yyvsa;
  yystacksize = YYINITDEPTH;

  YYDPRINTF ((stderr, "Starting parse\n"));

  yystate = 0;
  yyerrstatus = 0;
  yynerrs = 0;
  yychar = YYEMPTY; /* Cause a token to be read.  */

  /* Initialize stack pointers.
     Waste one element of value and location stack
     so that they stay on the same level as the state stack.
     The wasted elements are never initialized.  */
  yyssp = yyss;
  yyvsp = yyvs;

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

	/* Each stack pointer address is followed by the size of the
	   data in use in that stack, in bytes.  This used to be a
	   conditional around just the two extra args, but that might
	   be undefined if yyoverflow is a macro.  */
	yyoverflow (YY_("memory exhausted"),
		    &yyss1, yysize * sizeof (*yyssp),
		    &yyvs1, yysize * sizeof (*yyvsp),
		    &yystacksize);

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
#  undef YYSTACK_RELOCATE
	if (yyss1 != yyssa)
	  YYSTACK_FREE (yyss1);
      }
# endif
#endif /* no yyoverflow */

      yyssp = yyss + yysize - 1;
      yyvsp = yyvs + yysize - 1;

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
  if (yyn == YYPACT_NINF)
    goto yydefault;

  /* Not known => get a lookahead token if don't already have one.  */

  /* YYCHAR is either YYEMPTY or YYEOF or a valid lookahead symbol.  */
  if (yychar == YYEMPTY)
    {
      YYDPRINTF ((stderr, "Reading a token: "));
      yychar = YYLEX;
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
      if (yyn == 0 || yyn == YYTABLE_NINF)
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
  *++yyvsp = yylval;

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
     `$$ = $1'.

     Otherwise, the following line sets YYVAL to garbage.
     This behavior is undocumented and Bison
     users should not rely upon it.  Assigning to YYVAL
     unconditionally makes the parser a bit smaller, and it avoids a
     GCC warning that YYVAL may be used uninitialized.  */
  yyval = yyvsp[1-yylen];


  YY_REDUCE_PRINT (yyn);
  switch (yyn)
    {
        case 2:

/* Line 1455 of yacc.c  */
<<<<<<< HEAD
#line 92 "mozart-parser.y"
    { printExpr((yyvsp[(2) - (3)].NODE));;}
=======
#line 75 "mozart-parser.y"
    { exit(EXIT_SUCCESS); ;}
    break;

  case 3:

/* Line 1455 of yacc.c  */
#line 76 "mozart-parser.y"
    { exit(EXIT_SUCCESS); ;}
>>>>>>> master
    break;

  case 4:

/* Line 1455 of yacc.c  */
<<<<<<< HEAD
#line 93 "mozart-parser.y"
    {;;}
=======
#line 77 "mozart-parser.y"
    { ; ;}
>>>>>>> master
    break;

  case 5:

/* Line 1455 of yacc.c  */
<<<<<<< HEAD
#line 93 "mozart-parser.y"
    { printExpr((yyvsp[(2) - (4)].NODE));;}
=======
#line 78 "mozart-parser.y"
    { ; ;}
>>>>>>> master
    break;

  case 6:

/* Line 1455 of yacc.c  */
<<<<<<< HEAD
#line 94 "mozart-parser.y"
    { printTable() ;;}
=======
#line 79 "mozart-parser.y"
    { printNode((yyvsp[(1) - (2)].NODE)); ;}
>>>>>>> master
    break;

  case 7:

/* Line 1455 of yacc.c  */
<<<<<<< HEAD
#line 95 "mozart-parser.y"
    {;;}
=======
#line 80 "mozart-parser.y"
    { printNode((yyvsp[(2) - (3)].NODE)); ;}
>>>>>>> master
    break;

  case 8:

/* Line 1455 of yacc.c  */
<<<<<<< HEAD
#line 96 "mozart-parser.y"
    {;;}
=======
#line 81 "mozart-parser.y"
    { printNode((yyvsp[(1) - (2)].NODE)); ;}
    break;

  case 9:

/* Line 1455 of yacc.c  */
#line 82 "mozart-parser.y"
    { printNode((yyvsp[(2) - (3)].NODE)); ;}
>>>>>>> master
    break;

  case 10:

/* Line 1455 of yacc.c  */
<<<<<<< HEAD
#line 99 "mozart-parser.y"
    { typeCheck((yyvsp[(6) - (6)].NODE), "integer"); insert(construct((yyvsp[(2) - (6)].LEXEME), (yyvsp[(6) - (6)].NODE)));;}
=======
#line 83 "mozart-parser.y"
    { ; ;}
>>>>>>> master
    break;

  case 11:

/* Line 1455 of yacc.c  */
<<<<<<< HEAD
#line 100 "mozart-parser.y"
    { typeCheck((yyvsp[(6) - (6)].NODE), "float"); insert(construct((yyvsp[(2) - (6)].LEXEME), (yyvsp[(6) - (6)].NODE))) ;;}
=======
#line 84 "mozart-parser.y"
    { ; ;}
>>>>>>> master
    break;

  case 12:

/* Line 1455 of yacc.c  */
<<<<<<< HEAD
#line 101 "mozart-parser.y"
    { typeCheck((yyvsp[(6) - (6)].NODE), "boolean"); insert(construct((yyvsp[(2) - (6)].LEXEME), (yyvsp[(6) - (6)].NODE))); ;}
=======
#line 85 "mozart-parser.y"
    { ; ;}
>>>>>>> master
    break;

  case 13:

/* Line 1455 of yacc.c  */
<<<<<<< HEAD
#line 102 "mozart-parser.y"
    { typeCheck((yyvsp[(6) - (6)].NODE), "string"); insert(construct((yyvsp[(2) - (6)].LEXEME), (yyvsp[(6) - (6)].NODE))); ;}
=======
#line 86 "mozart-parser.y"
    { ; ;}
>>>>>>> master
    break;

  case 14:

/* Line 1455 of yacc.c  */
<<<<<<< HEAD
#line 106 "mozart-parser.y"
    {;;}
=======
#line 87 "mozart-parser.y"
    { ; ;}
>>>>>>> master
    break;

  case 15:

/* Line 1455 of yacc.c  */
<<<<<<< HEAD
#line 107 "mozart-parser.y"
    {;;}
=======
#line 88 "mozart-parser.y"
    { ; ;}
>>>>>>> master
    break;

  case 16:

/* Line 1455 of yacc.c  */
<<<<<<< HEAD
#line 109 "mozart-parser.y"
    {/*should all be stored in symbolTable and be made accessible to the rest of the program to execute*/;;}
=======
#line 92 "mozart-parser.y"
    {   
                                                                typeCheck((yyvsp[(6) - (6)].NODE), INTEGER);
                                                                insert(construct((yyvsp[(2) - (6)].LEXEME), (yyvsp[(6) - (6)].NODE)));
                                                            ;}
>>>>>>> master
    break;

  case 17:

/* Line 1455 of yacc.c  */
<<<<<<< HEAD
#line 110 "mozart-parser.y"
    {;;}
=======
#line 96 "mozart-parser.y"
    { 
                                                                typeCheck((yyvsp[(6) - (6)].NODE), FLOAT);
                                                                insert(construct((yyvsp[(2) - (6)].LEXEME), (yyvsp[(6) - (6)].NODE)));
                                                            ;}
>>>>>>> master
    break;

  case 18:

/* Line 1455 of yacc.c  */
<<<<<<< HEAD
#line 113 "mozart-parser.y"
    { (yyval.NODE) = trueVal(); ;}
=======
#line 100 "mozart-parser.y"
    { 
                                                                typeCheck((yyvsp[(6) - (6)].NODE), BOOLEAN);
                                                                insert(construct((yyvsp[(2) - (6)].LEXEME), (yyvsp[(6) - (6)].NODE))); 
                                                            ;}
>>>>>>> master
    break;

  case 19:

/* Line 1455 of yacc.c  */
<<<<<<< HEAD
#line 114 "mozart-parser.y"
    { (yyval.NODE) = falseVal(); ;}
=======
#line 104 "mozart-parser.y"
    { 
                                                                typeCheck((yyvsp[(6) - (6)].NODE), STRING);
                                                                insert(construct((yyvsp[(2) - (6)].LEXEME), (yyvsp[(6) - (6)].NODE))); 
                                                            ;}
>>>>>>> master
    break;

  case 20:

/* Line 1455 of yacc.c  */
<<<<<<< HEAD
#line 115 "mozart-parser.y"
    { (yyval.NODE) = greater((yyvsp[(1) - (3)].NODE), (yyvsp[(3) - (3)].NODE)); ;}
=======
#line 111 "mozart-parser.y"
    { ; ;}
>>>>>>> master
    break;

  case 21:

/* Line 1455 of yacc.c  */
<<<<<<< HEAD
#line 120 "mozart-parser.y"
    { (yyval.NODE) = construct(NULL, add((yyvsp[(1) - (3)].NODE), (yyvsp[(3) - (3)].NODE))); ;}
=======
#line 112 "mozart-parser.y"
    { ; ;}
>>>>>>> master
    break;

  case 22:

/* Line 1455 of yacc.c  */
<<<<<<< HEAD
#line 121 "mozart-parser.y"
    { ; ;}
=======
#line 116 "mozart-parser.y"
    { /*insert number of times loop get executed into symbolTable */ ;}
>>>>>>> master
    break;

  case 23:

/* Line 1455 of yacc.c  */
<<<<<<< HEAD
#line 122 "mozart-parser.y"
=======
#line 117 "mozart-parser.y"
>>>>>>> master
    { ; ;}
    break;

  case 24:

/* Line 1455 of yacc.c  */
<<<<<<< HEAD
#line 123 "mozart-parser.y"
=======
#line 121 "mozart-parser.y"
>>>>>>> master
    { ; ;}
    break;

  case 25:

/* Line 1455 of yacc.c  */
<<<<<<< HEAD
#line 124 "mozart-parser.y"
=======
#line 122 "mozart-parser.y"
>>>>>>> master
    { ; ;}
    break;

  case 26:

/* Line 1455 of yacc.c  */
<<<<<<< HEAD
#line 125 "mozart-parser.y"
    { ; ;}
=======
#line 126 "mozart-parser.y"
    { (yyval.NODE) = trueVal(); ;}
>>>>>>> master
    break;

  case 27:

/* Line 1455 of yacc.c  */
<<<<<<< HEAD
#line 126 "mozart-parser.y"
    {(yyval.NODE) = (yyvsp[(1) - (1)].NODE);;}
=======
#line 127 "mozart-parser.y"
    { (yyval.NODE) = falseVal(); ;}
>>>>>>> master
    break;

  case 28:

/* Line 1455 of yacc.c  */
<<<<<<< HEAD
#line 127 "mozart-parser.y"
    {;;}
=======
#line 128 "mozart-parser.y"
    { (yyval.NODE) = greater((yyvsp[(1) - (3)].NODE), (yyvsp[(3) - (3)].NODE)); ;}
>>>>>>> master
    break;

  case 29:

/* Line 1455 of yacc.c  */
#line 129 "mozart-parser.y"
<<<<<<< HEAD
    {(yyval.NODE) = construct(NULL, (yyvsp[(1) - (1)].NODE));;}
=======
    { ; ;}
>>>>>>> master
    break;

  case 30:

/* Line 1455 of yacc.c  */
#line 130 "mozart-parser.y"
<<<<<<< HEAD
    {(yyval.NODE) = construct(NULL, (yyvsp[(1) - (1)].NODE));;}
=======
    { ; ;}
>>>>>>> master
    break;

  case 31:

/* Line 1455 of yacc.c  */
#line 131 "mozart-parser.y"
<<<<<<< HEAD
    {(yyval.NODE) = construct(NULL, (yyvsp[(1) - (1)].NODE));;}
=======
    { ; ;}
>>>>>>> master
    break;

  case 32:

/* Line 1455 of yacc.c  */
#line 132 "mozart-parser.y"
<<<<<<< HEAD
    {(yyval.NODE) = construct(NULL, (yyvsp[(1) - (1)].NODE));;}
=======
    { ; ;}
>>>>>>> master
    break;

  case 33:

/* Line 1455 of yacc.c  */
#line 133 "mozart-parser.y"
    { ; ;}
    break;

  case 34:

/* Line 1455 of yacc.c  */
<<<<<<< HEAD
#line 1674 "mozart-parser.tab.c"
=======
#line 134 "mozart-parser.y"
    { ; ;}
    break;

  case 35:

/* Line 1455 of yacc.c  */
#line 135 "mozart-parser.y"
    { ; ;}
    break;

  case 36:

/* Line 1455 of yacc.c  */
#line 136 "mozart-parser.y"
    { ; ;}
    break;

  case 37:

/* Line 1455 of yacc.c  */
#line 140 "mozart-parser.y"
    { (yyval.NODE) = add((yyvsp[(1) - (3)].NODE), (yyvsp[(3) - (3)].NODE)); ;}
    break;

  case 38:

/* Line 1455 of yacc.c  */
#line 141 "mozart-parser.y"
    { ; ;}
    break;

  case 39:

/* Line 1455 of yacc.c  */
#line 142 "mozart-parser.y"
    { ; ;}
    break;

  case 40:

/* Line 1455 of yacc.c  */
#line 143 "mozart-parser.y"
    { ; ;}
    break;

  case 41:

/* Line 1455 of yacc.c  */
#line 144 "mozart-parser.y"
    { ; ;}
    break;

  case 42:

/* Line 1455 of yacc.c  */
#line 145 "mozart-parser.y"
    { ; ;}
    break;

  case 43:

/* Line 1455 of yacc.c  */
#line 146 "mozart-parser.y"
    { (yyval.NODE) = (yyvsp[(1) - (1)].NODE); ;}
    break;

  case 44:

/* Line 1455 of yacc.c  */
#line 147 "mozart-parser.y"
    { (yyval.NODE) = getNode((yyvsp[(1) - (1)].LEXEME)); ;}
    break;

  case 45:

/* Line 1455 of yacc.c  */
#line 151 "mozart-parser.y"
    { (yyval.NODE) = constructInteger(NULL, (yyvsp[(1) - (1)].VALUE).i); /* TODO: memory dealocation */ ;}
    break;

  case 46:

/* Line 1455 of yacc.c  */
#line 152 "mozart-parser.y"
    { (yyval.NODE) = constructFloat(NULL, (yyvsp[(1) - (1)].VALUE).f); ;}
    break;

  case 47:

/* Line 1455 of yacc.c  */
#line 153 "mozart-parser.y"
    { (yyval.NODE) = constructBoolean(NULL, (yyvsp[(1) - (1)].VALUE).b); ;}
    break;

  case 48:

/* Line 1455 of yacc.c  */
#line 154 "mozart-parser.y"
    { (yyval.NODE) = constructString(NULL, (yyvsp[(1) - (1)].VALUE).s); ;}
    break;



/* Line 1455 of yacc.c  */
#line 1862 "mozart-parser.tab.c"
>>>>>>> master
      default: break;
    }
  YY_SYMBOL_PRINT ("-> $$ =", yyr1[yyn], &yyval, &yyloc);

  YYPOPSTACK (yylen);
  yylen = 0;
  YY_STACK_PRINT (yyss, yyssp);

  *++yyvsp = yyval;

  /* Now `shift' the result of the reduction.  Determine what state
     that goes to, based on the state we popped back to and the rule
     number reduced by.  */

  yyn = yyr1[yyn];

  yystate = yypgoto[yyn - YYNTOKENS] + *yyssp;
  if (0 <= yystate && yystate <= YYLAST && yycheck[yystate] == *yyssp)
    yystate = yytable[yystate];
  else
    yystate = yydefgoto[yyn - YYNTOKENS];

  goto yynewstate;


/*------------------------------------.
| yyerrlab -- here on detecting error |
`------------------------------------*/
yyerrlab:
  /* If not already recovering from an error, report this error.  */
  if (!yyerrstatus)
    {
      ++yynerrs;
#if ! YYERROR_VERBOSE
      yyerror (YY_("syntax error"));
#else
      {
	YYSIZE_T yysize = yysyntax_error (0, yystate, yychar);
	if (yymsg_alloc < yysize && yymsg_alloc < YYSTACK_ALLOC_MAXIMUM)
	  {
	    YYSIZE_T yyalloc = 2 * yysize;
	    if (! (yysize <= yyalloc && yyalloc <= YYSTACK_ALLOC_MAXIMUM))
	      yyalloc = YYSTACK_ALLOC_MAXIMUM;
	    if (yymsg != yymsgbuf)
	      YYSTACK_FREE (yymsg);
	    yymsg = (char *) YYSTACK_ALLOC (yyalloc);
	    if (yymsg)
	      yymsg_alloc = yyalloc;
	    else
	      {
		yymsg = yymsgbuf;
		yymsg_alloc = sizeof yymsgbuf;
	      }
	  }

	if (0 < yysize && yysize <= yymsg_alloc)
	  {
	    (void) yysyntax_error (yymsg, yystate, yychar);
	    yyerror (yymsg);
	  }
	else
	  {
	    yyerror (YY_("syntax error"));
	    if (yysize != 0)
	      goto yyexhaustedlab;
	  }
      }
#endif
    }



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
		      yytoken, &yylval);
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

  /* Do not reclaim the symbols of the rule which action triggered
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
  yyerrstatus = 3;	/* Each real token shifted decrements this.  */

  for (;;)
    {
      yyn = yypact[yystate];
      if (yyn != YYPACT_NINF)
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


      yydestruct ("Error: popping",
		  yystos[yystate], yyvsp);
      YYPOPSTACK (1);
      yystate = *yyssp;
      YY_STACK_PRINT (yyss, yyssp);
    }

  *++yyvsp = yylval;


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

#if !defined(yyoverflow) || YYERROR_VERBOSE
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
     yydestruct ("Cleanup: discarding lookahead",
		 yytoken, &yylval);
  /* Do not reclaim the symbols of the rule which action triggered
     this YYABORT or YYACCEPT.  */
  YYPOPSTACK (yylen);
  YY_STACK_PRINT (yyss, yyssp);
  while (yyssp != yyss)
    {
      yydestruct ("Cleanup: popping",
		  yystos[*yyssp], yyvsp);
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
  /* Make sure YYID is used.  */
  return YYID (yyresult);
}



/* Line 1675 of yacc.c  */
<<<<<<< HEAD
#line 140 "mozart-parser.y"

/*
           |EXPR GREATEREQUAL EXPR                  { $$ = $1 >= $3}  
           |EXPR LOWER EXPR                         { $$ = $1 < $3}  
           |EXPR LOWEREQUAL EXPR                    { $$ = $1 <= $3}  
           |EXPR EQUAL EXPR                         { $$ = $1 == $3}  
           |EXPR  NOTEQUAL EXPR                     { $$ = $1 != $3}  
           |NOT LOGICEXPR                           { $$ = !$2} 
           |LOGICEXPR OR LOGICEXPR                  { $$ = $1 || $3} 
           |LOGICEXPR AND LOGICEXPR                 { $$ = $1 && $3} 
           
           | LINE LOOPSTMT ENDOFSTMT                       {;}
           
           LOOPSTMT :  INTEGERTYPE PER LOOP STARTOFSCOPE LINE ENDOFSCOPE         { insert number of times loop get executed into symbolTable;} 
           |ID PER LOOP STARTOFSCOPE LINE ENDOFSCOPE {;}
           */

           
void typeCheck(Node* n1, char * typeKeyword){
        if(strcmp(enumToString(n1->type),typeKeyword)){
                yyerror("type declaration does not match !");
                exit(1);
        }
}

int getIntValue(Node* n){
        return n->value.i;
}

Type getType(Node* n){
        return n->type;
}

float getFloatValue(Node* n){
        return n->value.f;
}

bool getBoolValue(Node* n){
        return n->value.b;
}

char* getStringValue(Node* n){
        return n->value.s;
}

char * stringConcat(char * str1, char * str2){
        char newString[strlen(str1) + strlen(str2) + 1];
        strcpy(newString, str1);
        strcpy(newString, str2);
        return strdup(newString);
}

Node* trueVal(){
        Node* result =(Node *) malloc(sizeof(Node));
        result->type = BOOLEAN;
        result->value.b = true;
        return result;
}
Node* falseVal(){
        Node* result =(Node *) malloc(sizeof(Node));
        result->type = BOOLEAN;
        result->value.b = false;
        return result;
}

Node* greater(Node* node1, Node* node2){
        if (node1->type != node2->type) 
                yyerror("incompatibile");
        else{
                Node* result =(Node *) malloc(sizeof(Node));
                result->type = BOOLEAN;
                switch(node1->type){
                        case INTEGER : result->value.b = node1->value.i > node2->value.i;
                                       return result; 
                        case FLOAT   : result->value.b = node1->value.f > node2->value.f;
                                        return result;
                        case BOOLEAN : yyerror("operator not supported.");
                                        break;
                        case STRING  : result->value.b = strlen(node1->value.s) > strlen(node2->value.s);
                                        return result;
                }
        }
}

Node* add(Node* node1, Node* node2){
        printf("\nAdding.\n");
        if (node1->type != node2->type) 
                yyerror("incompatibile");
        else{
                int resultI;
                float resultF;
                char* resultS;
                //Node* result =(Node *) malloc(sizeof(Node));
                switch(node1->type){
                        case INTEGER : resultI = node1->value.i + node2->value.i; 
                                       node1->value.i = resultI;
                                       return node1;
                        case FLOAT   : resultF = node1->value.f + node2->value.f;
                                       node1->value.f = resultF;
                                       return node1;
                        case BOOLEAN : yyerror("operator not supported.");
                                       break;
                        case STRING  : resultS = stringConcat(node1->value.s, node2->value.s);
                                       node1->value.s = resultS;
                                       return node1;
                }

        }
}
/*
Node* subtract(Node* node1, Node* node2){
        if (node1->type != node2->type) 
                yyerror("incompatibile");
        else{
                Node* result =(Node *) malloc(sizeof(Node));
                switch(node1->type){
                        case INTEGER : return node1->value.i - node2->value.i; 
                                       break;
                        case FLOAT   : return node1->value.f - node2->value.f;
                                       break;
                        case BOOLEAN : yyerror("operator not supported.");
                                       break;
                        case STRING  : yyerror("operator not supported.");
                                       break;
                }

        }
}

Node* multiply(Node* node1, Node* node2){
        if (node1->type != node2->type) 
                yyerror("incompatibile");
        else{
                switch(node1.type){
                        case INTEGER : return node1.value.i * node2.value.i; 
                                       break;
                        case FLOAT   : return node1.value.f * node2.value.f;
                                       break;
                        case BOOLEAN : yyerror("operator not supported.");
                                       break;
                        case STRING  : yyerror("operator not supported.");
                                       break;
                }

        }
}

Node* divide(Node* node1, Node* node2){
        if (node1.type != node2.type) 
                yyerror("incompatibile");
        if (node2.value == 0){
                yyerror("division by 0 is not possible.");
        }
        else{
                switch(node1.type){
                        case INTEGER : return node1.value.i - node2.value.i; 
                                       break;
                        case FLOAT   : return node1.value.f - node2.value.f;
                                       break;
                        case BOOLEAN : yyerror("operator not supported.");
                                       break;
                        case STRING  : yyerror("operator not supported.");
                                       break;
                }

        }
}*/


void printExpr(Node* n){
                printf("Result: ");
                switch(n->type){
                        case INTEGER : printf("%i\n", n->value.i);break;
                        case FLOAT   : printf("%f\n", n->value.f);break;
                        case BOOLEAN : printf("%i\n", n->value.b);break;
                        case STRING  : printf("%s\n", n->value.s);break;
                }
}


void yyerror(char * s) {  
    fprintf (stderr, "%s\n", s);
    exit(1);
}
  
=======
#line 157 "mozart-parser.y"

 
>>>>>>> master
int main(void) {
    return yyparse();
}

