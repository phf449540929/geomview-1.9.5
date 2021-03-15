/* A Bison parser, made by GNU Bison 2.7.12-4996.  */

/* Bison implementation for Yacc-like parsers in C
   
      Copyright (C) 1984, 1989-1990, 2000-2013 Free Software Foundation, Inc.
   
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

/* All symbols defined below should begin with wafsa or YY, to avoid
   infringing on user name space.  This should be done even for local
   variables, as they might otherwise be expanded by user macros.
   There are some unavoidable exceptions within include files to
   define necessary library symbols; they are noted "INFRINGES ON
   USER NAME SPACE" below.  */

/* Identify Bison output.  */
#define YYBISON 1

/* Bison version.  */
#define YYBISON_VERSION "2.7.12-4996"

/* Skeleton name.  */
#define YYSKELETON_NAME "yacc.c"

/* Pure parsers.  */
#define YYPURE 0

/* Push parsers.  */
#define YYPUSH 0

/* Pull parsers.  */
#define YYPULL 1




/* Copy the first part of user declarations.  */
/* Line 371 of yacc.c  */
#line 16 "../../../../../src/lib/oogl/wa/fsaparse.y"


#if 0
static char copyright[] =
  "Copyright (C) 1991 Mark B. Phillips, The Geometry Center";
#endif

#ifdef HAVE_CONFIG_H
# include "config.h"
#endif

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "wa.h"
#include "wa.yystype.h"
#include "wa.yacc.h"

#define MAXSTATES 100
#define MAXGENS 128

static int adj[MAXSTATES];
static int adj_index = 0;
static void install_adjacency();
static void wafsaerror(char *s);
extern int wafsalex(void);

static wa *fsa;


/* Line 371 of yacc.c  */
#line 99 "y.tab.c"

# ifndef YY_NULL
#  if defined __cplusplus && 201103L <= __cplusplus
#   define YY_NULL nullptr
#  else
#   define YY_NULL 0
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
   by #include "y.tab.h".  */
#ifndef YY_YY_Y_TAB_H_INCLUDED
# define YY_YY_Y_TAB_H_INCLUDED
/* Enabling traces.  */
#ifndef YYDEBUG
# define YYDEBUG 0
#endif
#if YYDEBUG
extern int wafsadebug;
#endif

/* Tokens.  */
#ifndef YYTOKENTYPE
# define YYTOKENTYPE
   /* Put the tokens into the symbol table, so that GDB and other debuggers
      know about them.  */
   enum wafsatokentype {
     FORMAT = 258,
     FSA = 259,
     STATES = 260,
     SYMBOLS = 261,
     BFS = 262,
     MIN = 263,
     VARIABLES = 264,
     ALPHABET = 265,
     START = 266,
     ATABLE = 267,
     INVERSES = 268,
     INV = 269,
     LEFT_BRACE = 270,
     RIGHT_BRACE = 271,
     LEFT_PAREN = 272,
     RIGHT_PAREN = 273,
     SEMICOLON = 274,
     PERCENT = 275,
     INT = 276,
     EQUAL = 277,
     STRING = 278,
     REAL = 279
   };
#endif
/* Tokens.  */
#define FORMAT 258
#define FSA 259
#define STATES 260
#define SYMBOLS 261
#define BFS 262
#define MIN 263
#define VARIABLES 264
#define ALPHABET 265
#define START 266
#define ATABLE 267
#define INVERSES 268
#define INV 269
#define LEFT_BRACE 270
#define RIGHT_BRACE 271
#define LEFT_PAREN 272
#define RIGHT_PAREN 273
#define SEMICOLON 274
#define PERCENT 275
#define INT 276
#define EQUAL 277
#define STRING 278
#define REAL 279



#if ! defined YYSTYPE && ! defined YYSTYPE_IS_DECLARED

# define wafsastype YYSTYPE /* obsolescent; will be withdrawn */
# define YYSTYPE_IS_DECLARED 1
#endif

extern YYSTYPE wafsalval;

#ifdef YYPARSE_PARAM
#if defined __STDC__ || defined __cplusplus
int wafsaparse (void *YYPARSE_PARAM);
#else
int wafsaparse ();
#endif
#else /* ! YYPARSE_PARAM */
#if defined __STDC__ || defined __cplusplus
int wafsaparse (void);
#else
int wafsaparse ();
#endif
#endif /* ! YYPARSE_PARAM */

#endif /* !YY_YY_Y_TAB_H_INCLUDED  */

/* Copy the second part of user declarations.  */

/* Line 390 of yacc.c  */
#line 212 "y.tab.c"

#ifdef short
# undef short
#endif

#ifdef YYTYPE_UINT8
typedef YYTYPE_UINT8 wafsatype_uint8;
#else
typedef unsigned char wafsatype_uint8;
#endif

#ifdef YYTYPE_INT8
typedef YYTYPE_INT8 wafsatype_int8;
#elif (defined __STDC__ || defined __C99__FUNC__ \
     || defined __cplusplus || defined _MSC_VER)
typedef signed char wafsatype_int8;
#else
typedef short int wafsatype_int8;
#endif

#ifdef YYTYPE_UINT16
typedef YYTYPE_UINT16 wafsatype_uint16;
#else
typedef unsigned short int wafsatype_uint16;
#endif

#ifdef YYTYPE_INT16
typedef YYTYPE_INT16 wafsatype_int16;
#else
typedef short int wafsatype_int16;
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

#ifndef __attribute__
/* This feature is available in gcc versions 2.5 and later.  */
# if (! defined __GNUC__ || __GNUC__ < 2 \
      || (__GNUC__ == 2 && __GNUC_MINOR__ < 5))
#  define __attribute__(Spec) /* empty */
# endif
#endif

/* Suppress unused-variable warnings by "using" E.  */
#if ! defined lint || defined __GNUC__
# define YYUSE(E) ((void) (E))
#else
# define YYUSE(E) /* empty */
#endif


/* Identity function, used to suppress warnings about constant conditions.  */
#ifndef lint
# define YYID(N) (N)
#else
#if (defined __STDC__ || defined __C99__FUNC__ \
     || defined __cplusplus || defined _MSC_VER)
static int
YYID (int wafsai)
#else
static int
YYID (wafsai)
    int wafsai;
#endif
{
  return wafsai;
}
#endif

#if ! defined wafsaoverflow || YYERROR_VERBOSE

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
#    if ! defined _ALLOCA_H && ! defined EXIT_SUCCESS && (defined __STDC__ || defined __C99__FUNC__ \
     || defined __cplusplus || defined _MSC_VER)
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
#   if ! defined malloc && ! defined EXIT_SUCCESS && (defined __STDC__ || defined __C99__FUNC__ \
     || defined __cplusplus || defined _MSC_VER)
void *malloc (YYSIZE_T); /* INFRINGES ON USER NAME SPACE */
#   endif
#  endif
#  ifndef YYFREE
#   define YYFREE free
#   if ! defined free && ! defined EXIT_SUCCESS && (defined __STDC__ || defined __C99__FUNC__ \
     || defined __cplusplus || defined _MSC_VER)
