/*
    DIMITRIS GAVOURAS
    03145
*/
#include <stdlib.h>
#include <stdio.h>
#include "list.h"

typedef struct product {
    int position;//max pos of the product
    int length;//length of the product
}product_t;

// void printList (struct list *head, int counter){
//     struct list *curr;
//     int j=0;

//     for (curr = head; j < counter; curr = curr->nxt, j++){
//         if (curr == NULL){
//             continue;
//         }
//         printf ("%d ", curr->num);
//         printf("%d\n", curr->pos);
//     }
// }

void checkP (struct list *head, product_t *product, int P){
/*
    Start from head and move untill you found or exceeded P, then keep the P or dont 
    and div the start of the equation and move one repeat until end
    If you found P and next num is 1 then addto one to the length of the equation
*/
    struct list *ptr_start = NULL;
    struct list *ptr_end = NULL;
    int mult = 0, len=0, poss=0;
    
    product->length = -1;
    product->position = -1;

    /*begin at the start of the array*/
    ptr_start = head;
    ptr_end = head;
    mult += ptr_start->num;

    while (1) {
        

        if (mult == P){
            //check if next is 1
            if ((ptr_end->nxt != NULL) && (ptr_end->nxt->num == 1)){
                ptr_end = ptr_end->nxt;
                continue;
            }

            len = ptr_end->pos - ptr_start->pos + 1; 
            poss = ptr_start->pos;

            if (len >= product->length){
                product->length = len;
                product->position = poss;
            }
            
            ptr_start = ptr_start->nxt;
            mult = (ptr_start->num);
            ptr_end = ptr_start;
            continue;
        }
        else if (mult >= P){
            if (ptr_start->nxt == NULL){
                break;        
            }
            ptr_start = ptr_start->nxt;
            mult = (ptr_start->num);
            ptr_end = ptr_start;
            continue;
        }
        else {
            if (ptr_end->nxt == NULL){
                break;
            }
            ptr_end = ptr_end->nxt;
        }

        mult = mult * ptr_end->num;
    }

    if (mult == P){
        if (len >= product->length){
            product->length = len;
            product->position = poss;
        }
    }

}

int main (int argc, char *argv[]){
    struct list *head;
    product_t product;
    int count_l=0, number=0, P=0;//To count uknown elements

    /*Do malloc for head*/
    P = atoi(argv[1]);
    scanf(" %d", &number);

    /*Call do_malloc and add all nums by returning counter for elements */  
    count_l = list_init (&head, number);
    if (count_l == -42){
        return -42;
    }

    int system_fail = insert_list (&head, &count_l);
    if (system_fail == -42){
        return -42;
    }

    //printList (head, count_l);
    checkP (head, &product, P);

    if (product.length == -1){
        printf ("longest sequence: NOT FOUND\n");
    }
    else {
        printf ("longest sequence: %d %d\n", product.position, product.length);
    }


    free_list (head);

    return 0;
}