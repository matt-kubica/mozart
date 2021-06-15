#ifndef TYPES
#define TYPES
 
    #include <stdio.h>
    #include <stdlib.h>
    #include <stdbool.h>
    #include <string.h>

    typedef enum ValueType {
        INTEGER,
        FLOAT,
        BOOLEAN,
        STRING
    } ValueType;

    typedef union Value {
        int i;
        float f;
        bool b;
        char *s;
    } Value;

//    typedef enum ExpressionType {
//
//    } ExpressionType;
//
//    typedef struct Identifier {
//
//    };

    typedef struct Node {
        const char* id;
        Value value;
        enum ValueType type ;
        struct Node* next;    
    } Node; 

    typedef struct Scope {
        const char* name;
        Node* symtab;
        struct Scope* parent;
    }  Scope;

    
#endif
