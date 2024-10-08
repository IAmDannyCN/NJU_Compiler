/* A Bison parser, made by GNU Bison 3.8.2.  */

/* Bison implementation for Yacc-like parsers in C

   Copyright (C) 1984, 1989-1990, 2000-2015, 2018-2021 Free Software Foundation,
   Inc.

   This program is free software: you can redistribute it and/or modify
   it under the terms of the GNU General Public License as published by
   the Free Software Foundation, either version 3 of the License, or
   (at your option) any later version.

   This program is distributed in the hope that it will be useful,
   but WITHOUT ANY WARRANTY; without even the implied warranty of
   MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
   GNU General Public License for more details.

   You should have received a copy of the GNU General Public License
   along with this program.  If not, see <https://www.gnu.org/licenses/>.  */

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

/* DO NOT RELY ON FEATURES THAT ARE NOT DOCUMENTED in the manual,
   especially those whose name start with YY_ or yy_.  They are
   private implementation details that can be changed or removed.  */

/* All symbols defined below should begin with yy or YY, to avoid
   infringing on user name space.  This should be done even for local
   variables, as they might otherwise be expanded by user macros.
   There are some unavoidable exceptions within include files to
   define necessary library symbols; they are noted "INFRINGES ON
   USER NAME SPACE" below.  */

/* Identify Bison output, and Bison version.  */
#define YYBISON 30802

/* Bison version string.  */
#define YYBISON_VERSION "3.8.2"

/* Skeleton name.  */
#define YYSKELETON_NAME "yacc.c"

/* Pure parsers.  */
#define YYPURE 0

/* Push parsers.  */
#define YYPUSH 0

/* Pull parsers.  */
#define YYPULL 1




/* First part of user prologue.  */
#line 1 "./syntax.y"

    #include <stdio.h>
    #include "syntaxtree.h"
    #include "lex.yy.c"
    int syntax_error = 0;
    extern Node* root;
    #define bug printf("bug %d\n", __LINE__)

    // #define YYDEBUG 1

    int yylex();
    int yyerror(char *);

#line 85 "./syntax.tab.c"

# ifndef YY_CAST
#  ifdef __cplusplus
#   define YY_CAST(Type, Val) static_cast<Type> (Val)
#   define YY_REINTERPRET_CAST(Type, Val) reinterpret_cast<Type> (Val)
#  else
#   define YY_CAST(Type, Val) ((Type) (Val))
#   define YY_REINTERPRET_CAST(Type, Val) ((Type) (Val))
#  endif
# endif
# ifndef YY_NULLPTR
#  if defined __cplusplus
#   if 201103L <= __cplusplus
#    define YY_NULLPTR nullptr
#   else
#    define YY_NULLPTR 0
#   endif
#  else
#   define YY_NULLPTR ((void*)0)
#  endif
# endif

#include "syntax.tab.h"
/* Symbol kind.  */
enum yysymbol_kind_t
{
  YYSYMBOL_YYEMPTY = -2,
  YYSYMBOL_YYEOF = 0,                      /* "end of file"  */
  YYSYMBOL_YYerror = 1,                    /* error  */
  YYSYMBOL_YYUNDEF = 2,                    /* "invalid token"  */
  YYSYMBOL_INT = 3,                        /* INT  */
  YYSYMBOL_FLOAT = 4,                      /* FLOAT  */
  YYSYMBOL_ID = 5,                         /* ID  */
  YYSYMBOL_SEMI = 6,                       /* SEMI  */
  YYSYMBOL_COMMA = 7,                      /* COMMA  */
  YYSYMBOL_ASSIGNOP = 8,                   /* ASSIGNOP  */
  YYSYMBOL_RELOP = 9,                      /* RELOP  */
  YYSYMBOL_PLUS = 10,                      /* PLUS  */
  YYSYMBOL_MINUS = 11,                     /* MINUS  */
  YYSYMBOL_STAR = 12,                      /* STAR  */
  YYSYMBOL_DIV = 13,                       /* DIV  */
  YYSYMBOL_AND = 14,                       /* AND  */
  YYSYMBOL_OR = 15,                        /* OR  */
  YYSYMBOL_DOT = 16,                       /* DOT  */
  YYSYMBOL_NOT = 17,                       /* NOT  */
  YYSYMBOL_TYPE = 18,                      /* TYPE  */
  YYSYMBOL_LP = 19,                        /* LP  */
  YYSYMBOL_RP = 20,                        /* RP  */
  YYSYMBOL_LB = 21,                        /* LB  */
  YYSYMBOL_RB = 22,                        /* RB  */
  YYSYMBOL_LC = 23,                        /* LC  */
  YYSYMBOL_RC = 24,                        /* RC  */
  YYSYMBOL_STRUCT = 25,                    /* STRUCT  */
  YYSYMBOL_RETURN = 26,                    /* RETURN  */
  YYSYMBOL_IF = 27,                        /* IF  */
  YYSYMBOL_ELSE = 28,                      /* ELSE  */
  YYSYMBOL_WHILE = 29,                     /* WHILE  */
  YYSYMBOL_SPACE = 30,                     /* SPACE  */
  YYSYMBOL_NLINE = 31,                     /* NLINE  */
  YYSYMBOL_LOWER_THAN_ELSE = 32,           /* LOWER_THAN_ELSE  */
  YYSYMBOL_YYACCEPT = 33,                  /* $accept  */
  YYSYMBOL_Program = 34,                   /* Program  */
  YYSYMBOL_ExtDefList = 35,                /* ExtDefList  */
  YYSYMBOL_ExtDef = 36,                    /* ExtDef  */
  YYSYMBOL_ExtDecList = 37,                /* ExtDecList  */
  YYSYMBOL_Specifier = 38,                 /* Specifier  */
  YYSYMBOL_StructSpecifier = 39,           /* StructSpecifier  */
  YYSYMBOL_OptTag = 40,                    /* OptTag  */
  YYSYMBOL_Tag = 41,                       /* Tag  */
  YYSYMBOL_VarDec = 42,                    /* VarDec  */
  YYSYMBOL_FunDec = 43,                    /* FunDec  */
  YYSYMBOL_VarList = 44,                   /* VarList  */
  YYSYMBOL_ParamDec = 45,                  /* ParamDec  */
  YYSYMBOL_CompSt = 46,                    /* CompSt  */
  YYSYMBOL_StmtList = 47,                  /* StmtList  */
  YYSYMBOL_Stmt = 48,                      /* Stmt  */
  YYSYMBOL_DefList = 49,                   /* DefList  */
  YYSYMBOL_Def = 50,                       /* Def  */
  YYSYMBOL_DecList = 51,                   /* DecList  */
  YYSYMBOL_Dec = 52,                       /* Dec  */
  YYSYMBOL_Exp = 53,                       /* Exp  */
  YYSYMBOL_Args = 54                       /* Args  */
};
typedef enum yysymbol_kind_t yysymbol_kind_t;




#ifdef short
# undef short
#endif

/* On compilers that do not define __PTRDIFF_MAX__ etc., make sure
   <limits.h> and (if available) <stdint.h> are included
   so that the code can choose integer types of a good width.  */

#ifndef __PTRDIFF_MAX__
# include <limits.h> /* INFRINGES ON USER NAME SPACE */
# if defined __STDC_VERSION__ && 199901 <= __STDC_VERSION__
#  include <stdint.h> /* INFRINGES ON USER NAME SPACE */
#  define YY_STDINT_H
# endif
#endif

/* Narrow types that promote to a signed type and that can represent a
   signed or unsigned integer of at least N bits.  In tables they can
   save space and decrease cache pressure.  Promoting to a signed type
   helps avoid bugs in integer arithmetic.  */

#ifdef __INT_LEAST8_MAX__
typedef __INT_LEAST8_TYPE__ yytype_int8;
#elif defined YY_STDINT_H
typedef int_least8_t yytype_int8;
#else
typedef signed char yytype_int8;
#endif

#ifdef __INT_LEAST16_MAX__
typedef __INT_LEAST16_TYPE__ yytype_int16;
#elif defined YY_STDINT_H
typedef int_least16_t yytype_int16;
#else
typedef short yytype_int16;
#endif

/* Work around bug in HP-UX 11.23, which defines these macros
   incorrectly for preprocessor constants.  This workaround can likely
   be removed in 2023, as HPE has promised support for HP-UX 11.23
   (aka HP-UX 11i v2) only through the end of 2022; see Table 2 of
   <https://h20195.www2.hpe.com/V2/getpdf.aspx/4AA4-7673ENW.pdf>.  */
#ifdef __hpux
# undef UINT_LEAST8_MAX
# undef UINT_LEAST16_MAX
# define UINT_LEAST8_MAX 255
# define UINT_LEAST16_MAX 65535
#endif

#if defined __UINT_LEAST8_MAX__ && __UINT_LEAST8_MAX__ <= __INT_MAX__
typedef __UINT_LEAST8_TYPE__ yytype_uint8;
#elif (!defined __UINT_LEAST8_MAX__ && defined YY_STDINT_H \
       && UINT_LEAST8_MAX <= INT_MAX)
typedef uint_least8_t yytype_uint8;
#elif !defined __UINT_LEAST8_MAX__ && UCHAR_MAX <= INT_MAX
typedef unsigned char yytype_uint8;
#else
typedef short yytype_uint8;
#endif

#if defined __UINT_LEAST16_MAX__ && __UINT_LEAST16_MAX__ <= __INT_MAX__
typedef __UINT_LEAST16_TYPE__ yytype_uint16;
#elif (!defined __UINT_LEAST16_MAX__ && defined YY_STDINT_H \
       && UINT_LEAST16_MAX <= INT_MAX)
typedef uint_least16_t yytype_uint16;
#elif !defined __UINT_LEAST16_MAX__ && USHRT_MAX <= INT_MAX
typedef unsigned short yytype_uint16;
#else
typedef int yytype_uint16;
#endif