void free (void *); /* INFRINGES ON USER NAME SPACE */
#   endif
#  endif
# endif
#endif /* ! defined wafsaoverflow || YYERROR_VERBOSE */


#if (! defined wafsaoverflow \
     && (! defined __cplusplus \
	 || (defined YYSTYPE_IS_TRIVIAL && YYSTYPE_IS_TRIVIAL)))

/* A type that is properly aligned for any stack member.  */
union wafsaalloc
{
  wafsatype_int16 wafsass_alloc;
  YYSTYPE wafsavs_alloc;
};

/* The size of the maximum gap between one aligned stack and the next.  */
# define YYSTACK_GAP_MAXIMUM (sizeof (union wafsaalloc) - 1)

/* The size of an array large to enough to hold all stacks, each with
   N elements.  */
# define YYSTACK_BYTES(N) \
     ((N) * (sizeof (wafsatype_int16) + sizeof (YYSTYPE)) \
      + YYSTACK_GAP_MAXIMUM)

# define YYCOPY_NEEDED 1

/* Relocate STACK from its old location to the new one.  The
   local variables YYSIZE and YYSTACKSIZE give the old and new number of
   elements in the stack, and YYPTR gives the new location of the
   stack.  Advance YYPTR to a properly aligned location for the next
   stack.  */
# define YYSTACK_RELOCATE(Stack_alloc, Stack)				\
    do									\
      {									\
	YYSIZE_T wafsanewbytes;						\
	YYCOPY (&wafsaptr->Stack_alloc, Stack, wafsasize);			\
	Stack = &wafsaptr->Stack_alloc;					\
	wafsanewbytes = wafsastacksize * sizeof (*Stack) + YYSTACK_GAP_MAXIMUM; \
	wafsaptr += wafsanewbytes / sizeof (*wafsaptr);				\
      }									\
    while (YYID (0))

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
          YYSIZE_T wafsai;                         \
          for (wafsai = 0; wafsai < (Count); wafsai++)   \
            (Dst)[wafsai] = (Src)[wafsai];            \
        }                                       \
      while (YYID (0))
#  endif
# endif
#endif /* !YYCOPY_NEEDED */

/* YYFINAL -- State number of the termination state.  */
#define YYFINAL  4
/* YYLAST -- Last index in YYTABLE.  */
#define YYLAST   44

/* YYNTOKENS -- Number of terminals.  */
#define YYNTOKENS  25
/* YYNNTS -- Number of nonterminals.  */
#define YYNNTS  18
/* YYNRULES -- Number of rules.  */
#define YYNRULES  29
/* YYNRULES -- Number of states.  */
#define YYNSTATES  56

/* YYTRANSLATE(YYLEX) -- Bison symbol number corresponding to YYLEX.  */
#define YYUNDEFTOK  2
#define YYMAXUTOK   279

#define YYTRANSLATE(YYX)						\
  ((unsigned int) (YYX) <= YYMAXUTOK ? wafsatranslate[YYX] : YYUNDEFTOK)

/* YYTRANSLATE[YYLEX] -- Bison symbol number corresponding to YYLEX.  */
static const wafsatype_uint8 wafsatranslate[] =
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
      15,    16,    17,    18,    19,    20,    21,    22,    23,    24
};

#if YYDEBUG
/* YYPRHS[YYN] -- Index of the first RHS symbol of rule number YYN in
   YYRHS.  */
static const wafsatype_uint8 wafsaprhs[] =
{
       0,     0,     3,     7,    17,    20,    23,    25,    28,    30,
      32,    35,    37,    40,    42,    44,    49,    51,    54,    58,
      63,    69,    71,    74,    77,    79,    81,    84,    89,    91
};

/* YYRHS -- A `-1'-separated list of the rules' RHS.  */
static const wafsatype_int8 wafsarhs[] =
{
      26,     0,    -1,     3,    24,    27,    -1,     4,    15,    28,
      29,    30,    32,    20,    39,    16,    -1,     5,    21,    -1,
       6,    21,    -1,    31,    -1,    31,    30,    -1,     7,    -1,
       8,    -1,     9,    21,    -1,    33,    -1,    33,    32,    -1,
      34,    -1,    37,    -1,    10,    15,    35,    16,    -1,    36,
      -1,    35,    36,    -1,    21,    22,    23,    -1,    11,    15,
      21,    16,    -1,    11,    15,    21,    38,    16,    -1,    21,
      -1,    21,    38,    -1,    12,    40,    -1,    12,    -1,    41,
      -1,    41,    40,    -1,    21,    23,    42,    19,    -1,    21,
      -1,    42,    21,    -1
};

/* YYRLINE[YYN] -- source line where rule number YYN was defined.  */
static const wafsatype_uint8 wafsarline[] =
{
       0,    58,    58,    61,    73,    81,    98,    99,   104,   105,
     106,   110,   111,   114,   115,   121,   124,   125,   128,   136,
     138,   143,   144,   148,   149,   152,   153,   156,   160,   164
};
#endif

#if YYDEBUG || YYERROR_VERBOSE || 0
/* YYTNAME[SYMBOL-NUM] -- String name of the symbol SYMBOL-NUM.
   First, the terminals, then, starting at YYNTOKENS, nonterminals.  */
static const char *const wafsatname[] =
{
  "$end", "error", "$undefined", "FORMAT", "FSA", "STATES", "SYMBOLS",
  "BFS", "MIN", "VARIABLES", "ALPHABET", "START", "ATABLE", "INVERSES",
  "INV", "LEFT_BRACE", "RIGHT_BRACE", "LEFT_PAREN", "RIGHT_PAREN",
  "SEMICOLON", "PERCENT", "INT", "EQUAL", "STRING", "REAL", "$accept",
  "fsa_file", "fsa_format", "states", "symbols", "fsa_characteristics",
  "fsa_characteristic", "info_items", "info_item", "alphabet",
  "symbol_names", "symbol_name", "start_states", "int_list", "fsa_table",
  "acstates", "acstate", "adjacency", YY_NULL
};
#endif

# ifdef YYPRINT
/* YYTOKNUM[YYLEX-NUM] -- Internal token number corresponding to
   token YYLEX-NUM.  */
static const wafsatype_uint16 wafsatoknum[] =
{
       0,   256,   257,   258,   259,   260,   261,   262,   263,   264,
     265,   266,   267,   268,   269,   270,   271,   272,   273,   274,
     275,   276,   277,   278,   279
};
# endif

/* YYR1[YYN] -- Symbol number of symbol that rule YYN derives.  */
static const wafsatype_uint8 wafsar1[] =
{
       0,    25,    26,    27,    28,    29,    30,    30,    31,    31,
      31,    32,    32,    33,    33,    34,    35,    35,    36,    37,
      37,    38,    38,    39,    39,    40,    40,    41,    42,    42
};

