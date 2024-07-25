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
#line 1 "parser.y"

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef struct node {
    char *token;
    struct node *left;
    struct node *right;
} node;

node* mkleaf(char* token);
node* mknode(char* token, node* left, node* right);
void printtree(node* tree);
extern int yylineno;
extern char* yytext;

int yyerror(char* e);


#line 92 "y.tab.c"

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
# define YYDEBUG 0
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
    BOOL = 258,                    /* BOOL  */
    CHAR = 259,                    /* CHAR  */
    INT = 260,                     /* INT  */
    STRING = 261,                  /* STRING  */
    FLOAT = 262,                   /* FLOAT  */
    DOUBLE = 263,                  /* DOUBLE  */
    VOID = 264,                    /* VOID  */
    IF = 265,                      /* IF  */
    BOOL_TRUE = 266,               /* BOOL_TRUE  */
    BOOL_FALSE = 267,              /* BOOL_FALSE  */
    ELSE = 268,                    /* ELSE  */
    WHILE = 269,                   /* WHILE  */
    FOR = 270,                     /* FOR  */
    VAR = 271,                     /* VAR  */
    MAIN = 272,                    /* MAIN  */
    RETURN = 273,                  /* RETURN  */
    NULL_ = 274,                   /* NULL_  */
    DO = 275,                      /* DO  */
    PUBLIC = 276,                  /* PUBLIC  */
    PRIVATE = 277,                 /* PRIVATE  */
    STATIC = 278,                  /* STATIC  */
    ARGS = 279,                    /* ARGS  */
    IDENTIFIER = 280,              /* IDENTIFIER  */
    INTEGER = 281,                 /* INTEGER  */
    FLOAT_LITERAL = 282,           /* FLOAT_LITERAL  */
    CHAR_LITERAL = 283,            /* CHAR_LITERAL  */
    STRING_LITERAL = 284,          /* STRING_LITERAL  */
    INT_POINTER = 285,             /* INT_POINTER  */
    CHAR_POINTER = 286,            /* CHAR_POINTER  */
    REAL_POINTER = 287,            /* REAL_POINTER  */
    FLOAT_POINTER = 288,           /* FLOAT_POINTER  */
    AND = 289,                     /* AND  */
    OR = 290,                      /* OR  */
    EQ = 291,                      /* EQ  */
    NE = 292,                      /* NE  */
    GE = 293,                      /* GE  */
    LE = 294,                      /* LE  */
    ASSIGN = 295                   /* ASSIGN  */
  };
  typedef enum yytokentype yytoken_kind_t;
#endif
/* Token kinds.  */
#define YYEMPTY -2
#define YYEOF 0
#define YYerror 256
#define YYUNDEF 257
#define BOOL 258
#define CHAR 259
#define INT 260
#define STRING 261
#define FLOAT 262
#define DOUBLE 263
#define VOID 264
#define IF 265
#define BOOL_TRUE 266
#define BOOL_FALSE 267
#define ELSE 268
#define WHILE 269
#define FOR 270
#define VAR 271
#define MAIN 272
#define RETURN 273
#define NULL_ 274
#define DO 275
#define PUBLIC 276
#define PRIVATE 277
#define STATIC 278
#define ARGS 279
#define IDENTIFIER 280
#define INTEGER 281
#define FLOAT_LITERAL 282
#define CHAR_LITERAL 283
#define STRING_LITERAL 284
#define INT_POINTER 285
#define CHAR_POINTER 286
#define REAL_POINTER 287
#define FLOAT_POINTER 288
#define AND 289
#define OR 290
#define EQ 291
#define NE 292
#define GE 293
#define LE 294
#define ASSIGN 295

/* Value type.  */
#if ! defined YYSTYPE && ! defined YYSTYPE_IS_DECLARED
union YYSTYPE
{
#line 22 "parser.y"

