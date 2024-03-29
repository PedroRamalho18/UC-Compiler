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
#line 3 "uccompiler.y"

#include "ast.h"
#include <stdio.h>

int yylex();
void yyerror(const char *);

struct node *program;
struct node* aux;

extern char *yytext;

int stat_check = 0;
int error_check = 0;

#line 87 "y.tab.c"

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

/* Use api.header.include to #include this header
   instead of duplicating it here.  */
#ifndef YY_YY_Y_TAB_H_INCLUDED
# define YY_YY_Y_TAB_H_INCLUDED
/* Debug traces.  */
#ifndef YYDEBUG
# define YYDEBUG 1
#endif
#if YYDEBUG
extern int yydebug;
#endif

/* Token kinds.  */
#ifndef YYTOKENTYPE
# define YYTOKENTYPE
  enum yytokentype
  {
    YYEMPTY = -2,
    YYEOF = 0,                     /* "end of file"  */
    YYerror = 256,                 /* error  */
    YYUNDEF = 257,                 /* "invalid token"  */
    CHAR = 258,                    /* CHAR  */
    DOUBLE = 259,                  /* DOUBLE  */
    INT = 260,                     /* INT  */
    SHORT = 261,                   /* SHORT  */
    ELSE = 262,                    /* ELSE  */
    WHILE = 263,                   /* WHILE  */
    IF = 264,                      /* IF  */
    RETURN = 265,                  /* RETURN  */
    VOID = 266,                    /* VOID  */
    BITWISEAND = 267,              /* BITWISEAND  */
    BITWISEOR = 268,               /* BITWISEOR  */
    BITWISEXOR = 269,              /* BITWISEXOR  */
    AND = 270,                     /* AND  */
    ASSIGN = 271,                  /* ASSIGN  */
    MUL = 272,                     /* MUL  */
    COMMA = 273,                   /* COMMA  */
    DIV = 274,                     /* DIV  */
    EQ = 275,                      /* EQ  */
    GE = 276,                      /* GE  */
    GT = 277,                      /* GT  */
    LBRACE = 278,                  /* LBRACE  */
    LE = 279,                      /* LE  */
    LPAR = 280,                    /* LPAR  */
    LT = 281,                      /* LT  */
    MINUS = 282,                   /* MINUS  */
    MOD = 283,                     /* MOD  */
    NE = 284,                      /* NE  */
    NOT = 285,                     /* NOT  */
    OR = 286,                      /* OR  */
    PLUS = 287,                    /* PLUS  */
    RBRACE = 288,                  /* RBRACE  */
    RPAR = 289,                    /* RPAR  */
    SEMI = 290,                    /* SEMI  */
    IDENTIFIER = 291,              /* IDENTIFIER  */
    NATURAL = 292,                 /* NATURAL  */
    DECIMAL = 293,                 /* DECIMAL  */
    CHRLIT = 294,                  /* CHRLIT  */
    RESERVED = 295                 /* RESERVED  */
  };
  typedef enum yytokentype yytoken_kind_t;
#endif
/* Token kinds.  */
#define YYEMPTY -2
#define YYEOF 0
#define YYerror 256
#define YYUNDEF 257
#define CHAR 258
#define DOUBLE 259
#define INT 260
#define SHORT 261
#define ELSE 262
#define WHILE 263
#define IF 264
#define RETURN 265
#define VOID 266
#define BITWISEAND 267
#define BITWISEOR 268
#define BITWISEXOR 269
#define AND 270
#define ASSIGN 271
#define MUL 272
#define COMMA 273
#define DIV 274
#define EQ 275
#define GE 276
#define GT 277
#define LBRACE 278
#define LE 279
#define LPAR 280
#define LT 281
#define MINUS 282
#define MOD 283
#define NE 284
#define NOT 285
#define OR 286
#define PLUS 287
#define RBRACE 288
#define RPAR 289
#define SEMI 290
#define IDENTIFIER 291
#define NATURAL 292
#define DECIMAL 293
#define CHRLIT 294
#define RESERVED 295

/* Value type.  */
#if ! defined YYSTYPE && ! defined YYSTYPE_IS_DECLARED
union YYSTYPE
{
#line 39 "uccompiler.y"

    char *token;
    struct node *node;

#line 225 "y.tab.c"

};
typedef union YYSTYPE YYSTYPE;
# define YYSTYPE_IS_TRIVIAL 1
# define YYSTYPE_IS_DECLARED 1
#endif


extern YYSTYPE yylval;


int yyparse (void);


