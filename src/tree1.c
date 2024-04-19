/*
    DIMITRIS GAVOURAS
    03145
*/
#include <stdio.h>
#include <stdlib.h>
#include "tree.h"
#include "lifo.h"
#include "fifo.h"

int create_levelOrder (tree_t *tree){
    levelTrack lvlTrack;
    node_t *curr;

    if (tree->root == NULL){
        return 1;
    }

    lvlTrack.head = NULL;
    lvlTrack.tail = NULL;

    /*call move node to create first node with root in list level order*/
    move_node (&lvlTrack, tree->root);

    while (1){

        if (lvlTrack.head == NULL){
            break;
        }
        curr = fifo(&lvlTrack);
    
        printf ("%d ", curr->value);

        /*free this node and conitnue to the next*/
        if (lvlTrack.head == NULL){
            lvlTrack.tail = NULL;
        }

        if (curr->left != NULL){
            move_node (&lvlTrack, curr->left);
        }
        
        if (curr->right != NULL){
            move_node (&lvlTrack, curr->right);
        }

    }

    return 1;
}

int main (int argc, char *argv[]){
    struct post_order *postorder, *curr;
    /*node_t *node;*/
    tree_t *tree;
    int number=0;
    
    postorder = NULL;
    /*put everything in a list (each time change head)*/
    while(1){

        scanf (" %d", &number);

        if (number <= 0 ){
            break;
        }

        insertNew_node (&postorder, number);
    }

    tree = create_tree();
    number = 0;

    /*start puting in tree the list one by one
    then free theat node and move on*/
    while (1){
        number = postorder->num;

        btree_insert(tree, number);

        postorder->num = 0;
        if (postorder->nxt == NULL){
            free(postorder);
            break;
        }

        curr = postorder;
        postorder = postorder->nxt;
        free(curr);

    }

    create_levelOrder(tree);

    free_tree (tree->root);
    free(tree);
    printf ("\n");
    return 0;
}