%{
#include "symtab.h"
#include <stdio.h>
#include <stdlib.h> 
#include <ctype.h>
#include <stdbool.h>

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

LOOPSTMT :  INTEGERTYPE PER LOOP STARTOFSCOPE LINE ENDOFSCOPE         { /*insert number of times loop get executed into symbolTable*/;} 
           |ID PER LOOP STARTOFSCOPE LINE ENDOFSCOPE 

IFSTMT : IF LPAREN LOGICEXPR RPAREN STARTOFSCOPE LINE ELSE LINE ENDOFSCOPE    {}
        |IF LPAREN LOGICEXPR RPAREN STARTOFSCOPE LINE ENDOFSCOPE         

FUNCTION : FUNCTIONDECL LPAREN VARDECL RPAREN STARTOFSCOPE LINE ENDOFSCOPE    {/*should all be stored in symbolTable and be made accessible to the rest of the program to execute*/;} 
           |FUNCTIONDECL LPAREN RPAREN STARTOFSCOPE LINE ENDOFSCOPE

LOGICEXPR : 
            TRUEVAL                                 { $$ = trueVal(); }
           |FALSEVAL                                { $$ = falseVal(); }
           |EXPR GREATER EXPR                       { $$ = greater($1, $3); }
 
           

EXPR    : EXPR PLUS EXPR                            { $$ = add($1, $3); }
        | EXPR MINUS EXPR                           {  }
        | EXPR PER EXPR                             {  }
        | EXPR DIV EXPR                             {  }
        | EXPR MOD EXPR                             { }
        | LPAREN EXPR RPAREN                        {}
        | TYPEVAL                                   {  }
        | ID                                        {}

TYPEVAL : INTEGERTYPE                                   {}
          |FLOATTYPE
          |BOOLEANTYPE
          |STRINGTYPE






              
%%

    typedef enum Type {
        INTEGER,
        FLOAT,
        BOOLEAN,
        STRING
    } Type;

    typedef union Value {
        int i;
        float f;
        bool b;
        char *s;
    } Value;

    typedef struct Node {
        const char* id;  
        Value value;
        Type type;
        struct Node* next;    
    } Node; 


    Node * head = NULL;
    
    void printTable() {
        Node * node = head;
        while(node != NULL) {
            switch (node -> type) {
                case INTEGER:
                    printf("\nID: %s\nATTRIBUTE: %d\n", node -> id, node -> value.i);
                    break;
                case FLOAT:
                    printf("\nID: %s\nATTRIBUTE: %f\n", node -> id, node -> value.f);
                    break;
                case BOOLEAN:
                    printf("\nID: %s\nATTRIBUTE: %d\n", node -> id, (int)node -> value.b);
                    break;
                case STRING:
                    printf("\nID: %s\nATTRIBUTE: %s\n", node -> id, node -> value.s);
                    break;
            }
            node = node -> next;
        }
    }

    Node* construct(char* id, Node* node){
        node->id = id;
        node->next = NULL;
        return node;
    }

    Node *constructInteger(const char *id, int value) {
        Node * node = (Node *) malloc(sizeof(Node));
        node -> id = id;
        node -> value.i = value;
        node -> type = INTEGER;
        node -> next = NULL;
        return node;
    }

    Node *constructFloat(const char *id, float value) {
        Node * node = (Node *) malloc(sizeof(Node));
        node -> id = id;
        node -> value.f = value;
        node -> type = FLOAT;
        node -> next = NULL;
        return node;
    }

    Node *constructBoolean(const char *id, bool value) {
        Node * node = (Node *) malloc(sizeof(Node));
        node -> id = id;
        node -> value.b = value;
        node -> type = BOOLEAN;
        node -> next = NULL;
        return node;
    }

    Node *constructString(const char *id, char *value) {
        Node * node = (Node *) malloc(sizeof(Node));
        node -> id = id;
        node -> value.s = strdup(value);
        node -> type = STRING;
        node -> next = NULL;
        return node;
    }

    void insert(Node * newNode){
        if (head == NULL) {
            head = newNode;
        }
        else {
            Node * node = head;
            while (node -> next != NULL) {
                if (strcmp(newNode -> id, node -> id) == 0) {
                    // TODO: better error handling
                    printf("Variable name already in use!\n");
                    exit(EXIT_FAILURE);
                }
                node = node -> next;
            }
            if (strcmp(newNode -> id, node -> id) == 0) {
                printf("Variable name already in use!\n");
                exit(EXIT_FAILURE);
            }
            node -> next = newNode;
        }
    }

    Node* getNode(const char *id) {
        Node *node = head;
        while (node != NULL) {
            if (strcmp(node -> id, id) == 0) {
                return node;
            }
            node = node -> next;
        }
        return 0;
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