/* YYR2[YYN] -- Number of symbols composing right hand side of rule YYN.  */
static const wafsatype_uint8 wafsar2[] =
{
       0,     2,     3,     9,     2,     2,     1,     2,     1,     1,
       2,     1,     2,     1,     1,     4,     1,     2,     3,     4,
       5,     1,     2,     2,     1,     1,     2,     4,     1,     2
};

/* YYDEFACT[STATE-NAME] -- Default reduction number in state STATE-NUM.
   Performed when YYTABLE doesn't specify something else to do.  Zero
   means the default is an error.  */
static const wafsatype_uint8 wafsadefact[] =
{
       0,     0,     0,     0,     1,     0,     2,     0,     0,     0,
       4,     0,     0,     5,     8,     9,     0,     0,     6,    10,
       0,     0,     0,    11,    13,    14,     7,     0,     0,     0,
      12,     0,     0,    16,     0,    24,     0,     0,    15,    17,
      19,    21,     0,     0,    23,    25,     3,    18,    22,    20,
       0,    26,    28,     0,    27,    29
};

/* YYDEFGOTO[NTERM-NUM].  */
static const wafsatype_int8 wafsadefgoto[] =
{
      -1,     2,     6,     9,    12,    17,    18,    22,    23,    24,
      32,    33,    25,    42,    36,    44,    45,    53
};

/* YYPACT[STATE-NUM] -- Index in YYTABLE of the portion describing
   STATE-NUM.  */
#define YYPACT_NINF -17
static const wafsatype_int8 wafsapact[] =
{
       5,   -11,    12,    10,   -17,     1,   -17,    13,    -6,    11,
     -17,    -2,    -5,   -17,   -17,   -17,    -1,     0,    -5,   -17,
       6,     7,     3,     0,   -17,   -17,   -17,     4,     8,    14,
     -17,     2,   -16,   -17,   -15,     9,    15,    16,   -17,   -17,
     -17,    17,    18,    19,   -17,     9,   -17,   -17,   -17,   -17,
      20,   -17,   -17,   -12,   -17,   -17
};

/* YYPGOTO[NTERM-NUM].  */
static const wafsatype_int8 wafsapgoto[] =
{
     -17,   -17,   -17,   -17,   -17,    22,   -17,    21,   -17,   -17,
     -17,    -4,   -17,   -14,   -17,   -13,   -17,   -17
};

/* YYTABLE[YYPACT[STATE-NUM]].  What to do in state STATE-NUM.  If
   positive, shift that token.  If negative, reduce the rule which
   number is the opposite.  If YYTABLE_NINF, syntax error.  */
#define YYTABLE_NINF -1
static const wafsatype_uint8 wafsatable[] =
{
      38,    40,    14,    15,    16,    31,    41,    54,     1,    55,
      20,    21,     4,     3,     5,    10,     7,    11,     8,    13,
      19,    27,    28,    29,    37,    31,    35,    48,    39,    34,
      43,    46,    51,     0,    49,     0,     0,     0,    41,    47,
      26,    52,    50,     0,    30
};

#define wafsapact_value_is_default(Yystate) \
  (!!((Yystate) == (-17)))

#define wafsatable_value_is_error(Yytable_value) \
  YYID (0)

static const wafsatype_int8 wafsacheck[] =
{
      16,    16,     7,     8,     9,    21,    21,    19,     3,    21,
      10,    11,     0,    24,     4,    21,    15,     6,     5,    21,
      21,    15,    15,    20,    22,    21,    12,    41,    32,    21,
      21,    16,    45,    -1,    16,    -1,    -1,    -1,    21,    23,
      18,    21,    23,    -1,    23
};

/* YYSTOS[STATE-NUM] -- The (internal number of the) accessing
   symbol of state STATE-NUM.  */
static const wafsatype_uint8 wafsastos[] =
{
       0,     3,    26,    24,     0,     4,    27,    15,     5,    28,
      21,     6,    29,    21,     7,     8,     9,    30,    31,    21,
      10,    11,    32,    33,    34,    37,    30,    15,    15,    20,
      32,    21,    35,    36,    21,    12,    39,    22,    16,    36,
      16,    21,    38,    21,    40,    41,    16,    23,    38,    16,
      23,    40,    21,    42,    19,    21
};

#define wafsaerrok		(wafsaerrstatus = 0)
#define wafsaclearin	(wafsachar = YYEMPTY)
#define YYEMPTY		(-2)
#define YYEOF		0

#define YYACCEPT	goto wafsaacceptlab
#define YYABORT		goto wafsaabortlab
#define YYERROR		goto wafsaerrorlab


/* Like YYERROR except do call wafsaerror.  This remains here temporarily
   to ease the transition to the new meaning of YYERROR, for GCC.
   Once GCC version 2 has supplanted version 1, this can go.  However,
   YYFAIL appears to be in use.  Nevertheless, it is formally deprecated
   in Bison 2.4.2's NEWS entry, where a plan to phase it out is
   discussed.  */

#define YYFAIL		goto wafsaerrlab
#if defined YYFAIL
  /* This is here to suppress warnings from the GCC cpp's
     -Wunused-macros.  Normally we don't worry about that warning, but
     some users do, and we want to make it easy for users to remove
     YYFAIL uses, which will produce warnings from Bison 2.5.  */
#endif

#define YYRECOVERING()  (!!wafsaerrstatus)

#define YYBACKUP(Token, Value)                                  \
do                                                              \
  if (wafsachar == YYEMPTY)                                        \
    {                                                           \
      wafsachar = (Token);                                         \
      wafsalval = (Value);                                         \
      YYPOPSTACK (wafsalen);                                       \
      wafsastate = *wafsassp;                                         \
      goto wafsabackup;                                            \
    }                                                           \
  else                                                          \
    {                                                           \
      wafsaerror (YY_("syntax error: cannot back up")); \
      YYERROR;							\
    }								\
while (YYID (0))

/* Error token number */
#define YYTERROR	1
#define YYERRCODE	256


/* This macro is provided for backward compatibility. */
#ifndef YY_LOCATION_PRINT
# define YY_LOCATION_PRINT(File, Loc) ((void) 0)
#endif


/* YYLEX -- calling `wafsalex' with the right arguments.  */
#ifdef YYLEX_PARAM
# define YYLEX wafsalex (YYLEX_PARAM)
#else
# define YYLEX wafsalex ()
#endif

/* Enable debugging if requested.  */
#if YYDEBUG

# ifndef YYFPRINTF
#  include <stdio.h> /* INFRINGES ON USER NAME SPACE */
#  define YYFPRINTF fprintf
# endif

# define YYDPRINTF(Args)			\
do {						\
  if (wafsadebug)					\
    YYFPRINTF Args;				\
} while (YYID (0))

