
/* A Bison parser, made by GNU Bison 2.4.1.  */

/* Skeleton interface for Bison's Yacc-like parsers in C
   
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


/* Tokens.  */
#ifndef YYTOKENTYPE
# define YYTOKENTYPE
   /* Put the tokens into the symbol table, so that GDB and other debuggers
      know about them.  */
   enum yytokentype {
     VAR = 258,
     COLON = 259,
     SEMICOLON = 260,
     IF = 261,
     ELSE = 262,
     LOOP = 263,
     STARTOFSCOPE = 264,
     ENDOFSCOPE = 265,
     ASSIGNMENT = 266,
     LPAREN = 267,
     RPAREN = 268,
     ENDOFSTMT = 269,
     PLUS = 270,
     MINUS = 271,
     PER = 272,
     DIV = 273,
     MOD = 274,
     GREATEREQUAL = 275,
     LOWEREQUAL = 276,
     GREATER = 277,
     LOWER = 278,
     NOTEQUAL = 279,
     NOT = 280,
     EQUAL = 281,
     OR = 282,
     AND = 283,
     TRUEVAL = 284,
     FALSEVAL = 285,
     INTKEYWORD = 286,
     FLOATKEYWORD = 287,
     BOOLEANKEYWORD = 288,
     STRINGKEYWORD = 289,
     SCALEKEYWORD = 290,
     FUNCTIONDECL = 291,
     RETURNSTMT = 292,
     EXITSTMT = 293,
     ID = 294,
     INTEGERTYPE = 295,
     FLOATTYPE = 296,
     BOOLEANTYPE = 297,
     STRINGTYPE = 298
   };
#endif



#if ! defined YYSTYPE && ! defined YYSTYPE_IS_DECLARED
typedef union YYSTYPE
{

/* Line 1676 of yacc.c  */
#line 66 "mozart-parser.y"

    char* LEXEME;
    struct Node* NODE;
    Value VALUE;



/* Line 1676 of yacc.c  */
#line 103 "mozart-parser.tab.h"
} YYSTYPE;
# define YYSTYPE_IS_TRIVIAL 1
# define yystype YYSTYPE /* obsolescent; will be withdrawn */
# define YYSTYPE_IS_DECLARED 1
#endif

extern YYSTYPE yylval;


