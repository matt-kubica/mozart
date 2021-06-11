#ifndef LOGICEXPR
#define LOGICEXPR

    #include "types.h"
    #include "helpers.h"


    Node* trueVal();
    Node* falseVal();
    Node* greater(Node*, Node*);
    Node* greaterEqual(Node*, Node*);
    Node* lower(Node*, Node*);
    Node* lowerEqual(Node*, Node*);
    Node* equal(Node*, Node*);
    Node* notEqual(Node*, Node*);
    Node* not(Node*);
    Node* and(Node*, Node*);
    Node* or(Node*, Node*);


    Node* trueVal() {
        Node* result = (Node *) malloc(sizeof(Node));
        result -> type = BOOLEAN;
        result -> value.b = 1;
        return result;
    }

    Node* falseVal() {
        Node* result = (Node *) malloc(sizeof(Node));
        result -> type = BOOLEAN;
        result -> value.b = 0;
        return result;
    }

    Node* greater(Node* node1, Node* node2){
            
        if (node1 -> type != node2 -> type) 
            yyerror("Incompatibile types!");

        Node* result = (Node *) malloc(sizeof(Node));
        result -> type = BOOLEAN;
        switch(node1 -> type) {
            case INTEGER: 
                result -> value.b = node1 -> value.i > node2 -> value.i;
                return result; 
            case FLOAT: 
                result -> value.b = node1 -> value.f > node2 -> value.f;
                return result;
            case BOOLEAN: 
                yyerror("Operator not supported!");
                return NULL;
            case STRING: 
                result -> value.b = strlen(node1 -> value.s) > strlen(node2 -> value.s);
                return result;
        }

        return NULL;
    }

    Node* greaterEqual(Node* node1, Node* node2){
            
        if (node1 -> type != node2 -> type) 
            yyerror("Incompatibile types!");

        Node* result = (Node *) malloc(sizeof(Node));
        result -> type = BOOLEAN;
        switch(node1 -> type) {
            case INTEGER: 
                result -> value.b = node1 -> value.i >= node2 -> value.i;
                return result; 
            case FLOAT: 
                result -> value.b = node1 -> value.f >= node2 -> value.f;
                return result;
            case BOOLEAN: 
                yyerror("Operator not supported!");
                return NULL;
            case STRING: 
                result -> value.b = strlen(node1 -> value.s) >= strlen(node2 -> value.s);
                return result;
        }

        return NULL;
    }

    Node* lower(Node* node1, Node* node2){
            
        if (node1 -> type != node2 -> type) 
            yyerror("Incompatibile types!");

        Node* result = (Node *) malloc(sizeof(Node));
        result -> type = BOOLEAN;
        switch(node1 -> type) {
            case INTEGER: 
                result -> value.b = node1 -> value.i < node2 -> value.i;
                return result; 
            case FLOAT: 
                result -> value.b = node1 -> value.f < node2 -> value.f;
                return result;
            case BOOLEAN: 
                yyerror("Operator not supported!");
                return NULL;
            case STRING: 
                result -> value.b = strlen(node1 -> value.s) < strlen(node2 -> value.s);
                return result;
        }

        return NULL;
    }


    Node* lowerEqual(Node* node1, Node* node2){
            
        if (node1 -> type != node2 -> type) 
            yyerror("Incompatibile types!");

        Node* result = (Node *) malloc(sizeof(Node));
        result -> type = BOOLEAN;
        switch(node1 -> type) {
            case INTEGER: 
                result -> value.b = node1 -> value.i <= node2 -> value.i;
                return result; 
            case FLOAT: 
                result -> value.b = node1 -> value.f <= node2 -> value.f;
                return result;
            case BOOLEAN: 
                yyerror("Operator not supported!");
                return NULL;
            case STRING: 
                result -> value.b = strlen(node1 -> value.s) <= strlen(node2 -> value.s);
                return result;
        }

        return NULL;
    }

    Node* equal(Node* node1, Node* node2){
            
        if (node1 -> type != node2 -> type) 
            yyerror("Incompatibile types!");

        Node* result = (Node *) malloc(sizeof(Node));
        result -> type = BOOLEAN;
        switch(node1 -> type) {
            case INTEGER: 
                result -> value.b = node1 -> value.i == node2 -> value.i;
                return result; 
            case FLOAT: 
                result -> value.b = node1 -> value.f == node2 -> value.f;
                return result;
            case BOOLEAN: 
                yyerror("Operator not supported!");
                return NULL;
            case STRING: 
                result -> value.b = strcmp(node1 -> value.s, node2 -> value.s) == 0;
                return result;
        }

        return NULL;
    }

    Node* notEqual(Node* node1, Node* node2){
            
        if (node1 -> type != node2 -> type) 
            yyerror("Incompatibile types!");

        Node* result = (Node *) malloc(sizeof(Node));
        result -> type = BOOLEAN;
        switch(node1 -> type) {
            case INTEGER: 
                result -> value.b = node1 -> value.i != node2 -> value.i;
                return result; 
            case FLOAT: 
                result -> value.b = node1 -> value.f != node2 -> value.f;
                return result;
            case BOOLEAN: 
                yyerror("Operator not supported!");
                return NULL;
            case STRING: 
                result -> value.b = strcmp(node1 -> value.s, node2 -> value.s) != 0;
                return result;
        }

        return NULL;
    }

    Node* not(Node* node){
        Node* result = (Node *) malloc(sizeof(Node));
        result -> type = BOOLEAN;
        switch(node -> type) {
            case INTEGER: 
                result -> value.b = ((node -> value.i) != 0);
                return result; 
            case FLOAT: 
                result -> value.b = ((node -> value.f) != 0.0);
                return result;
            case BOOLEAN: 
                result -> value.b = !(node -> value.b);
                return result;
            case STRING: 
                result -> value.b = strlen(node -> value.s) == 0;
                return result;
        }

        return NULL;
    }

    Node* and(Node* node1, Node* node2){
            
        if (node1 -> type != node2 -> type) 
            yyerror("Incompatibile types!");

        Node* result = (Node *) malloc(sizeof(Node));
        result -> type = BOOLEAN;
        switch(node1 -> type) {
            case INTEGER: 
                yyerror("Operator not supported!");
                return NULL;
            case FLOAT: 
                yyerror("Operator not supported!");
                return NULL;
            case BOOLEAN: 
                result -> value.b = node1 -> value.b && node2 -> value.b;
                return result;
            case STRING: 
                yyerror("Operator not supported!");
                return NULL;
        }

        return NULL;
    }


    Node* or(Node* node1, Node* node2){
            
        if (node1 -> type != node2 -> type) 
            yyerror("Incompatibile types!");

        Node* result = (Node *) malloc(sizeof(Node));
        result -> type = BOOLEAN;
        switch(node1 -> type) {
            case INTEGER: 
                yyerror("Operator not supported!");
                return NULL;
            case FLOAT: 
                yyerror("Operator not supported!");
                return NULL;
            case BOOLEAN: 
                result -> value.b = node1 -> value.b || node2 -> value.b;
                return result;
            case STRING: 
                yyerror("Operator not supported!");
                return NULL;
        }

        return NULL;
    }

    

#endif