  char* string; 
  struct node* node;

#line 230 "y.tab.c"

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
  YYSYMBOL_BOOL = 3,                       /* BOOL  */
  YYSYMBOL_CHAR = 4,                       /* CHAR  */
  YYSYMBOL_INT = 5,                        /* INT  */
  YYSYMBOL_STRING = 6,                     /* STRING  */
  YYSYMBOL_FLOAT = 7,                      /* FLOAT  */
  YYSYMBOL_DOUBLE = 8,                     /* DOUBLE  */
  YYSYMBOL_VOID = 9,                       /* VOID  */
  YYSYMBOL_IF = 10,                        /* IF  */
  YYSYMBOL_BOOL_TRUE = 11,                 /* BOOL_TRUE  */
  YYSYMBOL_BOOL_FALSE = 12,                /* BOOL_FALSE  */
  YYSYMBOL_ELSE = 13,                      /* ELSE  */
  YYSYMBOL_WHILE = 14,                     /* WHILE  */
  YYSYMBOL_FOR = 15,                       /* FOR  */
  YYSYMBOL_VAR = 16,                       /* VAR  */
  YYSYMBOL_MAIN = 17,                      /* MAIN  */
  YYSYMBOL_RETURN = 18,                    /* RETURN  */
  YYSYMBOL_NULL_ = 19,                     /* NULL_  */
  YYSYMBOL_DO = 20,                        /* DO  */
  YYSYMBOL_PUBLIC = 21,                    /* PUBLIC  */
  YYSYMBOL_PRIVATE = 22,                   /* PRIVATE  */
  YYSYMBOL_STATIC = 23,                    /* STATIC  */
  YYSYMBOL_ARGS = 24,                      /* ARGS  */
  YYSYMBOL_IDENTIFIER = 25,                /* IDENTIFIER  */
  YYSYMBOL_INTEGER = 26,                   /* INTEGER  */
  YYSYMBOL_FLOAT_LITERAL = 27,             /* FLOAT_LITERAL  */
  YYSYMBOL_CHAR_LITERAL = 28,              /* CHAR_LITERAL  */
  YYSYMBOL_STRING_LITERAL = 29,            /* STRING_LITERAL  */
  YYSYMBOL_INT_POINTER = 30,               /* INT_POINTER  */
  YYSYMBOL_CHAR_POINTER = 31,              /* CHAR_POINTER  */
  YYSYMBOL_REAL_POINTER = 32,              /* REAL_POINTER  */
  YYSYMBOL_FLOAT_POINTER = 33,             /* FLOAT_POINTER  */
  YYSYMBOL_AND = 34,                       /* AND  */
  YYSYMBOL_OR = 35,                        /* OR  */
  YYSYMBOL_EQ = 36,                        /* EQ  */
  YYSYMBOL_NE = 37,                        /* NE  */
  YYSYMBOL_GE = 38,                        /* GE  */
  YYSYMBOL_LE = 39,                        /* LE  */
  YYSYMBOL_ASSIGN = 40,                    /* ASSIGN  */
  YYSYMBOL_41_ = 41,                       /* '('  */
  YYSYMBOL_42_ = 42,                       /* ')'  */
  YYSYMBOL_43_ = 43,                       /* '{'  */
  YYSYMBOL_44_ = 44,                       /* '}'  */
  YYSYMBOL_45_ = 45,                       /* ':'  */
  YYSYMBOL_46_ = 46,                       /* ';'  */
  YYSYMBOL_47_ = 47,                       /* ','  */
  YYSYMBOL_48_ = 48,                       /* '['  */
  YYSYMBOL_49_ = 49,                       /* ']'  */
  YYSYMBOL_50_ = 50,                       /* '+'  */
  YYSYMBOL_51_ = 51,                       /* '-'  */
  YYSYMBOL_52_ = 52,                       /* '*'  */
  YYSYMBOL_53_ = 53,                       /* '/'  */
  YYSYMBOL_54_ = 54,                       /* '>'  */
  YYSYMBOL_55_ = 55,                       /* '<'  */
  YYSYMBOL_YYACCEPT = 56,                  /* $accept  */
  YYSYMBOL_PROGRAM = 57,                   /* PROGRAM  */
  YYSYMBOL_CODE = 58,                      /* CODE  */
  YYSYMBOL_FUNCTIONS = 59,                 /* FUNCTIONS  */
  YYSYMBOL_FUNCTION = 60,                  /* FUNCTION  */
  YYSYMBOL_HAS_PARAMS = 61,                /* HAS_PARAMS  */
  YYSYMBOL_FUNCTION_MOD = 62,              /* FUNCTION_MOD  */
  YYSYMBOL_PARAMETER_LIST = 63,            /* PARAMETER_LIST  */
  YYSYMBOL_PARAMETER = 64,                 /* PARAMETER  */
  YYSYMBOL_IDENTIFIERS = 65,               /* IDENTIFIERS  */
  YYSYMBOL_PARAMETER_TYPE = 66,            /* PARAMETER_TYPE  */
  YYSYMBOL_FUNCTION_TYPE = 67,             /* FUNCTION_TYPE  */
  YYSYMBOL_FUNCTION_BODY = 68,             /* FUNCTION_BODY  */
  YYSYMBOL_DECLARATIONS = 69,              /* DECLARATIONS  */
  YYSYMBOL_STATEMENTS = 70,                /* STATEMENTS  */
  YYSYMBOL_NESTED_FUNCTIONS = 71,          /* NESTED_FUNCTIONS  */
  YYSYMBOL_STATEMENT = 72,                 /* STATEMENT  */
  YYSYMBOL_DECLARATION = 73,               /* DECLARATION  */
  YYSYMBOL_VAR_DECLARATION = 74,           /* VAR_DECLARATION  */
  YYSYMBOL_VAR_ASSIGN_LIST = 75,           /* VAR_ASSIGN_LIST  */
  YYSYMBOL_STRING_DECLARATION = 76,        /* STRING_DECLARATION  */
  YYSYMBOL_STRING_DECL_LIST = 77,          /* STRING_DECL_LIST  */
  YYSYMBOL_STRING_DECL_ELEM = 78,          /* STRING_DECL_ELEM  */
  YYSYMBOL_EXPR = 79                       /* EXPR  */
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
#define YYFINAL  18
/* YYLAST -- Last index in YYTABLE.  */
#define YYLAST   413

/* YYNTOKENS -- Number of terminals.  */
#define YYNTOKENS  56
/* YYNNTS -- Number of nonterminals.  */
#define YYNNTS  24
/* YYNRULES -- Number of rules.  */
#define YYNRULES  91
/* YYNSTATES -- Number of states.  */
#define YYNSTATES  207

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
      41,    42,    52,    50,    47,    51,     2,    53,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,    45,    46,
      55,     2,    54,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,    48,     2,    49,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,    43,     2,    44,     2,     2,     2,     2,
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
       0,    39,    39,    42,    45,    46,    49,    50,    51,    52,
      53,    54,    57,    58,    60,    61,    63,    64,    67,    70,
      71,    74,    75,    76,    77,    78,    79,    80,    81,    84,
      85,    86,    87,    88,    89,    90,    91,    92,    95,    96,
      97,   100,   101,   102,   103,   104,   105,   108,   109,   112,
     113,   116,   117,   118,   119,   120,   121,   122,   123,   124,
     125,   128,   131,   134,   135,   136,   137,   140,   143,   144,
     147,   148,   151,   152,   153,   154,   155,   156,   157,   158,
     159,   160,   161,   162,   163,   164,   165,   166,   167,   168,
     169,   170
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
  "\"end of file\"", "error", "\"invalid token\"", "BOOL", "CHAR", "INT",
  "STRING", "FLOAT", "DOUBLE", "VOID", "IF", "BOOL_TRUE", "BOOL_FALSE",
  "ELSE", "WHILE", "FOR", "VAR", "MAIN", "RETURN", "NULL_", "DO", "PUBLIC",
  "PRIVATE", "STATIC", "ARGS", "IDENTIFIER", "INTEGER", "FLOAT_LITERAL",
  "CHAR_LITERAL", "STRING_LITERAL", "INT_POINTER", "CHAR_POINTER",
  "REAL_POINTER", "FLOAT_POINTER", "AND", "OR", "EQ", "NE", "GE", "LE",
  "ASSIGN", "'('", "')'", "'{'", "'}'", "':'", "';'", "','", "'['", "']'",
  "'+'", "'-'", "'*'", "'/'", "'>'", "'<'", "$accept", "PROGRAM", "CODE",
  "FUNCTIONS", "FUNCTION", "HAS_PARAMS", "FUNCTION_MOD", "PARAMETER_LIST",
  "PARAMETER", "IDENTIFIERS", "PARAMETER_TYPE", "FUNCTION_TYPE",
  "FUNCTION_BODY", "DECLARATIONS", "STATEMENTS", "NESTED_FUNCTIONS",
  "STATEMENT", "DECLARATION", "VAR_DECLARATION", "VAR_ASSIGN_LIST",
  "STRING_DECLARATION", "STRING_DECL_LIST", "STRING_DECL_ELEM", "EXPR", YY_NULLPTR
};

static const char *
yysymbol_name (yysymbol_kind_t yysymbol)
{
  return yytname[yysymbol];
}
#endif

#define YYPACT_NINF (-158)

#define yypact_value_is_default(Yyn) \
  ((Yyn) == YYPACT_NINF)

#define YYTABLE_NINF (-60)

#define yytable_value_is_error(Yyn) \
  0

/* YYPACT[STATE-NUM] -- Index in YYTABLE of the portion describing
   STATE-NUM.  */
