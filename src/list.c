#include <stdlib.h>
#include <stdio.h>
#include "list.h"

int list_init (struct list **head, int number){
    struct list *curr;
    int count_l = 0;
    curr = (struct list*)malloc(sizeof(struct list));
    if (curr == NULL){
        perror("Error");
        return -42;
    }
    curr->num = number;
    curr->nxt = NULL;
    count_l+=1;
    curr->pos = count_l-1;

    *head = curr;

    return count_l;
}

int insert_list (struct list **head, int *count_l){
    struct list *curr;
    int number=0, count=*count_l;

    for (curr = *head;;curr = curr->nxt){
        while (curr->nxt != NULL){
            curr = curr->nxt;
        }
        scanf (" %d", &number);

        if (number == 0){
            //all elements have been transfered
           break;
        }
        curr->nxt = (struct list*)malloc(sizeof(struct list));
        if ((curr->nxt) == NULL){
            perror("Error");
            return -42;
        }
        curr->nxt->num = number;
        count++;
        curr->nxt->nxt = NULL;
        curr->nxt->pos = count - 1;
    }

    *count_l  = count;

    return 1;
}

void free_list (struct list *head){
    struct list *curr ;

    while (head != NULL){
        curr = head;
        head = head->nxt;
        free(curr);
    }
}