#ifndef YYPTRDIFF_T
# if defined __PTRDIFF_TYPE__ && defined __PTRDIFF_MAX__
#  define YYPTRDIFF_T __PTRDIFF_TYPE__
#  define YYPTRDIFF_MAXIMUM __PTRDIFF_MAX__
# elif defined PTRDIFF_MAX
#  ifndef ptrdiff_t
#   include <stddef.h> /* INFRINGES ON USER NAME SPACE */
#  endif
#  define YYPTRDIFF_T ptrdiff_t
#  define YYPTRDIFF_MAXIMUM PTRDIFF_MAX
# else
#  define YYPTRDIFF_T long
#  define YYPTRDIFF_MAXIMUM LONG_MAX
# endif
#endif

#ifndef YYSIZE_T
# ifdef __SIZE_TYPE__
#  define YYSIZE_T __SIZE_TYPE__
# elif defined size_t
#  define YYSIZE_T size_t
# elif defined __STDC_VERSION__ && 199901 <= __STDC_VERSION__
#  include <stddef.h> /* INFRINGES ON USER NAME SPACE */
#  define YYSIZE_T size_t
# else
#  define YYSIZE_T unsigned
# endif
#endif

#define YYSIZE_MAXIMUM                                  \
  YY_CAST (YYPTRDIFF_T,                                 \
           (YYPTRDIFF_MAXIMUM < YY_CAST (YYSIZE_T, -1)  \
            ? YYPTRDIFF_MAXIMUM                         \
            : YY_CAST (YYSIZE_T, -1)))

#define YYSIZEOF(X) YY_CAST (YYPTRDIFF_T, sizeof (X))


/* Stored state numbers (used for stacks). */
typedef yytype_uint8 yy_state_t;

/* State numbers in computations.  */
typedef int yy_state_fast_t;

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


#ifndef YY_ATTRIBUTE_PURE
# if defined __GNUC__ && 2 < __GNUC__ + (96 <= __GNUC_MINOR__)
#  define YY_ATTRIBUTE_PURE __attribute__ ((__pure__))
# else
#  define YY_ATTRIBUTE_PURE
# endif
#endif

#ifndef YY_ATTRIBUTE_UNUSED
# if defined __GNUC__ && 2 < __GNUC__ + (7 <= __GNUC_MINOR__)
#  define YY_ATTRIBUTE_UNUSED __attribute__ ((__unused__))
# else
#  define YY_ATTRIBUTE_UNUSED
# endif
#endif

/* Suppress unused-variable warnings by "using" E.  */
#if ! defined lint || defined __GNUC__
# define YY_USE(E) ((void) (E))
#else
# define YY_USE(E) /* empty */
#endif

/* Suppress an incorrect diagnostic about yylval being uninitialized.  */
#if defined __GNUC__ && ! defined __ICC && 406 <= __GNUC__ * 100 + __GNUC_MINOR__
# if __GNUC__ * 100 + __GNUC_MINOR__ < 407
#  define YY_IGNORE_MAYBE_UNINITIALIZED_BEGIN                           \
    _Pragma ("GCC diagnostic push")                                     \
    _Pragma ("GCC diagnostic ignored \"-Wuninitialized\"")
# else
#  define YY_IGNORE_MAYBE_UNINITIALIZED_BEGIN                           \
    _Pragma ("GCC diagnostic push")                                     \
    _Pragma ("GCC diagnostic ignored \"-Wuninitialized\"")              \
    _Pragma ("GCC diagnostic ignored \"-Wmaybe-uninitialized\"")
# endif
# define YY_IGNORE_MAYBE_UNINITIALIZED_END      \
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

#if defined __cplusplus && defined __GNUC__ && ! defined __ICC && 6 <= __GNUC__
# define YY_IGNORE_USELESS_CAST_BEGIN                          \
    _Pragma ("GCC diagnostic push")                            \
    _Pragma ("GCC diagnostic ignored \"-Wuseless-cast\"")
# define YY_IGNORE_USELESS_CAST_END            \
    _Pragma ("GCC diagnostic pop")
#endif
#ifndef YY_IGNORE_USELESS_CAST_BEGIN
# define YY_IGNORE_USELESS_CAST_BEGIN
# define YY_IGNORE_USELESS_CAST_END
#endif


#define YY_ASSERT(E) ((void) (0 && (E)))

#if !defined yyoverflow

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
#endif /* !defined yyoverflow */

#if (! defined yyoverflow \
     && (! defined __cplusplus \
         || (defined YYLTYPE_IS_TRIVIAL && YYLTYPE_IS_TRIVIAL \
             && defined YYSTYPE_IS_TRIVIAL && YYSTYPE_IS_TRIVIAL)))

/* A type that is properly aligned for any stack member.  */
union yyalloc
{
  yy_state_t yyss_alloc;
  YYSTYPE yyvs_alloc;
  YYLTYPE yyls_alloc;
};

/* The size of the maximum gap between one aligned stack and the next.  */
# define YYSTACK_GAP_MAXIMUM (YYSIZEOF (union yyalloc) - 1)

/* The size of an array large to enough to hold all stacks, each with
   N elements.  */
# define YYSTACK_BYTES(N) \
     ((N) * (YYSIZEOF (yy_state_t) + YYSIZEOF (YYSTYPE) \
             + YYSIZEOF (YYLTYPE)) \
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
        YYPTRDIFF_T yynewbytes;                                         \
        YYCOPY (&yyptr->Stack_alloc, Stack, yysize);                    \
        Stack = &yyptr->Stack_alloc;                                    \
        yynewbytes = yystacksize * YYSIZEOF (*Stack) + YYSTACK_GAP_MAXIMUM; \
        yyptr += yynewbytes / YYSIZEOF (*yyptr);                        \
      }                                                                 \
    while (0)

#endif

#if defined YYCOPY_NEEDED && YYCOPY_NEEDED
/* Copy COUNT objects from SRC to DST.  The source and destination do
   not overlap.  */
# ifndef YYCOPY
#  if defined __GNUC__ && 1 < __GNUC__
#   define YYCOPY(Dst, Src, Count) \
      __builtin_memcpy (Dst, Src, YY_CAST (YYSIZE_T, (Count)) * sizeof (*(Src)))
#  else
#   define YYCOPY(Dst, Src, Count)              \
      do                                        \
        {                                       \
          YYPTRDIFF_T yyi;                      \
          for (yyi = 0; yyi < (Count); yyi++)   \
            (Dst)[yyi] = (Src)[yyi];            \
        }                                       \
      while (0)
#  endif
# endif
#endif /* !YYCOPY_NEEDED */

/* YYFINAL -- State number of the termination state.  */
#define YYFINAL  13
/* YYLAST -- Last index in YYTABLE.  */
#define YYLAST   413

/* YYNTOKENS -- Number of terminals.  */
#define YYNTOKENS  33
/* YYNNTS -- Number of nonterminals.  */
#define YYNNTS  22
/* YYNRULES -- Number of rules.  */
#define YYNRULES  92
/* YYNSTATES -- Number of states.  */
#define YYNSTATES  160

/* YYMAXUTOK -- Last valid token kind.  */
#define YYMAXUTOK   287


/* YYTRANSLATE(TOKEN-NUM) -- Symbol number corresponding to TOKEN-NUM
   as returned by yylex, with out-of-bounds checking.  */
#define YYTRANSLATE(YYX)                                \
  (0 <= (YYX) && (YYX) <= YYMAXUTOK                     \
   ? YY_CAST (yysymbol_kind_t, yytranslate[YYX])        \
   : YYSYMBOL_YYUNDEF)

/* YYTRANSLATE[TOKEN-NUM] -- Symbol number corresponding to TOKEN-NUM
   as returned by yylex.  */
static const yytype_int8 yytranslate[] =
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
      25,    26,    27,    28,    29,    30,    31,    32
};

#if YYDEBUG
/* YYRLINE[YYN] -- Source line where rule number YYN was defined.  */
static const yytype_uint8 yyrline[] =
{
       0,    36,    36,    39,    40,    43,    44,    45,    46,    47,
      50,    51,    52,    53,    54,    57,    58,    61,    62,    63,
      66,    67,    70,    73,    74,    75,    76,    80,    81,    82,
      83,    86,    87,    88,    91,    94,    95,    98,    99,   102,
     103,   104,   105,   106,   107,   108,   109,   110,   111,   115,
     116,   119,   120,   123,   124,   125,   126,   129,   130,   131,
     134,   135,   136,   137,   138,   139,   140,   141,   142,   143,
     144,   145,   146,   147,   148,   149,   150,   151,   155,   156,
     157,   158,   159,   160,   161,   162,   163,   164,   165,   166,
     167,   170,   171
};
#endif

/** Accessing symbol of state STATE.  */
#define YY_ACCESSING_SYMBOL(State) YY_CAST (yysymbol_kind_t, yystos[State])

#if YYDEBUG || 0
/* The user-facing name of the symbol whose (internal) number is
   YYSYMBOL.  No bounds checking.  */
static const char *yysymbol_name (yysymbol_kind_t yysymbol) YY_ATTRIBUTE_UNUSED;

/* YYTNAME[SYMBOL-NUM] -- String name of the symbol SYMBOL-NUM.
   First, the terminals, then, starting at YYNTOKENS, nonterminals.  */
static const char *const yytname[] =
{
  "\"end of file\"", "error", "\"invalid token\"", "INT", "FLOAT", "ID",
  "SEMI", "COMMA", "ASSIGNOP", "RELOP", "PLUS", "MINUS", "STAR", "DIV",
  "AND", "OR", "DOT", "NOT", "TYPE", "LP", "RP", "LB", "RB", "LC", "RC",
  "STRUCT", "RETURN", "IF", "ELSE", "WHILE", "SPACE", "NLINE",
  "LOWER_THAN_ELSE", "$accept", "Program", "ExtDefList", "ExtDef",
  "ExtDecList", "Specifier", "StructSpecifier", "OptTag", "Tag", "VarDec",
  "FunDec", "VarList", "ParamDec", "CompSt", "StmtList", "Stmt", "DefList",
  "Def", "DecList", "Dec", "Exp", "Args", YY_NULLPTR
};

