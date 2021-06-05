#include "symtab.h"
#include <stdio.h>
#include <stdlib.h>

int main(){

    Node * node1 = constructInteger("ciao", 3);
    Node * node2 = constructInteger("bonjur", 4);
    Node * node3 = constructFloat("dziendobry", 5);
    Node * node4 = constructBoolean("hi", false);
    Node * node5 = constructString("hi!", "some string");


    insert(node1);
    insert(node2);
    insert(node3);
    insert(node4);
    insert(node5);

    printTable();

    // printf("------------\n");
    // Node *x = getNode("hello");
    // if (x -> type == INTEGER)
    // 	printf("%d\n", x -> value.i);


}