#endif /* !YY_YY_Y_TAB_H_INCLUDED  */
/* Symbol kind.  */
enum yysymbol_kind_t
{
  YYSYMBOL_YYEMPTY = -2,
  YYSYMBOL_YYEOF = 0,                      /* "end of file"  */
  YYSYMBOL_YYerror = 1,                    /* error  */
  YYSYMBOL_YYUNDEF = 2,                    /* "invalid token"  */
  YYSYMBOL_CHAR = 3,                       /* CHAR  */
  YYSYMBOL_DOUBLE = 4,                     /* DOUBLE  */
  YYSYMBOL_INT = 5,                        /* INT  */
  YYSYMBOL_SHORT = 6,                      /* SHORT  */
  YYSYMBOL_ELSE = 7,                       /* ELSE  */
  YYSYMBOL_WHILE = 8,                      /* WHILE  */
  YYSYMBOL_IF = 9,                         /* IF  */
  YYSYMBOL_RETURN = 10,                    /* RETURN  */
  YYSYMBOL_VOID = 11,                      /* VOID  */
  YYSYMBOL_BITWISEAND = 12,                /* BITWISEAND  */
  YYSYMBOL_BITWISEOR = 13,                 /* BITWISEOR  */
  YYSYMBOL_BITWISEXOR = 14,                /* BITWISEXOR  */
  YYSYMBOL_AND = 15,                       /* AND  */
  YYSYMBOL_ASSIGN = 16,                    /* ASSIGN  */
  YYSYMBOL_MUL = 17,                       /* MUL  */
  YYSYMBOL_COMMA = 18,                     /* COMMA  */
  YYSYMBOL_DIV = 19,                       /* DIV  */
  YYSYMBOL_EQ = 20,                        /* EQ  */
  YYSYMBOL_GE = 21,                        /* GE  */
  YYSYMBOL_GT = 22,                        /* GT  */
  YYSYMBOL_LBRACE = 23,                    /* LBRACE  */
  YYSYMBOL_LE = 24,                        /* LE  */
  YYSYMBOL_LPAR = 25,                      /* LPAR  */
  YYSYMBOL_LT = 26,                        /* LT  */
  YYSYMBOL_MINUS = 27,                     /* MINUS  */
  YYSYMBOL_MOD = 28,                       /* MOD  */
  YYSYMBOL_NE = 29,                        /* NE  */
  YYSYMBOL_NOT = 30,                       /* NOT  */
  YYSYMBOL_OR = 31,                        /* OR  */
  YYSYMBOL_PLUS = 32,                      /* PLUS  */
  YYSYMBOL_RBRACE = 33,                    /* RBRACE  */
  YYSYMBOL_RPAR = 34,                      /* RPAR  */
  YYSYMBOL_SEMI = 35,                      /* SEMI  */
  YYSYMBOL_IDENTIFIER = 36,                /* IDENTIFIER  */
  YYSYMBOL_NATURAL = 37,                   /* NATURAL  */
  YYSYMBOL_DECIMAL = 38,                   /* DECIMAL  */
  YYSYMBOL_CHRLIT = 39,                    /* CHRLIT  */
  YYSYMBOL_RESERVED = 40,                  /* RESERVED  */
  YYSYMBOL_YYACCEPT = 41,                  /* $accept  */
  YYSYMBOL_Program = 42,                   /* Program  */
  YYSYMBOL_FunctionsAndDeclarations = 43,  /* FunctionsAndDeclarations  */
  YYSYMBOL_FunctionDefinition = 44,        /* FunctionDefinition  */
  YYSYMBOL_FunctionBody = 45,              /* FunctionBody  */
  YYSYMBOL_DeclarationsAndStatements = 46, /* DeclarationsAndStatements  */
  YYSYMBOL_FunctionDeclaration = 47,       /* FunctionDeclaration  */
  YYSYMBOL_FunctionDeclarator = 48,        /* FunctionDeclarator  */
  YYSYMBOL_ParameterList = 49,             /* ParameterList  */
  YYSYMBOL_ParameterDeclaration = 50,      /* ParameterDeclaration  */
  YYSYMBOL_Declaration = 51,               /* Declaration  */
  YYSYMBOL_Declarations = 52,              /* Declarations  */
  YYSYMBOL_TypeSpec = 53,                  /* TypeSpec  */
  YYSYMBOL_Declarator = 54,                /* Declarator  */
  YYSYMBOL_Statement = 55,                 /* Statement  */
  YYSYMBOL_StatementError = 56,            /* StatementError  */
  YYSYMBOL_Statements = 57,                /* Statements  */
  YYSYMBOL_ExprList = 58,                  /* ExprList  */
  YYSYMBOL_ExprCall = 59,                  /* ExprCall  */
  YYSYMBOL_Expr = 60                       /* Expr  */
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
         || (defined YYSTYPE_IS_TRIVIAL && YYSTYPE_IS_TRIVIAL)))

/* A type that is properly aligned for any stack member.  */
union yyalloc
{
  yy_state_t yyss_alloc;
  YYSTYPE yyvs_alloc;
};

/* The size of the maximum gap between one aligned stack and the next.  */
# define YYSTACK_GAP_MAXIMUM (YYSIZEOF (union yyalloc) - 1)

/* The size of an array large to enough to hold all stacks, each with
   N elements.  */
# define YYSTACK_BYTES(N) \
     ((N) * (YYSIZEOF (yy_state_t) + YYSIZEOF (YYSTYPE)) \
      + YYSTACK_GAP_MAXIMUM)

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
#define YYFINAL  14
/* YYLAST -- Last index in YYTABLE.  */
#define YYLAST   414

/* YYNTOKENS -- Number of terminals.  */
#define YYNTOKENS  41
/* YYNNTS -- Number of nonterminals.  */
#define YYNNTS  20
/* YYNRULES -- Number of rules.  */
#define YYNRULES  79
/* YYNSTATES -- Number of states.  */
#define YYNSTATES  138

/* YYMAXUTOK -- Last valid token kind.  */
#define YYMAXUTOK   295


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
      25,    26,    27,    28,    29,    30,    31,    32,    33,    34,
      35,    36,    37,    38,    39,    40
};

#if YYDEBUG
/* YYRLINE[YYN] -- Source line where rule number YYN was defined.  */
static const yytype_uint8 yyrline[] =
{
       0,    45,    45,    48,    49,    50,    51,    52,    53,    56,
      59,    60,    63,    64,    65,    66,    69,    72,    75,    76,
      79,    80,    83,    84,    94,    95,    98,    99,   100,   101,
     102,   105,   106,   109,   110,   111,   112,   113,   122,   132,
     146,   154,   155,   158,   159,   161,   162,   165,   166,   169,
     170,   173,   174,   175,   176,   177,   178,   179,   180,   181,
     182,   183,   184,   185,   186,   187,   188,   189,   190,   191,
     192,   193,   194,   195,   196,   197,   198,   199,   200,   201
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
  "\"end of file\"", "error", "\"invalid token\"", "CHAR", "DOUBLE",
  "INT", "SHORT", "ELSE", "WHILE", "IF", "RETURN", "VOID", "BITWISEAND",
  "BITWISEOR", "BITWISEXOR", "AND", "ASSIGN", "MUL", "COMMA", "DIV", "EQ",
  "GE", "GT", "LBRACE", "LE", "LPAR", "LT", "MINUS", "MOD", "NE", "NOT",
  "OR", "PLUS", "RBRACE", "RPAR", "SEMI", "IDENTIFIER", "NATURAL",
  "DECIMAL", "CHRLIT", "RESERVED", "$accept", "Program",
  "FunctionsAndDeclarations", "FunctionDefinition", "FunctionBody",
  "DeclarationsAndStatements", "FunctionDeclaration", "FunctionDeclarator",
  "ParameterList", "ParameterDeclaration", "Declaration", "Declarations",
  "TypeSpec", "Declarator", "Statement", "StatementError", "Statements",
  "ExprList", "ExprCall", "Expr", YY_NULLPTR
};

static const char *
yysymbol_name (yysymbol_kind_t yysymbol)
{
  return yytname[yysymbol];
}
#endif

#define YYPACT_NINF (-83)

#define yypact_value_is_default(Yyn) \
  ((Yyn) == YYPACT_NINF)

#define YYTABLE_NINF (-3)

#define yytable_value_is_error(Yyn) \
  0

/* YYPACT[STATE-NUM] -- Index in YYTABLE of the portion describing
   STATE-NUM.  */
