/* A Bison parser, made by GNU Bison 3.5.1.  */

/* Bison interface for Yacc-like parsers in C

   Copyright (C) 1984, 1989-1990, 2000-2015, 2018-2020 Free Software Foundation,
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

/* Undocumented macros, especially those whose name start with YY_,
   are private implementation details.  Do not rely on them.  */

#ifndef YY_YY_Y_TAB_H_INCLUDED
# define YY_YY_Y_TAB_H_INCLUDED
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
    NUM = 258,
    IDENTIFIER = 259,
    STRING_LITERAL = 260,
    TAPU_INT = 261,
    TAPU_STRING = 262,
    EQ = 263,
    SEMICOLON = 264,
    COMMA = 265,
    PRINT = 266,
    OPEN_PAREN = 267,
    CLOSE_PAREN = 268,
    OPEN_BRACE = 269,
    CLOSE_BRACE = 270,
    PLUS = 271,
    MINUS = 272,
    TIMES = 273,
    DIVIDE = 274,
    GOKULDHAM = 275,
    BAPUJI_SAHMAT = 276,
    BAPUJI_ASAHMAT = 277,
    EQUAL = 278,
    NE = 279,
    LT = 280,
    LE = 281,
    GT = 282,
    GE = 283
  };
#endif
/* Tokens.  */
#define NUM 258
#define IDENTIFIER 259
#define STRING_LITERAL 260
#define TAPU_INT 261
#define TAPU_STRING 262
#define EQ 263
#define SEMICOLON 264
#define COMMA 265
#define PRINT 266
#define OPEN_PAREN 267
#define CLOSE_PAREN 268
#define OPEN_BRACE 269
#define CLOSE_BRACE 270
#define PLUS 271
#define MINUS 272
#define TIMES 273
#define DIVIDE 274
#define GOKULDHAM 275
#define BAPUJI_SAHMAT 276
#define BAPUJI_ASAHMAT 277
#define EQUAL 278
#define NE 279
#define LT 280
#define LE 281
#define GT 282
#define GE 283

/* Value type.  */
#if ! defined YYSTYPE && ! defined YYSTYPE_IS_DECLARED
union YYSTYPE
{
#line 19 "tmkoc_yacc.y"

    int num;
    char* str;

#line 118 "y.tab.h"

};
typedef union YYSTYPE YYSTYPE;
# define YYSTYPE_IS_TRIVIAL 1
# define YYSTYPE_IS_DECLARED 1
#endif


extern YYSTYPE yylval;

int yyparse (void);

#endif /* !YY_YY_Y_TAB_H_INCLUDED  */
