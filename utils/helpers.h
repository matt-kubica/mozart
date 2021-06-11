#ifndef HELPERS
#define HELPERS

    #include <stdio.h>
    #include <stdlib.h>
    #include "types.h"


    void yyerror(const char*);
    Type getType(Node*);
    char* enumToString(Type);
    void typeCheck(Node*, Type);
    int getIntValue(Node*);
    float getFloatValue(Node*);
    bool getBoolValue(Node*);
    char* getStringValue(Node*);


    void yyerror(const char* msg) { 
        /* TODO: add line to error message */ 
        fprintf(stderr, "%s\n", msg);
        exit(EXIT_FAILURE);
    }

    Type getType(Node* node) {
        return node -> type;
    }

    char* typeToString(Type type) {   
        switch (type) {
            case INTEGER: return "integer";
            case FLOAT:   return "float";
            case BOOLEAN: return "boolean";
            case STRING:  return "string";
        }
    }

    void typeCheck(Node* node, Type type) {
        if (node -> type != type)
            yyerror("type declaration does not match!");
    }

    int getIntValue(Node* node) {
        return node -> value.i;
    }

    float getFloatValue(Node *node) {
        return node -> value.f;
    }

    bool getBoolValue(Node* node) {
        return node -> value.b;
    }

    char* getStringValue(Node* node) {
        return node -> value.s;
    }

    char* stringConcat(const char* str1, const char* str2) {
        char newString[strlen(str1) + strlen(str2) + 1];
        strcpy(newString, str1);
        strcpy(newString, str2);
        return strdup(newString);
    }

    /*
    char* stringSubtract(char* a, char* b){
        if(a >= b){
            char res[strlen(a)];
        }
        else{
            char res[strlen(b)];
        }

        int i = 0;
        while(*a++ && *b++ && *a != '\0' && *b != '\0'){
            if(strcmp(a, b) != 0){
                res[i] = *a;
                i++;
            }
        }
        return res;
    }*/  //Just an idea, return a string which is string a without substring b

#endif
