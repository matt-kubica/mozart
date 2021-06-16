#ifndef EXPR
#define EXPR

    #include "types.h"
    #include "helpers.h"


    Node* add(Node*, Node*);
    Node* subtract(Node*, Node*);
    Node* multiply(Node*, Node*);
    Node* divide(Node*, Node*);
    Node* modulo(Node*, Node*);


    Node* add(Node* node1, Node* node2) {

        if (node1 -> type != node2 -> type)  
            yyerror("Incompatibile types!");

        Node* result = (Node *) malloc(sizeof(Node));
        switch(node1 -> type) {
            case INTEGER: 
                result -> value.i = node1 -> value.i + node2 -> value.i; 
                result -> type = INTEGER;
                return result;
            case FLOAT: 
                result -> value.f = node1 -> value.f + node2 -> value.f;
                result -> type = FLOAT;
                return result;
            case BOOLEAN: 
                yyerror("Operator not supported!");
                return NULL;
            case STRING: 
                result -> value.s = strcat(node1 -> value.s, node2 -> value.s);
                result -> type = STRING;
                return result;
        }    
        return NULL;
    }

    Node* subtract(Node* node1, Node* node2) {

        if (node1 -> type != node2 -> type)  
            yyerror("Incompatibile types!");

        Node* result = (Node *) malloc(sizeof(Node));
        switch(node1 -> type) {
            case INTEGER: 
                result -> value.i = node1 -> value.i - node2 -> value.i; 
                result -> type = INTEGER;
                return result;
            case FLOAT: 
                result -> value.f = node1 -> value.f - node2 -> value.f;
                result -> type = FLOAT;
                return result;
            case BOOLEAN: 
                yyerror("Operator not supported!");
                return NULL;
            case STRING: 
                result -> value.s = stringSubtract(node1 -> value.s, node2 -> value.s);
                result -> type = STRING;
                return result;
        }    
        return NULL;
    }

    Node* multiply(Node* node1, Node* node2) {

        if (node1 -> type != node2 -> type)  
            yyerror("Incompatibile types!");

        Node* result = (Node *) malloc(sizeof(Node));
        switch(node1 -> type) {
            case INTEGER: 
                result -> value.i = node1 -> value.i * node2 -> value.i; 
                result -> type = INTEGER;
                return result;
            case FLOAT: 
                result -> value.f = node1 -> value.f * node2 -> value.f;
                result -> type = FLOAT;
                return result;
            case BOOLEAN: 
                yyerror("Operator not supported!");
                return NULL;
            case STRING: 
                yyerror("Operator not supported!");
                return NULL;
        }    
        return NULL;
    }

    Node* divide(Node* node1, Node* node2) {

        if (node1 -> type != node2 -> type)  
            yyerror("Incompatibile types!");

        Node* result = (Node *) malloc(sizeof(Node));
        switch(node1 -> type) {
            case INTEGER: 
                if(node1->value.i == 0 && node2->value.i == 0){
                    yyerror("...indeterminate...");
                    return NULL;
                }
                else if(node1->value.i != 0 && node2->value.i == 0){
                    yyerror("...undefined...");
                    return NULL;
                }
                result -> value.i = node1 -> value.i / node2 -> value.i; 
                result -> type = INTEGER;
                return result;
            case FLOAT: 
                if(node1->value.f == 0.00000 && node2->value.i == 0.00000){
                    yyerror("...indeterminate...");
                    return NULL;
                }
                else if(node1->value.f != 0.00000 && node2->value.f == 0.00000){
                    yyerror("...undefined...");
                    return NULL;
                }
                result -> value.f = node1 -> value.f / node2 -> value.f;
                result -> type = FLOAT;
                return result;
            case BOOLEAN: 
                yyerror("Operator not supported!");
                return NULL;
            case STRING: 
                yyerror("Operator not supported!");
                return NULL;
        }    
        return NULL;
    }


    Node* modulo(Node* node1, Node* node2) {

        if (node1 -> type != node2 -> type)  
            yyerror("Incompatibile types!");

        Node* result = (Node *) malloc(sizeof(Node));
        switch(node1 -> type) {
            case INTEGER: 
                if(node1->value.i == 0 && node2->value.i == 0){
                    yyerror("...indeterminate...");
                    return NULL;
                }
                else if(node1->value.i != 0 && node2->value.i == 0){
                    yyerror("...undefined...");
                    return NULL;
                }
                result -> value.i = node1 -> value.i - (node2 -> value.i * (node1 -> value.i / node2 -> value.i));   
                result -> type = INTEGER;
                return result;
            case FLOAT: 
                if(node1->value.f == 0.00000 && node2->value.i == 0.00000){
                    yyerror("...indeterminate...");
                    return NULL;
                }
                else if(node1->value.f != 0.00000 && node2->value.f == 0.00000){
                    yyerror("...undefined...");
                    return NULL;
                }
                result -> value.f = node1 -> value.f - (node2 -> value.f * (node1 -> value.f / node2 -> value.f));
                result -> type = FLOAT;
                return result;
            case BOOLEAN: 
                yyerror("Operator not supported!");
                return NULL;
            case STRING: 
                yyerror("Operator not supported!");
                return NULL;
        }    
        return NULL;
    }

#endif