# define YY_SYMBOL_PRINT(Title, Type, Value, Location)			  \
do {									  \
  if (wafsadebug)								  \
    {									  \
      YYFPRINTF (stderr, "%s ", Title);					  \
      wafsa_symbol_print (stderr,						  \
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
wafsa_symbol_value_print (FILE *wafsaoutput, int wafsatype, YYSTYPE const * const wafsavaluep)
#else
static void
wafsa_symbol_value_print (wafsaoutput, wafsatype, wafsavaluep)
    FILE *wafsaoutput;
    int wafsatype;
    YYSTYPE const * const wafsavaluep;
#endif
{
  FILE *wafsao = wafsaoutput;
  YYUSE (wafsao);
  if (!wafsavaluep)
    return;
# ifdef YYPRINT
  if (wafsatype < YYNTOKENS)
    YYPRINT (wafsaoutput, wafsatoknum[wafsatype], *wafsavaluep);
# else
  YYUSE (wafsaoutput);
# endif
  YYUSE (wafsatype);
}


/*--------------------------------.
| Print this symbol on YYOUTPUT.  |
`--------------------------------*/

#if (defined __STDC__ || defined __C99__FUNC__ \
     || defined __cplusplus || defined _MSC_VER)
static void
wafsa_symbol_print (FILE *wafsaoutput, int wafsatype, YYSTYPE const * const wafsavaluep)
#else
static void
wafsa_symbol_print (wafsaoutput, wafsatype, wafsavaluep)
    FILE *wafsaoutput;
    int wafsatype;
    YYSTYPE const * const wafsavaluep;
#endif
{
  if (wafsatype < YYNTOKENS)
    YYFPRINTF (wafsaoutput, "token %s (", wafsatname[wafsatype]);
  else
    YYFPRINTF (wafsaoutput, "nterm %s (", wafsatname[wafsatype]);

  wafsa_symbol_value_print (wafsaoutput, wafsatype, wafsavaluep);
  YYFPRINTF (wafsaoutput, ")");
}

/*------------------------------------------------------------------.
| wafsa_stack_print -- Print the state stack from its BOTTOM up to its |
| TOP (included).                                                   |
`------------------------------------------------------------------*/

#if (defined __STDC__ || defined __C99__FUNC__ \
     || defined __cplusplus || defined _MSC_VER)
static void
wafsa_stack_print (wafsatype_int16 *wafsabottom, wafsatype_int16 *wafsatop)
#else
static void
wafsa_stack_print (wafsabottom, wafsatop)
    wafsatype_int16 *wafsabottom;
    wafsatype_int16 *wafsatop;
#endif
{
  YYFPRINTF (stderr, "Stack now");
  for (; wafsabottom <= wafsatop; wafsabottom++)
    {
      int wafsabot = *wafsabottom;
      YYFPRINTF (stderr, " %d", wafsabot);
    }
  YYFPRINTF (stderr, "\n");
}

# define YY_STACK_PRINT(Bottom, Top)				\
do {								\
  if (wafsadebug)							\
    wafsa_stack_print ((Bottom), (Top));				\
} while (YYID (0))


/*------------------------------------------------.
| Report that the YYRULE is going to be reduced.  |
`------------------------------------------------*/

#if (defined __STDC__ || defined __C99__FUNC__ \
     || defined __cplusplus || defined _MSC_VER)
static void
wafsa_reduce_print (YYSTYPE *wafsavsp, int wafsarule)
#else
static void
wafsa_reduce_print (wafsavsp, wafsarule)
    YYSTYPE *wafsavsp;
    int wafsarule;
#endif
{
  int wafsanrhs = wafsar2[wafsarule];
  int wafsai;
  unsigned long int wafsalno = wafsarline[wafsarule];
  YYFPRINTF (stderr, "Reducing stack by rule %d (line %lu):\n",
	     wafsarule - 1, wafsalno);
  /* The symbols being reduced.  */
  for (wafsai = 0; wafsai < wafsanrhs; wafsai++)
    {
      YYFPRINTF (stderr, "   $%d = ", wafsai + 1);
      wafsa_symbol_print (stderr, wafsarhs[wafsaprhs[wafsarule] + wafsai],
		       &(wafsavsp[(wafsai + 1) - (wafsanrhs)])
		       		       );
      YYFPRINTF (stderr, "\n");
    }
}

# define YY_REDUCE_PRINT(Rule)		\
do {					\
  if (wafsadebug)				\
    wafsa_reduce_print (wafsavsp, Rule); \
} while (YYID (0))

/* Nonzero means print parse trace.  It is left uninitialized so that
   multiple parsers can coexist.  */
int wafsadebug;
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

# ifndef wafsastrlen
#  if defined __GLIBC__ && defined _STRING_H
#   define wafsastrlen strlen
#  else
/* Return the length of YYSTR.  */
#if (defined __STDC__ || defined __C99__FUNC__ \
     || defined __cplusplus || defined _MSC_VER)
static YYSIZE_T
wafsastrlen (const char *wafsastr)
#else
static YYSIZE_T
wafsastrlen (wafsastr)
    const char *wafsastr;
#endif
{
  YYSIZE_T wafsalen;
  for (wafsalen = 0; wafsastr[wafsalen]; wafsalen++)
    continue;
  return wafsalen;
}
#  endif
# endif

# ifndef wafsastpcpy
#  if defined __GLIBC__ && defined _STRING_H && defined _GNU_SOURCE
#   define wafsastpcpy stpcpy
#  else
/* Copy YYSRC to YYDEST, returning the address of the terminating '\0' in
   YYDEST.  */
#if (defined __STDC__ || defined __C99__FUNC__ \
     || defined __cplusplus || defined _MSC_VER)
static char *
wafsastpcpy (char *wafsadest, const char *wafsasrc)
#else
static char *
wafsastpcpy (wafsadest, wafsasrc)
    char *wafsadest;
    const char *wafsasrc;
#endif
{
  char *wafsad = wafsadest;
  const char *wafsas = wafsasrc;

  while ((*wafsad++ = *wafsas++) != '\0')
    continue;

  return wafsad - 1;
}
#  endif
# endif

# ifndef wafsatnamerr
/* Copy to YYRES the contents of YYSTR after stripping away unnecessary
   quotes and backslashes, so that it's suitable for wafsaerror.  The
   heuristic is that double-quoting is unnecessary unless the string
   contains an apostrophe, a comma, or backslash (other than
   backslash-backslash).  YYSTR is taken from wafsatname.  If YYRES is
   null, do not copy; instead, return the length of what the result
   would have been.  */
