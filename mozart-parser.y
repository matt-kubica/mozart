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

%token GREATEREQUAL
%token LOWEREQUAL
%token GREATER
%token LOWER
%token NOTEQUAL
%token NOT
%token EQUAL
%token OR
%token AND

%left OR
%left AND
%left GREATEREQUAL LOWEREQUAL GREATER LOWER NOTEQUAL EQUAL 
%left NOT

%left PLUS MINUS 
%left PER DIV MOD

%token INTKEYWORD
%token FLOATKEYWORD
%token BOOLEANKEYWORD
%token STRINGKEYWORD

%token FUNCTIONDECL
%token RETURNSTMT
%token EXITSTMT

%token <VALUE> INTEGERTYPE FLOATTYPE BOOLEANTYPE STRINGTYPE
%token <LEXEME> ID

%union{
    char* LEXEME;
    struct Node* NODE;
    Value VALUE;
}

%type <NODE> EXPR LOGICEXPR TYPEVAL IFSTMT LINE FUNCTION VARDECL

%start LINE
%%

LINE        :                                               { ; }
            | LINE EXITSTMT ENDOFSTMT                       { exit(EXIT_SUCCESS); }
            | LINE VARDECL ENDOFSTMT                        { insert($2); }
            | LINE VARDECL SEMICOLON                        { if($1 != NULL){$2->next = $1;} $$ = $2; }  
            | LINE EXPR ENDOFSTMT                           { printNode($2); }
            | LINE EXPR SEMICOLON                           { ;}
            | LINE LOGICEXPR ENDOFSTMT                      { printNode($2); }
            | LINE IFSTMT ENDOFSTMT                         { printAllTables(); leaveScope(); }
            | LINE LOOPSTMT ENDOFSTMT                                                   { printAllTables(); leaveScope(); }
            | LINE INTKEYWORD FUNCTION EXPR ENDOFSCOPE ENDOFSTMT                        { typeCheck($4, INTEGER); printAllTables();leaveScope(); }
            | LINE FLOATKEYWORD FUNCTION EXPR ENDOFSCOPE ENDOFSTMT                      { typeCheck($4, FLOAT); printAllTables();leaveScope(); }
            | LINE BOOLEANKEYWORD FUNCTION EXPR ENDOFSCOPE ENDOFSTMT                    { typeCheck($4, BOOLEAN); printAllTables();leaveScope(); }
            | LINE STRINGKEYWORD FUNCTION EXPR ENDOFSCOPE ENDOFSTMT                     { typeCheck($4, STRING); printAllTables();leaveScope(); }
            ;


VARDECL     : VAR ID COLON INTKEYWORD ASSIGNMENT EXPR       {   
                                                                typeCheck($6, INTEGER);
                                                                $$ = construct($2, $6);
                                                            }
            | VAR ID COLON FLOATKEYWORD ASSIGNMENT EXPR     { 
                                                                typeCheck($6, FLOAT);
                                                                $$ = construct($2, $6);
                                                            }
            | VAR ID COLON BOOLEANKEYWORD ASSIGNMENT EXPR   { 
                                                                typeCheck($6, BOOLEAN);
                                                                $$ = construct($2, $6);
                                                            }
            | VAR ID COLON BOOLEANKEYWORD ASSIGNMENT LOGICEXPR{ 
                                                                typeCheck($6, BOOLEAN);
                                                                $$ = construct($2, $6); 
                                                            }
            | VAR ID COLON STRINGKEYWORD ASSIGNMENT EXPR    { 
                                                                typeCheck($6, STRING);
                                                                $$ = construct($2, $6);
                                                            }
            ;


LOGICEXPR   : EXPR GREATER EXPR                             { $$ = greater($1, $3); }
            | EXPR GREATEREQUAL EXPR                        { $$ = greaterEqual($1, $3); }  
            | EXPR LOWER EXPR                               { $$ = lower($1, $3); }  
            | EXPR LOWEREQUAL EXPR                          { $$ = lowerEqual($1, $3); }  
            | EXPR EQUAL EXPR                               { $$ = equal($1, $3); }  
            | EXPR NOTEQUAL EXPR                            { $$ = notEqual($1, $3); } 
            | LPAREN LOGICEXPR RPAREN                       { $$ = $2;}
            | LOGICEXPR OR LOGICEXPR                        { $$ = or($1, $3); } 
            | LOGICEXPR AND LOGICEXPR                       { $$ = and($1, $3); }  
            | NOT LOGICEXPR                                 { $$ = not($2); }
            | TYPEVAL                                       { $$ = $1;  }
            ;

IFSTMT      : IF LPAREN LOGICEXPR RPAREN STARTOFSCOPE LINE ELSE LINE ENDOFSCOPE      { if($3->value.b == 1){enterScope("if"); insert($6);} 
                                                                                       else{enterScope("else"); printNode($8); insert($8);}
                                                                                    }
            | IF LPAREN LOGICEXPR RPAREN STARTOFSCOPE LINE ENDOFSCOPE                { enterScope("if"); insert($6);}
            ;


LOOPSTMT    : LOOP STARTOFSCOPE LINE ENDOFSCOPE                                      { enterScope("loop"); insert($3);}    
            ;


FUNCTION    : FUNCTIONDECL ID LPAREN RPAREN STARTOFSCOPE LINE RETURNSTMT             { enterScope($2); insert($6);    }
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


TYPEVAL     : INTEGERTYPE                                   { $$ = constructInteger(NULL, $1.i); }
            | FLOATTYPE                                     { $$ = constructFloat(NULL, $1.f);   }
            | BOOLEANTYPE                                   { $$ = constructBoolean(NULL, $1.b); } 
            | STRINGTYPE                                    { $$ = constructString(NULL, $1.s);  }
            ;
            
%%
 
int main(void) {
    currentScope = (Scope*) malloc(sizeof(Scope));
    currentScope -> symtab = NULL;
    currentScope -> name = "global";
    currentScope -> parent = NULL;

    return yyparse();
}

