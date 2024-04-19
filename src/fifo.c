#include <stdio.h>
#include <stdlib.h>
#include "tree.h"
#include "fifo.h"


void move_node (levelTrack *lvlTrack, node_t *node){
    levelOrder *lvlOrder;

    lvlOrder = (levelOrder*)malloc(sizeof(levelOrder));
    if (lvlOrder == NULL){
        perror("ERROR");
        exit(-42);
    }
    lvlOrder->node = node;
    lvlOrder->nxt = NULL;

    if (lvlTrack->head == NULL){
        lvlTrack->head = lvlOrder;
        lvlTrack->tail = lvlOrder;
    }
    else {
        lvlTrack->tail->nxt = lvlOrder;
        lvlTrack->tail = lvlOrder;
    }

}

node_t* fifo (levelTrack *lvlTrack){
    node_t* node;
    levelOrder *delete;

    if (lvlTrack->head != NULL){
        node = lvlTrack->head->node;
    }
    else {
        node=NULL;
    }

    if (lvlTrack->head != NULL){
        delete = lvlTrack->head;
        lvlTrack->head = lvlTrack->head->nxt;
        free(delete);
        if (lvlTrack->head == NULL){
            lvlTrack->tail = NULL;
        }
    }
    return node;
}