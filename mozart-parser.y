%{
#include "symtab.h"
#include <stdio.h>
#include <stdlib.h> 
#include <ctype.h>
#include <stdbool.h>

char * stringConcat(char * str1, char * str2);
Node* trueVal();
Node* falseVal();
Node* greater(Node* node1, Node* node2);
Node* add(Node* node1, Node* node2);
Node* subtract(Node* node1, Node* node2);
Node* multiply(Node* node1, Node* node2);
Node* divide(Node* node1, Node* node2);
void yyerror(char * s);
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


%token INTKEYWORD
%token FLOATKEYWORD
%token BOOLEANKEYWORD
%token STRINGKEYWORD
%token SCALEKEYWORD

%token FUNCTIONDECL
%token RETURNSTMT

%union{
    char* LEXEME;
    Node* NODE;
    // struct Node* LINKTOSYM;
}

%token <LEXEME> ID 
%token <NODE> INTEGERTYPE FLOATTYPE BOOLEANTYPE STRINGTYPE

%type <NODE> EXPR
%type <NODE> LOGICEXPR 
%start LINE;


%%
LINE    : 
        | LINE VARDECL ENDOFSTMT                    { ; }
        | LINE EXPR ENDOFSTMT
        | LINE LOOPSTMT ENDOFSTMT
        | LINE LOGICEXPR ENDOFSTMT
        | LINE IFSTMT ENDOFSTMT
        | LINE FUNCTION ENDOFSTMT

VARDECL : VAR ID COLON INTKEYWORD ASSIGNMENT EXPR      { insert(construct($2, $6)); /*TODO type checking in construction*/}
        | VAR ID COLON FLOATKEYWORD ASSIGNMENT EXPR    { insert(construct($2, $6)); }
        | VAR ID COLON BOOLEANKEYWORD ASSIGNMENT EXPR  { insert(construct($2, $6)); }
        | VAR ID COLON STRINGKEYWORD ASSIGNMENT EXPR   { insert(construct($2, $6)); }

LOOPSTMT :  INTEGERTYPE PER LOOP START LINE END         { /*insert number of times loop get executed into symbolTable*/;} 
           |ID PER LOOP START LINE END 

IFSTMT : IF LPARENTHESIS LOGICEXPR RPARENTHESIS START LINE ELSE LINE END    {}
        |IF LPARENTHESIS LOGICEXPR RPARENTHESIS START LINE END         

FUNCTION : FUNCTIONDECL LPARENTHESIS VARDECL RPARENTHESIS START LINE END    {/*should all be stored in symbolTable and be made accessible to the rest of the program to execute*/;} 
           |FUNCTIONDECL LPARENTHESIS RPARENTHESIS START LINE END

LOGICEXPR : 
            TRUEVAL                                 { $$ = trueVal()}
           |FALSEVAL                                { $$ = falseVal()}
           |EXPR GREATER EXPR                       { $$ = greater($1, $3)}
 
           

EXPR    : EXPR PLUS EXPR                            { $$ = add($1, $3); }
        | EXPR MINUS EXPR                           {  }
        | EXPR PER EXPR                             {  }
        | EXPR DIV EXPR                             {  }
        | EXPR MOD EXPR                             { }
        | LPARENTHESIS EXPR RPARENTHESIS            {}
        | TYPEVAL                                   {  }
        | ID                                        {}

TYPEVAL : INTEGERTYPE                                   {}
          |FLOATTYPE
          |BOOLEANTYPE
          |STRINGTYPE






              
%%

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
    printf("enter whatever word to start: ");
    
    return yyparse();
}

