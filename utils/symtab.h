#ifndef SYMTAB
#define SYMTAB

    #include "types.h"
    #include "helpers.h"

    void printNode(Node*);
    void printTable(Node* n);
    void printAllTables();
    Node* construct(const char*, Node*);
    Node *constructInteger(const char*, int);
    Node *constructFloat(const char*, float);
    Node *constructBoolean(const char*, bool);
    Node *constructString(const char*, char*);
    void insert(Node*);
    void enterScope(const char*);
    void leaveScope();
    Node* getNode(const char*);
    
    Scope* currentScope;

    void printNode(Node* node) {
        switch (node -> type) {
            case INTEGER:
                printf("ID: %s\nVALUE: %d\nTYPE: %s\n", 
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
    
    void printTable(Node* head) {
        Node* node = head;
        while(node != NULL) {
            printNode(node);
            node = node -> next;
        }
    }

    void printAllTables(){
        Scope* pointer = currentScope;
        while(pointer != NULL){
            printf("\nTABLE NAME: %s\n", pointer->name);
            printTable(pointer->symtab);
            pointer = pointer->parent;
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
        if (currentScope -> symtab == NULL) {
            currentScope -> symtab = newNode;
            return;
        }

        Node * node = currentScope -> symtab;
        while (node -> next != NULL) {
            printf("Iterating?");
            if (strcmp(newNode -> id, node -> id) == 0)
                yyerror("Variable name already in use!");
            node = node -> next;
        }
        if (strcmp(newNode -> id, node -> id) == 0)
            yyerror("Variable name already in use!");
        node -> next = newNode;

    }

    void enterScope(const char* name) {
        Scope* newScope = (Scope *) malloc(sizeof(Scope));
        newScope -> name = name;
        newScope -> parent = currentScope;
        newScope -> symtab = NULL;

        currentScope = newScope;
    }

    void leaveScope() {
        Scope* pointer = currentScope;
        currentScope = pointer -> parent;
        free(pointer);
    }

    Node* getNode(const char* id) {
        Scope* scopePointer = currentScope;
        while(scopePointer != NULL){
            Node *nodePointer = scopePointer -> symtab;
            while (nodePointer != NULL) {
                if (strcmp(nodePointer -> id, id) == 0)
                    return nodePointer;
                nodePointer = nodePointer -> next;
            }
            scopePointer = scopePointer -> parent;
        }
        return NULL;
    }



#endif

