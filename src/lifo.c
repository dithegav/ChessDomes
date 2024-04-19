#include <stdio.h>
#include <stdlib.h>
#include "lifo.h"

void insertNew_node (struct post_order **postorder, int number){
    struct post_order *curr;

    curr = (struct post_order *) malloc (sizeof(struct post_order));

    if (curr == NULL){
        *postorder = NULL;
        perror ("ERROR");
        exit (-42);
    }

    /*
    / pass number and then put it infront of the head 
    / to create the circumstances for a later lifo
    */
    curr->num = number;
    curr->nxt = *postorder;
    *postorder = curr;

}