static const yytype_int16 yypact[] =
{
      59,   195,   195,    11,  -158,  -158,    59,  -158,  -158,  -158,
    -158,  -158,  -158,  -158,  -158,  -158,     0,    23,  -158,  -158,
     -20,    35,   -10,    -4,   203,   -27,    22,    41,    44,  -158,
    -158,  -158,  -158,  -158,  -158,  -158,  -158,  -158,    46,    53,
      89,   -14,    89,     4,   203,    77,    81,    72,  -158,  -158,
      82,    83,   203,   165,   195,   195,    86,  -158,  -158,  -158,
    -158,   165,   102,    87,   156,  -158,    69,   156,    92,     2,
       6,   204,    89,   110,    91,    93,    89,    95,  -158,    88,
    -158,    97,    90,    99,   165,   165,   156,    94,  -158,   226,
     115,   122,   165,   232,  -158,  -158,  -158,  -158,  -158,  -158,
      69,    69,  -158,   165,  -158,  -158,   165,   165,   165,   165,
     165,   165,  -158,   165,   165,   165,   165,   165,   165,   104,
    -158,    89,  -158,   105,    89,    77,   124,  -158,    81,   254,
     276,   165,   126,  -158,   112,   116,   286,  -158,   308,   358,
     358,   358,   358,   358,   358,   358,   358,   358,   358,   358,
     358,  -158,   114,  -158,   121,  -158,   120,  -158,   130,   132,
     330,     5,   133,   154,   154,  -158,  -158,  -158,  -158,   140,
      89,    89,   156,   165,   126,  -158,   153,   159,   167,   161,
     168,   171,   352,  -158,   164,   164,  -158,   201,  -158,   172,
     126,   173,   174,   175,    89,  -158,    89,    89,    89,   176,
     177,   178,   179,  -158,  -158,  -158,  -158
};

/* YYDEFACT[STATE-NUM] -- Default reduction number in state STATE-NUM.
   Performed when YYTABLE does not specify something else to do.  Zero
   means the default is an error.  */
static const yytype_int8 yydefact[] =
{
       0,     0,     0,     0,     2,     3,     5,    37,    33,    30,
      31,    32,    29,    34,    35,    36,     0,     0,     1,     4,
       0,     0,     0,     0,     0,     0,     0,     0,     0,    24,
      21,    22,    23,    25,    26,    27,    28,    12,    16,     0,
      40,     0,    40,     0,     0,     0,     0,     0,    89,    90,
       0,     0,     0,     0,     0,     0,    84,    85,    86,    87,
      88,     0,     0,     0,     0,    39,    45,    48,     0,    44,
      46,     0,    40,     0,     0,     0,    40,     0,    17,    20,
      18,     0,     0,    69,     0,     0,     0,     0,    84,     0,
       0,     0,     0,     0,    61,    10,    38,    58,    59,    42,
      44,    46,    47,     0,    41,    43,     0,     0,     0,     0,
       0,     0,    60,     0,     0,     0,     0,     0,     0,     0,
      14,    40,    11,     0,    40,     0,     0,    67,     0,     0,
       0,     0,     0,    55,     0,     0,     0,    91,     0,    82,
      83,    76,    77,    78,    79,    72,    73,    74,    75,    80,
      81,     8,     0,     9,     0,    19,     0,    68,     0,     0,
       0,    65,     0,    13,    13,    56,    57,     6,     7,    71,
      40,    40,     0,     0,     0,    62,     0,     0,     0,     0,
       0,     0,    63,    66,    15,    15,    70,    51,    53,     0,
       0,     0,     0,     0,    40,    64,    40,    40,    40,     0,
       0,     0,     0,    54,    49,    50,    52
};

/* YYPGOTO[NTERM-NUM].  */
static const yytype_int16 yypgoto[] =
{
    -158,  -158,  -158,   213,  -158,   -22,   -41,   180,  -158,   103,
      -9,    17,   -42,     8,   -25,  -158,   -83,  -158,   -60,  -157,
     -13,   101,  -158,   -48
};

/* YYDEFGOTO[NTERM-NUM].  */
static const yytype_uint8 yydefgoto[] =
{
       0,     3,     4,     5,     6,    26,    74,    37,    38,    80,
      62,    16,    63,    64,    65,    66,    67,    68,    69,   162,
      70,    82,    83,    71
};

/* YYTABLE[YYPACT[STATE-NUM]] -- What to do in state STATE-NUM.  If
   positive, shift that token.  If negative, reduce the rule whose
   number is the opposite.  If YYTABLE_NINF, syntax error.  */
static const yytype_int16 yytable[] =
{
      75,    28,    77,   131,    97,    89,   100,    97,    46,   100,
     100,    18,    46,    93,    24,    39,    40,   183,    52,    17,
      24,    22,    52,    54,    55,    20,    97,    54,    55,    72,
     119,    73,    25,   195,   123,    39,   129,   130,    27,    96,
     100,   100,   102,    87,   136,   173,   -58,    76,    21,    73,
     -59,    98,   174,   101,    98,   138,   101,   101,   139,   140,
     141,   142,   143,   144,    41,   145,   146,   147,   148,   149,
     150,    90,    91,    98,    99,    46,    23,   104,   105,   152,
       1,     2,   154,   160,    42,    52,    43,   101,   101,   181,
      54,    55,    44,    29,    30,    46,    31,    32,    45,    47,
      48,    49,    79,    50,    51,    52,    81,    53,   104,   105,
      54,    55,    97,    84,    56,    57,    58,    59,    60,    33,
      34,    35,    36,    85,    86,   182,    92,    94,   179,   180,
      61,    95,   103,   120,   121,   125,   127,   122,   124,   132,
     134,   176,   177,   191,   192,   126,   128,   135,   151,   153,
     156,   161,   199,   163,   200,   201,   202,   164,   167,    98,
      29,    30,    46,    31,    32,   168,    47,    48,    49,   169,
      50,    51,    52,   170,    53,   171,    48,    49,    24,   175,
     178,    56,    57,    58,    59,    60,    33,    34,    35,    36,
      88,    57,    58,    59,    60,   184,   186,    61,     7,     8,
       9,   185,    10,    11,    12,   187,    61,    29,    30,    73,
      31,    32,   188,   189,   193,   194,   196,   197,   198,    19,
     203,   204,   205,   206,    78,    13,    14,    15,   155,   157,
       0,     0,     0,    33,    34,    35,    36,     0,   106,   107,
     108,   109,   110,   111,     0,     0,     0,     0,     0,     0,
     112,     0,     0,     0,   113,   114,   115,   116,   117,   118,
     106,   107,   108,   109,   110,   111,   106,   107,   108,   109,
     110,   111,   133,     0,   137,     0,   113,   114,   115,   116,
     117,   118,   113,   114,   115,   116,   117,   118,   106,   107,
     108,   109,   110,   111,     0,     0,   158,     0,     0,     0,
       0,     0,     0,     0,   113,   114,   115,   116,   117,   118,
     106,   107,   108,   109,   110,   111,     0,     0,   159,     0,
     106,   107,   108,   109,   110,   111,   113,   114,   115,   116,
     117,   118,   165,     0,     0,     0,   113,   114,   115,   116,
     117,   118,   106,   107,   108,   109,   110,   111,     0,     0,
       0,     0,     0,     0,   166,     0,     0,     0,   113,   114,
     115,   116,   117,   118,   106,   107,   108,   109,   110,   111,
       0,     0,     0,     0,     0,     0,   172,     0,     0,     0,
     113,   114,   115,   116,   117,   118,   106,   107,   108,   109,
     110,   111,   106,   107,   108,   109,   110,   111,     0,   190,
       0,     0,   113,   114,   115,   116,   117,   118,   113,   114,
     115,   116,   117,   118
};

