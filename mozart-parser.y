%{
#include <stdio.h>
#include <stdlib.h> 
#include <ctype.h>
#include <stdbool.h>
#include "symtab/functions.h"
#include "symtab/types.h"


extern int yylex();
char * stringConcat(char * str1, char * str2);
Node* trueVal();
Node* falseVal();
Node* greater(Node* node1, Node* node2);
Node* add(Node* node1, Node* node2);
Node* subtract(Node* node1, Node* node2);
Node* multiply(Node* node1, Node* node2);
Node* divide(Node* node1, Node* node2);
void yyerror(char * s);
int getIntValue(Node* n);
float getFloatValue(Node* n);
bool getBoolValue(Node* n);
char* getStringValue(Node* n);
void typeCheck(Node* n1, char * typeKeyword);
Type getType(Node* n);

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
%start LINE;


%%
LINE    : 
        | LINE VARDECL ENDOFSTMT                    { ; }
        | LINE EXPR ENDOFSTMT                       { ; }
        | LINE LOGICEXPR ENDOFSTMT                  { ; }
        | LINE IFSTMT ENDOFSTMT                     { ; }
        | LINE FUNCTION ENDOFSTMT                   { ; }

VARDECL : VAR ID COLON INTKEYWORD ASSIGNMENT EXPR      { typeCheck($6, "integer");insert(construct($2, $6)); /*TODO type checking in construction*/}
        | VAR ID COLON FLOATKEYWORD ASSIGNMENT EXPR    { typeCheck($6, "float");insert(construct($2, $6)) ;}
        | VAR ID COLON BOOLEANKEYWORD ASSIGNMENT EXPR  { typeCheck($6, "boolean");insert(construct($2, $6)); }
        | VAR ID COLON STRINGKEYWORD ASSIGNMENT EXPR   { typeCheck($6, "string");insert(construct($2, $6)); }



IFSTMT : IF LPAREN LOGICEXPR RPAREN STARTOFSCOPE LINE ELSE LINE ENDOFSCOPE    {;}
        |IF LPAREN LOGICEXPR RPAREN STARTOFSCOPE LINE ENDOFSCOPE     {;}    

FUNCTION : FUNCTIONDECL LPAREN VARDECL RPAREN STARTOFSCOPE LINE ENDOFSCOPE    {/*should all be stored in symbolTable and be made accessible to the rest of the program to execute*/;} 
           |FUNCTIONDECL LPAREN RPAREN STARTOFSCOPE LINE ENDOFSCOPE{;}

LOGICEXPR : 
            TRUEVAL                                 { $$ = trueVal(); }
           |FALSEVAL                                { $$ = falseVal(); }
           |EXPR GREATER EXPR                       { $$ = greater($1, $3); }

 
           

EXPR    : EXPR PLUS EXPR                            { $$ = add($1, $3); }
        | EXPR MINUS EXPR                           { ; }
        | EXPR PER EXPR                             { ; }
        | EXPR DIV EXPR                             { ; }
        | EXPR MOD EXPR                             { ; }
        | LPAREN EXPR RPAREN                        { ; }
        | TYPEVAL                                   { $$ = $1; }
        | ID                                        { ; }

TYPEVAL : INTEGERTYPE                                   { $$ = constructInteger(NULL, $1 -> i); }
          |FLOATTYPE                                    { $$ = constructFloat(NULL, $1 -> f); }
          |BOOLEANTYPE                                  { $$ = constructBoolean(NULL, $1 -> b); }
          |STRINGTYPE                                   { $$ = constructString(NULL, $1 -> s); }






              
%%
/*
           |EXPR GREATEREQUAL EXPR                  { $$ = $1 >= $3}  
           |EXPR LOWER EXPR                         { $$ = $1 < $3}  
           |EXPR LOWEREQUAL EXPR                    { $$ = $1 <= $3}  
           |EXPR EQUAL EXPR                         { $$ = $1 == $3}  
           |EXPR  NOTEQUAL EXPR                     { $$ = $1 != $3}  
           |NOT LOGICEXPR                           { $$ = !$2} 
           |LOGICEXPR OR LOGICEXPR                  { $$ = $1 || $3} 
           |LOGICEXPR AND LOGICEXPR                 { $$ = $1 && $3} 
           
           | LINE LOOPSTMT ENDOFSTMT                       {;}
           
           LOOPSTMT :  INTEGERTYPE PER LOOP STARTOFSCOPE LINE ENDOFSCOPE         { insert number of times loop get executed into symbolTable;} 
           |ID PER LOOP STARTOFSCOPE LINE ENDOFSCOPE {;}
           */

           
void typeCheck(Node* n1, char * typeKeyword){
        printf("\ntypeChecking\nType: %s\nTypeKeyword: %s\n", enumToString(n1->type), typeKeyword);
        if(strcmp(enumToString(n1->type),typeKeyword)){
                yyerror("type declaration does not match !");
                exit(1);
        }
}


int getIntValue(Node* n){
        return n->value.i;
}

Type getType(Node* n){
        return n->type;
}

float getFloatValue(Node* n){
        return n->value.f;
}

bool getBoolValue(Node* n){
        return n->value.b;
}

char* getStringValue(Node* n){
        return n->value.s;
}

char * stringConcat(char * str1, char * str2){
        char newString[strlen(str1) + strlen(str2) + 1];
        strcpy(newString, str1);
        strcpy(newString, str2);
        return strdup(newString);
}

Node* trueVal(){
        Node* result =(Node *) malloc(sizeof(Node));
        result->type = BOOLEAN;
        result->value.b = true;
        return result;
}
Node* falseVal(){
        Node* result =(Node *) malloc(sizeof(Node));
        result->type = BOOLEAN;
        result->value.b = false;
        return result;
}

Node* greater(Node* node1, Node* node2){
        if (node1->type != node2->type) 
                yyerror("incompatibile");
        else{
                Node* result =(Node *) malloc(sizeof(Node));
                result->type = BOOLEAN;
                switch(node1->type){
                        case INTEGER : result->value.b = node1->value.i > node2->value.i;
                                       return result; 
                        case FLOAT   : result->value.b = node1->value.f > node2->value.f;
                                        return result;
                        case BOOLEAN : yyerror("operator not supported.");
                                        break;
                        case STRING  : result->value.b = strlen(node1->value.s) > strlen(node2->value.s);
                                        return result;
                }
        }
        return NULL;
}

Node* add(Node* node1, Node* node2){
        if (node1->type != node2->type) 
                yyerror("incompatibile");
        else{
                Node* result =(Node *) malloc(sizeof(Node));
                switch(node1->type){
                        case INTEGER : result->value.i = node1->value.i + node2->value.i; 
                                       result->type = INTEGER;
                                       return result;
                        case FLOAT   : result->value.f = node1->value.f + node2->value.f;
                                       result->type = FLOAT;
                                       return result;
                        case BOOLEAN : yyerror("operator not supported.");
                                       break;
                        case STRING  : result->value.s = stringConcat(node1->value.s, node2->value.s);
                                       result->type = STRING;
                                       return result;
                }

        }
        return NULL;
}
/*
Node* subtract(Node* node1, Node* node2){
        if (node1.type != node2.type) 
                yyerror("incompatibile");
        else{
                Node* result =(Node *) malloc(sizeof(Node));
                switch(node1.type){
                        case INTEGER : return node1.value.i - node2.value.i; 
                                       break;
                        case FLOAT   : return node1.value.f - node2.value.f;
                                       break;
                        case BOOLEAN : yyerror("operator not supported.");
                                       break;
                        case STRING  : yyerror("operator not supported.");
                                       break;
                }

        }
}

Node* multiply(Node* node1, Node* node2){
        if (node1.type != node2.type) 
                yyerror("incompatibile");
        else{
                switch(node1.type){
                        case INTEGER : return node1.value.i * node2.value.i; 
                                       break;
                        case FLOAT   : return node1.value.f * node2.value.f;
                                       break;
                        case BOOLEAN : yyerror("operator not supported.");
                                       break;
                        case STRING  : yyerror("operator not supported.");
                                       break;
                }

        }
}

Node* divide(Node* node1, Node* node2){
        if (node1.type != node2.type) 
                yyerror("incompatibile");
        if (node2.value == 0){
                yyerror("division by 0 is not possible.");
        }
        else{
                switch(node1.type){
                        case INTEGER : return node1.value.i - node2.value.i; 
                                       break;
                        case FLOAT   : return node1.value.f - node2.value.f;
                                       break;
                        case BOOLEAN : yyerror("operator not supported.");
                                       break;
                        case STRING  : yyerror("operator not supported.");
                                       break;
                }

        }
}
*/


void yyerror(char * s) {  
    fprintf (stderr, "%s\n", s);
    exit(1);
}
  
int main(void) {
    return yyparse();
}

