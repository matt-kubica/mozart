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

//    typedef enum IdentifierType {
//        UNDEFINED,
//        FUNCTION,
//        PARAMETER,
//        VARIABLE
//    } ExpressionType;
//
//    typedef struct Identifier {
//        enum IdentifierType type;
//        const char* name;
//    };

    typedef struct Node {
        const char *id;
        union Value value;
        enum ValueType type ;
        struct Node* next;    
    } Node; 

    typedef struct Scope {
        const char* name;
        Node* symtab;
        struct Scope* parent;
    }  Scope;

    
#endif
