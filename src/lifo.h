#ifndef LIFO_H
#define LIFO_H

struct post_order {
    int num;
    struct post_order *nxt;
};

void insertNew_node (struct post_order **postorder, int number);

#endif