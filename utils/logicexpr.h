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
        result -> value.b = true;
        return result;
    }

    Node* falseVal() {
        Node* result = (Node *) malloc(sizeof(Node));
        result -> type = BOOLEAN;
        result -> value.b = false;
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

    /* TODO: definitions of other functions declared above */

#endif