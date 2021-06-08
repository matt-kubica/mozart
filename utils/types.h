#ifndef TYPES
#define TYPES
 
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
        enum Type type ;
        struct Node* next;    
    } Node; 

#endif