static const yytype_int16 yycheck[] =
{
      42,    23,    43,    86,    64,    53,    66,    67,     6,    69,
      70,     0,     6,    61,    24,    24,    43,   174,    16,     2,
      24,    41,    16,    21,    22,    25,    86,    21,    22,    43,
      72,    45,    42,   190,    76,    44,    84,    85,    42,    64,
     100,   101,    67,    52,    92,    40,    44,    43,    25,    45,
      44,    64,    47,    66,    67,   103,    69,    70,   106,   107,
     108,   109,   110,   111,    42,   113,   114,   115,   116,   117,
     118,    54,    55,    86,    66,     6,    41,    69,    70,   121,
      21,    22,   124,   131,    43,    16,    42,   100,   101,   172,
      21,    22,    46,     4,     5,     6,     7,     8,    45,    10,
      11,    12,    25,    14,    15,    16,    25,    18,   100,   101,
      21,    22,   172,    41,    25,    26,    27,    28,    29,    30,
      31,    32,    33,    41,    41,   173,    40,    25,   170,   171,
      41,    44,    40,    23,    43,    47,    46,    44,    43,    45,
      25,   163,   164,   184,   185,    48,    47,    25,    44,    44,
      26,    25,   194,    41,   196,   197,   198,    41,    44,   172,
       4,     5,     6,     7,     8,    44,    10,    11,    12,    49,
      14,    15,    16,    43,    18,    43,    11,    12,    24,    46,
      40,    25,    26,    27,    28,    29,    30,    31,    32,    33,
      25,    26,    27,    28,    29,    42,    29,    41,     3,     4,
       5,    42,     7,     8,     9,    44,    41,     4,     5,    45,
       7,     8,    44,    42,    13,    43,    43,    43,    43,     6,
      44,    44,    44,    44,    44,    30,    31,    32,   125,   128,
      -1,    -1,    -1,    30,    31,    32,    33,    -1,    34,    35,
      36,    37,    38,    39,    -1,    -1,    -1,    -1,    -1,    -1,
      46,    -1,    -1,    -1,    50,    51,    52,    53,    54,    55,
      34,    35,    36,    37,    38,    39,    34,    35,    36,    37,
      38,    39,    46,    -1,    42,    -1,    50,    51,    52,    53,
      54,    55,    50,    51,    52,    53,    54,    55,    34,    35,
      36,    37,    38,    39,    -1,    -1,    42,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    50,    51,    52,    53,    54,    55,
      34,    35,    36,    37,    38,    39,    -1,    -1,    42,    -1,
      34,    35,    36,    37,    38,    39,    50,    51,    52,    53,
      54,    55,    46,    -1,    -1,    -1,    50,    51,    52,    53,
      54,    55,    34,    35,    36,    37,    38,    39,    -1,    -1,
      -1,    -1,    -1,    -1,    46,    -1,    -1,    -1,    50,    51,
      52,    53,    54,    55,    34,    35,    36,    37,    38,    39,
      -1,    -1,    -1,    -1,    -1,    -1,    46,    -1,    -1,    -1,
      50,    51,    52,    53,    54,    55,    34,    35,    36,    37,
      38,    39,    34,    35,    36,    37,    38,    39,    -1,    47,
      -1,    -1,    50,    51,    52,    53,    54,    55,    50,    51,
      52,    53,    54,    55
};

/* YYSTOS[STATE-NUM] -- The symbol kind of the accessing symbol of
   state STATE-NUM.  */
static const yytype_int8 yystos[] =
{
       0,    21,    22,    57,    58,    59,    60,     3,     4,     5,
       7,     8,     9,    30,    31,    32,    67,    67,     0,    59,
      25,    25,    41,    41,    24,    42,    61,    42,    61,     4,
       5,     7,     8,    30,    31,    32,    33,    63,    64,    66,
      43,    42,    43,    42,    46,    45,     6,    10,    11,    12,
      14,    15,    16,    18,    21,    22,    25,    26,    27,    28,
      29,    41,    66,    68,    69,    70,    71,    72,    73,    74,
      76,    79,    43,    45,    62,    68,    43,    62,    63,    25,
      65,    25,    77,    78,    41,    41,    41,    66,    25,    79,
      67,    67,    40,    79,    25,    44,    70,    74,    76,    69,
      74,    76,    70,    40,    69,    69,    34,    35,    36,    37,
      38,    39,    46,    50,    51,    52,    53,    54,    55,    68,
      23,    43,    44,    68,    43,    47,    48,    46,    47,    79,
      79,    72,    45,    46,    25,    25,    79,    42,    79,    79,
      79,    79,    79,    79,    79,    79,    79,    79,    79,    79,
      79,    44,    68,    44,    68,    65,    26,    77,    42,    42,
      79,    25,    75,    41,    41,    46,    46,    44,    44,    49,
      43,    43,    46,    40,    47,    46,    61,    61,    40,    68,
      68,    72,    79,    75,    42,    42,    29,    44,    44,    42,
      47,    62,    62,    13,    43,    75,    43,    43,    43,    68,
      68,    68,    68,    44,    44,    44,    44
};

/* YYR1[RULE-NUM] -- Symbol kind of the left-hand side of rule RULE-NUM.  */
static const yytype_int8 yyr1[] =
{
       0,    56,    57,    58,    59,    59,    60,    60,    60,    60,
      60,    60,    61,    61,    62,    62,    63,    63,    64,    65,
      65,    66,    66,    66,    66,    66,    66,    66,    66,    67,
      67,    67,    67,    67,    67,    67,    67,    67,    68,    68,
      68,    69,    69,    69,    69,    69,    69,    70,    70,    71,
      71,    72,    72,    72,    72,    72,    72,    72,    72,    72,
      72,    73,    74,    75,    75,    75,    75,    76,    77,    77,
      78,    78,    79,    79,    79,    79,    79,    79,    79,    79,
      79,    79,    79,    79,    79,    79,    79,    79,    79,    79,
      79,    79
};

