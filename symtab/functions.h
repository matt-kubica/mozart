#ifndef SYMTABFUNCTIONS
#define SYMTABFUNCTIONS

    #include "types.h"

    Node * head = NULL;

    char * enumToString(Type type){
        
        switch (type) {
            case INTEGER:
                return "integer";
            case FLOAT:
                return "float";
            case BOOLEAN:
                return "boolean";
            case STRING:
                return "string";
        }
    }

    void printNode(Node *node) {

        switch (node -> type) {
            case INTEGER:
                printf("\nID: %s\nVALUE: %d\nTYPE: %s\n", 
                    node -> id, 
                    node -> value.i, 
                    enumToString(node -> type)
                );
                break;
            case FLOAT:
                printf("\nID: %s\nVALUE: %f\nTYPE: %s\n", 
                    node -> id, 
                    node -> value.f, 
                    enumToString(node -> type)
                );
                break;
            case BOOLEAN:
                printf("\nID: %s\nVALUE: %d\nTYPE: %s\n", 
                    node -> id, 
                    node -> value.b, 
                    enumToString(node -> type)
                );
                break;
            case STRING:
                printf("\nID: %s\nVALUE: %s\nTYPE: %s\n", 
                    node -> id, 
                    node -> value.s, 
                    enumToString(node -> type)
                );
                break;
            }
    }
    
    void printTable() {
        Node * node = head;
        while(node != NULL) {
            printNode(node);
            node = node -> next;
        }
    }

    Node* construct(char *id, Node* node){
        node->id = id;
        node->next = NULL;
        return node;
    }

    Node *constructInteger(char *id, int value) {
        Node * node = (Node *) malloc(sizeof(Node));
        node -> id = id;
        node -> value.i = value;
        node -> type = INTEGER;
        node -> next = NULL;
        return node;
    }

    Node *constructFloat(char *id, float value) {
        Node * node = (Node *) malloc(sizeof(Node));
        node -> id = id;
        node -> value.f = value;
        node -> type = FLOAT;
        node -> next = NULL;
        return node;
    }

    Node *constructBoolean(char *id, bool value) {
        Node * node = (Node *) malloc(sizeof(Node));
        node -> id = id;
        node -> value.b = value;
        node -> type = BOOLEAN;
        node -> next = NULL;
        return node;
    }

    Node *constructString(char *id, char * value) {
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

#endif

