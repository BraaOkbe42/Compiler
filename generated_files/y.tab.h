/* A Bison parser, made by GNU Bison 3.8.2.  */

/* Bison interface for Yacc-like parsers in C

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

/* DO NOT RELY ON FEATURES THAT ARE NOT DOCUMENTED in the manual,
   especially those whose name start with YY_ or yy_.  They are
   private implementation details that can be changed or removed.  */

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

#line 152 "y.tab.h"

};
typedef union YYSTYPE YYSTYPE;
# define YYSTYPE_IS_TRIVIAL 1
# define YYSTYPE_IS_DECLARED 1
#endif


extern YYSTYPE yylval;


int yyparse (void);


#endif /* !YY_YY_Y_TAB_H_INCLUDED  */