static YYSIZE_T
wafsatnamerr (char *wafsares, const char *wafsastr)
{
  if (*wafsastr == '"')
    {
      YYSIZE_T wafsan = 0;
      char const *wafsap = wafsastr;

      for (;;)
	switch (*++wafsap)
	  {
	  case '\'':
	  case ',':
	    goto do_not_strip_quotes;

	  case '\\':
	    if (*++wafsap != '\\')
	      goto do_not_strip_quotes;
	    /* Fall through.  */
	  default:
	    if (wafsares)
	      wafsares[wafsan] = *wafsap;
	    wafsan++;
	    break;

	  case '"':
	    if (wafsares)
	      wafsares[wafsan] = '\0';
	    return wafsan;
	  }
    do_not_strip_quotes: ;
    }

  if (! wafsares)
    return wafsastrlen (wafsastr);

  return wafsastpcpy (wafsares, wafsastr) - wafsares;
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
wafsasyntax_error (YYSIZE_T *wafsamsg_alloc, char **wafsamsg,
                wafsatype_int16 *wafsassp, int wafsatoken)
{
  YYSIZE_T wafsasize0 = wafsatnamerr (YY_NULL, wafsatname[wafsatoken]);
  YYSIZE_T wafsasize = wafsasize0;
  enum { YYERROR_VERBOSE_ARGS_MAXIMUM = 5 };
  /* Internationalized format string. */
  const char *wafsaformat = YY_NULL;
  /* Arguments of wafsaformat. */
  char const *wafsaarg[YYERROR_VERBOSE_ARGS_MAXIMUM];
  /* Number of reported tokens (one for the "unexpected", one per
     "expected"). */
  int wafsacount = 0;

  /* There are many possibilities here to consider:
     - Assume YYFAIL is not used.  It's too flawed to consider.  See
       <http://lists.gnu.org/archive/html/bison-patches/2009-12/msg00024.html>
       for details.  YYERROR is fine as it does not invoke this
       function.
     - If this state is a consistent state with a default action, then
       the only way this function was invoked is if the default action
       is an error action.  In that case, don't check for expected
       tokens because there are none.
     - The only way there can be no lookahead present (in wafsachar) is if
       this state is a consistent state with a default action.  Thus,
       detecting the absence of a lookahead is sufficient to determine
       that there is no unexpected or expected token to report.  In that
       case, just report a simple "syntax error".
     - Don't assume there isn't a lookahead just because this state is a
       consistent state with a default action.  There might have been a
       previous inconsistent state, consistent state with a non-default
       action, or user semantic action that manipulated wafsachar.
     - Of course, the expected token list depends on states to have
       correct lookahead information, and it depends on the parser not
       to perform extra reductions after fetching a lookahead from the
       scanner and before detecting a syntax error.  Thus, state merging
       (from LALR or IELR) and default reductions corrupt the expected
       token list.  However, the list is correct for canonical LR with
       one exception: it will still contain any token that will not be
       accepted due to an error action in a later state.
  */
  if (wafsatoken != YYEMPTY)
    {
      int wafsan = wafsapact[*wafsassp];
      wafsaarg[wafsacount++] = wafsatname[wafsatoken];
      if (!wafsapact_value_is_default (wafsan))
        {
          /* Start YYX at -YYN if negative to avoid negative indexes in
             YYCHECK.  In other words, skip the first -YYN actions for
             this state because they are default actions.  */
          int wafsaxbegin = wafsan < 0 ? -wafsan : 0;
          /* Stay within bounds of both wafsacheck and wafsatname.  */
          int wafsachecklim = YYLAST - wafsan + 1;
          int wafsaxend = wafsachecklim < YYNTOKENS ? wafsachecklim : YYNTOKENS;
          int wafsax;

          for (wafsax = wafsaxbegin; wafsax < wafsaxend; ++wafsax)
            if (wafsacheck[wafsax + wafsan] == wafsax && wafsax != YYTERROR
                && !wafsatable_value_is_error (wafsatable[wafsax + wafsan]))
              {
                if (wafsacount == YYERROR_VERBOSE_ARGS_MAXIMUM)
                  {
                    wafsacount = 1;
                    wafsasize = wafsasize0;
                    break;
                  }
                wafsaarg[wafsacount++] = wafsatname[wafsax];
                {
                  YYSIZE_T wafsasize1 = wafsasize + wafsatnamerr (YY_NULL, wafsatname[wafsax]);
                  if (! (wafsasize <= wafsasize1
                         && wafsasize1 <= YYSTACK_ALLOC_MAXIMUM))
                    return 2;
                  wafsasize = wafsasize1;
                }
              }
        }
    }

  switch (wafsacount)
    {
# define YYCASE_(N, S)                      \
      case N:                               \
        wafsaformat = S;                       \
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
    YYSIZE_T wafsasize1 = wafsasize + wafsastrlen (wafsaformat);
    if (! (wafsasize <= wafsasize1 && wafsasize1 <= YYSTACK_ALLOC_MAXIMUM))
      return 2;
    wafsasize = wafsasize1;
  }

  if (*wafsamsg_alloc < wafsasize)
    {
      *wafsamsg_alloc = 2 * wafsasize;
      if (! (wafsasize <= *wafsamsg_alloc
             && *wafsamsg_alloc <= YYSTACK_ALLOC_MAXIMUM))
        *wafsamsg_alloc = YYSTACK_ALLOC_MAXIMUM;
      return 1;
    }

  /* Avoid sprintf, as that infringes on the user's name space.
     Don't have undefined behavior even if the translation
     produced a string with the wrong number of "%s"s.  */
  {
    char *wafsap = *wafsamsg;
    int wafsai = 0;
    while ((*wafsap = *wafsaformat) != '\0')
      if (*wafsap == '%' && wafsaformat[1] == 's' && wafsai < wafsacount)
        {
          wafsap += wafsatnamerr (wafsap, wafsaarg[wafsai++]);
          wafsaformat += 2;
        }
      else
        {
          wafsap++;
          wafsaformat++;
        }
  }
  return 0;
}
#endif /* YYERROR_VERBOSE */

/*-----------------------------------------------.
| Release the memory associated to this symbol.  |
`-----------------------------------------------*/

/*ARGSUSED*/
#if (defined __STDC__ || defined __C99__FUNC__ \
     || defined __cplusplus || defined _MSC_VER)
static void
wafsadestruct (const char *wafsamsg, int wafsatype, YYSTYPE *wafsavaluep)
#else
static void
wafsadestruct (wafsamsg, wafsatype, wafsavaluep)
    const char *wafsamsg;
    int wafsatype;
    YYSTYPE *wafsavaluep;
#endif
{
  YYUSE (wafsavaluep);

  if (!wafsamsg)
    wafsamsg = "Deleting";
  YY_SYMBOL_PRINT (wafsamsg, wafsatype, wafsavaluep, wafsalocationp);

  YYUSE (wafsatype);
}




/* The lookahead symbol.  */
int wafsachar;


#ifndef YY_IGNORE_MAYBE_UNINITIALIZED_BEGIN
# define YY_IGNORE_MAYBE_UNINITIALIZED_BEGIN
# define YY_IGNORE_MAYBE_UNINITIALIZED_END
#endif
#ifndef YY_INITIAL_VALUE
# define YY_INITIAL_VALUE(Value) /* Nothing. */
#endif

/* The semantic value of the lookahead symbol.  */
YYSTYPE wafsalval YY_INITIAL_VALUE(wafsaval_default);

/* Number of syntax errors so far.  */
int wafsanerrs;


/*----------.
| wafsaparse.  |
`----------*/

#ifdef YYPARSE_PARAM
#if (defined __STDC__ || defined __C99__FUNC__ \
     || defined __cplusplus || defined _MSC_VER)
