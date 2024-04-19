#ifndef LIST_H
#define LIST_H

struct list {
    int num;
    struct list *nxt;
    int pos;
    
};

int list_init (struct list **head, int number);

int insert_list (struct list **head, int *count_l);

void free_list (struct list *head);

#endif