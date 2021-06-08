%{
#include <stdio.h>
#include <stdlib.h> 
#include <ctype.h>
#include <stdbool.h>
#include "utils/symtab.h"
#include "utils/expr.h"
#include "utils/logicexpr.h"

extern int yylex();
%}

%token VAR
%token COLON

%token IF
%token ELSE
%token LOOP

%token STARTOFSCOPE
%token ENDOFSCOPE
%token ASSIGNMENT
%token LPAREN
%token RPAREN
%token ENDOFSTMT

%token PLUS
%token MINUS
%token PER
%token DIV
%token MOD

%left PLUS MINUS 
%left PER DIV MOD

%token GREATEREQUAL
%token LOWEREQUAL
%token GREATER
%token LOWER
%token NOTEQUAL
%token NOT
%token EQUAL
%token OR
%token AND

%token TRUEVAL
%token FALSEVAL

%token INTKEYWORD
%token FLOATKEYWORD
%token BOOLEANKEYWORD
%token STRINGKEYWORD
%token SCALEKEYWORD

%token FUNCTIONDECL
%token RETURNSTMT
%token EXITSTMT

%union{
    char* LEXEME;
    struct Node* NODE;
    Value VALUE;
}

%token <LEXEME> ID 
%token <VALUE> INTEGERTYPE FLOATTYPE BOOLEANTYPE STRINGTYPE
%type <NODE> EXPR
%type <NODE> LOGICEXPR 
%type <NODE> TYPEVAL 
%start LINE


%%

LINE        : EXITSTMT ENDOFSTMT                            { exit(EXIT_SUCCESS); }
            | LINE EXITSTMT ENDOFSTMT                       { exit(EXIT_SUCCESS); }
            | VARDECL ENDOFSTMT                             { ; }
            | LINE VARDECL ENDOFSTMT                        { ; }
            | EXPR ENDOFSTMT                                { printNode($1); }
            | LINE EXPR ENDOFSTMT                           { printNode($2); }
            | LOGICEXPR ENDOFSTMT                           { printNode($1); }
            | LINE LOGICEXPR ENDOFSTMT                      { printNode($2); }
            | IFSTMT ENDOFSTMT                              { ; }
            | LINE IFSTMT ENDOFSTMT                         { ; }
            | LOOPSTMT ENDOFSTMT                            { ; }
            | LINE LOOPSTMT ENDOFSTMT                       { ; }
            | FUNCTION ENDOFSTMT                            { ; }
            | LINE FUNCTION ENDOFSTMT                       { ; }
            ;


VARDECL     : VAR ID COLON INTKEYWORD ASSIGNMENT EXPR       {   
                                                                typeCheck($6, INTEGER);
                                                                insert(construct($2, $6));
                                                            }
            | VAR ID COLON FLOATKEYWORD ASSIGNMENT EXPR     { 
                                                                typeCheck($6, FLOAT);
                                                                insert(construct($2, $6));
                                                            }
            | VAR ID COLON BOOLEANKEYWORD ASSIGNMENT EXPR   { 
                                                                typeCheck($6, BOOLEAN);
                                                                insert(construct($2, $6)); 
                                                            }
            | VAR ID COLON STRINGKEYWORD ASSIGNMENT EXPR    { 
                                                                typeCheck($6, STRING);
                                                                insert(construct($2, $6)); 
                                                            }
            ;


IFSTMT      : IF LPAREN LOGICEXPR RPAREN STARTOFSCOPE LINE ELSE LINE ENDOFSCOPE     { ; }
            | IF LPAREN LOGICEXPR RPAREN STARTOFSCOPE LINE ENDOFSCOPE               { ; }    
            ;


LOOPSTMT    : INTEGERTYPE PER LOOP STARTOFSCOPE LINE ENDOFSCOPE         { /*insert number of times loop get executed into symbolTable */ } 
            | ID PER LOOP STARTOFSCOPE LINE ENDOFSCOPE                              { ; }
            ;


FUNCTION    : FUNCTIONDECL LPAREN VARDECL RPAREN STARTOFSCOPE LINE ENDOFSCOPE       { ; } 
            | FUNCTIONDECL LPAREN RPAREN STARTOFSCOPE LINE ENDOFSCOPE               { ; }
            ;


LOGICEXPR   : TRUEVAL                                       { $$ = trueVal(); }
            | FALSEVAL                                      { $$ = falseVal(); }
            | EXPR GREATER EXPR                             { $$ = greater($1, $3); }
            | EXPR GREATEREQUAL EXPR                        { ; }  
            | EXPR LOWER EXPR                               { ; }  
            | EXPR LOWEREQUAL EXPR                          { ; }  
            | EXPR EQUAL EXPR                               { ; }  
            | EXPR NOTEQUAL EXPR                            { ; }  
            | NOT LOGICEXPR                                 { ; } 
            | LOGICEXPR OR LOGICEXPR                        { ; } 
            | LOGICEXPR AND LOGICEXPR                       { ; } 
            ;
 
           
EXPR        : EXPR PLUS EXPR                                { $$ = add($1, $3); }
            | EXPR MINUS EXPR                               { ; }
            | EXPR PER EXPR                                 { ; }
            | EXPR DIV EXPR                                 { ; }
            | EXPR MOD EXPR                                 { ; }
            | LPAREN EXPR RPAREN                            { ; }
            | TYPEVAL                                       { $$ = $1; }
            | ID                                            { $$ = getNode($1); }
            ;


TYPEVAL     : INTEGERTYPE                                   { $$ = constructInteger(NULL, $1.i); }
            | FLOATTYPE                                     { $$ = constructFloat(NULL, $1.f); }
            | BOOLEANTYPE                                   { $$ = constructBoolean(NULL, $1.b); }
            | STRINGTYPE                                    { $$ = constructString(NULL, $1.s); }
            ;
            
%%
 
int main(void) {
    return yyparse();
}