static const char *
yysymbol_name (yysymbol_kind_t yysymbol)
{
  return yytname[yysymbol];
}
#endif

#define YYPACT_NINF (-139)

#define yypact_value_is_default(Yyn) \
  ((Yyn) == YYPACT_NINF)

#define YYTABLE_NINF (-54)

#define yytable_value_is_error(Yyn) \
  0

/* YYPACT[STATE-NUM] -- Index in YYTABLE of the portion describing
   STATE-NUM.  */
static const yytype_int16 yypact[] =
{
       7,    17,  -139,    67,    80,  -139,     7,    83,  -139,  -139,
      59,   106,  -139,  -139,  -139,    36,    95,  -139,    93,    91,
       3,    61,    14,    28,    76,  -139,   404,    14,    60,   119,
      -8,  -139,   120,   112,   123,    -8,   143,  -139,  -139,   157,
     160,   146,   162,     2,  -139,   152,  -139,  -139,   149,   158,
    -139,    47,  -139,   179,    39,   180,   135,  -139,  -139,    28,
     166,  -139,    28,  -139,  -139,  -139,  -139,    25,  -139,  -139,
     169,   134,   151,   156,   173,   172,   174,  -139,   170,    47,
      94,  -139,   178,  -139,   160,   160,  -139,  -139,  -139,   129,
    -139,   280,  -139,     0,   182,   328,   201,   110,   286,   286,
    -139,  -139,  -139,  -139,   195,   200,   217,   222,   239,   244,
     261,   266,   203,   283,  -139,   370,  -139,  -139,   189,  -139,
     299,   190,  -139,  -139,  -139,  -139,  -139,   342,   356,  -139,
     370,  -139,   390,  -139,   280,  -139,   280,  -139,     0,  -139,
       0,  -139,   383,  -139,   383,  -139,   191,   313,  -139,   286,
    -139,    64,    64,  -139,  -139,  -139,   187,  -139,    64,  -139
};

/* YYDEFACT[STATE-NUM] -- Default reduction number in state STATE-NUM.
   Performed when YYTABLE does not specify something else to do.  Zero
   means the default is an error.  */
static const yytype_int8 yydefact[] =
{
       0,     0,    15,    21,     0,     2,     0,     0,    16,     8,
      22,     0,    18,     1,     3,     9,    23,     6,     0,     0,
       0,     0,     0,     0,     0,     5,     0,     0,     0,     0,
      50,     7,     0,     0,     0,    50,     0,    23,    14,     0,
       0,     0,    32,     0,    28,     0,    12,    11,    26,     0,
      36,     0,    19,     0,    57,     0,     0,    17,    49,     0,
      34,    29,     0,    30,    27,    25,    24,     0,    76,    77,
      75,     0,     0,     0,     0,     0,     0,    40,     0,     0,
       0,    52,     0,    51,    56,     0,    33,    31,    47,     0,
      87,    69,    88,    70,     0,     0,     0,     0,     0,     0,
      35,    37,    45,    39,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,    59,    58,    55,    54,     0,    72,
      92,     0,    86,    68,    48,    46,    41,     0,     0,    78,
      60,    81,    63,    82,    64,    83,    65,    84,    66,    85,
      67,    79,    61,    80,    62,    74,     0,     0,    89,     0,
      71,     0,     0,    90,    73,    91,    42,    44,     0,    43
};

/* YYPGOTO[NTERM-NUM].  */
static const yytype_int16 yypgoto[] =
{
    -139,  -139,   210,  -139,   386,    24,  -139,  -139,  -139,   -28,
    -139,   -18,  -139,   204,   150,  -138,   128,  -139,    43,  -139,
     -71,    81
};

/* YYDEFGOTO[NTERM-NUM].  */
static const yytype_int8 yydefgoto[] =
{
       0,     4,     5,     6,    18,    40,     8,    11,    12,    19,
      20,    41,    42,    77,    78,    79,    34,    35,    55,    56,
      80,   121
};

/* YYTABLE[YYPACT[STATE-NUM]] -- What to do in state STATE-NUM.  If
   positive, shift that token.  If negative, reduce the rule whose
   number is the opposite.  If YYTABLE_NINF, syntax error.  */
static const yytype_int16 yytable[] =
{
      91,    93,    95,    97,    29,    54,    45,    -4,     1,    59,
       2,   115,    60,   156,   157,    36,   112,     3,   120,    37,
     159,   113,    63,     9,     7,     2,    30,   127,   128,    39,
       7,    88,     3,   130,   132,   134,   136,   138,   140,   142,
     144,    86,   147,    22,    87,    33,     2,    82,    67,    50,
      68,    69,    70,     3,    33,    23,    54,    54,    71,    33,
      28,    48,    32,    49,    72,    67,    73,    68,    69,    70,
      30,   -38,    10,    74,    75,    71,    76,    43,   120,     2,
      13,    72,   -20,    73,    15,   -50,     3,    30,    16,    17,
      74,    75,    26,    76,     2,   102,    44,   -10,    27,    25,
     103,     3,   104,   105,   106,   107,   108,   109,   110,   111,
     112,   125,    28,    53,    24,   113,   126,    37,   104,   105,
     106,   107,   108,   109,   110,   111,   112,   116,   117,    21,
     118,   113,    68,    69,    70,    90,    84,    68,    69,    70,
      71,   -53,    85,    50,    52,    71,    72,    57,    73,   119,
      22,    72,    92,    73,    68,    69,    70,    94,    51,    68,
      69,    70,    71,    58,    59,    37,    61,    71,    72,    62,
      73,    65,    64,    72,    96,    73,    68,    69,    70,   114,
      66,    68,    69,    70,    71,    81,    83,    28,    89,    71,
      72,    98,    73,    99,   100,    72,   129,    73,    68,    69,
      70,   131,   122,    68,    69,    70,    71,   124,   145,   148,
     150,    71,    72,   153,    73,   158,    14,    72,   133,    73,
      68,    69,    70,   135,    31,    68,    69,    70,    71,   101,
     155,     0,     0,    71,    72,     0,    73,     0,     0,    72,
     137,    73,    68,    69,    70,   139,     0,    68,    69,    70,
      71,     0,     0,     0,     0,    71,    72,     0,    73,     0,
       0,    72,   141,    73,    68,    69,    70,   143,     0,    68,
      69,    70,    71,     0,     0,     0,     0,    71,    72,     0,
      73,     0,     0,    72,   146,    73,    68,    69,    70,    68,
      69,    70,   108,   109,    71,     0,   112,    71,     0,     0,
      72,   113,    73,    72,     0,    73,   149,   104,   105,   106,
     107,   108,   109,   110,   111,   112,     0,     0,     0,     0,
     113,   104,   105,   106,   107,   108,   109,   110,   111,   112,
       0,     0,     0,     0,   113,   154,   104,   105,   106,   107,
     108,   109,   110,   111,   112,     0,     0,     0,   123,   113,
     104,   105,   106,   107,   108,   109,   110,   111,   112,     0,
       0,     0,   151,   113,   104,   105,   106,   107,   108,   109,
     110,   111,   112,     0,     0,     0,   152,   113,   104,   105,
     106,   107,   108,   109,   110,   111,   112,     0,     0,     0,
       0,   113,   105,   106,   107,   108,   109,     0,     0,   112,
     106,   107,   108,   109,   113,    36,   112,     0,    38,    37,
     -13,   113,    46,    47
};

static const yytype_int16 yycheck[] =
{
      71,    72,    73,    74,     1,    33,    24,     0,     1,     7,
      18,    82,    40,   151,   152,     1,    16,    25,    89,     5,
     158,    21,    20,     6,     0,    18,    23,    98,    99,     1,
       6,     6,    25,   104,   105,   106,   107,   108,   109,   110,
     111,    59,   113,     7,    62,    21,    18,     8,     1,    24,
       3,     4,     5,    25,    30,    19,    84,    85,    11,    35,
      21,     1,     1,     3,    17,     1,    19,     3,     4,     5,
      23,    24,     5,    26,    27,    11,    29,     1,   149,    18,
       0,    17,    23,    19,     1,    24,    25,    23,     5,     6,
      26,    27,     1,    29,    18,     1,    20,     6,     7,     6,
       6,    25,     8,     9,    10,    11,    12,    13,    14,    15,
      16,     1,    21,     1,    19,    21,     6,     5,     8,     9,
      10,    11,    12,    13,    14,    15,    16,    84,    85,    23,
       1,    21,     3,     4,     5,     1,     1,     3,     4,     5,
      11,     6,     7,    24,    24,    11,    17,    24,    19,    20,
       7,    17,     1,    19,     3,     4,     5,     1,    30,     3,
       4,     5,    11,    35,     7,     5,    20,    11,    17,     7,
      19,    22,    20,    17,     1,    19,     3,     4,     5,     1,
      22,     3,     4,     5,    11,     6,     6,    21,    19,    11,
      17,    19,    19,    19,    24,    17,     1,    19,     3,     4,
       5,     1,    20,     3,     4,     5,    11,     6,     5,    20,
      20,    11,    17,    22,    19,    28,     6,    17,     1,    19,
       3,     4,     5,     1,    20,     3,     4,     5,    11,    79,
     149,    -1,    -1,    11,    17,    -1,    19,    -1,    -1,    17,
       1,    19,     3,     4,     5,     1,    -1,     3,     4,     5,
      11,    -1,    -1,    -1,    -1,    11,    17,    -1,    19,    -1,
      -1,    17,     1,    19,     3,     4,     5,     1,    -1,     3,
       4,     5,    11,    -1,    -1,    -1,    -1,    11,    17,    -1,
      19,    -1,    -1,    17,     1,    19,     3,     4,     5,     3,
       4,     5,    12,    13,    11,    -1,    16,    11,    -1,    -1,
      17,    21,    19,    17,    -1,    19,     7,     8,     9,    10,
      11,    12,    13,    14,    15,    16,    -1,    -1,    -1,    -1,
      21,     8,     9,    10,    11,    12,    13,    14,    15,    16,
      -1,    -1,    -1,    -1,    21,    22,     8,     9,    10,    11,
      12,    13,    14,    15,    16,    -1,    -1,    -1,    20,    21,
       8,     9,    10,    11,    12,    13,    14,    15,    16,    -1,
      -1,    -1,    20,    21,     8,     9,    10,    11,    12,    13,
      14,    15,    16,    -1,    -1,    -1,    20,    21,     8,     9,
      10,    11,    12,    13,    14,    15,    16,    -1,    -1,    -1,
      -1,    21,     9,    10,    11,    12,    13,    -1,    -1,    16,
      10,    11,    12,    13,    21,     1,    16,    -1,    22,     5,
       6,    21,    26,    27
};