/* YYR2[RULE-NUM] -- Number of symbols on the right-hand side of rule RULE-NUM.  */
static const yytype_int8 yyr2[] =
{
       0,     2,     1,     1,     2,     1,    10,    10,     9,     9,
       8,     8,     2,     0,     2,     0,     1,     3,     3,     3,
       1,     1,     1,     1,     1,     1,     1,     1,     1,     1,
       1,     1,     1,     1,     1,     1,     1,     1,     2,     1,
       0,     2,     2,     2,     1,     1,     1,     2,     1,    10,
      10,     7,    11,     7,    10,     3,     4,     4,     1,     1,
       2,     2,     5,     3,     5,     1,     3,     3,     3,     1,
       6,     4,     3,     3,     3,     3,     3,     3,     3,     3,
       3,     3,     3,     3,     1,     1,     1,     1,     1,     1,
       1,     3
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
  case 2: /* PROGRAM: CODE  */
#line 39 "parser.y"
                       { printtree((yyvsp[0].node)); }
#line 1462 "y.tab.c"
    break;

  case 3: /* CODE: FUNCTIONS  */
#line 42 "parser.y"
                            { (yyval.node) = mknode("CODE", (yyvsp[0].node), NULL); }
#line 1468 "y.tab.c"
    break;

  case 4: /* FUNCTIONS: FUNCTION FUNCTIONS  */
#line 45 "parser.y"
                                     { (yyval.node) = mknode("FUNCTIONS", (yyvsp[-1].node), (yyvsp[0].node)); }
#line 1474 "y.tab.c"
    break;

  case 5: /* FUNCTIONS: FUNCTION  */
#line 46 "parser.y"
                           { (yyval.node) = mknode("FUNCTIONS", (yyvsp[0].node), NULL); }
#line 1480 "y.tab.c"
    break;

  case 6: /* FUNCTION: PUBLIC FUNCTION_TYPE IDENTIFIER '(' HAS_PARAMS ')' FUNCTION_MOD '{' FUNCTION_BODY '}'  */
#line 49 "parser.y"
                                                                                                        { (yyval.node) = mknode("FUNC", mknode("PUBLIC", mkleaf((yyvsp[-7].string)), NULL), mknode("PARAMS", (yyvsp[-5].node), mknode("BODY", (yyvsp[-3].string), (yyvsp[-1].node)))); }
#line 1486 "y.tab.c"
    break;

  case 7: /* FUNCTION: PRIVATE FUNCTION_TYPE IDENTIFIER '(' HAS_PARAMS ')' FUNCTION_MOD '{' FUNCTION_BODY '}'  */
#line 50 "parser.y"
                                                                                                         { (yyval.node) = mknode("FUNC", mknode("PRIVATE", mkleaf((yyvsp[-7].string)), NULL), mknode("PARAMS", (yyvsp[-5].node), mknode("BODY", (yyvsp[-3].string), (yyvsp[-1].node)))); }
#line 1492 "y.tab.c"
    break;

  case 8: /* FUNCTION: PUBLIC FUNCTION_TYPE IDENTIFIER '(' HAS_PARAMS ')' '{' FUNCTION_BODY '}'  */
#line 51 "parser.y"
                                                                                           { (yyval.node) = mknode("FUNC", mknode("PUBLIC", mkleaf((yyvsp[-6].string)), NULL), mknode("PARAMS", (yyvsp[-4].node), mknode("BODY", NULL, (yyvsp[-1].node)))); }
#line 1498 "y.tab.c"
    break;

  case 9: /* FUNCTION: PRIVATE FUNCTION_TYPE IDENTIFIER '(' HAS_PARAMS ')' '{' FUNCTION_BODY '}'  */
#line 52 "parser.y"
                                                                                            { (yyval.node) = mknode("FUNC", mknode("PRIVATE", mkleaf((yyvsp[-6].string)), NULL), mknode("PARAMS", (yyvsp[-4].node), mknode("BODY", NULL, (yyvsp[-1].node)))); }
#line 1504 "y.tab.c"
    break;

  case 10: /* FUNCTION: PUBLIC FUNCTION_TYPE IDENTIFIER '(' ')' '{' FUNCTION_BODY '}'  */
#line 53 "parser.y"
                                                                                { (yyval.node) = mknode("FUNC", mknode("PUBLIC", mkleaf((yyvsp[-5].string)), NULL), mknode("BODY", NULL, (yyvsp[-1].node))); }
#line 1510 "y.tab.c"
    break;

  case 11: /* FUNCTION: PRIVATE FUNCTION_TYPE IDENTIFIER '(' ')' '{' FUNCTION_BODY '}'  */
#line 54 "parser.y"
                                                                                 { (yyval.node) = mknode("FUNC", mknode("PRIVATE", mkleaf((yyvsp[-5].string)), NULL), mknode("BODY", NULL, (yyvsp[-1].node))); }
#line 1516 "y.tab.c"
    break;

  case 12: /* HAS_PARAMS: ARGS PARAMETER_LIST  */
#line 57 "parser.y"
                                      { (yyval.node) = mknode("ARGS", (yyvsp[0].node), NULL); }
#line 1522 "y.tab.c"
    break;

  case 13: /* HAS_PARAMS: %empty  */
#line 58 "parser.y"
                  { (yyval.node) = NULL; }
#line 1528 "y.tab.c"
    break;

  case 14: /* FUNCTION_MOD: ':' STATIC  */
#line 60 "parser.y"
                             { (yyval.string) = mkleaf("STATIC"); }
#line 1534 "y.tab.c"
    break;

  case 15: /* FUNCTION_MOD: %empty  */
#line 61 "parser.y"
                  { (yyval.string) = mkleaf("NON-STATIC"); }
#line 1540 "y.tab.c"
    break;

  case 16: /* PARAMETER_LIST: PARAMETER  */
#line 63 "parser.y"
                            { (yyval.node) = (yyvsp[0].node); }
#line 1546 "y.tab.c"
    break;

  case 17: /* PARAMETER_LIST: PARAMETER ';' PARAMETER_LIST  */
#line 64 "parser.y"
                                               { (yyval.node) = mknode(",", (yyvsp[-2].node), (yyvsp[0].node)); }
#line 1552 "y.tab.c"
    break;

  case 18: /* PARAMETER: PARAMETER_TYPE ':' IDENTIFIERS  */
#line 67 "parser.y"
                                                 { (yyval.node) = mknode("", (yyvsp[-2].node), (yyvsp[0].node)); }
#line 1558 "y.tab.c"
    break;

  case 19: /* IDENTIFIERS: IDENTIFIER ',' IDENTIFIERS  */
#line 70 "parser.y"
                                             { (yyval.node) = mknode("", mkleaf((yyvsp[-2].string)), (yyvsp[0].node)); }
#line 1564 "y.tab.c"
    break;

  case 20: /* IDENTIFIERS: IDENTIFIER  */
#line 71 "parser.y"
                             { (yyval.node) = mkleaf((yyvsp[0].string)); }
#line 1570 "y.tab.c"
    break;

  case 21: /* PARAMETER_TYPE: INT  */
#line 74 "parser.y"
                      { (yyval.node) = mkleaf("int"); }
#line 1576 "y.tab.c"
    break;

  case 22: /* PARAMETER_TYPE: FLOAT  */
#line 75 "parser.y"
                        { (yyval.node) = mkleaf("float"); }
#line 1582 "y.tab.c"
    break;

  case 23: /* PARAMETER_TYPE: DOUBLE  */
#line 76 "parser.y"
                         { (yyval.node) = mkleaf("double"); }
#line 1588 "y.tab.c"
    break;

  case 24: /* PARAMETER_TYPE: CHAR  */
#line 77 "parser.y"
                       { (yyval.node) = mkleaf("char"); }
#line 1594 "y.tab.c"
    break;

  case 25: /* PARAMETER_TYPE: INT_POINTER  */
#line 78 "parser.y"
                              { (yyval.node) = mkleaf("int*"); }
#line 1600 "y.tab.c"
    break;

  case 26: /* PARAMETER_TYPE: CHAR_POINTER  */
#line 79 "parser.y"
                               { (yyval.node) = mkleaf("char*"); }
#line 1606 "y.tab.c"
    break;

  case 27: /* PARAMETER_TYPE: REAL_POINTER  */
#line 80 "parser.y"
                               { (yyval.node) = mkleaf("double*"); }
#line 1612 "y.tab.c"
    break;

  case 28: /* PARAMETER_TYPE: FLOAT_POINTER  */
#line 81 "parser.y"
                                { (yyval.node) = mkleaf("float*"); }
#line 1618 "y.tab.c"
    break;

  case 29: /* FUNCTION_TYPE: VOID  */
#line 84 "parser.y"
                       { (yyval.string) = mkleaf("void"); }
#line 1624 "y.tab.c"
    break;

  case 30: /* FUNCTION_TYPE: INT  */
#line 85 "parser.y"
                      { (yyval.string) = mkleaf("int"); }
#line 1630 "y.tab.c"
    break;

  case 31: /* FUNCTION_TYPE: FLOAT  */
#line 86 "parser.y"
                        { (yyval.string) = mkleaf("float"); }
#line 1636 "y.tab.c"
    break;

  case 32: /* FUNCTION_TYPE: DOUBLE  */
#line 87 "parser.y"
                         { (yyval.string) = mkleaf("double"); }
#line 1642 "y.tab.c"
    break;

  case 33: /* FUNCTION_TYPE: CHAR  */
#line 88 "parser.y"
                       { (yyval.string) = mkleaf("char"); }
#line 1648 "y.tab.c"
    break;

  case 34: /* FUNCTION_TYPE: INT_POINTER  */
#line 89 "parser.y"
                              { (yyval.string) = mkleaf("int*"); }
#line 1654 "y.tab.c"
    break;

  case 35: /* FUNCTION_TYPE: CHAR_POINTER  */
#line 90 "parser.y"
                               { (yyval.string) = mkleaf("char*"); }
#line 1660 "y.tab.c"
    break;

  case 36: /* FUNCTION_TYPE: REAL_POINTER  */
#line 91 "parser.y"
                               { (yyval.string) = mkleaf("double*"); }
#line 1666 "y.tab.c"
    break;

  case 37: /* FUNCTION_TYPE: BOOL  */
#line 92 "parser.y"
                       { (yyval.string) = mkleaf("bool"); }
#line 1672 "y.tab.c"
    break;

  case 38: /* FUNCTION_BODY: DECLARATIONS STATEMENTS  */
#line 95 "parser.y"
                                          { (yyval.node) = mknode("BODY", (yyvsp[-1].node), (yyvsp[0].node)); }
#line 1678 "y.tab.c"
    break;

  case 39: /* FUNCTION_BODY: STATEMENTS  */
#line 96 "parser.y"
                             { (yyval.node) = mknode("BODY", NULL, (yyvsp[0].node)); }
#line 1684 "y.tab.c"
    break;

  case 40: /* FUNCTION_BODY: %empty  */
#line 97 "parser.y"
                  { (yyval.node) = mknode("BODY", NULL, NULL); }
#line 1690 "y.tab.c"
    break;

  case 41: /* DECLARATIONS: VAR_DECLARATION DECLARATIONS  */
#line 100 "parser.y"
                                               { (yyval.node) = mknode("", (yyvsp[-1].node), (yyvsp[0].node)); }
#line 1696 "y.tab.c"
    break;

  case 42: /* DECLARATIONS: NESTED_FUNCTIONS DECLARATIONS  */
#line 101 "parser.y"
                                                { (yyval.node) = mknode("", (yyvsp[-1].node), (yyvsp[0].node)); }
#line 1702 "y.tab.c"
    break;

  case 43: /* DECLARATIONS: STRING_DECLARATION DECLARATIONS  */
#line 102 "parser.y"
                                                  { (yyval.node) = mknode("", (yyvsp[-1].node), (yyvsp[0].node)); }
#line 1708 "y.tab.c"
    break;

  case 44: /* DECLARATIONS: VAR_DECLARATION  */
#line 103 "parser.y"
                                  { (yyval.node) = mknode("", (yyvsp[0].node), NULL); }
#line 1714 "y.tab.c"
    break;

  case 45: /* DECLARATIONS: NESTED_FUNCTIONS  */
#line 104 "parser.y"
                                   { (yyval.node) = mknode("", (yyvsp[0].node), NULL); }
#line 1720 "y.tab.c"
    break;

  case 46: /* DECLARATIONS: STRING_DECLARATION  */
#line 105 "parser.y"
                                     { (yyval.node) = mknode("", (yyvsp[0].node), NULL); }
#line 1726 "y.tab.c"
    break;

  case 47: /* STATEMENTS: STATEMENT STATEMENTS  */
#line 108 "parser.y"
                                       { (yyval.node) = mknode("", (yyvsp[-1].node), (yyvsp[0].node)); }
#line 1732 "y.tab.c"
    break;

  case 48: /* STATEMENTS: STATEMENT  */
#line 109 "parser.y"
                            { (yyval.node) = mknode("", (yyvsp[0].node), NULL); }
#line 1738 "y.tab.c"
    break;

  case 49: /* NESTED_FUNCTIONS: PUBLIC FUNCTION_TYPE IDENTIFIER '(' HAS_PARAMS ')' FUNCTION_MOD '{' FUNCTION_BODY '}'  */
#line 112 "parser.y"
                                                                                                        { (yyval.node) = mknode("FUNC", mknode("PUBLIC", mkleaf((yyvsp[-7].string)), NULL), mknode("PARAMS", (yyvsp[-5].node), mknode("BODY", (yyvsp[-3].string), (yyvsp[-1].node)))); }
#line 1744 "y.tab.c"
    break;

  case 50: /* NESTED_FUNCTIONS: PRIVATE FUNCTION_TYPE IDENTIFIER '(' HAS_PARAMS ')' FUNCTION_MOD '{' FUNCTION_BODY '}'  */
#line 113 "parser.y"
                                                                                                         { (yyval.node) = mknode("FUNC", mknode("PRIVATE", mkleaf((yyvsp[-7].string)), NULL), mknode("PARAMS", (yyvsp[-5].node), mknode("BODY", (yyvsp[-3].string), (yyvsp[-1].node)))); }
#line 1750 "y.tab.c"
    break;

  case 51: /* STATEMENT: IF '(' EXPR ')' '{' FUNCTION_BODY '}'  */
#line 116 "parser.y"
                                                        { (yyval.node) = mknode("IF", (yyvsp[-4].node), (yyvsp[-1].node)); }
#line 1756 "y.tab.c"
    break;

  case 52: /* STATEMENT: IF '(' EXPR ')' '{' FUNCTION_BODY '}' ELSE '{' FUNCTION_BODY '}'  */
#line 117 "parser.y"
                                                                                   { (yyval.node) = mknode("IF-ELSE", mknode("IF", (yyvsp[-8].node), (yyvsp[-5].node)), (yyvsp[-1].node)); }
#line 1762 "y.tab.c"
    break;

  case 53: /* STATEMENT: WHILE '(' EXPR ')' '{' FUNCTION_BODY '}'  */
#line 118 "parser.y"
                                                           { (yyval.node) = mknode("WHILE", (yyvsp[-4].node), (yyvsp[-1].node)); }
#line 1768 "y.tab.c"
    break;

  case 54: /* STATEMENT: FOR '(' STATEMENT EXPR ';' STATEMENT ')' '{' FUNCTION_BODY '}'  */
#line 119 "parser.y"
                                                                                 { (yyval.node) = mknode("FOR", (yyvsp[-7].node), mknode("", (yyvsp[-6].node), mknode("", (yyvsp[-4].node), (yyvsp[-1].node)))); }
#line 1774 "y.tab.c"
    break;

  case 55: /* STATEMENT: RETURN EXPR ';'  */
#line 120 "parser.y"
                                  { (yyval.node) = mknode("RETURN", (yyvsp[-1].node), NULL); }
#line 1780 "y.tab.c"
    break;

  case 56: /* STATEMENT: IDENTIFIER ASSIGN EXPR ';'  */
#line 121 "parser.y"
                                             { (yyval.node) = mknode("ASSIGN", mkleaf((yyvsp[-3].string)), (yyvsp[-1].node)); }
#line 1786 "y.tab.c"
    break;

  case 57: /* STATEMENT: DECLARATION ASSIGN EXPR ';'  */
#line 122 "parser.y"
                                              { (yyval.node) = mknode("DECL-ASSIGN", (yyvsp[-3].node), (yyvsp[-1].node)); }
#line 1792 "y.tab.c"
    break;

  case 58: /* STATEMENT: VAR_DECLARATION  */
#line 123 "parser.y"
                                  { (yyval.node) = (yyvsp[0].node); }
#line 1798 "y.tab.c"
    break;

  case 59: /* STATEMENT: STRING_DECLARATION  */
#line 124 "parser.y"
                                     { (yyval.node) = (yyvsp[0].node); }
#line 1804 "y.tab.c"
    break;

  case 60: /* STATEMENT: EXPR ';'  */
#line 125 "parser.y"
                           { (yyval.node) = (yyvsp[-1].node); }
#line 1810 "y.tab.c"
    break;

  case 61: /* DECLARATION: PARAMETER_TYPE IDENTIFIER  */
#line 128 "parser.y"
                                            { (yyval.node) = mknode("DECLARATION", (yyvsp[-1].node), mkleaf((yyvsp[0].string))); }
#line 1816 "y.tab.c"
    break;

  case 62: /* VAR_DECLARATION: VAR PARAMETER_TYPE ':' VAR_ASSIGN_LIST ';'  */
#line 131 "parser.y"
                                                             { (yyval.node) = mknode("VAR_DECLARATION", (yyvsp[-3].node), (yyvsp[-1].string)); }
#line 1822 "y.tab.c"
    break;

  case 63: /* VAR_ASSIGN_LIST: IDENTIFIER ASSIGN EXPR  */
#line 134 "parser.y"
                                         { (yyval.string) = mknode("VAR_ASSIGN", mkleaf((yyvsp[-2].string)), (yyvsp[0].node)); }
#line 1828 "y.tab.c"
    break;

  case 64: /* VAR_ASSIGN_LIST: IDENTIFIER ASSIGN EXPR ',' VAR_ASSIGN_LIST  */
#line 135 "parser.y"
                                                             { (yyval.string) = mknode("VAR_ASSIGN_LIST", mknode("VAR_ASSIGN", mkleaf((yyvsp[-4].string)), (yyvsp[-2].node)), (yyvsp[0].string)); }
#line 1834 "y.tab.c"
    break;

  case 65: /* VAR_ASSIGN_LIST: IDENTIFIER  */
#line 136 "parser.y"
                             { (yyval.string) = mkleaf((yyvsp[0].string)); }
#line 1840 "y.tab.c"
    break;

  case 66: /* VAR_ASSIGN_LIST: IDENTIFIER ',' VAR_ASSIGN_LIST  */
#line 137 "parser.y"
                                                 { (yyval.string) = mknode("VAR_ASSIGN_LIST", mkleaf((yyvsp[-2].string)), (yyvsp[0].string)); }
#line 1846 "y.tab.c"
    break;

  case 67: /* STRING_DECLARATION: STRING STRING_DECL_LIST ';'  */
#line 140 "parser.y"
                                                 { (yyval.node) = mknode("STRING_DECLARATION", (yyvsp[-1].string), NULL); }
#line 1852 "y.tab.c"
    break;

  case 68: /* STRING_DECL_LIST: STRING_DECL_ELEM ',' STRING_DECL_LIST  */
#line 143 "parser.y"
                                                         { (yyval.string) = mknode("STRING_DECL_LIST", (yyvsp[-2].node), (yyvsp[0].string)); }
#line 1858 "y.tab.c"
    break;

  case 69: /* STRING_DECL_LIST: STRING_DECL_ELEM  */
#line 144 "parser.y"
                                    { (yyval.string) = (yyvsp[0].node); }
#line 1864 "y.tab.c"
    break;

  case 70: /* STRING_DECL_ELEM: IDENTIFIER '[' INTEGER ']' ASSIGN STRING_LITERAL  */
#line 147 "parser.y"
                                                                    { (yyval.node) = mknode("STRING_ASSIGN", mkleaf((yyvsp[-5].string)), mknode("ARRAY", mkleaf((yyvsp[-3].string)), mkleaf((yyvsp[0].string)))); }
#line 1870 "y.tab.c"
    break;

  case 71: /* STRING_DECL_ELEM: IDENTIFIER '[' INTEGER ']'  */
#line 148 "parser.y"
                                              { (yyval.node) = mknode("ARRAY_DECL", mkleaf((yyvsp[-3].string)), mkleaf((yyvsp[-1].string))); }
#line 1876 "y.tab.c"
    break;

  case 72: /* EXPR: EXPR '+' EXPR  */
#line 151 "parser.y"
                                { (yyval.node) = mknode("+", (yyvsp[-2].node), (yyvsp[0].node)); }
#line 1882 "y.tab.c"
    break;

  case 73: /* EXPR: EXPR '-' EXPR  */
#line 152 "parser.y"
                                { (yyval.node) = mknode("-", (yyvsp[-2].node), (yyvsp[0].node)); }
#line 1888 "y.tab.c"
    break;

  case 74: /* EXPR: EXPR '*' EXPR  */
#line 153 "parser.y"
                                { (yyval.node) = mknode("*", (yyvsp[-2].node), (yyvsp[0].node)); }
#line 1894 "y.tab.c"
    break;

  case 75: /* EXPR: EXPR '/' EXPR  */
#line 154 "parser.y"
                                { (yyval.node) = mknode("/", (yyvsp[-2].node), (yyvsp[0].node)); }
#line 1900 "y.tab.c"
    break;

  case 76: /* EXPR: EXPR EQ EXPR  */
#line 155 "parser.y"
                               { (yyval.node) = mknode("==", (yyvsp[-2].node), (yyvsp[0].node)); }
#line 1906 "y.tab.c"
    break;

  case 77: /* EXPR: EXPR NE EXPR  */
#line 156 "parser.y"
                               { (yyval.node) = mknode("!=", (yyvsp[-2].node), (yyvsp[0].node)); }
#line 1912 "y.tab.c"
    break;

  case 78: /* EXPR: EXPR GE EXPR  */
#line 157 "parser.y"
                               { (yyval.node) = mknode(">=", (yyvsp[-2].node), (yyvsp[0].node)); }
#line 1918 "y.tab.c"
    break;

  case 79: /* EXPR: EXPR LE EXPR  */
#line 158 "parser.y"
                               { (yyval.node) = mknode("<=", (yyvsp[-2].node), (yyvsp[0].node)); }
#line 1924 "y.tab.c"
    break;

  case 80: /* EXPR: EXPR '>' EXPR  */
#line 159 "parser.y"
                                { (yyval.node) = mknode(">", (yyvsp[-2].node), (yyvsp[0].node)); }
#line 1930 "y.tab.c"
    break;

  case 81: /* EXPR: EXPR '<' EXPR  */
#line 160 "parser.y"
                                { (yyval.node) = mknode("<", (yyvsp[-2].node), (yyvsp[0].node)); }
#line 1936 "y.tab.c"
    break;

  case 82: /* EXPR: EXPR AND EXPR  */
#line 161 "parser.y"
                                { (yyval.node) = mknode("&&", (yyvsp[-2].node), (yyvsp[0].node)); }
#line 1942 "y.tab.c"
    break;

  case 83: /* EXPR: EXPR OR EXPR  */
#line 162 "parser.y"
                               { (yyval.node) = mknode("||", (yyvsp[-2].node), (yyvsp[0].node)); }
#line 1948 "y.tab.c"
    break;

  case 84: /* EXPR: IDENTIFIER  */
#line 163 "parser.y"
                             { (yyval.node) = mkleaf((yyvsp[0].string)); }
#line 1954 "y.tab.c"
    break;

  case 85: /* EXPR: INTEGER  */
#line 164 "parser.y"
                          { (yyval.node) = mkleaf((yyvsp[0].string)); }
#line 1960 "y.tab.c"
    break;

  case 86: /* EXPR: FLOAT_LITERAL  */
#line 165 "parser.y"
                                { (yyval.node) = mkleaf((yyvsp[0].string)); }
#line 1966 "y.tab.c"
    break;

  case 87: /* EXPR: CHAR_LITERAL  */
#line 166 "parser.y"
                               { (yyval.node) = mkleaf((yyvsp[0].string)); }
#line 1972 "y.tab.c"
    break;

  case 88: /* EXPR: STRING_LITERAL  */
#line 167 "parser.y"
                                 { (yyval.node) = mkleaf((yyvsp[0].string)); }
#line 1978 "y.tab.c"
    break;

  case 89: /* EXPR: BOOL_TRUE  */
#line 168 "parser.y"
                            { (yyval.node) = mkleaf("TRUE"); }
#line 1984 "y.tab.c"
    break;

  case 90: /* EXPR: BOOL_FALSE  */
#line 169 "parser.y"
                             { (yyval.node) = mkleaf("FALSE"); }
#line 1990 "y.tab.c"
    break;

  case 91: /* EXPR: '(' EXPR ')'  */
#line 170 "parser.y"
                               { (yyval.node) = (yyvsp[-1].node); }
#line 1996 "y.tab.c"
    break;


#line 2000 "y.tab.c"

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

#line 173 "parser.y"


node* mkleaf(char* token) {
    node* newnode = (node*)malloc(sizeof(node));
    newnode->token = strdup(token);
    newnode->left = NULL;
    newnode->right = NULL;
    return newnode;
}

node* mknode(char* token, node* left, node* right) {
    node* newnode = mkleaf(token);
    newnode->left = left;
    newnode->right = right;
    return newnode;
}

void printtree(node* tree) {
    if (tree == NULL) return;
    static int depth = 0;
    for (int i = 0; i < depth; i++) printf("  ");
    printf("%s\n", tree->token);
    depth++;
    printtree(tree->left);
    printtree(tree->right);
    depth--;
}

int yyerror(char* e) {
    fflush(stdout);
    fprintf(stderr, "Error: %s at line %d\n", e, yylineno);
    fprintf(stderr, "Last token: %s\n", yytext);
    return 0;
}

int main() {
    yyparse();
    return 0;
}
