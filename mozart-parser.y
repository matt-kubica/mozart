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

%token START
%token END
%token ASSIGNMENT
%token LPARENTHESIS
%token RPARENTHESIS
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

%token <LEXEME> ID 
%token <VALUE> INTEGER, FLOAT, BOOLEAN, STRING

%type <VALUE> EXPR
%type <VALUE> VARDECL
%start LINE;


%%
LINE    : 
        | LINE VARDECL ENDOFSTMT                    { ; }
        | LINE EXPR ENDOFSTMT
        | LINE LOOPSTMT ENDOFSTMT
        | LINE LOGICEXPR
        | LINE IFSTMT
        | LINE FUNCTION

VARDECL : VAR ID COLON INTTYPE ASSIGNMENT EXPR      { insert(constructInteger($2, $6)); }
        | VAR ID COLON FLOATTYPE ASSIGNMENT EXPR    { insert(constructFloat($2, $6)); }
        | VAR ID COLON BOOLEANTYPE ASSIGNMENT EXPR  { insert(constructBoolean($2, $6)); }
        | VAR ID COLON STRINGTYPE ASSIGNMENT EXPR   { insert(constructString($2, $6)); }

LOOPSTMT :  INTEGER PER LOOP START LINE END         { /*insert number of times loop get executed into symbolTable*/;} 
           |ID PER LOOP START LINE END

IFSTMT : IF LPARENTHESIS LOGICEXPR RPARENTHESIS START LINE ELSE LINE END    {/*line should execute only if LOGICEXPR is true, so attribute of ifstmt should be setted from $6 if LOGICEXPR is true, otherwise from $8*/}
        |IF LPARENTHESIS LOGICEXPR RPARENTHESIS START LINE END

FUNCTION : FUNCTIONDECL LPARENTHESIS VARDECL RPARENTHESIS START LINE END    {/*should all be stored in symbolTable and be made accessible to the rest of the program to execute*/;} 

LOGICEXPR : 
            TRUEVAL                                 {/*the most basic LOGICEXPRs are TRUEVAL and FALSEVAL*/}
           |FALSEVAL
           |EXPR GREATER EXPR                       { /*expression compared to other expression, return type boolean*/}
           |EXPR GREATEREQUAL EXPR
           |EXPR LOWER EXPR
           |EXPR LOWEREQUAL EXPR
           |EXPR EQUAL EXPR
           |EXPR NOTEQUAL EXPR
           |NOT LOGICEXPR                           {/*not , or , and are called on LOGICEXPR itself, for example NOT 5=5 should return false*/}
           |OR LOGICEXPR
           |AND LOGICEXPR                       
           

EXPR    : EXPR PLUS EXPR                            { $$ = $1 + $3; }
        | EXPR MINUS EXPR                           { $$ = $1 - $3; }
        | EXPR PER EXPR                             { $$ = $1 * $3; }
        | EXPR DIV EXPR                             { $$ = $1 / $3; }
        | EXPR MOD EXPR                             { $$ = $1- (($1 / $3)* $3); }
        | LPARENTHESIS EXPR RPARENTHESIS            { $$ = $2; }
        | TYPEVAL                                   { $$ = $1; }

TYPEVAL : INTEGER|FLOAT|BOOLEAN|STRING






              
%%



void yyerror(char * s) {  
    fprintf (stderr, "%s\n", s);
}
  
int main(void) {
    printf("enter whatever word to start: ");
    
    yylex();
    return yyparse();
}