int
wafsaparse (void *YYPARSE_PARAM)
#else
int
wafsaparse (YYPARSE_PARAM)
    void *YYPARSE_PARAM;
#endif
#else /* ! YYPARSE_PARAM */
#if (defined __STDC__ || defined __C99__FUNC__ \
     || defined __cplusplus || defined _MSC_VER)
int
wafsaparse (void)
#else
int
wafsaparse ()

#endif
#endif
{
    int wafsastate;
    /* Number of tokens to shift before error messages enabled.  */
    int wafsaerrstatus;

    /* The stacks and their tools:
       `wafsass': related to states.
       `wafsavs': related to semantic values.

       Refer to the stacks through separate pointers, to allow wafsaoverflow
       to reallocate them elsewhere.  */

    /* The state stack.  */
    wafsatype_int16 wafsassa[YYINITDEPTH];
    wafsatype_int16 *wafsass;
    wafsatype_int16 *wafsassp;

    /* The semantic value stack.  */
    YYSTYPE wafsavsa[YYINITDEPTH];
    YYSTYPE *wafsavs;
    YYSTYPE *wafsavsp;

    YYSIZE_T wafsastacksize;

  int wafsan;
  int wafsaresult;
  /* Lookahead token as an internal (translated) token number.  */
  int wafsatoken = 0;
  /* The variables used to return semantic value and location from the
     action routines.  */
  YYSTYPE wafsaval;

#if YYERROR_VERBOSE
  /* Buffer for error messages, and its allocated size.  */
  char wafsamsgbuf[128];
  char *wafsamsg = wafsamsgbuf;
  YYSIZE_T wafsamsg_alloc = sizeof wafsamsgbuf;
#endif

#define YYPOPSTACK(N)   (wafsavsp -= (N), wafsassp -= (N))

  /* The number of symbols on the RHS of the reduced rule.
     Keep to zero when no symbol should be popped.  */
  int wafsalen = 0;

  wafsassp = wafsass = wafsassa;
  wafsavsp = wafsavs = wafsavsa;
  wafsastacksize = YYINITDEPTH;

  YYDPRINTF ((stderr, "Starting parse\n"));

  wafsastate = 0;
  wafsaerrstatus = 0;
  wafsanerrs = 0;
  wafsachar = YYEMPTY; /* Cause a token to be read.  */
  goto wafsasetstate;

/*------------------------------------------------------------.
| wafsanewstate -- Push a new state, which is found in wafsastate.  |
`------------------------------------------------------------*/
 wafsanewstate:
  /* In all cases, when you get here, the value and location stacks
     have just been pushed.  So pushing a state here evens the stacks.  */
  wafsassp++;

 wafsasetstate:
  *wafsassp = wafsastate;

  if (wafsass + wafsastacksize - 1 <= wafsassp)
    {
      /* Get the current used size of the three stacks, in elements.  */
      YYSIZE_T wafsasize = wafsassp - wafsass + 1;

#ifdef wafsaoverflow
      {
	/* Give user a chance to reallocate the stack.  Use copies of
	   these so that the &'s don't force the real ones into
	   memory.  */
	YYSTYPE *wafsavs1 = wafsavs;
	wafsatype_int16 *wafsass1 = wafsass;

	/* Each stack pointer address is followed by the size of the
	   data in use in that stack, in bytes.  This used to be a
	   conditional around just the two extra args, but that might
	   be undefined if wafsaoverflow is a macro.  */
	wafsaoverflow (YY_("memory exhausted"),
		    &wafsass1, wafsasize * sizeof (*wafsassp),
		    &wafsavs1, wafsasize * sizeof (*wafsavsp),
		    &wafsastacksize);

	wafsass = wafsass1;
	wafsavs = wafsavs1;
      }
#else /* no wafsaoverflow */
# ifndef YYSTACK_RELOCATE
      goto wafsaexhaustedlab;
# else
      /* Extend the stack our own way.  */
      if (YYMAXDEPTH <= wafsastacksize)
	goto wafsaexhaustedlab;
      wafsastacksize *= 2;
      if (YYMAXDEPTH < wafsastacksize)
	wafsastacksize = YYMAXDEPTH;

      {
	wafsatype_int16 *wafsass1 = wafsass;
	union wafsaalloc *wafsaptr =
	  (union wafsaalloc *) YYSTACK_ALLOC (YYSTACK_BYTES (wafsastacksize));
	if (! wafsaptr)
	  goto wafsaexhaustedlab;
	YYSTACK_RELOCATE (wafsass_alloc, wafsass);
	YYSTACK_RELOCATE (wafsavs_alloc, wafsavs);
#  undef YYSTACK_RELOCATE
	if (wafsass1 != wafsassa)
	  YYSTACK_FREE (wafsass1);
      }
# endif
#endif /* no wafsaoverflow */

      wafsassp = wafsass + wafsasize - 1;
      wafsavsp = wafsavs + wafsasize - 1;

      YYDPRINTF ((stderr, "Stack size increased to %lu\n",
		  (unsigned long int) wafsastacksize));

      if (wafsass + wafsastacksize - 1 <= wafsassp)
	YYABORT;
    }

  YYDPRINTF ((stderr, "Entering state %d\n", wafsastate));

  if (wafsastate == YYFINAL)
    YYACCEPT;

  goto wafsabackup;

/*-----------.
| wafsabackup.  |
`-----------*/
wafsabackup:

  /* Do appropriate processing given the current state.  Read a
     lookahead token if we need one and don't already have one.  */

  /* First try to decide what to do without reference to lookahead token.  */
  wafsan = wafsapact[wafsastate];
  if (wafsapact_value_is_default (wafsan))
    goto wafsadefault;

  /* Not known => get a lookahead token if don't already have one.  */

  /* YYCHAR is either YYEMPTY or YYEOF or a valid lookahead symbol.  */
  if (wafsachar == YYEMPTY)
    {
      YYDPRINTF ((stderr, "Reading a token: "));
      wafsachar = YYLEX;
    }

  if (wafsachar <= YYEOF)
    {
      wafsachar = wafsatoken = YYEOF;
      YYDPRINTF ((stderr, "Now at end of input.\n"));
    }
  else
    {
      wafsatoken = YYTRANSLATE (wafsachar);
      YY_SYMBOL_PRINT ("Next token is", wafsatoken, &wafsalval, &wafsalloc);
    }

  /* If the proper action on seeing token YYTOKEN is to reduce or to
     detect an error, take that action.  */
  wafsan += wafsatoken;
  if (wafsan < 0 || YYLAST < wafsan || wafsacheck[wafsan] != wafsatoken)
    goto wafsadefault;
  wafsan = wafsatable[wafsan];
  if (wafsan <= 0)
    {
      if (wafsatable_value_is_error (wafsan))
        goto wafsaerrlab;
      wafsan = -wafsan;
      goto wafsareduce;
    }

  /* Count tokens shifted since error; after three, turn off error
     status.  */
  if (wafsaerrstatus)
    wafsaerrstatus--;

  /* Shift the lookahead token.  */
  YY_SYMBOL_PRINT ("Shifting", wafsatoken, &wafsalval, &wafsalloc);

  /* Discard the shifted token.  */
  wafsachar = YYEMPTY;

  wafsastate = wafsan;
  YY_IGNORE_MAYBE_UNINITIALIZED_BEGIN
  *++wafsavsp = wafsalval;
  YY_IGNORE_MAYBE_UNINITIALIZED_END

  goto wafsanewstate;


/*-----------------------------------------------------------.
| wafsadefault -- do the default action for the current state.  |
`-----------------------------------------------------------*/
wafsadefault:
  wafsan = wafsadefact[wafsastate];
  if (wafsan == 0)
    goto wafsaerrlab;
  goto wafsareduce;


/*-----------------------------.
| wafsareduce -- Do a reduction.  |
`-----------------------------*/
wafsareduce:
  /* wafsan is the number of a rule to reduce with.  */
  wafsalen = wafsar2[wafsan];

  /* If YYLEN is nonzero, implement the default value of the action:
     `$$ = $1'.

     Otherwise, the following line sets YYVAL to garbage.
     This behavior is undocumented and Bison
     users should not rely upon it.  Assigning to YYVAL
     unconditionally makes the parser a bit smaller, and it avoids a
     GCC warning that YYVAL may be used uninitialized.  */
  wafsaval = wafsavsp[1-wafsalen];


  YY_REDUCE_PRINT (wafsan);
  switch (wafsan)
    {
        case 3:
/* Line 1787 of yacc.c  */
#line 70 "../../../../../src/lib/oogl/wa/fsaparse.y"
    { return(0); }
    break;

  case 4:
/* Line 1787 of yacc.c  */
#line 74 "../../../../../src/lib/oogl/wa/fsaparse.y"
    {
		      fsa->nstates = (wafsavsp[(2) - (2)].i);
		      fsa->action =
			(int**)malloc((fsa->nstates+1)*sizeof(int*));
		    }
    break;

  case 5:
/* Line 1787 of yacc.c  */
#line 82 "../../../../../src/lib/oogl/wa/fsaparse.y"
    {
		      int i,j;
		      fsa->ngens = (wafsavsp[(2) - (2)].i);
		      for (i=0; i<=fsa->nstates; ++i) {
			fsa->action[i] =
			  (int*)malloc((fsa->ngens+1)*sizeof(int));
			for (j=0; j<=fsa->ngens; ++j)
			  fsa->action[i][j] = 0;
		      }
		      fsa->genlist=(char**)malloc(fsa->ngens*sizeof(char*));
		      for (i=0; i<fsa->ngens; ++i)
			fsa->genlist[i] = "";
		    }
    break;

  case 14:
/* Line 1787 of yacc.c  */
#line 116 "../../../../../src/lib/oogl/wa/fsaparse.y"
    {
		      fsa->start= (wafsavsp[(1) - (1)].i);
		    }
    break;

  case 18:
/* Line 1787 of yacc.c  */
#line 129 "../../../../../src/lib/oogl/wa/fsaparse.y"
    {
		      fsa->genlist[(wafsavsp[(1) - (3)].i)-1] =
			(char*)malloc((strlen((wafsavsp[(3) - (3)].s))+1)*sizeof(char));
		      strcpy(fsa->genlist[(wafsavsp[(1) - (3)].i)-1], (wafsavsp[(3) - (3)].s));
		    }
    break;

  case 19:
/* Line 1787 of yacc.c  */
#line 137 "../../../../../src/lib/oogl/wa/fsaparse.y"
    { (wafsaval.i) = (wafsavsp[(3) - (4)].i); }
    break;

  case 20:
/* Line 1787 of yacc.c  */
#line 139 "../../../../../src/lib/oogl/wa/fsaparse.y"
    { (wafsaval.i) = (wafsavsp[(3) - (5)].i); }
    break;

  case 27:
/* Line 1787 of yacc.c  */
#line 157 "../../../../../src/lib/oogl/wa/fsaparse.y"
    { install_adjacency((wafsavsp[(1) - (4)].i)); adj_index = 0; }
    break;

  case 28:
/* Line 1787 of yacc.c  */
#line 161 "../../../../../src/lib/oogl/wa/fsaparse.y"
    {
		    adj[adj_index++] = (wafsavsp[(1) - (1)].i);
		  }
    break;

  case 29:
/* Line 1787 of yacc.c  */
#line 165 "../../../../../src/lib/oogl/wa/fsaparse.y"
    {
		    adj[adj_index++] = (wafsavsp[(2) - (2)].i);
		  }
    break;


/* Line 1787 of yacc.c  */
#line 1525 "y.tab.c"
      default: break;
    }
  /* User semantic actions sometimes alter wafsachar, and that requires
     that wafsatoken be updated with the new translation.  We take the
     approach of translating immediately before every use of wafsatoken.
     One alternative is translating here after every semantic action,
     but that translation would be missed if the semantic action invokes
     YYABORT, YYACCEPT, or YYERROR immediately after altering wafsachar or
     if it invokes YYBACKUP.  In the case of YYABORT or YYACCEPT, an
     incorrect destructor might then be invoked immediately.  In the
     case of YYERROR or YYBACKUP, subsequent parser actions might lead
     to an incorrect destructor call or verbose syntax error message
     before the lookahead is translated.  */
  YY_SYMBOL_PRINT ("-> $$ =", wafsar1[wafsan], &wafsaval, &wafsaloc);

  YYPOPSTACK (wafsalen);
  wafsalen = 0;
  YY_STACK_PRINT (wafsass, wafsassp);

  *++wafsavsp = wafsaval;

  /* Now `shift' the result of the reduction.  Determine what state
     that goes to, based on the state we popped back to and the rule
     number reduced by.  */

  wafsan = wafsar1[wafsan];

  wafsastate = wafsapgoto[wafsan - YYNTOKENS] + *wafsassp;
  if (0 <= wafsastate && wafsastate <= YYLAST && wafsacheck[wafsastate] == *wafsassp)
    wafsastate = wafsatable[wafsastate];
  else
    wafsastate = wafsadefgoto[wafsan - YYNTOKENS];

  goto wafsanewstate;


/*------------------------------------.
| wafsaerrlab -- here on detecting error |
`------------------------------------*/
wafsaerrlab:
  /* Make sure we have latest lookahead translation.  See comments at
     user semantic actions for why this is necessary.  */
  wafsatoken = wafsachar == YYEMPTY ? YYEMPTY : YYTRANSLATE (wafsachar);

  /* If not already recovering from an error, report this error.  */
  if (!wafsaerrstatus)
    {
      ++wafsanerrs;
#if ! YYERROR_VERBOSE
      wafsaerror (YY_("syntax error"));
#else
# define YYSYNTAX_ERROR wafsasyntax_error (&wafsamsg_alloc, &wafsamsg, \
                                        wafsassp, wafsatoken)
      {
        char const *wafsamsgp = YY_("syntax error");
        int wafsasyntax_error_status;
        wafsasyntax_error_status = YYSYNTAX_ERROR;
        if (wafsasyntax_error_status == 0)
          wafsamsgp = wafsamsg;
        else if (wafsasyntax_error_status == 1)
          {
            if (wafsamsg != wafsamsgbuf)
              YYSTACK_FREE (wafsamsg);
            wafsamsg = (char *) YYSTACK_ALLOC (wafsamsg_alloc);
            if (!wafsamsg)
              {
                wafsamsg = wafsamsgbuf;
                wafsamsg_alloc = sizeof wafsamsgbuf;
                wafsasyntax_error_status = 2;
              }
            else
              {
                wafsasyntax_error_status = YYSYNTAX_ERROR;
                wafsamsgp = wafsamsg;
              }
          }
        wafsaerror (wafsamsgp);
        if (wafsasyntax_error_status == 2)
          goto wafsaexhaustedlab;
      }
# undef YYSYNTAX_ERROR
#endif
    }



  if (wafsaerrstatus == 3)
    {
      /* If just tried and failed to reuse lookahead token after an
	 error, discard it.  */

      if (wafsachar <= YYEOF)
	{
	  /* Return failure if at end of input.  */
	  if (wafsachar == YYEOF)
	    YYABORT;
	}
      else
	{
	  wafsadestruct ("Error: discarding",
		      wafsatoken, &wafsalval);
	  wafsachar = YYEMPTY;
	}
    }

  /* Else will try to reuse lookahead token after shifting the error
     token.  */
  goto wafsaerrlab1;


