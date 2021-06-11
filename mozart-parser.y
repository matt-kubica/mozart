%{
#include <stdio.h>
#include <stdlib.h> 
#include <ctype.h>
#include <stdbool.h>
<<<<<<< HEAD
#include "symtab.h"
#include "symtabFunctions.h"
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
void printExpr(Node* n);
=======
#include "utils/symtab.h"
#include "utils/expr.h"
#include "utils/logicexpr.h"

extern int yylex();
>>>>>>> master
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
%type <NODE> TYPEVAL 
%start LINE
/*
| EXITSTMT ENDOFSTMT                            { exit(EXIT_SUCCESS); }
| VARDECL ENDOFSTMT                             { ; }
| EXPR ENDOFSTMT                                { printNode($1); }
| LOGICEXPR ENDOFSTMT                           { printNode($1); }
| IFSTMT ENDOFSTMT                              { ; }
| LOOPSTMT ENDOFSTMT                            { ; }
| FUNCTION ENDOFSTMT                            { ; }
*/

%%
<<<<<<< HEAD
LINE    : 
        | LINE EXPR ENDOFSTMT                       { printExpr($2);}
        | LINE LOGICEXPR ENDOFSTMT{;}               { printExpr($2);}
        | LINE VARDECL ENDOFSTMT                    { printTable() ;}
        | LINE IFSTMT ENDOFSTMT{;}
        | LINE FUNCTION ENDOFSTMT{;}
        | LINE ENDOFSTMT

VARDECL : VAR ID COLON INTKEYWORD ASSIGNMENT EXPR      { typeCheck($6, "integer"); insert(construct($2, $6));}
        | VAR ID COLON FLOATKEYWORD ASSIGNMENT EXPR    { typeCheck($6, "float"); insert(construct($2, $6)) ;}
        | VAR ID COLON BOOLEANKEYWORD ASSIGNMENT EXPR  { typeCheck($6, "boolean"); insert(construct($2, $6)); }
        | VAR ID COLON STRINGKEYWORD ASSIGNMENT EXPR   { typeCheck($6, "string"); insert(construct($2, $6)); }



IFSTMT : IF LPAREN LOGICEXPR RPAREN STARTOFSCOPE LINE ELSE LINE ENDOFSCOPE    {;}
        |IF LPAREN LOGICEXPR RPAREN STARTOFSCOPE LINE ENDOFSCOPE     {;}    

FUNCTION : FUNCTIONDECL LPAREN VARDECL RPAREN STARTOFSCOPE LINE ENDOFSCOPE    {/*should all be stored in symbolTable and be made accessible to the rest of the program to execute*/;} 
           |FUNCTIONDECL LPAREN RPAREN STARTOFSCOPE LINE ENDOFSCOPE{;}

LOGICEXPR : 
            TRUEVAL                                 { $$ = trueVal(); }
           |FALSEVAL                                { $$ = falseVal(); }
           |EXPR GREATER EXPR                       { $$ = greater($1, $3); }
=======
>>>>>>> master

LINE        : 
            
            | LINE EXITSTMT ENDOFSTMT                       { exit(EXIT_SUCCESS); }
            | LINE VARDECL ENDOFSTMT                        { ; }
            | LINE EXPR ENDOFSTMT                           { printNode($2); }
            | LINE LOGICEXPR ENDOFSTMT                      { printNode($2); }
            | LINE IFSTMT ENDOFSTMT                         { ; }
            | LINE LOOPSTMT ENDOFSTMT                       { ; }
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
            | VAR ID COLON BOOLEANKEYWORD ASSIGNMENT LOGICEXPR{ 
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


LOOPSTMT    : LOOP STARTOFSCOPE LINE ENDOFSCOPE         { /*insert number of times loop get executed into symbolTable */ } 
            ;


FUNCTION    : FUNCTIONDECL LPAREN VARDECL RPAREN STARTOFSCOPE LINE ENDOFSCOPE       { ; } 
            | FUNCTIONDECL LPAREN RPAREN STARTOFSCOPE LINE ENDOFSCOPE               { ; }
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
 
           
<<<<<<< HEAD

EXPR    : EXPR PLUS EXPR                            { $$ = construct(NULL, add($1, $3)); }
        | EXPR MINUS EXPR                           { ; }
        | EXPR PER EXPR                             { ; }
        | EXPR DIV EXPR                             { ; }
        | EXPR MOD EXPR                             { ; }
        | LPAREN EXPR RPAREN                        { ; }
        | TYPEVAL                                   {$$ = $1;}
        | ID                                        {;}

TYPEVAL : INTEGERTYPE                                   {$$ = construct(NULL, $1);}
          |FLOATTYPE                                    {$$ = construct(NULL, $1);}
          |BOOLEANTYPE                                  {$$ = construct(NULL, $1);}
          |STRINGTYPE                                   {$$ = construct(NULL, $1);}






              
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
}

Node* add(Node* node1, Node* node2){
        printf("\nAdding.\n");
        if (node1->type != node2->type) 
                yyerror("incompatibile");
        else{
                int resultI;
                float resultF;
                char* resultS;
                //Node* result =(Node *) malloc(sizeof(Node));
                switch(node1->type){
                        case INTEGER : resultI = node1->value.i + node2->value.i; 
                                       node1->value.i = resultI;
                                       return node1;
                        case FLOAT   : resultF = node1->value.f + node2->value.f;
                                       node1->value.f = resultF;
                                       return node1;
                        case BOOLEAN : yyerror("operator not supported.");
                                       break;
                        case STRING  : resultS = stringConcat(node1->value.s, node2->value.s);
                                       node1->value.s = resultS;
                                       return node1;
                }

        }
}
/*
Node* subtract(Node* node1, Node* node2){
        if (node1->type != node2->type) 
                yyerror("incompatibile");
        else{
                Node* result =(Node *) malloc(sizeof(Node));
                switch(node1->type){
                        case INTEGER : return node1->value.i - node2->value.i; 
                                       break;
                        case FLOAT   : return node1->value.f - node2->value.f;
                                       break;
                        case BOOLEAN : yyerror("operator not supported.");
                                       break;
                        case STRING  : yyerror("operator not supported.");
                                       break;
                }

        }
}

Node* multiply(Node* node1, Node* node2){
        if (node1->type != node2->type) 
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
}*/


void printExpr(Node* n){
                printf("Result: ");
                switch(n->type){
                        case INTEGER : printf("%i\n", n->value.i);break;
                        case FLOAT   : printf("%f\n", n->value.f);break;
                        case BOOLEAN : printf("%i\n", n->value.b);break;
                        case STRING  : printf("%s\n", n->value.s);break;
                }
}


void yyerror(char * s) {  
    fprintf (stderr, "%s\n", s);
    exit(1);
}
  
=======
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
 
>>>>>>> master
int main(void) {
    return yyparse();
}

