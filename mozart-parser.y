%{
#include <stdio.h>
#include <stdlib.h> 
#include <ctype.h>
#include <stdbool.h>
#include "utils/symtab.h"
#include "utils/expr.h"
#include "utils/logicexpr.h"

extern int yylex();
extern Scope* currentScope;
%}

%token VAR
%token COLON
%token SEMICOLON

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

%left GREATEREQUAL LOWEREQUAL GREATER LOWER NOTEQUAL EQUAL OR
%left NOT
%left AND

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
%type <NODE> TYPEVAL IFSTMT LINE FUNCTION VARDECL
%start LINE
%%

LINE        :                                               { ; }
            | LINE EXITSTMT ENDOFSTMT                       { exit(EXIT_SUCCESS); }
            | LINE VARDECL ENDOFSTMT                        { insert($2); }
            | LINE VARDECL SEMICOLON                        { if($1 != NULL){$1->next = $2;}else{$$ = $2;} }
            | LINE EXPR ENDOFSTMT                           { printNode($2); }
            | LINE LOGICEXPR ENDOFSTMT                      { printNode($2); }
            | LINE IFSTMT ENDOFSTMT                         { ; }
            | LINE LOOPSTMT ENDOFSTMT                       { ; }
            | LINE FUNCTION ENDOFSTMT                       { ; }
            | LINE ID LPAREN RPAREN ENDOFSTMT               { Scope* fun = getScope($2); printTable(fun->symtab);}
            | LINE ID LPAREN TYPEKEYWORD RPAREN ENDOFSTMT   { ; }
            ;


VARDECL     : VAR ID COLON INTKEYWORD ASSIGNMENT EXPR       {   
                                                                typeCheck($6, INTEGER);
                                                                $$ = construct($2, $6);
                                                            }
            | VAR ID COLON FLOATKEYWORD ASSIGNMENT EXPR     { 
                                                                typeCheck($6, FLOAT);
                                                                insert(construct($2, $6));
                                                            }
            | VAR ID COLON BOOLEANKEYWORD ASSIGNMENT EXPR   { 
                                                                typeCheck($6, BOOLEAN);
                                                                insert(construct($2, $6)); 
                                                            }
            | VAR ID COLON BOOLEANKEYWORD ASSIGNMENT LOGICEXPR{ 
                                                                typeCheck($6, BOOLEAN);
                                                                insert(construct($2, $6)); 
                                                            }
            | VAR ID COLON STRINGKEYWORD ASSIGNMENT EXPR    { 
                                                                typeCheck($6, STRING);
                                                                insert(construct($2, $6)); 
                                                            }
            ;

LOGICEXPR   : EXPR GREATER EXPR                             { $$ = greater($1, $3); }
            | EXPR GREATEREQUAL EXPR                        { $$ = greaterEqual($1, $3); }  
            | EXPR LOWER EXPR                               { $$ = lower($1, $3); }  
            | EXPR LOWEREQUAL EXPR                          { $$ = lowerEqual($1, $3); }  
            | EXPR EQUAL EXPR                               { $$ = equal($1, $3); }  
            | EXPR NOTEQUAL EXPR                            { $$ = notEqual($1, $3); } 
            | LPAREN LOGICEXPR RPAREN                       { $$ = $2;}
            | EXPR OR EXPR                                  { $$ = or($1, $3); } 
            | EXPR AND EXPR                                 { $$ = and($1, $3); }  
            | NOT EXPR                                      { $$ = not($2); }
            ;

IFSTMT      : IF LPAREN LOGICEXPR RPAREN STARTOFSCOPE LINE ELSE LINE ENDOFSCOPE     { /**/ }
            | IF LPAREN LOGICEXPR RPAREN STARTOFSCOPE LINE ENDOFSCOPE               { printf("Executed IFSTMT\n"); }
            ;


LOOPSTMT    : LOOP STARTOFSCOPE LINE ENDOFSCOPE         { /*insert number of times loop get executed into symbolTable */ } 
            ;


FUNCTION    : FUNCTIONDECL ID LPAREN TYPEKEYWORD ID RPAREN STARTOFSCOPE LINE ENDOFSCOPE       { ; } 
            | FUNCTIONDECL ID LPAREN RPAREN STARTOFSCOPE LINE ENDOFSCOPE                      { enterScope($2); insert($6);}
            ;

TYPEKEYWORD : INTKEYWORD
            | FLOATKEYWORD  
            | BOOLEANKEYWORD
            | STRINGKEYWORD
            ;

EXPR        : EXPR PLUS EXPR                                { $$ = add($1, $3); }
            | EXPR MINUS EXPR                               { $$ = subtract($1, $3); }
            | EXPR PER EXPR                                 { $$ = multiply($1, $3);; }
            | EXPR DIV EXPR                                 { $$ = divide($1, $3); }
            | EXPR MOD EXPR                                 { $$ = modulo($1, $3); }
            | LPAREN EXPR RPAREN                            { $$ = $2; }
            | TYPEVAL                                       { $$ = $1; }
            | ID                                            { $$ = getNode($1); }
            ;


TYPEVAL     : INTEGERTYPE                                   { $$ = constructInteger(NULL, $1.i); /* TODO: memory dealocation */ }
            | FLOATTYPE                                     { $$ = constructFloat(NULL, $1.f); }
            | BOOLEANTYPE                                   { $$ = constructBoolean(NULL, $1.b); } 
            | STRINGTYPE                                    { $$ = constructString(NULL, $1.s); }
            ;
            
%%
 
int main(void) {
    currentScope = (Scope*) malloc(sizeof(Scope));
    currentScope -> symtab = NULL;
    currentScope -> name = "global";
    currentScope -> parent = NULL;

    return yyparse();
}