/*---------------------------------------------------.
| wafsaerrorlab -- error raised explicitly by YYERROR.  |
`---------------------------------------------------*/
wafsaerrorlab:

  /* Pacify compilers like GCC when the user code never invokes
     YYERROR and the label wafsaerrorlab therefore never appears in user
     code.  */
  if (/*CONSTCOND*/ 0)
     goto wafsaerrorlab;

  /* Do not reclaim the symbols of the rule which action triggered
     this YYERROR.  */
  YYPOPSTACK (wafsalen);
  wafsalen = 0;
  YY_STACK_PRINT (wafsass, wafsassp);
  wafsastate = *wafsassp;
  goto wafsaerrlab1;


/*-------------------------------------------------------------.
| wafsaerrlab1 -- common code for both syntax error and YYERROR.  |
`-------------------------------------------------------------*/
wafsaerrlab1:
  wafsaerrstatus = 3;	/* Each real token shifted decrements this.  */

  for (;;)
    {
      wafsan = wafsapact[wafsastate];
      if (!wafsapact_value_is_default (wafsan))
	{
	  wafsan += YYTERROR;
	  if (0 <= wafsan && wafsan <= YYLAST && wafsacheck[wafsan] == YYTERROR)
	    {
	      wafsan = wafsatable[wafsan];
	      if (0 < wafsan)
		break;
	    }
	}

      /* Pop the current state because it cannot handle the error token.  */
      if (wafsassp == wafsass)
	YYABORT;


      wafsadestruct ("Error: popping",
		  wafsastos[wafsastate], wafsavsp);
      YYPOPSTACK (1);
      wafsastate = *wafsassp;
      YY_STACK_PRINT (wafsass, wafsassp);
    }

  YY_IGNORE_MAYBE_UNINITIALIZED_BEGIN
  *++wafsavsp = wafsalval;
  YY_IGNORE_MAYBE_UNINITIALIZED_END


  /* Shift the error token.  */
  YY_SYMBOL_PRINT ("Shifting", wafsastos[wafsan], wafsavsp, wafsalsp);

  wafsastate = wafsan;
  goto wafsanewstate;