static const yytype_int16 yypact[] =
{
     150,   -28,   -83,   -83,   -83,   -83,   -83,    55,   117,   -83,
     -83,   -83,    21,   -83,   -83,   -83,   -83,   -83,    64,    56,
     -14,   -83,   375,   178,    65,   -83,   -83,    22,   -83,   233,
     375,   375,   375,    34,   -83,   -83,   -83,   -83,   261,    38,
     -83,    24,    59,    61,   360,   137,   -83,   -83,   104,   -83,
      22,   -83,   -13,    77,   -83,    60,    43,   -83,   -83,   -83,
     218,   375,   375,   375,   375,   375,   375,   375,   375,   375,
     375,   375,   375,   375,   375,   375,   375,   375,   375,   178,
     -83,   -83,   375,   375,   -83,   -12,   -18,   -83,   -83,   -83,
     170,   -83,   -83,   -83,   -83,   -83,   -83,    72,   -83,    44,
     261,   261,   354,   322,   340,   303,   261,   -83,   -83,    -8,
     131,   131,   131,   131,    68,   -83,    -8,   282,    68,   -83,
      47,    49,   -83,   -83,   -83,    76,   -83,   -83,   -83,   375,
     -83,   203,   203,   261,   -83,   109,   203,   -83
};

/* YYDEFACT[STATE-NUM] -- Default reduction number in state STATE-NUM.
   Performed when YYTABLE does not specify something else to do.  Zero
   means the default is an error.  */
static const yytype_int8 yydefact[] =
{
       0,     0,    26,    30,    27,    29,    28,     0,     0,     3,
       4,     5,     0,    22,     1,     6,     7,     8,    31,     0,
       0,    24,     0,     0,     0,    16,     9,     0,    23,     0,
       0,     0,     0,    53,    54,    56,    55,    32,    47,     0,
      18,    21,     0,     0,     0,     0,    11,    34,     0,    15,
       0,    14,     0,    31,    25,     0,     0,    75,    77,    76,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
      17,    20,     0,     0,    41,     0,     0,    36,    44,    45,
       0,    10,    13,    12,    35,    52,    57,     0,    78,     0,
      50,    48,    68,    66,    67,    65,    58,    61,    62,    69,
      72,    74,    71,    73,    60,    63,    70,    64,    59,    19,
       0,     0,    42,    33,    43,     0,    37,    46,    51,     0,
      79,     0,     0,    49,    40,    38,     0,    39
};

/* YYPGOTO[NTERM-NUM].  */
static const yytype_int8 yypgoto[] =
{
     -83,   -83,   -83,   111,   -83,   -83,   116,   -83,   -83,    46,
       4,   -83,     3,    99,     5,   -82,   -83,   -19,   -83,   -30
};

/* YYDEFGOTO[NTERM-NUM].  */
static const yytype_int8 yydefgoto[] =
{
       0,     7,     8,     9,    26,    48,    10,    19,    39,    40,
      11,    20,    12,    21,    88,    89,    90,    52,    99,    38
};

/* YYTABLE[YYPACT[STATE-NUM]] -- What to do in state STATE-NUM.  If
   positive, shift that token.  If negative, reduce the rule whose
   number is the opposite.  If YYTABLE_NINF, syntax error.  */
static const yytype_int16 yytable[] =
{
      57,    58,    59,    37,    27,    61,    61,    13,   127,    67,
      56,    68,    17,    70,    71,   123,    72,   124,    73,    74,
      75,    28,    94,   122,    78,    85,    41,    50,    49,    51,
     100,   101,   102,   103,   104,   105,   106,   107,   108,   109,
     110,   111,   112,   113,   114,   115,   116,   117,   118,   134,
     135,    50,    92,    93,   137,    14,    79,    18,    53,    60,
      81,    61,   129,   120,   121,    61,     1,    61,     2,     3,
       4,     5,    80,    42,    43,    44,     6,    96,   130,    24,
      22,   131,    41,   132,    82,    67,    83,    68,    45,    23,
      29,    25,    30,    22,    95,    31,    75,    32,    46,   133,
      47,    33,    34,    35,    36,     1,   128,     2,     3,     4,
       5,   124,    42,    43,    44,     6,   136,    -2,     1,    15,
       2,     3,     4,     5,    16,   119,    54,    45,     6,    29,
       0,    30,     0,     0,    31,     0,    32,    91,    86,    47,
      33,    34,    35,    36,     0,    42,    43,    44,    67,     0,
      68,     1,     0,     2,     3,     4,     5,     0,    74,    75,
      45,     6,    29,    78,    30,     0,     0,    31,     0,    32,
      87,   125,    47,    33,    34,    35,    36,     0,    42,    43,
      44,     2,     3,     4,     5,     0,     0,     0,     0,     6,
       0,     0,     0,    45,     0,    29,     0,    30,     0,     0,
      31,     0,    32,   126,   125,    47,    33,    34,    35,    36,
       0,    42,    43,    44,     0,     0,     0,     0,     0,    97,
       0,     0,     0,     0,     0,     0,    45,     0,    29,     0,
      30,     0,     0,    31,    55,    32,     0,     0,    47,    33,
      34,    35,    36,    29,     0,    30,     0,     0,    31,     0,
      32,     0,    98,     0,    33,    34,    35,    36,    29,     0,
      30,     0,     0,    31,     0,    32,     0,     0,     0,    33,
      34,    35,    36,    62,    63,    64,    65,    66,    67,     0,
      68,    69,    70,    71,     0,    72,     0,    73,    74,    75,
      76,     0,    77,    78,    62,    63,    64,    65,     0,    67,
       0,    68,    69,    70,    71,     0,    72,     0,    73,    74,
      75,    76,     0,     0,    78,    62,    63,    64,     0,     0,
      67,     0,    68,    69,    70,    71,     0,    72,     0,    73,
      74,    75,    76,     0,    62,    78,    64,     0,     0,    67,
       0,    68,    69,    70,    71,     0,    72,     0,    73,    74,
      75,    76,    62,     0,    78,     0,     0,    67,     0,    68,
      69,    70,    71,     0,    72,     0,    73,    74,    75,    76,
       0,    67,    78,    68,    69,    70,    71,     0,    72,     0,
      73,    74,    75,    76,     0,    29,    78,    30,     0,     0,
      31,     0,    32,     0,     0,    84,    33,    34,    35,    36,
      29,     0,    30,     0,     0,    31,     0,    32,     0,     0,
       0,    33,    34,    35,    36
};

