#ifndef FIFO_H
#define FIFO_H

typedef struct level_order {
    node_t *node;
    struct level_order *nxt;
}levelOrder;

typedef struct level_track {
    levelOrder *head;
    levelOrder *tail;
}levelTrack;


void move_node (levelTrack *lvlTrack, node_t *node);

node_t* fifo (levelTrack *lvlTrack);

#endif