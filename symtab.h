#ifndef SYMTAB
#define SYMTAB

    #include <stdio.h>
    #include <stdlib.h>
    #include <stdbool.h>
    #include <string.h>

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


#endif