static const yytype_int16 yycheck[] =
{
      30,    31,    32,    22,    18,    18,    18,    35,    90,    17,
      29,    19,     8,    21,    22,    33,    24,    35,    26,    27,
      28,    35,    35,    35,    32,    44,    23,    24,    24,    24,
      60,    61,    62,    63,    64,    65,    66,    67,    68,    69,
      70,    71,    72,    73,    74,    75,    76,    77,    78,   131,
     132,    48,    48,    48,   136,     0,    18,    36,    36,    25,
      36,    18,    18,    82,    83,    18,     1,    18,     3,     4,
       5,     6,    34,     8,     9,    10,    11,    34,    34,    23,
      16,    34,    79,    34,    25,    17,    25,    19,    23,    25,
      25,    35,    27,    16,    34,    30,    28,    32,    33,   129,
      35,    36,    37,    38,    39,     1,    34,     3,     4,     5,
       6,    35,     8,     9,    10,    11,     7,     0,     1,     8,
       3,     4,     5,     6,     8,    79,    27,    23,    11,    25,
      -1,    27,    -1,    -1,    30,    -1,    32,    33,     1,    35,
      36,    37,    38,    39,    -1,     8,     9,    10,    17,    -1,
      19,     1,    -1,     3,     4,     5,     6,    -1,    27,    28,
      23,    11,    25,    32,    27,    -1,    -1,    30,    -1,    32,
      33,     1,    35,    36,    37,    38,    39,    -1,     8,     9,
      10,     3,     4,     5,     6,    -1,    -1,    -1,    -1,    11,
      -1,    -1,    -1,    23,    -1,    25,    -1,    27,    -1,    -1,
      30,    -1,    32,    33,     1,    35,    36,    37,    38,    39,
      -1,     8,     9,    10,    -1,    -1,    -1,    -1,    -1,     1,
      -1,    -1,    -1,    -1,    -1,    -1,    23,    -1,    25,    -1,
      27,    -1,    -1,    30,     1,    32,    -1,    -1,    35,    36,
      37,    38,    39,    25,    -1,    27,    -1,    -1,    30,    -1,
      32,    -1,    34,    -1,    36,    37,    38,    39,    25,    -1,
      27,    -1,    -1,    30,    -1,    32,    -1,    -1,    -1,    36,
      37,    38,    39,    12,    13,    14,    15,    16,    17,    -1,
      19,    20,    21,    22,    -1,    24,    -1,    26,    27,    28,
      29,    -1,    31,    32,    12,    13,    14,    15,    -1,    17,
      -1,    19,    20,    21,    22,    -1,    24,    -1,    26,    27,
      28,    29,    -1,    -1,    32,    12,    13,    14,    -1,    -1,
      17,    -1,    19,    20,    21,    22,    -1,    24,    -1,    26,
      27,    28,    29,    -1,    12,    32,    14,    -1,    -1,    17,
      -1,    19,    20,    21,    22,    -1,    24,    -1,    26,    27,
      28,    29,    12,    -1,    32,    -1,    -1,    17,    -1,    19,
      20,    21,    22,    -1,    24,    -1,    26,    27,    28,    29,
      -1,    17,    32,    19,    20,    21,    22,    -1,    24,    -1,
      26,    27,    28,    29,    -1,    25,    32,    27,    -1,    -1,
      30,    -1,    32,    -1,    -1,    35,    36,    37,    38,    39,
      25,    -1,    27,    -1,    -1,    30,    -1,    32,    -1,    -1,
      -1,    36,    37,    38,    39
};

/* YYSTOS[STATE-NUM] -- The symbol kind of the accessing symbol of
   state STATE-NUM.  */
static const yytype_int8 yystos[] =
{
       0,     1,     3,     4,     5,     6,    11,    42,    43,    44,
      47,    51,    53,    35,     0,    44,    47,    51,    36,    48,
      52,    54,    16,    25,    23,    35,    45,    18,    35,    25,
      27,    30,    32,    36,    37,    38,    39,    58,    60,    49,
      50,    53,     8,     9,    10,    23,    33,    35,    46,    51,
      53,    55,    58,    36,    54,     1,    58,    60,    60,    60,
      25,    18,    12,    13,    14,    15,    16,    17,    19,    20,
      21,    22,    24,    26,    27,    28,    29,    31,    32,    18,
      34,    36,    25,    25,    35,    58,     1,    33,    55,    56,
      57,    33,    51,    55,    35,    34,    34,     1,    34,    59,
      60,    60,    60,    60,    60,    60,    60,    60,    60,    60,
      60,    60,    60,    60,    60,    60,    60,    60,    60,    50,
      58,    58,    35,    33,    35,     1,    33,    56,    34,    18,
      34,    34,    34,    60,    56,    56,     7,    56
};

/* YYR1[RULE-NUM] -- Symbol kind of the left-hand side of rule RULE-NUM.  */
static const yytype_int8 yyr1[] =
{
       0,    41,    42,    43,    43,    43,    43,    43,    43,    44,
      45,    45,    46,    46,    46,    46,    47,    48,    49,    49,
      50,    50,    51,    51,    52,    52,    53,    53,    53,    53,
      53,    54,    54,    55,    55,    55,    55,    55,    55,    55,
      55,    55,    55,    56,    56,    57,    57,    58,    58,    59,
      59,    60,    60,    60,    60,    60,    60,    60,    60,    60,
      60,    60,    60,    60,    60,    60,    60,    60,    60,    60,
      60,    60,    60,    60,    60,    60,    60,    60,    60,    60
};

/* YYR2[RULE-NUM] -- Number of symbols on the right-hand side of rule RULE-NUM.  */
static const yytype_int8 yyr2[] =
{
       0,     2,     1,     1,     1,     1,     2,     2,     2,     3,
       3,     2,     2,     2,     1,     1,     3,     4,     1,     3,
       2,     1,     2,     3,     1,     3,     1,     1,     1,     1,
       1,     1,     3,     3,     1,     2,     2,     3,     5,     7,
       5,     2,     3,     2,     1,     1,     2,     1,     3,     3,
       1,     4,     3,     1,     1,     1,     1,     3,     3,     3,
       3,     3,     3,     3,     3,     3,     3,     3,     3,     3,
       3,     3,     3,     3,     3,     2,     2,     2,     3,     4
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




# define YY_SYMBOL_PRINT(Title, Kind, Value, Location)                    \
do {                                                                      \
  if (yydebug)                                                            \
    {                                                                     \
      YYFPRINTF (stderr, "%s ", Title);                                   \
      yy_symbol_print (stderr,                                            \
                  Kind, Value); \
      YYFPRINTF (stderr, "\n");                                           \
    }                                                                     \
} while (0)


/*-----------------------------------.
| Print this symbol's value on YYO.  |
`-----------------------------------*/

static void
yy_symbol_value_print (FILE *yyo,
                       yysymbol_kind_t yykind, YYSTYPE const * const yyvaluep)
{
  FILE *yyoutput = yyo;
  YY_USE (yyoutput);
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
                 yysymbol_kind_t yykind, YYSTYPE const * const yyvaluep)
{
  YYFPRINTF (yyo, "%s %s (",
             yykind < YYNTOKENS ? "token" : "nterm", yysymbol_name (yykind));

  yy_symbol_value_print (yyo, yykind, yyvaluep);
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
yy_reduce_print (yy_state_t *yyssp, YYSTYPE *yyvsp,
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
                       &yyvsp[(yyi + 1) - (yynrhs)]);
      YYFPRINTF (stderr, "\n");
    }
}

