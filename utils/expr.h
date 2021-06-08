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
                result -> value.s = stringConcat(node1 -> value.s, node2 -> value.s);
                result -> type = STRING;
                return result;
        }    
        return NULL;
    }

    /* TODO: definitions of other functions declared above */

#endif