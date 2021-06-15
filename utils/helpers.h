#ifndef HELPERS
#define HELPERS

    #include <stdio.h>
    #include <stdlib.h>
    #include "types.h"


    void yyerror(const char*);
    ValueType getType(Node*);
    char* enumToString(ValueType);
    void typeCheck(Node*, ValueType);
    int getIntValue(Node*);
    float getFloatValue(Node*);
    bool getBoolValue(Node*);
    char* getStringValue(Node*);
    char* removeQuoteMarks(char* s);
    char* stringConcat(const char* s1, const char* s2);
    char* stringSubtract(char* s1, char* s2);


    void yyerror(const char* msg) { 
        /* TODO: add line to error message */ 
        fprintf(stderr, "%s\n", msg);
        exit(EXIT_FAILURE);
    }

    ValueType getType(Node* node) {
        return node -> type;
    }

    char* typeToString(ValueType type) {
        switch (type) {
            case INTEGER: return "integer";
            case FLOAT:   return "float";
            case BOOLEAN: return "boolean";
            case STRING:  return "string";
        }
    }

    void typeCheck(Node* node, ValueType type) {
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

    char* removeQuoteMarks(char* s1){
        char *res = (char *) malloc(strlen(s1)*sizeof(char));
        int i = 1;
        int j = 0;
        while(i < strlen(s1)-1){
            res[j] = s1[i];
            i++;
            j++;
        }
        
        return res;
    }

    char* stringConcat(const char* str1, const char* str2) {
        char newString[strlen(str1) + strlen(str2) + 1];
        strcpy(newString, str1);
        strcpy(newString, str2);
        return strdup(newString);
    }

    
    char* stringSubtract(char* a, char* b){
        char* res;
        if(strlen(a) >= strlen(b)){
            res = (char *) malloc(strlen(a)*sizeof(char));
        }
        else if(strlen(a) < strlen(b)){
            printf("subtrahend smaller than minhuend, subtraction not possible.");
            return NULL;
        }

        int i = 0;
        int j = 0;

        int resI = 0;
        
        while(i < strlen(a)){
            while(j < strlen(b)){
                if(a[i] == b[j]){
                    i++;
                    j = 0;
                    break;
                }
                j++;
            }
            
            if(j != 0){
                res[resI] = a[i];
                resI++;
                i++;
                j = 0;
            }
        }

        return res;
    }  //Just an idea, return a string which is string a without char occurences of b

#endif