/* YYSTOS[STATE-NUM] -- The symbol kind of the accessing symbol of
   state STATE-NUM.  */
static const yytype_int8 yystos[] =
{
       0,     1,    18,    25,    34,    35,    36,    38,    39,     6,
       5,    40,    41,     0,    35,     1,     5,     6,    37,    42,
      43,    23,     7,    19,    19,     6,     1,     7,    21,     1,
      23,    46,     1,    38,    49,    50,     1,     5,    37,     1,
      38,    44,    45,     1,    20,    44,    37,    37,     1,     3,
      24,    49,    24,     1,    42,    51,    52,    24,    49,     7,
      42,    20,     7,    20,    20,    22,    22,     1,     3,     4,
       5,    11,    17,    19,    26,    27,    29,    46,    47,    48,
      53,     6,     8,     6,     1,     7,    44,    44,     6,    19,
       1,    53,     1,    53,     1,    53,     1,    53,    19,    19,
      24,    47,     1,     6,     8,     9,    10,    11,    12,    13,
      14,    15,    16,    21,     1,    53,    51,    51,     1,    20,
      53,    54,    20,    20,     6,     1,     6,    53,    53,     1,
      53,     1,    53,     1,    53,     1,    53,     1,    53,     1,
      53,     1,    53,     1,    53,     5,     1,    53,    20,     7,
      20,    20,    20,    22,    22,    54,    48,    48,    28,    48
};

/* YYR1[RULE-NUM] -- Symbol kind of the left-hand side of rule RULE-NUM.  */
static const yytype_int8 yyr1[] =
{
       0,    33,    34,    35,    35,    36,    36,    36,    36,    36,
      37,    37,    37,    37,    37,    38,    38,    39,    39,    39,
      40,    40,    41,    42,    42,    42,    42,    43,    43,    43,
      43,    44,    44,    44,    45,    46,    46,    47,    47,    48,
      48,    48,    48,    48,    48,    48,    48,    48,    48,    49,
      49,    50,    50,    51,    51,    51,    51,    52,    52,    52,
      53,    53,    53,    53,    53,    53,    53,    53,    53,    53,
      53,    53,    53,    53,    53,    53,    53,    53,    53,    53,
      53,    53,    53,    53,    53,    53,    53,    53,    53,    53,
      53,    54,    54
};

/* YYR2[RULE-NUM] -- Number of symbols on the right-hand side of rule RULE-NUM.  */
static const yytype_int8 yyr2[] =
{
       0,     2,     1,     2,     0,     3,     2,     3,     2,     2,
       1,     3,     3,     2,     3,     1,     1,     5,     2,     5,
       1,     0,     1,     1,     4,     4,     3,     4,     3,     4,
       4,     3,     1,     3,     2,     4,     2,     2,     0,     2,
       1,     3,     5,     7,     5,     2,     3,     2,     3,     2,
       0,     3,     3,     1,     3,     3,     2,     1,     3,     3,
       3,     3,     3,     3,     3,     3,     3,     3,     3,     2,
       2,     4,     3,     4,     3,     1,     1,     1,     3,     3,
       3,     3,     3,     3,     3,     3,     3,     2,     2,     4,
       4,     3,     1
};


enum { YYENOMEM = -2 };

#define yyerrok         (yyerrstatus = 0)
#define yyclearin       (yychar = YYEMPTY)

#define YYACCEPT        goto yyacceptlab
#define YYABORT         goto yyabortlab
#define YYERROR         goto yyerrorlab
#define YYNOMEM         goto yyexhaustedlab


#define YYRECOVERING()  (!!yyerrstatus)

#define YYBACKUP(Token, Value)                                    \
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

/* Backward compatibility with an undocumented macro.
   Use YYerror or YYUNDEF. */
#define YYERRCODE YYUNDEF

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


/* YYLOCATION_PRINT -- Print the location on the stream.
   This macro was not mandated originally: define only if we know
   we won't break user code: when these are the locations we know.  */

# ifndef YYLOCATION_PRINT

#  if defined YY_LOCATION_PRINT

   /* Temporary convenience wrapper in case some people defined the
      undocumented and private YY_LOCATION_PRINT macros.  */
#   define YYLOCATION_PRINT(File, Loc)  YY_LOCATION_PRINT(File, *(Loc))

#  elif defined YYLTYPE_IS_TRIVIAL && YYLTYPE_IS_TRIVIAL

/* Print *YYLOCP on YYO.  Private, do not rely on its existence. */

