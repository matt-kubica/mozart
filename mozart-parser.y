%{
#include "symtab.h"
#include <stdio.h>
#include <stdlib.h> 
#include <ctype.h>
#include <stdbool.h>


%}

%token VAR
%token COLON

%token IF
%token ELSE
%token LOOP

%token END
%token ASSIGNMENT
%token LPARENTHESIS
%token RPARENTHESIS
%token ENDOFSTMT

%token TYPE
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


%token INTTYPE
%token FLOATTYPE
%token BOOLEANTYPE
%token STRINGTYPE
%token SCALETYPE

%token FUNCTIONDECL
%token RETURNSTMT

%union{
    char* LEXEME;
    Value VALUE;
    // struct Node* LINKTOSYM;
}

%token START
%token <LEXEME> ID 
%token <VALUE> INTEGER, FLOAT, BOOLEAN, STRING

%type <VALUE> EXPR
%type <VALUE> VARDECL
%start LINE;


%%
LINE    : 
        | LINE VARDECL ENDOFSTMT                    { ; }

VARDECL : VAR ID COLON INTTYPE ASSIGNMENT EXPR      { insert(constructInteger($2, $6)); }
        | VAR ID COLON FLOATTYPE ASSIGNMENT EXPR    { insert(constructFloat($2, $6)); }
        | VAR ID COLON BOOLEANTYPE ASSIGNMENT EXPR  { insert(constructBoolean($2, $6)); }
        | VAR ID COLON STRINGTYPE ASSIGNMENT EXPR   { insert(constructString($2, $6)); }


EXPR    : EXPR PLUS EXPR                            { $$ = $1 + $3; }
        | EXPR MINUS EXPR                           { $$ = $1 - $3; }
        | EXPR PER EXPR                             { $$ = $1 * $3; }
        | EXPR DIV EXPR                             { $$ = $1 / $3; }
        | EXPR MOD EXPR                             { $$ = $1- (($1 / $3)* $3); }
        | INTEGER                                   { $$ = $1; }

              
%%



void yyerror(char * s) {  
    fprintf (stderr, "%s\n", s);
}
  
int main(void) {
    printf("enter whatever word to start: ");
    
    yylex();
    return yyparse();
}

