#ifndef SYMTABSTRUCT
#define SYMTABSTRUCT

#include "types.h"
#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include <string.h>


typedef struct SymbTable{
    Node* head;
    SymbTable* parentSym;
}  SymbTable;

#endif