# define YY_REDUCE_PRINT(Rule)          \
do {                                    \
  if (yydebug)                          \
    yy_reduce_print (yyssp, yyvsp, Rule); \
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
            yysymbol_kind_t yykind, YYSTYPE *yyvaluep)
{
  YY_USE (yyvaluep);
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

  int yyn;
  /* The return value of yyparse.  */
  int yyresult;
  /* Lookahead symbol kind.  */
  yysymbol_kind_t yytoken = YYSYMBOL_YYEMPTY;
  /* The variables used to return semantic value and location from the
     action routines.  */
  YYSTYPE yyval;



#define YYPOPSTACK(N)   (yyvsp -= (N), yyssp -= (N))

  /* The number of symbols on the RHS of the reduced rule.
     Keep to zero when no symbol should be popped.  */
  int yylen = 0;

  YYDPRINTF ((stderr, "Starting parse\n"));

  yychar = YYEMPTY; /* Cause a token to be read.  */

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

        /* Each stack pointer address is followed by the size of the
           data in use in that stack, in bytes.  This used to be a
           conditional around just the two extra args, but that might
           be undefined if yyoverflow is a macro.  */
        yyoverflow (YY_("memory exhausted"),
                    &yyss1, yysize * YYSIZEOF (*yyssp),
                    &yyvs1, yysize * YYSIZEOF (*yyvsp),
                    &yystacksize);
        yyss = yyss1;
        yyvs = yyvs1;
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
#  undef YYSTACK_RELOCATE
        if (yyss1 != yyssa)
          YYSTACK_FREE (yyss1);
      }