/*-------------------------------------.
| wafsaacceptlab -- YYACCEPT comes here.  |
`-------------------------------------*/
wafsaacceptlab:
  wafsaresult = 0;
  goto wafsareturn;

/*-----------------------------------.
| wafsaabortlab -- YYABORT comes here.  |
`-----------------------------------*/
wafsaabortlab:
  wafsaresult = 1;
  goto wafsareturn;

#if !defined wafsaoverflow || YYERROR_VERBOSE
/*-------------------------------------------------.
| wafsaexhaustedlab -- memory exhaustion comes here.  |
`-------------------------------------------------*/
wafsaexhaustedlab:
  wafsaerror (YY_("memory exhausted"));
  wafsaresult = 2;
  /* Fall through.  */
#endif

wafsareturn:
  if (wafsachar != YYEMPTY)
    {
      /* Make sure we have latest lookahead translation.  See comments at
         user semantic actions for why this is necessary.  */
      wafsatoken = YYTRANSLATE (wafsachar);
      wafsadestruct ("Cleanup: discarding lookahead",
                  wafsatoken, &wafsalval);
    }
  /* Do not reclaim the symbols of the rule which action triggered
     this YYABORT or YYACCEPT.  */
  YYPOPSTACK (wafsalen);
  YY_STACK_PRINT (wafsass, wafsassp);
  while (wafsassp != wafsass)
    {
      wafsadestruct ("Cleanup: popping",
		  wafsastos[*wafsassp], wafsavsp);
      YYPOPSTACK (1);
    }
#ifndef wafsaoverflow
  if (wafsass != wafsassa)
    YYSTACK_FREE (wafsass);
#endif
#if YYERROR_VERBOSE
  if (wafsamsg != wafsamsgbuf)
    YYSTACK_FREE (wafsamsg);
#endif
  /* Make sure YYID is used.  */
  return YYID (wafsaresult);
}


/* Line 2050 of yacc.c  */
#line 171 "../../../../../src/lib/oogl/wa/fsaparse.y"


static void wafsaerror(char *s)
{
  printf("wafsaerror: %s\n", s);
}

static void
  install_adjacency(n)
int n;
{
  int i;

  for (i=0; i<adj_index; ++i)
    fsa->action[n][i+1] = adj[i];
}

void
parse_init(f)
     wa *f;
{
  fsa = f;

  fsa->fail = fsa->state = 0;
}

/*-----------------------------------------------------------------------
 * Function:	fsaparse
 * Description:	parse a .wa file into an wa struct
 * Args  IN:	fp: .wa file pointer
 *      OUT:	*fsa: the resulting fsa struct
 * Returns:	1 for success, 0 for error
 * Author:	mbp
 * Date:	Sat Mar 23 21:47:04 1991
 * Notes:	Does not recognize the full grammar defined by
 *		"Data Exchange for Automatic Groups".  Only recognizes
 *		files of the form used by several examples I was
 *		using at the time I wrote this.  I think, but am not
 *		at all sure, that this includes all word-acceptor
 *		automata.
 */
int
  fsaparse(fp, fsa)
FILE *fp;
wa *fsa;
{
  extern FILE *wafsain;
  int ret;

  parse_init(fsa);

  wafsain = fp;
  ret = wafsaparse();

  return(ret ==0);
}
