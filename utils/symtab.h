#ifndef SYMTAB
#define SYMTAB

    #include "types.h"
    #include "helpers.h"

    void printNode(Node*);
    void printTable(Node* n);
    Node* construct(const char*, Node*);
    Node *constructInteger(const char*, int);
    Node *constructFloat(const char*, float);
    Node *constructBoolean(const char*, bool);
    Node *constructString(const char*, char*);
    void insert(Node* n);
    void newScope(char* name);
    void goToParentScope();
    Node* getNode(const char* id);

    
    SymbTable* parentTable = NULL;

    void printNode(Node* node) {

        switch (node -> type) {
            case INTEGER:
                printf("\nID: %s\nVALUE: %d\nTYPE: %s\n", 
                    node -> id, 
                    node -> value.i, 
                    typeToString(node -> type)
                );
                break;
            case FLOAT:
                printf("\nID: %s\nVALUE: %f\nTYPE: %s\n", 
                    node -> id, 
                    node -> value.f, 
                    typeToString(node -> type)
                );
                break;
            case BOOLEAN:
                printf("\nID: %s\nVALUE: %d\nTYPE: %s\n", 
                    node -> id, 
                    node -> value.b, 
                    typeToString(node -> type)
                );
                break;
            case STRING:
                printf("\nID: %s\nVALUE: %s\nTYPE: %s\n", 
                    node -> id, 
                    node -> value.s, 
                    typeToString(node -> type)
                );
                break;
            }
    }
    
    void printTable(Node * head) {
        Node * node = head;
        while(node != NULL) {
            printNode(node);
            node = node -> next;
        }
    }


    Node* construct(const char* id, Node* node) {
        node -> id = id;
        node -> next = NULL;
        return node;
    }

    Node *constructInteger(const char* id, int value) {
        Node * node = (Node *) malloc(sizeof(Node));
        node -> id = id;
        node -> value.i = value;
        node -> type = INTEGER;
        node -> next = NULL;
        return node;
    }

    Node *constructFloat(const char* id, float value) {
        Node * node = (Node *) malloc(sizeof(Node));
        node -> id = id;
        node -> value.f = value;
        node -> type = FLOAT;
        node -> next = NULL;
        return node;
    }

    Node *constructBoolean(const char* id, bool value) {
        Node * node = (Node *) malloc(sizeof(Node));
        node -> id = id;
        node -> value.b = value;
        node -> type = BOOLEAN;
        node -> next = NULL;
        return node;
    }

    Node *constructString(const char* id, char* value) {
        Node * node = (Node *) malloc(sizeof(Node));
        node -> id = id;
        node -> value.s = removeQuoteMarks(value);
        node -> type = STRING;
        node -> next = NULL;
        return node;
    }

    void insert(Node* newNode) {
        if (parentTable -> head == NULL) {
           parentTable -> head = newNode;
        }
        else {
            Node * node = parentTable -> head;
            while (node -> next != NULL) {
                if (strcmp(newNode -> id, node -> id) == 0) 
                    yyerror("Variable name already in use!");
                node = node -> next;
            }
            if (strcmp(newNode -> id, node -> id) == 0) 
                yyerror("Variable name already in use!");
            node -> next = newNode;
        }
    }

    void newScope(char* name){
        SymbTable* childTable = (SymbTable *) malloc(sizeof(SymbTable));
        childTable->scope = name;
        childTable->parentSym = parentTable;
        childTable ->head = NULL;

        parentTable = childTable;
    }

    void goToParentScope(){
        SymbTable* pointer = parentTable;
        parentTable = pointer->parentSym;
        free(pointer);
    }

    Node* getNode(const char* id) {
        SymbTable* pointer = parentTable;
        while(pointer != NULL){
            Node *node = pointer -> head;
            while (node != NULL) {
                if (strcmp(node -> id, id) == 0)
                    return node;
                node = node -> next;
            }
            pointer = pointer->parentSym;
        }
        return NULL;
    }

#endif