# endif

      yyssp = yyss + yysize - 1;
      yyvsp = yyvs + yysize - 1;

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


  YY_REDUCE_PRINT (yyn);
  switch (yyn)
    {
  case 2: /* Program: FunctionsAndDeclarations  */
#line 45 "uccompiler.y"
                                  {program = newnode(Program, NULL); addchild(program, (yyvsp[0].node));}
#line 1407 "y.tab.c"
    break;

  case 3: /* FunctionsAndDeclarations: FunctionDefinition  */
#line 48 "uccompiler.y"
                                             {(yyval.node) = (yyvsp[0].node);}
#line 1413 "y.tab.c"
    break;

  case 4: /* FunctionsAndDeclarations: FunctionDeclaration  */
#line 49 "uccompiler.y"
                          {(yyval.node) = (yyvsp[0].node);}
#line 1419 "y.tab.c"
    break;

  case 5: /* FunctionsAndDeclarations: Declaration  */
#line 50 "uccompiler.y"
                  {(yyval.node) = (yyvsp[0].node);}
#line 1425 "y.tab.c"
    break;

  case 6: /* FunctionsAndDeclarations: FunctionsAndDeclarations FunctionDefinition  */
#line 51 "uccompiler.y"
                                                  {(yyval.node)=(yyvsp[-1].node);addbrother((yyval.node),(yyvsp[0].node));}
#line 1431 "y.tab.c"
    break;

  case 7: /* FunctionsAndDeclarations: FunctionsAndDeclarations FunctionDeclaration  */
#line 52 "uccompiler.y"
                                                   {(yyval.node)=(yyvsp[-1].node);addbrother((yyval.node),(yyvsp[0].node));}
#line 1437 "y.tab.c"
    break;

  case 8: /* FunctionsAndDeclarations: FunctionsAndDeclarations Declaration  */
#line 53 "uccompiler.y"
                                           {(yyval.node)=(yyvsp[-1].node);addbrother((yyval.node),(yyvsp[0].node));}
#line 1443 "y.tab.c"
    break;

  case 9: /* FunctionDefinition: TypeSpec FunctionDeclarator FunctionBody  */
#line 56 "uccompiler.y"
                                                             {(yyval.node) = newnode(FuncDefinition, NULL); addchild((yyval.node),(yyvsp[-2].node)); addchild((yyval.node),(yyvsp[-1].node)); addchild((yyval.node),(yyvsp[0].node));}
#line 1449 "y.tab.c"
    break;

  case 10: /* FunctionBody: LBRACE DeclarationsAndStatements RBRACE  */
#line 59 "uccompiler.y"
                                                      {(yyval.node) = newnode(FuncBody, NULL); addchild((yyval.node), (yyvsp[-1].node));}
#line 1455 "y.tab.c"
    break;

  case 11: /* FunctionBody: LBRACE RBRACE  */
#line 60 "uccompiler.y"
                    {(yyval.node) = newnode(FuncBody, NULL);}
#line 1461 "y.tab.c"
    break;

  case 12: /* DeclarationsAndStatements: DeclarationsAndStatements Statement  */
#line 63 "uccompiler.y"
                                                               {(yyval.node)=(yyvsp[-1].node); addbrother((yyval.node),(yyvsp[0].node));}
#line 1467 "y.tab.c"
    break;

  case 13: /* DeclarationsAndStatements: DeclarationsAndStatements Declaration  */
#line 64 "uccompiler.y"
                                            {(yyval.node)=(yyvsp[-1].node); addbrother((yyval.node),(yyvsp[0].node));}
#line 1473 "y.tab.c"
    break;

  case 14: /* DeclarationsAndStatements: Statement  */
#line 65 "uccompiler.y"
                {(yyval.node) = (yyvsp[0].node);}
#line 1479 "y.tab.c"
    break;

  case 15: /* DeclarationsAndStatements: Declaration  */
#line 66 "uccompiler.y"
                  {(yyval.node) = (yyvsp[0].node);}
#line 1485 "y.tab.c"
    break;

  case 16: /* FunctionDeclaration: TypeSpec FunctionDeclarator SEMI  */
#line 69 "uccompiler.y"
                                                      {(yyval.node) = newnode(FuncDeclaration, NULL); addchild((yyval.node), (yyvsp[-2].node)); addchild((yyval.node), (yyvsp[-1].node));}
#line 1491 "y.tab.c"
    break;

  case 17: /* FunctionDeclarator: IDENTIFIER LPAR ParameterList RPAR  */
#line 72 "uccompiler.y"
                                                       {(yyval.node) = newnode(Identifier, (yyvsp[-3].token)); aux=newnode(ParamList,NULL); addchild(aux,(yyvsp[-1].node)); addbrother((yyval.node),aux);}
#line 1497 "y.tab.c"
    break;

  case 18: /* ParameterList: ParameterDeclaration  */
#line 75 "uccompiler.y"
                                    {(yyval.node)=(yyvsp[0].node);}
#line 1503 "y.tab.c"
    break;

  case 19: /* ParameterList: ParameterList COMMA ParameterDeclaration  */
#line 76 "uccompiler.y"
                                                {(yyval.node)=(yyvsp[-2].node); addbrother((yyval.node), (yyvsp[0].node));}
#line 1509 "y.tab.c"
    break;

  case 20: /* ParameterDeclaration: TypeSpec IDENTIFIER  */
#line 79 "uccompiler.y"
                                          {(yyval.node) = newnode(ParamDeclaration, NULL); addchild((yyval.node), (yyvsp[-1].node)); addchild((yyval.node), newnode(Identifier, (yyvsp[0].token)));}
#line 1515 "y.tab.c"
    break;

  case 21: /* ParameterDeclaration: TypeSpec  */
#line 80 "uccompiler.y"
               {(yyval.node) = newnode(ParamDeclaration, NULL); addchild((yyval.node), (yyvsp[0].node));}
#line 1521 "y.tab.c"
    break;

  case 22: /* Declaration: error SEMI  */
#line 83 "uccompiler.y"
                        {(yyval.node)=newnode(Error,NULL); error_check=1;}
#line 1527 "y.tab.c"
    break;

  case 23: /* Declaration: TypeSpec Declarations SEMI  */
#line 84 "uccompiler.y"
                                 {
                                    (yyval.node) = (yyvsp[-1].node);
                                    aux = (yyval.node);
                                    while(aux != NULL){
                                        aux->children->next->node->category = (yyvsp[-2].node)->category;
                                        aux = aux->brother;
                                    }
                                }
#line 1540 "y.tab.c"
    break;

  case 24: /* Declarations: Declarator  */
#line 94 "uccompiler.y"
                         {(yyval.node) = (yyvsp[0].node);}
#line 1546 "y.tab.c"
    break;

  case 25: /* Declarations: Declarations COMMA Declarator  */
#line 95 "uccompiler.y"
                                    {(yyval.node)=(yyvsp[-2].node); addbrother((yyval.node), (yyvsp[0].node));}
#line 1552 "y.tab.c"
    break;

  case 26: /* TypeSpec: CHAR  */
#line 98 "uccompiler.y"
               {(yyval.node)=newnode(Char,NULL);}
#line 1558 "y.tab.c"
    break;

  case 27: /* TypeSpec: INT  */
#line 99 "uccompiler.y"
          {(yyval.node)=newnode(Int,NULL);}
#line 1564 "y.tab.c"
    break;

  case 28: /* TypeSpec: VOID  */
#line 100 "uccompiler.y"
           {(yyval.node)=newnode(Void,NULL);}
#line 1570 "y.tab.c"
    break;

  case 29: /* TypeSpec: SHORT  */
#line 101 "uccompiler.y"
            {(yyval.node)=newnode(Short,NULL);}
#line 1576 "y.tab.c"
    break;

  case 30: /* TypeSpec: DOUBLE  */
#line 102 "uccompiler.y"
             {(yyval.node)=newnode(Double,NULL);}
#line 1582 "y.tab.c"
    break;

  case 31: /* Declarator: IDENTIFIER  */
#line 105 "uccompiler.y"
                       {(yyval.node) = newnode(Declaration, NULL); addchild((yyval.node), newnode(Null, NULL)); addchild((yyval.node), newnode(Identifier, (yyvsp[0].token)));}
#line 1588 "y.tab.c"
    break;

  case 32: /* Declarator: IDENTIFIER ASSIGN ExprList  */
#line 106 "uccompiler.y"
                                 {(yyval.node) = newnode(Declaration, NULL); addchild((yyval.node), newnode(Null, NULL)); addchild((yyval.node), newnode(Identifier, (yyvsp[-2].token))); addchild((yyval.node), (yyvsp[0].node));}
#line 1594 "y.tab.c"
    break;

  case 33: /* Statement: LBRACE error RBRACE  */
#line 109 "uccompiler.y"
                               {(yyval.node)=newnode(Error,NULL); error_check=1;}
#line 1600 "y.tab.c"
    break;

  case 34: /* Statement: SEMI  */
#line 110 "uccompiler.y"
           {(yyval.node) = NULL;}
#line 1606 "y.tab.c"
    break;

  case 35: /* Statement: ExprList SEMI  */
#line 111 "uccompiler.y"
                    {(yyval.node) = (yyvsp[-1].node);}
#line 1612 "y.tab.c"
    break;

  case 36: /* Statement: LBRACE RBRACE  */
#line 112 "uccompiler.y"
                    {(yyval.node) = NULL;}
#line 1618 "y.tab.c"
    break;

  case 37: /* Statement: LBRACE Statements RBRACE  */
#line 113 "uccompiler.y"
                               {
                        if(stat_check == 1){
						    (yyval.node)=newnode(StatList, NULL);
						    addchild((yyval.node),(yyvsp[-1].node));
                        }
					    else{
						    (yyval.node) = (yyvsp[-1].node);
				    	}
                    }
#line 1632 "y.tab.c"
    break;

  case 38: /* Statement: IF LPAR ExprList RPAR StatementError  */
#line 122 "uccompiler.y"
                                           {
        (yyval.node) = newnode(If, NULL); addchild((yyval.node), (yyvsp[-2].node));
        if((yyvsp[0].node) == NULL){
            aux = newnode(Null,NULL);
            addchild((yyval.node),aux);
        }else{
            addchild((yyval.node), (yyvsp[0].node));
        }
        addchild((yyval.node), newnode(Null,NULL));
    }
#line 1647 "y.tab.c"
    break;

  case 39: /* Statement: IF LPAR ExprList RPAR StatementError ELSE StatementError  */
#line 132 "uccompiler.y"
                                                               {
        (yyval.node) = newnode(If, NULL); addchild((yyval.node), (yyvsp[-4].node));
        if((yyvsp[-2].node) == NULL){
            addchild((yyval.node),newnode(Null,NULL));
        }else{
            addchild((yyval.node),(yyvsp[-2].node));
        }

        if((yyvsp[0].node) == NULL){
            addchild((yyval.node),newnode(Null,NULL));
        }else{
            addchild((yyval.node),(yyvsp[0].node));
        }
    }
#line 1666 "y.tab.c"
    break;

  case 40: /* Statement: WHILE LPAR ExprList RPAR StatementError  */
#line 146 "uccompiler.y"
                                              {
        (yyval.node) = newnode(While, NULL); addchild((yyval.node), (yyvsp[-2].node));
        if((yyvsp[0].node) == NULL){
            addchild((yyval.node), newnode(Null,NULL));
        }else{
            addchild((yyval.node), (yyvsp[0].node));
        }
    }
#line 1679 "y.tab.c"
    break;

  case 41: /* Statement: RETURN SEMI  */
#line 154 "uccompiler.y"
                  {(yyval.node)=newnode(Return, NULL); addchild((yyval.node), newnode(Null,NULL));}
#line 1685 "y.tab.c"
    break;

  case 42: /* Statement: RETURN ExprList SEMI  */
#line 155 "uccompiler.y"
                           {(yyval.node)=newnode(Return, NULL); addchild((yyval.node), (yyvsp[-1].node));}
#line 1691 "y.tab.c"
    break;

  case 43: /* StatementError: error SEMI  */
#line 158 "uccompiler.y"
                           {(yyval.node)=newnode(Error,NULL); error_check=1;}
#line 1697 "y.tab.c"
    break;

  case 44: /* StatementError: Statement  */
#line 159 "uccompiler.y"
                {(yyval.node) = (yyvsp[0].node);}
#line 1703 "y.tab.c"
    break;

  case 45: /* Statements: StatementError  */
#line 161 "uccompiler.y"
                           {(yyval.node) = (yyvsp[0].node); stat_check = 0;}
#line 1709 "y.tab.c"
    break;

  case 46: /* Statements: Statements StatementError  */
#line 162 "uccompiler.y"
                                {(yyval.node)=(yyvsp[-1].node); addbrother((yyval.node),(yyvsp[0].node)); stat_check = 1;}
#line 1715 "y.tab.c"
    break;

  case 47: /* ExprList: Expr  */
#line 165 "uccompiler.y"
               {(yyval.node) = (yyvsp[0].node);}
#line 1721 "y.tab.c"
    break;

  case 48: /* ExprList: ExprList COMMA Expr  */
#line 166 "uccompiler.y"
                          {(yyval.node) = newnode(Comma, NULL); addchild((yyval.node), newnode(Expr,NULL)); addchild((yyval.node), (yyvsp[-2].node)); addchild((yyval.node), (yyvsp[0].node));}
#line 1727 "y.tab.c"
    break;

  case 49: /* ExprCall: ExprCall COMMA Expr  */
#line 169 "uccompiler.y"
                              {(yyval.node) = (yyvsp[-2].node); addbrother((yyval.node), (yyvsp[0].node));}
#line 1733 "y.tab.c"
    break;

  case 50: /* ExprCall: Expr  */
#line 170 "uccompiler.y"
           {(yyval.node) = (yyvsp[0].node);}
#line 1739 "y.tab.c"
    break;

  case 51: /* Expr: IDENTIFIER LPAR error RPAR  */
#line 173 "uccompiler.y"
                                 {(yyval.node)=newnode(Error,NULL); error_check=1;}
#line 1745 "y.tab.c"
    break;

  case 52: /* Expr: LPAR error RPAR  */
#line 174 "uccompiler.y"
                      {(yyval.node)=newnode(Error,NULL); error_check=1;}
#line 1751 "y.tab.c"
    break;

  case 53: /* Expr: IDENTIFIER  */
#line 175 "uccompiler.y"
                 {(yyval.node) = newnode(Identifier,(yyvsp[0].token)); addchild((yyval.node), newnode(Expr,NULL));}
#line 1757 "y.tab.c"
    break;

  case 54: /* Expr: NATURAL  */
#line 176 "uccompiler.y"
              {(yyval.node) = newnode(Natural,(yyvsp[0].token)); addchild((yyval.node), newnode(Expr,NULL));}
#line 1763 "y.tab.c"
    break;

  case 55: /* Expr: CHRLIT  */
#line 177 "uccompiler.y"
             {(yyval.node) = newnode(ChrLit,(yyvsp[0].token)); addchild((yyval.node), newnode(Expr,NULL));}
#line 1769 "y.tab.c"
    break;

  case 56: /* Expr: DECIMAL  */
#line 178 "uccompiler.y"
              {(yyval.node) = newnode(Decimal,(yyvsp[0].token)); addchild((yyval.node), newnode(Expr,NULL));}
#line 1775 "y.tab.c"
    break;

  case 57: /* Expr: LPAR ExprList RPAR  */
#line 179 "uccompiler.y"
                         {(yyval.node) = (yyvsp[-1].node);}
#line 1781 "y.tab.c"
    break;

  case 58: /* Expr: Expr ASSIGN Expr  */
#line 180 "uccompiler.y"
                       {(yyval.node) = newnode(Store, NULL); addchild((yyval.node), newnode(Expr,NULL)); addchild((yyval.node), (yyvsp[-2].node)); addchild((yyval.node), (yyvsp[0].node));}
#line 1787 "y.tab.c"
    break;

  case 59: /* Expr: Expr PLUS Expr  */
#line 181 "uccompiler.y"
                     {(yyval.node) = newnode(Add, NULL); addchild((yyval.node), newnode(Expr,NULL)); addchild((yyval.node), (yyvsp[-2].node)); addchild((yyval.node), (yyvsp[0].node));}
#line 1793 "y.tab.c"
    break;

  case 60: /* Expr: Expr MINUS Expr  */
#line 182 "uccompiler.y"
                      {(yyval.node) = newnode(Sub, NULL); addchild((yyval.node), newnode(Expr,NULL)); addchild((yyval.node), (yyvsp[-2].node)); addchild((yyval.node), (yyvsp[0].node));}
#line 1799 "y.tab.c"
    break;

  case 61: /* Expr: Expr MUL Expr  */
#line 183 "uccompiler.y"
                    {(yyval.node) = newnode(Mul, NULL); addchild((yyval.node), newnode(Expr,NULL)); addchild((yyval.node), (yyvsp[-2].node)); addchild((yyval.node), (yyvsp[0].node));}
#line 1805 "y.tab.c"
    break;

  case 62: /* Expr: Expr DIV Expr  */
#line 184 "uccompiler.y"
                    {(yyval.node) = newnode(Div, NULL); addchild((yyval.node), newnode(Expr,NULL)); addchild((yyval.node), (yyvsp[-2].node)); addchild((yyval.node), (yyvsp[0].node));}
#line 1811 "y.tab.c"
    break;

  case 63: /* Expr: Expr MOD Expr  */
#line 185 "uccompiler.y"
                    {(yyval.node) = newnode(Mod, NULL); addchild((yyval.node), newnode(Expr,NULL)); addchild((yyval.node), (yyvsp[-2].node)); addchild((yyval.node), (yyvsp[0].node));}
#line 1817 "y.tab.c"
    break;

  case 64: /* Expr: Expr OR Expr  */
#line 186 "uccompiler.y"
                   {(yyval.node) = newnode(Or, NULL); addchild((yyval.node), newnode(Expr,NULL)); addchild((yyval.node), (yyvsp[-2].node)); addchild((yyval.node), (yyvsp[0].node));}
#line 1823 "y.tab.c"
    break;

  case 65: /* Expr: Expr AND Expr  */
#line 187 "uccompiler.y"
                    {(yyval.node) = newnode(And, NULL); addchild((yyval.node), newnode(Expr,NULL)); addchild((yyval.node), (yyvsp[-2].node)); addchild((yyval.node), (yyvsp[0].node));}
#line 1829 "y.tab.c"
    break;

  case 66: /* Expr: Expr BITWISEOR Expr  */
#line 188 "uccompiler.y"
                          {(yyval.node) = newnode(BitWiseOr, NULL); addchild((yyval.node), newnode(Expr,NULL)); addchild((yyval.node), (yyvsp[-2].node)); addchild((yyval.node), (yyvsp[0].node));}
#line 1835 "y.tab.c"
    break;

  case 67: /* Expr: Expr BITWISEXOR Expr  */
#line 189 "uccompiler.y"
                           {(yyval.node) = newnode(BitWiseXor, NULL); addchild((yyval.node), newnode(Expr,NULL)); addchild((yyval.node), (yyvsp[-2].node)); addchild((yyval.node), (yyvsp[0].node));}
#line 1841 "y.tab.c"
    break;

  case 68: /* Expr: Expr BITWISEAND Expr  */
#line 190 "uccompiler.y"
                           {(yyval.node) = newnode(BitWiseAnd, NULL); addchild((yyval.node), newnode(Expr,NULL)); addchild((yyval.node), (yyvsp[-2].node)); addchild((yyval.node), (yyvsp[0].node));}
#line 1847 "y.tab.c"
    break;

  case 69: /* Expr: Expr EQ Expr  */
#line 191 "uccompiler.y"
                   {(yyval.node) = newnode(Eq, NULL); addchild((yyval.node), newnode(Expr,NULL)); addchild((yyval.node), (yyvsp[-2].node)); addchild((yyval.node), (yyvsp[0].node));}
#line 1853 "y.tab.c"
    break;

  case 70: /* Expr: Expr NE Expr  */
#line 192 "uccompiler.y"
                   {(yyval.node) = newnode(Ne, NULL); addchild((yyval.node), newnode(Expr,NULL)); addchild((yyval.node), (yyvsp[-2].node)); addchild((yyval.node), (yyvsp[0].node));}
#line 1859 "y.tab.c"
    break;

  case 71: /* Expr: Expr LE Expr  */
#line 193 "uccompiler.y"
                   {(yyval.node) = newnode(Le, NULL); addchild((yyval.node), newnode(Expr,NULL)); addchild((yyval.node), (yyvsp[-2].node)); addchild((yyval.node), (yyvsp[0].node));}
#line 1865 "y.tab.c"
    break;

  case 72: /* Expr: Expr GE Expr  */
#line 194 "uccompiler.y"
                   {(yyval.node) = newnode(Ge, NULL); addchild((yyval.node), newnode(Expr,NULL)); addchild((yyval.node), (yyvsp[-2].node)); addchild((yyval.node), (yyvsp[0].node));}
#line 1871 "y.tab.c"
    break;

  case 73: /* Expr: Expr LT Expr  */
#line 195 "uccompiler.y"
                   {(yyval.node) = newnode(Lt, NULL); addchild((yyval.node), newnode(Expr,NULL)); addchild((yyval.node), (yyvsp[-2].node)); addchild((yyval.node), (yyvsp[0].node));}
#line 1877 "y.tab.c"
    break;

  case 74: /* Expr: Expr GT Expr  */
#line 196 "uccompiler.y"
                   {(yyval.node) = newnode(Gt, NULL); addchild((yyval.node), newnode(Expr,NULL)); addchild((yyval.node), (yyvsp[-2].node)); addchild((yyval.node), (yyvsp[0].node));}
#line 1883 "y.tab.c"
    break;

  case 75: /* Expr: MINUS Expr  */
#line 197 "uccompiler.y"
                           {(yyval.node) = newnode(Minus, NULL); addchild((yyval.node), newnode(Expr,NULL)); addchild((yyval.node), (yyvsp[0].node));}
#line 1889 "y.tab.c"
    break;

  case 76: /* Expr: PLUS Expr  */
#line 198 "uccompiler.y"
                          {(yyval.node) = newnode(Plus, NULL); addchild((yyval.node), newnode(Expr,NULL)); addchild((yyval.node), (yyvsp[0].node));}
#line 1895 "y.tab.c"
    break;

  case 77: /* Expr: NOT Expr  */
#line 199 "uccompiler.y"
               {(yyval.node) = newnode(Not, NULL); addchild((yyval.node), newnode(Expr,NULL)); addchild((yyval.node), (yyvsp[0].node));}
#line 1901 "y.tab.c"
    break;

  case 78: /* Expr: IDENTIFIER LPAR RPAR  */
#line 200 "uccompiler.y"
                           {(yyval.node) = newnode(Call, NULL); addchild((yyval.node), newnode(Expr,NULL)); aux=newnode(Identifier, (yyvsp[-2].token)); addchild((yyval.node), aux); addchild(aux, newnode(Expr,NULL));}
#line 1907 "y.tab.c"
    break;

  case 79: /* Expr: IDENTIFIER LPAR ExprCall RPAR  */
#line 201 "uccompiler.y"
                                    {(yyval.node) = newnode(Call, NULL); addchild((yyval.node), newnode(Expr,NULL)); aux=newnode(Identifier, (yyvsp[-3].token));    addchild((yyval.node), aux); addchild(aux, newnode(Expr,NULL)); addchild((yyval.node), (yyvsp[-1].node));}
#line 1913 "y.tab.c"
    break;


#line 1917 "y.tab.c"

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


      yydestruct ("Error: popping",
                  YY_ACCESSING_SYMBOL (yystate), yyvsp);
      YYPOPSTACK (1);
      yystate = *yyssp;
      YY_STACK_PRINT (yyss, yyssp);
    }

  YY_IGNORE_MAYBE_UNINITIALIZED_BEGIN
  *++yyvsp = yylval;
  YY_IGNORE_MAYBE_UNINITIALIZED_END


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
                  yytoken, &yylval);
    }
  /* Do not reclaim the symbols of the rule whose action triggered
     this YYABORT or YYACCEPT.  */
  YYPOPSTACK (yylen);
  YY_STACK_PRINT (yyss, yyssp);
  while (yyssp != yyss)
    {
      yydestruct ("Cleanup: popping",
                  YY_ACCESSING_SYMBOL (+*yyssp), yyvsp);
      YYPOPSTACK (1);
    }
#ifndef yyoverflow
  if (yyss != yyssa)
    YYSTACK_FREE (yyss);
#endif

  return yyresult;
}

#line 203 "uccompiler.y"