YY_ATTRIBUTE_UNUSED
static int
yy_location_print_ (FILE *yyo, YYLTYPE const * const yylocp)
{
  int res = 0;
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

#   define YYLOCATION_PRINT  yy_location_print_

    /* Temporary convenience wrapper in case some people defined the
       undocumented and private YY_LOCATION_PRINT macros.  */
#   define YY_LOCATION_PRINT(File, Loc)  YYLOCATION_PRINT(File, &(Loc))

#  else

#   define YYLOCATION_PRINT(File, Loc) ((void) 0)
    /* Temporary convenience wrapper in case some people defined the
       undocumented and private YY_LOCATION_PRINT macros.  */
#   define YY_LOCATION_PRINT  YYLOCATION_PRINT

#  endif
# endif /* !defined YYLOCATION_PRINT */


# define YY_SYMBOL_PRINT(Title, Kind, Value, Location)                    \
do {                                                                      \
  if (yydebug)                                                            \
    {                                                                     \
      YYFPRINTF (stderr, "%s ", Title);                                   \
      yy_symbol_print (stderr,                                            \
                  Kind, Value, Location); \
      YYFPRINTF (stderr, "\n");                                           \
    }                                                                     \
} while (0)


/*-----------------------------------.
| Print this symbol's value on YYO.  |
`-----------------------------------*/

static void
yy_symbol_value_print (FILE *yyo,
                       yysymbol_kind_t yykind, YYSTYPE const * const yyvaluep, YYLTYPE const * const yylocationp)
{
  FILE *yyoutput = yyo;
  YY_USE (yyoutput);
  YY_USE (yylocationp);
  if (!yyvaluep)
    return;
  YY_IGNORE_MAYBE_UNINITIALIZED_BEGIN
  YY_USE (yykind);
  YY_IGNORE_MAYBE_UNINITIALIZED_END
}


/*---------------------------.
| Print this symbol on YYO.  |
`---------------------------*/

static void
yy_symbol_print (FILE *yyo,
                 yysymbol_kind_t yykind, YYSTYPE const * const yyvaluep, YYLTYPE const * const yylocationp)
{
  YYFPRINTF (yyo, "%s %s (",
             yykind < YYNTOKENS ? "token" : "nterm", yysymbol_name (yykind));

  YYLOCATION_PRINT (yyo, yylocationp);
  YYFPRINTF (yyo, ": ");
  yy_symbol_value_print (yyo, yykind, yyvaluep, yylocationp);
  YYFPRINTF (yyo, ")");
}

/*------------------------------------------------------------------.
| yy_stack_print -- Print the state stack from its BOTTOM up to its |
| TOP (included).                                                   |
`------------------------------------------------------------------*/

static void
yy_stack_print (yy_state_t *yybottom, yy_state_t *yytop)
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
yy_reduce_print (yy_state_t *yyssp, YYSTYPE *yyvsp, YYLTYPE *yylsp,
                 int yyrule)
{
  int yylno = yyrline[yyrule];
  int yynrhs = yyr2[yyrule];
  int yyi;
  YYFPRINTF (stderr, "Reducing stack by rule %d (line %d):\n",
             yyrule - 1, yylno);
  /* The symbols being reduced.  */
  for (yyi = 0; yyi < yynrhs; yyi++)
    {
      YYFPRINTF (stderr, "   $%d = ", yyi + 1);
      yy_symbol_print (stderr,
                       YY_ACCESSING_SYMBOL (+yyssp[yyi + 1 - yynrhs]),
                       &yyvsp[(yyi + 1) - (yynrhs)],
                       &(yylsp[(yyi + 1) - (yynrhs)]));
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
# define YYDPRINTF(Args) ((void) 0)
# define YY_SYMBOL_PRINT(Title, Kind, Value, Location)
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






/*-----------------------------------------------.
| Release the memory associated to this symbol.  |
`-----------------------------------------------*/

static void
yydestruct (const char *yymsg,
            yysymbol_kind_t yykind, YYSTYPE *yyvaluep, YYLTYPE *yylocationp)
{
  YY_USE (yyvaluep);
  YY_USE (yylocationp);
  if (!yymsg)
    yymsg = "Deleting";
  YY_SYMBOL_PRINT (yymsg, yykind, yyvaluep, yylocationp);

  YY_IGNORE_MAYBE_UNINITIALIZED_BEGIN
  YY_USE (yykind);
  YY_IGNORE_MAYBE_UNINITIALIZED_END
}


/* Lookahead token kind.  */
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
    yy_state_fast_t yystate = 0;
    /* Number of tokens to shift before error messages enabled.  */
    int yyerrstatus = 0;

    /* Refer to the stacks through separate pointers, to allow yyoverflow
       to reallocate them elsewhere.  */

    /* Their size.  */
    YYPTRDIFF_T yystacksize = YYINITDEPTH;

    /* The state stack: array, bottom, top.  */
    yy_state_t yyssa[YYINITDEPTH];
    yy_state_t *yyss = yyssa;
    yy_state_t *yyssp = yyss;

    /* The semantic value stack: array, bottom, top.  */
    YYSTYPE yyvsa[YYINITDEPTH];
    YYSTYPE *yyvs = yyvsa;
    YYSTYPE *yyvsp = yyvs;

    /* The location stack: array, bottom, top.  */
    YYLTYPE yylsa[YYINITDEPTH];
    YYLTYPE *yyls = yylsa;
    YYLTYPE *yylsp = yyls;

  int yyn;
  /* The return value of yyparse.  */
  int yyresult;
  /* Lookahead symbol kind.  */
  yysymbol_kind_t yytoken = YYSYMBOL_YYEMPTY;
  /* The variables used to return semantic value and location from the
     action routines.  */
  YYSTYPE yyval;
  YYLTYPE yyloc;

  /* The locations where the error started and ended.  */
  YYLTYPE yyerror_range[3];



#define YYPOPSTACK(N)   (yyvsp -= (N), yyssp -= (N), yylsp -= (N))

  /* The number of symbols on the RHS of the reduced rule.
     Keep to zero when no symbol should be popped.  */
  int yylen = 0;

  YYDPRINTF ((stderr, "Starting parse\n"));

  yychar = YYEMPTY; /* Cause a token to be read.  */

  yylsp[0] = yylloc;
  goto yysetstate;


/*------------------------------------------------------------.
| yynewstate -- push a new state, which is found in yystate.  |
`------------------------------------------------------------*/
yynewstate:
  /* In all cases, when you get here, the value and location stacks
     have just been pushed.  So pushing a state here evens the stacks.  */
  yyssp++;


/*--------------------------------------------------------------------.
| yysetstate -- set current state (the top of the stack) to yystate.  |
`--------------------------------------------------------------------*/
yysetstate:
  YYDPRINTF ((stderr, "Entering state %d\n", yystate));
  YY_ASSERT (0 <= yystate && yystate < YYNSTATES);
  YY_IGNORE_USELESS_CAST_BEGIN
  *yyssp = YY_CAST (yy_state_t, yystate);
  YY_IGNORE_USELESS_CAST_END
  YY_STACK_PRINT (yyss, yyssp);

  if (yyss + yystacksize - 1 <= yyssp)
#if !defined yyoverflow && !defined YYSTACK_RELOCATE
    YYNOMEM;
#else
    {
      /* Get the current used size of the three stacks, in elements.  */
      YYPTRDIFF_T yysize = yyssp - yyss + 1;

# if defined yyoverflow
      {
        /* Give user a chance to reallocate the stack.  Use copies of
           these so that the &'s don't force the real ones into
           memory.  */
        yy_state_t *yyss1 = yyss;
        YYSTYPE *yyvs1 = yyvs;
        YYLTYPE *yyls1 = yyls;

        /* Each stack pointer address is followed by the size of the
           data in use in that stack, in bytes.  This used to be a
           conditional around just the two extra args, but that might
           be undefined if yyoverflow is a macro.  */
        yyoverflow (YY_("memory exhausted"),
                    &yyss1, yysize * YYSIZEOF (*yyssp),
                    &yyvs1, yysize * YYSIZEOF (*yyvsp),
                    &yyls1, yysize * YYSIZEOF (*yylsp),
                    &yystacksize);
        yyss = yyss1;
        yyvs = yyvs1;
        yyls = yyls1;
      }
# else /* defined YYSTACK_RELOCATE */
      /* Extend the stack our own way.  */
      if (YYMAXDEPTH <= yystacksize)
        YYNOMEM;
      yystacksize *= 2;
      if (YYMAXDEPTH < yystacksize)
        yystacksize = YYMAXDEPTH;

      {
        yy_state_t *yyss1 = yyss;
        union yyalloc *yyptr =
          YY_CAST (union yyalloc *,
                   YYSTACK_ALLOC (YY_CAST (YYSIZE_T, YYSTACK_BYTES (yystacksize))));
        if (! yyptr)
          YYNOMEM;
        YYSTACK_RELOCATE (yyss_alloc, yyss);
        YYSTACK_RELOCATE (yyvs_alloc, yyvs);
        YYSTACK_RELOCATE (yyls_alloc, yyls);
#  undef YYSTACK_RELOCATE
        if (yyss1 != yyssa)
          YYSTACK_FREE (yyss1);
      }
# endif

      yyssp = yyss + yysize - 1;
      yyvsp = yyvs + yysize - 1;
      yylsp = yyls + yysize - 1;

      YY_IGNORE_USELESS_CAST_BEGIN
      YYDPRINTF ((stderr, "Stack size increased to %ld\n",
                  YY_CAST (long, yystacksize)));
      YY_IGNORE_USELESS_CAST_END

      if (yyss + yystacksize - 1 <= yyssp)
        YYABORT;
    }
#endif /* !defined yyoverflow && !defined YYSTACK_RELOCATE */


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

  /* YYCHAR is either empty, or end-of-input, or a valid lookahead.  */
  if (yychar == YYEMPTY)
    {
      YYDPRINTF ((stderr, "Reading a token\n"));
      yychar = yylex ();
    }

  if (yychar <= YYEOF)
    {
      yychar = YYEOF;
      yytoken = YYSYMBOL_YYEOF;
      YYDPRINTF ((stderr, "Now at end of input.\n"));
    }
  else if (yychar == YYerror)
    {
      /* The scanner already issued an error message, process directly
         to error recovery.  But do not keep the error token as
         lookahead, it is too special and may lead us to an endless
         loop in error recovery. */
      yychar = YYUNDEF;
      yytoken = YYSYMBOL_YYerror;
      yyerror_range[1] = yylloc;
      goto yyerrlab1;
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
  yystate = yyn;
  YY_IGNORE_MAYBE_UNINITIALIZED_BEGIN
  *++yyvsp = yylval;
  YY_IGNORE_MAYBE_UNINITIALIZED_END
  *++yylsp = yylloc;

  /* Discard the shifted token.  */
  yychar = YYEMPTY;
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
| yyreduce -- do a reduction.  |
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

  /* Default location. */
  YYLLOC_DEFAULT (yyloc, (yylsp - yylen), yylen);
  yyerror_range[1] = yyloc;
  YY_REDUCE_PRINT (yyn);
  switch (yyn)
    {
  case 2: /* Program: ExtDefList  */
#line 36 "./syntax.y"
                     { (yyval.type_node) = Constructor("Program", "\0", TYPE_NONTERMINAL, (yyloc).first_line); BuildSon((yyval.type_node), 1, (yyvsp[0].type_node)); SetRoot((yyval.type_node)); }
#line 1395 "./syntax.tab.c"
    break;

  case 3: /* ExtDefList: ExtDef ExtDefList  */
#line 39 "./syntax.y"
                               { (yyval.type_node) = Constructor("ExtDefList", "\0", TYPE_NONTERMINAL, (yyloc).first_line); BuildSon((yyval.type_node), 2, (yyvsp[-1].type_node), (yyvsp[0].type_node)); }
#line 1401 "./syntax.tab.c"
    break;

  case 4: /* ExtDefList: %empty  */
#line 40 "./syntax.y"
                  { (yyval.type_node) = NULL; }
#line 1407 "./syntax.tab.c"
    break;

  case 5: /* ExtDef: Specifier ExtDecList SEMI  */
#line 43 "./syntax.y"
                                   { (yyval.type_node) = Constructor("ExtDef", "\0", TYPE_NONTERMINAL, (yyloc).first_line); BuildSon((yyval.type_node), 3, (yyvsp[-2].type_node), (yyvsp[-1].type_node), (yyvsp[0].type_node)); }
#line 1413 "./syntax.tab.c"
    break;

  case 6: /* ExtDef: Specifier SEMI  */
#line 44 "./syntax.y"
                     { (yyval.type_node) = Constructor("ExtDef", "\0", TYPE_NONTERMINAL, (yyloc).first_line); BuildSon((yyval.type_node), 2, (yyvsp[-1].type_node), (yyvsp[0].type_node)); }
#line 1419 "./syntax.tab.c"
    break;

  case 7: /* ExtDef: Specifier FunDec CompSt  */
#line 45 "./syntax.y"
                             { (yyval.type_node) = Constructor("ExtDef", "\0", TYPE_NONTERMINAL, (yyloc).first_line); BuildSon((yyval.type_node), 3, (yyvsp[-2].type_node), (yyvsp[-1].type_node), (yyvsp[0].type_node)); }
#line 1425 "./syntax.tab.c"
    break;

  case 8: /* ExtDef: error SEMI  */
#line 46 "./syntax.y"
                 { (yyval.type_node) = NULL; syntax_error = 1; }
#line 1431 "./syntax.tab.c"
    break;

  case 9: /* ExtDef: Specifier error  */
#line 47 "./syntax.y"
                       { (yyval.type_node) = NULL; syntax_error = 1; }
#line 1437 "./syntax.tab.c"
    break;

  case 10: /* ExtDecList: VarDec  */
#line 50 "./syntax.y"
                    { (yyval.type_node) = Constructor("ExtDecList", "\0", TYPE_NONTERMINAL, (yyloc).first_line); BuildSon((yyval.type_node), 1, (yyvsp[0].type_node)); }
#line 1443 "./syntax.tab.c"
    break;

  case 11: /* ExtDecList: VarDec COMMA ExtDecList  */
#line 51 "./syntax.y"
                              { (yyval.type_node) = Constructor("ExtDecList", "\0", TYPE_NONTERMINAL, (yyloc).first_line); BuildSon((yyval.type_node), 3, (yyvsp[-2].type_node), (yyvsp[-1].type_node), (yyvsp[0].type_node)); }
#line 1449 "./syntax.tab.c"
    break;

  case 12: /* ExtDecList: VarDec error ExtDecList  */
#line 52 "./syntax.y"
                              { (yyval.type_node) = NULL; syntax_error = 1; }
#line 1455 "./syntax.tab.c"
    break;

  case 13: /* ExtDecList: VarDec error  */
#line 53 "./syntax.y"
                   { (yyval.type_node) = NULL; syntax_error = 1; }
#line 1461 "./syntax.tab.c"
    break;

  case 14: /* ExtDecList: error COMMA ExtDecList  */
#line 54 "./syntax.y"
                             { (yyval.type_node) = NULL; syntax_error = 1; }
#line 1467 "./syntax.tab.c"
    break;

  case 15: /* Specifier: TYPE  */
#line 57 "./syntax.y"
                 { (yyval.type_node) = Constructor("Specifier", "\0", TYPE_NONTERMINAL, (yyloc).first_line); BuildSon((yyval.type_node), 1, (yyvsp[0].type_node)); }
#line 1473 "./syntax.tab.c"
    break;

  case 16: /* Specifier: StructSpecifier  */
#line 58 "./syntax.y"
                      { (yyval.type_node) = Constructor("Specifier", "\0", TYPE_NONTERMINAL, (yyloc).first_line); BuildSon((yyval.type_node), 1, (yyvsp[0].type_node)); }
#line 1479 "./syntax.tab.c"
    break;

  case 17: /* StructSpecifier: STRUCT OptTag LC DefList RC  */
#line 61 "./syntax.y"
                                              { (yyval.type_node) = Constructor("StructSpecifier", "\0", TYPE_NONTERMINAL, (yyloc).first_line); BuildSon((yyval.type_node), 5, (yyvsp[-4].type_node), (yyvsp[-3].type_node), (yyvsp[-2].type_node), (yyvsp[-1].type_node), (yyvsp[0].type_node)); }
#line 1485 "./syntax.tab.c"
    break;

  case 18: /* StructSpecifier: STRUCT Tag  */
#line 62 "./syntax.y"
                 { (yyval.type_node) = Constructor("StructSpecifier", "\0", TYPE_NONTERMINAL, (yyloc).first_line); BuildSon((yyval.type_node), 2, (yyvsp[-1].type_node), (yyvsp[0].type_node)); }
#line 1491 "./syntax.tab.c"
    break;

  case 19: /* StructSpecifier: STRUCT OptTag LC error RC  */
#line 63 "./syntax.y"
                                { (yyval.type_node) = NULL; syntax_error = 1; }
#line 1497 "./syntax.tab.c"
    break;

  case 20: /* OptTag: ID  */
#line 66 "./syntax.y"
            { (yyval.type_node) = Constructor("OptTag", "\0", TYPE_NONTERMINAL, (yyloc).first_line); BuildSon((yyval.type_node), 1, (yyvsp[0].type_node)); }
#line 1503 "./syntax.tab.c"
    break;

  case 21: /* OptTag: %empty  */
#line 67 "./syntax.y"
                  { (yyval.type_node) = NULL; }
#line 1509 "./syntax.tab.c"
    break;

  case 22: /* Tag: ID  */
#line 70 "./syntax.y"
         { (yyval.type_node) = Constructor("Tag", "\0", TYPE_NONTERMINAL, (yyloc).first_line); BuildSon((yyval.type_node), 1, (yyvsp[0].type_node)); }
#line 1515 "./syntax.tab.c"
    break;

  case 23: /* VarDec: ID  */
#line 73 "./syntax.y"
            { (yyval.type_node) = Constructor("VarDec", "\0", TYPE_NONTERMINAL, (yyloc).first_line); BuildSon((yyval.type_node), 1, (yyvsp[0].type_node)); }
#line 1521 "./syntax.tab.c"
    break;

  case 24: /* VarDec: VarDec LB INT RB  */
#line 74 "./syntax.y"
                       { (yyval.type_node) = Constructor("VarDec", "\0", TYPE_NONTERMINAL, (yyloc).first_line); BuildSon((yyval.type_node), 4, (yyvsp[-3].type_node), (yyvsp[-2].type_node), (yyvsp[-1].type_node), (yyvsp[0].type_node)); }
#line 1527 "./syntax.tab.c"
    break;

  case 25: /* VarDec: VarDec LB error RB  */
#line 75 "./syntax.y"
                         { (yyval.type_node) = NULL; syntax_error = 1; }
#line 1533 "./syntax.tab.c"
    break;

  case 26: /* VarDec: VarDec LB error  */
#line 76 "./syntax.y"
                      { (yyval.type_node) = NULL; syntax_error = 1; }
#line 1539 "./syntax.tab.c"
    break;

  case 27: /* FunDec: ID LP VarList RP  */
#line 80 "./syntax.y"
                          { (yyval.type_node) = Constructor("FunDec", "\0", TYPE_NONTERMINAL, (yyloc).first_line); BuildSon((yyval.type_node), 4, (yyvsp[-3].type_node), (yyvsp[-2].type_node), (yyvsp[-1].type_node), (yyvsp[0].type_node)); }
#line 1545 "./syntax.tab.c"
    break;

  case 28: /* FunDec: ID LP RP  */
#line 81 "./syntax.y"
               { (yyval.type_node) = Constructor("FunDec", "\0", TYPE_NONTERMINAL, (yyloc).first_line); BuildSon((yyval.type_node), 3, (yyvsp[-2].type_node), (yyvsp[-1].type_node), (yyvsp[0].type_node)); }
#line 1551 "./syntax.tab.c"
    break;

  case 29: /* FunDec: error LP VarList RP  */
#line 82 "./syntax.y"
                          { (yyval.type_node) = NULL; syntax_error = 1; }
#line 1557 "./syntax.tab.c"
    break;

  case 30: /* FunDec: ID LP error RP  */
#line 83 "./syntax.y"
                     { (yyval.type_node) = NULL; syntax_error = 1; }
#line 1563 "./syntax.tab.c"
    break;

  case 31: /* VarList: ParamDec COMMA VarList  */
#line 86 "./syntax.y"
                                 { (yyval.type_node) = Constructor("VarList", "\0", TYPE_NONTERMINAL, (yyloc).first_line); BuildSon((yyval.type_node), 3, (yyvsp[-2].type_node), (yyvsp[-1].type_node), (yyvsp[0].type_node)); }
#line 1569 "./syntax.tab.c"
    break;

  case 32: /* VarList: ParamDec  */
#line 87 "./syntax.y"
               { (yyval.type_node) = Constructor("VarList", "\0", TYPE_NONTERMINAL, (yyloc).first_line); BuildSon((yyval.type_node), 1, (yyvsp[0].type_node)); }
#line 1575 "./syntax.tab.c"
    break;

  case 33: /* VarList: error COMMA VarList  */
#line 88 "./syntax.y"
                          { (yyval.type_node) = NULL; syntax_error = 1; }
#line 1581 "./syntax.tab.c"
    break;

  case 34: /* ParamDec: Specifier VarDec  */
#line 91 "./syntax.y"
                            { (yyval.type_node) = Constructor("ParamDec", "\0", TYPE_NONTERMINAL, (yyloc).first_line); BuildSon((yyval.type_node), 2, (yyvsp[-1].type_node), (yyvsp[0].type_node)); }
#line 1587 "./syntax.tab.c"
    break;

  case 35: /* CompSt: LC DefList StmtList RC  */
#line 94 "./syntax.y"
                                { (yyval.type_node) = Constructor("CompSt", "\0", TYPE_NONTERMINAL, (yyloc).first_line); BuildSon((yyval.type_node), 4, (yyvsp[-3].type_node), (yyvsp[-2].type_node), (yyvsp[-1].type_node), (yyvsp[0].type_node)); }
#line 1593 "./syntax.tab.c"
    break;

  case 36: /* CompSt: error RC  */
#line 95 "./syntax.y"
               { (yyval.type_node) = NULL; syntax_error = 1; }
#line 1599 "./syntax.tab.c"
    break;

  case 37: /* StmtList: Stmt StmtList  */
#line 98 "./syntax.y"
                         { (yyval.type_node) = Constructor("StmtList", "\0", TYPE_NONTERMINAL, (yyloc).first_line); BuildSon((yyval.type_node), 2, (yyvsp[-1].type_node), (yyvsp[0].type_node)); }
#line 1605 "./syntax.tab.c"
    break;

  case 38: /* StmtList: %empty  */
#line 99 "./syntax.y"
                  { (yyval.type_node) = NULL; }
#line 1611 "./syntax.tab.c"
    break;

  case 39: /* Stmt: Exp SEMI  */
#line 102 "./syntax.y"
                { (yyval.type_node) = Constructor("Stmt", "\0", TYPE_NONTERMINAL, (yyloc).first_line); BuildSon((yyval.type_node), 2, (yyvsp[-1].type_node), (yyvsp[0].type_node)); }
#line 1617 "./syntax.tab.c"
    break;

  case 40: /* Stmt: CompSt  */
#line 103 "./syntax.y"
             { (yyval.type_node) = Constructor("Stmt", "\0", TYPE_NONTERMINAL, (yyloc).first_line); BuildSon((yyval.type_node), 1, (yyvsp[0].type_node)); }
#line 1623 "./syntax.tab.c"
    break;

  case 41: /* Stmt: RETURN Exp SEMI  */
#line 104 "./syntax.y"
                      { (yyval.type_node) = Constructor("Stmt", "\0", TYPE_NONTERMINAL, (yyloc).first_line); BuildSon((yyval.type_node), 3, (yyvsp[-2].type_node), (yyvsp[-1].type_node), (yyvsp[0].type_node)); }
#line 1629 "./syntax.tab.c"
    break;

  case 42: /* Stmt: IF LP Exp RP Stmt  */
#line 105 "./syntax.y"
                                              { (yyval.type_node) = Constructor("Stmt", "\0", TYPE_NONTERMINAL, (yyloc).first_line); BuildSon((yyval.type_node), 5, (yyvsp[-4].type_node), (yyvsp[-3].type_node), (yyvsp[-2].type_node), (yyvsp[-1].type_node), (yyvsp[0].type_node)); }
#line 1635 "./syntax.tab.c"
    break;

  case 43: /* Stmt: IF LP Exp RP Stmt ELSE Stmt  */
#line 106 "./syntax.y"
                                  { (yyval.type_node) = Constructor("Stmt", "\0", TYPE_NONTERMINAL, (yyloc).first_line); BuildSon((yyval.type_node), 7, (yyvsp[-6].type_node), (yyvsp[-5].type_node), (yyvsp[-4].type_node), (yyvsp[-3].type_node), (yyvsp[-2].type_node), (yyvsp[-1].type_node), (yyvsp[0].type_node)); }
#line 1641 "./syntax.tab.c"
    break;

  case 44: /* Stmt: WHILE LP Exp RP Stmt  */
#line 107 "./syntax.y"
                           { (yyval.type_node) = Constructor("Stmt", "\0", TYPE_NONTERMINAL, (yyloc).first_line); BuildSon((yyval.type_node), 5, (yyvsp[-4].type_node), (yyvsp[-3].type_node), (yyvsp[-2].type_node), (yyvsp[-1].type_node), (yyvsp[0].type_node)); }
#line 1647 "./syntax.tab.c"
    break;

  case 45: /* Stmt: Exp error  */
#line 108 "./syntax.y"
                { (yyval.type_node) = NULL; syntax_error = 1; }
#line 1653 "./syntax.tab.c"
    break;

  case 46: /* Stmt: RETURN Exp error  */
#line 109 "./syntax.y"
                       { (yyval.type_node) = NULL; syntax_error = 1; }
#line 1659 "./syntax.tab.c"
    break;

  case 47: /* Stmt: error SEMI  */
#line 110 "./syntax.y"
                 { (yyval.type_node) = NULL; syntax_error = 1; }
#line 1665 "./syntax.tab.c"
    break;

  case 48: /* Stmt: RETURN error SEMI  */
#line 111 "./syntax.y"
                        { (yyval.type_node) = NULL; syntax_error = 1; }
#line 1671 "./syntax.tab.c"
    break;

  case 49: /* DefList: Def DefList  */
#line 115 "./syntax.y"
                      { (yyval.type_node) = Constructor("DefList", "\0", TYPE_NONTERMINAL, (yyloc).first_line); BuildSon((yyval.type_node), 2, (yyvsp[-1].type_node), (yyvsp[0].type_node)); }
#line 1677 "./syntax.tab.c"
    break;

  case 50: /* DefList: %empty  */
#line 116 "./syntax.y"
                  { (yyval.type_node) = NULL; }
#line 1683 "./syntax.tab.c"
    break;

  case 51: /* Def: Specifier DecList SEMI  */
#line 119 "./syntax.y"
                             { (yyval.type_node) = Constructor("Def", "\0", TYPE_NONTERMINAL, (yyloc).first_line); BuildSon((yyval.type_node), 3, (yyvsp[-2].type_node), (yyvsp[-1].type_node), (yyvsp[0].type_node)); }
#line 1689 "./syntax.tab.c"
    break;

  case 52: /* Def: Specifier error SEMI  */
#line 120 "./syntax.y"
                           { (yyval.type_node) = NULL; syntax_error = 1; }
#line 1695 "./syntax.tab.c"
    break;

  case 53: /* DecList: Dec  */
#line 123 "./syntax.y"
              { (yyval.type_node) = Constructor("DecList", "\0", TYPE_NONTERMINAL, (yyloc).first_line); BuildSon((yyval.type_node), 1, (yyvsp[0].type_node)); }
#line 1701 "./syntax.tab.c"
    break;

  case 54: /* DecList: Dec COMMA DecList  */
#line 124 "./syntax.y"
                        { (yyval.type_node) = Constructor("DecList", "\0", TYPE_NONTERMINAL, (yyloc).first_line); BuildSon((yyval.type_node), 3, (yyvsp[-2].type_node), (yyvsp[-1].type_node), (yyvsp[0].type_node)); }
#line 1707 "./syntax.tab.c"
    break;

  case 55: /* DecList: Dec error DecList  */
#line 125 "./syntax.y"
                        { (yyval.type_node) = NULL; syntax_error = 1; }
#line 1713 "./syntax.tab.c"
    break;

  case 56: /* DecList: Dec error  */
#line 126 "./syntax.y"
                { (yyval.type_node) = NULL; syntax_error = 1; }
#line 1719 "./syntax.tab.c"
    break;

  case 57: /* Dec: VarDec  */
#line 129 "./syntax.y"
             { (yyval.type_node) = Constructor("Dec", "\0", TYPE_NONTERMINAL, (yyloc).first_line); BuildSon((yyval.type_node), 1, (yyvsp[0].type_node)); }
#line 1725 "./syntax.tab.c"
    break;

  case 58: /* Dec: VarDec ASSIGNOP Exp  */
#line 130 "./syntax.y"
                          { (yyval.type_node) = Constructor("Dec", "\0", TYPE_NONTERMINAL, (yyloc).first_line); BuildSon((yyval.type_node), 3, (yyvsp[-2].type_node), (yyvsp[-1].type_node), (yyvsp[0].type_node)); }
#line 1731 "./syntax.tab.c"
    break;

  case 59: /* Dec: VarDec ASSIGNOP error  */
#line 131 "./syntax.y"
                            { (yyval.type_node) = NULL; syntax_error = 1; }
#line 1737 "./syntax.tab.c"
    break;

  case 60: /* Exp: Exp ASSIGNOP Exp  */
#line 134 "./syntax.y"
                       { (yyval.type_node) = Constructor("Exp", "\0", TYPE_NONTERMINAL, (yyloc).first_line); BuildSon((yyval.type_node), 3, (yyvsp[-2].type_node), (yyvsp[-1].type_node), (yyvsp[0].type_node)); }
#line 1743 "./syntax.tab.c"
    break;

  case 61: /* Exp: Exp AND Exp  */
#line 135 "./syntax.y"
                  { (yyval.type_node) = Constructor("Exp", "\0", TYPE_NONTERMINAL, (yyloc).first_line); BuildSon((yyval.type_node), 3, (yyvsp[-2].type_node), (yyvsp[-1].type_node), (yyvsp[0].type_node)); }
#line 1749 "./syntax.tab.c"
    break;

  case 62: /* Exp: Exp OR Exp  */
#line 136 "./syntax.y"
                 { (yyval.type_node) = Constructor("Exp", "\0", TYPE_NONTERMINAL, (yyloc).first_line); BuildSon((yyval.type_node), 3, (yyvsp[-2].type_node), (yyvsp[-1].type_node), (yyvsp[0].type_node)); }
#line 1755 "./syntax.tab.c"
    break;

  case 63: /* Exp: Exp RELOP Exp  */
#line 137 "./syntax.y"
                    { (yyval.type_node) = Constructor("Exp", "\0", TYPE_NONTERMINAL, (yyloc).first_line); BuildSon((yyval.type_node), 3, (yyvsp[-2].type_node), (yyvsp[-1].type_node), (yyvsp[0].type_node)); }
#line 1761 "./syntax.tab.c"
    break;

  case 64: /* Exp: Exp PLUS Exp  */
#line 138 "./syntax.y"
                   { (yyval.type_node) = Constructor("Exp", "\0", TYPE_NONTERMINAL, (yyloc).first_line); BuildSon((yyval.type_node), 3, (yyvsp[-2].type_node), (yyvsp[-1].type_node), (yyvsp[0].type_node)); }
#line 1767 "./syntax.tab.c"
    break;

  case 65: /* Exp: Exp MINUS Exp  */
#line 139 "./syntax.y"
                    { (yyval.type_node) = Constructor("Exp", "\0", TYPE_NONTERMINAL, (yyloc).first_line); BuildSon((yyval.type_node), 3, (yyvsp[-2].type_node), (yyvsp[-1].type_node), (yyvsp[0].type_node)); }
#line 1773 "./syntax.tab.c"
    break;

  case 66: /* Exp: Exp STAR Exp  */
#line 140 "./syntax.y"
                   { (yyval.type_node) = Constructor("Exp", "\0", TYPE_NONTERMINAL, (yyloc).first_line); BuildSon((yyval.type_node), 3, (yyvsp[-2].type_node), (yyvsp[-1].type_node), (yyvsp[0].type_node)); }
#line 1779 "./syntax.tab.c"
    break;

  case 67: /* Exp: Exp DIV Exp  */
#line 141 "./syntax.y"
                  { (yyval.type_node) = Constructor("Exp", "\0", TYPE_NONTERMINAL, (yyloc).first_line); BuildSon((yyval.type_node), 3, (yyvsp[-2].type_node), (yyvsp[-1].type_node), (yyvsp[0].type_node)); }
#line 1785 "./syntax.tab.c"
    break;

  case 68: /* Exp: LP Exp RP  */
#line 142 "./syntax.y"
                { (yyval.type_node) = Constructor("Exp", "\0", TYPE_NONTERMINAL, (yyloc).first_line); BuildSon((yyval.type_node), 3, (yyvsp[-2].type_node), (yyvsp[-1].type_node), (yyvsp[0].type_node)); }
#line 1791 "./syntax.tab.c"
    break;

  case 69: /* Exp: MINUS Exp  */
#line 143 "./syntax.y"
                { (yyval.type_node) = Constructor("Exp", "\0", TYPE_NONTERMINAL, (yyloc).first_line); BuildSon((yyval.type_node), 2, (yyvsp[-1].type_node), (yyvsp[0].type_node)); }
#line 1797 "./syntax.tab.c"
    break;

  case 70: /* Exp: NOT Exp  */
#line 144 "./syntax.y"
              { (yyval.type_node) = Constructor("Exp", "\0", TYPE_NONTERMINAL, (yyloc).first_line); BuildSon((yyval.type_node), 2, (yyvsp[-1].type_node), (yyvsp[0].type_node)); }
#line 1803 "./syntax.tab.c"
    break;

  case 71: /* Exp: ID LP Args RP  */
#line 145 "./syntax.y"
                    { (yyval.type_node) = Constructor("Exp", "\0", TYPE_NONTERMINAL, (yyloc).first_line); BuildSon((yyval.type_node), 4, (yyvsp[-3].type_node), (yyvsp[-2].type_node), (yyvsp[-1].type_node), (yyvsp[0].type_node)); }
#line 1809 "./syntax.tab.c"
    break;

  case 72: /* Exp: ID LP RP  */
#line 146 "./syntax.y"
               { (yyval.type_node) = Constructor("Exp", "\0", TYPE_NONTERMINAL, (yyloc).first_line); BuildSon((yyval.type_node), 3, (yyvsp[-2].type_node), (yyvsp[-1].type_node), (yyvsp[0].type_node)); }
#line 1815 "./syntax.tab.c"
    break;

  case 73: /* Exp: Exp LB Exp RB  */
#line 147 "./syntax.y"
                    { (yyval.type_node) = Constructor("Exp", "\0", TYPE_NONTERMINAL, (yyloc).first_line); BuildSon((yyval.type_node), 4, (yyvsp[-3].type_node), (yyvsp[-2].type_node), (yyvsp[-1].type_node), (yyvsp[0].type_node)); }
#line 1821 "./syntax.tab.c"
    break;

  case 74: /* Exp: Exp DOT ID  */
#line 148 "./syntax.y"
                 { (yyval.type_node) = Constructor("Exp", "\0", TYPE_NONTERMINAL, (yyloc).first_line); BuildSon((yyval.type_node), 3, (yyvsp[-2].type_node), (yyvsp[-1].type_node), (yyvsp[0].type_node)); }
#line 1827 "./syntax.tab.c"
    break;

  case 75: /* Exp: ID  */
#line 149 "./syntax.y"
         { (yyval.type_node) = Constructor("Exp", "\0", TYPE_NONTERMINAL, (yyloc).first_line); BuildSon((yyval.type_node), 1, (yyvsp[0].type_node)); }
#line 1833 "./syntax.tab.c"
    break;

  case 76: /* Exp: INT  */
#line 150 "./syntax.y"
          { (yyval.type_node) = Constructor("Exp", "\0", TYPE_NONTERMINAL, (yyloc).first_line); BuildSon((yyval.type_node), 1, (yyvsp[0].type_node)); }
#line 1839 "./syntax.tab.c"
    break;

  case 77: /* Exp: FLOAT  */
#line 151 "./syntax.y"
            { (yyval.type_node) = Constructor("Exp", "\0", TYPE_NONTERMINAL, (yyloc).first_line); BuildSon((yyval.type_node), 1, (yyvsp[0].type_node)); }
#line 1845 "./syntax.tab.c"
    break;

  case 78: /* Exp: Exp ASSIGNOP error  */
#line 155 "./syntax.y"
                         { (yyval.type_node) = NULL; syntax_error = 1; }
#line 1851 "./syntax.tab.c"
    break;

  case 79: /* Exp: Exp AND error  */
#line 156 "./syntax.y"
                    { (yyval.type_node) = NULL; syntax_error = 1; }
#line 1857 "./syntax.tab.c"
    break;

  case 80: /* Exp: Exp OR error  */
#line 157 "./syntax.y"
                   { (yyval.type_node) = NULL; syntax_error = 1; }
#line 1863 "./syntax.tab.c"
    break;

  case 81: /* Exp: Exp RELOP error  */
#line 158 "./syntax.y"
                      { (yyval.type_node) = NULL; syntax_error = 1; }
#line 1869 "./syntax.tab.c"
    break;

  case 82: /* Exp: Exp PLUS error  */
#line 159 "./syntax.y"
                     { (yyval.type_node) = NULL; syntax_error = 1; }
#line 1875 "./syntax.tab.c"
    break;

  case 83: /* Exp: Exp MINUS error  */
#line 160 "./syntax.y"
                      { (yyval.type_node) = NULL; syntax_error = 1; }
#line 1881 "./syntax.tab.c"
    break;

  case 84: /* Exp: Exp STAR error  */
#line 161 "./syntax.y"
                     { (yyval.type_node) = NULL; syntax_error = 1; }
#line 1887 "./syntax.tab.c"
    break;

  case 85: /* Exp: Exp DIV error  */
#line 162 "./syntax.y"
                    { (yyval.type_node) = NULL; syntax_error = 1; }
#line 1893 "./syntax.tab.c"
    break;

  case 86: /* Exp: LP error RP  */
#line 163 "./syntax.y"
                  { (yyval.type_node) = NULL; syntax_error = 1; }
#line 1899 "./syntax.tab.c"
    break;

  case 87: /* Exp: MINUS error  */
#line 164 "./syntax.y"
                  { (yyval.type_node) = NULL; syntax_error = 1; }
#line 1905 "./syntax.tab.c"
    break;

  case 88: /* Exp: NOT error  */
#line 165 "./syntax.y"
                { (yyval.type_node) = NULL; syntax_error = 1; }
#line 1911 "./syntax.tab.c"
    break;

  case 89: /* Exp: ID LP error RP  */
#line 166 "./syntax.y"
                     { (yyval.type_node) = NULL; syntax_error = 1; }
#line 1917 "./syntax.tab.c"
    break;

  case 90: /* Exp: Exp LB error RB  */
#line 167 "./syntax.y"
                      { (yyval.type_node) = NULL; syntax_error = 1; }
#line 1923 "./syntax.tab.c"
    break;

  case 91: /* Args: Exp COMMA Args  */
#line 170 "./syntax.y"
                      { (yyval.type_node) = Constructor("Args", "\0", TYPE_NONTERMINAL, (yyloc).first_line); BuildSon((yyval.type_node), 3, (yyvsp[-2].type_node), (yyvsp[-1].type_node), (yyvsp[0].type_node)); }
#line 1929 "./syntax.tab.c"
    break;

  case 92: /* Args: Exp  */
#line 171 "./syntax.y"
          { (yyval.type_node) = Constructor("Args", "\0", TYPE_NONTERMINAL, (yyloc).first_line); BuildSon((yyval.type_node), 1, (yyvsp[0].type_node)); }
#line 1935 "./syntax.tab.c"
    break;


#line 1939 "./syntax.tab.c"

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
  YY_SYMBOL_PRINT ("-> $$ =", YY_CAST (yysymbol_kind_t, yyr1[yyn]), &yyval, &yyloc);

  YYPOPSTACK (yylen);
  yylen = 0;

  *++yyvsp = yyval;
  *++yylsp = yyloc;

  /* Now 'shift' the result of the reduction.  Determine what state
     that goes to, based on the state we popped back to and the rule
     number reduced by.  */
  {
    const int yylhs = yyr1[yyn] - YYNTOKENS;
    const int yyi = yypgoto[yylhs] + *yyssp;
    yystate = (0 <= yyi && yyi <= YYLAST && yycheck[yyi] == *yyssp
               ? yytable[yyi]
               : yydefgoto[yylhs]);
  }

  goto yynewstate;


/*--------------------------------------.
| yyerrlab -- here on detecting error.  |
`--------------------------------------*/
yyerrlab:
  /* Make sure we have latest lookahead translation.  See comments at
     user semantic actions for why this is necessary.  */
  yytoken = yychar == YYEMPTY ? YYSYMBOL_YYEMPTY : YYTRANSLATE (yychar);
  /* If not already recovering from an error, report this error.  */
  if (!yyerrstatus)
    {
      ++yynerrs;
      yyerror (YY_("syntax error"));
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
  /* Pacify compilers when the user code never invokes YYERROR and the
     label yyerrorlab therefore never appears in user code.  */
  if (0)
    YYERROR;
  ++yynerrs;

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

  /* Pop stack until we find a state that shifts the error token.  */
  for (;;)
    {
      yyn = yypact[yystate];
      if (!yypact_value_is_default (yyn))
        {
          yyn += YYSYMBOL_YYerror;
          if (0 <= yyn && yyn <= YYLAST && yycheck[yyn] == YYSYMBOL_YYerror)
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
                  YY_ACCESSING_SYMBOL (yystate), yyvsp, yylsp);
      YYPOPSTACK (1);
      yystate = *yyssp;
      YY_STACK_PRINT (yyss, yyssp);
    }

  YY_IGNORE_MAYBE_UNINITIALIZED_BEGIN
  *++yyvsp = yylval;
  YY_IGNORE_MAYBE_UNINITIALIZED_END

  yyerror_range[2] = yylloc;
  ++yylsp;
  YYLLOC_DEFAULT (*yylsp, yyerror_range, 2);

  /* Shift the error token.  */
  YY_SYMBOL_PRINT ("Shifting", YY_ACCESSING_SYMBOL (yyn), yyvsp, yylsp);

  yystate = yyn;
  goto yynewstate;


/*-------------------------------------.
| yyacceptlab -- YYACCEPT comes here.  |
`-------------------------------------*/
yyacceptlab:
  yyresult = 0;
  goto yyreturnlab;


/*-----------------------------------.
| yyabortlab -- YYABORT comes here.  |
`-----------------------------------*/
yyabortlab:
  yyresult = 1;
  goto yyreturnlab;


/*-----------------------------------------------------------.
| yyexhaustedlab -- YYNOMEM (memory exhaustion) comes here.  |
`-----------------------------------------------------------*/
yyexhaustedlab:
  yyerror (YY_("memory exhausted"));
  yyresult = 2;
  goto yyreturnlab;


/*----------------------------------------------------------.
| yyreturnlab -- parsing is finished, clean up and return.  |
`----------------------------------------------------------*/
yyreturnlab:
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
                  YY_ACCESSING_SYMBOL (+*yyssp), yyvsp, yylsp);
      YYPOPSTACK (1);
    }
#ifndef yyoverflow
  if (yyss != yyssa)
    YYSTACK_FREE (yyss);
#endif

  return yyresult;
}

#line 174 "./syntax.y"


int main(int argc, char **argv) {
    if(argc <= 1) {
        return 1;
    }
    FILE * f = fopen(argv[1], "r");
    if(!f) {
        perror(argv[1]);
        return 1;
    }
    yyrestart(f);
    // yydebug = 1;
    yyparse();
    if(!lex_error && !syntax_error) {
        OutPutTree(root, 0);
    }
    return 0;
}

int yyerror(char *msg) {
    if(!haserror[yylineno]) {
        printf("Error type B at Line %d: %s.\n", yylineno, msg);
        syntax_error = 1;
        haserror[yylineno] = 1;
    }
}
